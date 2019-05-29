/*
 * /home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/slprj/grt/_sharedutils/norm_2e9Xj4lM.c
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
 * Created for block: crazyflie
 */

#include "rtwtypes.h"
#include <math.h>
#include "norm_2e9Xj4lM.h"

/* Function for MATLAB Function: '<S1>/complementary filter' */
real_T norm_2e9Xj4lM(const real_T x[3])
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
