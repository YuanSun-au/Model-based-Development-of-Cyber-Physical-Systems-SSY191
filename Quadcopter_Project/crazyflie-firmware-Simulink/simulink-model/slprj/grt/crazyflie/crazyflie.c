/*
 * Code generation for system model 'crazyflie'
 *
 * Model                      : crazyflie
 * Model version              : 1.381
 * Simulink Coder version : 9.1 (R2019a) 23-Nov-2018
 * C source code generated on : Wed May  1 18:22:36 2019
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "crazyflie.h"
#include "crazyflie_private.h"
#include "norm_2e9Xj4lM.h"
#include "rt_atan2d_snf.h"

/* System initialize for referenced model: 'crazyflie' */
void crazyflie_Init(DW_crazyflie_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S1>/Delay' */
  localDW->Delay_DSTATE[0] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Accumulator' */
  localDW->Accumulator_DSTATE[0] = 0.0;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  localDW->Delay_DSTATE[1] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Accumulator' */
  localDW->Accumulator_DSTATE[1] = 0.0;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  localDW->Delay_DSTATE[2] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Accumulator' */
  localDW->Accumulator_DSTATE[2] = 0.0;
}

/* System reset for referenced model: 'crazyflie' */
void crazyflie_Reset(DW_crazyflie_f_T *localDW)
{
  /* InitializeConditions for Delay: '<S1>/Delay' */
  localDW->Delay_DSTATE[0] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Accumulator' */
  localDW->Accumulator_DSTATE[0] = 0.0;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  localDW->Delay_DSTATE[1] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Accumulator' */
  localDW->Accumulator_DSTATE[1] = 0.0;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  localDW->Delay_DSTATE[2] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Accumulator' */
  localDW->Accumulator_DSTATE[2] = 0.0;
}

/* Output and update for referenced model: 'crazyflie' */
void crazyflie(const real_T *rtu_Base_Thrust, const real_T *rtu_Ref_Roll, const
               real_T *rtu_Ref_Pitch, const real_T *rtu_Ref_YawRate, const
               real_T *rtu_Acc_x, const real_T *rtu_Acc_y, const real_T
               *rtu_Acc_z, const real_T *rtu_Gyro_x, const real_T *rtu_Gyro_y,
               const real_T *rtu_Gyro_z, uint16_T *rty_Motor_1, uint16_T
               *rty_Motor_2, uint16_T *rty_Motor_3, uint16_T *rty_Motor_4,
               real_T *rty_Log1, real_T *rty_Log2, real_T *rty_Log3, real_T
               *rty_Log4, real_T *rty_Log5, real_T *rty_Log6, DW_crazyflie_f_T
               *localDW)
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  real_T rtb_z[3];
  real_T rtb_x_I[3];
  real_T rtb_Add1[4];
  real_T rtb_Saturation[4];
  real_T rtb_deg2rad4_0[8];
  real_T tmp[4];
  real_T rtb_deg2rad4_1[5];
  real_T tmp_0[3];
  int32_T i;
  int32_T i_0;
  real_T rtb_deg2rad4_idx_1;
  real_T rtb_deg2rad4_idx_2;
  real_T rtb_deg2rad4_idx_0;

  /* SignalConversion: '<S3>/TmpSignal ConversionAt SFunction Inport2' incorporates:
   *  MATLAB Function: '<S1>/complementary filter'
   */
  rtb_x_I[0] = *rtu_Acc_x;
  rtb_x_I[1] = *rtu_Acc_y;
  rtb_x_I[2] = *rtu_Acc_z;

  /* MATLAB Function: '<S1>/complementary filter' incorporates:
   *  Delay: '<S1>/Delay'
   *  SampleTimeMath: '<S1>/Weighted Sample Time'
   *
   * About '<S1>/Weighted Sample Time':
   *  y = K where K = ( w * Ts )
   */
  rtb_deg2rad4_idx_0 = *rtu_Acc_x;
  rtb_deg2rad4_idx_1 = *rtu_Acc_y;
  rtb_deg2rad4_idx_2 = *rtu_Acc_z;

  /* MATLAB Function 'Pitch and Roll angles estimator/complementary filter': '<S3>:1' */
  /* '<S3>:1:4' angle_filter = zeros(3,1); */
  /* '<S3>:1:7' alpha = 0.05; */
  /* '<S3>:1:8' gamma = alpha / ( dt + alpha ); */
  /* '<S3>:1:11' if norm(acc) ~= 0 */
  scale = norm_2e9Xj4lM(rtb_x_I);
  if (scale != 0.0) {
    /* '<S3>:1:12' acc = acc / norm(acc); */
    rtb_deg2rad4_idx_0 = *rtu_Acc_x / scale;
    rtb_deg2rad4_idx_1 = *rtu_Acc_y / scale;
    rtb_deg2rad4_idx_2 = *rtu_Acc_z / scale;
  }

  /* '<S3>:1:16' theta = rad2deg(atan2(-acc(1), norm([acc(2), acc(3)] ))); */
  scale = 3.3121686421112381E-170;
  absxk = fabs(rtb_deg2rad4_idx_1);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(rtb_deg2rad4_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  y = scale * sqrt(y);

  /* '<S3>:1:17' phi   = rad2deg(atan2(acc(2), acc(3))); */
  /* '<S3>:1:18' angle_acc = [phi theta 0]' ; */
  /* '<S3>:1:21' angle_gyro = old_angle + dt * gyro; */
  /* '<S3>:1:24' angle_filter = (1 - gamma) * angle_acc  + gamma * angle_gyro; */
  rtb_x_I[0] = (0.01 * *rtu_Gyro_x + localDW->Delay_DSTATE[0]) *
    0.83333333333333326 + 57.295779513082323 * rt_atan2d_snf(rtb_deg2rad4_idx_1,
    rtb_deg2rad4_idx_2) * 0.16666666666666674;
  rtb_x_I[1] = (0.01 * *rtu_Gyro_y + localDW->Delay_DSTATE[1]) *
    0.83333333333333326 + 57.295779513082323 * rt_atan2d_snf(-rtb_deg2rad4_idx_0,
    y) * 0.16666666666666674;
  rtb_x_I[2] = (0.01 * *rtu_Gyro_z + localDW->Delay_DSTATE[2]) *
    0.83333333333333326;

  /* Gain: '<Root>/deg2rad1' */
  rtb_deg2rad4_idx_0 = 0.017453292519943295 * rtb_x_I[0];
  rtb_deg2rad4_idx_1 = 0.017453292519943295 * rtb_x_I[1];

  /* Gain: '<Root>/deg2rad' */
  rtb_z[0] = 0.017453292519943295 * *rtu_Gyro_x;
  rtb_z[1] = 0.017453292519943295 * *rtu_Gyro_y;
  rtb_z[2] = 0.017453292519943295 * *rtu_Gyro_z;

  /* SignalConversion: '<S2>/TmpSignal ConversionAtGainInport1' incorporates:
   *  DiscreteIntegrator: '<S2>/Accumulator'
   */
  rtb_deg2rad4_0[0] = rtb_deg2rad4_idx_0;
  rtb_deg2rad4_0[1] = rtb_deg2rad4_idx_1;
  rtb_deg2rad4_0[2] = rtb_z[0];
  rtb_deg2rad4_0[5] = localDW->Accumulator_DSTATE[0];
  rtb_deg2rad4_0[3] = rtb_z[1];
  rtb_deg2rad4_0[6] = localDW->Accumulator_DSTATE[1];
  rtb_deg2rad4_0[4] = rtb_z[2];
  rtb_deg2rad4_0[7] = localDW->Accumulator_DSTATE[2];
  for (i = 0; i < 4; i++) {
    /* Gain: '<S2>/Gain' incorporates:
     *  SignalConversion: '<S2>/TmpSignal ConversionAtGainInport1'
     */
    tmp[i] = 0.0;
    for (i_0 = 0; i_0 < 8; i_0++) {
      tmp[i] += rtCP_Gain_Gain[(i_0 << 2) + i] * rtb_deg2rad4_0[i_0];
    }

    /* End of Gain: '<S2>/Gain' */

    /* Sum: '<S2>/Add1' incorporates:
     *  Gain: '<S2>/Thrust converter'
     */
    rtb_deg2rad4_idx_2 = 445368.67142371729 * tmp[i] + *rtu_Base_Thrust;

    /* Saturate: '<Root>/Saturation' */
    if (rtb_deg2rad4_idx_2 > 65536.0) {
      rtb_Saturation[i] = 65536.0;
    } else if (rtb_deg2rad4_idx_2 < 0.0) {
      rtb_Saturation[i] = 0.0;
    } else {
      rtb_Saturation[i] = rtb_deg2rad4_idx_2;
    }

    /* End of Saturate: '<Root>/Saturation' */

    /* Sum: '<S2>/Add1' incorporates:
     *  Gain: '<S2>/Thrust converter'
     */
    rtb_Add1[i] = rtb_deg2rad4_idx_2;
  }

  /* SignalConversion: '<S2>/TmpSignal ConversionAtGain1Inport1' */
  rtb_deg2rad4_1[0] = rtb_deg2rad4_idx_0;
  rtb_deg2rad4_1[1] = rtb_deg2rad4_idx_1;
  rtb_deg2rad4_1[2] = rtb_z[0];
  rtb_deg2rad4_1[3] = rtb_z[1];
  rtb_deg2rad4_1[4] = rtb_z[2];

  /* DataTypeConversion: '<Root>/ToDouble' */
  *rty_Log1 = rtb_x_I[0];

  /* DataTypeConversion: '<Root>/ToDouble1' */
  *rty_Log2 = rtb_x_I[1];

  /* DataTypeConversion: '<Root>/ToDouble2' */
  *rty_Log3 = rtb_Add1[0];

  /* DataTypeConversion: '<Root>/ToDouble3' */
  *rty_Log4 = rtb_Add1[1];

  /* DataTypeConversion: '<Root>/ToDouble4' */
  *rty_Log5 = rtb_Add1[2];

  /* DataTypeConversion: '<Root>/ToDouble5' */
  *rty_Log6 = rtb_Add1[3];

  /* DataTypeConversion: '<Root>/ToUint16' */
  if (rtb_Saturation[0] < 65536.0) {
    *rty_Motor_1 = (uint16_T)rtb_Saturation[0];
  } else {
    *rty_Motor_1 = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<Root>/ToUint16' */

  /* DataTypeConversion: '<Root>/ToUint16_1' */
  if (rtb_Saturation[1] < 65536.0) {
    *rty_Motor_2 = (uint16_T)rtb_Saturation[1];
  } else {
    *rty_Motor_2 = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<Root>/ToUint16_1' */

  /* DataTypeConversion: '<Root>/ToUint16_2' */
  if (rtb_Saturation[2] < 65536.0) {
    *rty_Motor_3 = (uint16_T)rtb_Saturation[2];
  } else {
    *rty_Motor_3 = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<Root>/ToUint16_2' */

  /* DataTypeConversion: '<Root>/ToUint16_3' */
  if (rtb_Saturation[3] < 65536.0) {
    *rty_Motor_4 = (uint16_T)rtb_Saturation[3];
  } else {
    *rty_Motor_4 = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<Root>/ToUint16_3' */

  /* Gain: '<Root>/deg2rad4' */
  tmp_0[0] = 0.017453292519943295 * *rtu_Ref_Roll;
  tmp_0[1] = 0.017453292519943295 * *rtu_Ref_Pitch;
  tmp_0[2] = 0.017453292519943295 * *rtu_Ref_YawRate;
  for (i = 0; i < 3; i++) {
    /* Gain: '<S2>/Gain1' incorporates:
     *  SignalConversion: '<S2>/TmpSignal ConversionAtGain1Inport1'
     */
    rtb_z[i] = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      rtb_z[i] += rtCP_Gain1_Gain[3 * i_0 + i] * rtb_deg2rad4_1[i_0];
    }

    /* End of Gain: '<S2>/Gain1' */

    /* Update for Delay: '<S1>/Delay' */
    localDW->Delay_DSTATE[i] = rtb_x_I[i];

    /* Update for DiscreteIntegrator: '<S2>/Accumulator' incorporates:
     *  Sum: '<S2>/Sum'
     */
    localDW->Accumulator_DSTATE[i] += tmp_0[i] - rtb_z[i];
  }
}

/* Model initialize function */
void crazyflie_initialize(const char_T **rt_errorStatus, RT_MODEL_crazyflie_T *
  const crazyflie_M, DW_crazyflie_f_T *localDW)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(crazyflie_M, rt_errorStatus);

  /* states (dwork) */
  (void) memset((void *)localDW, 0,
                sizeof(DW_crazyflie_f_T));
}
