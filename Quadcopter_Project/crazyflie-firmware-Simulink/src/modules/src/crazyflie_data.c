/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: crazyflie_data.c
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

/* Constant parameters (default storage) */
const ConstP rtConstP = {
  /* Expression: -K_fb_int
   * Referenced by: '<S2>/Gain'
   */
  { -0.0, -0.0, -0.0, -0.0, 0.10626465046562551, -0.1062646504493221,
    -0.10626465044914644, 0.10626465046545212, -0.0, -0.0, -0.0, -0.0,
    0.0115677637549339, -0.011567763754828705, -0.011567763754827791,
    0.011567763754932998, 0.019813833458184067, -0.019813833458185225,
    0.019813833458184049, -0.0198138334581852, -0.0, -0.0, -0.0, -0.0,
    -0.00010506162939557485, 0.0001050616294579094, 0.00010506162945753788,
    -0.00010506162939524811, -6.236093036125347E-5, 6.2360930361495708E-5,
    -6.2360930361244824E-5, 6.2360930361487062E-5 },

  /* Expression: [0 30 0]'
   * Referenced by: '<Root>/Constant1'
   */
  { 0.0, 30.0, 0.0 },

  /* Expression: H
   * Referenced by: '<S2>/Gain1'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /* Computed Parameter: Logic_table
   * Referenced by: '<S8>/Logic'
   */
  { 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
