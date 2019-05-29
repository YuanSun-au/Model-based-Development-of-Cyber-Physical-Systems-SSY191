/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: crazyflie.h
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

#ifndef RTW_HEADER_crazyflie_h_
#define RTW_HEADER_crazyflie_h_
#include <math.h>
#include <string.h>
#ifndef crazyflie_COMMON_INCLUDES_
# define crazyflie_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* crazyflie_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE[3];              /* '<S1>/Delay' */
  real_T Accumulator_DSTATE[3];        /* '<S2>/Accumulator' */
  int8_T Accumulator_PrevResetState;   /* '<S2>/Accumulator' */
  uint8_T icLoad;                      /* '<S1>/Delay' */
  boolean_T Memory_PreviousInput;      /* '<S8>/Memory' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: -K_fb_int
   * Referenced by: '<S2>/Gain'
   */
  real_T Gain_Gain[32];

  /* Expression: [0 30 0]'
   * Referenced by: '<Root>/Constant1'
   */
  real_T Constant1_Value_o[3];

  /* Expression: H
   * Referenced by: '<S2>/Gain1'
   */
  real_T Gain1_Gain[15];

  /* Computed Parameter: Logic_table
   * Referenced by: '<S8>/Logic'
   */
  boolean_T Logic_table[16];
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Base_Thrust;                  /* '<Root>/Base_Thrust' */
  real_T Ref_Roll;                     /* '<Root>/Ref_Roll' */
  real_T Ref_Pitch;                    /* '<Root>/Ref_Pitch' */
  real_T Ref_YawRate;                  /* '<Root>/Ref_YawRate' */
  real_T Acc_x;                        /* '<Root>/Acc_x' */
  real_T Acc_y;                        /* '<Root>/Acc_y' */
  real_T Acc_z;                        /* '<Root>/Acc_z' */
  real_T Gyro_x;                       /* '<Root>/Gyro_x' */
  real_T Gyro_y;                       /* '<Root>/Gyro_y' */
  real_T Gyro_z;                       /* '<Root>/Gyro_z' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint16_T Motor_1;                    /* '<Root>/Motor_1' */
  uint16_T Motor_2;                    /* '<Root>/Motor_2' */
  uint16_T Motor_3;                    /* '<Root>/Motor_3' */
  uint16_T Motor_4;                    /* '<Root>/Motor_4' */
  real_T Log1;                         /* '<Root>/Log1' */
  real_T Log2;                         /* '<Root>/Log2' */
  real_T Log3;                         /* '<Root>/Log3' */
  real_T Log4;                         /* '<Root>/Log4' */
  real_T Log5;                         /* '<Root>/Log5' */
  real_T Log6;                         /* '<Root>/Log6' */
} ExtY;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void crazyflie_initialize(void);
extern void crazyflie_step(void);
extern void crazyflie_terminate(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope5 1' : Unused code path elimination
 * Block '<S5>/Compare' : Unused code path elimination
 * Block '<S5>/Constant' : Unused code path elimination
 * Block '<S6>/Delay Input1' : Unused code path elimination
 * Block '<S6>/FixPt Relational Operator' : Unused code path elimination
 * Block '<S2>/Gain2' : Unused code path elimination
 * Block '<S2>/Gain3' : Unused code path elimination
 * Block '<S2>/Scope' : Unused code path elimination
 * Block '<S2>/Scope2' : Unused code path elimination
 * Block '<S2>/zeros' : Unused code path elimination
 * Block '<Root>/rad2deg' : Unused code path elimination
 * Block '<Root>/Manual Switch' : Eliminated due to constant selection input
 * Block '<Root>/Manual Switch1' : Eliminated due to constant selection input
 * Block '<Root>/ToDouble' : Eliminate redundant data type conversion
 * Block '<Root>/ToDouble1' : Eliminate redundant data type conversion
 * Block '<Root>/ToDouble2' : Eliminate redundant data type conversion
 * Block '<Root>/ToDouble3' : Eliminate redundant data type conversion
 * Block '<Root>/ToDouble4' : Eliminate redundant data type conversion
 * Block '<Root>/ToDouble5' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'crazyflie'
 * '<S1>'   : 'crazyflie/Pitch and Roll angles estimator'
 * '<S2>'   : 'crazyflie/State feedback with integral action'
 * '<S3>'   : 'crazyflie/safety_box'
 * '<S4>'   : 'crazyflie/Pitch and Roll angles estimator/complementary filter'
 * '<S5>'   : 'crazyflie/State feedback with integral action/Compare To Zero'
 * '<S6>'   : 'crazyflie/State feedback with integral action/Detect Change'
 * '<S7>'   : 'crazyflie/safety_box/MATLAB Function'
 * '<S8>'   : 'crazyflie/safety_box/S-R Flip-Flop'
 */
#endif                                 /* RTW_HEADER_crazyflie_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
