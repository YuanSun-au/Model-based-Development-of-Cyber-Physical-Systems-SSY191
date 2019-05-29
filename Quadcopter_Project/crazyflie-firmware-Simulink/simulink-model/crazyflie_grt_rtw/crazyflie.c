/*
 * crazyflie.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "crazyflie".
 *
 * Model version              : 1.394
 * Simulink Coder version : 9.1 (R2019a) 23-Nov-2018
 * C source code generated on : Wed May  1 19:04:56 2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "crazyflie.h"
#include "crazyflie_private.h"

/* Block states (default storage) */
DW_crazyflie_T crazyflie_DW;

/* External inputs (root inport signals with default storage) */
ExtU_crazyflie_T crazyflie_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_crazyflie_T crazyflie_Y;

/* Real-time model */
RT_MODEL_crazyflie_T crazyflie_M_;
RT_MODEL_crazyflie_T *const crazyflie_M = &crazyflie_M_;

/* Forward declaration for local functions */
static real_T crazyflie_norm(const real_T x[3]);

/* Function for MATLAB Function: '<S1>/complementary filter' */
static real_T crazyflie_norm(const real_T x[3])
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

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void crazyflie_step(void)
{
  /* local block i/o variables */
  real_T rtb_angle_filter[3];
  real_T rtb_Add1[4];
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  real_T rtb_x_I[3];
  real_T rtb_deg2rad4_0[8];
  real_T rtb_deg2rad4_1[5];
  real_T tmp[3];
  int32_T i;
  int32_T i_0;
  real_T rtb_deg2rad4_idx_1;
  real_T rtb_deg2rad4_idx_2;
  real_T rtb_deg2rad4_idx_0;

  /* SignalConversion: '<S3>/TmpSignal ConversionAt SFunction Inport2' incorporates:
   *  Inport: '<Root>/Acc_x'
   *  Inport: '<Root>/Acc_y'
   *  Inport: '<Root>/Acc_z'
   *  MATLAB Function: '<S1>/complementary filter'
   */
  rtb_x_I[0] = crazyflie_U.Acc_x;
  rtb_x_I[1] = crazyflie_U.Acc_y;
  rtb_x_I[2] = crazyflie_U.Acc_z;

  /* MATLAB Function: '<S1>/complementary filter' incorporates:
   *  Delay: '<S1>/Delay'
   *  Inport: '<Root>/Acc_x'
   *  Inport: '<Root>/Acc_y'
   *  Inport: '<Root>/Acc_z'
   *  Inport: '<Root>/Gyro_x'
   *  Inport: '<Root>/Gyro_y'
   *  Inport: '<Root>/Gyro_z'
   *  SampleTimeMath: '<S1>/Weighted Sample Time'
   *
   * About '<S1>/Weighted Sample Time':
   *  y = K where K = ( w * Ts )
   */
  rtb_deg2rad4_idx_0 = crazyflie_U.Acc_x;
  rtb_deg2rad4_idx_1 = crazyflie_U.Acc_y;
  rtb_deg2rad4_idx_2 = crazyflie_U.Acc_z;
  scale = crazyflie_norm(rtb_x_I);
  if (scale != 0.0) {
    rtb_deg2rad4_idx_0 = crazyflie_U.Acc_x / scale;
    rtb_deg2rad4_idx_1 = crazyflie_U.Acc_y / scale;
    rtb_deg2rad4_idx_2 = crazyflie_U.Acc_z / scale;
  }

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
  rtb_angle_filter[0] = (0.01 * crazyflie_U.Gyro_x + crazyflie_DW.Delay_DSTATE[0])
    * 0.83333333333333326 + 57.295779513082323 * rt_atan2d_snf
    (rtb_deg2rad4_idx_1, rtb_deg2rad4_idx_2) * 0.16666666666666674;
  rtb_angle_filter[1] = (0.01 * crazyflie_U.Gyro_y + crazyflie_DW.Delay_DSTATE[1])
    * 0.83333333333333326 + 57.295779513082323 * rt_atan2d_snf
    (-rtb_deg2rad4_idx_0, y) * 0.16666666666666674;
  rtb_angle_filter[2] = (0.01 * crazyflie_U.Gyro_z + crazyflie_DW.Delay_DSTATE[2])
    * 0.83333333333333326;

  /* Gain: '<Root>/deg2rad1' */
  rtb_deg2rad4_idx_0 = 0.017453292519943295 * rtb_angle_filter[0];
  rtb_deg2rad4_idx_1 = 0.017453292519943295 * rtb_angle_filter[1];

  /* Gain: '<Root>/deg2rad' incorporates:
   *  Inport: '<Root>/Gyro_x'
   *  Inport: '<Root>/Gyro_y'
   *  Inport: '<Root>/Gyro_z'
   */
  rtb_x_I[0] = 0.017453292519943295 * crazyflie_U.Gyro_x;
  rtb_x_I[1] = 0.017453292519943295 * crazyflie_U.Gyro_y;
  rtb_x_I[2] = 0.017453292519943295 * crazyflie_U.Gyro_z;

  /* SignalConversion: '<S2>/TmpSignal ConversionAtGainInport1' incorporates:
   *  DiscreteIntegrator: '<S2>/Accumulator'
   */
  rtb_deg2rad4_0[0] = rtb_deg2rad4_idx_0;
  rtb_deg2rad4_0[1] = rtb_deg2rad4_idx_1;
  rtb_deg2rad4_0[2] = rtb_x_I[0];
  rtb_deg2rad4_0[5] = crazyflie_DW.Accumulator_DSTATE[0];
  rtb_deg2rad4_0[3] = rtb_x_I[1];
  rtb_deg2rad4_0[6] = crazyflie_DW.Accumulator_DSTATE[1];
  rtb_deg2rad4_0[4] = rtb_x_I[2];
  rtb_deg2rad4_0[7] = crazyflie_DW.Accumulator_DSTATE[2];
  for (i = 0; i < 4; i++) {
    /* Gain: '<S2>/Gain' incorporates:
     *  SignalConversion: '<S2>/TmpSignal ConversionAtGainInport1'
     */
    rtb_Add1[i] = 0.0;
    for (i_0 = 0; i_0 < 8; i_0++) {
      rtb_Add1[i] += crazyflie_ConstP.Gain_Gain[(i_0 << 2) + i] *
        rtb_deg2rad4_0[i_0];
    }

    /* End of Gain: '<S2>/Gain' */

    /* Sum: '<S2>/Add1' incorporates:
     *  Gain: '<S2>/Thrust converter'
     *  Inport: '<Root>/Base_Thrust'
     */
    rtb_Add1[i] = 445368.67142371729 * rtb_Add1[i] + crazyflie_U.Base_Thrust;
  }

  /* Outport: '<Root>/Log3' */
  crazyflie_Y.Log3 = rtb_Add1[0];

  /* Outport: '<Root>/Log4' */
  crazyflie_Y.Log4 = rtb_Add1[1];

  /* Outport: '<Root>/Log5' */
  crazyflie_Y.Log5 = rtb_Add1[2];

  /* Outport: '<Root>/Log6' */
  crazyflie_Y.Log6 = rtb_Add1[3];

  /* Outport: '<Root>/Log1' */
  crazyflie_Y.Log1 = rtb_angle_filter[0];

  /* Outport: '<Root>/Log2' */
  crazyflie_Y.Log2 = rtb_angle_filter[1];

  /* DataTypeConversion: '<Root>/ToUint16' */
  if (rtb_Add1[0] < 65536.0) {
    if (rtb_Add1[0] >= 0.0) {
      /* Outport: '<Root>/Motor_1' */
      crazyflie_Y.Motor_1 = (uint16_T)rtb_Add1[0];
    } else {
      /* Outport: '<Root>/Motor_1' */
      crazyflie_Y.Motor_1 = 0U;
    }
  } else {
    /* Outport: '<Root>/Motor_1' */
    crazyflie_Y.Motor_1 = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<Root>/ToUint16' */

  /* DataTypeConversion: '<Root>/ToUint16_1' */
  if (rtb_Add1[1] < 65536.0) {
    if (rtb_Add1[1] >= 0.0) {
      /* Outport: '<Root>/Motor_2' */
      crazyflie_Y.Motor_2 = (uint16_T)rtb_Add1[1];
    } else {
      /* Outport: '<Root>/Motor_2' */
      crazyflie_Y.Motor_2 = 0U;
    }
  } else {
    /* Outport: '<Root>/Motor_2' */
    crazyflie_Y.Motor_2 = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<Root>/ToUint16_1' */

  /* DataTypeConversion: '<Root>/ToUint16_2' */
  if (rtb_Add1[2] < 65536.0) {
    if (rtb_Add1[2] >= 0.0) {
      /* Outport: '<Root>/Motor_3' */
      crazyflie_Y.Motor_3 = (uint16_T)rtb_Add1[2];
    } else {
      /* Outport: '<Root>/Motor_3' */
      crazyflie_Y.Motor_3 = 0U;
    }
  } else {
    /* Outport: '<Root>/Motor_3' */
    crazyflie_Y.Motor_3 = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<Root>/ToUint16_2' */

  /* DataTypeConversion: '<Root>/ToUint16_3' */
  if (rtb_Add1[3] < 65536.0) {
    if (rtb_Add1[3] >= 0.0) {
      /* Outport: '<Root>/Motor_4' */
      crazyflie_Y.Motor_4 = (uint16_T)rtb_Add1[3];
    } else {
      /* Outport: '<Root>/Motor_4' */
      crazyflie_Y.Motor_4 = 0U;
    }
  } else {
    /* Outport: '<Root>/Motor_4' */
    crazyflie_Y.Motor_4 = MAX_uint16_T;
  }

  /* End of DataTypeConversion: '<Root>/ToUint16_3' */

  /* Update for Delay: '<S1>/Delay' */
  crazyflie_DW.Delay_DSTATE[0] = rtb_angle_filter[0];
  crazyflie_DW.Delay_DSTATE[1] = rtb_angle_filter[1];
  crazyflie_DW.Delay_DSTATE[2] = rtb_angle_filter[2];

  /* SignalConversion: '<S2>/TmpSignal ConversionAtGain1Inport1' */
  rtb_deg2rad4_1[0] = rtb_deg2rad4_idx_0;
  rtb_deg2rad4_1[1] = rtb_deg2rad4_idx_1;
  rtb_deg2rad4_1[2] = rtb_x_I[0];
  rtb_deg2rad4_1[3] = rtb_x_I[1];
  rtb_deg2rad4_1[4] = rtb_x_I[2];

  /* Gain: '<Root>/deg2rad4' incorporates:
   *  Inport: '<Root>/Ref_Pitch'
   *  Inport: '<Root>/Ref_Roll'
   *  Inport: '<Root>/Ref_YawRate'
   */
  rtb_x_I[0] = 0.017453292519943295 * crazyflie_U.Ref_Roll;
  rtb_x_I[1] = 0.017453292519943295 * crazyflie_U.Ref_Pitch;
  rtb_x_I[2] = 0.017453292519943295 * crazyflie_U.Ref_YawRate;
  for (i = 0; i < 3; i++) {
    /* Gain: '<S2>/Gain1' incorporates:
     *  SignalConversion: '<S2>/TmpSignal ConversionAtGain1Inport1'
     */
    tmp[i] = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      tmp[i] += crazyflie_ConstP.Gain1_Gain[3 * i_0 + i] * rtb_deg2rad4_1[i_0];
    }

    /* End of Gain: '<S2>/Gain1' */

    /* Update for DiscreteIntegrator: '<S2>/Accumulator' incorporates:
     *  Sum: '<S2>/Sum'
     */
    crazyflie_DW.Accumulator_DSTATE[i] += rtb_x_I[i] - tmp[i];
  }

  /* Matfile logging */
  rt_UpdateTXYLogVars(crazyflie_M->rtwLogInfo, (&crazyflie_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(crazyflie_M)!=-1) &&
        !((rtmGetTFinal(crazyflie_M)-crazyflie_M->Timing.taskTime0) >
          crazyflie_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(crazyflie_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++crazyflie_M->Timing.clockTick0)) {
    ++crazyflie_M->Timing.clockTickH0;
  }

  crazyflie_M->Timing.taskTime0 = crazyflie_M->Timing.clockTick0 *
    crazyflie_M->Timing.stepSize0 + crazyflie_M->Timing.clockTickH0 *
    crazyflie_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void crazyflie_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)crazyflie_M, 0,
                sizeof(RT_MODEL_crazyflie_T));
  rtmSetTFinal(crazyflie_M, 25.0);
  crazyflie_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    crazyflie_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(crazyflie_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(crazyflie_M->rtwLogInfo, (NULL));
    rtliSetLogT(crazyflie_M->rtwLogInfo, "tout");
    rtliSetLogX(crazyflie_M->rtwLogInfo, "");
    rtliSetLogXFinal(crazyflie_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(crazyflie_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(crazyflie_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(crazyflie_M->rtwLogInfo, 0);
    rtliSetLogDecimation(crazyflie_M->rtwLogInfo, 1);
    rtliSetLogY(crazyflie_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(crazyflie_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(crazyflie_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&crazyflie_DW, 0,
                sizeof(DW_crazyflie_T));

  /* external inputs */
  (void)memset(&crazyflie_U, 0, sizeof(ExtU_crazyflie_T));

  /* external outputs */
  (void) memset((void *)&crazyflie_Y, 0,
                sizeof(ExtY_crazyflie_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(crazyflie_M->rtwLogInfo, 0.0, rtmGetTFinal
    (crazyflie_M), crazyflie_M->Timing.stepSize0, (&rtmGetErrorStatus
    (crazyflie_M)));

  /* InitializeConditions for Delay: '<S1>/Delay' */
  crazyflie_DW.Delay_DSTATE[0] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Accumulator' */
  crazyflie_DW.Accumulator_DSTATE[0] = 0.0;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  crazyflie_DW.Delay_DSTATE[1] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Accumulator' */
  crazyflie_DW.Accumulator_DSTATE[1] = 0.0;

  /* InitializeConditions for Delay: '<S1>/Delay' */
  crazyflie_DW.Delay_DSTATE[2] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S2>/Accumulator' */
  crazyflie_DW.Accumulator_DSTATE[2] = 0.0;
}

/* Model terminate function */
void crazyflie_terminate(void)
{
  /* (no terminate code required) */
}
