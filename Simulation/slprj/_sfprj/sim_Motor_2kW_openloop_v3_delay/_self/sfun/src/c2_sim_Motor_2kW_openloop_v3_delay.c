/* Include files */

#include "blascompat32.h"
#include "sim_Motor_2kW_openloop_v3_delay_sfun.h"
#include "c2_sim_Motor_2kW_openloop_v3_delay.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "sim_Motor_2kW_openloop_v3_delay_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[23] = { "REF_AMP", "DEAD_TIME",
  "Timer_Ratio", "phase_c", "pwm_1", "pwm_2", "pwm_3", "pwm_4", "pwm_5", "pwm_6",
  "nargin", "nargout", "phase_a", "phase_b", "Timer1", "Timer2", "Timer_prev",
  "phase_stored", "counter", "ctrl_sig", "phase_stored_out", "Timer_prev_out",
  "counter_out" };

/* Function Declarations */
static void initialize_c2_sim_Motor_2kW_openloop_v3_delay
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance);
static void initialize_params_c2_sim_Motor_2kW_openloop_v3_delay
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance);
static void enable_c2_sim_Motor_2kW_openloop_v3_delay
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance);
static void disable_c2_sim_Motor_2kW_openloop_v3_delay
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_sim_Motor_2kW_openloop_v3_delay
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_sim_Motor_2kW_openloop_v3_delay
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance);
static void set_sim_state_c2_sim_Motor_2kW_openloop_v3_delay
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance, const
   mxArray *c2_st);
static void finalize_c2_sim_Motor_2kW_openloop_v3_delay
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance);
static void sf_c2_sim_Motor_2kW_openloop_v3_delay
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance);
static void c2_chartstep_c2_sim_Motor_2kW_openloop_v3_delay
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance);
static void initSimStructsc2_sim_Motor_2kW_openloop_v3_delay
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance, const
   mxArray *c2_counter_out, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance, const
   mxArray *c2_Timer_prev_out, const char_T *c2_identifier, real_T c2_y[2]);
static void c2_d_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[2]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_e_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance, const
   mxArray *c2_phase_stored_out, const char_T *c2_identifier, real_T c2_y[3]);
static void c2_f_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_g_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance, const
   mxArray *c2_ctrl_sig, const char_T *c2_identifier, real_T c2_y[6]);
static void c2_h_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6]);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_i_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_j_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance, const
   mxArray *c2_b_is_active_c2_sim_Motor_2kW_openloop_v3_delay, const char_T
   *c2_identifier);
static uint8_T c2_k_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_sim_Motor_2kW_openloop_v3_delay
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_sim_Motor_2kW_openloop_v3_delay = 0U;
}

static void initialize_params_c2_sim_Motor_2kW_openloop_v3_delay
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance)
{
}

static void enable_c2_sim_Motor_2kW_openloop_v3_delay
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_sim_Motor_2kW_openloop_v3_delay
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_sim_Motor_2kW_openloop_v3_delay
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_sim_Motor_2kW_openloop_v3_delay
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[2];
  const mxArray *c2_b_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  int32_T c2_i1;
  real_T c2_c_u[6];
  const mxArray *c2_d_y = NULL;
  int32_T c2_i2;
  real_T c2_d_u[3];
  const mxArray *c2_e_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  real_T *c2_counter_out;
  real_T (*c2_phase_stored_out)[3];
  real_T (*c2_ctrl_sig)[6];
  real_T (*c2_Timer_prev_out)[2];
  c2_counter_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_Timer_prev_out = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_phase_stored_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_ctrl_sig = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(5), FALSE);
  for (c2_i0 = 0; c2_i0 < 2; c2_i0++) {
    c2_u[c2_i0] = (*c2_Timer_prev_out)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = *c2_counter_out;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  for (c2_i1 = 0; c2_i1 < 6; c2_i1++) {
    c2_c_u[c2_i1] = (*c2_ctrl_sig)[c2_i1];
  }

  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  for (c2_i2 = 0; c2_i2 < 3; c2_i2++) {
    c2_d_u[c2_i2] = (*c2_phase_stored_out)[c2_i2];
  }

  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", c2_d_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_b_hoistedGlobal =
    chartInstance->c2_is_active_c2_sim_Motor_2kW_openloop_v3_delay;
  c2_e_u = c2_b_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_sim_Motor_2kW_openloop_v3_delay
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance, const
   mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[2];
  int32_T c2_i3;
  real_T c2_dv1[6];
  int32_T c2_i4;
  real_T c2_dv2[3];
  int32_T c2_i5;
  real_T *c2_counter_out;
  real_T (*c2_Timer_prev_out)[2];
  real_T (*c2_ctrl_sig)[6];
  real_T (*c2_phase_stored_out)[3];
  c2_counter_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_Timer_prev_out = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_phase_stored_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_ctrl_sig = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
                        "Timer_prev_out", c2_dv0);
  for (c2_i3 = 0; c2_i3 < 2; c2_i3++) {
    (*c2_Timer_prev_out)[c2_i3] = c2_dv0[c2_i3];
  }

  *c2_counter_out = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 1)), "counter_out");
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
                        "ctrl_sig", c2_dv1);
  for (c2_i4 = 0; c2_i4 < 6; c2_i4++) {
    (*c2_ctrl_sig)[c2_i4] = c2_dv1[c2_i4];
  }

  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 3)),
                        "phase_stored_out", c2_dv2);
  for (c2_i5 = 0; c2_i5 < 3; c2_i5++) {
    (*c2_phase_stored_out)[c2_i5] = c2_dv2[c2_i5];
  }

  chartInstance->c2_is_active_c2_sim_Motor_2kW_openloop_v3_delay =
    c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 4)),
    "is_active_c2_sim_Motor_2kW_openloop_v3_delay");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_sim_Motor_2kW_openloop_v3_delay(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_sim_Motor_2kW_openloop_v3_delay
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance)
{
}

static void sf_c2_sim_Motor_2kW_openloop_v3_delay
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance)
{
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i10;
  real_T *c2_phase_a;
  real_T *c2_phase_b;
  real_T *c2_Timer1;
  real_T *c2_Timer2;
  real_T *c2_counter;
  real_T *c2_counter_out;
  real_T (*c2_Timer_prev_out)[2];
  real_T (*c2_phase_stored)[3];
  real_T (*c2_Timer_prev)[2];
  real_T (*c2_phase_stored_out)[3];
  real_T (*c2_ctrl_sig)[6];
  c2_counter_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_counter = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c2_Timer_prev_out = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_phase_stored = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 5);
  c2_Timer_prev = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 4);
  c2_Timer2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_Timer1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_phase_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_phase_stored_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_ctrl_sig = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_phase_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_phase_a, 0U);
  for (c2_i6 = 0; c2_i6 < 6; c2_i6++) {
    _SFD_DATA_RANGE_CHECK((*c2_ctrl_sig)[c2_i6], 1U);
  }

  for (c2_i7 = 0; c2_i7 < 3; c2_i7++) {
    _SFD_DATA_RANGE_CHECK((*c2_phase_stored_out)[c2_i7], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_phase_b, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_Timer1, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_Timer2, 5U);
  for (c2_i8 = 0; c2_i8 < 2; c2_i8++) {
    _SFD_DATA_RANGE_CHECK((*c2_Timer_prev)[c2_i8], 6U);
  }

  for (c2_i9 = 0; c2_i9 < 3; c2_i9++) {
    _SFD_DATA_RANGE_CHECK((*c2_phase_stored)[c2_i9], 7U);
  }

  for (c2_i10 = 0; c2_i10 < 2; c2_i10++) {
    _SFD_DATA_RANGE_CHECK((*c2_Timer_prev_out)[c2_i10], 8U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_counter, 9U);
  _SFD_DATA_RANGE_CHECK(*c2_counter_out, 10U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_sim_Motor_2kW_openloop_v3_delay(chartInstance);
  sf_debug_check_for_state_inconsistency
    (_sim_Motor_2kW_openloop_v3_delayMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void c2_chartstep_c2_sim_Motor_2kW_openloop_v3_delay
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_e_hoistedGlobal;
  real_T c2_phase_a;
  real_T c2_phase_b;
  real_T c2_Timer1;
  real_T c2_Timer2;
  int32_T c2_i11;
  real_T c2_Timer_prev[2];
  int32_T c2_i12;
  real_T c2_phase_stored[3];
  real_T c2_counter;
  uint32_T c2_debug_family_var_map[23];
  real_T c2_REF_AMP;
  real_T c2_DEAD_TIME;
  real_T c2_Timer_Ratio;
  real_T c2_phase_c;
  real_T c2_pwm_1;
  real_T c2_pwm_2;
  real_T c2_pwm_3;
  real_T c2_pwm_4;
  real_T c2_pwm_5;
  real_T c2_pwm_6;
  real_T c2_nargin = 7.0;
  real_T c2_nargout = 4.0;
  real_T c2_ctrl_sig[6];
  real_T c2_phase_stored_out[3];
  real_T c2_Timer_prev_out[2];
  real_T c2_counter_out;
  real_T c2_a;
  real_T c2_y;
  real_T c2_A;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_b_a;
  real_T c2_c_y;
  real_T c2_b_A;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_d_y;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_c_a;
  real_T c2_e_y;
  real_T c2_c_A;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_f_y;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_m_x[3];
  int32_T c2_i13;
  int32_T c2_k;
  real_T c2_b_k;
  real_T c2_n_x;
  real_T c2_o_x;
  int32_T c2_i14;
  real_T c2_u[3];
  const mxArray *c2_g_y = NULL;
  int32_T c2_i15;
  real_T c2_b_pwm_1[6];
  int32_T c2_i16;
  real_T c2_b_Timer1[2];
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i20;
  real_T *c2_b_counter_out;
  real_T *c2_b_counter;
  real_T *c2_b_Timer2;
  real_T *c2_c_Timer1;
  real_T *c2_b_phase_b;
  real_T *c2_b_phase_a;
  real_T (*c2_b_ctrl_sig)[6];
  real_T (*c2_b_phase_stored_out)[3];
  real_T (*c2_b_Timer_prev_out)[2];
  real_T (*c2_b_phase_stored)[3];
  real_T (*c2_b_Timer_prev)[2];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  c2_b_counter_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c2_b_counter = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c2_b_Timer_prev_out = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 3);
  c2_b_phase_stored = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 5);
  c2_b_Timer_prev = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_Timer2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_c_Timer1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_phase_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_phase_stored_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S,
    2);
  c2_b_ctrl_sig = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_phase_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_phase_a;
  c2_b_hoistedGlobal = *c2_b_phase_b;
  c2_c_hoistedGlobal = *c2_c_Timer1;
  c2_d_hoistedGlobal = *c2_b_Timer2;
  c2_e_hoistedGlobal = *c2_b_counter;
  c2_phase_a = c2_hoistedGlobal;
  c2_phase_b = c2_b_hoistedGlobal;
  c2_Timer1 = c2_c_hoistedGlobal;
  c2_Timer2 = c2_d_hoistedGlobal;
  for (c2_i11 = 0; c2_i11 < 2; c2_i11++) {
    c2_Timer_prev[c2_i11] = (*c2_b_Timer_prev)[c2_i11];
  }

  for (c2_i12 = 0; c2_i12 < 3; c2_i12++) {
    c2_phase_stored[c2_i12] = (*c2_b_phase_stored)[c2_i12];
  }

  c2_counter = c2_e_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 23U, 23U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_REF_AMP, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_DEAD_TIME, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_Timer_Ratio, 2U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_phase_c, 3U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pwm_1, 4U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pwm_2, 5U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pwm_3, 6U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pwm_4, 7U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pwm_5, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_pwm_6, 9U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 10U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 11U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_phase_a, 12U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_phase_b, 13U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Timer1, 14U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Timer2, 15U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_Timer_prev, 16U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_phase_stored, 17U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_counter, 18U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_ctrl_sig, 19U, c2_d_sf_marshallOut,
    c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_phase_stored_out, 20U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_Timer_prev_out, 21U,
    c2_b_sf_marshallOut, c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_counter_out, 22U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
  c2_REF_AMP = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
  c2_DEAD_TIME = 10.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
  c2_Timer_Ratio = 100.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 25);
  c2_phase_c = -c2_phase_a - c2_phase_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
  c2_a = c2_phase_a + c2_REF_AMP;
  c2_y = c2_a * 100.0;
  c2_A = c2_y;
  c2_x = c2_A;
  c2_b_x = c2_x;
  c2_b_y = c2_b_x / 2.0;
  c2_c_x = c2_b_y;
  c2_phase_a = c2_c_x;
  c2_d_x = c2_phase_a;
  c2_phase_a = c2_d_x;
  c2_phase_a = muDoubleScalarFloor(c2_phase_a);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
  c2_b_a = c2_phase_b + c2_REF_AMP;
  c2_c_y = c2_b_a * 100.0;
  c2_b_A = c2_c_y;
  c2_e_x = c2_b_A;
  c2_f_x = c2_e_x;
  c2_d_y = c2_f_x / 2.0;
  c2_g_x = c2_d_y;
  c2_phase_b = c2_g_x;
  c2_h_x = c2_phase_b;
  c2_phase_b = c2_h_x;
  c2_phase_b = muDoubleScalarFloor(c2_phase_b);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 28);
  c2_c_a = c2_phase_c + c2_REF_AMP;
  c2_e_y = c2_c_a * 100.0;
  c2_c_A = c2_e_y;
  c2_i_x = c2_c_A;
  c2_j_x = c2_i_x;
  c2_f_y = c2_j_x / 2.0;
  c2_k_x = c2_f_y;
  c2_phase_c = c2_k_x;
  c2_l_x = c2_phase_c;
  c2_phase_c = c2_l_x;
  c2_phase_c = muDoubleScalarFloor(c2_phase_c);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 32);
  guard2 = FALSE;
  if (CV_EML_COND(0, 1, 0, c2_Timer_prev[0] < 0.2)) {
    if (CV_EML_COND(0, 1, 1, c2_Timer1 > 0.8)) {
      CV_EML_MCDC(0, 1, 0, TRUE);
      CV_EML_IF(0, 1, 0, TRUE);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 33);
      c2_m_x[0] = c2_phase_a;
      c2_m_x[1] = c2_phase_b;
      c2_m_x[2] = c2_phase_c;
      for (c2_i13 = 0; c2_i13 < 3; c2_i13++) {
        c2_phase_stored_out[c2_i13] = c2_m_x[c2_i13];
      }

      for (c2_k = 0; c2_k < 3; c2_k++) {
        c2_b_k = 1.0 + (real_T)c2_k;
        c2_n_x = c2_phase_stored_out[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c2_b_k), 1, 3, 1, 0) - 1];
        c2_o_x = c2_n_x;
        c2_o_x = muDoubleScalarFloor(c2_o_x);
        c2_phase_stored_out[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c2_b_k), 1, 3, 1, 0) - 1] = c2_o_x;
      }

      sf_mex_printf("%s =\\n", "phase_stored_out");
      for (c2_i14 = 0; c2_i14 < 3; c2_i14++) {
        c2_u[c2_i14] = c2_phase_stored_out[c2_i14];
      }

      c2_g_y = NULL;
      sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3),
                    FALSE);
      sf_mex_call_debug("disp", 0U, 1U, 14, c2_g_y);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 34);
      c2_counter = 0.0;
    } else {
      guard2 = TRUE;
    }
  } else {
    guard2 = TRUE;
  }

  if (guard2 == TRUE) {
    CV_EML_MCDC(0, 1, 0, FALSE);
    CV_EML_IF(0, 1, 0, FALSE);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 36);
    for (c2_i15 = 0; c2_i15 < 3; c2_i15++) {
      c2_phase_stored_out[c2_i15] = c2_phase_stored[c2_i15];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 39);
  guard1 = FALSE;
  if (CV_EML_COND(0, 1, 2, c2_Timer_prev[1] < 0.2)) {
    if (CV_EML_COND(0, 1, 3, c2_Timer2 > 0.8)) {
      CV_EML_MCDC(0, 1, 1, TRUE);
      CV_EML_IF(0, 1, 1, TRUE);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 40);
      c2_counter++;
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(0, 1, 1, FALSE);
    CV_EML_IF(0, 1, 1, FALSE);
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 44);
  if (CV_EML_IF(0, 1, 2, c2_counter < c2_phase_stored[0])) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 45);
    c2_pwm_1 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 45);
    c2_pwm_2 = 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 46);
    if (CV_EML_IF(0, 1, 3, c2_counter - c2_phase_stored[0] < c2_DEAD_TIME)) {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 47);
      c2_pwm_1 = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 47);
      c2_pwm_2 = 0.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 49);
      c2_pwm_1 = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 49);
      c2_pwm_2 = 0.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 53);
  if (CV_EML_IF(0, 1, 4, c2_counter < c2_phase_stored[1])) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 54);
    c2_pwm_3 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 54);
    c2_pwm_4 = 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 55);
    if (CV_EML_IF(0, 1, 5, c2_counter - c2_phase_stored[1] < c2_DEAD_TIME)) {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 56);
      c2_pwm_3 = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 56);
      c2_pwm_4 = 0.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 58);
      c2_pwm_3 = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 58);
      c2_pwm_4 = 0.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 62);
  if (CV_EML_IF(0, 1, 6, c2_counter + 1.0 < c2_phase_stored[2])) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 63);
    c2_pwm_5 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 63);
    c2_pwm_6 = 1.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 64);
    if (CV_EML_IF(0, 1, 7, c2_counter - c2_phase_stored[2] < c2_DEAD_TIME)) {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 65);
      c2_pwm_5 = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 65);
      c2_pwm_6 = 0.0;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 67);
      c2_pwm_5 = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 67);
      c2_pwm_6 = 0.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 70);
  if (CV_EML_IF(0, 1, 8, c2_counter < c2_DEAD_TIME)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 71);
    c2_pwm_1 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 71);
    c2_pwm_2 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 72);
    c2_pwm_3 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 72);
    c2_pwm_5 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 73);
    c2_pwm_5 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 73);
    c2_pwm_6 = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 78);
  c2_b_pwm_1[0] = c2_pwm_1;
  c2_b_pwm_1[1] = c2_pwm_2;
  c2_b_pwm_1[2] = c2_pwm_3;
  c2_b_pwm_1[3] = c2_pwm_4;
  c2_b_pwm_1[4] = c2_pwm_5;
  c2_b_pwm_1[5] = c2_pwm_6;
  for (c2_i16 = 0; c2_i16 < 6; c2_i16++) {
    c2_ctrl_sig[c2_i16] = c2_b_pwm_1[c2_i16];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 79);
  c2_b_Timer1[0] = c2_Timer1;
  c2_b_Timer1[1] = c2_Timer2;
  for (c2_i17 = 0; c2_i17 < 2; c2_i17++) {
    c2_Timer_prev_out[c2_i17] = c2_b_Timer1[c2_i17];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 80);
  c2_counter_out = c2_counter;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -80);
  sf_debug_symbol_scope_pop();
  for (c2_i18 = 0; c2_i18 < 6; c2_i18++) {
    (*c2_b_ctrl_sig)[c2_i18] = c2_ctrl_sig[c2_i18];
  }

  for (c2_i19 = 0; c2_i19 < 3; c2_i19++) {
    (*c2_b_phase_stored_out)[c2_i19] = c2_phase_stored_out[c2_i19];
  }

  for (c2_i20 = 0; c2_i20 < 2; c2_i20++) {
    (*c2_b_Timer_prev_out)[c2_i20] = c2_Timer_prev_out[c2_i20];
  }

  *c2_b_counter_out = c2_counter_out;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_sim_Motor_2kW_openloop_v3_delay
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance)
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
  SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance, const
   mxArray *c2_counter_out, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_counter_out),
    &c2_thisId);
  sf_mex_destroy(&c2_counter_out);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance, const
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
  const mxArray *c2_counter_out;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *)
    chartInstanceVoid;
  c2_counter_out = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_counter_out),
    &c2_thisId);
  sf_mex_destroy(&c2_counter_out);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i21;
  real_T c2_b_inData[2];
  int32_T c2_i22;
  real_T c2_u[2];
  const mxArray *c2_y = NULL;
  SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i21 = 0; c2_i21 < 2; c2_i21++) {
    c2_b_inData[c2_i21] = (*(real_T (*)[2])c2_inData)[c2_i21];
  }

  for (c2_i22 = 0; c2_i22 < 2; c2_i22++) {
    c2_u[c2_i22] = c2_b_inData[c2_i22];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance, const
   mxArray *c2_Timer_prev_out, const char_T *c2_identifier, real_T c2_y[2])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Timer_prev_out), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_Timer_prev_out);
}

static void c2_d_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[2])
{
  real_T c2_dv3[2];
  int32_T c2_i23;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv3, 1, 0, 0U, 1, 0U, 1, 2);
  for (c2_i23 = 0; c2_i23 < 2; c2_i23++) {
    c2_y[c2_i23] = c2_dv3[c2_i23];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Timer_prev_out;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[2];
  int32_T c2_i24;
  SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *)
    chartInstanceVoid;
  c2_Timer_prev_out = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Timer_prev_out), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_Timer_prev_out);
  for (c2_i24 = 0; c2_i24 < 2; c2_i24++) {
    (*(real_T (*)[2])c2_outData)[c2_i24] = c2_y[c2_i24];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i25;
  real_T c2_b_inData[3];
  int32_T c2_i26;
  real_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i25 = 0; c2_i25 < 3; c2_i25++) {
    c2_b_inData[c2_i25] = (*(real_T (*)[3])c2_inData)[c2_i25];
  }

  for (c2_i26 = 0; c2_i26 < 3; c2_i26++) {
    c2_u[c2_i26] = c2_b_inData[c2_i26];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_e_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance, const
   mxArray *c2_phase_stored_out, const char_T *c2_identifier, real_T c2_y[3])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_phase_stored_out),
                        &c2_thisId, c2_y);
  sf_mex_destroy(&c2_phase_stored_out);
}

static void c2_f_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3])
{
  real_T c2_dv4[3];
  int32_T c2_i27;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv4, 1, 0, 0U, 1, 0U, 1, 3);
  for (c2_i27 = 0; c2_i27 < 3; c2_i27++) {
    c2_y[c2_i27] = c2_dv4[c2_i27];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_phase_stored_out;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[3];
  int32_T c2_i28;
  SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *)
    chartInstanceVoid;
  c2_phase_stored_out = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_phase_stored_out),
                        &c2_thisId, c2_y);
  sf_mex_destroy(&c2_phase_stored_out);
  for (c2_i28 = 0; c2_i28 < 3; c2_i28++) {
    (*(real_T (*)[3])c2_outData)[c2_i28] = c2_y[c2_i28];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i29;
  real_T c2_b_inData[6];
  int32_T c2_i30;
  real_T c2_u[6];
  const mxArray *c2_y = NULL;
  SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i29 = 0; c2_i29 < 6; c2_i29++) {
    c2_b_inData[c2_i29] = (*(real_T (*)[6])c2_inData)[c2_i29];
  }

  for (c2_i30 = 0; c2_i30 < 6; c2_i30++) {
    c2_u[c2_i30] = c2_b_inData[c2_i30];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_g_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance, const
   mxArray *c2_ctrl_sig, const char_T *c2_identifier, real_T c2_y[6])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_ctrl_sig), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_ctrl_sig);
}

static void c2_h_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[6])
{
  real_T c2_dv5[6];
  int32_T c2_i31;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv5, 1, 0, 0U, 1, 0U, 1, 6);
  for (c2_i31 = 0; c2_i31 < 6; c2_i31++) {
    c2_y[c2_i31] = c2_dv5[c2_i31];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_ctrl_sig;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[6];
  int32_T c2_i32;
  SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *)
    chartInstanceVoid;
  c2_ctrl_sig = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_ctrl_sig), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_ctrl_sig);
  for (c2_i32 = 0; c2_i32 < 6; c2_i32++) {
    (*(real_T (*)[6])c2_outData)[c2_i32] = c2_y[c2_i32];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray
  *sf_c2_sim_Motor_2kW_openloop_v3_delay_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[6];
  c2_ResolvedFunctionInfo (*c2_b_info)[6];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i33;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[6])c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "mtimes";
  (*c2_b_info)[0].dominantType = "double";
  (*c2_b_info)[0].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c2_b_info)[0].fileTimeLo = 1289483692U;
  (*c2_b_info)[0].fileTimeHi = 0U;
  (*c2_b_info)[0].mFileTimeLo = 0U;
  (*c2_b_info)[0].mFileTimeHi = 0U;
  (*c2_b_info)[1].context = "";
  (*c2_b_info)[1].name = "mrdivide";
  (*c2_b_info)[1].dominantType = "double";
  (*c2_b_info)[1].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c2_b_info)[1].fileTimeLo = 1325088138U;
  (*c2_b_info)[1].fileTimeHi = 0U;
  (*c2_b_info)[1].mFileTimeLo = 1319697566U;
  (*c2_b_info)[1].mFileTimeHi = 0U;
  (*c2_b_info)[2].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c2_b_info)[2].name = "rdivide";
  (*c2_b_info)[2].dominantType = "double";
  (*c2_b_info)[2].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[2].fileTimeLo = 1286786444U;
  (*c2_b_info)[2].fileTimeHi = 0U;
  (*c2_b_info)[2].mFileTimeLo = 0U;
  (*c2_b_info)[2].mFileTimeHi = 0U;
  (*c2_b_info)[3].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[3].name = "eml_div";
  (*c2_b_info)[3].dominantType = "double";
  (*c2_b_info)[3].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c2_b_info)[3].fileTimeLo = 1313319010U;
  (*c2_b_info)[3].fileTimeHi = 0U;
  (*c2_b_info)[3].mFileTimeLo = 0U;
  (*c2_b_info)[3].mFileTimeHi = 0U;
  (*c2_b_info)[4].context = "";
  (*c2_b_info)[4].name = "floor";
  (*c2_b_info)[4].dominantType = "double";
  (*c2_b_info)[4].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c2_b_info)[4].fileTimeLo = 1286786342U;
  (*c2_b_info)[4].fileTimeHi = 0U;
  (*c2_b_info)[4].mFileTimeLo = 0U;
  (*c2_b_info)[4].mFileTimeHi = 0U;
  (*c2_b_info)[5].context =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  (*c2_b_info)[5].name = "eml_scalar_floor";
  (*c2_b_info)[5].dominantType = "double";
  (*c2_b_info)[5].resolved =
    "[ILXE]C:/Program Files/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  (*c2_b_info)[5].fileTimeLo = 1286786326U;
  (*c2_b_info)[5].fileTimeHi = 0U;
  (*c2_b_info)[5].mFileTimeLo = 0U;
  (*c2_b_info)[5].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 6), FALSE);
  for (c2_i33 = 0; c2_i33 < 6; c2_i33++) {
    c2_r0 = &c2_info[c2_i33];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i33);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i33);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i33);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i33);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i33);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i33);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i33);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i33);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_i_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i34;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i34, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i34;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *)
    chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_j_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance, const
   mxArray *c2_b_is_active_c2_sim_Motor_2kW_openloop_v3_delay, const char_T
   *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_sim_Motor_2kW_openloop_v3_delay), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_sim_Motor_2kW_openloop_v3_delay);
  return c2_y;
}

static uint8_T c2_k_emlrt_marshallIn
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info
  (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_sim_Motor_2kW_openloop_v3_delay_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(997641343U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(238129409U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1675922443U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1104026641U);
}

mxArray *sf_c2_sim_Motor_2kW_openloop_v3_delay_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("0mUmKcnJTZhnFBs3dcbCPG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

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
      pr[0] = (double)(2);
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
      pr[0] = (double)(3);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(2);
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

static const mxArray *sf_get_sim_state_info_c2_sim_Motor_2kW_openloop_v3_delay
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[19],T\"Timer_prev_out\",},{M[1],M[25],T\"counter_out\",},{M[1],M[5],T\"ctrl_sig\",},{M[1],M[23],T\"phase_stored_out\",},{M[8],M[0],T\"is_active_c2_sim_Motor_2kW_openloop_v3_delay\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_sim_Motor_2kW_openloop_v3_delay_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance;
    chartInstance = (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_sim_Motor_2kW_openloop_v3_delayMachineNumber_,
           2,
           1,
           1,
           11,
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
            (_sim_Motor_2kW_openloop_v3_delayMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_sim_Motor_2kW_openloop_v3_delayMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_sim_Motor_2kW_openloop_v3_delayMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"phase_a");
          _SFD_SET_DATA_PROPS(1,2,0,1,"ctrl_sig");
          _SFD_SET_DATA_PROPS(2,2,0,1,"phase_stored_out");
          _SFD_SET_DATA_PROPS(3,1,1,0,"phase_b");
          _SFD_SET_DATA_PROPS(4,1,1,0,"Timer1");
          _SFD_SET_DATA_PROPS(5,1,1,0,"Timer2");
          _SFD_SET_DATA_PROPS(6,1,1,0,"Timer_prev");
          _SFD_SET_DATA_PROPS(7,1,1,0,"phase_stored");
          _SFD_SET_DATA_PROPS(8,2,0,1,"Timer_prev_out");
          _SFD_SET_DATA_PROPS(9,1,1,0,"counter");
          _SFD_SET_DATA_PROPS(10,2,0,1,"counter_out");
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
        _SFD_CV_INIT_EML(0,1,1,9,0,0,0,0,4,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,6414);
        _SFD_CV_INIT_EML_IF(0,1,0,4021,4060,4283,4410);
        _SFD_CV_INIT_EML_IF(0,1,1,4412,4451,-1,4626);
        _SFD_CV_INIT_EML_IF(0,1,2,4635,4666,4814,5117);
        _SFD_CV_INIT_EML_IF(0,1,3,4814,4855,5032,5117);
        _SFD_CV_INIT_EML_IF(0,1,4,5133,5164,5264,5414);
        _SFD_CV_INIT_EML_IF(0,1,5,5264,5305,5356,5414);
        _SFD_CV_INIT_EML_IF(0,1,6,5430,5463,5559,5709);
        _SFD_CV_INIT_EML_IF(0,1,7,5559,5600,5651,5709);
        _SFD_CV_INIT_EML_IF(0,1,8,5711,5736,-1,6089);

        {
          static int condStart[] = { 4029, 4050 };

          static int condEnd[] = { 4046, 4060 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,4029,4060,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 4420, 4441 };

          static int condEnd[] = { 4437, 4451 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,4420,4451,2,2,&(condStart[0]),&(condEnd[0]),
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
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)
            c2_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)
            c2_c_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)
            c2_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);

        {
          real_T *c2_phase_a;
          real_T *c2_phase_b;
          real_T *c2_Timer1;
          real_T *c2_Timer2;
          real_T *c2_counter;
          real_T *c2_counter_out;
          real_T (*c2_ctrl_sig)[6];
          real_T (*c2_phase_stored_out)[3];
          real_T (*c2_Timer_prev)[2];
          real_T (*c2_phase_stored)[3];
          real_T (*c2_Timer_prev_out)[2];
          c2_counter_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c2_counter = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c2_Timer_prev_out = (real_T (*)[2])ssGetOutputPortSignal
            (chartInstance->S, 3);
          c2_phase_stored = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S,
            5);
          c2_Timer_prev = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S,
            4);
          c2_Timer2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_Timer1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_phase_b = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_phase_stored_out = (real_T (*)[3])ssGetOutputPortSignal
            (chartInstance->S, 2);
          c2_ctrl_sig = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_phase_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_phase_a);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_ctrl_sig);
          _SFD_SET_DATA_VALUE_PTR(2U, *c2_phase_stored_out);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_phase_b);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_Timer1);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_Timer2);
          _SFD_SET_DATA_VALUE_PTR(6U, *c2_Timer_prev);
          _SFD_SET_DATA_VALUE_PTR(7U, *c2_phase_stored);
          _SFD_SET_DATA_VALUE_PTR(8U, *c2_Timer_prev_out);
          _SFD_SET_DATA_VALUE_PTR(9U, c2_counter);
          _SFD_SET_DATA_VALUE_PTR(10U, c2_counter_out);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_sim_Motor_2kW_openloop_v3_delayMachineNumber_,
         chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "EaKbDwoMyAkn3CiP4D9KsD";
}

static void sf_opaque_initialize_c2_sim_Motor_2kW_openloop_v3_delay(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct*) chartInstanceVar)->S,
     0);
  initialize_params_c2_sim_Motor_2kW_openloop_v3_delay
    ((SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct*) chartInstanceVar);
  initialize_c2_sim_Motor_2kW_openloop_v3_delay
    ((SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_sim_Motor_2kW_openloop_v3_delay(void
  *chartInstanceVar)
{
  enable_c2_sim_Motor_2kW_openloop_v3_delay
    ((SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_sim_Motor_2kW_openloop_v3_delay(void
  *chartInstanceVar)
{
  disable_c2_sim_Motor_2kW_openloop_v3_delay
    ((SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_sim_Motor_2kW_openloop_v3_delay(void
  *chartInstanceVar)
{
  sf_c2_sim_Motor_2kW_openloop_v3_delay
    ((SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c2_sim_Motor_2kW_openloop_v3_delay(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_sim_Motor_2kW_openloop_v3_delay
    ((SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_sim_Motor_2kW_openloop_v3_delay();/* state var info */
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

extern void sf_internal_set_sim_state_c2_sim_Motor_2kW_openloop_v3_delay
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_sim_Motor_2kW_openloop_v3_delay();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_sim_Motor_2kW_openloop_v3_delay
    ((SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_sim_Motor_2kW_openloop_v3_delay
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c2_sim_Motor_2kW_openloop_v3_delay(S);
}

static void sf_opaque_set_sim_state_c2_sim_Motor_2kW_openloop_v3_delay(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_sim_Motor_2kW_openloop_v3_delay(S, st);
}

static void sf_opaque_terminate_c2_sim_Motor_2kW_openloop_v3_delay(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_sim_Motor_2kW_openloop_v3_delay
      ((SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_sim_Motor_2kW_openloop_v3_delay_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_sim_Motor_2kW_openloop_v3_delay
    ((SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_sim_Motor_2kW_openloop_v3_delay(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_sim_Motor_2kW_openloop_v3_delay
      ((SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_sim_Motor_2kW_openloop_v3_delay(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_sim_Motor_2kW_openloop_v3_delay_optimization_info
      ();
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
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,7);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,4);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(437308825U));
  ssSetChecksum1(S,(468486974U));
  ssSetChecksum2(S,(2104495917U));
  ssSetChecksum3(S,(2208157848U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_sim_Motor_2kW_openloop_v3_delay(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_sim_Motor_2kW_openloop_v3_delay(SimStruct *S)
{
  SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *chartInstance;
  chartInstance = (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct *)malloc
    (sizeof(SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc2_sim_Motor_2kW_openloop_v3_delayInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_sim_Motor_2kW_openloop_v3_delay;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_sim_Motor_2kW_openloop_v3_delay;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_sim_Motor_2kW_openloop_v3_delay;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_sim_Motor_2kW_openloop_v3_delay;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_sim_Motor_2kW_openloop_v3_delay;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_sim_Motor_2kW_openloop_v3_delay;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_sim_Motor_2kW_openloop_v3_delay;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_sim_Motor_2kW_openloop_v3_delay;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_sim_Motor_2kW_openloop_v3_delay;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c2_sim_Motor_2kW_openloop_v3_delay;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_sim_Motor_2kW_openloop_v3_delay;
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

void c2_sim_Motor_2kW_openloop_v3_delay_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_sim_Motor_2kW_openloop_v3_delay(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_sim_Motor_2kW_openloop_v3_delay(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_sim_Motor_2kW_openloop_v3_delay(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_sim_Motor_2kW_openloop_v3_delay_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
