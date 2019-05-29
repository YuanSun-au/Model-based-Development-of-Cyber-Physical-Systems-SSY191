/*
 * open_loop.c
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

/* Block signals (default storage) */
B_open_loop_T open_loop_B;

/* Continuous states */
X_open_loop_T open_loop_X;

/* Mass Matrices */
MassMatrix_open_loop_T open_loop_MassMatrix;

/* Block states (default storage) */
DW_open_loop_T open_loop_DW;

/* Real-time model */
RT_MODEL_open_loop_T open_loop_M_;
RT_MODEL_open_loop_T *const open_loop_M = &open_loop_M_;

/* ForcingFunction for root system: '<Root>' */
void open_loop_forcingfunction(void)
{
  NeslSimulationData *simulationData;
  real_T time;
  boolean_T tmp;
  real_T tmp_0[16];
  int_T tmp_1[5];
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  char *msg;
  int_T is;
  int_T ci;
  XDot_open_loop_T *_rtXdot;
  _rtXdot = ((XDot_open_loop_T *) open_loop_M->derivs);

  /* ForcingFunction for SimscapeExecutionBlock: '<S21>/STATE_1' */
  simulationData = (NeslSimulationData *)open_loop_DW.STATE_1_SimData;
  time = open_loop_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 110;
  simulationData->mData->mContStates.mX =
    &open_loop_X.open_loopPlant_of_the_quadrocop[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &open_loop_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 5;
  simulationData->mData->mModeVector.mX = &open_loop_DW.STATE_1_Modes[0];
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(open_loop_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&open_loop_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_1[0] = 0;
  tmp_0[0] = open_loop_B.INPUT_1_1_1[0];
  tmp_0[1] = open_loop_B.INPUT_1_1_1[1];
  tmp_0[2] = open_loop_B.INPUT_1_1_1[2];
  tmp_0[3] = open_loop_B.INPUT_1_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = open_loop_B.INPUT_1_1_2[0];
  tmp_0[5] = open_loop_B.INPUT_1_1_2[1];
  tmp_0[6] = open_loop_B.INPUT_1_1_2[2];
  tmp_0[7] = open_loop_B.INPUT_1_1_2[3];
  tmp_1[2] = 8;
  tmp_0[8] = open_loop_B.INPUT_1_1_3[0];
  tmp_0[9] = open_loop_B.INPUT_1_1_3[1];
  tmp_0[10] = open_loop_B.INPUT_1_1_3[2];
  tmp_0[11] = open_loop_B.INPUT_1_1_3[3];
  tmp_1[3] = 12;
  tmp_0[12] = open_loop_B.INPUT_1_1_4[0];
  tmp_0[13] = open_loop_B.INPUT_1_1_4[1];
  tmp_0[14] = open_loop_B.INPUT_1_1_4[2];
  tmp_0[15] = open_loop_B.INPUT_1_1_4[3];
  tmp_1[4] = 16;
  simulationData->mData->mInputValues.mN = 16;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 5;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  simulationData->mData->mDx.mN = 110;
  simulationData->mData->mDx.mX = &_rtXdot->open_loopPlant_of_the_quadrocop[0];
  diagnosticManager = (NeuDiagnosticManager *)open_loop_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  is = ne_simulator_method((NeslSimulator *)open_loop_DW.STATE_1_Simulator,
    NESL_SIM_FORCINGFUNCTION, simulationData, diagnosticManager);
  if (is != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(open_loop_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(open_loop_M, msg);
    }
  }

  /* End of ForcingFunction for SimscapeExecutionBlock: '<S21>/STATE_1' */

  /* ForcingFunction for StateSpace: '<Root>/Linearized State-Space' */
  for (is = 0; is < 12; is++) {
    _rtXdot->LinearizedStateSpace_CSTATE[is] = 0.0;
    for (ci = 0; ci < 12; ci++) {
      _rtXdot->LinearizedStateSpace_CSTATE[is] += open_loop_P.An[ci * 12 + is] *
        open_loop_X.LinearizedStateSpace_CSTATE[ci];
    }

    _rtXdot->LinearizedStateSpace_CSTATE[is] += open_loop_P.Bn[is] *
      open_loop_B.Bias[0];
    _rtXdot->LinearizedStateSpace_CSTATE[is] += open_loop_P.Bn[12 + is] *
      open_loop_B.Bias[1];
    _rtXdot->LinearizedStateSpace_CSTATE[is] += open_loop_P.Bn[24 + is] *
      open_loop_B.Bias[2];
    _rtXdot->LinearizedStateSpace_CSTATE[is] += open_loop_P.Bn[36 + is] *
      open_loop_B.Bias[3];
  }

  /* End of ForcingFunction for StateSpace: '<Root>/Linearized State-Space' */
}

/* MassMatrix for root system: '<Root>' */
void open_loop_massmatrix(void)
{
  NeslSimulationData *simulationData;
  real_T time;
  boolean_T tmp;
  real_T tmp_0[16];
  int_T tmp_1[5];
  real_T *tmp_2;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  int32_T tmp_3;
  char *msg;

  /* MassMatrix for SimscapeExecutionBlock: '<S21>/STATE_1' */
  simulationData = (NeslSimulationData *)open_loop_DW.STATE_1_SimData;
  time = open_loop_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 110;
  simulationData->mData->mContStates.mX =
    &open_loop_X.open_loopPlant_of_the_quadrocop[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &open_loop_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 5;
  simulationData->mData->mModeVector.mX = &open_loop_DW.STATE_1_Modes[0];
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(open_loop_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&open_loop_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_1[0] = 0;
  tmp_0[0] = open_loop_B.INPUT_1_1_1[0];
  tmp_0[1] = open_loop_B.INPUT_1_1_1[1];
  tmp_0[2] = open_loop_B.INPUT_1_1_1[2];
  tmp_0[3] = open_loop_B.INPUT_1_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = open_loop_B.INPUT_1_1_2[0];
  tmp_0[5] = open_loop_B.INPUT_1_1_2[1];
  tmp_0[6] = open_loop_B.INPUT_1_1_2[2];
  tmp_0[7] = open_loop_B.INPUT_1_1_2[3];
  tmp_1[2] = 8;
  tmp_0[8] = open_loop_B.INPUT_1_1_3[0];
  tmp_0[9] = open_loop_B.INPUT_1_1_3[1];
  tmp_0[10] = open_loop_B.INPUT_1_1_3[2];
  tmp_0[11] = open_loop_B.INPUT_1_1_3[3];
  tmp_1[3] = 12;
  tmp_0[12] = open_loop_B.INPUT_1_1_4[0];
  tmp_0[13] = open_loop_B.INPUT_1_1_4[1];
  tmp_0[14] = open_loop_B.INPUT_1_1_4[2];
  tmp_0[15] = open_loop_B.INPUT_1_1_4[3];
  tmp_1[4] = 16;
  simulationData->mData->mInputValues.mN = 16;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 5;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  tmp_2 = open_loop_MassMatrix.pr;
  tmp_2 = double_pointer_shift(tmp_2, open_loop_DW.STATE_1_MASS_MATRIX_PR);
  simulationData->mData->mMassMatrixPr.mN = 12;
  simulationData->mData->mMassMatrixPr.mX = tmp_2;
  diagnosticManager = (NeuDiagnosticManager *)open_loop_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_3 = ne_simulator_method((NeslSimulator *)open_loop_DW.STATE_1_Simulator,
    NESL_SIM_MASSMATRIX, simulationData, diagnosticManager);
  if (tmp_3 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(open_loop_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(open_loop_M, msg);
    }
  }

  /* End of MassMatrix for SimscapeExecutionBlock: '<S21>/STATE_1' */
}

void local_evaluateMassMatrix(RTWSolverInfo *si, real_T *Mdest )
{
  /* Refresh global mass matrix */
  open_loop_massmatrix();

  /* Copy the mass matrix from system to the destination, if needed. */
  if (Mdest != rtsiGetSolverMassMatrixPr(si)) {
    real_T *Msrc = rtsiGetSolverMassMatrixPr(si);
    int_T nzmax = rtsiGetSolverMassMatrixNzMax(si);
    (void) memcpy(Mdest, Msrc,
                  (uint_T)nzmax*sizeof(real_T));
  }
}

/* Simplified version of numjac.cpp, for use with RTW. */
void local_numjac( RTWSolverInfo *si, real_T *y, const real_T *Fty, real_T *fac,
                  real_T *dFdy )
{
  /* constants */
  real_T THRESH = 1e-6;
  real_T EPS = 2.2e-16;                /* utGetEps(); */
  real_T BL = pow(EPS, 0.75);
  real_T BU = pow(EPS, 0.25);
  real_T FACMIN = pow(EPS, 0.78);
  real_T FACMAX = 0.1;
  int_T nx = 122;
  real_T *x = rtsiGetContStates(si);
  real_T del;
  real_T difmax;
  real_T FdelRowmax;
  real_T temp;
  real_T Fdiff;
  real_T maybe;
  real_T xscale;
  real_T fscale;
  real_T *p;
  int_T rowmax;
  int_T i,j;
  if (x != y)
    (void) memcpy(x, y,
                  (uint_T)nx*sizeof(real_T));
  rtsiSetSolverComputingJacobian(si,true);
  for (p = dFdy, j = 0; j < nx; j++, p += nx) {
    /* Select an increment del for a difference approximation to
       column j of dFdy.  The vector fac accounts for experience
       gained in previous calls to numjac. */
    xscale = fabs(x[j]);
    if (xscale < THRESH)
      xscale = THRESH;
    temp = (x[j] + fac[j]*xscale);
    del = temp - y[j];
    while (del == 0.0) {
      if (fac[j] < FACMAX) {
        fac[j] *= 100.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
        temp = (x[j] + fac[j]*xscale);
        del = temp - x[j];
      } else {
        del = THRESH;                  /* thresh is nonzero */
        break;
      }
    }

    /* Keep del pointing into region. */
    if (Fty[j] >= 0.0)
      del = fabs(del);
    else
      del = -fabs(del);

    /* Form a difference approximation to column j of dFdy. */
    temp = x[j];
    x[j] += del;
    open_loop_step();
    rtsiSetdX(si,p);
    open_loop_forcingfunction();
    x[j] = temp;
    difmax = 0.0;
    rowmax = 0;
    FdelRowmax = p[0];
    temp = 1.0 / del;
    for (i = 0; i < nx; i++) {
      Fdiff = p[i] - Fty[i];
      maybe = fabs(Fdiff);
      if (maybe > difmax) {
        difmax = maybe;
        rowmax = i;
        FdelRowmax = p[i];
      }

      p[i] = temp * Fdiff;
    }

    /* Adjust fac for next call to numjac. */
    if (((FdelRowmax != 0.0) && (Fty[rowmax] != 0.0)) || (difmax == 0.0)) {
      fscale = fabs(FdelRowmax);
      if (fscale < fabs(Fty[rowmax]))
        fscale = fabs(Fty[rowmax]);
      if (difmax <= BL*fscale) {
        /* The difference is small, so increase the increment. */
        fac[j] *= 10.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
      } else if (difmax > BU*fscale) {
        /* The difference is large, so reduce the increment. */
        fac[j] *= 0.1;
        if (fac[j] < FACMIN)
          fac[j] = FACMIN;
      }
    }
  }

  rtsiSetSolverComputingJacobian(si,false);
}                                      /* end local_numjac */

/*
 * This function updates continuous states using the ODE14x fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static int_T rt_ODE14x_N[4] = { 12, 8, 6, 4 };

  time_T t0 = rtsiGetT(si);
  time_T t1 = t0;
  time_T h = rtsiGetStepSize(si);
  real_T *x1 = rtsiGetContStates(si);
  int_T order = rtsiGetSolverExtrapolationOrder(si);
  int_T numIter = rtsiGetSolverNumberNewtonIterations(si);
  ODE14X_IntgData *id = (ODE14X_IntgData *)rtsiGetSolverData(si);
  real_T *x0 = id->x0;
  real_T *f0 = id->f0;
  real_T *x1start = id->x1start;
  real_T *f1 = id->f1;
  real_T *Delta = id->Delta;
  real_T *E = id->E;
  real_T *fac = id->fac;
  real_T *dfdx = id->DFDX;
  real_T *W = id->W;
  int_T *pivots = id->pivots;
  real_T *xtmp = id->xtmp;
  real_T *ztmp = id->ztmp;
  int_T *Mpattern_ir = rtsiGetSolverMassMatrixIr(si);
  int_T *Mpattern_jc = rtsiGetSolverMassMatrixJc(si);
  real_T *M = id->M;
  int_T col,row,rowidx;
  int_T *N = &(rt_ODE14x_N[0]);
  int_T i,j,k,iter;
  int_T nx = 122;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(x0, x1,
                (uint_T)nx*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  if (id->isFirstStep) {
    local_evaluateMassMatrix(si,M );
    id->isFirstStep = false;
  }

  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  open_loop_forcingfunction();
  local_numjac(si,x0,f0,fac,dfdx );
  for (j = 0; j < order; j++) {
    real_T *p;
    real_T hN = h/N[j];

    /* Get the iteration matrix and solution at t0 */

    /* [L,U] = lu(M - hN*J) */
    (void) memcpy(W, dfdx,
                  (uint_T)nx*nx*sizeof(real_T));
    for (p = W, i = 0; i < nx*nx; i++, p++) {
      *p *= (-hN);
    }

    for (col = 0, p = W; col < nx; col++, p += nx) {
      for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++) {
        real_T m_row_col = M[rowidx];
        row = Mpattern_ir[rowidx];
        p[row] += m_row_col;
      }
    }

    rt_lu_real(W, nx,
               pivots);

    /* First Newton's iteration at t0. */
    /* rhs = hN*f0 */
    for (i = 0; i < nx; i++) {
      Delta[i] = hN*f0[i];
    }

    /* Delta = (U \ (L \ rhs)) */
    rt_ForwardSubstitutionRR_Dbl(W, Delta,
      f1, nx,
      1, pivots,
      1);
    rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
      Delta, nx,
      1, 0);

    /* ytmp = y0 + Delta
       ztmp = (ytmp-y0)/h
     */
    (void) memcpy(x1, x0,
                  (uint_T)nx*sizeof(real_T));
    for (i = 0; i < nx; i++) {
      x1[i] += Delta[i];
      ztmp[i] = Delta[i]/hN;
    }

    /* Additional Newton's iterations, if desired.
       for iter = 2:NewtIter
       rhs = hN*feval(odefun,tn,ytmp,extraArgs{:}) - M*(ytmp - yn);
       if statedepM   % only for state dep. Mdel ~= 0
       Mdel = M - feval(massfun,tn,ytmp);
       rhs = rhs + Mdel*ztmp*h;
       end
       Delta = ( U \ ( L \ rhs ) );
       ytmp = ytmp + Delta;
       ztmp = (ytmp - yn)/h
       end
     */
    rtsiSetT(si, t0);
    rtsiSetdX(si, f1);
    for (iter = 1; iter < numIter; iter++) {
      open_loop_step();
      open_loop_forcingfunction();
      for (i = 0; i < nx; i++) {
        Delta[i] = hN*f1[i];
        xtmp[i] = x1[i] - x0[i];
      }

      /* rhs = hN*f(tn,ytmp) - M*(ytmp-yn) */
      for (col = 0; col < nx; col++) {
        for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++) {
          real_T m_row_col = M[rowidx];
          row = Mpattern_ir[rowidx];
          Delta[row] -= m_row_col*xtmp[col];
        }
      }

      rt_ForwardSubstitutionRR_Dbl(W, Delta,
        f1, nx,
        1, pivots,
        1);
      rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
        Delta, nx,
        1, 0);

      /* ytmp = ytmp + delta
         ztmp = (ytmp - yn)/h
       */
      for (i = 0; i < nx; i++) {
        x1[i] += Delta[i];
        ztmp[i] = (x1[i] - x0[i])/hN;
      }
    }

    /* Steps from t0+hN to t1 -- subintegration of N(j) steps for extrapolation
       ttmp = t0;
       for i = 2:N(j)
       ttmp = ttmp + hN
       ytmp0 = ytmp;
       for iter = 1:NewtIter
       rhs = (ytmp0 - ytmp) + hN*feval(odefun,ttmp,ytmp,extraArgs{:});
       Delta = ( U \ ( L \ rhs ) );
       ytmp = ytmp + Delta;
       end
       end
     */
    for (k = 1; k < N[j]; k++) {
      t1 = t0 + k*hN;
      (void) memcpy(x1start, x1,
                    (uint_T)nx*sizeof(real_T));
      rtsiSetT(si, t1);
      rtsiSetdX(si, f1);
      for (iter = 0; iter < numIter; iter++) {
        open_loop_step();
        open_loop_forcingfunction();
        if (iter == 0) {
          for (i = 0; i < nx; i++) {
            Delta[i] = hN*f1[i];
          }
        } else {
          for (i = 0; i < nx; i++) {
            Delta[i] = hN*f1[i];
            xtmp[i] = (x1[i]-x1start[i]);
          }

          /* rhs = hN*f(tn,ytmp) - M*(ytmp-yn) */
          for (col = 0; col < nx; col++) {
            for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx
                 ++) {
              real_T m_row_col = M[rowidx];
              row = Mpattern_ir[rowidx];
              Delta[row] -= m_row_col*xtmp[col];
            }
          }
        }

        rt_ForwardSubstitutionRR_Dbl(W, Delta,
          f1, nx,
          1, pivots,
          1);
        rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
          Delta, nx,
          1, 0);

        /* ytmp = ytmp + Delta
           ztmp = (ytmp - ytmp0)/h
         */
        for (i = 0; i < nx; i++) {
          x1[i] += Delta[i];
          ztmp[i] = (x1[i] - x1start[i])/hN;
        }
      }
    }

    /* Extrapolate to order j
       E(:,j) = ytmp
       for k = j:-1:2
       coef = N(k-1)/(N(j) - N(k-1))
       E(:,k-1) = E(:,k) + coef*( E(:,k) - E(:,k-1) )
       end
     */
    (void) memcpy(&(E[nx*j]), x1,
                  (uint_T)nx*sizeof(real_T));
    for (k = j; k > 0; k--) {
      real_T coef = (real_T)(N[k-1]) / (N[j]-N[k-1]);
      for (i = 0; i < nx; i++) {
        x1[i] = E[nx*k+i] + coef*(E[nx*k+i] - E[nx*(k-1)+i]);
      }

      (void) memcpy(&(E[nx*(k-1)]), x1,
                    (uint_T)nx*sizeof(real_T));
    }
  }

  /* x1 = E(:,1); */
  (void) memcpy(x1, E,
                (uint_T)nx*sizeof(real_T));

  /* t1 = t0 + h; */
  rtsiSetT(si,rtsiGetSolverStopTime(si));
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void open_loop_step(void)
{
  /* local block i/o variables */
  real_T rtb_FromWs[4];
  real_T rtb_FromWs_g[4];
  real_T rtb_FromWs_a[4];
  if (rtmIsMajorTimeStep(open_loop_M)) {
    /* set solver stop time */
    if (!(open_loop_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&open_loop_M->solverInfo,
                            ((open_loop_M->Timing.clockTickH0 + 1) *
        open_loop_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&open_loop_M->solverInfo,
                            ((open_loop_M->Timing.clockTick0 + 1) *
        open_loop_M->Timing.stepSize0 + open_loop_M->Timing.clockTickH0 *
        open_loop_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(open_loop_M)) {
    open_loop_M->Timing.t[0] = rtsiGetT(&open_loop_M->solverInfo);
  }

  {
    NeslSimulationData *simulationData;
    real_T time;
    boolean_T tmp;
    real_T tmp_0[16];
    int_T tmp_1[5];
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    char *msg;
    real_T time_0;
    real_T tmp_2[131];
    int_T tmp_3[6];
    int_T iy;
    int_T ci;
    real_T y;
    boolean_T tmp_4;

    /* FromWorkspace: '<S10>/FromWs' */
    {
      real_T *pDataValues = (real_T *) open_loop_DW.FromWs_PWORK.DataPtr;
      real_T *pTimeValues = (real_T *) open_loop_DW.FromWs_PWORK.TimePtr;
      int_T currTimeIndex = open_loop_DW.FromWs_IWORK.PrevIndex;
      real_T t = open_loop_M->Timing.t[0];

      /* Get index */
      if (t <= pTimeValues[0]) {
        currTimeIndex = 0;
      } else if (t >= pTimeValues[4]) {
        currTimeIndex = 3;
      } else {
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }
      }

      open_loop_DW.FromWs_IWORK.PrevIndex = currTimeIndex;

      /* Post output */
      {
        real_T t1 = pTimeValues[currTimeIndex];
        real_T t2 = pTimeValues[currTimeIndex + 1];
        if (t1 == t2) {
          if (t < t1) {
            {
              int_T elIdx;
              for (elIdx = 0; elIdx < 4; ++elIdx) {
                (&rtb_FromWs[0])[elIdx] = pDataValues[currTimeIndex];
                pDataValues += 5;
              }
            }
          } else {
            {
              int_T elIdx;
              for (elIdx = 0; elIdx < 4; ++elIdx) {
                (&rtb_FromWs[0])[elIdx] = pDataValues[currTimeIndex + 1];
                pDataValues += 5;
              }
            }
          }
        } else {
          real_T f1 = (t2 - t) / (t2 - t1);
          real_T f2 = 1.0 - f1;
          real_T d1;
          real_T d2;
          int_T TimeIndex= currTimeIndex;

          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 4; ++elIdx) {
              d1 = pDataValues[TimeIndex];
              d2 = pDataValues[TimeIndex + 1];
              (&rtb_FromWs[0])[elIdx] = (real_T) rtInterpolate(d1, d2, f1, f2);
              pDataValues += 5;
            }
          }
        }
      }
    }

    /* FromWorkspace: '<S11>/FromWs' */
    {
      real_T *pDataValues = (real_T *) open_loop_DW.FromWs_PWORK_a.DataPtr;
      real_T *pTimeValues = (real_T *) open_loop_DW.FromWs_PWORK_a.TimePtr;
      int_T currTimeIndex = open_loop_DW.FromWs_IWORK_e.PrevIndex;
      real_T t = open_loop_M->Timing.t[0];

      /* Get index */
      if (t <= pTimeValues[0]) {
        currTimeIndex = 0;
      } else if (t >= pTimeValues[6]) {
        currTimeIndex = 5;
      } else {
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }
      }

      open_loop_DW.FromWs_IWORK_e.PrevIndex = currTimeIndex;

      /* Post output */
      {
        real_T t1 = pTimeValues[currTimeIndex];
        real_T t2 = pTimeValues[currTimeIndex + 1];
        if (t1 == t2) {
          if (t < t1) {
            {
              int_T elIdx;
              for (elIdx = 0; elIdx < 4; ++elIdx) {
                (&rtb_FromWs_g[0])[elIdx] = pDataValues[currTimeIndex];
                pDataValues += 7;
              }
            }
          } else {
            {
              int_T elIdx;
              for (elIdx = 0; elIdx < 4; ++elIdx) {
                (&rtb_FromWs_g[0])[elIdx] = pDataValues[currTimeIndex + 1];
                pDataValues += 7;
              }
            }
          }
        } else {
          real_T f1 = (t2 - t) / (t2 - t1);
          real_T f2 = 1.0 - f1;
          real_T d1;
          real_T d2;
          int_T TimeIndex= currTimeIndex;

          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 4; ++elIdx) {
              d1 = pDataValues[TimeIndex];
              d2 = pDataValues[TimeIndex + 1];
              (&rtb_FromWs_g[0])[elIdx] = (real_T) rtInterpolate(d1, d2, f1, f2);
              pDataValues += 7;
            }
          }
        }
      }
    }

    /* FromWorkspace: '<S12>/FromWs' */
    {
      real_T *pDataValues = (real_T *) open_loop_DW.FromWs_PWORK_g.DataPtr;
      real_T *pTimeValues = (real_T *) open_loop_DW.FromWs_PWORK_g.TimePtr;
      int_T currTimeIndex = open_loop_DW.FromWs_IWORK_g.PrevIndex;
      real_T t = open_loop_M->Timing.t[0];

      /* Get index */
      if (t <= pTimeValues[0]) {
        currTimeIndex = 0;
      } else if (t >= pTimeValues[1]) {
        currTimeIndex = 0;
      } else {
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }
      }

      open_loop_DW.FromWs_IWORK_g.PrevIndex = currTimeIndex;

      /* Post output */
      {
        real_T t1 = pTimeValues[currTimeIndex];
        real_T t2 = pTimeValues[currTimeIndex + 1];
        if (t1 == t2) {
          if (t < t1) {
            {
              int_T elIdx;
              for (elIdx = 0; elIdx < 4; ++elIdx) {
                (&rtb_FromWs_a[0])[elIdx] = pDataValues[currTimeIndex];
                pDataValues += 2;
              }
            }
          } else {
            {
              int_T elIdx;
              for (elIdx = 0; elIdx < 4; ++elIdx) {
                (&rtb_FromWs_a[0])[elIdx] = pDataValues[currTimeIndex + 1];
                pDataValues += 2;
              }
            }
          }
        } else {
          real_T f1 = (t2 - t) / (t2 - t1);
          real_T f2 = 1.0 - f1;
          real_T d1;
          real_T d2;
          int_T TimeIndex= currTimeIndex;

          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 4; ++elIdx) {
              d1 = pDataValues[TimeIndex];
              d2 = pDataValues[TimeIndex + 1];
              (&rtb_FromWs_a[0])[elIdx] = (real_T) rtInterpolate(d1, d2, f1, f2);
              pDataValues += 2;
            }
          }
        }
      }
    }

    /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
     *  Constant: '<Root>/Constant'
     */
    switch ((int32_T)open_loop_P.scenario) {
     case 1:
      open_loop_B.MultiportSwitch[0] = rtb_FromWs[0];
      open_loop_B.MultiportSwitch[1] = rtb_FromWs[1];
      open_loop_B.MultiportSwitch[2] = rtb_FromWs[2];
      open_loop_B.MultiportSwitch[3] = rtb_FromWs[3];
      break;

     case 2:
      open_loop_B.MultiportSwitch[0] = rtb_FromWs_g[0];
      open_loop_B.MultiportSwitch[1] = rtb_FromWs_g[1];
      open_loop_B.MultiportSwitch[2] = rtb_FromWs_g[2];
      open_loop_B.MultiportSwitch[3] = rtb_FromWs_g[3];
      break;

     default:
      open_loop_B.MultiportSwitch[0] = rtb_FromWs_a[0];
      open_loop_B.MultiportSwitch[1] = rtb_FromWs_a[1];
      open_loop_B.MultiportSwitch[2] = rtb_FromWs_a[2];
      open_loop_B.MultiportSwitch[3] = rtb_FromWs_a[3];
      break;
    }

    /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

    /* Gain: '<Root>/Thrust converter' */
    y = 0.015 * open_loop_P.g / 65536.0;

    /* Gain: '<Root>/Gain' */
    open_loop_B.motor_signals[0] = open_loop_P.Gain_Gain *
      open_loop_B.MultiportSwitch[0];

    /* Gain: '<Root>/Thrust converter' */
    open_loop_B.Thrustconverter[0] = y * open_loop_B.motor_signals[0];

    /* Gain: '<Root>/Gain' */
    open_loop_B.motor_signals[1] = open_loop_P.Gain_Gain *
      open_loop_B.MultiportSwitch[1];

    /* Gain: '<Root>/Thrust converter' */
    open_loop_B.Thrustconverter[1] = y * open_loop_B.motor_signals[1];

    /* Gain: '<Root>/Gain' */
    open_loop_B.motor_signals[2] = open_loop_P.Gain_Gain *
      open_loop_B.MultiportSwitch[2];

    /* Gain: '<Root>/Thrust converter' */
    open_loop_B.Thrustconverter[2] = y * open_loop_B.motor_signals[2];

    /* Gain: '<Root>/Gain' */
    open_loop_B.motor_signals[3] = open_loop_P.Gain_Gain *
      open_loop_B.MultiportSwitch[3];

    /* Gain: '<Root>/Thrust converter' */
    open_loop_B.Thrustconverter[3] = y * open_loop_B.motor_signals[3];

    /* SimscapeInputBlock: '<S21>/INPUT_1_1_1' */
    open_loop_B.INPUT_1_1_1[0] = open_loop_B.Thrustconverter[0];
    open_loop_B.INPUT_1_1_1[1] = 0.0;
    open_loop_B.INPUT_1_1_1[2] = 0.0;
    open_loop_B.INPUT_1_1_1[3] = 0.0;

    /* SimscapeInputBlock: '<S21>/INPUT_1_1_2' */
    open_loop_B.INPUT_1_1_2[0] = open_loop_B.Thrustconverter[1];
    open_loop_B.INPUT_1_1_2[1] = 0.0;
    open_loop_B.INPUT_1_1_2[2] = 0.0;
    open_loop_B.INPUT_1_1_2[3] = 0.0;

    /* SimscapeInputBlock: '<S21>/INPUT_1_1_3' */
    open_loop_B.INPUT_1_1_3[0] = open_loop_B.Thrustconverter[2];
    open_loop_B.INPUT_1_1_3[1] = 0.0;
    open_loop_B.INPUT_1_1_3[2] = 0.0;
    open_loop_B.INPUT_1_1_3[3] = 0.0;

    /* SimscapeInputBlock: '<S21>/INPUT_1_1_4' */
    open_loop_B.INPUT_1_1_4[0] = open_loop_B.Thrustconverter[3];
    open_loop_B.INPUT_1_1_4[1] = 0.0;
    open_loop_B.INPUT_1_1_4[2] = 0.0;
    open_loop_B.INPUT_1_1_4[3] = 0.0;

    /* SimscapeExecutionBlock: '<S21>/STATE_1' incorporates:
     *  SimscapeExecutionBlock: '<S21>/OUTPUT_1_0'
     */
    simulationData = (NeslSimulationData *)open_loop_DW.STATE_1_SimData;
    y = open_loop_M->Timing.t[0];
    time = y;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 110;
    simulationData->mData->mContStates.mX =
      &open_loop_X.open_loopPlant_of_the_quadrocop[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &open_loop_DW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 5;
    simulationData->mData->mModeVector.mX = &open_loop_DW.STATE_1_Modes[0];
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    tmp_4 = rtmIsMajorTimeStep(open_loop_M);
    simulationData->mData->mIsMajorTimeStep = tmp_4;
    tmp = false;
    simulationData->mData->mIsSolverAssertCheck = tmp;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp = rtsiIsSolverComputingJacobian(&open_loop_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    tmp_1[0] = 0;
    tmp_0[0] = open_loop_B.INPUT_1_1_1[0];
    tmp_0[1] = open_loop_B.INPUT_1_1_1[1];
    tmp_0[2] = open_loop_B.INPUT_1_1_1[2];
    tmp_0[3] = open_loop_B.INPUT_1_1_1[3];
    tmp_1[1] = 4;
    tmp_0[4] = open_loop_B.INPUT_1_1_2[0];
    tmp_0[5] = open_loop_B.INPUT_1_1_2[1];
    tmp_0[6] = open_loop_B.INPUT_1_1_2[2];
    tmp_0[7] = open_loop_B.INPUT_1_1_2[3];
    tmp_1[2] = 8;
    tmp_0[8] = open_loop_B.INPUT_1_1_3[0];
    tmp_0[9] = open_loop_B.INPUT_1_1_3[1];
    tmp_0[10] = open_loop_B.INPUT_1_1_3[2];
    tmp_0[11] = open_loop_B.INPUT_1_1_3[3];
    tmp_1[3] = 12;
    tmp_0[12] = open_loop_B.INPUT_1_1_4[0];
    tmp_0[13] = open_loop_B.INPUT_1_1_4[1];
    tmp_0[14] = open_loop_B.INPUT_1_1_4[2];
    tmp_0[15] = open_loop_B.INPUT_1_1_4[3];
    tmp_1[4] = 16;
    simulationData->mData->mInputValues.mN = 16;
    simulationData->mData->mInputValues.mX = &tmp_0[0];
    simulationData->mData->mInputOffsets.mN = 5;
    simulationData->mData->mInputOffsets.mX = &tmp_1[0];
    simulationData->mData->mOutputs.mN = 115;
    simulationData->mData->mOutputs.mX = &open_loop_B.STATE_1[0];
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    diagnosticManager = (NeuDiagnosticManager *)open_loop_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    iy = ne_simulator_method((NeslSimulator *)open_loop_DW.STATE_1_Simulator,
      NESL_SIM_OUTPUTS, simulationData, diagnosticManager);
    if (iy != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(open_loop_M));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(open_loop_M, msg);
      }
    }

    /* End of SimscapeExecutionBlock: '<S21>/STATE_1' */

    /* SimscapeExecutionBlock: '<S21>/OUTPUT_1_0' */
    simulationData = (NeslSimulationData *)open_loop_DW.OUTPUT_1_0_SimData;
    time_0 = y;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_0;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &open_loop_DW.OUTPUT_1_0_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &open_loop_DW.OUTPUT_1_0_Modes;
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    simulationData->mData->mIsMajorTimeStep = tmp_4;
    tmp = false;
    simulationData->mData->mIsSolverAssertCheck = tmp;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    tmp_3[0] = 0;
    tmp_2[0] = open_loop_B.INPUT_1_1_1[0];
    tmp_2[1] = open_loop_B.INPUT_1_1_1[1];
    tmp_2[2] = open_loop_B.INPUT_1_1_1[2];
    tmp_2[3] = open_loop_B.INPUT_1_1_1[3];
    tmp_3[1] = 4;
    tmp_2[4] = open_loop_B.INPUT_1_1_2[0];
    tmp_2[5] = open_loop_B.INPUT_1_1_2[1];
    tmp_2[6] = open_loop_B.INPUT_1_1_2[2];
    tmp_2[7] = open_loop_B.INPUT_1_1_2[3];
    tmp_3[2] = 8;
    tmp_2[8] = open_loop_B.INPUT_1_1_3[0];
    tmp_2[9] = open_loop_B.INPUT_1_1_3[1];
    tmp_2[10] = open_loop_B.INPUT_1_1_3[2];
    tmp_2[11] = open_loop_B.INPUT_1_1_3[3];
    tmp_3[3] = 12;
    tmp_2[12] = open_loop_B.INPUT_1_1_4[0];
    tmp_2[13] = open_loop_B.INPUT_1_1_4[1];
    tmp_2[14] = open_loop_B.INPUT_1_1_4[2];
    tmp_2[15] = open_loop_B.INPUT_1_1_4[3];
    tmp_3[4] = 16;
    memcpy(&tmp_2[16], &open_loop_B.STATE_1[0], 115U * sizeof(real_T));
    tmp_3[5] = 131;
    simulationData->mData->mInputValues.mN = 131;
    simulationData->mData->mInputValues.mX = &tmp_2[0];
    simulationData->mData->mInputOffsets.mN = 6;
    simulationData->mData->mInputOffsets.mX = &tmp_3[0];
    simulationData->mData->mOutputs.mN = 21;
    simulationData->mData->mOutputs.mX = &open_loop_B.OUTPUT_1_0[0];
    simulationData->mData->mSampleHits.mN = 0;
    simulationData->mData->mSampleHits.mX = NULL;
    simulationData->mData->mIsFundamentalSampleHit = false;
    simulationData->mData->mTolerances.mN = 0;
    simulationData->mData->mTolerances.mX = NULL;
    simulationData->mData->mCstateHasChanged = false;
    diagnosticManager = (NeuDiagnosticManager *)open_loop_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    iy = ne_simulator_method((NeslSimulator *)open_loop_DW.OUTPUT_1_0_Simulator,
      NESL_SIM_OUTPUTS, simulationData, diagnosticManager);
    if (iy != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(open_loop_M));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(open_loop_M, msg);
      }
    }

    if (rtmIsMajorTimeStep(open_loop_M)) {
    }

    for (iy = 0; iy < 12; iy++) {
      /* StateSpace: '<Root>/Linearized State-Space' */
      open_loop_B.LinearizedStateSpace[iy] = 0.0;
      for (ci = 0; ci < 12; ci++) {
        open_loop_B.LinearizedStateSpace[iy] += open_loop_P.Cn[ci * 12 + iy] *
          open_loop_X.LinearizedStateSpace_CSTATE[ci];
      }

      /* End of StateSpace: '<Root>/Linearized State-Space' */

      /* Bias: '<Root>/Bias1' */
      open_loop_B.Bias1[iy] = open_loop_B.LinearizedStateSpace[iy] +
        open_loop_P.x_lin[iy];
    }

    /* Gain: '<Root>/G3' */
    open_loop_B.Ang_L[0] = open_loop_P.G3_Gain * open_loop_B.Bias1[6];
    open_loop_B.Ang_L[1] = open_loop_P.G3_Gain * open_loop_B.Bias1[7];
    open_loop_B.Ang_L[2] = open_loop_P.G3_Gain * open_loop_B.Bias1[8];
    if (rtmIsMajorTimeStep(open_loop_M)) {
    }

    /* Gain: '<Root>/G4' */
    open_loop_B.Ang_Vel_L[0] = open_loop_P.G4_Gain * open_loop_B.Bias1[9];
    open_loop_B.Ang_Vel_L[1] = open_loop_P.G4_Gain * open_loop_B.Bias1[10];
    open_loop_B.Ang_Vel_L[2] = open_loop_P.G4_Gain * open_loop_B.Bias1[11];
    if (rtmIsMajorTimeStep(open_loop_M)) {
    }

    /* Bias: '<Root>/Bias' */
    open_loop_B.Bias[0] = open_loop_B.Thrustconverter[0] + -open_loop_P.u_lin[0];
    open_loop_B.Bias[1] = open_loop_B.Thrustconverter[1] + -open_loop_P.u_lin[1];
    open_loop_B.Bias[2] = open_loop_B.Thrustconverter[2] + -open_loop_P.u_lin[2];
    open_loop_B.Bias[3] = open_loop_B.Thrustconverter[3] + -open_loop_P.u_lin[3];

    /* Gain: '<Root>/G1' */
    open_loop_B.eul_angle[0] = open_loop_P.G1_Gain * open_loop_B.OUTPUT_1_0[3];
    open_loop_B.eul_angle[1] = open_loop_P.G1_Gain * open_loop_B.OUTPUT_1_0[4];
    open_loop_B.eul_angle[2] = open_loop_P.G1_Gain * open_loop_B.OUTPUT_1_0[5];
    if (rtmIsMajorTimeStep(open_loop_M)) {
    }

    /* Gain: '<Root>/G2' */
    open_loop_B.d_eul_angle[0] = open_loop_P.G2_Gain * open_loop_B.OUTPUT_1_0[6];
    open_loop_B.d_eul_angle[1] = open_loop_P.G2_Gain * open_loop_B.OUTPUT_1_0[7];
    open_loop_B.d_eul_angle[2] = open_loop_P.G2_Gain * open_loop_B.OUTPUT_1_0[8];
    if (rtmIsMajorTimeStep(open_loop_M)) {
    }
  }

  if (rtmIsMajorTimeStep(open_loop_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(open_loop_M->rtwLogInfo, (open_loop_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(open_loop_M)) {
    NeslSimulationData *simulationData;
    real_T time;
    boolean_T tmp;
    real_T tmp_0[16];
    int_T tmp_1[5];
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    int32_T tmp_2;
    char *msg;

    /* Update for SimscapeExecutionBlock: '<S21>/STATE_1' */
    simulationData = (NeslSimulationData *)open_loop_DW.STATE_1_SimData;
    time = open_loop_M->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 110;
    simulationData->mData->mContStates.mX =
      &open_loop_X.open_loopPlant_of_the_quadrocop[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &open_loop_DW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 5;
    simulationData->mData->mModeVector.mX = &open_loop_DW.STATE_1_Modes[0];
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(open_loop_M);
    tmp = false;
    simulationData->mData->mIsSolverAssertCheck = tmp;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp = rtsiIsSolverComputingJacobian(&open_loop_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    tmp_1[0] = 0;
    tmp_0[0] = open_loop_B.INPUT_1_1_1[0];
    tmp_0[1] = open_loop_B.INPUT_1_1_1[1];
    tmp_0[2] = open_loop_B.INPUT_1_1_1[2];
    tmp_0[3] = open_loop_B.INPUT_1_1_1[3];
    tmp_1[1] = 4;
    tmp_0[4] = open_loop_B.INPUT_1_1_2[0];
    tmp_0[5] = open_loop_B.INPUT_1_1_2[1];
    tmp_0[6] = open_loop_B.INPUT_1_1_2[2];
    tmp_0[7] = open_loop_B.INPUT_1_1_2[3];
    tmp_1[2] = 8;
    tmp_0[8] = open_loop_B.INPUT_1_1_3[0];
    tmp_0[9] = open_loop_B.INPUT_1_1_3[1];
    tmp_0[10] = open_loop_B.INPUT_1_1_3[2];
    tmp_0[11] = open_loop_B.INPUT_1_1_3[3];
    tmp_1[3] = 12;
    tmp_0[12] = open_loop_B.INPUT_1_1_4[0];
    tmp_0[13] = open_loop_B.INPUT_1_1_4[1];
    tmp_0[14] = open_loop_B.INPUT_1_1_4[2];
    tmp_0[15] = open_loop_B.INPUT_1_1_4[3];
    tmp_1[4] = 16;
    simulationData->mData->mInputValues.mN = 16;
    simulationData->mData->mInputValues.mX = &tmp_0[0];
    simulationData->mData->mInputOffsets.mN = 5;
    simulationData->mData->mInputOffsets.mX = &tmp_1[0];
    diagnosticManager = (NeuDiagnosticManager *)open_loop_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_2 = ne_simulator_method((NeslSimulator *)open_loop_DW.STATE_1_Simulator,
      NESL_SIM_UPDATE, simulationData, diagnosticManager);
    if (tmp_2 != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(open_loop_M));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(open_loop_M, msg);
      }
    }

    /* End of Update for SimscapeExecutionBlock: '<S21>/STATE_1' */
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(open_loop_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(open_loop_M)!=-1) &&
          !((rtmGetTFinal(open_loop_M)-(((open_loop_M->Timing.clockTick1+
               open_loop_M->Timing.clockTickH1* 4294967296.0)) * 0.01)) >
            (((open_loop_M->Timing.clockTick1+open_loop_M->Timing.clockTickH1*
               4294967296.0)) * 0.01) * (DBL_EPSILON))) {
        rtmSetErrorStatus(open_loop_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&open_loop_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++open_loop_M->Timing.clockTick0)) {
      ++open_loop_M->Timing.clockTickH0;
    }

    open_loop_M->Timing.t[0] = rtsiGetSolverStopTime(&open_loop_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      open_loop_M->Timing.clockTick1++;
      if (!open_loop_M->Timing.clockTick1) {
        open_loop_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void open_loop_derivatives(void)
{
  NeslSimulationData *simulationData;
  real_T time;
  boolean_T tmp;
  real_T tmp_0[16];
  int_T tmp_1[5];
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  char *msg;
  int_T is;
  int_T ci;
  XDot_open_loop_T *_rtXdot;
  _rtXdot = ((XDot_open_loop_T *) open_loop_M->derivs);

  /* Derivatives for SimscapeExecutionBlock: '<S21>/STATE_1' */
  simulationData = (NeslSimulationData *)open_loop_DW.STATE_1_SimData;
  time = open_loop_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 110;
  simulationData->mData->mContStates.mX =
    &open_loop_X.open_loopPlant_of_the_quadrocop[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &open_loop_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 5;
  simulationData->mData->mModeVector.mX = &open_loop_DW.STATE_1_Modes[0];
  tmp = false;
  simulationData->mData->mFoundZcEvents = tmp;
  simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep(open_loop_M);
  tmp = false;
  simulationData->mData->mIsSolverAssertCheck = tmp;
  simulationData->mData->mIsSolverCheckingCIC = false;
  tmp = rtsiIsSolverComputingJacobian(&open_loop_M->solverInfo);
  simulationData->mData->mIsComputingJacobian = tmp;
  simulationData->mData->mIsEvaluatingF0 = false;
  simulationData->mData->mIsSolverRequestingReset = false;
  tmp_1[0] = 0;
  tmp_0[0] = open_loop_B.INPUT_1_1_1[0];
  tmp_0[1] = open_loop_B.INPUT_1_1_1[1];
  tmp_0[2] = open_loop_B.INPUT_1_1_1[2];
  tmp_0[3] = open_loop_B.INPUT_1_1_1[3];
  tmp_1[1] = 4;
  tmp_0[4] = open_loop_B.INPUT_1_1_2[0];
  tmp_0[5] = open_loop_B.INPUT_1_1_2[1];
  tmp_0[6] = open_loop_B.INPUT_1_1_2[2];
  tmp_0[7] = open_loop_B.INPUT_1_1_2[3];
  tmp_1[2] = 8;
  tmp_0[8] = open_loop_B.INPUT_1_1_3[0];
  tmp_0[9] = open_loop_B.INPUT_1_1_3[1];
  tmp_0[10] = open_loop_B.INPUT_1_1_3[2];
  tmp_0[11] = open_loop_B.INPUT_1_1_3[3];
  tmp_1[3] = 12;
  tmp_0[12] = open_loop_B.INPUT_1_1_4[0];
  tmp_0[13] = open_loop_B.INPUT_1_1_4[1];
  tmp_0[14] = open_loop_B.INPUT_1_1_4[2];
  tmp_0[15] = open_loop_B.INPUT_1_1_4[3];
  tmp_1[4] = 16;
  simulationData->mData->mInputValues.mN = 16;
  simulationData->mData->mInputValues.mX = &tmp_0[0];
  simulationData->mData->mInputOffsets.mN = 5;
  simulationData->mData->mInputOffsets.mX = &tmp_1[0];
  simulationData->mData->mDx.mN = 110;
  simulationData->mData->mDx.mX = &_rtXdot->open_loopPlant_of_the_quadrocop[0];
  diagnosticManager = (NeuDiagnosticManager *)open_loop_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  is = ne_simulator_method((NeslSimulator *)open_loop_DW.STATE_1_Simulator,
    NESL_SIM_DERIVATIVES, simulationData, diagnosticManager);
  if (is != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(open_loop_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(open_loop_M, msg);
    }
  }

  /* End of Derivatives for SimscapeExecutionBlock: '<S21>/STATE_1' */

  /* Derivatives for StateSpace: '<Root>/Linearized State-Space' */
  for (is = 0; is < 12; is++) {
    _rtXdot->LinearizedStateSpace_CSTATE[is] = 0.0;
    for (ci = 0; ci < 12; ci++) {
      _rtXdot->LinearizedStateSpace_CSTATE[is] += open_loop_P.An[ci * 12 + is] *
        open_loop_X.LinearizedStateSpace_CSTATE[ci];
    }

    _rtXdot->LinearizedStateSpace_CSTATE[is] += open_loop_P.Bn[is] *
      open_loop_B.Bias[0];
    _rtXdot->LinearizedStateSpace_CSTATE[is] += open_loop_P.Bn[12 + is] *
      open_loop_B.Bias[1];
    _rtXdot->LinearizedStateSpace_CSTATE[is] += open_loop_P.Bn[24 + is] *
      open_loop_B.Bias[2];
    _rtXdot->LinearizedStateSpace_CSTATE[is] += open_loop_P.Bn[36 + is] *
      open_loop_B.Bias[3];
  }

  /* End of Derivatives for StateSpace: '<Root>/Linearized State-Space' */
}

/* Model initialize function */
void open_loop_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)open_loop_M, 0,
                sizeof(RT_MODEL_open_loop_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&open_loop_M->solverInfo,
                          &open_loop_M->Timing.simTimeStep);
    rtsiSetTPtr(&open_loop_M->solverInfo, &rtmGetTPtr(open_loop_M));
    rtsiSetStepSizePtr(&open_loop_M->solverInfo, &open_loop_M->Timing.stepSize0);
    rtsiSetdXPtr(&open_loop_M->solverInfo, &open_loop_M->derivs);
    rtsiSetContStatesPtr(&open_loop_M->solverInfo, (real_T **)
                         &open_loop_M->contStates);
    rtsiSetNumContStatesPtr(&open_loop_M->solverInfo,
      &open_loop_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&open_loop_M->solverInfo,
      &open_loop_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&open_loop_M->solverInfo,
      &open_loop_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&open_loop_M->solverInfo,
      &open_loop_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&open_loop_M->solverInfo, (&rtmGetErrorStatus
      (open_loop_M)));
    rtsiSetSolverMassMatrixIr(&open_loop_M->solverInfo, open_loop_MassMatrix.ir);
    rtsiSetSolverMassMatrixJc(&open_loop_M->solverInfo, open_loop_MassMatrix.jc);
    rtsiSetSolverMassMatrixPr(&open_loop_M->solverInfo, open_loop_MassMatrix.pr);
    rtsiSetRTModelPtr(&open_loop_M->solverInfo, open_loop_M);
  }

  rtsiSetSimTimeStep(&open_loop_M->solverInfo, MAJOR_TIME_STEP);
  open_loop_M->intgData.x0 = open_loop_M->odeX0;
  open_loop_M->intgData.f0 = open_loop_M->odeF0;
  open_loop_M->intgData.x1start = open_loop_M->odeX1START;
  open_loop_M->intgData.f1 = open_loop_M->odeF1;
  open_loop_M->intgData.Delta = open_loop_M->odeDELTA;
  open_loop_M->intgData.E = open_loop_M->odeE;
  open_loop_M->intgData.fac = open_loop_M->odeFAC;

  /* initialize */
  {
    int_T i;
    real_T *f = open_loop_M->intgData.fac;
    for (i = 0; i < (int_T)(sizeof(open_loop_M->odeFAC)/sizeof(real_T)); i++) {
      f[i] = 1.5e-8;
    }
  }

  open_loop_M->intgData.DFDX = open_loop_M->odeDFDX;
  open_loop_M->intgData.W = open_loop_M->odeW;
  open_loop_M->intgData.pivots = open_loop_M->odePIVOTS;
  open_loop_M->intgData.xtmp = open_loop_M->odeXTMP;
  open_loop_M->intgData.ztmp = open_loop_M->odeZTMP;
  open_loop_M->intgData.M = open_loop_M->odeMASSMATRIX_M;
  open_loop_M->intgData.isFirstStep = true;
  rtsiSetSolverExtrapolationOrder(&open_loop_M->solverInfo, 4);
  rtsiSetSolverNumberNewtonIterations(&open_loop_M->solverInfo, 1);
  open_loop_M->contStates = ((X_open_loop_T *) &open_loop_X);
  open_loop_M->massMatrixType = ((ssMatrixType)1);
  open_loop_M->massMatrixNzMax = (24);
  open_loop_M->massMatrixIr = (open_loop_MassMatrix.ir);
  open_loop_M->massMatrixJc = (open_loop_MassMatrix.jc);
  open_loop_M->massMatrixPr = (open_loop_MassMatrix.pr);
  rtsiSetSolverMassMatrixType(&open_loop_M->solverInfo, (ssMatrixType)1);
  rtsiSetSolverMassMatrixNzMax(&open_loop_M->solverInfo, 24);
  rtsiSetSolverData(&open_loop_M->solverInfo, (void *)&open_loop_M->intgData);
  rtsiSetSolverName(&open_loop_M->solverInfo,"ode14x");
  rtmSetTPtr(open_loop_M, &open_loop_M->Timing.tArray[0]);
  rtmSetTFinal(open_loop_M, 10.0);
  open_loop_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    open_loop_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(open_loop_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(open_loop_M->rtwLogInfo, (NULL));
    rtliSetLogT(open_loop_M->rtwLogInfo, "tout");
    rtliSetLogX(open_loop_M->rtwLogInfo, "");
    rtliSetLogXFinal(open_loop_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(open_loop_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(open_loop_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(open_loop_M->rtwLogInfo, 0);
    rtliSetLogDecimation(open_loop_M->rtwLogInfo, 1);
    rtliSetLogY(open_loop_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(open_loop_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(open_loop_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &open_loop_B), 0,
                sizeof(B_open_loop_T));

  /* states (continuous) */
  {
    (void) memset((void *)&open_loop_X, 0,
                  sizeof(X_open_loop_T));
  }

  /* global mass matrix */
  {
    int_T *ir = open_loop_MassMatrix.ir;
    int_T *jc = open_loop_MassMatrix.jc;
    real_T *pr = open_loop_MassMatrix.pr;
    (void) memset((void *)ir, 0,
                  24*sizeof(int_T));
    (void) memset((void *)jc, 0,
                  (122+1)*sizeof(int_T));
    (void) memset((void *)pr, 0,
                  24*sizeof(real_T));
  }

  /* states (dwork) */
  (void) memset((void *)&open_loop_DW, 0,
                sizeof(DW_open_loop_T));

  /* Root-level init GlobalMassMatrixPr offset */
  {
    open_loop_DW.STATE_1_MASS_MATRIX_PR = 0;/* '<S21>/STATE_1' */
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(open_loop_M->rtwLogInfo, 0.0, rtmGetTFinal
    (open_loop_M), open_loop_M->Timing.stepSize0, (&rtmGetErrorStatus
    (open_loop_M)));

  {
    NeslSimulator *tmp;
    boolean_T tmp_0;
    NeuDiagnosticManager *diagnosticManager;
    NeModelParameters modelParameters;
    real_T tmp_1;
    NeuDiagnosticTree *diagnosticTree;
    int32_T tmp_2;
    char *msg;
    NeslSimulationData *simulationData;
    real_T time;
    NeModelParameters modelParameters_0;
    real_T time_0;
    NeParameterBundle expl_temp;
    real_T time_tmp;
    boolean_T tmp_3;

    /* Start for FromWorkspace: '<S10>/FromWs' */
    {
      static real_T pTimeValues0[] = { 0.0, 4.0000000000000036,
        4.0000000000000036, 5.04, 10.0 } ;

      static real_T pDataValues0[] = { -1.9428902930940239E-16,
        -1.9428902930940239E-16, 10.0, 10.0, 10.0, 0.0, 0.0, 10.0, 10.0, 10.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

      open_loop_DW.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
      open_loop_DW.FromWs_PWORK.DataPtr = (void *) pDataValues0;
      open_loop_DW.FromWs_IWORK.PrevIndex = 0;
    }

    /* Start for FromWorkspace: '<S11>/FromWs' */
    {
      static real_T pTimeValues0[] = { 0.0, 4.0000000000000036,
        4.0000000000000036, 5.04, 6.0, 6.0, 10.0 } ;

      static real_T pDataValues0[] = { -1.9428902930940239E-16,
        -1.9428902930940239E-16, 1000.0, 1000.0, 1000.0, 1000.0, 1000.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2000.0, 2000.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 } ;

      open_loop_DW.FromWs_PWORK_a.TimePtr = (void *) pTimeValues0;
      open_loop_DW.FromWs_PWORK_a.DataPtr = (void *) pDataValues0;
      open_loop_DW.FromWs_IWORK_e.PrevIndex = 0;
    }

    /* Start for FromWorkspace: '<S12>/FromWs' */
    {
      static real_T pTimeValues0[] = { 0.0, 10.0 } ;

      static real_T pDataValues0[] = { 500.0, 500.0, 1000.0, 1000.0, 500.0,
        500.0, 1000.0, 1000.0 } ;

      open_loop_DW.FromWs_PWORK_g.TimePtr = (void *) pTimeValues0;
      open_loop_DW.FromWs_PWORK_g.DataPtr = (void *) pDataValues0;
      open_loop_DW.FromWs_IWORK_g.PrevIndex = 0;
    }

    /* Start for SimscapeExecutionBlock: '<S21>/STATE_1' incorporates:
     *  SimscapeExecutionBlock: '<S21>/OUTPUT_1_0'
     */
    tmp = nesl_lease_simulator("open_loop/Solver Configuration_1", 0, 0);
    open_loop_DW.STATE_1_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(open_loop_DW.STATE_1_Simulator);
    if (tmp_0) {
      open_loop_94817720_1_gateway();
      tmp = nesl_lease_simulator("open_loop/Solver Configuration_1", 0, 0);
      open_loop_DW.STATE_1_Simulator = (void *)tmp;
    }

    simulationData = nesl_create_simulation_data();
    open_loop_DW.STATE_1_SimData = (void *)simulationData;
    diagnosticManager = rtw_create_diagnostics();
    open_loop_DW.STATE_1_DiagMgr = (void *)diagnosticManager;
    modelParameters.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters.mSolverTolerance = 0.001;
    modelParameters.mVariableStepSolver = false;
    modelParameters.mFixedStepSize = 0.01;
    modelParameters.mStartTime = 0.0;
    modelParameters.mLoadInitialState = false;
    modelParameters.mUseSimState = false;
    modelParameters.mLinTrimCompile = false;
    modelParameters.mLoggingMode = SSC_LOGGING_ALL;
    modelParameters.mRTWModifiedTimeStamp = 4.77246959E+8;
    tmp_1 = 0.001;
    modelParameters.mSolverTolerance = tmp_1;
    tmp_1 = 0.01;
    modelParameters.mFixedStepSize = tmp_1;
    tmp_0 = false;
    modelParameters.mVariableStepSolver = tmp_0;
    diagnosticManager = (NeuDiagnosticManager *)open_loop_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_2 = nesl_initialize_simulator((NeslSimulator *)
      open_loop_DW.STATE_1_Simulator, &modelParameters, diagnosticManager);
    if (tmp_2 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(open_loop_M));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(open_loop_M, msg);
      }
    }

    expl_temp.mRealParameters.mN = 0;
    expl_temp.mRealParameters.mX = NULL;
    expl_temp.mLogicalParameters.mN = 0;
    expl_temp.mLogicalParameters.mX = NULL;
    expl_temp.mIntegerParameters.mN = 0;
    expl_temp.mIntegerParameters.mX = NULL;
    expl_temp.mIndexParameters.mN = 0;
    expl_temp.mIndexParameters.mX = NULL;
    nesl_simulator_set_rtps((NeslSimulator *)open_loop_DW.STATE_1_Simulator,
      expl_temp);
    simulationData = (NeslSimulationData *)open_loop_DW.STATE_1_SimData;
    time_tmp = open_loop_M->Timing.t[0];
    time = time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 110;
    simulationData->mData->mContStates.mX =
      &open_loop_X.open_loopPlant_of_the_quadrocop[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &open_loop_DW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 5;
    simulationData->mData->mModeVector.mX = &open_loop_DW.STATE_1_Modes[0];
    tmp_0 = false;
    simulationData->mData->mFoundZcEvents = tmp_0;
    tmp_3 = rtmIsMajorTimeStep(open_loop_M);
    simulationData->mData->mIsMajorTimeStep = tmp_3;
    tmp_0 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_0;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp_0 = rtsiIsSolverComputingJacobian(&open_loop_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp_0;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    diagnosticManager = (NeuDiagnosticManager *)open_loop_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_2 = ne_simulator_method((NeslSimulator *)open_loop_DW.STATE_1_Simulator,
      NESL_SIM_INITIALIZEONCE, simulationData, diagnosticManager);
    if (tmp_2 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(open_loop_M));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(open_loop_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S21>/STATE_1' */

    /* Start for SimscapeExecutionBlock: '<S21>/OUTPUT_1_0' */
    tmp = nesl_lease_simulator("open_loop/Solver Configuration_1", 1, 0);
    open_loop_DW.OUTPUT_1_0_Simulator = (void *)tmp;
    tmp_0 = pointer_is_null(open_loop_DW.OUTPUT_1_0_Simulator);
    if (tmp_0) {
      open_loop_94817720_1_gateway();
      tmp = nesl_lease_simulator("open_loop/Solver Configuration_1", 1, 0);
      open_loop_DW.OUTPUT_1_0_Simulator = (void *)tmp;
    }

    simulationData = nesl_create_simulation_data();
    open_loop_DW.OUTPUT_1_0_SimData = (void *)simulationData;
    diagnosticManager = rtw_create_diagnostics();
    open_loop_DW.OUTPUT_1_0_DiagMgr = (void *)diagnosticManager;
    modelParameters_0.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_0.mSolverTolerance = 0.001;
    modelParameters_0.mVariableStepSolver = false;
    modelParameters_0.mFixedStepSize = 0.01;
    modelParameters_0.mStartTime = 0.0;
    modelParameters_0.mLoadInitialState = false;
    modelParameters_0.mUseSimState = false;
    modelParameters_0.mLinTrimCompile = false;
    modelParameters_0.mLoggingMode = SSC_LOGGING_ALL;
    modelParameters_0.mRTWModifiedTimeStamp = 4.77246959E+8;
    tmp_1 = 0.001;
    modelParameters_0.mSolverTolerance = tmp_1;
    tmp_1 = 0.01;
    modelParameters_0.mFixedStepSize = tmp_1;
    tmp_0 = false;
    modelParameters_0.mVariableStepSolver = tmp_0;
    diagnosticManager = (NeuDiagnosticManager *)open_loop_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_2 = nesl_initialize_simulator((NeslSimulator *)
      open_loop_DW.OUTPUT_1_0_Simulator, &modelParameters_0, diagnosticManager);
    if (tmp_2 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(open_loop_M));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(open_loop_M, msg);
      }
    }

    simulationData = (NeslSimulationData *)open_loop_DW.OUTPUT_1_0_SimData;
    time_0 = time_tmp;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time_0;
    simulationData->mData->mContStates.mN = 0;
    simulationData->mData->mContStates.mX = NULL;
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX = &open_loop_DW.OUTPUT_1_0_Discrete;
    simulationData->mData->mModeVector.mN = 0;
    simulationData->mData->mModeVector.mX = &open_loop_DW.OUTPUT_1_0_Modes;
    tmp_0 = false;
    simulationData->mData->mFoundZcEvents = tmp_0;
    simulationData->mData->mIsMajorTimeStep = tmp_3;
    tmp_0 = false;
    simulationData->mData->mIsSolverAssertCheck = tmp_0;
    simulationData->mData->mIsSolverCheckingCIC = false;
    simulationData->mData->mIsComputingJacobian = false;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    diagnosticManager = (NeuDiagnosticManager *)open_loop_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_2 = ne_simulator_method((NeslSimulator *)
      open_loop_DW.OUTPUT_1_0_Simulator, NESL_SIM_INITIALIZEONCE, simulationData,
      diagnosticManager);
    if (tmp_2 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(open_loop_M));
      if (tmp_0) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(open_loop_M, msg);
      }
    }
  }

  {
    boolean_T tmp;
    char *tmp_0;
    int_T is;

    /* InitializeConditions for SimscapeExecutionBlock: '<S21>/STATE_1' */
    tmp = false;
    if (tmp) {
      is = strcmp("ode14x", rtsiGetSolverName(&open_loop_M->solverInfo));
      if (is != 0) {
        tmp_0 = solver_mismatch_message("ode14x", rtsiGetSolverName
          (&open_loop_M->solverInfo));
        rtmSetErrorStatus(open_loop_M, tmp_0);
      }
    }

    /* End of InitializeConditions for SimscapeExecutionBlock: '<S21>/STATE_1' */

    /* InitializeConditions for StateSpace: '<Root>/Linearized State-Space' */
    memcpy(&open_loop_X.LinearizedStateSpace_CSTATE[0], &open_loop_P.x0[0], 12U *
           sizeof(real_T));

    /* Root-level InitSystemMatrices */
    {
      static int_T modelMassMatrixIr[24] = { 9, 10, 11, 3, 4, 5, 0, 1, 2, 6, 7,
        8, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121 };

      static int_T modelMassMatrixJc[123] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 14, 15, 16, 17, 18, 19, 20,
        21, 22, 23, 24 };

      static real_T modelMassMatrixPr[24] = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0 };

      (void) memcpy(open_loop_MassMatrix.ir, modelMassMatrixIr,
                    24*sizeof(int_T));
      (void) memcpy(open_loop_MassMatrix.jc, modelMassMatrixJc,
                    123*sizeof(int_T));
      (void) memcpy(open_loop_MassMatrix.pr, modelMassMatrixPr,
                    24*sizeof(real_T));
    }
  }
}

/* Model terminate function */
void open_loop_terminate(void)
{
  /* Terminate for SimscapeExecutionBlock: '<S21>/STATE_1' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    open_loop_DW.STATE_1_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    open_loop_DW.STATE_1_SimData);
  nesl_erase_simulator("open_loop/Solver Configuration_1");

  /* Terminate for SimscapeExecutionBlock: '<S21>/OUTPUT_1_0' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    open_loop_DW.OUTPUT_1_0_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    open_loop_DW.OUTPUT_1_0_SimData);
  nesl_erase_simulator("open_loop/Solver Configuration_1");
}
