/*
 * open_loop_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "open_loop".
 *
 * Model version              : 1.107
 * Simulink Coder version : 9.1 (R2019a) 23-Nov-2018
 * C source code generated on : Wed May  1 18:27:18 2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "open_loop.h"
#include "open_loop_private.h"

/* Block parameters (default storage) */
P_open_loop_T open_loop_P = {
  /* Variable: An
   * Referenced by: '<Root>/Linearized State-Space'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, -9.81, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 9.81, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0 },

  /* Variable: Bn
   * Referenced by: '<Root>/Linearized State-Space'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 37.037037037037038, 0.0, 0.0, 0.0,
    -2331.6782748803721, -2265.1052879234812, -1265.5315232397606, 0.0, 0.0, 0.0,
    0.0, 0.0, 37.037037037037038, 0.0, 0.0, 0.0, -2331.6782748803721,
    2265.1052879234812, 1265.5315232397606, 0.0, 0.0, 0.0, 0.0, 0.0,
    37.037037037037038, 0.0, 0.0, 0.0, 2331.6782748803721, 2265.1052879234812,
    -1265.5315232397606, 0.0, 0.0, 0.0, 0.0, 0.0, 37.037037037037038, 0.0, 0.0,
    0.0, 2331.6782748803721, -2265.1052879234812, 1265.5315232397606 },

  /* Variable: Cn
   * Referenced by: '<Root>/Linearized State-Space'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /* Variable: g
   * Referenced by: '<Root>/Thrust converter'
   */
  9.81,

  /* Variable: scenario
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Variable: u_lin
   * Referenced by: '<Root>/Bias'
   */
  { 0.0662175, 0.0662175, 0.0662175, 0.0662175 },

  /* Variable: x0
   * Referenced by: '<Root>/Linearized State-Space'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Variable: x_lin
   * Referenced by: '<Root>/Bias1'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<Root>/Gain'
   */
  1.0,

  /* Expression: 180/3.141592
   * Referenced by: '<Root>/G3'
   */
  57.29579143313326,

  /* Expression: 180/3.141592
   * Referenced by: '<Root>/G4'
   */
  57.29579143313326,

  /* Expression: 180/3.141592
   * Referenced by: '<Root>/G1'
   */
  57.29579143313326,

  /* Expression: 180/3.141592
   * Referenced by: '<Root>/G2'
   */
  57.29579143313326
};
