/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'open_loop/Solver Configuration'.
 */

#include "ne_ds.h"
#include "open_loop_94817720_1_ds_vmf.h"
#include "open_loop_94817720_1_ds_sys_struct.h"
#include "open_loop_94817720_1_ds_externals.h"
#include "open_loop_94817720_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T open_loop_94817720_1_ds_vmf(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmBoolVector out;
  boolean_T t0[110];
  int32_T b;
  static boolean_T _cg_const_1[110] = { false, false, false, false, false, false,
    true, true, true, false, false, false, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true, true, true, true, true, true, true, true, true, true, true, true, true,
    true };

  (void)t1;
  out = t2->mVMF;
  for (b = 0; b < 110; b++) {
    t0[b] = _cg_const_1[b];
  }

  for (b = 0; b < 110; b++) {
    out.mX[b] = t0[b];
  }

  (void)sys;
  (void)t2;
  return 0;
}
