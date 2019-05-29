/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'open_loop/Solver Configuration'.
 */

#include "ne_ds.h"
#include "open_loop_94817720_1_ds_tdxy_p.h"
#include "open_loop_94817720_1_ds_sys_struct.h"
#include "open_loop_94817720_1_ds_externals.h"
#include "open_loop_94817720_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T open_loop_94817720_1_ds_tdxy_p(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  int32_T b;
  static int32_T _cg_const_1[111] = { 0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 27, 27,
    27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
    27, 27, 27, 27, 33, 39, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45,
    45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45,
    45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45,
    45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45,
    45, 48, 51, 54 };

  (void)t1;
  out = t2->mTDXY_P;
  out.mNumCol = 110UL;
  out.mNumRow = 21UL;
  for (b = 0; b < 111; b++) {
    out.mJc[b] = _cg_const_1[b];
  }

  out.mIr[0] = 3;
  out.mIr[1] = 4;
  out.mIr[2] = 5;
  out.mIr[3] = 3;
  out.mIr[4] = 4;
  out.mIr[5] = 5;
  out.mIr[6] = 3;
  out.mIr[7] = 4;
  out.mIr[8] = 5;
  out.mIr[9] = 9;
  out.mIr[10] = 10;
  out.mIr[11] = 11;
  out.mIr[12] = 9;
  out.mIr[13] = 10;
  out.mIr[14] = 11;
  out.mIr[15] = 9;
  out.mIr[16] = 10;
  out.mIr[17] = 11;
  out.mIr[18] = 12;
  out.mIr[19] = 13;
  out.mIr[20] = 14;
  out.mIr[21] = 12;
  out.mIr[22] = 13;
  out.mIr[23] = 14;
  out.mIr[24] = 12;
  out.mIr[25] = 13;
  out.mIr[26] = 14;
  out.mIr[27] = 6;
  out.mIr[28] = 7;
  out.mIr[29] = 8;
  out.mIr[30] = 18;
  out.mIr[31] = 19;
  out.mIr[32] = 20;
  out.mIr[33] = 6;
  out.mIr[34] = 7;
  out.mIr[35] = 8;
  out.mIr[36] = 18;
  out.mIr[37] = 19;
  out.mIr[38] = 20;
  out.mIr[39] = 6;
  out.mIr[40] = 7;
  out.mIr[41] = 8;
  out.mIr[42] = 18;
  out.mIr[43] = 19;
  out.mIr[44] = 20;
  out.mIr[45] = 15;
  out.mIr[46] = 16;
  out.mIr[47] = 17;
  out.mIr[48] = 15;
  out.mIr[49] = 16;
  out.mIr[50] = 17;
  out.mIr[51] = 15;
  out.mIr[52] = 16;
  out.mIr[53] = 17;
  (void)sys;
  (void)t2;
  return 0;
}
