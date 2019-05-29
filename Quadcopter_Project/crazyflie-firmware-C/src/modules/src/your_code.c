#include "your_code.h"	
/***
 *
 * This file is where you should add you tasks. You already know the structure
 * Required to do so from the work with the simulator.
 *
 * The function yourCodeInit() is set to automatically execute when the
 * quadrotor is started. This is where you need to create your tasks. The
 * scheduler that runs the tasks is already up and running so you should
 * NOT make a call to vTaskStartScheduler();.
 *
 * Below that you can find a few examples of useful function calls and code snippets.
 *
 * For further reference on how this is done. Look into the file stabilizer.c
 * which is usually handles the control of the crazyflie.
 *
 ***/

#define ALPHA 0.01f
#define g 9.81f
#define DT 0.01f
// #define GAMMA (ALPHA / (ALPHA + DT))
float GAMMA = (ALPHA / (ALPHA + DT));

#define DEBUG_MODULE "STAB"
#define DEG2RAD (3.1415f/180.f)
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define THRUST_CONV (4.0f*65536.0f/(0.06f*9.81f))
#define ACC_RANGE_PERC (0.25f)
#define SAFETY_MAX_ANG (60.f*DEG2RAD)
#define BASE_THRUST (0.f)

sensorData_t sensorData;
float state[5];
setpoint_t setpoint;
state_t setpoint_state;

// onlinetuning parameters
float factor_ref  = 30.f;
float fac_fb_rp   = 10.f;
float fac_fb_v    = 1.2f;
float fac_fb_yr   = 1.f;
float GYR_FORGET_FAC = 0.99f;
float ADD_THRUST = 0;

// array for storing angle output from filter
float angle_filter[3] = {0,0,0};
float angle_acc[3]    = {0,0,0};
float angle_gyro[3]   = {0,0,0};
float sensor_gyro[3]  = {0,0,0};
float sensor_acc[3]   = {0,0,0};
float motor_values[4] = {0,0,0,0};

SemaphoreHandle_t stateSemaphore, refSemaphore, calSemaphore;


// Thread to read from setpoint
void updateReference(void *pvParameters){
	TickType_t lastWakeTime = xTaskGetTickCount ();
	while(1){
		if( xSemaphoreTake( refSemaphore, (TickType_t) 1 ) == pdTRUE ){
			commanderGetSetpoint(&setpoint, &setpoint_state);
			xSemaphoreGive( refSemaphore );
		}
		vTaskDelayUntil(&lastWakeTime, F2T(RATE_100_HZ));
	}
}

// Thread to calculate control input and set those values to the motors
void updateControlInput(void *pvParameters){

	TickType_t lastWakeTime = xTaskGetTickCount ();
	DEBUG_PRINT("STAB - CONTROLLER STARTED AND WAITING FOR CALIBRATION.\n");
	xSemaphoreTake(calSemaphore, portMAX_DELAY);
	DEBUG_PRINT("STAB - CONTROLLER CALIBRATED.\n");

	float u_fb[4], u_ref[4], ref[3], l_state[5];
	float safety_bool = 1.f;
	while(1){

		// read shared resource
		xSemaphoreTake( stateSemaphore, portMAX_DELAY );
		l_state[0] = state[0];
		l_state[1] = state[1];
		l_state[2] = state[2];
		l_state[3] = state[3];
		l_state[4] = state[4];
		xSemaphoreGive(stateSemaphore);
		
		// u_fb = -K * x
		u_fb[0] = + 0.003384f*l_state[0]*fac_fb_rp + 0.003483f*l_state[1]*fac_fb_rp + 0.01073f*l_state[2]*fac_fb_v + 0.01105f*l_state[3]*fac_fb_v + 0.01737f*l_state[4]*fac_fb_yr;
   		u_fb[1] = + 0.003384f*l_state[0]*fac_fb_rp - 0.003483f*l_state[1]*fac_fb_rp + 0.01073f*l_state[2]*fac_fb_v - 0.01105f*l_state[3]*fac_fb_v - 0.01737f*l_state[4]*fac_fb_yr;
   		u_fb[2] = - 0.003384f*l_state[0]*fac_fb_rp - 0.003483f*l_state[1]*fac_fb_rp - 0.01073f*l_state[2]*fac_fb_v - 0.01105f*l_state[3]*fac_fb_v + 0.01737f*l_state[4]*fac_fb_yr;
   		u_fb[3] = - 0.003384f*l_state[0]*fac_fb_rp + 0.003483f*l_state[1]*fac_fb_rp - 0.01073f*l_state[2]*fac_fb_v + 0.01105f*l_state[3]*fac_fb_v - 0.01737f*l_state[4]*fac_fb_yr;
 
		// u_ref = Kr * ref
		xSemaphoreTake( refSemaphore, portMAX_DELAY	);
		ref[0] =  setpoint.attitude.roll    * DEG2RAD;
		ref[1] = -setpoint.attitude.pitch   * DEG2RAD;
		ref[2] =  setpoint.attitudeRate.yaw * DEG2RAD;
		xSemaphoreGive( refSemaphore );
		u_ref[0] = -0.0034f*ref[0] -0.0035f*ref[1] -0.0174f*ref[2];
   		u_ref[1] = -0.0034f*ref[0] +0.0035f*ref[1] +0.0174f*ref[2];
    	u_ref[2] =  0.0034f*ref[0] +0.0035f*ref[1] -0.0174f*ref[2];
    	u_ref[3] =  0.0034f*ref[0] -0.0035f*ref[1] +0.0174f*ref[2];
		
		// Control input = u_fb + u_ref + ref_thrust
		motor_values[0] = ( u_fb[0] + u_ref[0]*factor_ref ) * THRUST_CONV;
		motor_values[1] = ( u_fb[1] + u_ref[1]*factor_ref ) * THRUST_CONV;
		motor_values[2] = ( u_fb[2] + u_ref[2]*factor_ref ) * THRUST_CONV;
		motor_values[3] = ( u_fb[3] + u_ref[3]*factor_ref ) * THRUST_CONV;

		motor_values[0] = MIN(65500.f, MAX(motor_values[0], 0.f) + BASE_THRUST + setpoint.thrust + ADD_THRUST );
		motor_values[1] = MIN(65500.f, MAX(motor_values[1], 0.f) + BASE_THRUST + setpoint.thrust + ADD_THRUST );
		motor_values[2] = MIN(65500.f, MAX(motor_values[2], 0.f) + BASE_THRUST + setpoint.thrust + ADD_THRUST );
		motor_values[3] = MIN(65500.f, MAX(motor_values[3], 0.f) + BASE_THRUST + setpoint.thrust + ADD_THRUST );

		// Safety function: turns off all motors if roll or pitch is outside limit
		if (l_state[0] > SAFETY_MAX_ANG || l_state[0] < -SAFETY_MAX_ANG || 
		    l_state[1] > SAFETY_MAX_ANG || l_state[0] < -SAFETY_MAX_ANG){
			safety_bool = 0.f;
		}

		// Add Base thrust and saturate signals before converting to uint16_t
		motorsSetRatio(MOTOR_M1, (uint16_t) motor_values[0]*safety_bool );
		motorsSetRatio(MOTOR_M2, (uint16_t) motor_values[1]*safety_bool );
		motorsSetRatio(MOTOR_M3, (uint16_t) motor_values[2]*safety_bool );
		motorsSetRatio(MOTOR_M4, (uint16_t) motor_values[3]*safety_bool );

		// sleep until next time step
		vTaskDelayUntil(&lastWakeTime, F2T(RATE_100_HZ));
	}
}

void compFilter(void *pvParameters){	

	TickType_t lastWakeTime;
	float norm;

	// Wait for calibration
	DEBUG_PRINT("STAB - WAITING FOR CALIBRATION.\n");
	lastWakeTime = xTaskGetTickCount ();
	while(!sensorsAreCalibrated()) {
		vTaskDelayUntil(&lastWakeTime, F2T(RATE_100_HZ));
	}
	xSemaphoreGive( calSemaphore );
	DEBUG_PRINT("STAB - CALIBRATED.\n");
	DEBUG_PRINT("STAB - FILTERING.\n");
	lastWakeTime = xTaskGetTickCount ();
	while(1){

		// read from sensors
		sensorsWaitDataReady();
		sensorsAcquire(&sensorData, 1);
	
		// Acceleration observer
		norm = sqrt(pow(sensorData.acc.x, 2) + pow(sensorData.acc.y, 2) + pow(sensorData.acc.z, 2));
		// normalize acceleration measurements
		if (norm != 0){
			sensor_acc[0] = sensorData.acc.x / norm;
			sensor_acc[1] = sensorData.acc.y / norm;
			sensor_acc[2] = sensorData.acc.z / norm;
		}
		// calculate rotation angles based on acceleration sensor
		angle_acc[0] = atan2(sensor_acc[1], sensor_acc[2]);
		angle_acc[1] = atan2(-sensor_acc[0], sqrt(pow(sensor_acc[1],2) + pow(sensor_acc[2],2)) );
		angle_acc[2] = 0;

		// Gyro observer
		sensor_gyro[0] = DEG2RAD*sensorData.gyro.x;
		sensor_gyro[1] = DEG2RAD*sensorData.gyro.y;
		sensor_gyro[2] = DEG2RAD*sensorData.gyro.z;
		// equations imported from Matlab
		// T[0][0] = oa1-gyr3*(-dt*sin(theta)+(dt*pow(cos(phi),2.0)*cos(theta)*sin(theta))/(pow(cos(phi),2.0)*cos(theta)+cos(theta)*pow(sin(phi),2.0))+(dt*cos(theta)*pow(sin(phi),2.0)*sin(theta))/(pow(cos(phi),2.0)*cos(theta)+cos(theta)*pow(sin(phi),2.0)))+gyr1*(dt*cos(psi)*cos(theta)-(dt*cos(phi)*sin(theta)*(sin(phi)*sin(psi)-cos(phi)*cos(psi)*sin(theta)))/(pow(cos(phi),2.0)*cos(theta)+cos(theta)*pow(sin(phi),2.0))+(dt*sin(phi)*sin(theta)*(cos(phi)*sin(psi)+cos(psi)*sin(phi)*sin(theta)))/(pow(cos(phi),2.0)*cos(theta)+cos(theta)*pow(sin(phi),2.0)))-gyr2*(dt*cos(theta)*sin(psi)+(dt*cos(phi)*sin(theta)*(cos(psi)*sin(phi)+cos(phi)*sin(psi)*sin(theta)))/(pow(cos(phi),2.0)*cos(theta)+cos(theta)*pow(sin(phi),2.0))-(dt*sin(phi)*sin(theta)*(cos(phi)*cos(psi)-sin(phi)*sin(psi)*sin(theta)))/(pow(cos(phi),2.0)*cos(theta)+cos(theta)*pow(sin(phi),2.0)));
		// T[1][0] = oa2+gyr1*((dt*cos(phi)*(cos(phi)*sin(psi)+cos(psi)*sin(phi)*sin(theta)))/(pow(cos(phi),2.0)+pow(sin(phi),2.0))+(dt*sin(phi)*(sin(phi)*sin(psi)-cos(phi)*cos(psi)*sin(theta)))/(pow(cos(phi),2.0)+pow(sin(phi),2.0)))+gyr2*((dt*cos(phi)*(cos(phi)*cos(psi)-sin(phi)*sin(psi)*sin(theta)))/(pow(cos(phi),2.0)+pow(sin(phi),2.0))+(dt*sin(phi)*(cos(psi)*sin(phi)+cos(phi)*sin(psi)*sin(theta)))/(pow(cos(phi),2.0)+pow(sin(phi),2.0)));
		// T[2][0] = oa3+gyr3*((dt*pow(cos(phi),2.0)*cos(theta))/(pow(cos(phi),2.0)*cos(theta)+cos(theta)*pow(sin(phi),2.0))+(dt*cos(theta)*pow(sin(phi),2.0))/(pow(cos(phi),2.0)*cos(theta)+cos(theta)*pow(sin(phi),2.0)))+gyr1*((dt*cos(phi)*(sin(phi)*sin(psi)-cos(phi)*cos(psi)*sin(theta)))/(pow(cos(phi),2.0)*cos(theta)+cos(theta)*pow(sin(phi),2.0))-(dt*sin(phi)*(cos(phi)*sin(psi)+cos(psi)*sin(phi)*sin(theta)))/(pow(cos(phi),2.0)*cos(theta)+cos(theta)*pow(sin(phi),2.0)))+gyr2*((dt*cos(phi)*(cos(psi)*sin(phi)+cos(phi)*sin(psi)*sin(theta)))/(pow(cos(phi),2.0)*cos(theta)+cos(theta)*pow(sin(phi),2.0))-(dt*sin(phi)*(cos(phi)*cos(psi)-sin(phi)*sin(psi)*sin(theta)))/(pow(cos(phi),2.0)*cos(theta)+cos(theta)*pow(sin(phi),2.0)));
		// and translated into C
		angle_gyro[0] = angle_gyro[0] - sensor_gyro[2] * (-DT * sin(angle_filter[1]) + (DT * pow(cos(angle_filter[0]), 2.0) * cos(angle_filter[1]) * sin(angle_filter[1])) / (pow(cos(angle_filter[0]), 2.0) * cos(angle_filter[1]) + cos(angle_filter[1]) * pow(sin(angle_filter[0]), 2.0)) + (DT * cos(angle_filter[1]) * pow(sin(angle_filter[0]), 2.0) * sin(angle_filter[1])) / (pow(cos(angle_filter[0]), 2.0) * cos(angle_filter[1]) + cos(angle_filter[1]) * pow(sin(angle_filter[0]), 2.0))) + sensor_gyro[0] * (DT * cos(angle_filter[2]) * cos(angle_filter[1]) - (DT * cos(angle_filter[0]) * sin(angle_filter[1]) * (sin(angle_filter[0]) * sin(angle_filter[2]) - cos(angle_filter[0]) * cos(angle_filter[2]) * sin(angle_filter[1]))) / (pow(cos(angle_filter[0]), 2.0) * cos(angle_filter[1]) + cos(angle_filter[1]) * pow(sin(angle_filter[0]), 2.0)) + (DT * sin(angle_filter[0]) * sin(angle_filter[1]) * (cos(angle_filter[0]) * sin(angle_filter[2]) + cos(angle_filter[2]) * sin(angle_filter[0]) * sin(angle_filter[1]))) / (pow(cos(angle_filter[0]), 2.0) * cos(angle_filter[1]) + cos(angle_filter[1]) * pow(sin(angle_filter[0]), 2.0))) - sensor_gyro[1] * (DT * cos(angle_filter[1]) * sin(angle_filter[2]) + (DT * cos(angle_filter[0]) * sin(angle_filter[1]) * (cos(angle_filter[2]) * sin(angle_filter[0]) + cos(angle_filter[0]) * sin(angle_filter[2]) * sin(angle_filter[1]))) / (pow(cos(angle_filter[0]), 2.0) * cos(angle_filter[1]) + cos(angle_filter[1]) * pow(sin(angle_filter[0]), 2.0)) - (DT * sin(angle_filter[0]) * sin(angle_filter[1]) * (cos(angle_filter[0]) * cos(angle_filter[2]) - sin(angle_filter[0]) * sin(angle_filter[2]) * sin(angle_filter[1]))) / (pow(cos(angle_filter[0]), 2.0) * cos(angle_filter[1]) + cos(angle_filter[1]) * pow(sin(angle_filter[0]), 2.0)));
		angle_gyro[1] = angle_gyro[1] + sensor_gyro[0] * ((DT * cos(angle_filter[0]) * (cos(angle_filter[0]) * sin(angle_filter[2]) + cos(angle_filter[2]) * sin(angle_filter[0]) * sin(angle_filter[1]))) / (pow(cos(angle_filter[0]), 2.0) + pow(sin(angle_filter[0]), 2.0)) + (DT * sin(angle_filter[0]) * (sin(angle_filter[0]) * sin(angle_filter[2]) - cos(angle_filter[0]) * cos(angle_filter[2]) * sin(angle_filter[1]))) / (pow(cos(angle_filter[0]), 2.0) + pow(sin(angle_filter[0]), 2.0))) + sensor_gyro[1] * ((DT * cos(angle_filter[0]) * (cos(angle_filter[0]) * cos(angle_filter[2]) - sin(angle_filter[0]) * sin(angle_filter[2]) * sin(angle_filter[1]))) / (pow(cos(angle_filter[0]), 2.0) + pow(sin(angle_filter[0]), 2.0)) + (DT * sin(angle_filter[0]) * (cos(angle_filter[2]) * sin(angle_filter[0]) + cos(angle_filter[0]) * sin(angle_filter[2]) * sin(angle_filter[1]))) / (pow(cos(angle_filter[0]), 2.0) + pow(sin(angle_filter[0]), 2.0)));
		angle_gyro[2] = angle_gyro[2] + sensor_gyro[2] * ((DT * pow(cos(angle_filter[0]), 2.0) * cos(angle_filter[1])) / (pow(cos(angle_filter[0]), 2.0) * cos(angle_filter[1]) + cos(angle_filter[1]) * pow(sin(angle_filter[0]), 2.0)) + (DT * cos(angle_filter[1]) * pow(sin(angle_filter[0]), 2.0)) / (pow(cos(angle_filter[0]), 2.0) * cos(angle_filter[1]) + cos(angle_filter[1]) * pow(sin(angle_filter[0]), 2.0))) + sensor_gyro[0] * ((DT * cos(angle_filter[0]) * (sin(angle_filter[0]) * sin(angle_filter[2]) - cos(angle_filter[0]) * cos(angle_filter[2]) * sin(angle_filter[1]))) / (pow(cos(angle_filter[0]), 2.0) * cos(angle_filter[1]) + cos(angle_filter[1]) * pow(sin(angle_filter[0]), 2.0)) - (DT * sin(angle_filter[0]) * (cos(angle_filter[0]) * sin(angle_filter[2]) + cos(angle_filter[2]) * sin(angle_filter[0]) * sin(angle_filter[1]))) / (pow(cos(angle_filter[0]), 2.0) * cos(angle_filter[1]) + cos(angle_filter[1]) * pow(sin(angle_filter[0]), 2.0))) + sensor_gyro[1] * ((DT * cos(angle_filter[0]) * (cos(angle_filter[2]) * sin(angle_filter[0]) + cos(angle_filter[0]) * sin(angle_filter[2]) * sin(angle_filter[1]))) / (pow(cos(angle_filter[0]), 2.0) * cos(angle_filter[1]) + cos(angle_filter[1]) * pow(sin(angle_filter[0]), 2.0)) - (DT * sin(angle_filter[0]) * (cos(angle_filter[0]) * cos(angle_filter[2]) - sin(angle_filter[0]) * sin(angle_filter[2]) * sin(angle_filter[1]))) / (pow(cos(angle_filter[0]), 2.0) * cos(angle_filter[1]) + cos(angle_filter[1]) * pow(sin(angle_filter[0]), 2.0)));

		angle_gyro[0] = angle_gyro[0] * GYR_FORGET_FAC;
		angle_gyro[1] = angle_gyro[1] * GYR_FORGET_FAC;
		angle_gyro[2] = angle_gyro[2] * GYR_FORGET_FAC;

		// Complementary filter
		angle_filter[0] = (1 - GAMMA) * angle_acc[0] + GAMMA * angle_gyro[0];
		angle_filter[1] = (1 - GAMMA) * angle_acc[1] + GAMMA * angle_gyro[1];
		angle_filter[2] = (1 - GAMMA) * angle_acc[2] + GAMMA * angle_gyro[2];

		// Save shared resource
		if( xSemaphoreTake( stateSemaphore, (TickType_t) 1 ) == pdTRUE ){
			state[0] = angle_filter[0];
			state[1] = angle_filter[1];
			state[2] = sensor_gyro[0];
			state[3] = sensor_gyro[1];
			state[4] = sensor_gyro[2];
			xSemaphoreGive(stateSemaphore);
		}	

		// Give the semaphore to the control thread
		
		// sleep until next time step
		vTaskDelayUntil(&lastWakeTime, F2T(RATE_100_HZ));
	}
}

/* 	Main function that is called after initing the sensor and motors
 	Executes three threads which will:
		estimate states based on measurements
		calculate control input and inputs to the motors 
		read from reference (cellphone)
*/
void yourCodeInit(void){
	stateSemaphore = xSemaphoreCreateBinary();
	xSemaphoreGive( stateSemaphore );
	refSemaphore = xSemaphoreCreateBinary();
	xSemaphoreGive( refSemaphore );
	calSemaphore = xSemaphoreCreateBinary();
	xSemaphoreGive( calSemaphore );
	xSemaphoreTake( calSemaphore, (TickType_t) 1 );

	xTaskCreate(compFilter, "Complementary Filter", 1024, NULL, 4, NULL);
	xTaskCreate(updateControlInput, "Controller", 1024, NULL, 3, NULL);
	xTaskCreate(updateReference, "Reference", 1024, NULL, 2, NULL);
}


// Add ONLINE tuning parameters to the Graphic User Interface
PARAM_GROUP_START(AA_STAB)
PARAM_ADD(PARAM_FLOAT, factor_ref, &factor_ref)
PARAM_ADD(PARAM_FLOAT, fac_fb_rp, &fac_fb_rp)
PARAM_ADD(PARAM_FLOAT, fac_fb_v, &fac_fb_v)
PARAM_ADD(PARAM_FLOAT, fac_fb_yr, &fac_fb_yr)
PARAM_ADD(PARAM_FLOAT, GAMMA, &GAMMA)
PARAM_ADD(PARAM_FLOAT, GYR_FORGET_FAC, &GYR_FORGET_FAC)
PARAM_ADD(PARAM_FLOAT, ADD_THRUST, &ADD_THRUST)
PARAM_GROUP_STOP(AA_STAB)


// Add signals to be ploted in the GUI
LOG_GROUP_START(AA_thrust)
LOG_ADD(LOG_FLOAT, tx, &setpoint.thrust)
LOG_ADD(LOG_FLOAT, ty, &setpoint.thrust)
LOG_ADD(LOG_FLOAT, tz, &setpoint.thrust)
LOG_GROUP_STOP(AA_thrust)

LOG_GROUP_START(AA_gyro)
LOG_ADD(LOG_FLOAT, x, &sensorData.gyro.x)
LOG_ADD(LOG_FLOAT, y, &sensorData.gyro.y)
LOG_ADD(LOG_FLOAT, z, &sensorData.gyro.z)
LOG_GROUP_STOP(AA_gyro)

LOG_GROUP_START(AA_angle_filter)
LOG_ADD(LOG_FLOAT, roll,  &angle_filter[0])
LOG_ADD(LOG_FLOAT, pitch, &angle_filter[1])
LOG_ADD(LOG_FLOAT, yaw,   &angle_filter[2])
LOG_GROUP_STOP(AA_angle_filter)

LOG_GROUP_START(AA_angle_acc)
LOG_ADD(LOG_FLOAT, roll,  &angle_acc[0])
LOG_ADD(LOG_FLOAT, pitch, &angle_acc[1])
LOG_ADD(LOG_FLOAT, yaw,   &angle_acc[2])
LOG_GROUP_STOP(AA_angle_acc)

LOG_GROUP_START(AA_angle_gyro)
LOG_ADD(LOG_FLOAT, roll,  &angle_gyro[0])
LOG_ADD(LOG_FLOAT, pitch, &angle_gyro[1])
LOG_ADD(LOG_FLOAT, yaw,   &angle_gyro[2])
LOG_GROUP_STOP(AA_angle_gyro)

LOG_GROUP_START(AA_motor)
LOG_ADD(LOG_FLOAT, motor_1, &motor_values[0])
LOG_ADD(LOG_FLOAT, motor_2, &motor_values[1])
LOG_ADD(LOG_FLOAT, motor_3, &motor_values[2])
LOG_ADD(LOG_FLOAT, motor_4, &motor_values[3])
LOG_GROUP_STOP(AA_motor)



/*************************************************
 * WAIT FOR SENSORS TO BE CALIBRATED
 ************************************************/
// lastWakeTime = xTaskGetTickCount ();
// while(!sensorsAreCalibrated()) {
//     vTaskDelayUntil(&lastWakeTime, F2T(RATE_MAIN_LOOP));
// }

/*************************************************
 * RETRIEVE THE MOST RECENT SENSOR DATA
 *
 * The code creates a variable called sensorData and then calls a function
 * that fills this variable with the latest data from the sensors.
 *
 * sensorData_t sensorData = struct {
 *     Axis3f acc;
 *     Axis3f gyro;
 *     Axis3f mag;
 *     baro_t baro;
 *     zDistance_t zrange;
 *     point_t position;
 * }
 *
 ************************************************/
// sensorData_t sensorData;
// sensorsAcquire(&sensorData);

/*************************************************
 * RETRIEVE THE SET POINT FROM ANY EXTERNAL COMMAND INTERFACE
 *
 * The code creates a variable called setpoint and then calls a function
 * that fills this variable with the latest command input.
 *
 * setpoint_t setpoint = struct {
 *     uint32_t timestamp;
 *
 *     attitude_t attitude;      // deg
 *     attitude_t attitudeRate;  // deg/s
 *     quaternion_t attitudeQuaternion;
 *     float thrust;
 *     point_t position;         // m
 *     velocity_t velocity;      // m/s
 *     acc_t acceleration;       // m/s^2
 *     bool velocity_body;       // true if velocity is given in body frame; false if velocity is given in world frame
 *
 *     struct {
 *         stab_mode_t x;
 *         stab_mode_t y;
 *         stab_mode_t z;
 *         stab_mode_t roll;
 *         stab_mode_t pitch;
 *         stab_mode_t yaw;
 *         stab_mode_t quat;
 *     } mode;
 * }
 *
 ************************************************/
// setpoint_t setpoint;
// commanderGetSetpoint(&setpoint);

/*************************************************
 * SENDING OUTPUT TO THE MOTORS
 *
 * The code sends an output to each motor. The output should have the be
 * of the typ unsigned 16-bit integer, i.e. use variables such as:
 * uint16_t value_i
 *
 ************************************************/
// motorsSetRatio(MOTOR_M1, value_1);
// motorsSetRatio(MOTOR_M2, value_2);
// motorsSetRatio(MOTOR_M3, value_3);
// motorsSetRatio(MOTOR_M4, value_4);

/*************************************************
 * LOGGING VALUES THAT CAN BE PLOTTEN IN PYTHON CLIENT
 *
 * We have already set up three log blocks to for the accelerometer data, the
 * gyro data and the setpoints, just uncomment the block to start logging. Use
 * them as reference if you want to add custom blocks.
 *
 ************************************************/

/*
LOG_GROUP_START(acc)
LOG_ADD(LOG_FLOAT, x, &sensorData.acc.x)
LOG_ADD(LOG_FLOAT, y, &sensorData.acc.y)
LOG_ADD(LOG_FLOAT, z, &sensorData.acc.z)
LOG_GROUP_STOP(acc)
*/

/*
LOG_GROUP_START(gyro)
LOG_ADD(LOG_FLOAT, x, &sensorData.gyro.x)
LOG_ADD(LOG_FLOAT, y, &sensorData.gyro.y)
LOG_ADD(LOG_FLOAT, z, &sensorData.gyro.z)
LOG_GROUP_STOP(gyro)
*/

/*
LOG_GROUP_START(ctrltarget)
LOG_ADD(LOG_FLOAT, roll, &setpoint.attitude.roll)
LOG_ADD(LOG_FLOAT, pitch, &setpoint.attitude.pitch)
LOG_ADD(LOG_FLOAT, yaw, &setpoint.attitudeRate.yaw)
LOG_GROUP_STOP(ctrltarget)
*/


