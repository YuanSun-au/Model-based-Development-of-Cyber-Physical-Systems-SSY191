/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'open_loop/Solver Configuration'.
 */

#include "ne_ds.h"
#include "open_loop_94817720_1_ds_duf.h"
#include "open_loop_94817720_1_ds_sys_struct.h"
#include "open_loop_94817720_1_ds_externals.h"
#include "open_loop_94817720_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T open_loop_94817720_1_ds_duf(const NeDynamicSystem *t0, const
  NeDynamicSystemInput *t12, NeDsMethodOutput *t13)
{
  PmRealVector out;
  real_T t1[16];
  real_T t2[16];
  size_t t3;
  size_t t4;
  size_t t5;
  real_T t6;
  int32_T M[5];
  real_T U[4];
  (void)t0;
  M[0] = t12->mM.mX[0];
  M[1] = t12->mM.mX[1];
  M[2] = t12->mM.mX[2];
  M[3] = t12->mM.mX[3];
  M[4] = t12->mM.mX[4];
  U[0] = t12->mU.mX[0];
  U[1] = t12->mU.mX[1];
  U[2] = t12->mU.mX[2];
  U[3] = t12->mU.mX[3];
  out = t13->mDUF;
  t2[0] = 9.9999999999999988E+8;
  t2[1] = 0.0;
  t2[2] = 0.0;
  t2[3] = 0.0;
  t2[4] = 0.0;
  t2[5] = 9.9999999999999988E+8;
  t2[6] = 0.0;
  t2[7] = 0.0;
  t2[8] = 0.0;
  t2[9] = 0.0;
  t2[10] = 9.9999999999999988E+8;
  t2[11] = 0.0;
  t2[12] = 0.0;
  t2[13] = 0.0;
  t2[14] = 0.0;
  t2[15] = 9.9999999999999988E+8;
  for (t3 = 0UL; t3 < 16UL; t3++) {
    t4 = (t3 - t3 / 4UL * 4UL) % 4UL;
    t5 = (t3 - t3 / 4UL * 4UL) % 4UL;
    t6 = pmf_sqrt(((real_T)(M[t4 > 4UL ? 4UL : t4] != 0) * 2.0 - 1.0) * U[t5 >
                  3UL ? 3UL : t5] / 1.0E-9) * 2.0;
    t4 = (t3 - t3 / 4UL * 4UL) % 4UL;
    t1[t3] = -(1.0 / (t6 == 0.0 ? 1.0E-16 : t6) * ((real_T)(M[t4 > 4UL ? 4UL :
      t4] != 0) * 2.0 - 1.0) * t2[t3]);
  }

  out.mX[0] = t1[0];
  out.mX[1] = t1[1];
  out.mX[2] = t1[2];
  out.mX[3] = t1[3];
  out.mX[4] = t1[4];
  out.mX[5] = t1[5];
  out.mX[6] = t1[6];
  out.mX[7] = t1[7];
  out.mX[8] = t1[8];
  out.mX[9] = t1[9];
  out.mX[10] = t1[10];
  out.mX[11] = t1[11];
  out.mX[12] = t1[12];
  out.mX[13] = t1[13];
  out.mX[14] = t1[14];
  out.mX[15] = t1[15];
  (void)t0;
  (void)t13;
  return 0;
}
