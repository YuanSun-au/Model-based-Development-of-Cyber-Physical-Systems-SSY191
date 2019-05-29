/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: crazyflie.c
 *
 * Code generated for Simulink model 'crazyflie'.
 *
 * Model version                  : 1.262
 * Simulink Coder version         : 9.1 (R2019a) 23-Nov-2018
 * C/C++ source code generated on : Thu May  9 18:00:38 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "crazyflie.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Forward declaration for local functions */
static real_T norm(const real_T x[3]);

/* Function for MATLAB Function: '<S1>/complementary filter' */
static real_T norm(const real_T x[3])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 3.3121686421112381E-170;
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

/* Model step function */
void crazyflie_step(void)
{
  real_T T_angleder2w[9];
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  real_T b_x[9];
  int32_T p2;
  int32_T p3;
  static const int8_T b[3] = { 0, 0, 1 };

  real_T rtb_deg2rad7[3];
  real_T rtb_deg2rad8[3];
  real_T rtb_Switch[4];
  real_T tmp[9];
  real_T c[9];
  real_T tmp_0[9];
  real_T tmp_1[3];
  real_T rtb_deg2rad7_0[8];
  real_T tmp_2[4];
  real_T rtb_deg2rad7_1[5];
  real_T rtb_z_idx_1;
  real_T rtb_z_idx_2;
  real_T rtb_z_idx_0;
  real_T T_angleder2w_tmp;
  real_T T_angleder2w_tmp_0;
  real_T T_angleder2w_tmp_1;
  real_T scale_tmp;
  int32_T c_tmp;

  /* Delay: '<S1>/Delay' */
  if (rtDW.icLoad != 0) {
    rtDW.Delay_DSTATE[0] = 0.3490658503988659;
    rtDW.Delay_DSTATE[1] = 0.3490658503988659;
    rtDW.Delay_DSTATE[2] = 0.0;
  }

  /* Gain: '<Root>/deg2rad7' incorporates:
   *  Inport: '<Root>/Acc_x'
   *  Inport: '<Root>/Acc_y'
   *  Inport: '<Root>/Acc_z'
   */
  rtb_deg2rad7[0] = 0.017453292519943295 * rtU.Acc_x;
  rtb_deg2rad7[1] = 0.017453292519943295 * rtU.Acc_y;
  rtb_deg2rad7[2] = 0.017453292519943295 * rtU.Acc_z;

  /* Gain: '<Root>/deg2rad8' incorporates:
   *  Inport: '<Root>/Gyro_x'
   *  Inport: '<Root>/Gyro_y'
   *  Inport: '<Root>/Gyro_z'
   */
  rtb_deg2rad8[0] = 0.017453292519943295 * rtU.Gyro_x;
  rtb_deg2rad8[1] = 0.017453292519943295 * rtU.Gyro_y;
  rtb_deg2rad8[2] = 0.017453292519943295 * rtU.Gyro_z;

  /* MATLAB Function: '<S1>/complementary filter' incorporates:
   *  Delay: '<S1>/Delay'
   *  SampleTimeMath: '<S1>/Weighted Sample Time'
   *
   * About '<S1>/Weighted Sample Time':
   *  y = K where K = ( w * Ts )
   */
  rtb_z_idx_0 = rtb_deg2rad7[0];
  rtb_z_idx_1 = rtb_deg2rad7[1];
  rtb_z_idx_2 = rtb_deg2rad7[2];

  /*  initialize output */
  /* MATLAB Function 'Pitch and Roll angles estimator/complementary filter': '<S4>:1' */
  /* '<S4>:1:4' angle_filter = zeros(3,1); */
  /*     %%  tunning parameters */
  /* '<S4>:1:8' alpha = 0.05; */
  /* '<S4>:1:9' gamma = alpha / ( dt + alpha ); */
  /*      gamma = 1; */
  /*     %% Acceleration observer */
  /*  normalize acceleration measurements */
  /* '<S4>:1:15' if norm(acc) ~= 0 */
  scale = norm(rtb_deg2rad7);
  if (scale != 0.0) {
    /* '<S4>:1:16' acc = acc / norm(acc); */
    rtb_z_idx_0 = rtb_deg2rad7[0] / scale;
    rtb_z_idx_1 = rtb_deg2rad7[1] / scale;
    rtb_z_idx_2 = rtb_deg2rad7[2] / scale;
  }

  /*  calculate rotation angles based on acceleration sensor */
  /* '<S4>:1:20' theta = atan2(-acc(1), norm([acc(2), acc(3)] )); */
  scale = 3.3121686421112381E-170;
  absxk = fabs(rtb_z_idx_1);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(rtb_z_idx_2);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  y = scale * sqrt(y);

  /* '<S4>:1:21' phi   = atan2(acc(2), acc(3)); */
  /* '<S4>:1:22' angle_acc = [phi theta 0]'; */
  /*     %% Gyro observer */
  /* '<S4>:1:27' phi   = old_angle(1); */
  /* '<S4>:1:28' theta = old_angle(2); */
  /* '<S4>:1:29' psi   = old_angle(3); */
  /* '<S4>:1:31' rotx  = [1 0        0;  */
  /* '<S4>:1:32'              0 cos(phi) -sin(phi); */
  /* '<S4>:1:33'              0 sin(phi) cos(phi)]; */
  /* '<S4>:1:34' roty  = [cos(theta)  0 sin(theta);  */
  /* '<S4>:1:35'              0           1 0;  */
  /* '<S4>:1:36'              -sin(theta) 0 cos(theta)]; */
  /* '<S4>:1:37' rotz  = [cos(psi) -sin(psi) 0;  */
  /* '<S4>:1:38'              sin(psi)  cos(psi) 0;  */
  /* '<S4>:1:39'              0         0        1]; */
  /* '<S4>:1:40' R_b2w = (rotx * roty * rotz); */
  /* '<S4>:1:42' T_angleder2w = [ 1,        0,            sin(theta) */
  /* '<S4>:1:43'                      0, cos(phi),  -cos(theta)*sin(phi) */
  /* '<S4>:1:44'                      0, sin(phi),   cos(phi)*cos(theta)]; */
  T_angleder2w[0] = 1.0;
  T_angleder2w[3] = 0.0;
  t = sin(rtDW.Delay_DSTATE[1]);
  T_angleder2w[6] = t;
  T_angleder2w[1] = 0.0;
  T_angleder2w_tmp_0 = cos(rtDW.Delay_DSTATE[0]);
  T_angleder2w[4] = T_angleder2w_tmp_0;
  T_angleder2w_tmp = sin(rtDW.Delay_DSTATE[0]);
  T_angleder2w_tmp_1 = cos(rtDW.Delay_DSTATE[1]);
  T_angleder2w[7] = -T_angleder2w_tmp_1 * T_angleder2w_tmp;
  T_angleder2w[2] = 0.0;
  T_angleder2w[5] = T_angleder2w_tmp;
  T_angleder2w[8] = T_angleder2w_tmp_0 * T_angleder2w_tmp_1;

  /*  calculate rotation angles based on gyro sensor */
  /* '<S4>:1:47' angle_gyro = old_angle + dt * inv(T_angleder2w) * R_b2w * gyro; */
  memcpy(&b_x[0], &T_angleder2w[0], 9U * sizeof(real_T));
  p2 = 3;
  p3 = 6;
  scale_tmp = b_x[1] / b_x[0];
  b_x[1] = scale_tmp;
  scale = b_x[2] / b_x[0];
  b_x[2] = scale;
  b_x[4] -= scale_tmp * b_x[3];
  b_x[5] -= scale * b_x[3];
  b_x[7] -= scale_tmp * b_x[6];
  b_x[8] -= scale * b_x[6];
  if (fabs(b_x[5]) > fabs(b_x[4])) {
    p2 = 6;
    p3 = 3;
    b_x[1] = scale;
    b_x[2] = scale_tmp;
    scale = b_x[4];
    b_x[4] = b_x[5];
    b_x[5] = scale;
    scale = b_x[7];
    b_x[7] = b_x[8];
    b_x[8] = scale;
  }

  scale_tmp = b_x[5] / b_x[4];
  b_x[8] -= scale_tmp * b_x[7];
  scale = (scale_tmp * b_x[1] - b_x[2]) / b_x[8];
  absxk = -(b_x[7] * scale + b_x[1]) / b_x[4];
  T_angleder2w[0] = ((1.0 - b_x[3] * absxk) - b_x[6] * scale) / b_x[0];
  T_angleder2w[1] = absxk;
  T_angleder2w[2] = scale;
  scale = -scale_tmp / b_x[8];
  absxk = (1.0 - b_x[7] * scale) / b_x[4];
  T_angleder2w[p2] = -(b_x[3] * absxk + b_x[6] * scale) / b_x[0];
  T_angleder2w[p2 + 1] = absxk;
  T_angleder2w[p2 + 2] = scale;
  scale = 1.0 / b_x[8];
  absxk = -b_x[7] * scale / b_x[4];
  T_angleder2w[p3] = -(b_x[3] * absxk + b_x[6] * scale) / b_x[0];
  T_angleder2w[p3 + 1] = absxk;
  T_angleder2w[p3 + 2] = scale;

  /*   */
  /*     %% Sensor Fusion */
  /*  fuse acc and gyro sensor to estimate rotation */
  /* '<S4>:1:53' angle_filter = (1 - gamma) * angle_acc  + gamma * angle_gyro; */
  b_x[1] = 0.0;
  b_x[4] = T_angleder2w_tmp_0;
  b_x[7] = -T_angleder2w_tmp;
  b_x[2] = 0.0;
  b_x[5] = T_angleder2w_tmp;
  b_x[8] = T_angleder2w_tmp_0;
  tmp[0] = T_angleder2w_tmp_1;
  tmp[3] = 0.0;
  tmp[6] = t;
  b_x[0] = 1.0;
  tmp[1] = 0.0;
  b_x[3] = 0.0;
  tmp[4] = 1.0;
  b_x[6] = 0.0;
  tmp[7] = 0.0;
  tmp[2] = -t;
  tmp[5] = 0.0;
  tmp[8] = T_angleder2w_tmp_1;
  scale = cos(rtDW.Delay_DSTATE[2]);
  tmp_0[0] = scale;
  absxk = sin(rtDW.Delay_DSTATE[2]);
  tmp_0[3] = -absxk;
  tmp_0[6] = 0.0;
  tmp_0[1] = absxk;
  tmp_0[4] = scale;
  tmp_0[7] = 0.0;
  for (p2 = 0; p2 < 3; p2++) {
    for (p3 = 0; p3 < 3; p3++) {
      c_tmp = p2 + 3 * p3;
      c[c_tmp] = 0.0;
      c[c_tmp] += tmp[3 * p3] * b_x[p2];
      c[c_tmp] += tmp[3 * p3 + 1] * b_x[p2 + 3];
      c[c_tmp] += tmp[3 * p3 + 2] * b_x[p2 + 6];
    }

    tmp_0[2 + 3 * p2] = b[p2];
  }

  for (p2 = 0; p2 < 3; p2++) {
    for (p3 = 0; p3 < 3; p3++) {
      c_tmp = p3 + 3 * p2;
      b_x[c_tmp] = 0.0;
      b_x[c_tmp] += tmp_0[3 * p2] * c[p3];
      b_x[c_tmp] += tmp_0[3 * p2 + 1] * c[p3 + 3];
      b_x[c_tmp] += tmp_0[3 * p2 + 2] * c[p3 + 6];
    }
  }

  tmp_1[0] = 0.16666666666666674 * atan2(rtb_z_idx_1, rtb_z_idx_2);
  tmp_1[1] = 0.16666666666666674 * atan2(-rtb_z_idx_0, y);
  tmp_1[2] = 0.0;
  for (p2 = 0; p2 < 3; p2++) {
    scale = 0.0;
    for (p3 = 0; p3 < 3; p3++) {
      c_tmp = p2 + 3 * p3;
      tmp[c_tmp] = 0.0;
      tmp[c_tmp] += 0.01 * T_angleder2w[p2] * b_x[3 * p3];
      tmp[c_tmp] += T_angleder2w[p2 + 3] * 0.01 * b_x[3 * p3 + 1];
      tmp[c_tmp] += T_angleder2w[p2 + 6] * 0.01 * b_x[3 * p3 + 2];
      scale += tmp[c_tmp] * rtb_deg2rad8[p3];
    }

    rtb_deg2rad7[p2] = (rtDW.Delay_DSTATE[p2] + scale) * 0.83333333333333326 +
      tmp_1[p2];
  }

  /* End of MATLAB Function: '<S1>/complementary filter' */

  /* DiscreteIntegrator: '<S2>/Accumulator' */
  if (rtDW.Accumulator_PrevResetState == 1) {
    rtDW.Accumulator_DSTATE[0] = 0.0;
    rtDW.Accumulator_DSTATE[1] = 0.0;
    rtDW.Accumulator_DSTATE[2] = 0.0;
  }

  /* CombinatorialLogic: '<S8>/Logic' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   *  Memory: '<S8>/Memory'
   */
  /* MATLAB Function 'safety_box/MATLAB Function': '<S7>:1' */
  /* '<S7>:1:3' y = abs(u(1)) > deg2rad(60) || abs(u(2)) > deg2rad(60); */
  c_tmp = (int32_T)(((uint32_T)((fabs(rtb_deg2rad7[0]) > 1.0471975511965976) ||
    (fabs(rtb_deg2rad7[1]) > 1.0471975511965976)) << 1) +
                    rtDW.Memory_PreviousInput);

  /* Switch: '<S3>/Switch' incorporates:
   *  CombinatorialLogic: '<S8>/Logic'
   */
  if (rtConstP.Logic_table[(uint32_T)c_tmp]) {
    /* SignalConversion: '<S2>/TmpSignal ConversionAtGainInport1' incorporates:
     *  DiscreteIntegrator: '<S2>/Accumulator'
     */
    rtb_deg2rad7_0[0] = rtb_deg2rad7[0];
    rtb_deg2rad7_0[1] = rtb_deg2rad7[1];
    rtb_deg2rad7_0[2] = rtb_deg2rad8[0];
    rtb_deg2rad7_0[5] = rtDW.Accumulator_DSTATE[0];
    rtb_deg2rad7_0[3] = rtb_deg2rad8[1];
    rtb_deg2rad7_0[6] = rtDW.Accumulator_DSTATE[1];
    rtb_deg2rad7_0[4] = rtb_deg2rad8[2];
    rtb_deg2rad7_0[7] = rtDW.Accumulator_DSTATE[2];

    /* Gain: '<S2>/Gain' incorporates:
     *  Constant: '<Root>/Constant'
     *  Gain: '<S2>/Thrust converter'
     *  Saturate: '<S2>/Saturation'
     *  SignalConversion: '<S2>/TmpSignal ConversionAtGainInport1'
     *  Sum: '<S2>/Add1'
     */
    for (p2 = 0; p2 < 4; p2++) {
      tmp_2[p2] = 0.0;
      for (p3 = 0; p3 < 8; p3++) {
        tmp_2[p2] += rtConstP.Gain_Gain[(p3 << 2) + p2] * rtb_deg2rad7_0[p3];
      }

      rtb_Switch[p2] = fmax(445368.67142371729 * tmp_2[p2], 0.0) +
        14563.555555555557;
    }

    /* End of Gain: '<S2>/Gain' */
  } else {
    rtb_Switch[0] = 0.0;
    rtb_Switch[1] = 0.0;
    rtb_Switch[2] = 0.0;
    rtb_Switch[3] = 0.0;
  }

  /* End of Switch: '<S3>/Switch' */

  /* DataTypeConversion: '<Root>/ToUint16' */
  if (rtb_Switch[0] < 65536.0) {
    /* Outport: '<Root>/Motor_1' */
    rtY.Motor_1 = (uint16_T)rtb_Switch[0];
  } else {
    /* Outport: '<Root>/Motor_1' */
    rtY.Motor_1 = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<Root>/ToUint16' */

  /* DataTypeConversion: '<Root>/ToUint16_1' */
  if (rtb_Switch[1] < 65536.0) {
    /* Outport: '<Root>/Motor_2' */
    rtY.Motor_2 = (uint16_T)rtb_Switch[1];
  } else {
    /* Outport: '<Root>/Motor_2' */
    rtY.Motor_2 = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<Root>/ToUint16_1' */

  /* DataTypeConversion: '<Root>/ToUint16_2' */
  if (rtb_Switch[2] < 65536.0) {
    /* Outport: '<Root>/Motor_3' */
    rtY.Motor_3 = (uint16_T)rtb_Switch[2];
  } else {
    /* Outport: '<Root>/Motor_3' */
    rtY.Motor_3 = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<Root>/ToUint16_2' */

  /* DataTypeConversion: '<Root>/ToUint16_3' */
  if (rtb_Switch[3] < 65536.0) {
    /* Outport: '<Root>/Motor_4' */
    rtY.Motor_4 = (uint16_T)rtb_Switch[3];
  } else {
    /* Outport: '<Root>/Motor_4' */
    rtY.Motor_4 = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<Root>/ToUint16_3' */

  /* Outport: '<Root>/Log1' incorporates:
   *  Gain: '<Root>/rad2deg1'
   */
  rtY.Log1 = 57.295779513082323 * rtb_deg2rad7[0];

  /* Outport: '<Root>/Log2' incorporates:
   *  Gain: '<Root>/rad2deg1'
   */
  rtY.Log2 = 57.295779513082323 * rtb_deg2rad7[1];

  /* Outport: '<Root>/Log3' incorporates:
   *  Gain: '<Root>/rad2deg1'
   */
  rtY.Log3 = 57.295779513082323 * rtb_deg2rad7[2];

  /* Update for Delay: '<S1>/Delay' */
  rtDW.Delay_DSTATE[0] = rtb_deg2rad7[0];
  rtDW.Delay_DSTATE[1] = rtb_deg2rad7[1];
  rtDW.Delay_DSTATE[2] = rtb_deg2rad7[2];

  /* Outport: '<Root>/Log4' incorporates:
   *  Gain: '<Root>/rad2deg2'
   */
  rtY.Log4 = 57.295779513082323 * rtb_deg2rad8[0];

  /* Outport: '<Root>/Log5' incorporates:
   *  Gain: '<Root>/rad2deg2'
   */
  rtY.Log5 = 57.295779513082323 * rtb_deg2rad8[1];

  /* Outport: '<Root>/Log6' incorporates:
   *  Gain: '<Root>/rad2deg2'
   */
  rtY.Log6 = 57.295779513082323 * rtb_deg2rad8[2];

  /* Update for Delay: '<S1>/Delay' */
  rtDW.icLoad = 0U;

  /* SignalConversion: '<S2>/TmpSignal ConversionAtGain1Inport1' */
  rtb_deg2rad7_1[0] = rtb_deg2rad7[0];
  rtb_deg2rad7_1[1] = rtb_deg2rad7[1];
  rtb_deg2rad7_1[2] = rtb_deg2rad8[0];
  rtb_deg2rad7_1[3] = rtb_deg2rad8[1];
  rtb_deg2rad7_1[4] = rtb_deg2rad8[2];
  for (p2 = 0; p2 < 3; p2++) {
    /* Sum: '<S2>/Sum' incorporates:
     *  Gain: '<S2>/Gain1'
     *  SignalConversion: '<S2>/TmpSignal ConversionAtGain1Inport1'
     */
    scale = 0.0;
    for (p3 = 0; p3 < 5; p3++) {
      scale += rtConstP.Gain1_Gain[3 * p3 + p2] * rtb_deg2rad7_1[p3];
    }

    /* Update for DiscreteIntegrator: '<S2>/Accumulator' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Gain: '<Root>/deg2rad6'
     *  Gain: '<S2>/Gain1'
     *  Sum: '<S2>/Sum'
     */
    rtDW.Accumulator_DSTATE[p2] += 0.017453292519943295 *
      rtConstP.Constant1_Value_o[p2] - scale;
  }

  /* Update for DiscreteIntegrator: '<S2>/Accumulator' */
  rtDW.Accumulator_PrevResetState = 0;

  /* Update for Memory: '<S8>/Memory' incorporates:
   *  CombinatorialLogic: '<S8>/Logic'
   */
  rtDW.Memory_PreviousInput = rtConstP.Logic_table[(uint32_T)c_tmp];
}

/* Model initialize function */
void crazyflie_initialize(void)
{
  /* InitializeConditions for Delay: '<S1>/Delay' */
  rtDW.icLoad = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Accumulator' */
  rtDW.Accumulator_PrevResetState = 2;

  /* InitializeConditions for Memory: '<S8>/Memory' */
  rtDW.Memory_PreviousInput = true;
}

/* Model terminate function */
void crazyflie_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
