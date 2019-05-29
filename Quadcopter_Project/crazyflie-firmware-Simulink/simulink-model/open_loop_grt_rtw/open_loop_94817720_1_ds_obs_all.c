/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'open_loop/Solver Configuration'.
 */

#include "ne_ds.h"
#include "open_loop_94817720_1_ds_obs_all.h"
#include "open_loop_94817720_1_ds_sys_struct.h"
#include "open_loop_94817720_1_ds_externals.h"
#include "open_loop_94817720_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T open_loop_94817720_1_ds_obs_all(const NeDynamicSystem *t0, const
  NeDynamicSystemInput *t47, NeDsMethodOutput *t48)
{
  PmRealVector out;
  real_T t1[144];
  size_t t21;
  real_T t32;
  real_T t33;
  real_T t34;
  real_T U[4];
  real_T X[110];
  int32_T b;
  (void)t0;
  U[0] = t47->mU.mX[0];
  U[1] = t47->mU.mX[1];
  U[2] = t47->mU.mX[2];
  U[3] = t47->mU.mX[3];
  for (b = 0; b < 110; b++) {
    X[b] = t47->mX.mX[b];
  }

  out = t48->mOBS_ALL;
  t32 = ((U[0UL] * -0.032526911934581189 + U[1UL] * -0.032526911934581189) + U
         [2UL] * 0.032526911934581189) + U[3UL] * 0.032526911934581189;
  t33 = ((U[0UL] * -0.032526911934581189 + U[1UL] * 0.032526911934581189) + U
         [2UL] * 0.032526911934581189) + U[3UL] * -0.032526911934581189;
  t34 = ((-X[30UL] + -X[32UL]) + X[31UL]) + X[33UL];
  for (t21 = 0UL; t21 < 9UL; t21++) {
    t1[t21] = X[t21 + 12UL];
  }

  for (t21 = 9UL; t21 - 9UL < 9UL; t21++) {
    t1[t21] = X[t21 + 12UL];
  }

  t1[18UL] = t32;
  t1[19UL] = t33;
  t1[20UL] = t34;
  t1[21UL] = t32;
  t1[22UL] = t33;
  t1[23UL] = t34;
  for (t21 = 24UL; t21 - 24UL < 4UL; t21++) {
    t1[t21] = X[t21 + 6UL];
  }

  t1[28UL] = 0.0;
  t1[29UL] = 0.0;
  t1[30UL] = 0.0;
  t1[31UL] = X[0UL];
  t1[32UL] = X[1UL];
  t1[33UL] = X[2UL];
  for (t21 = 0UL; t21 < 4UL; t21++) {
    t1[t21 + 34UL] = U[t21];
  }

  t1[38UL] = X[34UL];
  t1[39UL] = X[35UL];
  t1[40UL] = X[36UL];
  t1[41UL] = X[0UL];
  t1[42UL] = X[3UL];
  t1[43UL] = X[4UL];
  t1[44UL] = X[5UL];
  t1[45UL] = X[2UL];
  for (t21 = 37UL; t21 - 37UL < 4UL; t21++) {
    t1[t21 + 9UL] = X[t21];
  }

  for (t21 = 41UL; t21 - 41UL < 9UL; t21++) {
    t1[t21 + 9UL] = X[t21];
  }

  for (t21 = 50UL; t21 - 50UL < 9UL; t21++) {
    t1[t21 + 9UL] = X[t21];
  }

  for (t21 = 59UL; t21 - 59UL < 9UL; t21++) {
    t1[t21 + 9UL] = X[t21];
  }

  t1[77UL] = X[1UL];
  t1[78UL] = X[6UL];
  t1[79UL] = X[7UL];
  t1[80UL] = X[8UL];
  t1[81UL] = X[68UL];
  t1[82UL] = X[69UL];
  t1[83UL] = X[70UL];
  t1[84UL] = X[9UL];
  t1[85UL] = X[10UL];
  t1[86UL] = X[11UL];
  for (t21 = 71UL; t21 - 71UL < 9UL; t21++) {
    t1[t21 + 16UL] = X[t21];
  }

  for (t21 = 80UL; t21 - 80UL < 9UL; t21++) {
    t1[t21 + 16UL] = X[t21];
  }

  for (t21 = 89UL; t21 - 89UL < 9UL; t21++) {
    t1[t21 + 16UL] = X[t21];
  }

  for (t21 = 98UL; t21 - 98UL < 9UL; t21++) {
    t1[t21 + 16UL] = X[t21];
  }

  t1[123UL] = 0.0;
  t1[124UL] = 0.0;
  t1[125UL] = 0.0;
  t1[126UL] = X[107UL];
  t1[127UL] = X[108UL];
  t1[128UL] = X[109UL];
  t1[129UL] = X[0UL];
  t1[130UL] = X[1UL];
  t1[131UL] = X[2UL];
  t1[132UL] = X[34UL] * 57.295779513082323;
  t1[133UL] = X[35UL] * 57.295779513082323;
  t1[134UL] = X[36UL] * 57.295779513082323;
  t1[135UL] = X[3UL];
  t1[136UL] = X[4UL];
  t1[137UL] = X[5UL];
  t1[138UL] = X[6UL];
  t1[139UL] = X[7UL];
  t1[140UL] = X[8UL];
  t1[141UL] = X[34UL];
  t1[142UL] = X[35UL];
  t1[143UL] = X[36UL];
  for (b = 0; b < 144; b++) {
    out.mX[b] = t1[b];
  }

  (void)t0;
  (void)t48;
  return 0;
}
