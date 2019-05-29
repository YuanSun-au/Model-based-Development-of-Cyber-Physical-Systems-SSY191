/*
 * crazyflie_data.c
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

/* Constant parameters (default storage) */
const ConstP_crazyflie_T crazyflie_ConstP = {
  /* Expression: -K_fb_int
   * Referenced by: '<S2>/Gain'
   */
  { 0.028301239057865534, 0.028301239057864684, -0.028301239057864889,
    -0.028301239057865316, 0.028538194441132446, -0.028538194441132519,
    -0.028538194441132304, 0.028538194441132363, 0.0027677438619801817,
    0.0027677438619801375, -0.0027677438619801579, -0.0027677438619801609,
    0.0028089509305757555, -0.0028089509305757564, -0.0028089509305757477,
    0.0028089509305757477, 0.0079233285283435, -0.0079233285283434509,
    0.00792332852834347, -0.0079233285283435168, -0.001373333456556733,
    -0.0013733334565566768, 0.0013733334565566898, 0.0013733334565567184,
    -0.0013764102549234246, 0.0013764102549234385, 0.001376410254923417,
    -0.00137641025492343, -0.0012885445970171952, 0.0012885445970171883,
    -0.0012885445970171898, 0.0012885445970171967 },

  /* Expression: H
   * Referenced by: '<S2>/Gain1'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 }
};
