/*
 * crazyflie_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "crazyflie".
 *
 * Model version              : 1.381
 * Simulink Coder version : 9.1 (R2019a) 23-Nov-2018
 * C source code generated on : Wed May  1 18:22:36 2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_crazyflie_private_h_
#define RTW_HEADER_crazyflie_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
# define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

extern const real_T rtCP_pooled_gQLwpZLBj4ay[32];
extern const real_T rtCP_pooled_LmbAjK6TKSwf[15];

#define rtCP_Gain_Gain                 rtCP_pooled_gQLwpZLBj4ay  /* Expression: -K_fb_int
                                                                  * Referenced by: '<S2>/Gain'
                                                                  */
#define rtCP_Gain1_Gain                rtCP_pooled_LmbAjK6TKSwf  /* Expression: H
                                                                  * Referenced by: '<S2>/Gain1'
                                                                  */
#endif                                 /* RTW_HEADER_crazyflie_private_h_ */
