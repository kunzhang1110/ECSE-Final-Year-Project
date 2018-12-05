/* Include files */

#include "blascompat32.h"
#include "sim_Motor_2kW_openloop_sfun.h"
#include "c2_sim_Motor_2kW_openloop.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "sim_Motor_2kW_openloop_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[25] = { "REF_AMP", "REF_FREQ",
  "AMP_MOD", "FREQ_MOD", "TRI_AMP", "TRI_FREQ", "TRI_PER", "phase_c", "tri_wav",
  "pwm_1", "pwm_3", "pwm_5", "pwm_2", "pwm_4", "pwm_6", "mag_fb", "nargin",
  "nargout", "phase_a", "phase_b", "t", "fb_phase_a", "fb_phase_b", "ctrl_sig",
  "error" };

/* Function Declarations */
static void initialize_c2_sim_Motor_2kW_openloop
  (SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance);
static void initialize_params_c2_sim_Motor_2kW_openloop
  (SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance);
static void enable_c2_sim_Motor_2kW_openloop
  (SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance);
static void disable_c2_sim_Motor_2kW_openloop
  (SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_sim_Motor_2kW_openloop
  (SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_sim_Motor_2kW_openloop
  (SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance);
static void set_sim_state_c2_sim_Motor_2kW_openloop
  (SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance, const mxArray
   *c2_st);
static void finalize_c2_sim_Motor_2kW_openloop
  (SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance);
static void sf_c2_sim_Motor_2kW_openloop
  (SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance);
static void c2_chartstep_c2_sim_Motor_2kW_openloop
  (SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance);
static void initSimStructsc2_sim_Motor_2kW_openloop
  (SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_sim_Motor_2kW_openloopInstanceStruct
  *chartInstance, const mxArray *c2_error, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_sim_Motor_2kW_openloopInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn(SFc2_sim_Motor_2kW_openloopInstanceStruct
  *chartInstance, const mxArray *c2_ctrl_sig, const char_T *c2_identifier,
  real_T c2_y[6]);
static void c2_d_emlrt_marshallIn(SFc2_sim_Motor_2kW_openloopInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[6]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[18]);
static void c2_eml_scalar_eg(SFc2_sim_Motor_2kW_openloopInstanceStruct
  *chartInstance);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_e_emlrt_marshallIn(SFc2_sim_Motor_2kW_openloopInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_f_emlrt_marshallIn(SFc2_sim_Motor_2kW_openloopInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_sim_Motor_2kW_openloop, const
  char_T *c2_identifier);
static uint8_T c2_g_emlrt_marshallIn(SFc2_sim_Motor_2kW_openloopInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_sim_Motor_2kW_openloopInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_sim_Motor_2kW_openloop
  (SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_sim_Motor_2kW_openloop = 0U;
}

static void initialize_params_c2_sim_Motor_2kW_openloop
  (SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance)
{
}

static void enable_c2_sim_Motor_2kW_openloop
  (SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_sim_Motor_2kW_openloop
  (SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_sim_Motor_2kW_openloop
  (SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_sim_Motor_2kW_openloop
  (SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[6];
  const mxArray *c2_b_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T *c2_error;
  real_T (*c2_ctrl_sig)[6];
  c2_error = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_ctrl_sig = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(3), FALSE);
  for (c2_i0 = 0; c2_i0 < 6; c2_i0++) {
    c2_u[c2_i0] = (*c2_ctrl_sig)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 6), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = *c2_error;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_b_hoistedGlobal = chartInstance->c2_is_active_c2_sim_Motor_2kW_openloop;
  c2_c_u = c2_b_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_sim_Motor_2kW_openloop
  (SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance, const mxArray
   *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[6];
  int32_T c2_i1;
  real_T *c2_error;
  real_T (*c2_ctrl_sig)[6];
  c2_error = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_ctrl_sig = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
                        "ctrl_sig", c2_dv0);
  for (c2_i1 = 0; c2_i1 < 6; c2_i1++) {
    (*c2_ctrl_sig)[c2_i1] = c2_dv0[c2_i1];
  }

  *c2_error = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    1)), "error");
  chartInstance->c2_is_active_c2_sim_Motor_2kW_openloop = c2_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
     "is_active_c2_sim_Motor_2kW_openloop");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_sim_Motor_2kW_openloop(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_sim_Motor_2kW_openloop
  (SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance)
{
}

static void sf_c2_sim_Motor_2kW_openloop
  (SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance)
{
  int32_T c2_i2;
  real_T *c2_phase_a;
  real_T *c2_phase_b;
  real_T *c2_t;
  real_T *c2_error;
  real_T *c2_fb_phase_a;
  real_T *c2_fb_phase_b;
  real_T (*c2_ctrl_sig)[6];
  c2_fb_phase_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_fb_phase_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_error = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_phase_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_ctrl_sig = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_phase_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_phase_a, 0U);
  for (c2_i2 = 0; c2_i2 < 6; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*c2_ctrl_sig)[c2_i2], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_phase_b, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_t, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_error, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_fb_phase_a, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_fb_phase_b, 6U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_sim_Motor_2kW_openloop(chartInstance);
  sf_debug_check_for_state_inconsistency(_sim_Motor_2kW_openloopMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_sim_Motor_2kW_openloop
  (SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_e_hoistedGlobal;
  real_T c2_phase_a;
  real_T c2_phase_b;
  real_T c2_t;
  real_T c2_fb_phase_a;
  real_T c2_fb_phase_b;
  uint32_T c2_debug_family_var_map[25];
  real_T c2_REF_AMP;
  real_T c2_REF_FREQ;
  real_T c2_AMP_MOD;
  real_T c2_FREQ_MOD;
  real_T c2_TRI_AMP;
  real_T c2_TRI_FREQ;
  real_T c2_TRI_PER;
  real_T c2_phase_c;
  real_T c2_tri_wav;
  real_T c2_pwm_1;
  real_T c2_pwm_3;
  real_T c2_pwm_5;
  real_T c2_pwm_2;
  real_T c2_pwm_4;
  real_T c2_pwm_6;
  real_T c2_mag_fb;
  real_T c2_nargin = 5.0;
  real_T c2_nargout = 2.0;
  real_T c2_ctrl_sig[6];
  real_T c2_error;
  real_T c2_x;
  real_T c2_xk;
  real_T c2_b_x;
  real_T c2_r;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_y;
  real_T c2_f_x;
  real_T c2_b_y;
  real_T c2_b;
  real_T c2_c_y;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_d_y;
  real_T c2_b_b;
  real_T c2_e_y;
  real_T c2_c_b;
  real_T c2_f_y;
  int32_T c2_i3;
  real_T *c2_b_error;
  real_T *c2_b_fb_phase_b;
  real_T *c2_b_fb_phase_a;
  real_T *c2_b_t;
  real_T *c2_b_phase_b;
  real_T *c2_b_phase_a;
  real_T (*c2_b_ctrl_sig)[6];
  c2_b_fb_phase_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_fb_phase_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_error = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_phase_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_ctrl_sig = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_phase_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_phase_a;
  c2_b_hoistedGlobal = *c2_b_phase_b;
  c2_c_hoistedGlobal = *c2_b_t;
  c2_d_hoistedGlobal = *c2_b_fb_phase_a;
  c2_e_hoistedGlobal = *c2_b_fb_phase_b;
  c2_phase_a = c2_hoistedGlobal;
  c2_phase_b = c2_b_hoistedGlobal;
  c2_t = c2_c_hoistedGlobal;
  c2_fb_phase_a = c2_d_hoistedGlobal;
  c2_fb_phase_b = c2_e_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 25U, 25U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_REF_AMP, 0U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_REF_FREQ, 1U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_AMP_MOD, 2U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_FREQ_MOD, 3U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_TRI_AMP, 4U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_TRI_FREQ, 5U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_TRI_PER, 6U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_phase_c, 7U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_tri_wav, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pwm_1, 9U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pwm_3, 10U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pwm_5, 11U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pwm_2, 12U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pwm_4, 13U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pwm_6, 14U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_mag_fb, 15U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 16U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 17U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_phase_a, 18U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_phase_b, 19U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_t, 20U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_fb_phase_a, 21U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_fb_phase_b, 22U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_ctrl_sig, 23U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_error, 24U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 21);
  c2_REF_AMP = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
  c2_REF_FREQ = 300.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
  c2_AMP_MOD = 0.9;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
  c2_FREQ_MOD = 100.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
  c2_TRI_AMP = 1.1111111111111112;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
  c2_TRI_FREQ = 30000.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 28);
  c2_TRI_PER = 3.3333333333333335E-5;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 35);
  c2_phase_c = -c2_phase_a - c2_phase_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 36);
  c2_x = c2_t;
  c2_eml_scalar_eg(chartInstance);
  c2_xk = c2_x;
  c2_b_x = c2_xk;
  c2_eml_scalar_eg(chartInstance);
  c2_r = c2_b_x / 3.3333333333333335E-5;
  c2_c_x = c2_r;
  c2_d_x = c2_c_x;
  c2_d_x = muDoubleScalarRound(c2_d_x);
  c2_e_x = c2_r - c2_d_x;
  c2_y = muDoubleScalarAbs(c2_e_x);
  c2_f_x = c2_r;
  c2_b_y = muDoubleScalarAbs(c2_f_x);
  c2_b = c2_b_y;
  c2_c_y = 2.2204460492503131E-16 * c2_b;
  if (c2_y <= c2_c_y) {
    c2_r = 0.0;
  } else {
    c2_g_x = c2_r;
    c2_h_x = c2_g_x;
    c2_h_x = muDoubleScalarFloor(c2_h_x);
    c2_r = (c2_r - c2_h_x) * 3.3333333333333335E-5;
  }

  c2_i_x = c2_r - 1.6666666666666667E-5;
  c2_j_x = c2_i_x;
  c2_d_y = muDoubleScalarAbs(c2_j_x);
  c2_b_b = c2_d_y;
  c2_e_y = 133333.33333333334 * c2_b_b;
  c2_tri_wav = c2_e_y - c2_TRI_AMP;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 37);
  if (CV_EML_IF(0, 1, 0, c2_phase_a > c2_tri_wav)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 37);
    c2_pwm_1 = c2_REF_AMP;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 38);
    c2_pwm_1 = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 41);
  if (CV_EML_IF(0, 1, 1, c2_phase_b > c2_tri_wav)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 41);
    c2_pwm_3 = c2_REF_AMP;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 42);
    c2_pwm_3 = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 45);
  if (CV_EML_IF(0, 1, 2, c2_phase_c > c2_tri_wav)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 45);
    c2_pwm_5 = c2_REF_AMP;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 46);
    c2_pwm_5 = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 53);
  if (CV_EML_IF(0, 1, 3, c2_pwm_1 == 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 53);
    c2_pwm_2 = c2_REF_AMP;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 54);
    c2_pwm_2 = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 57);
  if (CV_EML_IF(0, 1, 4, c2_pwm_3 == 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 57);
    c2_pwm_4 = c2_REF_AMP;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 58);
    c2_pwm_4 = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 61);
  if (CV_EML_IF(0, 1, 5, c2_pwm_5 == 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 61);
    c2_pwm_6 = c2_REF_AMP;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 62);
    c2_pwm_6 = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 66);
  c2_ctrl_sig[0] = c2_pwm_1;
  c2_ctrl_sig[1] = c2_pwm_2;
  c2_ctrl_sig[2] = c2_pwm_3;
  c2_ctrl_sig[3] = c2_pwm_4;
  c2_ctrl_sig[4] = c2_pwm_5;
  c2_ctrl_sig[5] = c2_pwm_6;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 67);
  c2_mag_fb = 200.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 68);
  c2_c_b = c2_phase_a;
  c2_f_y = 200.0 * c2_c_b;
  c2_error = c2_fb_phase_a - c2_f_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -68);
  sf_debug_symbol_scope_pop();
  for (c2_i3 = 0; c2_i3 < 6; c2_i3++) {
    (*c2_b_ctrl_sig)[c2_i3] = c2_ctrl_sig[c2_i3];
  }

  *c2_b_error = c2_error;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_sim_Motor_2kW_openloop
  (SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_openloopInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_sim_Motor_2kW_openloopInstanceStruct
  *chartInstance, const mxArray *c2_error, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_error), &c2_thisId);
  sf_mex_destroy(&c2_error);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_sim_Motor_2kW_openloopInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_error;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_openloopInstanceStruct *)chartInstanceVoid;
  c2_error = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_error), &c2_thisId);
  sf_mex_destroy(&c2_error);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i4;
  real_T c2_b_inData[6];
  int32_T c2_i5;
  real_T c2_u[6];
  const mxArray *c2_y = NULL;
  SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_openloopInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i4 = 0; c2_i4 < 6; c2_i4++) {
    c2_b_inData[c2_i4] = (*(real_T (*)[6])c2_inData)[c2_i4];
  }

  for (c2_i5 = 0; c2_i5 < 6; c2_i5++) {
    c2_u[c2_i5] = c2_b_inData[c2_i5];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 6), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn(SFc2_sim_Motor_2kW_openloopInstanceStruct
  *chartInstance, const mxArray *c2_ctrl_sig, const char_T *c2_identifier,
  real_T c2_y[6])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_ctrl_sig), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_ctrl_sig);
}

static void c2_d_emlrt_marshallIn(SFc2_sim_Motor_2kW_openloopInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[6])
{
  real_T c2_dv1[6];
  int32_T c2_i6;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv1, 1, 0, 0U, 1, 0U, 2, 1, 6);
  for (c2_i6 = 0; c2_i6 < 6; c2_i6++) {
    c2_y[c2_i6] = c2_dv1[c2_i6];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_ctrl_sig;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[6];
  int32_T c2_i7;
  SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_openloopInstanceStruct *)chartInstanceVoid;
  c2_ctrl_sig = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_ctrl_sig), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_ctrl_sig);
  for (c2_i7 = 0; c2_i7 < 6; c2_i7++) {
    (*(real_T (*)[6])c2_outData)[c2_i7] = c2_y[c2_i7];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_sim_Motor_2kW_openloop_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[18];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i8;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 18), FALSE);
  for (c2_i8 = 0; c2_i8 < 18; c2_i8++) {
    c2_r0 = &c2_info[c2_i8];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i8);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i8);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i8);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i8);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i8);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i8);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i8);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i8);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[18])
{
  c2_info[0].context = "";
  c2_info[0].name = "mrdivide";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[0].fileTimeLo = 1342782144U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 1319697566U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[1].name = "rdivide";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[1].fileTimeLo = 1286786444U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[2].name = "eml_div";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[2].fileTimeLo = 1313319010U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context = "";
  c2_info[3].name = "mtimes";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[3].fileTimeLo = 1289483692U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context = "";
  c2_info[4].name = "mod";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c2_info[4].fileTimeLo = 1326691996U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c2_info[5].name = "eml_scalar_eg";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[5].fileTimeLo = 1286786396U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c2_info[6].name = "eml_scalexp_alloc";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[6].fileTimeLo = 1330572434U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c2_info[7].name = "eml_scalar_eg";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[7].fileTimeLo = 1286786396U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c2_info[8].name = "eml_scalar_floor";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[8].fileTimeLo = 1286786326U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c2_info[9].name = "eml_scalar_round";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c2_info[9].fileTimeLo = 1307622438U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c2_info[10].name = "eml_scalar_abs";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[10].fileTimeLo = 1286786312U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c2_info[11].name = "eps";
  c2_info[11].dominantType = "char";
  c2_info[11].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[11].fileTimeLo = 1326691996U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[12].name = "eml_is_float_class";
  c2_info[12].dominantType = "char";
  c2_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[12].fileTimeLo = 1286786382U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[13].name = "eml_eps";
  c2_info[13].dominantType = "char";
  c2_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c2_info[13].fileTimeLo = 1326691996U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c2_info[14].name = "eml_float_model";
  c2_info[14].dominantType = "char";
  c2_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c2_info[14].fileTimeLo = 1326691996U;
  c2_info[14].fileTimeHi = 0U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c2_info[15].name = "mtimes";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[15].fileTimeLo = 1289483692U;
  c2_info[15].fileTimeHi = 0U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
  c2_info[16].context = "";
  c2_info[16].name = "abs";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[16].fileTimeLo = 1286786294U;
  c2_info[16].fileTimeHi = 0U;
  c2_info[16].mFileTimeLo = 0U;
  c2_info[16].mFileTimeHi = 0U;
  c2_info[17].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[17].name = "eml_scalar_abs";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[17].fileTimeLo = 1286786312U;
  c2_info[17].fileTimeHi = 0U;
  c2_info[17].mFileTimeLo = 0U;
  c2_info[17].mFileTimeHi = 0U;
}

static void c2_eml_scalar_eg(SFc2_sim_Motor_2kW_openloopInstanceStruct
  *chartInstance)
{
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_openloopInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_e_emlrt_marshallIn(SFc2_sim_Motor_2kW_openloopInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i9;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i9, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i9;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_openloopInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_sim_Motor_2kW_openloopInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_sim_Motor_2kW_openloop, const
  char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_sim_Motor_2kW_openloop), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_sim_Motor_2kW_openloop);
  return c2_y;
}

static uint8_T c2_g_emlrt_marshallIn(SFc2_sim_Motor_2kW_openloopInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_sim_Motor_2kW_openloopInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_sim_Motor_2kW_openloop_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2278690190U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1247500903U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(922344452U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2959596323U);
}

mxArray *sf_c2_sim_Motor_2kW_openloop_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("tDGajjobdo6zVgGpwAvdKH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(6);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_sim_Motor_2kW_openloop(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"ctrl_sig\",},{M[1],M[11],T\"error\",},{M[8],M[0],T\"is_active_c2_sim_Motor_2kW_openloop\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_sim_Motor_2kW_openloop_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance;
    chartInstance = (SFc2_sim_Motor_2kW_openloopInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_sim_Motor_2kW_openloopMachineNumber_,
           2,
           1,
           1,
           7,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_sim_Motor_2kW_openloopMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_sim_Motor_2kW_openloopMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_sim_Motor_2kW_openloopMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"phase_a");
          _SFD_SET_DATA_PROPS(1,2,0,1,"ctrl_sig");
          _SFD_SET_DATA_PROPS(2,1,1,0,"phase_b");
          _SFD_SET_DATA_PROPS(3,1,1,0,"t");
          _SFD_SET_DATA_PROPS(4,2,0,1,"error");
          _SFD_SET_DATA_PROPS(5,1,1,0,"fb_phase_a");
          _SFD_SET_DATA_PROPS(6,1,1,0,"fb_phase_b");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,6,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,4984);
        _SFD_CV_INIT_EML_IF(0,1,0,3775,3800,3858,3911);
        _SFD_CV_INIT_EML_IF(0,1,1,3913,3938,3986,4041);
        _SFD_CV_INIT_EML_IF(0,1,2,4043,4068,4100,4154);
        _SFD_CV_INIT_EML_IF(0,1,3,4364,4380,4420,4441);
        _SFD_CV_INIT_EML_IF(0,1,4,4443,4459,4499,4520);
        _SFD_CV_INIT_EML_IF(0,1,5,4522,4538,4578,4599);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)
            c2_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c2_phase_a;
          real_T *c2_phase_b;
          real_T *c2_t;
          real_T *c2_error;
          real_T *c2_fb_phase_a;
          real_T *c2_fb_phase_b;
          real_T (*c2_ctrl_sig)[6];
          c2_fb_phase_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c2_fb_phase_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_error = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_phase_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_ctrl_sig = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_phase_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_phase_a);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_ctrl_sig);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_phase_b);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_t);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_error);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_fb_phase_a);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_fb_phase_b);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_sim_Motor_2kW_openloopMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "ehDZGiPmx4GHyJu4n6xFEE";
}

static void sf_opaque_initialize_c2_sim_Motor_2kW_openloop(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_sim_Motor_2kW_openloopInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_sim_Motor_2kW_openloop
    ((SFc2_sim_Motor_2kW_openloopInstanceStruct*) chartInstanceVar);
  initialize_c2_sim_Motor_2kW_openloop
    ((SFc2_sim_Motor_2kW_openloopInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_sim_Motor_2kW_openloop(void *chartInstanceVar)
{
  enable_c2_sim_Motor_2kW_openloop((SFc2_sim_Motor_2kW_openloopInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_sim_Motor_2kW_openloop(void *chartInstanceVar)
{
  disable_c2_sim_Motor_2kW_openloop((SFc2_sim_Motor_2kW_openloopInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_sim_Motor_2kW_openloop(void *chartInstanceVar)
{
  sf_c2_sim_Motor_2kW_openloop((SFc2_sim_Motor_2kW_openloopInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_sim_Motor_2kW_openloop
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_sim_Motor_2kW_openloop
    ((SFc2_sim_Motor_2kW_openloopInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_sim_Motor_2kW_openloop();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c2_sim_Motor_2kW_openloop(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_sim_Motor_2kW_openloop();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_sim_Motor_2kW_openloop
    ((SFc2_sim_Motor_2kW_openloopInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_sim_Motor_2kW_openloop
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c2_sim_Motor_2kW_openloop(S);
}

static void sf_opaque_set_sim_state_c2_sim_Motor_2kW_openloop(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c2_sim_Motor_2kW_openloop(S, st);
}

static void sf_opaque_terminate_c2_sim_Motor_2kW_openloop(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_sim_Motor_2kW_openloopInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_sim_Motor_2kW_openloop
      ((SFc2_sim_Motor_2kW_openloopInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_sim_Motor_2kW_openloop_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_sim_Motor_2kW_openloop
    ((SFc2_sim_Motor_2kW_openloopInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_sim_Motor_2kW_openloop(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_sim_Motor_2kW_openloop
      ((SFc2_sim_Motor_2kW_openloopInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_sim_Motor_2kW_openloop(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_sim_Motor_2kW_openloop_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(307500127U));
  ssSetChecksum1(S,(249648732U));
  ssSetChecksum2(S,(4222626877U));
  ssSetChecksum3(S,(1497417054U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_sim_Motor_2kW_openloop(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_sim_Motor_2kW_openloop(SimStruct *S)
{
  SFc2_sim_Motor_2kW_openloopInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_openloopInstanceStruct *)malloc(sizeof
    (SFc2_sim_Motor_2kW_openloopInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_sim_Motor_2kW_openloopInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_sim_Motor_2kW_openloop;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_sim_Motor_2kW_openloop;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_sim_Motor_2kW_openloop;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_sim_Motor_2kW_openloop;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_sim_Motor_2kW_openloop;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_sim_Motor_2kW_openloop;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_sim_Motor_2kW_openloop;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_sim_Motor_2kW_openloop;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_sim_Motor_2kW_openloop;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_sim_Motor_2kW_openloop;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_sim_Motor_2kW_openloop;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c2_sim_Motor_2kW_openloop_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_sim_Motor_2kW_openloop(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_sim_Motor_2kW_openloop(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_sim_Motor_2kW_openloop(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_sim_Motor_2kW_openloop_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
