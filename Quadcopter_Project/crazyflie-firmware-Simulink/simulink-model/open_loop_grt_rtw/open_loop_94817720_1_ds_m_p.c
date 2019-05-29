/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'open_loop/Solver Configuration'.
 */

#include "ne_ds.h"
#include "open_loop_94817720_1_ds_m_p.h"
#include "open_loop_94817720_1_ds_sys_struct.h"
#include "open_loop_94817720_1_ds_externals.h"
#include "open_loop_94817720_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T open_loop_94817720_1_ds_m_p(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  int32_T b;
  static int32_T _cg_const_1[111] = { 0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33,
    36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
    36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
    36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
    36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
    36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36,
    36, 36, 36, 36 };

  (void)t1;
  out = t2->mM_P;
  out.mNumCol = 110UL;
  out.mNumRow = 110UL;
  for (b = 0; b < 111; b++) {
    out.mJc[b] = _cg_const_1[b];
  }

  out.mIr[0] = 9;
  out.mIr[1] = 10;
  out.mIr[2] = 11;
  out.mIr[3] = 9;
  out.mIr[4] = 10;
  out.mIr[5] = 11;
  out.mIr[6] = 9;
  out.mIr[7] = 10;
  out.mIr[8] = 11;
  out.mIr[9] = 3;
  out.mIr[10] = 4;
  out.mIr[11] = 5;
  out.mIr[12] = 3;
  out.mIr[13] = 4;
  out.mIr[14] = 5;
  out.mIr[15] = 3;
  out.mIr[16] = 4;
  out.mIr[17] = 5;
  out.mIr[18] = 0;
  out.mIr[19] = 1;
  out.mIr[20] = 2;
  out.mIr[21] = 0;
  out.mIr[22] = 1;
  out.mIr[23] = 2;
  out.mIr[24] = 0;
  out.mIr[25] = 1;
  out.mIr[26] = 2;
  out.mIr[27] = 6;
  out.mIr[28] = 7;
  out.mIr[29] = 8;
  out.mIr[30] = 6;
  out.mIr[31] = 7;
  out.mIr[32] = 8;
  out.mIr[33] = 6;
  out.mIr[34] = 7;
  out.mIr[35] = 8;
  (void)sys;
  (void)t2;
  return 0;
}
