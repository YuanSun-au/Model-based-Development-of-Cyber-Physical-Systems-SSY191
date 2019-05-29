/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'open_loop/Solver Configuration'.
 */

#include "ne_ds.h"
#include "open_loop_94817720_1_ds_f.h"
#include "open_loop_94817720_1_ds_sys_struct.h"
#include "open_loop_94817720_1_ds_externals.h"
#include "open_loop_94817720_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T open_loop_94817720_1_ds_f(const NeDynamicSystem *t0, const
  NeDynamicSystemInput *t320, NeDsMethodOutput *t321)
{
  PmRealVector out;
  real_T t1[110];
  real_T t13[4];
  real_T t18[9];
  real_T t19[9];
  real_T t20[9];
  real_T t24[9];
  real_T t26[9];
  real_T t30[9];
  real_T t32[9];
  real_T t34[9];
  real_T t41[9];
  real_T t49[9];
  real_T t55[9];
  real_T t61[9];
  real_T t65[9];
  size_t t129;
  real_T t188;
  real_T t192;
  real_T t213;
  real_T t215;
  real_T t229;
  real_T t266;
  real_T t267;
  real_T t268;
  real_T t269;
  real_T t278;
  real_T t285;
  real_T t290;
  real_T t294;
  real_T t313;
  real_T t316;
  int32_T M[5];
  real_T U[4];
  real_T X[110];
  int32_T b;
  (void)t0;
  M[0] = t320->mM.mX[0];
  M[1] = t320->mM.mX[1];
  M[2] = t320->mM.mX[2];
  M[3] = t320->mM.mX[3];
  M[4] = t320->mM.mX[4];
  U[0] = t320->mU.mX[0];
  U[1] = t320->mU.mX[1];
  U[2] = t320->mU.mX[2];
  U[3] = t320->mU.mX[3];
  for (b = 0; b < 110; b++) {
    X[b] = t320->mX.mX[b];
  }

  out = t321->mF;
  t192 = (1.395E-5 * X[9UL] + 0.0 * X[10UL]) + 0.0 * X[11UL];
  t313 = (0.0 * X[9UL] + 1.436E-5 * X[10UL]) + 0.0 * X[11UL];
  t316 = (0.0 * X[9UL] + 0.0 * X[10UL]) + 2.173E-5 * X[11UL];
  t294 = -X[10UL] * t316 - -X[11UL] * t313;
  t290 = -X[11UL] * t192 - -X[9UL] * t316;
  t316 = -X[9UL] * t313 - -X[10UL] * t192;
  t13[0] = 1.0;
  t13[1] = 1.0;
  t13[2] = 1.0;
  t13[3] = 1.0;
  t313 = cos(X[0UL]);
  t213 = -sin(X[0UL]);
  t229 = sin(X[0UL]);
  t18[0UL] = 0.0;
  t18[3UL] = 0.0;
  t18[6UL] = 0.0;
  t18[1UL] = 0.0;
  t18[4UL] = t313;
  t18[7UL] = t213;
  t18[2UL] = 0.0;
  t18[5UL] = t229;
  t18[8UL] = t313;
  t19[0] = 1.0;
  t19[1] = 1.0;
  t19[2] = 1.0;
  t19[3] = 1.0;
  t19[4] = 1.0;
  t19[5] = 1.0;
  t19[6] = 1.0;
  t19[7] = 1.0;
  t19[8] = 1.0;
  t20[0] = -1.0;
  t20[1] = -0.0;
  t20[2] = -0.0;
  t20[3] = -0.0;
  t20[4] = -0.0;
  t20[5] = -0.0;
  t20[6] = -0.0;
  t20[7] = -0.0;
  t20[8] = -0.0;
  t213 = cos(X[1UL]);
  t188 = sin(X[1UL]);
  t192 = -sin(X[1UL]);
  t24[0UL] = t213;
  t24[3UL] = 0.0;
  t24[6UL] = t188;
  t24[1UL] = 0.0;
  t24[4UL] = 0.0;
  t24[7UL] = 0.0;
  t24[2UL] = t192;
  t24[5UL] = 0.0;
  t24[8UL] = t213;
  t26[0] = -0.0;
  t26[1] = -0.0;
  t26[2] = -0.0;
  t26[3] = -0.0;
  t26[4] = -1.0;
  t26[5] = -0.0;
  t26[6] = -0.0;
  t26[7] = -0.0;
  t26[8] = -0.0;
  t213 = cos(X[2UL]);
  t192 = -sin(X[2UL]);
  t215 = sin(X[2UL]);
  t30[0UL] = t213;
  t30[3UL] = t192;
  t30[6UL] = 0.0;
  t30[1UL] = t215;
  t30[4UL] = t213;
  t30[7UL] = 0.0;
  t30[2UL] = 0.0;
  t30[5UL] = 0.0;
  t30[8UL] = 0.0;
  t32[0] = -0.0;
  t32[1] = -0.0;
  t32[2] = -0.0;
  t32[3] = -0.0;
  t32[4] = -0.0;
  t32[5] = -0.0;
  t32[6] = -0.0;
  t32[7] = -0.0;
  t32[8] = -1.0;
  t213 = (X[41UL] * X[50UL] + X[44UL] * X[51UL]) + X[47UL] * X[52UL];
  t278 = (X[41UL] * X[53UL] + X[44UL] * X[54UL]) + X[47UL] * X[55UL];
  t267 = (X[41UL] * X[56UL] + X[44UL] * X[57UL]) + X[47UL] * X[58UL];
  t192 = (X[42UL] * X[50UL] + X[45UL] * X[51UL]) + X[48UL] * X[52UL];
  t285 = (X[42UL] * X[53UL] + X[45UL] * X[54UL]) + X[48UL] * X[55UL];
  t268 = (X[42UL] * X[56UL] + X[45UL] * X[57UL]) + X[48UL] * X[58UL];
  t215 = (X[43UL] * X[50UL] + X[46UL] * X[51UL]) + X[49UL] * X[52UL];
  t266 = (X[43UL] * X[53UL] + X[46UL] * X[54UL]) + X[49UL] * X[55UL];
  t269 = (X[43UL] * X[56UL] + X[46UL] * X[57UL]) + X[49UL] * X[58UL];
  t34[0UL] = (t213 * X[59UL] + t278 * X[60UL]) + t267 * X[61UL];
  t34[3UL] = t213 * X[62UL];
  t34[3UL] += t278 * X[63UL];
  t34[3UL] += t267 * X[64UL];
  t34[6UL] = t213 * X[65UL];
  t34[6UL] += t278 * X[66UL];
  t34[6UL] += t267 * X[67UL];
  t34[1UL] = t192 * X[59UL];
  t34[1UL] += t285 * X[60UL];
  t34[1UL] += t268 * X[61UL];
  t34[4UL] = t192 * X[62UL];
  t34[4UL] += t285 * X[63UL];
  t34[4UL] += t268 * X[64UL];
  t34[7UL] = t192 * X[65UL];
  t34[7UL] += t285 * X[66UL];
  t34[7UL] += t268 * X[67UL];
  t34[2UL] = t215 * X[59UL];
  t34[2UL] += t266 * X[60UL];
  t34[2UL] += t269 * X[61UL];
  t34[5UL] = t215 * X[62UL];
  t34[5UL] += t266 * X[63UL];
  t34[5UL] += t269 * X[64UL];
  t34[8UL] = t215 * X[65UL];
  t34[8UL] += t266 * X[66UL];
  t34[8UL] += t269 * X[67UL];
  t278 = -cos(X[1UL]) * sin(X[0UL]);
  t285 = cos(X[0UL]) * cos(X[1UL]);
  t41[0UL] = 0.0;
  t41[3UL] = 0.0;
  t41[6UL] = t188;
  t41[1UL] = 0.0;
  t41[4UL] = t313;
  t41[7UL] = t278;
  t41[2UL] = 0.0;
  t41[5UL] = t229;
  t41[8UL] = t285;
  t278 = cos(X[0UL]);
  t285 = -sin(X[0UL]);
  t266 = sin(X[0UL]);
  t49[0UL] = 0.0;
  t49[3UL] = 0.0;
  t49[6UL] = 0.0;
  t49[1UL] = 0.0;
  t49[4UL] = t278;
  t49[7UL] = t285;
  t49[2UL] = 0.0;
  t49[5UL] = t266;
  t49[8UL] = t278;
  t192 = cos(X[1UL]);
  t278 = sin(X[1UL]);
  t285 = -sin(X[1UL]);
  t55[0UL] = t192;
  t55[3UL] = 0.0;
  t55[6UL] = t278;
  t55[1UL] = 0.0;
  t55[4UL] = 0.0;
  t55[7UL] = 0.0;
  t55[2UL] = t285;
  t55[5UL] = 0.0;
  t55[8UL] = t192;
  t192 = cos(X[2UL]);
  t313 = -sin(X[2UL]);
  t278 = sin(X[2UL]);
  t61[0UL] = t192;
  t61[3UL] = t313;
  t61[6UL] = 0.0;
  t61[1UL] = t278;
  t61[4UL] = t192;
  t61[7UL] = 0.0;
  t61[2UL] = 0.0;
  t61[5UL] = 0.0;
  t61[8UL] = 0.0;
  t192 = (X[80UL] * X[89UL] + X[83UL] * X[90UL]) + X[86UL] * X[91UL];
  t278 = (X[80UL] * X[92UL] + X[83UL] * X[93UL]) + X[86UL] * X[94UL];
  t267 = (X[80UL] * X[95UL] + X[83UL] * X[96UL]) + X[86UL] * X[97UL];
  t213 = (X[81UL] * X[89UL] + X[84UL] * X[90UL]) + X[87UL] * X[91UL];
  t285 = (X[81UL] * X[92UL] + X[84UL] * X[93UL]) + X[87UL] * X[94UL];
  t268 = (X[81UL] * X[95UL] + X[84UL] * X[96UL]) + X[87UL] * X[97UL];
  t313 = (X[82UL] * X[89UL] + X[85UL] * X[90UL]) + X[88UL] * X[91UL];
  t266 = (X[82UL] * X[92UL] + X[85UL] * X[93UL]) + X[88UL] * X[94UL];
  t269 = (X[82UL] * X[95UL] + X[85UL] * X[96UL]) + X[88UL] * X[97UL];
  t65[0UL] = (t192 * X[98UL] + t278 * X[99UL]) + t267 * X[100UL];
  t65[3UL] = t192 * X[101UL];
  t65[3UL] += t278 * X[102UL];
  t65[3UL] += t267 * X[103UL];
  t65[6UL] = t192 * X[104UL];
  t65[6UL] += t278 * X[105UL];
  t65[6UL] += t267 * X[106UL];
  t65[1UL] = t213 * X[98UL];
  t65[1UL] += t285 * X[99UL];
  t65[1UL] += t268 * X[100UL];
  t65[4UL] = t213 * X[101UL];
  t65[4UL] += t285 * X[102UL];
  t65[4UL] += t268 * X[103UL];
  t65[7UL] = t213 * X[104UL];
  t65[7UL] += t285 * X[105UL];
  t65[7UL] += t268 * X[106UL];
  t65[2UL] = t313 * X[98UL];
  t65[2UL] += t266 * X[99UL];
  t65[2UL] += t269 * X[100UL];
  t65[5UL] = t313 * X[101UL];
  t65[5UL] += t266 * X[102UL];
  t65[5UL] += t269 * X[103UL];
  t65[8UL] = t313 * X[104UL];
  t65[8UL] += t266 * X[105UL];
  t65[8UL] += t269 * X[106UL];
  t1[0UL] = 0.0;
  t1[1UL] = 0.0;
  t1[2UL] = 0.0;
  t1[3UL] = 0.0;
  t1[4UL] = 0.0;
  t1[5UL] = 0.0;
  t1[6UL] = t294;
  t1[7UL] = t290;
  t1[8UL] = t316;
  t1[9UL] = 0.0;
  t1[10UL] = 0.0;
  t1[11UL] = 0.0;
  for (t129 = 0UL; t129 < 4UL; t129++) {
    t294 = -pmf_sqrt(((real_T)(M[t129] != 0) * 2.0 - 1.0) * U[t129] / 1.0E-9);
    t1[t129 + 12UL] = t294 / (t13[t129] == 0.0 ? 1.0E-16 : t13[t129]);
  }

  for (t129 = 37UL; t129 - 37UL < 4UL; t129++) {
    t1[t129 + 18446744073709551595UL] = -(X[t129] * X[t129] * 2.75E-11) /
      (t13[t129 - 37UL] == 0.0 ? 1.0E-16 : t13[t129 - 37UL]);
  }

  for (t129 = 0UL; t129 < 9UL; t129++) {
    t1[t129 + 20UL] = -t18[t129] / (t19[t129] == 0.0 ? 1.0E-16 : t19[t129]) +
      t20[t129];
  }

  for (t129 = 0UL; t129 < 9UL; t129++) {
    t1[t129 + 29UL] = -t24[t129] / (t19[t129] == 0.0 ? 1.0E-16 : t19[t129]) +
      t26[t129];
  }

  for (t129 = 0UL; t129 < 9UL; t129++) {
    t1[t129 + 38UL] = -t30[t129] / (t19[t129] == 0.0 ? 1.0E-16 : t19[t129]) +
      t32[t129];
  }

  for (t129 = 0UL; t129 < 9UL; t129++) {
    t1[t129 + 47UL] = -t34[t129] / (t19[t129] == 0.0 ? 1.0E-16 : t19[t129]);
  }

  t1[56UL] = -((X[12UL] * X[9UL] + X[15UL] * X[10UL]) + X[18UL] * X[11UL]);
  t1[57UL] = -((X[13UL] * X[9UL] + X[16UL] * X[10UL]) + X[19UL] * X[11UL]);
  t1[58UL] = -((X[14UL] * X[9UL] + X[17UL] * X[10UL]) + X[20UL] * X[11UL]);
  for (t129 = 0UL; t129 < 9UL; t129++) {
    t1[t129 + 59UL] = -t41[t129] / (t19[t129] == 0.0 ? 1.0E-16 : t19[t129]) +
      t20[t129];
  }

  t1[68UL] = -((X[21UL] * X[34UL] + X[24UL] * X[35UL]) + X[27UL] * X[36UL]);
  t1[69UL] = -((X[22UL] * X[34UL] + X[25UL] * X[35UL]) + X[28UL] * X[36UL]);
  t1[70UL] = -((X[23UL] * X[34UL] + X[26UL] * X[35UL]) + X[29UL] * X[36UL]);
  for (t129 = 0UL; t129 < 9UL; t129++) {
    t1[t129 + 71UL] = -t49[t129] / (t19[t129] == 0.0 ? 1.0E-16 : t19[t129]) +
      t20[t129];
  }

  for (t129 = 0UL; t129 < 9UL; t129++) {
    t1[t129 + 80UL] = -t55[t129] / (t19[t129] == 0.0 ? 1.0E-16 : t19[t129]) +
      t26[t129];
  }

  for (t129 = 0UL; t129 < 9UL; t129++) {
    t1[t129 + 89UL] = -t61[t129] / (t19[t129] == 0.0 ? 1.0E-16 : t19[t129]) +
      t32[t129];
  }

  for (t129 = 0UL; t129 < 9UL; t129++) {
    t1[t129 + 98UL] = -t65[t129] / (t19[t129] == 0.0 ? 1.0E-16 : t19[t129]);
  }

  t1[107UL] = -0.0 + ((X[71UL] * X[107UL] + X[74UL] * X[108UL]) + X[77UL] * X
                      [109UL]) / 0.1019367991845056;
  t1[108UL] = -0.0 + ((X[72UL] * X[107UL] + X[75UL] * X[108UL]) + X[78UL] * X
                      [109UL]) / 0.1019367991845056;
  t1[109UL] = -9.81 + ((X[73UL] * X[107UL] + X[76UL] * X[108UL]) + X[79UL] * X
                       [109UL]) / 0.1019367991845056;
  for (b = 0; b < 110; b++) {
    out.mX[b] = t1[b];
  }

  (void)t0;
  (void)t321;
  return 0;
}
