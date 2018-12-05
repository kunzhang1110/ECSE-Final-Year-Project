/* Include files */

#include "blascompat32.h"
#include "sim_Motor_2kW_closedloop_v6_delay_sfun.h"
#include "c2_sim_Motor_2kW_closedloop_v6_delay.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "sim_Motor_2kW_closedloop_v6_delay_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[31] = { "REF_AMP", "DEAD_TIME",
  "Count_Max", "feedback_c", "FbGain", "feedback_a_scaled", "feedback_b_scaled",
  "feedback_c_scaled", "ref_c", "PropGain", "ctrl_a", "ctrl_b", "ctrl_c",
  "pwm_1", "pwm_2", "pwm_3", "pwm_4", "pwm_5", "pwm_6", "nargin", "nargout",
  "ref_a", "ref_b", "feedback_a", "feedback_b", "Timer_in", "ctrl_sig", "error",
  "counter", "ctrl_stored", "Timer" };

/* Function Declarations */
static void initialize_c2_sim_Motor_2kW_closedloop_v6_delay
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance);
static void initialize_params_c2_sim_Motor_2kW_closedloop_v6_delay
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance);
static void enable_c2_sim_Motor_2kW_closedloop_v6_delay
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance);
static void disable_c2_sim_Motor_2kW_closedloop_v6_delay
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_sim_Motor_2kW_closedloop_v6_delay
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_sim_Motor_2kW_closedloop_v6_delay
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance);
static void set_sim_state_c2_sim_Motor_2kW_closedloop_v6_delay
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, const
   mxArray *c2_st);
static void finalize_c2_sim_Motor_2kW_closedloop_v6_delay
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance);
static void sf_c2_sim_Motor_2kW_closedloop_v6_delay
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance);
static void c2_chartstep_c2_sim_Motor_2kW_closedloop_v6_delay
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance);
static void initSimStructsc2_sim_Motor_2kW_closedloop_v6_delay
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, const
   mxArray *c2_Timer, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, const
   mxArray *c2_ctrl_sig, const char_T *c2_identifier, real_T c2_y[6]);
static void c2_e_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_f_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_g_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, const
   mxArray *c2_b_is_active_c2_sim_Motor_2kW_closedloop_v6_delay, const char_T
   *c2_identifier);
static uint8_T c2_h_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static real_T c2_get_Timer(SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *
  chartInstance, uint32_T c2_b);
static void c2_set_Timer(SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct
  *chartInstance, uint32_T c2_b, real_T c2_c);
static real_T *c2_access_Timer
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, uint32_T
   c2_b);
static real_T c2_get_counter
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, uint32_T
   c2_b);
static void c2_set_counter(SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *
  chartInstance, uint32_T c2_b, real_T c2_c);
static real_T *c2_access_counter
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, uint32_T
   c2_b);
static real_T c2_get_ctrl_stored
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, uint32_T
   c2_b);
static void c2_set_ctrl_stored
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, uint32_T
   c2_b, real_T c2_c);
static real_T *c2_access_ctrl_stored
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, uint32_T
   c2_b);
static void init_dsm_address_info
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_sim_Motor_2kW_closedloop_v6_delay
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_sim_Motor_2kW_closedloop_v6_delay = 0U;
}

static void initialize_params_c2_sim_Motor_2kW_closedloop_v6_delay
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance)
{
}

static void enable_c2_sim_Motor_2kW_closedloop_v6_delay
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_sim_Motor_2kW_closedloop_v6_delay
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_sim_Motor_2kW_closedloop_v6_delay
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_sim_Motor_2kW_closedloop_v6_delay
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance)
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
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = *c2_error;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_b_hoistedGlobal =
    chartInstance->c2_is_active_c2_sim_Motor_2kW_closedloop_v6_delay;
  c2_c_u = c2_b_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_sim_Motor_2kW_closedloop_v6_delay
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, const
   mxArray *c2_st)
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
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
                        "ctrl_sig", c2_dv0);
  for (c2_i1 = 0; c2_i1 < 6; c2_i1++) {
    (*c2_ctrl_sig)[c2_i1] = c2_dv0[c2_i1];
  }

  *c2_error = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    1)), "error");
  chartInstance->c2_is_active_c2_sim_Motor_2kW_closedloop_v6_delay =
    c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
    "is_active_c2_sim_Motor_2kW_closedloop_v6_delay");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_sim_Motor_2kW_closedloop_v6_delay(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_sim_Motor_2kW_closedloop_v6_delay
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance)
{
}

static void sf_c2_sim_Motor_2kW_closedloop_v6_delay
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance)
{
  int32_T c2_i2;
  real_T *c2_ref_a;
  real_T *c2_ref_b;
  real_T *c2_feedback_a;
  real_T *c2_feedback_b;
  real_T *c2_error;
  real_T *c2_Timer_in;
  real_T (*c2_ctrl_sig)[6];
  c2_Timer_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_error = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_feedback_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_feedback_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_ref_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_ctrl_sig = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_ref_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_ref_a, 0U);
  for (c2_i2 = 0; c2_i2 < 6; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*c2_ctrl_sig)[c2_i2], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_ref_b, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_feedback_a, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_feedback_b, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_error, 6U);
  _SFD_DATA_RANGE_CHECK(*c2_Timer_in, 9U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_sim_Motor_2kW_closedloop_v6_delay(chartInstance);
  sf_debug_check_for_state_inconsistency
    (_sim_Motor_2kW_closedloop_v6_delayMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_sim_Motor_2kW_closedloop_v6_delay
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_e_hoistedGlobal;
  real_T c2_ref_a;
  real_T c2_ref_b;
  real_T c2_feedback_a;
  real_T c2_feedback_b;
  real_T c2_Timer_in;
  uint32_T c2_debug_family_var_map[31];
  real_T c2_REF_AMP;
  real_T c2_DEAD_TIME;
  real_T c2_Count_Max;
  real_T c2_feedback_c;
  real_T c2_FbGain;
  real_T c2_feedback_a_scaled;
  real_T c2_feedback_b_scaled;
  real_T c2_feedback_c_scaled;
  real_T c2_ref_c;
  real_T c2_PropGain;
  real_T c2_ctrl_a;
  real_T c2_ctrl_b;
  real_T c2_ctrl_c;
  real_T c2_pwm_1;
  real_T c2_pwm_2;
  real_T c2_pwm_3;
  real_T c2_pwm_4;
  real_T c2_pwm_5;
  real_T c2_pwm_6;
  real_T c2_nargin = 5.0;
  real_T c2_nargout = 2.0;
  real_T c2_ctrl_sig[6];
  real_T c2_error;
  real_T c2_a;
  real_T c2_b_a;
  real_T c2_c_a;
  real_T c2_d_a;
  real_T c2_e_a;
  real_T c2_f_a;
  real_T c2_g_a;
  real_T c2_y;
  real_T c2_A;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_h_a;
  real_T c2_c_y;
  real_T c2_b_A;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_d_y;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_a;
  real_T c2_e_y;
  real_T c2_c_A;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_f_y;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_m_x[3];
  int32_T c2_i3;
  int32_T c2_k;
  real_T c2_b_k;
  real_T c2_n_x;
  real_T c2_o_x;
  int32_T c2_i4;
  int32_T c2_i5;
  real_T c2_u[3];
  const mxArray *c2_g_y = NULL;
  real_T c2_b_pwm_1[6];
  int32_T c2_i6;
  int32_T c2_i7;
  real_T *c2_b_error;
  real_T *c2_b_Timer_in;
  real_T *c2_b_feedback_b;
  real_T *c2_b_feedback_a;
  real_T *c2_b_ref_b;
  real_T *c2_b_ref_a;
  real_T (*c2_b_ctrl_sig)[6];
  boolean_T guard1 = FALSE;
  c2_b_Timer_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_error = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_feedback_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_feedback_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_ref_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_ctrl_sig = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_ref_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_ref_a;
  c2_b_hoistedGlobal = *c2_b_ref_b;
  c2_c_hoistedGlobal = *c2_b_feedback_a;
  c2_d_hoistedGlobal = *c2_b_feedback_b;
  c2_e_hoistedGlobal = *c2_b_Timer_in;
  c2_ref_a = c2_hoistedGlobal;
  c2_ref_b = c2_b_hoistedGlobal;
  c2_feedback_a = c2_c_hoistedGlobal;
  c2_feedback_b = c2_d_hoistedGlobal;
  c2_Timer_in = c2_e_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 31U, 31U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_REF_AMP, 0U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_DEAD_TIME, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_Count_Max, 2U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_feedback_c, 3U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_FbGain, 4U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_feedback_a_scaled, 5U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_feedback_b_scaled, 6U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_feedback_c_scaled, 7U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_ref_c, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_PropGain, 9U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_ctrl_a, 10U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_ctrl_b, 11U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_ctrl_c, 12U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pwm_1, 13U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pwm_2, 14U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pwm_3, 15U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pwm_4, 16U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pwm_5, 17U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pwm_6, 18U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 19U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 20U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_ref_a, 21U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_ref_b, 22U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_feedback_a, 23U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_feedback_b, 24U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Timer_in, 25U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_ctrl_sig, 26U, c2_c_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_error, 27U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c2_counter_address,
    28U, c2_sf_marshallOut, c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable
    (*chartInstance->c2_ctrl_stored_address, 29U, c2_b_sf_marshallOut,
     c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c2_Timer_address, 30U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
  c2_REF_AMP = 2.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 25);
  c2_DEAD_TIME = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
  c2_Count_Max = 100.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
  c2_feedback_c = -c2_feedback_a - c2_feedback_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 29);
  c2_FbGain = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 30);
  c2_a = c2_feedback_a;
  c2_feedback_a_scaled = c2_a * 0.1;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 31);
  c2_b_a = c2_feedback_b;
  c2_feedback_b_scaled = c2_b_a * 0.1;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
  c2_c_a = c2_feedback_c;
  c2_feedback_c_scaled = c2_c_a * 0.1;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
  c2_ref_c = -c2_ref_a - c2_ref_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 35);
  c2_PropGain = 0.78;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 36);
  c2_d_a = c2_ref_a - c2_feedback_a_scaled;
  c2_ctrl_a = c2_d_a * 0.78;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 37);
  c2_e_a = c2_ref_b - c2_feedback_b_scaled;
  c2_ctrl_b = c2_e_a * 0.78;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 38);
  c2_f_a = c2_ref_c - c2_feedback_c_scaled;
  c2_ctrl_c = c2_f_a * 0.78;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 40);
  c2_g_a = c2_ctrl_a + c2_REF_AMP;
  c2_y = c2_g_a * 100.0;
  c2_A = c2_y;
  c2_x = c2_A;
  c2_b_x = c2_x;
  c2_b_y = c2_b_x / 4.0;
  c2_c_x = c2_b_y;
  c2_ctrl_a = c2_c_x;
  c2_d_x = c2_ctrl_a;
  c2_ctrl_a = c2_d_x;
  c2_ctrl_a = muDoubleScalarRound(c2_ctrl_a);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 41);
  c2_h_a = c2_ctrl_b + c2_REF_AMP;
  c2_c_y = c2_h_a * 100.0;
  c2_b_A = c2_c_y;
  c2_e_x = c2_b_A;
  c2_f_x = c2_e_x;
  c2_d_y = c2_f_x / 4.0;
  c2_g_x = c2_d_y;
  c2_ctrl_b = c2_g_x;
  c2_h_x = c2_ctrl_b;
  c2_ctrl_b = c2_h_x;
  c2_ctrl_b = muDoubleScalarRound(c2_ctrl_b);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 42);
  c2_i_a = c2_ctrl_c + c2_REF_AMP;
  c2_e_y = c2_i_a * 100.0;
  c2_c_A = c2_e_y;
  c2_i_x = c2_c_A;
  c2_j_x = c2_i_x;
  c2_f_y = c2_j_x / 4.0;
  c2_k_x = c2_f_y;
  c2_ctrl_c = c2_k_x;
  c2_l_x = c2_ctrl_c;
  c2_ctrl_c = c2_l_x;
  c2_ctrl_c = muDoubleScalarRound(c2_ctrl_c);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 45);
  if (CV_EML_IF(0, 1, 0, c2_get_counter(chartInstance, 0) == c2_Count_Max)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 46);
    c2_m_x[0] = c2_ctrl_a;
    c2_m_x[1] = c2_ctrl_b;
    c2_m_x[2] = c2_ctrl_c;
    for (c2_i3 = 0; c2_i3 < 3; c2_i3++) {
      c2_set_ctrl_stored(chartInstance, c2_i3, c2_m_x[c2_i3]);
    }

    for (c2_k = 0; c2_k < 3; c2_k++) {
      c2_b_k = 1.0 + (real_T)c2_k;
      c2_n_x = c2_get_ctrl_stored(chartInstance, _SFD_EML_ARRAY_BOUNDS_CHECK("",
                                   (int32_T)_SFD_INTEGER_CHECK("", c2_b_k), 1, 3,
        1, 0) - 1);
      c2_o_x = c2_n_x;
      c2_o_x = muDoubleScalarFloor(c2_o_x);
      c2_set_ctrl_stored(chartInstance, _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c2_b_k), 1, 3, 1, 0) - 1, c2_o_x);
    }

    ssUpdateDataStoreLog(chartInstance->S, 2);
    sf_mex_printf("%s =\\n", "ctrl_stored");
    for (c2_i4 = 0; c2_i4 < 3; c2_i4++) {
      c2_m_x[c2_i4] = c2_get_ctrl_stored(chartInstance, c2_i4);
    }

    for (c2_i5 = 0; c2_i5 < 3; c2_i5++) {
      c2_u[c2_i5] = c2_m_x[c2_i5];
    }

    c2_g_y = NULL;
    sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
    sf_mex_call_debug("disp", 0U, 1U, 14, c2_g_y);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 47);
    c2_set_counter(chartInstance, 0, 0.0);
    ssUpdateDataStoreLog(chartInstance->S, 1);
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 51);
  if (CV_EML_IF(0, 1, 1, c2_get_counter(chartInstance, 0) < c2_get_ctrl_stored
                (chartInstance, 0))) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 52);
    c2_pwm_1 = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 52);
    c2_pwm_2 = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 53);
    if (CV_EML_IF(0, 1, 2, c2_get_counter(chartInstance, 0) < c2_get_ctrl_stored
                  (chartInstance, 0) + c2_DEAD_TIME)) {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 54);
      c2_pwm_1 = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 54);
      c2_pwm_2 = 0.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 56);
      c2_pwm_1 = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 56);
      c2_pwm_2 = 1.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 60);
  if (CV_EML_IF(0, 1, 3, c2_get_counter(chartInstance, 0) < c2_get_ctrl_stored
                (chartInstance, 1))) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 61);
    c2_pwm_3 = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 61);
    c2_pwm_4 = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 62);
    if (CV_EML_IF(0, 1, 4, c2_get_counter(chartInstance, 0) < c2_get_ctrl_stored
                  (chartInstance, 1) + c2_DEAD_TIME)) {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 63);
      c2_pwm_3 = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 63);
      c2_pwm_4 = 0.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 65);
      c2_pwm_3 = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 65);
      c2_pwm_4 = 1.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 69);
  if (CV_EML_IF(0, 1, 5, c2_get_counter(chartInstance, 0) + 1.0 <
                c2_get_ctrl_stored(chartInstance, 2))) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 70);
    c2_pwm_5 = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 70);
    c2_pwm_6 = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 71);
    if (CV_EML_IF(0, 1, 6, c2_get_counter(chartInstance, 0) < c2_get_ctrl_stored
                  (chartInstance, 2) + c2_DEAD_TIME)) {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 72);
      c2_pwm_5 = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 72);
      c2_pwm_6 = 0.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 74);
      c2_pwm_5 = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 74);
      c2_pwm_6 = 1.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 77);
  if (CV_EML_IF(0, 1, 7, c2_get_counter(chartInstance, 0) < c2_DEAD_TIME)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 78);
    c2_pwm_1 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 78);
    c2_pwm_2 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 79);
    c2_pwm_3 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 79);
    c2_pwm_4 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 80);
    c2_pwm_5 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 80);
    c2_pwm_6 = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 83);
  guard1 = FALSE;
  if (CV_EML_COND(0, 1, 0, c2_get_Timer(chartInstance, 0) < 0.2)) {
    if (CV_EML_COND(0, 1, 1, c2_Timer_in > 0.8)) {
      CV_EML_MCDC(0, 1, 0, TRUE);
      CV_EML_IF(0, 1, 8, TRUE);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 84);
      c2_set_counter(chartInstance, 0, c2_get_counter(chartInstance, 0) + 1.0);
      ssUpdateDataStoreLog(chartInstance->S, 1);
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(0, 1, 0, FALSE);
    CV_EML_IF(0, 1, 8, FALSE);
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 88);
  c2_b_pwm_1[0] = c2_pwm_1;
  c2_b_pwm_1[1] = c2_pwm_2;
  c2_b_pwm_1[2] = c2_pwm_3;
  c2_b_pwm_1[3] = c2_pwm_4;
  c2_b_pwm_1[4] = c2_pwm_5;
  c2_b_pwm_1[5] = c2_pwm_6;
  for (c2_i6 = 0; c2_i6 < 6; c2_i6++) {
    c2_ctrl_sig[c2_i6] = c2_b_pwm_1[c2_i6];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 89);
  ssUpdateDataStoreLog(chartInstance->S, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 90);
  ssUpdateDataStoreLog(chartInstance->S, 1);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 91);
  c2_error = c2_feedback_a - c2_ref_a;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -91);
  sf_debug_symbol_scope_pop();
  for (c2_i7 = 0; c2_i7 < 6; c2_i7++) {
    (*c2_b_ctrl_sig)[c2_i7] = c2_ctrl_sig[c2_i7];
  }

  *c2_b_error = c2_error;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_sim_Motor_2kW_closedloop_v6_delay
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance)
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
  SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, const
   mxArray *c2_Timer, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Timer), &c2_thisId);
  sf_mex_destroy(&c2_Timer);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
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
  const mxArray *c2_Timer;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *)
    chartInstanceVoid;
  c2_Timer = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Timer), &c2_thisId);
  sf_mex_destroy(&c2_Timer);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i8;
  real_T c2_b_inData[3];
  int32_T c2_i9;
  real_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i8 = 0; c2_i8 < 3; c2_i8++) {
    c2_b_inData[c2_i8] = (*(real_T (*)[3])c2_inData)[c2_i8];
  }

  for (c2_i9 = 0; c2_i9 < 3; c2_i9++) {
    c2_u[c2_i9] = c2_b_inData[c2_i9];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3])
{
  real_T c2_dv1[3];
  int32_T c2_i10;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c2_i10 = 0; c2_i10 < 3; c2_i10++) {
    c2_y[c2_i10] = c2_dv1[c2_i10];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_ctrl_stored;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[3];
  int32_T c2_i11;
  SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *)
    chartInstanceVoid;
  c2_ctrl_stored = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_ctrl_stored), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_ctrl_stored);
  for (c2_i11 = 0; c2_i11 < 3; c2_i11++) {
    (*(real_T (*)[3])c2_outData)[c2_i11] = c2_y[c2_i11];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i12;
  real_T c2_b_inData[6];
  int32_T c2_i13;
  real_T c2_u[6];
  const mxArray *c2_y = NULL;
  SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i12 = 0; c2_i12 < 6; c2_i12++) {
    c2_b_inData[c2_i12] = (*(real_T (*)[6])c2_inData)[c2_i12];
  }

  for (c2_i13 = 0; c2_i13 < 6; c2_i13++) {
    c2_u[c2_i13] = c2_b_inData[c2_i13];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, const
   mxArray *c2_ctrl_sig, const char_T *c2_identifier, real_T c2_y[6])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_ctrl_sig), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_ctrl_sig);
}

static void c2_e_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6])
{
  real_T c2_dv2[6];
  int32_T c2_i14;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv2, 1, 0, 0U, 1, 0U, 1, 6);
  for (c2_i14 = 0; c2_i14 < 6; c2_i14++) {
    c2_y[c2_i14] = c2_dv2[c2_i14];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_ctrl_sig;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[6];
  int32_T c2_i15;
  SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *)
    chartInstanceVoid;
  c2_ctrl_sig = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_ctrl_sig), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_ctrl_sig);
  for (c2_i15 = 0; c2_i15 < 6; c2_i15++) {
    (*(real_T (*)[6])c2_outData)[c2_i15] = c2_y[c2_i15];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray
  *sf_c2_sim_Motor_2kW_closedloop_v6_delay_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[8];
  c2_ResolvedFunctionInfo (*c2_b_info)[8];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i16;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[8])c2_info;
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
  (*c2_b_info)[4].context = "";
  (*c2_b_info)[4].name = "round";
  (*c2_b_info)[4].dominantType = "double";
  (*c2_b_info)[4].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/round.m";
  (*c2_b_info)[4].fileTimeLo = 1286786348U;
  (*c2_b_info)[4].fileTimeHi = 0U;
  (*c2_b_info)[4].mFileTimeLo = 0U;
  (*c2_b_info)[4].mFileTimeHi = 0U;
  (*c2_b_info)[5].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/round.m";
  (*c2_b_info)[5].name = "eml_scalar_round";
  (*c2_b_info)[5].dominantType = "double";
  (*c2_b_info)[5].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  (*c2_b_info)[5].fileTimeLo = 1307622438U;
  (*c2_b_info)[5].fileTimeHi = 0U;
  (*c2_b_info)[5].mFileTimeLo = 0U;
  (*c2_b_info)[5].mFileTimeHi = 0U;
  (*c2_b_info)[6].context = "";
  (*c2_b_info)[6].name = "floor";
  (*c2_b_info)[6].dominantType = "double";
  (*c2_b_info)[6].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c2_b_info)[6].fileTimeLo = 1286786342U;
  (*c2_b_info)[6].fileTimeHi = 0U;
  (*c2_b_info)[6].mFileTimeLo = 0U;
  (*c2_b_info)[6].mFileTimeHi = 0U;
  (*c2_b_info)[7].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c2_b_info)[7].name = "eml_scalar_floor";
  (*c2_b_info)[7].dominantType = "double";
  (*c2_b_info)[7].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  (*c2_b_info)[7].fileTimeLo = 1286786326U;
  (*c2_b_info)[7].fileTimeHi = 0U;
  (*c2_b_info)[7].mFileTimeLo = 0U;
  (*c2_b_info)[7].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 8), FALSE);
  for (c2_i16 = 0; c2_i16 < 8; c2_i16++) {
    c2_r0 = &c2_info[c2_i16];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i16);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i16);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i16);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i16);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i16);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i16);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i16);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i16);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_f_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i17;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i17, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i17;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *)
    chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_g_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, const
   mxArray *c2_b_is_active_c2_sim_Motor_2kW_closedloop_v6_delay, const char_T
   *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_sim_Motor_2kW_closedloop_v6_delay), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_sim_Motor_2kW_closedloop_v6_delay);
  return c2_y;
}

static uint8_T c2_h_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static real_T c2_get_Timer(SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *
  chartInstance, uint32_T c2_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c2_b);
  if (chartInstance->c2_Timer_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'Timer\' (#28) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c2_Timer_address;
}

static void c2_set_Timer(SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct
  *chartInstance, uint32_T c2_b, real_T c2_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c2_b);
  if (chartInstance->c2_Timer_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'Timer\' (#28) in the initialization routine of the chart.\n");
  }

  *chartInstance->c2_Timer_address = c2_c;
}

static real_T *c2_access_Timer
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, uint32_T
   c2_b)
{
  real_T *c2_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c2_Timer_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'Timer\' (#28) in the initialization routine of the chart.\n");
  }

  c2_c = chartInstance->c2_Timer_address;
  if (c2_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c2_c;
}

static real_T c2_get_counter
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, uint32_T
   c2_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c2_b);
  if (chartInstance->c2_counter_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'counter\' (#33) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c2_counter_address;
}

static void c2_set_counter(SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *
  chartInstance, uint32_T c2_b, real_T c2_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c2_b);
  if (chartInstance->c2_counter_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'counter\' (#33) in the initialization routine of the chart.\n");
  }

  *chartInstance->c2_counter_address = c2_c;
}

static real_T *c2_access_counter
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, uint32_T
   c2_b)
{
  real_T *c2_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c2_counter_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'counter\' (#33) in the initialization routine of the chart.\n");
  }

  c2_c = chartInstance->c2_counter_address;
  if (c2_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c2_c;
}

static real_T c2_get_ctrl_stored
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, uint32_T
   c2_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c2_b);
  if (chartInstance->c2_ctrl_stored_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'ctrl_stored\' (#32) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c2_ctrl_stored_address)[c2_b];
}

static void c2_set_ctrl_stored
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, uint32_T
   c2_b, real_T c2_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c2_b);
  if (chartInstance->c2_ctrl_stored_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'ctrl_stored\' (#32) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c2_ctrl_stored_address)[c2_b] = c2_c;
}

static real_T *c2_access_ctrl_stored
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance, uint32_T
   c2_b)
{
  real_T *c2_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c2_ctrl_stored_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'ctrl_stored\' (#32) in the initialization routine of the chart.\n");
  }

  c2_c = *chartInstance->c2_ctrl_stored_address;
  if (c2_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c2_c;
}

static void init_dsm_address_info
  (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "Timer", (void **)
    &chartInstance->c2_Timer_address, &chartInstance->c2_Timer_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "counter", (void **)
    &chartInstance->c2_counter_address, &chartInstance->c2_counter_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "ctrl_stored", (void **)
    &chartInstance->c2_ctrl_stored_address, &chartInstance->c2_ctrl_stored_index);
}

/* SFunction Glue Code */
void sf_c2_sim_Motor_2kW_closedloop_v6_delay_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1309014512U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(335715554U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3129412788U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(566239033U);
}

mxArray *sf_c2_sim_Motor_2kW_closedloop_v6_delay_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("6cR0ZNeU4L1I7ouVDEnnUE");
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
      pr[0] = (double)(6);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_sim_Motor_2kW_closedloop_v6_delay
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"ctrl_sig\",},{M[1],M[34],T\"error\",},{M[8],M[0],T\"is_active_c2_sim_Motor_2kW_closedloop_v6_delay\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_sim_Motor_2kW_closedloop_v6_delay_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance;
    chartInstance = (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_sim_Motor_2kW_closedloop_v6_delayMachineNumber_,
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
            (_sim_Motor_2kW_closedloop_v6_delayMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_sim_Motor_2kW_closedloop_v6_delayMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_sim_Motor_2kW_closedloop_v6_delayMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"ref_a");
          _SFD_SET_DATA_PROPS(1,2,0,1,"ctrl_sig");
          _SFD_SET_DATA_PROPS(2,1,1,0,"ref_b");
          _SFD_SET_DATA_PROPS(3,11,0,0,"Timer");
          _SFD_SET_DATA_PROPS(4,1,1,0,"feedback_a");
          _SFD_SET_DATA_PROPS(5,1,1,0,"feedback_b");
          _SFD_SET_DATA_PROPS(6,2,0,1,"error");
          _SFD_SET_DATA_PROPS(7,11,0,0,"ctrl_stored");
          _SFD_SET_DATA_PROPS(8,11,0,0,"counter");
          _SFD_SET_DATA_PROPS(9,1,1,0,"Timer_in");
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
        _SFD_CV_INIT_EML(0,1,1,9,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,6858);
        _SFD_CV_INIT_EML_IF(0,1,0,4514,4540,-1,4770);
        _SFD_CV_INIT_EML_IF(0,1,1,4779,4809,4956,5257);
        _SFD_CV_INIT_EML_IF(0,1,2,4956,4996,5172,5257);
        _SFD_CV_INIT_EML_IF(0,1,3,5273,5303,5403,5552);
        _SFD_CV_INIT_EML_IF(0,1,4,5403,5443,5494,5552);
        _SFD_CV_INIT_EML_IF(0,1,5,5568,5600,5696,5845);
        _SFD_CV_INIT_EML_IF(0,1,6,5696,5736,5787,5845);
        _SFD_CV_INIT_EML_IF(0,1,7,5847,5872,-1,6224);
        _SFD_CV_INIT_EML_IF(0,1,8,6226,6259,-1,6438);

        {
          static int condStart[] = { 6234, 6247 };

          static int condEnd[] = { 6243, 6259 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,6234,6259,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

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
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)
            c2_c_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)
            c2_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c2_ref_a;
          real_T *c2_ref_b;
          real_T *c2_feedback_a;
          real_T *c2_feedback_b;
          real_T *c2_error;
          real_T *c2_Timer_in;
          real_T (*c2_ctrl_sig)[6];
          c2_Timer_in = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c2_error = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_feedback_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_feedback_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_ref_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_ctrl_sig = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_ref_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_ref_a);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_ctrl_sig);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_ref_b);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c2_Timer_address);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_feedback_a);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_feedback_b);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_error);
          _SFD_SET_DATA_VALUE_PTR(7U, *chartInstance->c2_ctrl_stored_address);
          _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c2_counter_address);
          _SFD_SET_DATA_VALUE_PTR(9U, c2_Timer_in);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_sim_Motor_2kW_closedloop_v6_delayMachineNumber_,
         chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "2IrjdWo8WmZkqiF4RdRjPH";
}

static void sf_opaque_initialize_c2_sim_Motor_2kW_closedloop_v6_delay(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct*) chartInstanceVar
     )->S,0);
  initialize_params_c2_sim_Motor_2kW_closedloop_v6_delay
    ((SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct*) chartInstanceVar);
  initialize_c2_sim_Motor_2kW_closedloop_v6_delay
    ((SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_sim_Motor_2kW_closedloop_v6_delay(void
  *chartInstanceVar)
{
  enable_c2_sim_Motor_2kW_closedloop_v6_delay
    ((SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_sim_Motor_2kW_closedloop_v6_delay(void
  *chartInstanceVar)
{
  disable_c2_sim_Motor_2kW_closedloop_v6_delay
    ((SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_sim_Motor_2kW_closedloop_v6_delay(void
  *chartInstanceVar)
{
  sf_c2_sim_Motor_2kW_closedloop_v6_delay
    ((SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c2_sim_Motor_2kW_closedloop_v6_delay(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_sim_Motor_2kW_closedloop_v6_delay
    ((SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c2_sim_Motor_2kW_closedloop_v6_delay();/* state var info */
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

extern void sf_internal_set_sim_state_c2_sim_Motor_2kW_closedloop_v6_delay
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c2_sim_Motor_2kW_closedloop_v6_delay();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_sim_Motor_2kW_closedloop_v6_delay
    ((SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c2_sim_Motor_2kW_closedloop_v6_delay(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_sim_Motor_2kW_closedloop_v6_delay(S);
}

static void sf_opaque_set_sim_state_c2_sim_Motor_2kW_closedloop_v6_delay
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_sim_Motor_2kW_closedloop_v6_delay(S, st);
}

static void sf_opaque_terminate_c2_sim_Motor_2kW_closedloop_v6_delay(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_sim_Motor_2kW_closedloop_v6_delay
      ((SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_sim_Motor_2kW_closedloop_v6_delay_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_sim_Motor_2kW_closedloop_v6_delay
    ((SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_sim_Motor_2kW_closedloop_v6_delay(SimStruct *
  S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_sim_Motor_2kW_closedloop_v6_delay
      ((SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct*)(((ChartInfoStruct
          *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_sim_Motor_2kW_closedloop_v6_delay(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_sim_Motor_2kW_closedloop_v6_delay_optimization_info();
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
  ssSetChecksum0(S,(3922252779U));
  ssSetChecksum1(S,(805741952U));
  ssSetChecksum2(S,(2494284073U));
  ssSetChecksum3(S,(1974838030U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_sim_Motor_2kW_closedloop_v6_delay(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_sim_Motor_2kW_closedloop_v6_delay(SimStruct *S)
{
  SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct *)malloc
    (sizeof(SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc2_sim_Motor_2kW_closedloop_v6_delayInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_sim_Motor_2kW_closedloop_v6_delay;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_sim_Motor_2kW_closedloop_v6_delay;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_sim_Motor_2kW_closedloop_v6_delay;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_sim_Motor_2kW_closedloop_v6_delay;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_sim_Motor_2kW_closedloop_v6_delay;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_sim_Motor_2kW_closedloop_v6_delay;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_sim_Motor_2kW_closedloop_v6_delay;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_sim_Motor_2kW_closedloop_v6_delay;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_sim_Motor_2kW_closedloop_v6_delay;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c2_sim_Motor_2kW_closedloop_v6_delay;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_sim_Motor_2kW_closedloop_v6_delay;
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

void c2_sim_Motor_2kW_closedloop_v6_delay_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_sim_Motor_2kW_closedloop_v6_delay(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_sim_Motor_2kW_closedloop_v6_delay(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_sim_Motor_2kW_closedloop_v6_delay(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_sim_Motor_2kW_closedloop_v6_delay_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
