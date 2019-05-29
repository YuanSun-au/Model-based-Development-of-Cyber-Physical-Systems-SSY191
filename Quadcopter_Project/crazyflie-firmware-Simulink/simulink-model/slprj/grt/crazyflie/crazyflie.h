/*
 * Code generation for system model 'crazyflie'
 * For more details, see corresponding source file crazyflie.c
 *
 */

#ifndef RTW_HEADER_crazyflie_h_
#define RTW_HEADER_crazyflie_h_
#include <math.h>
#include <string.h>
#ifndef crazyflie_COMMON_INCLUDES_
# define crazyflie_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* crazyflie_COMMON_INCLUDES_ */

#include "crazyflie_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Block states (default storage) for model 'crazyflie' */
typedef struct {
  real_T Delay_DSTATE[3];              /* '<S1>/Delay' */
  real_T Accumulator_DSTATE[3];        /* '<S2>/Accumulator' */
} DW_crazyflie_f_T;

/* Real-time Model Data Structure */
struct tag_RTM_crazyflie_T {
  const char_T **errorStatus;
};

typedef struct {
  DW_crazyflie_f_T rtdw;
  RT_MODEL_crazyflie_T rtm;
} MdlrefDW_crazyflie_T;

/* Model reference registration function */
extern void crazyflie_initialize(const char_T **rt_errorStatus,
  RT_MODEL_crazyflie_T *const crazyflie_M, DW_crazyflie_f_T *localDW);
extern void crazyflie_Init(DW_crazyflie_f_T *localDW);
extern void crazyflie_Reset(DW_crazyflie_f_T *localDW);
extern void crazyflie(const real_T *rtu_Base_Thrust, const real_T *rtu_Ref_Roll,
                      const real_T *rtu_Ref_Pitch, const real_T *rtu_Ref_YawRate,
                      const real_T *rtu_Acc_x, const real_T *rtu_Acc_y, const
                      real_T *rtu_Acc_z, const real_T *rtu_Gyro_x, const real_T *
                      rtu_Gyro_y, const real_T *rtu_Gyro_z, uint16_T
                      *rty_Motor_1, uint16_T *rty_Motor_2, uint16_T *rty_Motor_3,
                      uint16_T *rty_Motor_4, real_T *rty_Log1, real_T *rty_Log2,
                      real_T *rty_Log3, real_T *rty_Log4, real_T *rty_Log5,
                      real_T *rty_Log6, DW_crazyflie_f_T *localDW);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope5 1' : Unused code path elimination
 * Block '<S2>/zeros' : Unused code path elimination
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
 * '<S3>'   : 'crazyflie/Pitch and Roll angles estimator/complementary filter'
 */
#endif                                 /* RTW_HEADER_crazyflie_h_ */
