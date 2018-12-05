/* Include files */

#include "blascompat32.h"
#include "sim_Motor_2kW_openloop_v2_sfun.h"
#include "c2_sim_Motor_2kW_openloop_v2.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "sim_Motor_2kW_openloop_v2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[26] = { "REF_AMP", "REC_FREQ",
  "REC_PER", "VON", "phase_c", "InitialTime", "D_a", "OffTime", "pwm_1", "pwm_2",
  "pwm_3", "pwm_4", "pwm_5", "pwm_6", "nargin", "nargout", "phase_a", "phase_b",
  "t", "OnPeriod", "tstart", "init_flag", "ctrl_sig", "OnPeriod_out",
  "tstart_out", "init_flag_out" };

/* Function Declarations */
static void initialize_c2_sim_Motor_2kW_openloop_v2
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance);
static void initialize_params_c2_sim_Motor_2kW_openloop_v2
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance);
static void enable_c2_sim_Motor_2kW_openloop_v2
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance);
static void disable_c2_sim_Motor_2kW_openloop_v2
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_sim_Motor_2kW_openloop_v2
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_sim_Motor_2kW_openloop_v2
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance);
static void set_sim_state_c2_sim_Motor_2kW_openloop_v2
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance, const mxArray
   *c2_st);
static void finalize_c2_sim_Motor_2kW_openloop_v2
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance);
static void sf_c2_sim_Motor_2kW_openloop_v2
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance);
static void c2_chartstep_c2_sim_Motor_2kW_openloop_v2
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance);
static void initSimStructsc2_sim_Motor_2kW_openloop_v2
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_sim_Motor_2kW_openloop_v2InstanceStruct
  *chartInstance, const mxArray *c2_init_flag_out, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_sim_Motor_2kW_openloop_v2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn(SFc2_sim_Motor_2kW_openloop_v2InstanceStruct
  *chartInstance, const mxArray *c2_ctrl_sig, const char_T *c2_identifier,
  real_T c2_y[6]);
static void c2_d_emlrt_marshallIn(SFc2_sim_Motor_2kW_openloop_v2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[6]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_e_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_f_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance, const mxArray
   *c2_b_is_active_c2_sim_Motor_2kW_openloop_v2, const char_T *c2_identifier);
static uint8_T c2_g_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_sim_Motor_2kW_openloop_v2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_sim_Motor_2kW_openloop_v2
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_sim_Motor_2kW_openloop_v2 = 0U;
}

static void initialize_params_c2_sim_Motor_2kW_openloop_v2
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance)
{
}

static void enable_c2_sim_Motor_2kW_openloop_v2
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_sim_Motor_2kW_openloop_v2
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_sim_Motor_2kW_openloop_v2
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_sim_Motor_2kW_openloop_v2
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  int32_T c2_i0;
  real_T c2_b_u[6];
  const mxArray *c2_c_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  uint8_T c2_d_hoistedGlobal;
  uint8_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  real_T *c2_OnPeriod_out;
  real_T *c2_init_flag_out;
  real_T *c2_tstart_out;
  real_T (*c2_ctrl_sig)[6];
  c2_init_flag_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_tstart_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_OnPeriod_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_ctrl_sig = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(5), FALSE);
  c2_hoistedGlobal = *c2_OnPeriod_out;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  for (c2_i0 = 0; c2_i0 < 6; c2_i0++) {
    c2_b_u[c2_i0] = (*c2_ctrl_sig)[c2_i0];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 1, 6),
                FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_b_hoistedGlobal = *c2_init_flag_out;
  c2_c_u = c2_b_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_c_hoistedGlobal = *c2_tstart_out;
  c2_d_u = c2_c_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_d_hoistedGlobal = chartInstance->c2_is_active_c2_sim_Motor_2kW_openloop_v2;
  c2_e_u = c2_d_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_sim_Motor_2kW_openloop_v2
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance, const mxArray
   *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[6];
  int32_T c2_i1;
  real_T *c2_OnPeriod_out;
  real_T *c2_init_flag_out;
  real_T *c2_tstart_out;
  real_T (*c2_ctrl_sig)[6];
  c2_init_flag_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_tstart_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_OnPeriod_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_ctrl_sig = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_OnPeriod_out = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 0)), "OnPeriod_out");
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
                        "ctrl_sig", c2_dv0);
  for (c2_i1 = 0; c2_i1 < 6; c2_i1++) {
    (*c2_ctrl_sig)[c2_i1] = c2_dv0[c2_i1];
  }

  *c2_init_flag_out = c2_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 2)), "init_flag_out");
  *c2_tstart_out = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 3)), "tstart_out");
  chartInstance->c2_is_active_c2_sim_Motor_2kW_openloop_v2 =
    c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 4)),
    "is_active_c2_sim_Motor_2kW_openloop_v2");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_sim_Motor_2kW_openloop_v2(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_sim_Motor_2kW_openloop_v2
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance)
{
}

static void sf_c2_sim_Motor_2kW_openloop_v2
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance)
{
  int32_T c2_i2;
  real_T *c2_phase_a;
  real_T *c2_phase_b;
  real_T *c2_t;
  real_T *c2_OnPeriod_out;
  real_T *c2_OnPeriod;
  real_T *c2_tstart;
  real_T *c2_tstart_out;
  real_T *c2_init_flag;
  real_T *c2_init_flag_out;
  real_T (*c2_ctrl_sig)[6];
  c2_init_flag_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_init_flag = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c2_tstart_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_tstart = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_OnPeriod = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_OnPeriod_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
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
  _SFD_DATA_RANGE_CHECK(*c2_OnPeriod_out, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_OnPeriod, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_tstart, 6U);
  _SFD_DATA_RANGE_CHECK(*c2_tstart_out, 7U);
  _SFD_DATA_RANGE_CHECK(*c2_init_flag, 8U);
  _SFD_DATA_RANGE_CHECK(*c2_init_flag_out, 9U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_sim_Motor_2kW_openloop_v2(chartInstance);
  sf_debug_check_for_state_inconsistency
    (_sim_Motor_2kW_openloop_v2MachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void c2_chartstep_c2_sim_Motor_2kW_openloop_v2
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_e_hoistedGlobal;
  real_T c2_f_hoistedGlobal;
  real_T c2_phase_a;
  real_T c2_phase_b;
  real_T c2_t;
  real_T c2_OnPeriod;
  real_T c2_tstart;
  real_T c2_init_flag;
  uint32_T c2_debug_family_var_map[26];
  real_T c2_REF_AMP;
  real_T c2_REC_FREQ;
  real_T c2_REC_PER;
  real_T c2_VON;
  real_T c2_phase_c;
  real_T c2_InitialTime;
  real_T c2_D_a;
  real_T c2_OffTime;
  real_T c2_pwm_1;
  real_T c2_pwm_2;
  real_T c2_pwm_3;
  real_T c2_pwm_4;
  real_T c2_pwm_5;
  real_T c2_pwm_6;
  real_T c2_nargin = 6.0;
  real_T c2_nargout = 4.0;
  real_T c2_ctrl_sig[6];
  real_T c2_OnPeriod_out;
  real_T c2_tstart_out;
  real_T c2_init_flag_out;
  real_T c2_A;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_a;
  int32_T c2_i3;
  real_T *c2_b_init_flag_out;
  real_T *c2_b_tstart_out;
  real_T *c2_b_OnPeriod_out;
  real_T *c2_b_init_flag;
  real_T *c2_b_tstart;
  real_T *c2_b_OnPeriod;
  real_T *c2_b_t;
  real_T *c2_b_phase_b;
  real_T *c2_b_phase_a;
  real_T (*c2_b_ctrl_sig)[6];
  c2_b_init_flag_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_b_init_flag = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c2_b_tstart_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_b_tstart = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_OnPeriod = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_OnPeriod_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_phase_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_ctrl_sig = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_phase_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_phase_a;
  c2_b_hoistedGlobal = *c2_b_phase_b;
  c2_c_hoistedGlobal = *c2_b_t;
  c2_d_hoistedGlobal = *c2_b_OnPeriod;
  c2_e_hoistedGlobal = *c2_b_tstart;
  c2_f_hoistedGlobal = *c2_b_init_flag;
  c2_phase_a = c2_hoistedGlobal;
  c2_phase_b = c2_b_hoistedGlobal;
  c2_t = c2_c_hoistedGlobal;
  c2_OnPeriod = c2_d_hoistedGlobal;
  c2_tstart = c2_e_hoistedGlobal;
  c2_init_flag = c2_f_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 26U, 26U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_REF_AMP, 0U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_REC_FREQ, 1U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_REC_PER, 2U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_VON, 3U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_phase_c, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_InitialTime, 5U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_D_a, 6U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_OffTime, 7U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pwm_1, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pwm_2, 9U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pwm_3, 10U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pwm_4, 11U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pwm_5, 12U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pwm_6, 13U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 14U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 15U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_phase_a, 16U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_phase_b, 17U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_t, 18U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_OnPeriod, 19U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_tstart, 20U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_init_flag, 21U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_ctrl_sig, 22U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_OnPeriod_out, 23U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_tstart_out, 24U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_init_flag_out, 25U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
  c2_REF_AMP = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
  c2_REC_FREQ = 1500.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 25);
  c2_REC_PER = 0.00066666666666666664;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
  c2_VON = 2.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 30);
  c2_phase_a += c2_REF_AMP;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 31);
  c2_phase_b += c2_REF_AMP;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
  c2_phase_c = -c2_phase_a - c2_phase_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 37);
  c2_InitialTime = c2_tstart + c2_REC_PER;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 38);
  c2_A = c2_phase_a;
  c2_x = c2_A;
  c2_b_x = c2_x;
  c2_D_a = c2_b_x / 2.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 39);
  c2_a = c2_D_a;
  c2_OnPeriod = c2_a * 0.00066666666666666664;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 40);
  c2_OffTime = c2_tstart + c2_OnPeriod;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 42);
  if (CV_EML_IF(0, 1, 0, c2_t < c2_InitialTime)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 43);
    if (CV_EML_IF(0, 1, 1, c2_init_flag == 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 44);
      c2_t = c2_tstart;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 44);
      c2_init_flag = 1.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 46);
    if (CV_EML_IF(0, 1, 2, c2_t <= c2_OffTime)) {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 46);
      c2_pwm_1 = c2_VON;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 47);
      c2_pwm_1 = 0.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 52);
  if (CV_EML_IF(0, 1, 3, c2_t > c2_InitialTime)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 53);
    c2_tstart = c2_t;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 54);
    c2_pwm_1 = 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 55);
    if (CV_EML_IF(0, 1, 4, c2_t <= c2_OffTime)) {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 55);
      c2_pwm_1 = c2_VON;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 56);
      c2_pwm_1 = 0.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 61);
  if (CV_EML_IF(0, 1, 5, c2_pwm_1 == 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 61);
    c2_pwm_2 = c2_VON;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 62);
    c2_pwm_2 = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 100);
  c2_pwm_3 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 101);
  c2_pwm_4 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 102);
  c2_pwm_5 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 103);
  c2_pwm_6 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 107);
  c2_OnPeriod_out = c2_OnPeriod;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 108);
  c2_tstart_out = c2_tstart;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 109);
  c2_init_flag_out = c2_init_flag;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 110);
  c2_ctrl_sig[0] = c2_pwm_1;
  c2_ctrl_sig[1] = c2_pwm_2;
  c2_ctrl_sig[2] = c2_pwm_3;
  c2_ctrl_sig[3] = c2_pwm_4;
  c2_ctrl_sig[4] = c2_pwm_5;
  c2_ctrl_sig[5] = c2_pwm_6;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -110);
  sf_debug_symbol_scope_pop();
  for (c2_i3 = 0; c2_i3 < 6; c2_i3++) {
    (*c2_b_ctrl_sig)[c2_i3] = c2_ctrl_sig[c2_i3];
  }

  *c2_b_OnPeriod_out = c2_OnPeriod_out;
  *c2_b_tstart_out = c2_tstart_out;
  *c2_b_init_flag_out = c2_init_flag_out;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_sim_Motor_2kW_openloop_v2
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance)
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
  SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_sim_Motor_2kW_openloop_v2InstanceStruct
  *chartInstance, const mxArray *c2_init_flag_out, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_init_flag_out),
    &c2_thisId);
  sf_mex_destroy(&c2_init_flag_out);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_sim_Motor_2kW_openloop_v2InstanceStruct
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
  const mxArray *c2_init_flag_out;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *)
    chartInstanceVoid;
  c2_init_flag_out = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_init_flag_out),
    &c2_thisId);
  sf_mex_destroy(&c2_init_flag_out);
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
  SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *)
    chartInstanceVoid;
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

static void c2_c_emlrt_marshallIn(SFc2_sim_Motor_2kW_openloop_v2InstanceStruct
  *chartInstance, const mxArray *c2_ctrl_sig, const char_T *c2_identifier,
  real_T c2_y[6])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_ctrl_sig), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_ctrl_sig);
}

static void c2_d_emlrt_marshallIn(SFc2_sim_Motor_2kW_openloop_v2InstanceStruct
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
  SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *)
    chartInstanceVoid;
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

const mxArray *sf_c2_sim_Motor_2kW_openloop_v2_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[4];
  c2_ResolvedFunctionInfo (*c2_b_info)[4];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i8;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[4])c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "mrdivide";
  (*c2_b_info)[0].dominantType = "double";
  (*c2_b_info)[0].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c2_b_info)[0].fileTimeLo = 1325088138U;
  (*c2_b_info)[0].fileTimeHi = 0U;
  (*c2_b_info)[0].mFileTimeLo = 1319697566U;
  (*c2_b_info)[0].mFileTimeHi = 0U;
  (*c2_b_info)[1].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c2_b_info)[1].name = "rdivide";
  (*c2_b_info)[1].dominantType = "double";
  (*c2_b_info)[1].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[1].fileTimeLo = 1286786444U;
  (*c2_b_info)[1].fileTimeHi = 0U;
  (*c2_b_info)[1].mFileTimeLo = 0U;
  (*c2_b_info)[1].mFileTimeHi = 0U;
  (*c2_b_info)[2].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[2].name = "eml_div";
  (*c2_b_info)[2].dominantType = "double";
  (*c2_b_info)[2].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c2_b_info)[2].fileTimeLo = 1313319010U;
  (*c2_b_info)[2].fileTimeHi = 0U;
  (*c2_b_info)[2].mFileTimeLo = 0U;
  (*c2_b_info)[2].mFileTimeHi = 0U;
  (*c2_b_info)[3].context = "";
  (*c2_b_info)[3].name = "mtimes";
  (*c2_b_info)[3].dominantType = "double";
  (*c2_b_info)[3].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c2_b_info)[3].fileTimeLo = 1289483692U;
  (*c2_b_info)[3].fileTimeHi = 0U;
  (*c2_b_info)[3].mFileTimeLo = 0U;
  (*c2_b_info)[3].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 4), FALSE);
  for (c2_i8 = 0; c2_i8 < 4; c2_i8++) {
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

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_e_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
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
  SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *)
    chartInstanceVoid;
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

static uint8_T c2_f_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance, const mxArray
   *c2_b_is_active_c2_sim_Motor_2kW_openloop_v2, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_sim_Motor_2kW_openloop_v2), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_sim_Motor_2kW_openloop_v2);
  return c2_y;
}

static uint8_T c2_g_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance, const mxArray
   *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_sim_Motor_2kW_openloop_v2InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_sim_Motor_2kW_openloop_v2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1014609139U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3098793678U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(977426553U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2350596066U);
}

mxArray *sf_c2_sim_Motor_2kW_openloop_v2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("y43LWDRL1UOqhwFTSpZZ6D");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_sim_Motor_2kW_openloop_v2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[11],T\"OnPeriod_out\",},{M[1],M[5],T\"ctrl_sig\",},{M[1],M[16],T\"init_flag_out\",},{M[1],M[14],T\"tstart_out\",},{M[8],M[0],T\"is_active_c2_sim_Motor_2kW_openloop_v2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_sim_Motor_2kW_openloop_v2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance;
    chartInstance = (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_sim_Motor_2kW_openloop_v2MachineNumber_,
           2,
           1,
           1,
           10,
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
          init_script_number_translation
            (_sim_Motor_2kW_openloop_v2MachineNumber_,chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_sim_Motor_2kW_openloop_v2MachineNumber_,chartInstance->chartNumber,
             1);
          sf_debug_set_chart_event_thresholds
            (_sim_Motor_2kW_openloop_v2MachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"phase_a");
          _SFD_SET_DATA_PROPS(1,2,0,1,"ctrl_sig");
          _SFD_SET_DATA_PROPS(2,1,1,0,"phase_b");
          _SFD_SET_DATA_PROPS(3,1,1,0,"t");
          _SFD_SET_DATA_PROPS(4,2,0,1,"OnPeriod_out");
          _SFD_SET_DATA_PROPS(5,1,1,0,"OnPeriod");
          _SFD_SET_DATA_PROPS(6,1,1,0,"tstart");
          _SFD_SET_DATA_PROPS(7,2,0,1,"tstart_out");
          _SFD_SET_DATA_PROPS(8,1,1,0,"init_flag");
          _SFD_SET_DATA_PROPS(9,2,0,1,"init_flag_out");
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
        _SFD_CV_INIT_EML(0,1,1,6,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,7607);
        _SFD_CV_INIT_EML_IF(0,1,0,4859,4880,-1,5085);
        _SFD_CV_INIT_EML_IF(0,1,1,4890,4910,-1,4976);
        _SFD_CV_INIT_EML_IF(0,1,2,4985,5003,5052,5081);
        _SFD_CV_INIT_EML_IF(0,1,3,5129,5150,5371,5464);
        _SFD_CV_INIT_EML_IF(0,1,4,5371,5393,5439,5464);
        _SFD_CV_INIT_EML_IF(0,1,5,5604,5620,5656,5709);
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
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);

        {
          real_T *c2_phase_a;
          real_T *c2_phase_b;
          real_T *c2_t;
          real_T *c2_OnPeriod_out;
          real_T *c2_OnPeriod;
          real_T *c2_tstart;
          real_T *c2_tstart_out;
          real_T *c2_init_flag;
          real_T *c2_init_flag_out;
          real_T (*c2_ctrl_sig)[6];
          c2_init_flag_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c2_init_flag = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c2_tstart_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c2_tstart = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c2_OnPeriod = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_OnPeriod_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_t = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_phase_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_ctrl_sig = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_phase_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_phase_a);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_ctrl_sig);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_phase_b);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_t);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_OnPeriod_out);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_OnPeriod);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_tstart);
          _SFD_SET_DATA_VALUE_PTR(7U, c2_tstart_out);
          _SFD_SET_DATA_VALUE_PTR(8U, c2_init_flag);
          _SFD_SET_DATA_VALUE_PTR(9U, c2_init_flag_out);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_sim_Motor_2kW_openloop_v2MachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "eR53YkYxItMxCPtYS8fiiC";
}

static void sf_opaque_initialize_c2_sim_Motor_2kW_openloop_v2(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_sim_Motor_2kW_openloop_v2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_sim_Motor_2kW_openloop_v2
    ((SFc2_sim_Motor_2kW_openloop_v2InstanceStruct*) chartInstanceVar);
  initialize_c2_sim_Motor_2kW_openloop_v2
    ((SFc2_sim_Motor_2kW_openloop_v2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_sim_Motor_2kW_openloop_v2(void *chartInstanceVar)
{
  enable_c2_sim_Motor_2kW_openloop_v2
    ((SFc2_sim_Motor_2kW_openloop_v2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_sim_Motor_2kW_openloop_v2(void
  *chartInstanceVar)
{
  disable_c2_sim_Motor_2kW_openloop_v2
    ((SFc2_sim_Motor_2kW_openloop_v2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_sim_Motor_2kW_openloop_v2(void
  *chartInstanceVar)
{
  sf_c2_sim_Motor_2kW_openloop_v2((SFc2_sim_Motor_2kW_openloop_v2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_sim_Motor_2kW_openloop_v2
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_sim_Motor_2kW_openloop_v2
    ((SFc2_sim_Motor_2kW_openloop_v2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_sim_Motor_2kW_openloop_v2();/* state var info */
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

extern void sf_internal_set_sim_state_c2_sim_Motor_2kW_openloop_v2(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_sim_Motor_2kW_openloop_v2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_sim_Motor_2kW_openloop_v2
    ((SFc2_sim_Motor_2kW_openloop_v2InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_sim_Motor_2kW_openloop_v2
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c2_sim_Motor_2kW_openloop_v2(S);
}

static void sf_opaque_set_sim_state_c2_sim_Motor_2kW_openloop_v2(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c2_sim_Motor_2kW_openloop_v2(S, st);
}

static void sf_opaque_terminate_c2_sim_Motor_2kW_openloop_v2(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_sim_Motor_2kW_openloop_v2InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_sim_Motor_2kW_openloop_v2
      ((SFc2_sim_Motor_2kW_openloop_v2InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_sim_Motor_2kW_openloop_v2_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_sim_Motor_2kW_openloop_v2
    ((SFc2_sim_Motor_2kW_openloop_v2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_sim_Motor_2kW_openloop_v2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_sim_Motor_2kW_openloop_v2
      ((SFc2_sim_Motor_2kW_openloop_v2InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_sim_Motor_2kW_openloop_v2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_sim_Motor_2kW_openloop_v2_optimization_info();
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
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,4);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(360863730U));
  ssSetChecksum1(S,(1196828020U));
  ssSetChecksum2(S,(387739571U));
  ssSetChecksum3(S,(2605590982U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_sim_Motor_2kW_openloop_v2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_sim_Motor_2kW_openloop_v2(SimStruct *S)
{
  SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct *)malloc(sizeof
    (SFc2_sim_Motor_2kW_openloop_v2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_sim_Motor_2kW_openloop_v2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_sim_Motor_2kW_openloop_v2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_sim_Motor_2kW_openloop_v2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_sim_Motor_2kW_openloop_v2;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_sim_Motor_2kW_openloop_v2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_sim_Motor_2kW_openloop_v2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_sim_Motor_2kW_openloop_v2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_sim_Motor_2kW_openloop_v2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_sim_Motor_2kW_openloop_v2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_sim_Motor_2kW_openloop_v2;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_sim_Motor_2kW_openloop_v2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_sim_Motor_2kW_openloop_v2;
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

void c2_sim_Motor_2kW_openloop_v2_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_sim_Motor_2kW_openloop_v2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_sim_Motor_2kW_openloop_v2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_sim_Motor_2kW_openloop_v2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_sim_Motor_2kW_openloop_v2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
