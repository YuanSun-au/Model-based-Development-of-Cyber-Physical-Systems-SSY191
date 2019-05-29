/*
 * open_loop.h
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

#ifndef RTW_HEADER_open_loop_h_
#define RTW_HEADER_open_loop_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef open_loop_COMMON_INCLUDES_
# define open_loop_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "nesl_rtw.h"
#include "open_loop_94817720_1_gateway.h"
#endif                                 /* open_loop_COMMON_INCLUDES_ */

#include "open_loop_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "math.h"
#include "rt_matrixlib.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMassMatrixIr
# define rtmGetMassMatrixIr(rtm)       ((rtm)->massMatrixIr)
#endif

#ifndef rtmSetMassMatrixIr
# define rtmSetMassMatrixIr(rtm, val)  ((rtm)->massMatrixIr = (val))
#endif

#ifndef rtmGetMassMatrixJc
# define rtmGetMassMatrixJc(rtm)       ((rtm)->massMatrixJc)
#endif

#ifndef rtmSetMassMatrixJc
# define rtmSetMassMatrixJc(rtm, val)  ((rtm)->massMatrixJc = (val))
#endif

#ifndef rtmGetMassMatrixNzMax
# define rtmGetMassMatrixNzMax(rtm)    ((rtm)->massMatrixNzMax)
#endif

#ifndef rtmSetMassMatrixNzMax
# define rtmSetMassMatrixNzMax(rtm, val) ((rtm)->massMatrixNzMax = (val))
#endif

#ifndef rtmGetMassMatrixPr
# define rtmGetMassMatrixPr(rtm)       ((rtm)->massMatrixPr)
#endif

#ifndef rtmSetMassMatrixPr
# define rtmSetMassMatrixPr(rtm, val)  ((rtm)->massMatrixPr = (val))
#endif

#ifndef rtmGetMassMatrixType
# define rtmGetMassMatrixType(rtm)     ((rtm)->massMatrixType)
#endif

#ifndef rtmSetMassMatrixType
# define rtmSetMassMatrixType(rtm, val) ((rtm)->massMatrixType = (val))
#endif

#ifndef rtmGetOdeDELTA
# define rtmGetOdeDELTA(rtm)           ((rtm)->odeDELTA)
#endif

#ifndef rtmSetOdeDELTA
# define rtmSetOdeDELTA(rtm, val)      ((rtm)->odeDELTA = (val))
#endif

#ifndef rtmGetOdeDFDX
# define rtmGetOdeDFDX(rtm)            ((rtm)->odeDFDX)
#endif

#ifndef rtmSetOdeDFDX
# define rtmSetOdeDFDX(rtm, val)       ((rtm)->odeDFDX = (val))
#endif

#ifndef rtmGetOdeE
# define rtmGetOdeE(rtm)               ((rtm)->odeE)
#endif

#ifndef rtmSetOdeE
# define rtmSetOdeE(rtm, val)          ((rtm)->odeE = (val))
#endif

#ifndef rtmGetOdeF0
# define rtmGetOdeF0(rtm)              ((rtm)->odeF0)
#endif

#ifndef rtmSetOdeF0
# define rtmSetOdeF0(rtm, val)         ((rtm)->odeF0 = (val))
#endif

#ifndef rtmGetOdeF1
# define rtmGetOdeF1(rtm)              ((rtm)->odeF1)
#endif

#ifndef rtmSetOdeF1
# define rtmSetOdeF1(rtm, val)         ((rtm)->odeF1 = (val))
#endif

#ifndef rtmGetOdeFAC
# define rtmGetOdeFAC(rtm)             ((rtm)->odeFAC)
#endif

#ifndef rtmSetOdeFAC
# define rtmSetOdeFAC(rtm, val)        ((rtm)->odeFAC = (val))
#endif

#ifndef rtmGetOdeMASSMATRIX_M
# define rtmGetOdeMASSMATRIX_M(rtm)    ((rtm)->odeMASSMATRIX_M)
#endif

#ifndef rtmSetOdeMASSMATRIX_M
# define rtmSetOdeMASSMATRIX_M(rtm, val) ((rtm)->odeMASSMATRIX_M = (val))
#endif

#ifndef rtmGetOdePIVOTS
# define rtmGetOdePIVOTS(rtm)          ((rtm)->odePIVOTS)
#endif

#ifndef rtmSetOdePIVOTS
# define rtmSetOdePIVOTS(rtm, val)     ((rtm)->odePIVOTS = (val))
#endif

#ifndef rtmGetOdeW
# define rtmGetOdeW(rtm)               ((rtm)->odeW)
#endif

#ifndef rtmSetOdeW
# define rtmSetOdeW(rtm, val)          ((rtm)->odeW = (val))
#endif

#ifndef rtmGetOdeX0
# define rtmGetOdeX0(rtm)              ((rtm)->odeX0)
#endif

#ifndef rtmSetOdeX0
# define rtmSetOdeX0(rtm, val)         ((rtm)->odeX0 = (val))
#endif

#ifndef rtmGetOdeX1START
# define rtmGetOdeX1START(rtm)         ((rtm)->odeX1START)
#endif

#ifndef rtmSetOdeX1START
# define rtmSetOdeX1START(rtm, val)    ((rtm)->odeX1START = (val))
#endif

#ifndef rtmGetOdeXTMP
# define rtmGetOdeXTMP(rtm)            ((rtm)->odeXTMP)
#endif

#ifndef rtmSetOdeXTMP
# define rtmSetOdeXTMP(rtm, val)       ((rtm)->odeXTMP = (val))
#endif

#ifndef rtmGetOdeZTMP
# define rtmGetOdeZTMP(rtm)            ((rtm)->odeZTMP)
#endif

#ifndef rtmSetOdeZTMP
# define rtmSetOdeZTMP(rtm, val)       ((rtm)->odeZTMP = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T MultiportSwitch[4];           /* '<Root>/Multiport Switch' */
  real_T motor_signals[4];             /* '<Root>/Gain' */
  real_T Thrustconverter[4];           /* '<Root>/Thrust converter' */
  real_T INPUT_1_1_1[4];               /* '<S21>/INPUT_1_1_1' */
  real_T INPUT_1_1_2[4];               /* '<S21>/INPUT_1_1_2' */
  real_T INPUT_1_1_3[4];               /* '<S21>/INPUT_1_1_3' */
  real_T INPUT_1_1_4[4];               /* '<S21>/INPUT_1_1_4' */
  real_T STATE_1[115];                 /* '<S21>/STATE_1' */
  real_T OUTPUT_1_0[21];               /* '<S21>/OUTPUT_1_0' */
  real_T LinearizedStateSpace[12];     /* '<Root>/Linearized State-Space' */
  real_T Bias1[12];                    /* '<Root>/Bias1' */
  real_T Ang_L[3];                     /* '<Root>/G3' */
  real_T Ang_Vel_L[3];                 /* '<Root>/G4' */
  real_T Bias[4];                      /* '<Root>/Bias' */
  real_T eul_angle[3];                 /* '<Root>/G1' */
  real_T d_eul_angle[3];               /* '<Root>/G2' */
} B_open_loop_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T INPUT_1_1_1_Discrete[2];      /* '<S21>/INPUT_1_1_1' */
  real_T INPUT_1_1_2_Discrete[2];      /* '<S21>/INPUT_1_1_2' */
  real_T INPUT_1_1_3_Discrete[2];      /* '<S21>/INPUT_1_1_3' */
  real_T INPUT_1_1_4_Discrete[2];      /* '<S21>/INPUT_1_1_4' */
  real_T STATE_1_Discrete;             /* '<S21>/STATE_1' */
  real_T OUTPUT_1_0_Discrete;          /* '<S21>/OUTPUT_1_0' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK;                      /* '<S10>/FromWs' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK_a;                    /* '<S11>/FromWs' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK_g;                    /* '<S12>/FromWs' */

  void* STATE_1_Simulator;             /* '<S21>/STATE_1' */
  void* STATE_1_SimData;               /* '<S21>/STATE_1' */
  void* STATE_1_DiagMgr;               /* '<S21>/STATE_1' */
  void* STATE_1_ZcLogger;              /* '<S21>/STATE_1' */
  void* STATE_1_TsIndex;               /* '<S21>/STATE_1' */
  void* OUTPUT_1_0_Simulator;          /* '<S21>/OUTPUT_1_0' */
  void* OUTPUT_1_0_SimData;            /* '<S21>/OUTPUT_1_0' */
  void* OUTPUT_1_0_DiagMgr;            /* '<S21>/OUTPUT_1_0' */
  void* OUTPUT_1_0_ZcLogger;           /* '<S21>/OUTPUT_1_0' */
  void* OUTPUT_1_0_TsIndex;            /* '<S21>/OUTPUT_1_0' */
  struct {
    void *LoggedData;
  } Accdata_PWORK;                     /* '<Root>/Acc. data' */

  struct {
    void *LoggedData;
  } Acceleration_PWORK;                /* '<Root>/Acceleration' */

  struct {
    void *LoggedData;
  } Ang_L_PWORK;                       /* '<Root>/Ang_L' */

  struct {
    void *LoggedData;
  } Ang_vel_L_PWORK;                   /* '<Root>/Ang_vel_L' */

  struct {
    void *LoggedData;
  } MotorSignals_PWORK;                /* '<Root>/MotorSignals' */

  struct {
    void *LoggedData;
  } Pos_L_PWORK;                       /* '<Root>/Pos_L' */

  struct {
    void *LoggedData;
  } Thrust_PWORK;                      /* '<Root>/Thrust' */

  struct {
    void *LoggedData;
  } Vel_L_PWORK;                       /* '<Root>/Vel_L' */

  struct {
    void *LoggedData;
  } Angle_PWORK;                       /* '<Root>/Angle' */

  struct {
    void *LoggedData;
  } Angularvelocity_PWORK;             /* '<Root>/Angular velocity' */

  struct {
    void *LoggedData;
  } Gyrodata_PWORK;                    /* '<Root>/Gyro. data' */

  struct {
    void *LoggedData;
  } Position_PWORK;                    /* '<Root>/Position' */

  struct {
    void *LoggedData;
  } Velocity_PWORK;                    /* '<Root>/Velocity' */

  struct {
    int_T PrevIndex;
  } FromWs_IWORK;                      /* '<S10>/FromWs' */

  struct {
    int_T PrevIndex;
  } FromWs_IWORK_e;                    /* '<S11>/FromWs' */

  struct {
    int_T PrevIndex;
  } FromWs_IWORK_g;                    /* '<S12>/FromWs' */

  int_T STATE_1_Modes[5];              /* '<S21>/STATE_1' */
  int_T OUTPUT_1_0_Modes;              /* '<S21>/OUTPUT_1_0' */
  int32_T STATE_1_MASS_MATRIX_PR;      /* '<S21>/STATE_1' */
  boolean_T STATE_1_FirstOutput;       /* '<S21>/STATE_1' */
  boolean_T OUTPUT_1_0_FirstOutput;    /* '<S21>/OUTPUT_1_0' */
} DW_open_loop_T;

/* Continuous states (default storage) */
typedef struct {
  real_T open_loopPlant_of_the_quadrocop[110];/* '<S21>/STATE_1' */
  real_T LinearizedStateSpace_CSTATE[12];/* '<Root>/Linearized State-Space' */
} X_open_loop_T;

/* State derivatives (default storage) */
typedef struct {
  real_T open_loopPlant_of_the_quadrocop[110];/* '<S21>/STATE_1' */
  real_T LinearizedStateSpace_CSTATE[12];/* '<Root>/Linearized State-Space' */
} XDot_open_loop_T;

/* State disabled  */
typedef struct {
  boolean_T open_loopPlant_of_the_quadrocop[110];/* '<S21>/STATE_1' */
  boolean_T LinearizedStateSpace_CSTATE[12];/* '<Root>/Linearized State-Space' */
} XDis_open_loop_T;

/* Mass Matrix (global) */
typedef struct {
  int_T ir[24];
  int_T jc[123];
  real_T pr[24];
} MassMatrix_open_loop_T;

#ifndef ODE14X_INTG
#define ODE14X_INTG

/* ODE14X Integration Data */
typedef struct {
  real_T *x0;
  real_T *f0;
  real_T *x1start;
  real_T *f1;
  real_T *Delta;
  real_T *E;
  real_T *fac;
  real_T *DFDX;
  real_T *W;
  int_T *pivots;
  real_T *xtmp;
  real_T *ztmp;
  real_T *M;
  real_T *M1;
  real_T *Edot;
  real_T *xdot;
  real_T *fminusMxdot;
  boolean_T isFirstStep;
} ODE14X_IntgData;

#endif

/* Parameters (default storage) */
struct P_open_loop_T_ {
  real_T An[144];                      /* Variable: An
                                        * Referenced by: '<Root>/Linearized State-Space'
                                        */
  real_T Bn[48];                       /* Variable: Bn
                                        * Referenced by: '<Root>/Linearized State-Space'
                                        */
  real_T Cn[144];                      /* Variable: Cn
                                        * Referenced by: '<Root>/Linearized State-Space'
                                        */
  real_T g;                            /* Variable: g
                                        * Referenced by: '<Root>/Thrust converter'
                                        */
  real_T scenario;                     /* Variable: scenario
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T u_lin[4];                     /* Variable: u_lin
                                        * Referenced by: '<Root>/Bias'
                                        */
  real_T x0[12];                       /* Variable: x0
                                        * Referenced by: '<Root>/Linearized State-Space'
                                        */
  real_T x_lin[12];                    /* Variable: x_lin
                                        * Referenced by: '<Root>/Bias1'
                                        */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T G3_Gain;                      /* Expression: 180/3.141592
                                        * Referenced by: '<Root>/G3'
                                        */
  real_T G4_Gain;                      /* Expression: 180/3.141592
                                        * Referenced by: '<Root>/G4'
                                        */
  real_T G1_Gain;                      /* Expression: 180/3.141592
                                        * Referenced by: '<Root>/G1'
                                        */
  real_T G2_Gain;                      /* Expression: 180/3.141592
                                        * Referenced by: '<Root>/G2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_open_loop_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_open_loop_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  int_T massMatrixType;
  int_T massMatrixNzMax;
  int_T *massMatrixIr;
  int_T *massMatrixJc;
  real_T *massMatrixPr;
  real_T odeX0[122];
  real_T odeF0[122];
  real_T odeX1START[122];
  real_T odeF1[122];
  real_T odeDELTA[122];
  real_T odeE[4*122];
  real_T odeFAC[122];
  real_T odeDFDX[122*122];
  real_T odeW[122*122];
  int_T odePIVOTS[122];
  real_T odeXTMP[122];
  real_T odeZTMP[122];
  real_T odeMASSMATRIX_M[24];
  ODE14X_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_open_loop_T open_loop_P;

/* Block signals (default storage) */
extern B_open_loop_T open_loop_B;

/* Continuous states (default storage) */
extern X_open_loop_T open_loop_X;

/* global MassMatrix */
extern MassMatrix_open_loop_T open_loop_MassMatrix;

/* Block states (default storage) */
extern DW_open_loop_T open_loop_DW;

/* Model entry point functions */
extern void open_loop_initialize(void);
extern void open_loop_step(void);
extern void open_loop_terminate(void);

/* Real-time Model object */
extern RT_MODEL_open_loop_T *const open_loop_M;

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
 * '<Root>' : 'open_loop'
 * '<S1>'   : 'open_loop/PS -> S 1'
 * '<S2>'   : 'open_loop/PS -> S 2'
 * '<S3>'   : 'open_loop/PS -> S 3'
 * '<S4>'   : 'open_loop/PS -> S 4'
 * '<S5>'   : 'open_loop/PS -> S 5'
 * '<S6>'   : 'open_loop/PS -> S 6'
 * '<S7>'   : 'open_loop/PS -> S 7'
 * '<S8>'   : 'open_loop/Simulink-PS Converter'
 * '<S9>'   : 'open_loop/Solver Configuration'
 * '<S10>'  : 'open_loop/scenario 1'
 * '<S11>'  : 'open_loop/scenario 2'
 * '<S12>'  : 'open_loop/scenario 3'
 * '<S13>'  : 'open_loop/PS -> S 1/EVAL_KEY'
 * '<S14>'  : 'open_loop/PS -> S 2/EVAL_KEY'
 * '<S15>'  : 'open_loop/PS -> S 3/EVAL_KEY'
 * '<S16>'  : 'open_loop/PS -> S 4/EVAL_KEY'
 * '<S17>'  : 'open_loop/PS -> S 5/EVAL_KEY'
 * '<S18>'  : 'open_loop/PS -> S 6/EVAL_KEY'
 * '<S19>'  : 'open_loop/PS -> S 7/EVAL_KEY'
 * '<S20>'  : 'open_loop/Simulink-PS Converter/EVAL_KEY'
 * '<S21>'  : 'open_loop/Solver Configuration/EVAL_KEY'
 */
#endif                                 /* RTW_HEADER_open_loop_h_ */
