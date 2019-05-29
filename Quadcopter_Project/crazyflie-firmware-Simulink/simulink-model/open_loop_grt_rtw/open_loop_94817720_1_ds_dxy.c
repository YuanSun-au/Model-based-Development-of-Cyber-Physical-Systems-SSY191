/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'open_loop/Solver Configuration'.
 */

#include "ne_ds.h"
#include "open_loop_94817720_1_ds_dxy.h"
#include "open_loop_94817720_1_ds_sys_struct.h"
#include "open_loop_94817720_1_ds_externals.h"
#include "open_loop_94817720_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T open_loop_94817720_1_ds_dxy(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmRealVector out;
  (void)t1;
  out = t2->mDXY;
  out.mX[0] = 1.0;
  out.mX[1] = 0.0;
  out.mX[2] = 0.0;
  out.mX[3] = 0.0;
  out.mX[4] = 1.0;
  out.mX[5] = 0.0;
  out.mX[6] = 0.0;
  out.mX[7] = 0.0;
  out.mX[8] = 1.0;
  out.mX[9] = 1.0;
  out.mX[10] = 0.0;
  out.mX[11] = 0.0;
  out.mX[12] = 0.0;
  out.mX[13] = 1.0;
  out.mX[14] = 0.0;
  out.mX[15] = 0.0;
  out.mX[16] = 0.0;
  out.mX[17] = 1.0;
  out.mX[18] = 1.0;
  out.mX[19] = 0.0;
  out.mX[20] = 0.0;
  out.mX[21] = 0.0;
  out.mX[22] = 1.0;
  out.mX[23] = 0.0;
  out.mX[24] = 0.0;
  out.mX[25] = 0.0;
  out.mX[26] = 1.0;
  out.mX[27] = 1.0;
  out.mX[28] = 0.0;
  out.mX[29] = 0.0;
  out.mX[30] = 57.295779513082323;
  out.mX[31] = 0.0;
  out.mX[32] = 0.0;
  out.mX[33] = 0.0;
  out.mX[34] = 1.0;
  out.mX[35] = 0.0;
  out.mX[36] = 0.0;
  out.mX[37] = 57.295779513082323;
  out.mX[38] = 0.0;
  out.mX[39] = 0.0;
  out.mX[40] = 0.0;
  out.mX[41] = 1.0;
  out.mX[42] = 0.0;
  out.mX[43] = 0.0;
  out.mX[44] = 57.295779513082323;
  out.mX[45] = 1.0;
  out.mX[46] = 0.0;
  out.mX[47] = 0.0;
  out.mX[48] = 0.0;
  out.mX[49] = 1.0;
  out.mX[50] = 0.0;
  out.mX[51] = 0.0;
  out.mX[52] = 0.0;
  out.mX[53] = 1.0;
  (void)sys;
  (void)t2;
  return 0;
}
