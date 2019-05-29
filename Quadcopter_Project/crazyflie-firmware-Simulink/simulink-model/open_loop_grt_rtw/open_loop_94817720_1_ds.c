/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'open_loop/Solver Configuration'.
 */
/* open_loop_94817720_1_ds.c - body for module open_loop_94817720_1_ds */

#include "ne_ds.h"
#include "open_loop_94817720_1_ds_tdxy_p.h"
#include "open_loop_94817720_1_ds_dxy_p.h"
#include "open_loop_94817720_1_ds_obs_all.h"
#include "open_loop_94817720_1_ds_obs_act.h"
#include "open_loop_94817720_1_ds_obs_exp.h"
#include "open_loop_94817720_1_ds_vmm.h"
#include "open_loop_94817720_1_ds_m_p.h"
#include "open_loop_94817720_1_ds_log.h"
#include "open_loop_94817720_1_ds_tdxf_p.h"
#include "open_loop_94817720_1_ds_m.h"
#include "open_loop_94817720_1_ds_a_p.h"
#include "open_loop_94817720_1_ds_obs_il.h"
#include "open_loop_94817720_1_ds_dxy.h"
#include "open_loop_94817720_1_ds_a.h"
#include "open_loop_94817720_1_ds_duf.h"
#include "open_loop_94817720_1_ds_dxf_p.h"
#include "open_loop_94817720_1_ds_vmf.h"
#include "open_loop_94817720_1_ds_dxf.h"
#include "open_loop_94817720_1_ds_f.h"
#include "open_loop_94817720_1_ds.h"
#include "ssc_ml_fun.h"
#include "open_loop_94817720_1_ds_external_struct.h"
#include "open_loop_94817720_1_ds_sys_struct.h"
#include "open_loop_94817720_1_ds_externals.h"

static int32_T ds_dxm_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dxm(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dum_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dum(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dtm_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dtm(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_b_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_b(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                    NeDsMethodOutput *out);
static int32_T ds_c_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_c(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                    NeDsMethodOutput *out);
static int32_T ds_slf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_slf0(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_duf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dtf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dtf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_ddf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_ddf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_tduf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dnf_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dnf(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dnf_v_x(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_ic(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                     NeDsMethodOutput *out);
static int32_T ds_icr(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_icr_im(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_icr_id(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_icr_il(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dxicr(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dxicr_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_tduicr_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_mduy_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_mdxy_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_tduy_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_y(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                    NeDsMethodOutput *out);
static int32_T ds_duy_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_duy(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_dty_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dty(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_mode(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_zc(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                     NeDsMethodOutput *out);
static int32_T ds_cache_r(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_cache_i(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_update_r(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_update_i(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_sfo(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_sfp(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static int32_T ds_init_r(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_init_i(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_assert(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_passert(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_iassert(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_del_t(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_del_v(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_del_v0(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_del_tmax(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dxdelt_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dxdelt(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dudelt_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dudelt(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dtdelt_p(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dtdelt(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_dp_l(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_dp_i(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_dp_j(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_dp_r(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_qx(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                     NeDsMethodOutput *out);
static int32_T ds_qu(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                     NeDsMethodOutput *out);
static int32_T ds_qt(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                     NeDsMethodOutput *out);
static int32_T ds_q1(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                     NeDsMethodOutput *out);
static int32_T ds_qx_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_qu_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_qt_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_q1_p(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
  NeDsMethodOutput *out);
static int32_T ds_var_tol(const NeDynamicSystem *ds, const NeDynamicSystemInput *
  in, NeDsMethodOutput *out);
static int32_T ds_eq_tol(const NeDynamicSystem *ds, const NeDynamicSystemInput
  *in, NeDsMethodOutput *out);
static int32_T ds_lv(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                     NeDsMethodOutput *out);
static int32_T ds_slv(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                      NeDsMethodOutput *out);
static NeDsMethodOutput *ds_output_m_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_m(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_vmm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dxm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dxm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dum_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dum(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dtm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dtm(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_a_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_a(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_b_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_b(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_c_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_c(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_f(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_vmf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_slf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_slf0(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dxf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dxf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_duf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_duf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dtf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dtf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_ddf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_ddf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_tduf_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_tdxf_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dnf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dnf(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dnf_v_x(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_ic(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_icr(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_icr_im(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_icr_id(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_icr_il(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dxicr(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dxicr_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_tduicr_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_mduy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_mdxy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_tduy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_tdxy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_y(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dxy_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dxy(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_duy_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_duy(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dty_p(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_dty(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_mode(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_zc(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_cache_r(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_cache_i(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_update_r(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_update_i(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_sfo(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_sfp(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_init_r(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_init_i(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_log(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_assert(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_passert(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_iassert(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_del_t(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_del_v(const NeDynamicSystem *ds, PmAllocator *
  allocator);
static NeDsMethodOutput *ds_output_del_v0(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_del_tmax(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dxdelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dxdelt(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dudelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dudelt(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dtdelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_dtdelt(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_obs_exp(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_obs_act(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_obs_all(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_obs_il(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dp_l(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dp_i(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dp_j(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_dp_r(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qx(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qu(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qt(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_q1(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qx_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qu_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_qt_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_q1_p(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_var_tol(const NeDynamicSystem *ds,
  PmAllocator *allocator);
static NeDsMethodOutput *ds_output_eq_tol(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_lv(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static NeDsMethodOutput *ds_output_slv(const NeDynamicSystem *ds, PmAllocator
  *allocator);
static void release_reference(NeDynamicSystem *ds);
static void get_reference(NeDynamicSystem *ds);
static NeDynamicSystem *diagnostics(const NeDynamicSystem *ds);
static void expand(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                   PmRealVector *out);
static NeEquationData s_equation_data[110] = { { "", 0U, 8,
    NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 2U, 0U, TRUE,
    1.0, "1", }, { "", 1U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 2U, 0U, TRUE, 1.0, "1", }, { "", 2U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 2U, 0U,
    TRUE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 2U, 2U, TRUE, 1.0, "1", }, { "", 1U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 2U, 2U,
    TRUE, 1.0, "1", }, { "", 2U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 2U, 2U, TRUE, 1.0, "1", }, { "", 0U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 4U,
    FALSE, 1.0, "1", }, { "", 1U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 4U, FALSE, 1.0, "1", }, { "", 2U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 4U,
    FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 2U, 5U, TRUE, 1.0, "1", }, { "", 1U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 2U, 5U,
    TRUE, 1.0, "1", }, { "", 2U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 2U, 5U, TRUE, 1.0, "1", }, { "", 0U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 7U,
    FALSE, 1.0, "1", }, { "", 1U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 7U, FALSE, 1.0, "1", }, { "", 2U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 7U,
    FALSE, 1.0, "1", }, { "", 3U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 7U, FALSE, 1.0, "1", }, { "", 0U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 8U,
    FALSE, 1.0, "1", }, { "", 1U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 8U, FALSE, 1.0, "1", }, { "", 2U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 8U,
    FALSE, 1.0, "1", }, { "", 3U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 8U, FALSE, 1.0, "1", }, { "", 0U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 9U,
    FALSE, 1.0, "1", }, { "", 1U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 9U, FALSE, 1.0, "1", }, { "", 2U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 9U,
    FALSE, 1.0, "1", }, { "", 3U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 9U, FALSE, 1.0, "1", }, { "", 4U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 9U,
    FALSE, 1.0, "1", }, { "", 5U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 9U, FALSE, 1.0, "1", }, { "", 6U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 9U,
    FALSE, 1.0, "1", }, { "", 7U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 9U, FALSE, 1.0, "1", }, { "", 8U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 9U,
    FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 10U, FALSE, 1.0, "1", }, { "", 1U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 10U,
    FALSE, 1.0, "1", }, { "", 2U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 10U, FALSE, 1.0, "1", }, { "", 3U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 10U,
    FALSE, 1.0, "1", }, { "", 4U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 10U, FALSE, 1.0, "1", }, { "", 5U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 10U,
    FALSE, 1.0, "1", }, { "", 6U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 10U, FALSE, 1.0, "1", }, { "", 7U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 10U,
    FALSE, 1.0, "1", }, { "", 8U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 10U, FALSE, 1.0, "1", }, { "", 0U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 11U,
    FALSE, 1.0, "1", }, { "", 1U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 11U, FALSE, 1.0, "1", }, { "", 2U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 11U,
    FALSE, 1.0, "1", }, { "", 3U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 11U, FALSE, 1.0, "1", }, { "", 4U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 11U,
    FALSE, 1.0, "1", }, { "", 5U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 11U, FALSE, 1.0, "1", }, { "", 6U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 11U,
    FALSE, 1.0, "1", }, { "", 7U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 11U, FALSE, 1.0, "1", }, { "", 8U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 11U,
    FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 12U, FALSE, 1.0, "1", }, { "", 1U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 12U,
    FALSE, 1.0, "1", }, { "", 2U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 12U, FALSE, 1.0, "1", }, { "", 3U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 12U,
    FALSE, 1.0, "1", }, { "", 4U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 12U, FALSE, 1.0, "1", }, { "", 5U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 12U,
    FALSE, 1.0, "1", }, { "", 6U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 12U, FALSE, 1.0, "1", }, { "", 7U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 12U,
    FALSE, 1.0, "1", }, { "", 8U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 12U, FALSE, 1.0, "1", }, { "", 0U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 13U,
    FALSE, 1.0, "1", }, { "", 1U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 13U, FALSE, 1.0, "1", }, { "", 2U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 13U,
    FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 14U, FALSE, 1.0, "1", }, { "", 1U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 14U,
    FALSE, 1.0, "1", }, { "", 2U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 14U, FALSE, 1.0, "1", }, { "", 3U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 14U,
    FALSE, 1.0, "1", }, { "", 4U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 14U, FALSE, 1.0, "1", }, { "", 5U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 14U,
    FALSE, 1.0, "1", }, { "", 6U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 14U, FALSE, 1.0, "1", }, { "", 7U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 14U,
    FALSE, 1.0, "1", }, { "", 8U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 14U, FALSE, 1.0, "1", }, { "", 0U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 15U,
    FALSE, 1.0, "1", }, { "", 1U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter", 1U, 15U, FALSE, 1.0, "1", }, { "", 2U,
    8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter", 1U, 15U,
    FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter1", 1U, 16U, FALSE, 1.0, "1", }, { "",
    1U, 8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter1", 1U,
    16U, FALSE, 1.0, "1", }, { "", 2U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter1", 1U, 16U, FALSE, 1.0, "1", }, { "",
    3U, 8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter1", 1U,
    16U, FALSE, 1.0, "1", }, { "", 4U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter1", 1U, 16U, FALSE, 1.0, "1", }, { "",
    5U, 8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter1", 1U,
    16U, FALSE, 1.0, "1", }, { "", 6U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter1", 1U, 16U, FALSE, 1.0, "1", }, { "",
    7U, 8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter1", 1U,
    16U, FALSE, 1.0, "1", }, { "", 8U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter1", 1U, 16U, FALSE, 1.0, "1", }, { "",
    0U, 8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter1", 1U,
    17U, FALSE, 1.0, "1", }, { "", 1U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter1", 1U, 17U, FALSE, 1.0, "1", }, { "",
    2U, 8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter1", 1U,
    17U, FALSE, 1.0, "1", }, { "", 3U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter1", 1U, 17U, FALSE, 1.0, "1", }, { "",
    4U, 8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter1", 1U,
    17U, FALSE, 1.0, "1", }, { "", 5U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter1", 1U, 17U, FALSE, 1.0, "1", }, { "",
    6U, 8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter1", 1U,
    17U, FALSE, 1.0, "1", }, { "", 7U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter1", 1U, 17U, FALSE, 1.0, "1", }, { "",
    8U, 8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter1", 1U,
    17U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter1", 1U, 18U, FALSE, 1.0, "1", }, { "",
    1U, 8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter1", 1U,
    18U, FALSE, 1.0, "1", }, { "", 2U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter1", 1U, 18U, FALSE, 1.0, "1", }, { "",
    3U, 8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter1", 1U,
    18U, FALSE, 1.0, "1", }, { "", 4U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter1", 1U, 18U, FALSE, 1.0, "1", }, { "",
    5U, 8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter1", 1U,
    18U, FALSE, 1.0, "1", }, { "", 6U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter1", 1U, 18U, FALSE, 1.0, "1", }, { "",
    7U, 8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter1", 1U,
    18U, FALSE, 1.0, "1", }, { "", 8U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter1", 1U, 18U, FALSE, 1.0, "1", }, { "",
    0U, 8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter1", 1U,
    19U, FALSE, 1.0, "1", }, { "", 1U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter1", 1U, 19U, FALSE, 1.0, "1", }, { "",
    2U, 8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter1", 1U,
    19U, FALSE, 1.0, "1", }, { "", 3U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter1", 1U, 19U, FALSE, 1.0, "1", }, { "",
    4U, 8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter1", 1U,
    19U, FALSE, 1.0, "1", }, { "", 5U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter1", 1U, 19U, FALSE, 1.0, "1", }, { "",
    6U, 8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter1", 1U,
    19U, FALSE, 1.0, "1", }, { "", 7U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter1", 1U, 19U, FALSE, 1.0, "1", }, { "",
    8U, 8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter1", 1U,
    19U, FALSE, 1.0, "1", }, { "", 0U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter1", 1U, 20U, FALSE, 1.0, "1", }, { "",
    1U, 8, NE_EQUATION_DOMAIN_TIME, "open_loop/Plant of the quadrocopter1", 1U,
    20U, FALSE, 1.0, "1", }, { "", 2U, 8, NE_EQUATION_DOMAIN_TIME,
    "open_loop/Plant of the quadrocopter1", 1U, 20U, FALSE, 1.0, "1", } };

static NeVariableData s_variable_data[110] = { {
    "Plant_of_the_quadrocopter.angle", 0U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, TRUE, 3U, 1U,
    NE_INIT_MODE_NONE, "Angle", }, { "Plant_of_the_quadrocopter.angle", 1U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, TRUE, 3U, 1U,
    NE_INIT_MODE_NONE, "Angle", }, { "Plant_of_the_quadrocopter.angle", 2U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, TRUE, 3U, 1U,
    NE_INIT_MODE_NONE, "Angle", }, { "Plant_of_the_quadrocopter.pos", 0U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, TRUE, 3U, 1U,
    NE_INIT_MODE_NONE, "Position", }, { "Plant_of_the_quadrocopter.pos", 1U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, TRUE, 3U, 1U,
    NE_INIT_MODE_NONE, "Position", }, { "Plant_of_the_quadrocopter.pos", 2U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, TRUE, 3U, 1U,
    NE_INIT_MODE_NONE, "Position", }, { "Plant_of_the_quadrocopter.v", 0U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, TRUE, 3U, 1U,
    NE_INIT_MODE_NONE, "Velocity", }, { "Plant_of_the_quadrocopter.v", 1U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, TRUE, 3U, 1U,
    NE_INIT_MODE_NONE, "Velocity", }, { "Plant_of_the_quadrocopter.v", 2U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, TRUE, 3U, 1U,
    NE_INIT_MODE_NONE, "Velocity", }, { "Plant_of_the_quadrocopter.w_b", 0U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, TRUE, 3U, 1U,
    NE_INIT_MODE_NONE, "w_b", }, { "Plant_of_the_quadrocopter.w_b", 1U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, TRUE, 3U, 1U,
    NE_INIT_MODE_NONE, "w_b", }, { "Plant_of_the_quadrocopter.w_b", 2U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, TRUE, 3U, 1U,
    NE_INIT_MODE_NONE, "w_b", }, { "Plant_of_the_quadrocopter.R_b2w", 0U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "R_b2w", }, { "Plant_of_the_quadrocopter.R_b2w", 1U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "R_b2w", }, { "Plant_of_the_quadrocopter.R_b2w", 2U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "R_b2w", }, { "Plant_of_the_quadrocopter.R_b2w", 3U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "R_b2w", }, { "Plant_of_the_quadrocopter.R_b2w", 4U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "R_b2w", }, { "Plant_of_the_quadrocopter.R_b2w", 5U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "R_b2w", }, { "Plant_of_the_quadrocopter.R_b2w", 6U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "R_b2w", }, { "Plant_of_the_quadrocopter.R_b2w", 7U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "R_b2w", }, { "Plant_of_the_quadrocopter.R_b2w", 8U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "R_b2w", }, { "Plant_of_the_quadrocopter.T_angleder2w",
    0U, 0, "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "T_angleder2w", }, {
    "Plant_of_the_quadrocopter.T_angleder2w", 1U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "T_angleder2w", }, {
    "Plant_of_the_quadrocopter.T_angleder2w", 2U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "T_angleder2w", }, {
    "Plant_of_the_quadrocopter.T_angleder2w", 3U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "T_angleder2w", }, {
    "Plant_of_the_quadrocopter.T_angleder2w", 4U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "T_angleder2w", }, {
    "Plant_of_the_quadrocopter.T_angleder2w", 5U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "T_angleder2w", }, {
    "Plant_of_the_quadrocopter.T_angleder2w", 6U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "T_angleder2w", }, {
    "Plant_of_the_quadrocopter.T_angleder2w", 7U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "T_angleder2w", }, {
    "Plant_of_the_quadrocopter.T_angleder2w", 8U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "T_angleder2w", }, {
    "Plant_of_the_quadrocopter.Tz_aer_drag", 0U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 4U, 1U,
    NE_INIT_MODE_NONE, "Tz_aer_drag", }, {
    "Plant_of_the_quadrocopter.Tz_aer_drag", 1U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 4U, 1U,
    NE_INIT_MODE_NONE, "Tz_aer_drag", }, {
    "Plant_of_the_quadrocopter.Tz_aer_drag", 2U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 4U, 1U,
    NE_INIT_MODE_NONE, "Tz_aer_drag", }, {
    "Plant_of_the_quadrocopter.Tz_aer_drag", 3U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 4U, 1U,
    NE_INIT_MODE_NONE, "Tz_aer_drag", }, { "Plant_of_the_quadrocopter.dangle",
    0U, 0, "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 1U,
    NE_INIT_MODE_NONE, "Angular velocity", }, {
    "Plant_of_the_quadrocopter.dangle", 1U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 1U,
    NE_INIT_MODE_NONE, "Angular velocity", }, {
    "Plant_of_the_quadrocopter.dangle", 2U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 1U,
    NE_INIT_MODE_NONE, "Angular velocity", }, {
    "Plant_of_the_quadrocopter.rotorspeed", 0U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 4U, 1U,
    NE_INIT_MODE_NONE, "rotorspeed", }, { "Plant_of_the_quadrocopter.rotorspeed",
    1U, 0, "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 4U, 1U,
    NE_INIT_MODE_NONE, "rotorspeed", }, { "Plant_of_the_quadrocopter.rotorspeed",
    2U, 0, "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 4U, 1U,
    NE_INIT_MODE_NONE, "rotorspeed", }, { "Plant_of_the_quadrocopter.rotorspeed",
    3U, 0, "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 4U, 1U,
    NE_INIT_MODE_NONE, "rotorspeed", }, { "Plant_of_the_quadrocopter.rotx", 0U,
    0, "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "rotx", }, { "Plant_of_the_quadrocopter.rotx", 1U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "rotx", }, { "Plant_of_the_quadrocopter.rotx", 2U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "rotx", }, { "Plant_of_the_quadrocopter.rotx", 3U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "rotx", }, { "Plant_of_the_quadrocopter.rotx", 4U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "rotx", }, { "Plant_of_the_quadrocopter.rotx", 5U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "rotx", }, { "Plant_of_the_quadrocopter.rotx", 6U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "rotx", }, { "Plant_of_the_quadrocopter.rotx", 7U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "rotx", }, { "Plant_of_the_quadrocopter.rotx", 8U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "rotx", }, { "Plant_of_the_quadrocopter.roty", 0U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "roty", }, { "Plant_of_the_quadrocopter.roty", 1U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "roty", }, { "Plant_of_the_quadrocopter.roty", 2U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "roty", }, { "Plant_of_the_quadrocopter.roty", 3U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "roty", }, { "Plant_of_the_quadrocopter.roty", 4U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "roty", }, { "Plant_of_the_quadrocopter.roty", 5U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "roty", }, { "Plant_of_the_quadrocopter.roty", 6U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "roty", }, { "Plant_of_the_quadrocopter.roty", 7U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "roty", }, { "Plant_of_the_quadrocopter.roty", 8U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "roty", }, { "Plant_of_the_quadrocopter.rotz", 0U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "rotz", }, { "Plant_of_the_quadrocopter.rotz", 1U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "rotz", }, { "Plant_of_the_quadrocopter.rotz", 2U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "rotz", }, { "Plant_of_the_quadrocopter.rotz", 3U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "rotz", }, { "Plant_of_the_quadrocopter.rotz", 4U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "rotz", }, { "Plant_of_the_quadrocopter.rotz", 5U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "rotz", }, { "Plant_of_the_quadrocopter.rotz", 6U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "rotz", }, { "Plant_of_the_quadrocopter.rotz", 7U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "rotz", }, { "Plant_of_the_quadrocopter.rotz", 8U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "rotz", }, { "Plant_of_the_quadrocopter.w", 0U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 1U,
    NE_INIT_MODE_NONE, "w", }, { "Plant_of_the_quadrocopter.w", 1U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 1U,
    NE_INIT_MODE_NONE, "w", }, { "Plant_of_the_quadrocopter.w", 2U, 0,
    "open_loop/Plant of the quadrocopter", 1.0, "1", 0.0, FALSE, 3U, 1U,
    NE_INIT_MODE_NONE, "w", }, { "Plant_of_the_quadrocopter1.R", 0U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "R", }, { "Plant_of_the_quadrocopter1.R", 1U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "R", }, { "Plant_of_the_quadrocopter1.R", 2U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "R", }, { "Plant_of_the_quadrocopter1.R", 3U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "R", }, { "Plant_of_the_quadrocopter1.R", 4U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "R", }, { "Plant_of_the_quadrocopter1.R", 5U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "R", }, { "Plant_of_the_quadrocopter1.R", 6U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "R", }, { "Plant_of_the_quadrocopter1.R", 7U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "R", }, { "Plant_of_the_quadrocopter1.R", 8U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "R", }, { "Plant_of_the_quadrocopter1.Rx", 0U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Rx", }, { "Plant_of_the_quadrocopter1.Rx", 1U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Rx", }, { "Plant_of_the_quadrocopter1.Rx", 2U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Rx", }, { "Plant_of_the_quadrocopter1.Rx", 3U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Rx", }, { "Plant_of_the_quadrocopter1.Rx", 4U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Rx", }, { "Plant_of_the_quadrocopter1.Rx", 5U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Rx", }, { "Plant_of_the_quadrocopter1.Rx", 6U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Rx", }, { "Plant_of_the_quadrocopter1.Rx", 7U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Rx", }, { "Plant_of_the_quadrocopter1.Rx", 8U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Rx", }, { "Plant_of_the_quadrocopter1.Ry", 0U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Ry", }, { "Plant_of_the_quadrocopter1.Ry", 1U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Ry", }, { "Plant_of_the_quadrocopter1.Ry", 2U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Ry", }, { "Plant_of_the_quadrocopter1.Ry", 3U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Ry", }, { "Plant_of_the_quadrocopter1.Ry", 4U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Ry", }, { "Plant_of_the_quadrocopter1.Ry", 5U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Ry", }, { "Plant_of_the_quadrocopter1.Ry", 6U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Ry", }, { "Plant_of_the_quadrocopter1.Ry", 7U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Ry", }, { "Plant_of_the_quadrocopter1.Ry", 8U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Ry", }, { "Plant_of_the_quadrocopter1.Rz", 0U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Rz", }, { "Plant_of_the_quadrocopter1.Rz", 1U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Rz", }, { "Plant_of_the_quadrocopter1.Rz", 2U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Rz", }, { "Plant_of_the_quadrocopter1.Rz", 3U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Rz", }, { "Plant_of_the_quadrocopter1.Rz", 4U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Rz", }, { "Plant_of_the_quadrocopter1.Rz", 5U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Rz", }, { "Plant_of_the_quadrocopter1.Rz", 6U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Rz", }, { "Plant_of_the_quadrocopter1.Rz", 7U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Rz", }, { "Plant_of_the_quadrocopter1.Rz", 8U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 3U,
    NE_INIT_MODE_NONE, "Rz", }, { "Plant_of_the_quadrocopter1.acc", 0U, 0,
    "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 1U,
    NE_INIT_MODE_NONE, "Accelerometer", }, { "Plant_of_the_quadrocopter1.acc",
    1U, 0, "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 1U,
    NE_INIT_MODE_NONE, "Accelerometer", }, { "Plant_of_the_quadrocopter1.acc",
    2U, 0, "open_loop/Plant of the quadrocopter1", 1.0, "1", 0.0, FALSE, 3U, 1U,
    NE_INIT_MODE_NONE, "Accelerometer", } };

static NeVariableData *s_discrete_data = NULL;
static NeObservableData s_observable_data[33] = { {
    "Plant_of_the_quadrocopter.R_b2w", "open_loop/Plant of the quadrocopter", 3U,
    3U, "1", 1.0e-6, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "R_b2w", }, {
    "Plant_of_the_quadrocopter.T_angleder2w",
    "open_loop/Plant of the quadrocopter", 3U, 3U, "1", 1.0e-6, "1",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "T_angleder2w", }, {
    "Plant_of_the_quadrocopter.T_b", "open_loop/Plant of the quadrocopter", 3U,
    1U, "N*m", 1.0e-6, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "T_b", }, {
    "Plant_of_the_quadrocopter.Tx", "open_loop/Plant of the quadrocopter", 1U,
    1U, "N*m", 1.0e-6, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Tx", }, {
    "Plant_of_the_quadrocopter.Ty", "open_loop/Plant of the quadrocopter", 1U,
    1U, "N*m", 1.0e-6, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Ty", }, {
    "Plant_of_the_quadrocopter.Tz", "open_loop/Plant of the quadrocopter", 1U,
    1U, "N*m", 1.0e-6, "J", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Tz", }, {
    "Plant_of_the_quadrocopter.Tz_aer_drag",
    "open_loop/Plant of the quadrocopter", 4U, 1U, "N*m", 1.0e-6, "J",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Tz_aer_drag", }, {
    "Plant_of_the_quadrocopter.a", "open_loop/Plant of the quadrocopter", 3U, 1U,
    "m/s^2", 1.0e-6, "m/s^2", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, TRUE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Acceleration", }, {
    "Plant_of_the_quadrocopter.angle", "open_loop/Plant of the quadrocopter", 3U,
    1U, "rad", 1.0e-6, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    TRUE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Angle", }, {
    "Plant_of_the_quadrocopter.ctrl", "open_loop/Plant of the quadrocopter", 4U,
    1U, "N", 1.0e-6, "N", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Thrust", }, {
    "Plant_of_the_quadrocopter.dangle", "open_loop/Plant of the quadrocopter",
    3U, 1U, "rad/s", 1.0e-6, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Angular velocity", }, {
    "Plant_of_the_quadrocopter.phi", "open_loop/Plant of the quadrocopter", 1U,
    1U, "rad", 1.0e-6, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "phi", }, {
    "Plant_of_the_quadrocopter.pos", "open_loop/Plant of the quadrocopter", 3U,
    1U, "m", 1.0e-6, "m", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, TRUE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Position", }, {
    "Plant_of_the_quadrocopter.psi", "open_loop/Plant of the quadrocopter", 1U,
    1U, "rad", 1.0e-6, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "psi", }, {
    "Plant_of_the_quadrocopter.rotorspeed",
    "open_loop/Plant of the quadrocopter", 4U, 1U, "rad/s", 1.0e-6, "1/s",
    NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, FALSE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "rotorspeed", }, {
    "Plant_of_the_quadrocopter.rotx", "open_loop/Plant of the quadrocopter", 3U,
    3U, "1", 1.0e-6, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "rotx", }, {
    "Plant_of_the_quadrocopter.roty", "open_loop/Plant of the quadrocopter", 3U,
    3U, "1", 1.0e-6, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "roty", }, {
    "Plant_of_the_quadrocopter.rotz", "open_loop/Plant of the quadrocopter", 3U,
    3U, "1", 1.0e-6, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "rotz", }, {
    "Plant_of_the_quadrocopter.theta", "open_loop/Plant of the quadrocopter", 1U,
    1U, "rad", 1.0e-6, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "theta", }, {
    "Plant_of_the_quadrocopter.v", "open_loop/Plant of the quadrocopter", 3U, 1U,
    "m/s", 1.0e-6, "m/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE, TRUE,
    NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Velocity", }, {
    "Plant_of_the_quadrocopter.w", "open_loop/Plant of the quadrocopter", 3U, 1U,
    "rad/s", 1.0e-6, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "w", }, {
    "Plant_of_the_quadrocopter.w_b", "open_loop/Plant of the quadrocopter", 3U,
    1U, "rad/s", 1.0e-6, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    TRUE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "w_b", }, {
    "Plant_of_the_quadrocopter1.R", "open_loop/Plant of the quadrocopter1", 3U,
    3U, "1", 1.0e-6, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "R", }, {
    "Plant_of_the_quadrocopter1.Rx", "open_loop/Plant of the quadrocopter1", 3U,
    3U, "1", 1.0e-6, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rx", }, {
    "Plant_of_the_quadrocopter1.Ry", "open_loop/Plant of the quadrocopter1", 3U,
    3U, "1", 1.0e-6, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Ry", }, {
    "Plant_of_the_quadrocopter1.Rz", "open_loop/Plant of the quadrocopter1", 3U,
    3U, "1", 1.0e-6, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Rz", }, {
    "Plant_of_the_quadrocopter1.a", "open_loop/Plant of the quadrocopter1", 3U,
    1U, "m/s^2", 1.0e-6, "m/s^2", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    TRUE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Acceleration", }, {
    "Plant_of_the_quadrocopter1.acc", "open_loop/Plant of the quadrocopter1", 3U,
    1U, "1", 1.0e-6, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Accelerometer", }, {
    "Plant_of_the_quadrocopter1.angle", "open_loop/Plant of the quadrocopter1",
    3U, 1U, "rad", 1.0e-6, "1", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Angle", }, {
    "Plant_of_the_quadrocopter1.gyro", "open_loop/Plant of the quadrocopter1",
    3U, 1U, "deg/s", 1.0e-6, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE,
    FALSE, FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Gyroscope", }, {
    "Plant_of_the_quadrocopter1.pos", "open_loop/Plant of the quadrocopter1", 3U,
    1U, "m", 1.0e-6, "m", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Position", }, {
    "Plant_of_the_quadrocopter1.v", "open_loop/Plant of the quadrocopter1", 3U,
    1U, "m/s", 1.0e-6, "m/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Velocity", }, {
    "Plant_of_the_quadrocopter1.w", "open_loop/Plant of the quadrocopter1", 3U,
    1U, "rad/s", 1.0e-6, "1/s", NE_NOMINAL_SOURCE_NONE, NE_INIT_MODE_NONE, FALSE,
    FALSE, NE_FREQTIME_TYPE_TIME, TRUE, TRUE, "Angular velocity", } };

static NeModeData *s_major_mode_data = NULL;
static NeZCData s_zc_data[5] = { { "open_loop/Plant of the quadrocopter", 1U, 0U,
    "Plant_of_the_quadrocopter",
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    NE_ZC_TYPE_TRUE, }, { "open_loop/Plant of the quadrocopter", 1U, 0U,
    "Plant_of_the_quadrocopter",
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    NE_ZC_TYPE_TRUE, }, { "open_loop/Plant of the quadrocopter", 1U, 0U,
    "Plant_of_the_quadrocopter",
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    NE_ZC_TYPE_TRUE, }, { "open_loop/Plant of the quadrocopter", 1U, 0U,
    "Plant_of_the_quadrocopter",
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    NE_ZC_TYPE_TRUE, }, { "open_loop/Plant of the quadrocopter", 1U, 1U,
    "Plant_of_the_quadrocopter",
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    NE_ZC_TYPE_FALSE, } };

static NeRange s_range[2] = { {
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    71U, 24U, 71U, 32U, NE_RANGE_TYPE_NORMAL, }, {
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    71U, 24U, 71U, 35U, NE_RANGE_TYPE_NORMAL, } };

static NeAssertData s_assert_data[3] = { { "open_loop/Plant of the quadrocopter",
    1U, 0U, "Plant_of_the_quadrocopter",
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    FALSE, "Argument of sqrt must be nonnegative.",
    "physmod:common:mf:core:asserts:RequireArgumentNonnegative", }, {
    "open_loop/Plant of the quadrocopter", 1U, 1U, "Plant_of_the_quadrocopter",
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    TRUE,
    "In power, the exponent should be positive when the base is equal to zero. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireExponentPositive", }, {
    "open_loop/Plant of the quadrocopter", 1U, 2U, "Plant_of_the_quadrocopter",
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    TRUE,
    "In power, the base should be nonnegative when the exponent is not an integer. This may become error in future releases.",
    "physmod:common:mf:core:asserts:RequireBaseNonnegative", } };

static NeRange s_assert_range[3] = { {
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    71U, 24U, 71U, 35U, NE_RANGE_TYPE_NORMAL, }, {
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    74U, 38U, 74U, 39U, NE_RANGE_TYPE_NORMAL, }, {
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    74U, 25U, 74U, 35U, NE_RANGE_TYPE_NORMAL, } };

static NeAssertData *s_param_assert_data = NULL;
static NeRange *s_param_assert_range = NULL;
static NeAssertData *s_initial_assert_data = NULL;
static NeRange *s_initial_assert_range = NULL;
static NeRange s_equation_range[21] = { {
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    66U, 5U, 66U, 10U, NE_RANGE_TYPE_NORMAL, }, {
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    66U, 7U, 66U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    67U, 5U, 67U, 12U, NE_RANGE_TYPE_NORMAL, }, {
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    67U, 9U, 67U, 17U, NE_RANGE_TYPE_NORMAL, }, {
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    83U, 5U, 83U, 52U, NE_RANGE_TYPE_NORMAL, }, {
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    110U, 5U, 110U, 20U, NE_RANGE_TYPE_NORMAL, }, {
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    110U, 15U, 110U, 24U, NE_RANGE_TYPE_NORMAL, }, {
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    71U, 5U, 71U, 35U, NE_RANGE_TYPE_NORMAL, }, {
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    74U, 5U, 74U, 39U, NE_RANGE_TYPE_NORMAL, }, {
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    89U, 5U, 91U, 34U, NE_RANGE_TYPE_NORMAL, }, {
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    92U, 5U, 94U, 39U, NE_RANGE_TYPE_NORMAL, }, {
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    95U, 5U, 97U, 35U, NE_RANGE_TYPE_NORMAL, }, {
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    98U, 5U, 98U, 33U, NE_RANGE_TYPE_NORMAL, }, {
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    101U, 5U, 101U, 21U, NE_RANGE_TYPE_NORMAL, }, {
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    106U, 5U, 108U, 57U, NE_RANGE_TYPE_NORMAL, }, {
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/plant.ssc",
    109U, 5U, 109U, 31U, NE_RANGE_TYPE_NORMAL, }, {
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/sensors.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/sensors.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/sensors.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/sensors.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, }, {
    "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/sensors.sscp",
    1U, 1U, 1U, 1U, NE_RANGE_TYPE_PROTECTED, } };

static NeParameterData *s_logical_parameter_data = NULL;
static NeParameterData *s_integer_parameter_data = NULL;
static NeParameterData *s_index_parameter_data = NULL;
static NeParameterData *s_real_parameter_data = NULL;
static real_T s_constant_table0[12] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
  0.0, 0.0, 0.0, 0.0 };

static NeDsMethodOutput *ds_output_m_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mM_P.mNumCol = 110;
  out->mM_P.mNumRow = 110;
  out->mM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    111);
  out->mM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    36);
  return out;
}

static NeDsMethodOutput *ds_output_m(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mM.mN = 36;
  out->mM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 36);
  return out;
}

static NeDsMethodOutput *ds_output_vmm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mVMM.mN = 36;
  out->mVMM.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    36);
  return out;
}

static NeDsMethodOutput *ds_output_dxm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXM_P.mNumCol = 110;
  out->mDXM_P.mNumRow = 36;
  out->mDXM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    111);
  out->mDXM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dxm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXM.mN = 0;
  out->mDXM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dum_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUM_P.mNumCol = 4;
  out->mDUM_P.mNumRow = 36;
  out->mDUM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  out->mDUM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dum(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUM.mN = 0;
  out->mDUM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dtm_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTM_P.mNumCol = 1;
  out->mDTM_P.mNumRow = 36;
  out->mDTM_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mDTM_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dtm(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTM.mN = 0;
  out->mDTM.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_a_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mA_P.mNumCol = 110;
  out->mA_P.mNumRow = 110;
  out->mA_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    111);
  out->mA_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    809);
  return out;
}

static NeDsMethodOutput *ds_output_a(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mA.mN = 809;
  out->mA.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 809);
  return out;
}

static NeDsMethodOutput *ds_output_b_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mB_P.mNumCol = 4;
  out->mB_P.mNumRow = 110;
  out->mB_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  out->mB_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    12);
  return out;
}

static NeDsMethodOutput *ds_output_b(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mB.mN = 12;
  out->mB.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 12);
  return out;
}

static NeDsMethodOutput *ds_output_c_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mC_P.mNumCol = 1;
  out->mC_P.mNumRow = 110;
  out->mC_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mC_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_c(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mC.mN = 0;
  out->mC.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_f(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mF.mN = 110;
  out->mF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 110);
  return out;
}

static NeDsMethodOutput *ds_output_vmf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mVMF.mN = 110;
  out->mVMF.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    110);
  return out;
}

static NeDsMethodOutput *ds_output_slf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSLF.mN = 110;
  out->mSLF.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    110);
  return out;
}

static NeDsMethodOutput *ds_output_slf0(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSLF0.mN = 110;
  out->mSLF0.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 110);
  return out;
}

static NeDsMethodOutput *ds_output_dxf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXF_P.mNumCol = 110;
  out->mDXF_P.mNumRow = 110;
  out->mDXF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    111);
  out->mDXF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    808);
  return out;
}

static NeDsMethodOutput *ds_output_dxf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXF.mN = 808;
  out->mDXF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 808);
  return out;
}

static NeDsMethodOutput *ds_output_duf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUF_P.mNumCol = 4;
  out->mDUF_P.mNumRow = 110;
  out->mDUF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  out->mDUF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    16);
  return out;
}

static NeDsMethodOutput *ds_output_duf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUF.mN = 16;
  out->mDUF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 16);
  return out;
}

static NeDsMethodOutput *ds_output_dtf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTF_P.mNumCol = 1;
  out->mDTF_P.mNumRow = 110;
  out->mDTF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mDTF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dtf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTF.mN = 0;
  out->mDTF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_ddf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDF_P.mNumCol = 0;
  out->mDDF_P.mNumRow = 110;
  out->mDDF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    1);
  out->mDDF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_ddf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDDF.mN = 0;
  out->mDDF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_tduf_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mTDUF_P.mNumCol = 4;
  out->mTDUF_P.mNumRow = 110;
  out->mTDUF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  out->mTDUF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    28);
  return out;
}

static NeDsMethodOutput *ds_output_tdxf_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mTDXF_P.mNumCol = 110;
  out->mTDXF_P.mNumRow = 110;
  out->mTDXF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    111);
  out->mTDXF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    1617);
  return out;
}

static NeDsMethodOutput *ds_output_dnf_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDNF_P.mNumCol = 0;
  out->mDNF_P.mNumRow = 110;
  out->mDNF_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    1);
  out->mDNF_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dnf(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDNF.mN = 0;
  out->mDNF.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dnf_v_x(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDNF_V_X.mN = 110;
  out->mDNF_V_X.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 110);
  return out;
}

static NeDsMethodOutput *ds_output_ic(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mIC.mN = 110;
  out->mIC.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 110);
  return out;
}

static NeDsMethodOutput *ds_output_icr(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mICR.mN = 0;
  out->mICR.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_icr_im(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mICR_IM.mN = 0;
  out->mICR_IM.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_icr_id(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mICR_ID.mN = 0;
  out->mICR_ID.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_icr_il(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mICR_IL.mN = 0;
  out->mICR_IL.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dxicr(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXICR.mN = 0;
  out->mDXICR.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dxicr_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXICR_P.mNumCol = 110;
  out->mDXICR_P.mNumRow = 0;
  out->mDXICR_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 111);
  out->mDXICR_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_tduicr_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mTDUICR_P.mNumCol = 4;
  out->mTDUICR_P.mNumRow = 0;
  out->mTDUICR_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 5);
  out->mTDUICR_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_mduy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMDUY_P.mNumCol = 4;
  out->mMDUY_P.mNumRow = 21;
  out->mMDUY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  out->mMDUY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_mdxy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMDXY_P.mNumCol = 110;
  out->mMDXY_P.mNumRow = 21;
  out->mMDXY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    111);
  out->mMDXY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_tduy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mTDUY_P.mNumCol = 4;
  out->mTDUY_P.mNumRow = 21;
  out->mTDUY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  out->mTDUY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_tdxy_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mTDXY_P.mNumCol = 110;
  out->mTDXY_P.mNumRow = 21;
  out->mTDXY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    111);
  out->mTDXY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    54);
  return out;
}

static NeDsMethodOutput *ds_output_y(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mY.mN = 21;
  out->mY.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 21);
  return out;
}

static NeDsMethodOutput *ds_output_dxy_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXY_P.mNumCol = 110;
  out->mDXY_P.mNumRow = 21;
  out->mDXY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    111);
  out->mDXY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    54);
  return out;
}

static NeDsMethodOutput *ds_output_dxy(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXY.mN = 54;
  out->mDXY.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 54);
  return out;
}

static NeDsMethodOutput *ds_output_duy_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUY_P.mNumCol = 4;
  out->mDUY_P.mNumRow = 21;
  out->mDUY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  out->mDUY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_duy(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUY.mN = 0;
  out->mDUY.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dty_p(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTY_P.mNumCol = 1;
  out->mDTY_P.mNumRow = 21;
  out->mDTY_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mDTY_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dty(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTY.mN = 0;
  out->mDTY.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_mode(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mMODE.mN = 5;
  out->mMODE.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  return out;
}

static NeDsMethodOutput *ds_output_zc(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mZC.mN = 5;
  out->mZC.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 5);
  return out;
}

static NeDsMethodOutput *ds_output_cache_r(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mCACHE_R.mN = 0;
  out->mCACHE_R.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_cache_i(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mCACHE_I.mN = 0;
  out->mCACHE_I.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_update_r(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mUPDATE_R.mN = 0;
  out->mUPDATE_R.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_update_i(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mUPDATE_I.mN = 0;
  out->mUPDATE_I.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_sfo(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSFO.mN = 0;
  out->mSFO.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_sfp(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSFP.mN = 0;
  out->mSFP.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_init_r(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mINIT_R.mN = 0;
  out->mINIT_R.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_init_i(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mINIT_I.mN = 0;
  out->mINIT_I.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_log(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mLOG.mN = 144;
  out->mLOG.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 144);
  return out;
}

static NeDsMethodOutput *ds_output_assert(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mASSERT.mN = 3;
  out->mASSERT.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    3);
  return out;
}

static NeDsMethodOutput *ds_output_passert(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mPASSERT.mN = 0;
  out->mPASSERT.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_iassert(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mIASSERT.mN = 0;
  out->mIASSERT.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_del_t(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDEL_T.mN = 0;
  out->mDEL_T.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_del_v(const NeDynamicSystem *ds, PmAllocator *
  allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDEL_V.mN = 0;
  out->mDEL_V.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_del_v0(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDEL_V0.mN = 0;
  out->mDEL_V0.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_del_tmax(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDEL_TMAX.mN = 0;
  out->mDEL_TMAX.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dxdelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXDELT_P.mNumCol = 110;
  out->mDXDELT_P.mNumRow = 0;
  out->mDXDELT_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 111);
  out->mDXDELT_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dxdelt(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDXDELT.mN = 0;
  out->mDXDELT.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dudelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUDELT_P.mNumCol = 4;
  out->mDUDELT_P.mNumRow = 0;
  out->mDUDELT_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 5);
  out->mDUDELT_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dudelt(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDUDELT.mN = 0;
  out->mDUDELT.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dtdelt_p(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTDELT_P.mNumCol = 1;
  out->mDTDELT_P.mNumRow = 0;
  out->mDTDELT_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 2);
  out->mDTDELT_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof
    (int32_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_dtdelt(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDTDELT.mN = 0;
  out->mDTDELT.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_obs_exp(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mOBS_EXP.mN = 144;
  out->mOBS_EXP.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    144);
  return out;
}

static NeDsMethodOutput *ds_output_obs_act(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mOBS_ACT.mN = 144;
  out->mOBS_ACT.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    144);
  return out;
}

static NeDsMethodOutput *ds_output_obs_all(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mOBS_ALL.mN = 144;
  out->mOBS_ALL.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    144);
  return out;
}

static NeDsMethodOutput *ds_output_obs_il(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mOBS_IL.mN = 144;
  out->mOBS_IL.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof
    (boolean_T), 144);
  return out;
}

static NeDsMethodOutput *ds_output_dp_l(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDP_L.mN = 0;
  out->mDP_L.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dp_i(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDP_I.mN = 0;
  out->mDP_I.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dp_j(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDP_J.mN = 0;
  out->mDP_J.mX = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_dp_r(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mDP_R.mN = 0;
  out->mDP_R.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_qx(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQX.mN = 0;
  out->mQX.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_qu(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQU.mN = 0;
  out->mQU.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_qt(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQT.mN = 0;
  out->mQT.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_q1(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQ1.mN = 0;
  out->mQ1.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T), 0);
  return out;
}

static NeDsMethodOutput *ds_output_qx_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQX_P.mNumCol = 110;
  out->mQX_P.mNumRow = 110;
  out->mQX_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    111);
  out->mQX_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_qu_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQU_P.mNumCol = 4;
  out->mQU_P.mNumRow = 110;
  out->mQU_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    5);
  out->mQU_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_qt_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQT_P.mNumCol = 1;
  out->mQT_P.mNumRow = 110;
  out->mQT_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mQT_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_q1_p(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mQ1_P.mNumCol = 1;
  out->mQ1_P.mNumRow = 110;
  out->mQ1_P.mJc = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    2);
  out->mQ1_P.mIr = (int32_T *) allocator->mCallocFcn(allocator, sizeof(int32_T),
    0);
  return out;
}

static NeDsMethodOutput *ds_output_var_tol(const NeDynamicSystem *ds,
  PmAllocator *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mVAR_TOL.mN = 110;
  out->mVAR_TOL.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    110);
  return out;
}

static NeDsMethodOutput *ds_output_eq_tol(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mEQ_TOL.mN = 110;
  out->mEQ_TOL.mX = (real_T *) allocator->mCallocFcn(allocator, sizeof(real_T),
    110);
  return out;
}

static NeDsMethodOutput *ds_output_lv(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mLV.mN = 110;
  out->mLV.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    110);
  return out;
}

static NeDsMethodOutput *ds_output_slv(const NeDynamicSystem *ds, PmAllocator
  *allocator)
{
  NeDsMethodOutput *out;
  (void)ds;
  out = (NeDsMethodOutput *) allocator->mCallocFcn(allocator, sizeof
    (NeDsMethodOutput), 1);
  out->mSLV.mN = 110;
  out->mSLV.mX = (boolean_T *) allocator->mCallocFcn(allocator, sizeof(boolean_T),
    110);
  return out;
}

static void release_reference(NeDynamicSystem *ds)
{
  _NeDynamicSystem *_ds;
  _ds = (_NeDynamicSystem *)ds;
  if (--_ds->mRefCnt == 0) {
    _ds->mAlloc.mFreeFcn(&_ds->mAlloc, _ds);
  }
}

static void get_reference(NeDynamicSystem *ds)
{
  _NeDynamicSystem *_ds;
  _ds = (_NeDynamicSystem *)ds;
  ++_ds->mRefCnt;
}

static NeDynamicSystem *diagnostics(const NeDynamicSystem *ds)
{
  _NeDynamicSystem *_ds = (_NeDynamicSystem *)ds;
  ne_ds_get_reference(&_ds->mBase);
  return &_ds->mBase;
}

static void expand(const NeDynamicSystem *ds, const NeDynamicSystemInput *in,
                   PmRealVector *out)
{
  (void)ds;
  memcpy(out->mX, in->mX.mX, sizeof(real_T)*out->mN);
}

NeDynamicSystem *open_loop_94817720_1_dae_ds(PmAllocator *allocator)
{
  NeDynamicSystem *ds;
  _NeDynamicSystem *_ds;
  static NeDsIoInfo input_info[1];
  static NeDsIoInfo output_info[7];

  /* allocate dynamic system data and extended data */
  _ds = (_NeDynamicSystem *)allocator->mCallocFcn( allocator, sizeof
    (_NeDynamicSystem), 1);
  _ds->mAlloc = *allocator;
  _ds->mRefCnt = 1;
  ds = &_ds->mBase;

  /* setup sizes */
  ds->mNumVariables = 110;
  ds->mNumDiscreteRealVariables = 0;
  ds->mNumDifferentialVariables = 12;
  ds->mNumEquations = 110;
  ds->mNumICResiduals = 0;
  ds->mNumModes = 5;
  ds->mNumMajorModes = 0;
  ds->mNumRealCache = 0;
  ds->mNumIntCache = 0;
  ds->mNumObservables = 33;
  ds->mNumObservableElements = 144;
  ds->mNumZcs = 5;
  ds->mNumAsserts = 3;
  ds->mNumAssertRanges = 3;
  ds->mNumParamAsserts = 0;
  ds->mNumParamAssertRanges = 0;
  ds->mNumInitialAsserts = 0;
  ds->mNumInitialAssertRanges = 0;
  ds->mNumRanges = 2;
  ds->mNumEquationRanges = 21;
  ds->mNumFundamentalSamples = 0;
  ds->mNumDelays = 0;
  ds->mNumLogicalParameters = 0;
  ds->mNumIntegerParameters = 0;
  ds->mNumIndexParameters = 0;
  ds->mNumRealParameters = 0;
  ds->mNumLogicalDerivedParameters = 0;
  ds->mNumIntegerDerivedParameters = 0;
  ds->mNumIndexDerivedParameters = 0;
  ds->mNumRealDerivedParameters = 0;
  ds->mIsOutputLinear = TRUE;
  ds->mIsOutputSwitchedLinear = TRUE;

  /* setup ios */
  ds->mNumIo[NE_INPUT_IO_TYPE] = 1;
  input_info[0].mIdentifier = "Plant_of_the_quadrocopter.ctrl";
  input_info[0].mM = 4;
  input_info[0].mN = 1;
  input_info[0].mName = "Plant_of_the_quadrocopter.ctrl";
  input_info[0].mUnit = "N";
  ds->mIo[NE_INPUT_IO_TYPE] = input_info;
  ds->mNumIo[NE_OUTPUT_IO_TYPE] = 7;
  output_info[0].mIdentifier = "Plant_of_the_quadrocopter.a";
  output_info[0].mM = 3;
  output_info[0].mN = 1;
  output_info[0].mName = "Plant_of_the_quadrocopter.a";
  output_info[0].mUnit = "m/s^2";
  output_info[1].mIdentifier = "Plant_of_the_quadrocopter.angle";
  output_info[1].mM = 3;
  output_info[1].mN = 1;
  output_info[1].mName = "Plant_of_the_quadrocopter.angle";
  output_info[1].mUnit = "rad";
  output_info[2].mIdentifier = "Plant_of_the_quadrocopter.dangle";
  output_info[2].mM = 3;
  output_info[2].mN = 1;
  output_info[2].mName = "Plant_of_the_quadrocopter.dangle";
  output_info[2].mUnit = "rad/s";
  output_info[3].mIdentifier = "Plant_of_the_quadrocopter.pos";
  output_info[3].mM = 3;
  output_info[3].mN = 1;
  output_info[3].mName = "Plant_of_the_quadrocopter.pos";
  output_info[3].mUnit = "m";
  output_info[4].mIdentifier = "Plant_of_the_quadrocopter.v";
  output_info[4].mM = 3;
  output_info[4].mN = 1;
  output_info[4].mName = "Plant_of_the_quadrocopter.v";
  output_info[4].mUnit = "m/s";
  output_info[5].mIdentifier = "Plant_of_the_quadrocopter1.acc";
  output_info[5].mM = 3;
  output_info[5].mN = 1;
  output_info[5].mName = "Plant_of_the_quadrocopter1.acc";
  output_info[5].mUnit = "1";
  output_info[6].mIdentifier = "Plant_of_the_quadrocopter1.gyro";
  output_info[6].mM = 3;
  output_info[6].mN = 1;
  output_info[6].mName = "Plant_of_the_quadrocopter1.gyro";
  output_info[6].mUnit = "deg/s";
  ds->mIo[NE_OUTPUT_IO_TYPE] = output_info;

  /* setup administration methods */
  ds->mReleaseReference = release_reference;
  ds->mGetReference = get_reference;
  ds->mDiagnosticsDsFcn = diagnostics;
  ds->mExpandFcn = expand;
  ds->mMethods[NE_DS_METHOD_M_P] = open_loop_94817720_1_ds_m_p;
  ds->mMakeOutput[NE_DS_METHOD_M_P] = ds_output_m_p;
  ds->mMethods[NE_DS_METHOD_M] = open_loop_94817720_1_ds_m;
  ds->mMakeOutput[NE_DS_METHOD_M] = ds_output_m;
  ds->mMethods[NE_DS_METHOD_VMM] = open_loop_94817720_1_ds_vmm;
  ds->mMakeOutput[NE_DS_METHOD_VMM] = ds_output_vmm;
  ds->mMethods[NE_DS_METHOD_DXM_P] = ds_dxm_p;
  ds->mMakeOutput[NE_DS_METHOD_DXM_P] = ds_output_dxm_p;
  ds->mMethods[NE_DS_METHOD_DXM] = ds_dxm;
  ds->mMakeOutput[NE_DS_METHOD_DXM] = ds_output_dxm;
  ds->mMethods[NE_DS_METHOD_DUM_P] = ds_dum_p;
  ds->mMakeOutput[NE_DS_METHOD_DUM_P] = ds_output_dum_p;
  ds->mMethods[NE_DS_METHOD_DUM] = ds_dum;
  ds->mMakeOutput[NE_DS_METHOD_DUM] = ds_output_dum;
  ds->mMethods[NE_DS_METHOD_DTM_P] = ds_dtm_p;
  ds->mMakeOutput[NE_DS_METHOD_DTM_P] = ds_output_dtm_p;
  ds->mMethods[NE_DS_METHOD_DTM] = ds_dtm;
  ds->mMakeOutput[NE_DS_METHOD_DTM] = ds_output_dtm;
  ds->mMethods[NE_DS_METHOD_A_P] = open_loop_94817720_1_ds_a_p;
  ds->mMakeOutput[NE_DS_METHOD_A_P] = ds_output_a_p;
  ds->mMethods[NE_DS_METHOD_A] = open_loop_94817720_1_ds_a;
  ds->mMakeOutput[NE_DS_METHOD_A] = ds_output_a;
  ds->mMethods[NE_DS_METHOD_B_P] = ds_b_p;
  ds->mMakeOutput[NE_DS_METHOD_B_P] = ds_output_b_p;
  ds->mMethods[NE_DS_METHOD_B] = ds_b;
  ds->mMakeOutput[NE_DS_METHOD_B] = ds_output_b;
  ds->mMethods[NE_DS_METHOD_C_P] = ds_c_p;
  ds->mMakeOutput[NE_DS_METHOD_C_P] = ds_output_c_p;
  ds->mMethods[NE_DS_METHOD_C] = ds_c;
  ds->mMakeOutput[NE_DS_METHOD_C] = ds_output_c;
  ds->mMethods[NE_DS_METHOD_F] = open_loop_94817720_1_ds_f;
  ds->mMakeOutput[NE_DS_METHOD_F] = ds_output_f;
  ds->mMethods[NE_DS_METHOD_VMF] = open_loop_94817720_1_ds_vmf;
  ds->mMakeOutput[NE_DS_METHOD_VMF] = ds_output_vmf;
  ds->mMethods[NE_DS_METHOD_SLF] = ds_slf;
  ds->mMakeOutput[NE_DS_METHOD_SLF] = ds_output_slf;
  ds->mMethods[NE_DS_METHOD_SLF0] = ds_slf0;
  ds->mMakeOutput[NE_DS_METHOD_SLF0] = ds_output_slf0;
  ds->mMethods[NE_DS_METHOD_DXF_P] = open_loop_94817720_1_ds_dxf_p;
  ds->mMakeOutput[NE_DS_METHOD_DXF_P] = ds_output_dxf_p;
  ds->mMethods[NE_DS_METHOD_DXF] = open_loop_94817720_1_ds_dxf;
  ds->mMakeOutput[NE_DS_METHOD_DXF] = ds_output_dxf;
  ds->mMethods[NE_DS_METHOD_DUF_P] = ds_duf_p;
  ds->mMakeOutput[NE_DS_METHOD_DUF_P] = ds_output_duf_p;
  ds->mMethods[NE_DS_METHOD_DUF] = open_loop_94817720_1_ds_duf;
  ds->mMakeOutput[NE_DS_METHOD_DUF] = ds_output_duf;
  ds->mMethods[NE_DS_METHOD_DTF_P] = ds_dtf_p;
  ds->mMakeOutput[NE_DS_METHOD_DTF_P] = ds_output_dtf_p;
  ds->mMethods[NE_DS_METHOD_DTF] = ds_dtf;
  ds->mMakeOutput[NE_DS_METHOD_DTF] = ds_output_dtf;
  ds->mMethods[NE_DS_METHOD_DDF_P] = ds_ddf_p;
  ds->mMakeOutput[NE_DS_METHOD_DDF_P] = ds_output_ddf_p;
  ds->mMethods[NE_DS_METHOD_DDF] = ds_ddf;
  ds->mMakeOutput[NE_DS_METHOD_DDF] = ds_output_ddf;
  ds->mMethods[NE_DS_METHOD_TDUF_P] = ds_tduf_p;
  ds->mMakeOutput[NE_DS_METHOD_TDUF_P] = ds_output_tduf_p;
  ds->mMethods[NE_DS_METHOD_TDXF_P] = open_loop_94817720_1_ds_tdxf_p;
  ds->mMakeOutput[NE_DS_METHOD_TDXF_P] = ds_output_tdxf_p;
  ds->mMethods[NE_DS_METHOD_DNF_P] = ds_dnf_p;
  ds->mMakeOutput[NE_DS_METHOD_DNF_P] = ds_output_dnf_p;
  ds->mMethods[NE_DS_METHOD_DNF] = ds_dnf;
  ds->mMakeOutput[NE_DS_METHOD_DNF] = ds_output_dnf;
  ds->mMethods[NE_DS_METHOD_DNF_V_X] = ds_dnf_v_x;
  ds->mMakeOutput[NE_DS_METHOD_DNF_V_X] = ds_output_dnf_v_x;
  ds->mMethods[NE_DS_METHOD_IC] = ds_ic;
  ds->mMakeOutput[NE_DS_METHOD_IC] = ds_output_ic;
  ds->mMethods[NE_DS_METHOD_ICR] = ds_icr;
  ds->mMakeOutput[NE_DS_METHOD_ICR] = ds_output_icr;
  ds->mMethods[NE_DS_METHOD_ICR_IM] = ds_icr_im;
  ds->mMakeOutput[NE_DS_METHOD_ICR_IM] = ds_output_icr_im;
  ds->mMethods[NE_DS_METHOD_ICR_ID] = ds_icr_id;
  ds->mMakeOutput[NE_DS_METHOD_ICR_ID] = ds_output_icr_id;
  ds->mMethods[NE_DS_METHOD_ICR_IL] = ds_icr_il;
  ds->mMakeOutput[NE_DS_METHOD_ICR_IL] = ds_output_icr_il;
  ds->mMethods[NE_DS_METHOD_DXICR] = ds_dxicr;
  ds->mMakeOutput[NE_DS_METHOD_DXICR] = ds_output_dxicr;
  ds->mMethods[NE_DS_METHOD_DXICR_P] = ds_dxicr_p;
  ds->mMakeOutput[NE_DS_METHOD_DXICR_P] = ds_output_dxicr_p;
  ds->mMethods[NE_DS_METHOD_TDUICR_P] = ds_tduicr_p;
  ds->mMakeOutput[NE_DS_METHOD_TDUICR_P] = ds_output_tduicr_p;
  ds->mMethods[NE_DS_METHOD_MDUY_P] = ds_mduy_p;
  ds->mMakeOutput[NE_DS_METHOD_MDUY_P] = ds_output_mduy_p;
  ds->mMethods[NE_DS_METHOD_MDXY_P] = ds_mdxy_p;
  ds->mMakeOutput[NE_DS_METHOD_MDXY_P] = ds_output_mdxy_p;
  ds->mMethods[NE_DS_METHOD_TDUY_P] = ds_tduy_p;
  ds->mMakeOutput[NE_DS_METHOD_TDUY_P] = ds_output_tduy_p;
  ds->mMethods[NE_DS_METHOD_TDXY_P] = open_loop_94817720_1_ds_tdxy_p;
  ds->mMakeOutput[NE_DS_METHOD_TDXY_P] = ds_output_tdxy_p;
  ds->mMethods[NE_DS_METHOD_Y] = ds_y;
  ds->mMakeOutput[NE_DS_METHOD_Y] = ds_output_y;
  ds->mMethods[NE_DS_METHOD_DXY_P] = open_loop_94817720_1_ds_dxy_p;
  ds->mMakeOutput[NE_DS_METHOD_DXY_P] = ds_output_dxy_p;
  ds->mMethods[NE_DS_METHOD_DXY] = open_loop_94817720_1_ds_dxy;
  ds->mMakeOutput[NE_DS_METHOD_DXY] = ds_output_dxy;
  ds->mMethods[NE_DS_METHOD_DUY_P] = ds_duy_p;
  ds->mMakeOutput[NE_DS_METHOD_DUY_P] = ds_output_duy_p;
  ds->mMethods[NE_DS_METHOD_DUY] = ds_duy;
  ds->mMakeOutput[NE_DS_METHOD_DUY] = ds_output_duy;
  ds->mMethods[NE_DS_METHOD_DTY_P] = ds_dty_p;
  ds->mMakeOutput[NE_DS_METHOD_DTY_P] = ds_output_dty_p;
  ds->mMethods[NE_DS_METHOD_DTY] = ds_dty;
  ds->mMakeOutput[NE_DS_METHOD_DTY] = ds_output_dty;
  ds->mMethods[NE_DS_METHOD_MODE] = ds_mode;
  ds->mMakeOutput[NE_DS_METHOD_MODE] = ds_output_mode;
  ds->mMethods[NE_DS_METHOD_ZC] = ds_zc;
  ds->mMakeOutput[NE_DS_METHOD_ZC] = ds_output_zc;
  ds->mMethods[NE_DS_METHOD_CACHE_R] = ds_cache_r;
  ds->mMakeOutput[NE_DS_METHOD_CACHE_R] = ds_output_cache_r;
  ds->mMethods[NE_DS_METHOD_CACHE_I] = ds_cache_i;
  ds->mMakeOutput[NE_DS_METHOD_CACHE_I] = ds_output_cache_i;
  ds->mMethods[NE_DS_METHOD_UPDATE_R] = ds_update_r;
  ds->mMakeOutput[NE_DS_METHOD_UPDATE_R] = ds_output_update_r;
  ds->mMethods[NE_DS_METHOD_UPDATE_I] = ds_update_i;
  ds->mMakeOutput[NE_DS_METHOD_UPDATE_I] = ds_output_update_i;
  ds->mMethods[NE_DS_METHOD_SFO] = ds_sfo;
  ds->mMakeOutput[NE_DS_METHOD_SFO] = ds_output_sfo;
  ds->mMethods[NE_DS_METHOD_SFP] = ds_sfp;
  ds->mMakeOutput[NE_DS_METHOD_SFP] = ds_output_sfp;
  ds->mMethods[NE_DS_METHOD_INIT_R] = ds_init_r;
  ds->mMakeOutput[NE_DS_METHOD_INIT_R] = ds_output_init_r;
  ds->mMethods[NE_DS_METHOD_INIT_I] = ds_init_i;
  ds->mMakeOutput[NE_DS_METHOD_INIT_I] = ds_output_init_i;
  ds->mMethods[NE_DS_METHOD_LOG] = open_loop_94817720_1_ds_log;
  ds->mMakeOutput[NE_DS_METHOD_LOG] = ds_output_log;
  ds->mMethods[NE_DS_METHOD_ASSERT] = ds_assert;
  ds->mMakeOutput[NE_DS_METHOD_ASSERT] = ds_output_assert;
  ds->mMethods[NE_DS_METHOD_PASSERT] = ds_passert;
  ds->mMakeOutput[NE_DS_METHOD_PASSERT] = ds_output_passert;
  ds->mMethods[NE_DS_METHOD_IASSERT] = ds_iassert;
  ds->mMakeOutput[NE_DS_METHOD_IASSERT] = ds_output_iassert;
  ds->mMethods[NE_DS_METHOD_DEL_T] = ds_del_t;
  ds->mMakeOutput[NE_DS_METHOD_DEL_T] = ds_output_del_t;
  ds->mMethods[NE_DS_METHOD_DEL_V] = ds_del_v;
  ds->mMakeOutput[NE_DS_METHOD_DEL_V] = ds_output_del_v;
  ds->mMethods[NE_DS_METHOD_DEL_V0] = ds_del_v0;
  ds->mMakeOutput[NE_DS_METHOD_DEL_V0] = ds_output_del_v0;
  ds->mMethods[NE_DS_METHOD_DEL_TMAX] = ds_del_tmax;
  ds->mMakeOutput[NE_DS_METHOD_DEL_TMAX] = ds_output_del_tmax;
  ds->mMethods[NE_DS_METHOD_DXDELT_P] = ds_dxdelt_p;
  ds->mMakeOutput[NE_DS_METHOD_DXDELT_P] = ds_output_dxdelt_p;
  ds->mMethods[NE_DS_METHOD_DXDELT] = ds_dxdelt;
  ds->mMakeOutput[NE_DS_METHOD_DXDELT] = ds_output_dxdelt;
  ds->mMethods[NE_DS_METHOD_DUDELT_P] = ds_dudelt_p;
  ds->mMakeOutput[NE_DS_METHOD_DUDELT_P] = ds_output_dudelt_p;
  ds->mMethods[NE_DS_METHOD_DUDELT] = ds_dudelt;
  ds->mMakeOutput[NE_DS_METHOD_DUDELT] = ds_output_dudelt;
  ds->mMethods[NE_DS_METHOD_DTDELT_P] = ds_dtdelt_p;
  ds->mMakeOutput[NE_DS_METHOD_DTDELT_P] = ds_output_dtdelt_p;
  ds->mMethods[NE_DS_METHOD_DTDELT] = ds_dtdelt;
  ds->mMakeOutput[NE_DS_METHOD_DTDELT] = ds_output_dtdelt;
  ds->mMethods[NE_DS_METHOD_OBS_EXP] = open_loop_94817720_1_ds_obs_exp;
  ds->mMakeOutput[NE_DS_METHOD_OBS_EXP] = ds_output_obs_exp;
  ds->mMethods[NE_DS_METHOD_OBS_ACT] = open_loop_94817720_1_ds_obs_act;
  ds->mMakeOutput[NE_DS_METHOD_OBS_ACT] = ds_output_obs_act;
  ds->mMethods[NE_DS_METHOD_OBS_ALL] = open_loop_94817720_1_ds_obs_all;
  ds->mMakeOutput[NE_DS_METHOD_OBS_ALL] = ds_output_obs_all;
  ds->mMethods[NE_DS_METHOD_OBS_IL] = open_loop_94817720_1_ds_obs_il;
  ds->mMakeOutput[NE_DS_METHOD_OBS_IL] = ds_output_obs_il;
  ds->mMethods[NE_DS_METHOD_DP_L] = ds_dp_l;
  ds->mMakeOutput[NE_DS_METHOD_DP_L] = ds_output_dp_l;
  ds->mMethods[NE_DS_METHOD_DP_I] = ds_dp_i;
  ds->mMakeOutput[NE_DS_METHOD_DP_I] = ds_output_dp_i;
  ds->mMethods[NE_DS_METHOD_DP_J] = ds_dp_j;
  ds->mMakeOutput[NE_DS_METHOD_DP_J] = ds_output_dp_j;
  ds->mMethods[NE_DS_METHOD_DP_R] = ds_dp_r;
  ds->mMakeOutput[NE_DS_METHOD_DP_R] = ds_output_dp_r;
  ds->mMethods[NE_DS_METHOD_QX] = ds_qx;
  ds->mMakeOutput[NE_DS_METHOD_QX] = ds_output_qx;
  ds->mMethods[NE_DS_METHOD_QU] = ds_qu;
  ds->mMakeOutput[NE_DS_METHOD_QU] = ds_output_qu;
  ds->mMethods[NE_DS_METHOD_QT] = ds_qt;
  ds->mMakeOutput[NE_DS_METHOD_QT] = ds_output_qt;
  ds->mMethods[NE_DS_METHOD_Q1] = ds_q1;
  ds->mMakeOutput[NE_DS_METHOD_Q1] = ds_output_q1;
  ds->mMethods[NE_DS_METHOD_QX_P] = ds_qx_p;
  ds->mMakeOutput[NE_DS_METHOD_QX_P] = ds_output_qx_p;
  ds->mMethods[NE_DS_METHOD_QU_P] = ds_qu_p;
  ds->mMakeOutput[NE_DS_METHOD_QU_P] = ds_output_qu_p;
  ds->mMethods[NE_DS_METHOD_QT_P] = ds_qt_p;
  ds->mMakeOutput[NE_DS_METHOD_QT_P] = ds_output_qt_p;
  ds->mMethods[NE_DS_METHOD_Q1_P] = ds_q1_p;
  ds->mMakeOutput[NE_DS_METHOD_Q1_P] = ds_output_q1_p;
  ds->mMethods[NE_DS_METHOD_VAR_TOL] = ds_var_tol;
  ds->mMakeOutput[NE_DS_METHOD_VAR_TOL] = ds_output_var_tol;
  ds->mMethods[NE_DS_METHOD_EQ_TOL] = ds_eq_tol;
  ds->mMakeOutput[NE_DS_METHOD_EQ_TOL] = ds_output_eq_tol;
  ds->mMethods[NE_DS_METHOD_LV] = ds_lv;
  ds->mMakeOutput[NE_DS_METHOD_LV] = ds_output_lv;
  ds->mMethods[NE_DS_METHOD_SLV] = ds_slv;
  ds->mMakeOutput[NE_DS_METHOD_SLV] = ds_output_slv;

  /* equation data */
  ds->mEquationData = s_equation_data;

  /* continuous variable data */
  ds->mVariableData = s_variable_data;

  /* discrete variable data */
  ds->mDiscreteData = s_discrete_data;

  /* observable data */
  ds->mObservableData = s_observable_data;

  /* major mode data */
  ds->mMajorModeData = s_major_mode_data;

  /* zc data */
  ds->mZCData = s_zc_data;

  /* ranges */
  ds->mRanges = s_range;

  /* assert data */
  ds->mAssertData = s_assert_data;

  /* assert ranges */
  ds->mAssertRanges = s_assert_range;

  /* param assert data */
  ds->mParamAssertData = s_param_assert_data;

  /* param assert ranges */
  ds->mParamAssertRanges = s_param_assert_range;

  /* initial assert data */
  ds->mInitialAssertData = s_initial_assert_data;

  /* initial assert ranges */
  ds->mInitialAssertRanges = s_initial_assert_range;

  /* equation ranges */
  ds->mEquationRanges = s_equation_range;

  /* parameters */
  ds->mLogicalParameters = s_logical_parameter_data;
  ds->mIntegerParameters = s_integer_parameter_data;
  ds->mIndexParameters = s_index_parameter_data;
  ds->mRealParameters = s_real_parameter_data;

  /* constant tables */
  _ds->mTable0 = s_constant_table0;
  return (NeDynamicSystem *)_ds;
}

static int32_T ds_assert (const NeDynamicSystem *t0, const NeDynamicSystemInput *
  t2, NeDsMethodOutput *t3)
{
  PmIntVector out;
  int32_T M_idx_4;
  (void)t0;
  M_idx_4 = t2->mM.mX[4];
  out = t3->mASSERT;
  out.mX[0] = (int32_T)(M_idx_4 != 0);
  out.mX[1] = 1;
  out.mX[2] = 1;
  (void)t0;
  (void)t3;
  return 0;
}

static int32_T ds_passert (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_iassert (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_del_v (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_del_v0 (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_del_tmax (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_del_t (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_dxdelt (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_dxdelt_p (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  int32_T b;
  (void)t1;
  out = t2->mDXDELT_P;
  out.mNumCol = 110UL;
  out.mNumRow = 0UL;
  for (b = 0; b < 111; b++) {
    out.mJc[b] = 0;
  }

  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_dudelt (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_dudelt_p (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mDUDELT_P;
  out.mNumCol = 4UL;
  out.mNumRow = 0UL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  out.mJc[2] = 0;
  out.mJc[3] = 0;
  out.mJc[4] = 0;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_dtdelt (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_dtdelt_p (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mDTDELT_P;
  out.mNumCol = 1UL;
  out.mNumRow = 0UL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_cache_r (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_init_r (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_update_r (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_cache_i (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_init_i (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_update_i (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_sfp (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_sfo (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_duf_p (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mDUF_P;
  out.mNumCol = 4UL;
  out.mNumRow = 110UL;
  out.mJc[0] = 0;
  out.mJc[1] = 4;
  out.mJc[2] = 8;
  out.mJc[3] = 12;
  out.mJc[4] = 16;
  out.mIr[0] = 12;
  out.mIr[1] = 13;
  out.mIr[2] = 14;
  out.mIr[3] = 15;
  out.mIr[4] = 12;
  out.mIr[5] = 13;
  out.mIr[6] = 14;
  out.mIr[7] = 15;
  out.mIr[8] = 12;
  out.mIr[9] = 13;
  out.mIr[10] = 14;
  out.mIr[11] = 15;
  out.mIr[12] = 12;
  out.mIr[13] = 13;
  out.mIr[14] = 14;
  out.mIr[15] = 15;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_dtf (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_dtf_p (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mDTF_P;
  out.mNumCol = 1UL;
  out.mNumRow = 110UL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_b (const NeDynamicSystem *sys, const NeDynamicSystemInput *t1,
                     NeDsMethodOutput *t2)
{
  PmRealVector out;
  (void)t1;
  out = t2->mB;
  out.mX[0] = -0.032526911934581189;
  out.mX[1] = -0.032526911934581189;
  out.mX[2] = 0.0;
  out.mX[3] = -0.032526911934581189;
  out.mX[4] = 0.032526911934581189;
  out.mX[5] = 0.0;
  out.mX[6] = 0.032526911934581189;
  out.mX[7] = 0.032526911934581189;
  out.mX[8] = 0.0;
  out.mX[9] = 0.032526911934581189;
  out.mX[10] = -0.032526911934581189;
  out.mX[11] = 0.0;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_b_p (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mB_P;
  out.mNumCol = 4UL;
  out.mNumRow = 110UL;
  out.mJc[0] = 0;
  out.mJc[1] = 3;
  out.mJc[2] = 6;
  out.mJc[3] = 9;
  out.mJc[4] = 12;
  out.mIr[0] = 6;
  out.mIr[1] = 7;
  out.mIr[2] = 8;
  out.mIr[3] = 6;
  out.mIr[4] = 7;
  out.mIr[5] = 8;
  out.mIr[6] = 6;
  out.mIr[7] = 7;
  out.mIr[8] = 8;
  out.mIr[9] = 6;
  out.mIr[10] = 7;
  out.mIr[11] = 8;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_c (const NeDynamicSystem *sys, const NeDynamicSystemInput *t1,
                     NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_c_p (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mC_P;
  out.mNumCol = 1UL;
  out.mNumRow = 110UL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_tduf_p (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mTDUF_P;
  out.mNumCol = 4UL;
  out.mNumRow = 110UL;
  out.mJc[0] = 0;
  out.mJc[1] = 7;
  out.mJc[2] = 14;
  out.mJc[3] = 21;
  out.mJc[4] = 28;
  out.mIr[0] = 6;
  out.mIr[1] = 7;
  out.mIr[2] = 8;
  out.mIr[3] = 12;
  out.mIr[4] = 13;
  out.mIr[5] = 14;
  out.mIr[6] = 15;
  out.mIr[7] = 6;
  out.mIr[8] = 7;
  out.mIr[9] = 8;
  out.mIr[10] = 12;
  out.mIr[11] = 13;
  out.mIr[12] = 14;
  out.mIr[13] = 15;
  out.mIr[14] = 6;
  out.mIr[15] = 7;
  out.mIr[16] = 8;
  out.mIr[17] = 12;
  out.mIr[18] = 13;
  out.mIr[19] = 14;
  out.mIr[20] = 15;
  out.mIr[21] = 6;
  out.mIr[22] = 7;
  out.mIr[23] = 8;
  out.mIr[24] = 12;
  out.mIr[25] = 13;
  out.mIr[26] = 14;
  out.mIr[27] = 15;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_ddf (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_ddf_p (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mDDF_P;
  out.mNumCol = 0UL;
  out.mNumRow = 110UL;
  out.mJc[0] = 0;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_slf (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  PmBoolVector out;
  boolean_T t0[110];
  int32_T b;
  (void)t1;
  out = t2->mSLF;
  for (b = 0; b < 110; b++) {
    t0[b] = false;
  }

  for (b = 0; b < 110; b++) {
    out.mX[b] = t0[b];
  }

  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_dnf (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_dnf_p (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mDNF_P;
  out.mNumCol = 0UL;
  out.mNumRow = 110UL;
  out.mJc[0] = 0;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_dnf_v_x (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmBoolVector out;
  boolean_T t0[110];
  int32_T b;
  (void)t1;
  out = t2->mDNF_V_X;
  for (b = 0; b < 110; b++) {
    t0[b] = true;
  }

  for (b = 0; b < 110; b++) {
    out.mX[b] = t0[b];
  }

  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_slf0 (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  PmBoolVector out;
  boolean_T t0[110];
  int32_T b;
  (void)t1;
  out = t2->mSLF0;
  for (b = 0; b < 110; b++) {
    t0[b] = false;
  }

  for (b = 0; b < 110; b++) {
    out.mX[b] = t0[b];
  }

  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_ic (const NeDynamicSystem *sys, const NeDynamicSystemInput *t1,
                      NeDsMethodOutput *t2)
{
  PmRealVector out;
  real_T t0[110];
  int32_T b;
  static real_T _cg_const_1[110] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  (void)t1;
  out = t2->mIC;
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

static int32_T ds_icr (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_icr_im (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_icr_id (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_icr_il (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_dxicr (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_dxicr_p (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  int32_T b;
  (void)t1;
  out = t2->mDXICR_P;
  out.mNumCol = 110UL;
  out.mNumRow = 0UL;
  for (b = 0; b < 111; b++) {
    out.mJc[b] = 0;
  }

  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_tduicr_p (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mTDUICR_P;
  out.mNumCol = 4UL;
  out.mNumRow = 0UL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  out.mJc[2] = 0;
  out.mJc[3] = 0;
  out.mJc[4] = 0;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_dxm (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_dxm_p (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  int32_T b;
  (void)t1;
  out = t2->mDXM_P;
  out.mNumCol = 110UL;
  out.mNumRow = 36UL;
  for (b = 0; b < 111; b++) {
    out.mJc[b] = 0;
  }

  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_dum (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_dum_p (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mDUM_P;
  out.mNumCol = 4UL;
  out.mNumRow = 36UL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  out.mJc[2] = 0;
  out.mJc[3] = 0;
  out.mJc[4] = 0;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_dtm (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_dtm_p (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mDTM_P;
  out.mNumCol = 1UL;
  out.mNumRow = 36UL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_mode (const NeDynamicSystem *t0, const NeDynamicSystemInput
  *t7, NeDsMethodOutput *t8)
{
  PmIntVector out;
  int32_T t1[5];
  boolean_T t2[1];
  size_t t4;
  size_t t5;
  real_T t6;
  real_T U[4];
  (void)t0;
  U[0] = t7->mU.mX[0];
  U[1] = t7->mU.mX[1];
  U[2] = t7->mU.mX[2];
  U[3] = t7->mU.mX[3];
  out = t8->mMODE;
  t2[0UL] = true;
  for (t5 = 0UL; t5 < 4UL; t5++) {
    t4 = t5 / 4UL;
    t6 = fabs(U[t5]);
    t2[t4 > 0UL ? 0UL : t4] = (t2[t4 > 0UL ? 0UL : t4] && (t6 / 1.0E-9 >= 0.0));
  }

  for (t5 = 0UL; t5 < 4UL; t5++) {
    t1[t5] = (int32_T)(U[t5] >= 0.0);
  }

  out.mX[0] = t1[0];
  out.mX[1] = t1[1];
  out.mX[2] = t1[2];
  out.mX[3] = t1[3];
  out.mX[4] = (int32_T)t2[0UL];
  (void)t0;
  (void)t8;
  return 0;
}

static int32_T ds_dp_l (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_dp_i (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_dp_j (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_dp_r (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_qx (const NeDynamicSystem *sys, const NeDynamicSystemInput *t1,
                      NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_qu (const NeDynamicSystem *sys, const NeDynamicSystemInput *t1,
                      NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_qt (const NeDynamicSystem *sys, const NeDynamicSystemInput *t1,
                      NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_q1 (const NeDynamicSystem *sys, const NeDynamicSystemInput *t1,
                      NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_qx_p (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  int32_T b;
  (void)t1;
  out = t2->mQX_P;
  out.mNumCol = 110UL;
  out.mNumRow = 110UL;
  for (b = 0; b < 111; b++) {
    out.mJc[b] = 0;
  }

  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_qu_p (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mQU_P;
  out.mNumCol = 4UL;
  out.mNumRow = 110UL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  out.mJc[2] = 0;
  out.mJc[3] = 0;
  out.mJc[4] = 0;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_qt_p (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mQT_P;
  out.mNumCol = 1UL;
  out.mNumRow = 110UL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_q1_p (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mQ1_P;
  out.mNumCol = 1UL;
  out.mNumRow = 110UL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_var_tol (const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmRealVector out;
  real_T t0[110];
  int32_T b;
  (void)t1;
  out = t2->mVAR_TOL;
  for (b = 0; b < 110; b++) {
    t0[b] = 1.0E-9;
  }

  for (b = 0; b < 110; b++) {
    out.mX[b] = t0[b];
  }

  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_eq_tol (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  PmRealVector out;
  real_T t0[110];
  int32_T b;
  (void)t1;
  out = t2->mEQ_TOL;
  for (b = 0; b < 110; b++) {
    t0[b] = 1.0E-9;
  }

  for (b = 0; b < 110; b++) {
    out.mX[b] = t0[b];
  }

  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_lv (const NeDynamicSystem *sys, const NeDynamicSystemInput *t1,
                      NeDsMethodOutput *t2)
{
  PmBoolVector out;
  boolean_T t0[110];
  int32_T b;
  (void)t1;
  out = t2->mLV;
  for (b = 0; b < 110; b++) {
    t0[b] = false;
  }

  for (b = 0; b < 110; b++) {
    out.mX[b] = t0[b];
  }

  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_slv (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  PmBoolVector out;
  boolean_T t0[110];
  int32_T b;
  (void)t1;
  out = t2->mSLV;
  for (b = 0; b < 110; b++) {
    t0[b] = false;
  }

  for (b = 0; b < 110; b++) {
    out.mX[b] = t0[b];
  }

  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_y (const NeDynamicSystem *t0, const NeDynamicSystemInput *t15,
                     NeDsMethodOutput *t16)
{
  PmRealVector out;
  real_T X[110];
  int32_T b;
  (void)t0;
  for (b = 0; b < 110; b++) {
    X[b] = t15->mX.mX[b];
  }

  out = t16->mY;
  out.mX[0] = 0.0;
  out.mX[1] = 0.0;
  out.mX[2] = 0.0;
  out.mX[3] = X[0UL];
  out.mX[4] = X[1UL];
  out.mX[5] = X[2UL];
  out.mX[6] = X[34UL];
  out.mX[7] = X[35UL];
  out.mX[8] = X[36UL];
  out.mX[9] = X[3UL];
  out.mX[10] = X[4UL];
  out.mX[11] = X[5UL];
  out.mX[12] = X[6UL];
  out.mX[13] = X[7UL];
  out.mX[14] = X[8UL];
  out.mX[15] = X[107UL];
  out.mX[16] = X[108UL];
  out.mX[17] = X[109UL];
  out.mX[18] = X[34UL] * 57.295779513082323;
  out.mX[19] = X[35UL] * 57.295779513082323;
  out.mX[20] = X[36UL] * 57.295779513082323;
  (void)t0;
  (void)t16;
  return 0;
}

static int32_T ds_duy (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_duy_p (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mDUY_P;
  out.mNumCol = 4UL;
  out.mNumRow = 21UL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  out.mJc[2] = 0;
  out.mJc[3] = 0;
  out.mJc[4] = 0;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_mduy_p (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mMDUY_P;
  out.mNumCol = 4UL;
  out.mNumRow = 21UL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  out.mJc[2] = 0;
  out.mJc[3] = 0;
  out.mJc[4] = 0;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_mdxy_p (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  int32_T b;
  (void)t1;
  out = t2->mMDXY_P;
  out.mNumCol = 110UL;
  out.mNumRow = 21UL;
  for (b = 0; b < 111; b++) {
    out.mJc[b] = 0;
  }

  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_tduy_p (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mTDUY_P;
  out.mNumCol = 4UL;
  out.mNumRow = 21UL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  out.mJc[2] = 0;
  out.mJc[3] = 0;
  out.mJc[4] = 0;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_dty (const NeDynamicSystem *sys, const NeDynamicSystemInput
  *t1, NeDsMethodOutput *t2)
{
  (void)t1;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_dty_p (const NeDynamicSystem *sys, const NeDynamicSystemInput *
  t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mDTY_P;
  out.mNumCol = 1UL;
  out.mNumRow = 21UL;
  out.mJc[0] = 0;
  out.mJc[1] = 0;
  (void)sys;
  (void)t2;
  return 0;
}

static int32_T ds_zc (const NeDynamicSystem *t0, const NeDynamicSystemInput *t7,
                      NeDsMethodOutput *t8)
{
  PmRealVector out;
  real_T t1[5];
  boolean_T t2[1];
  size_t t4;
  size_t t5;
  real_T t6;
  real_T U[4];
  (void)t0;
  U[0] = t7->mU.mX[0];
  U[1] = t7->mU.mX[1];
  U[2] = t7->mU.mX[2];
  U[3] = t7->mU.mX[3];
  out = t8->mZC;
  t2[0UL] = true;
  for (t5 = 0UL; t5 < 4UL; t5++) {
    t4 = t5 / 4UL;
    t6 = fabs(U[t5]);
    t2[t4 > 0UL ? 0UL : t4] = (t2[t4 > 0UL ? 0UL : t4] && (t6 / 1.0E-9 >= 0.0));
  }

  for (t5 = 0UL; t5 < 4UL; t5++) {
    t1[t5] = U[t5];
  }

  out.mX[0] = t1[0];
  out.mX[1] = t1[1];
  out.mX[2] = t1[2];
  out.mX[3] = t1[3];
  out.mX[4] = (real_T)t2[0UL];
  (void)t0;
  (void)t8;
  return 0;
}
