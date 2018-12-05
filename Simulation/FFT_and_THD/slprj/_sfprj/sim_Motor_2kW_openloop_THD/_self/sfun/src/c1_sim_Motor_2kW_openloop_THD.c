/* Include files */

#include "blascompat32.h"
#include "sim_Motor_2kW_openloop_THD_sfun.h"
#include "c1_sim_Motor_2kW_openloop_THD.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "sim_Motor_2kW_openloop_THD_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[16] = { "fd_frequency", "fs", "ts",
  "L", "i", "data_f", "datavec", "N", "Y", "f", "Y_mag", "dis_b", "nargin",
  "nargout", "stored_out", "THD" };

/* Function Declarations */
static void initialize_c1_sim_Motor_2kW_openloop_THD
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance);
static void initialize_params_c1_sim_Motor_2kW_openloop_THD
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance);
static void enable_c1_sim_Motor_2kW_openloop_THD
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance);
static void disable_c1_sim_Motor_2kW_openloop_THD
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_sim_Motor_2kW_openloop_THD
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_sim_Motor_2kW_openloop_THD
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance);
static void set_sim_state_c1_sim_Motor_2kW_openloop_THD
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance, const mxArray
   *c1_st);
static void finalize_c1_sim_Motor_2kW_openloop_THD
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance);
static void sf_c1_sim_Motor_2kW_openloop_THD
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance);
static void c1_chartstep_c1_sim_Motor_2kW_openloop_THD
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance);
static void initSimStructsc1_sim_Motor_2kW_openloop_THD
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *
  chartInstance, const mxArray *c1_THD, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_c_emlrt_marshallIn(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[513]);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_d_emlrt_marshallIn(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  creal_T c1_y[1024]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_e_emlrt_marshallIn(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[576]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[155]);
static void c1_b_info_helper(c1_ResolvedFunctionInfo c1_info[155]);
static void c1_c_info_helper(c1_ResolvedFunctionInfo c1_info[155]);
static void c1_eml_const_nonsingleton_dim
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance);
static void c1_fft(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance,
                   real_T c1_x, creal_T c1_y[1024]);
static real_T c1_permute(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct
  *chartInstance, real_T c1_a);
static void c1_eml_fft(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct
  *chartInstance, real_T c1_x, creal_T c1_y[1024]);
static void c1_eml_assert_valid_dim
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance);
static void c1_eml_scalar_eg(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct
  *chartInstance);
static void c1_check_forloop_overflow_error
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance);
static void c1_ipermute(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct
  *chartInstance, creal_T c1_b[1024], creal_T c1_a[1024]);
static void c1_abs(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance,
                   creal_T c1_x[513], real_T c1_y[513]);
static void c1_b_abs(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct
                     *chartInstance, real_T c1_x[513], real_T c1_y[513]);
static void c1_eml_li_find(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct
  *chartInstance, boolean_T c1_x[513], int32_T c1_y_data[513], int32_T
  c1_y_sizes[2]);
static real_T c1_norm(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct
                      *chartInstance, real_T c1_x[575]);
static real_T c1_b_norm(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct
  *chartInstance, real_T c1_x);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_f_emlrt_marshallIn
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_g_emlrt_marshallIn
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance, const mxArray
   *c1_b_is_active_c1_sim_Motor_2kW_openloop_THD, const char_T *c1_identifier);
static uint8_T c1_h_emlrt_marshallIn
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c1_sim_Motor_2kW_openloop_THD
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_sim_Motor_2kW_openloop_THD = 0U;
}

static void initialize_params_c1_sim_Motor_2kW_openloop_THD
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance)
{
}

static void enable_c1_sim_Motor_2kW_openloop_THD
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_sim_Motor_2kW_openloop_THD
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_sim_Motor_2kW_openloop_THD
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_sim_Motor_2kW_openloop_THD
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  uint8_T c1_b_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T *c1_THD;
  c1_THD = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2), FALSE);
  c1_hoistedGlobal = *c1_THD;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = chartInstance->c1_is_active_c1_sim_Motor_2kW_openloop_THD;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_sim_Motor_2kW_openloop_THD
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance, const mxArray
   *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_THD;
  c1_THD = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_THD = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
    "THD");
  chartInstance->c1_is_active_c1_sim_Motor_2kW_openloop_THD =
    c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
    "is_active_c1_sim_Motor_2kW_openloop_THD");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_sim_Motor_2kW_openloop_THD(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_sim_Motor_2kW_openloop_THD
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance)
{
}

static void sf_c1_sim_Motor_2kW_openloop_THD
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance)
{
  real_T *c1_THD;
  real_T *c1_stored_out;
  c1_stored_out = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_THD = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_THD, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_stored_out, 1U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_sim_Motor_2kW_openloop_THD(chartInstance);
  sf_debug_check_for_state_inconsistency
    (_sim_Motor_2kW_openloop_THDMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void c1_chartstep_c1_sim_Motor_2kW_openloop_THD
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_stored_out;
  uint32_T c1_debug_family_var_map[16];
  real_T c1_fd_frequency;
  real_T c1_fs;
  real_T c1_ts;
  real_T c1_L;
  real_T c1_i;
  real_T c1_data_f[576];
  real_T c1_datavec[576];
  real_T c1_N;
  creal_T c1_Y[1024];
  real_T c1_f[513];
  real_T c1_Y_mag[513];
  real_T c1_dis_b;
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  real_T c1_THD;
  int32_T c1_i0;
  int32_T c1_i1;
  creal_T c1_dcv0[1024];
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  creal_T c1_b_Y[513];
  real_T c1_b[513];
  int32_T c1_i5;
  real_T c1_b_b;
  real_T c1_y;
  real_T c1_a;
  real_T c1_b_y;
  int32_T c1_i6;
  real_T c1_b_f[513];
  int32_T c1_i7;
  boolean_T c1_c_b[513];
  int32_T c1_tmp_sizes[2];
  int32_T c1_tmp_data[513];
  int32_T c1_b_tmp_sizes[2];
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_loop_ub;
  int32_T c1_i10;
  real_T c1_b_tmp_data[513];
  real_T c1_d_b;
  real_T c1_c_y;
  real_T c1_b_a;
  real_T c1_d_y;
  int32_T c1_i11;
  real_T c1_c_f[513];
  int32_T c1_i12;
  boolean_T c1_e_b[513];
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_b_loop_ub;
  int32_T c1_i15;
  int32_T c1_i16;
  real_T c1_b_datavec[575];
  real_T c1_A;
  real_T c1_B;
  real_T c1_x;
  real_T c1_e_y;
  real_T c1_b_x;
  real_T c1_f_y;
  real_T c1_u;
  const mxArray *c1_g_y = NULL;
  real_T *c1_b_stored_out;
  real_T *c1_b_THD;
  c1_b_stored_out = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c1_b_THD = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_stored_out;
  c1_stored_out = c1_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 16U, 16U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c1_fd_frequency, 0U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_fs, 1U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_ts, 2U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_L, 3U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_i, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_data_f, 5U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_datavec, 6U, c1_d_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_N, 7U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_Y, 8U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_f, 9U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_Y_mag, 10U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_dis_b, 11U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 12U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 13U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_stored_out, 14U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_THD, 15U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
  c1_fd_frequency = 50.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  c1_fs = 9600.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
  c1_ts = 0.06;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
  c1_L = 576.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
  c1_i = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 19);
  for (c1_i0 = 0; c1_i0 < 576; c1_i0++) {
    c1_data_f[c1_i0] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
  for (c1_i1 = 0; c1_i1 < 576; c1_i1++) {
    c1_datavec[c1_i1] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
  c1_N = 1024.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
  c1_fft(chartInstance, c1_stored_out, c1_dcv0);
  for (c1_i2 = 0; c1_i2 < 1024; c1_i2++) {
    c1_Y[c1_i2] = c1_dcv0[c1_i2];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 25);
  for (c1_i3 = 0; c1_i3 < 513; c1_i3++) {
    c1_f[c1_i3] = 9.375 * (real_T)c1_i3;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 26);
  for (c1_i4 = 0; c1_i4 < 513; c1_i4++) {
    c1_b_Y[c1_i4] = c1_Y[c1_i4];
  }

  c1_abs(chartInstance, c1_b_Y, c1_b);
  for (c1_i5 = 0; c1_i5 < 513; c1_i5++) {
    c1_Y_mag[c1_i5] = 2.0 * c1_b[c1_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 27);
  c1_dis_b = 9.375;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 29);
  while (CV_EML_WHILE(0, 1, 0, c1_i <= 10.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 30);
    c1_b_b = c1_i;
    c1_y = 2.0 * c1_b_b;
    c1_a = c1_y - 1.0;
    c1_b_y = c1_a * 50.0;
    for (c1_i6 = 0; c1_i6 < 513; c1_i6++) {
      c1_b_f[c1_i6] = c1_f[c1_i6] - c1_b_y;
    }

    c1_b_abs(chartInstance, c1_b_f, c1_b);
    for (c1_i7 = 0; c1_i7 < 513; c1_i7++) {
      c1_c_b[c1_i7] = (c1_b[c1_i7] < 4.6875);
    }

    c1_eml_li_find(chartInstance, c1_c_b, c1_tmp_data, c1_tmp_sizes);
    c1_b_tmp_sizes[0] = 1;
    c1_b_tmp_sizes[1] = c1_tmp_sizes[1];
    c1_i8 = c1_b_tmp_sizes[0];
    c1_i9 = c1_b_tmp_sizes[1];
    c1_loop_ub = c1_tmp_sizes[0] * c1_tmp_sizes[1] - 1;
    for (c1_i10 = 0; c1_i10 <= c1_loop_ub; c1_i10++) {
      c1_b_tmp_data[c1_i10] = c1_f[c1_tmp_data[c1_i10] - 1];
    }

    sf_debug_size_eq_check_1d(1, c1_b_tmp_sizes[1]);
    _SFD_EML_ARRAY_BOUNDS_CHECK(
      "data_f(i)= f(abs(f-(2*i-1)*fd_frequency)<dis_b/2)", 1, 1, c1_b_tmp_sizes
      [1], 2, 0);
    c1_data_f[(int32_T)c1_i - 1] = c1_b_tmp_data[0];
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 31);
    c1_d_b = c1_i;
    c1_c_y = 2.0 * c1_d_b;
    c1_b_a = c1_c_y - 1.0;
    c1_d_y = c1_b_a * 50.0;
    for (c1_i11 = 0; c1_i11 < 513; c1_i11++) {
      c1_c_f[c1_i11] = c1_f[c1_i11] - c1_d_y;
    }

    c1_b_abs(chartInstance, c1_c_f, c1_b);
    for (c1_i12 = 0; c1_i12 < 513; c1_i12++) {
      c1_e_b[c1_i12] = (c1_b[c1_i12] < 4.6875);
    }

    c1_eml_li_find(chartInstance, c1_e_b, c1_tmp_data, c1_tmp_sizes);
    c1_b_tmp_sizes[0] = 1;
    c1_b_tmp_sizes[1] = c1_tmp_sizes[1];
    c1_i13 = c1_b_tmp_sizes[0];
    c1_i14 = c1_b_tmp_sizes[1];
    c1_b_loop_ub = c1_tmp_sizes[0] * c1_tmp_sizes[1] - 1;
    for (c1_i15 = 0; c1_i15 <= c1_b_loop_ub; c1_i15++) {
      c1_b_tmp_data[c1_i15] = c1_Y_mag[c1_tmp_data[c1_i15] - 1];
    }

    sf_debug_size_eq_check_1d(1, c1_b_tmp_sizes[1]);
    _SFD_EML_ARRAY_BOUNDS_CHECK(
      "datavec(i)= Y_mag(abs(f-(2*i-1)*fd_frequency)<dis_b/2)", 1, 1,
      c1_b_tmp_sizes[1], 2, 0);
    c1_datavec[(int32_T)c1_i - 1] = c1_b_tmp_data[0];
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 32);
    c1_i++;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 29);
    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 34);
  for (c1_i16 = 0; c1_i16 < 575; c1_i16++) {
    c1_b_datavec[c1_i16] = c1_datavec[c1_i16 + 1];
  }

  c1_A = c1_norm(chartInstance, c1_b_datavec);
  c1_B = c1_b_norm(chartInstance, c1_datavec[0]);
  c1_x = c1_A;
  c1_e_y = c1_B;
  c1_b_x = c1_x;
  c1_f_y = c1_e_y;
  c1_THD = c1_b_x / c1_f_y;
  sf_mex_printf("%s =\\n", "THD");
  c1_u = c1_THD;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("disp", 0U, 1U, 14, c1_g_y);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -34);
  sf_debug_symbol_scope_pop();
  *c1_b_THD = c1_THD;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_sim_Motor_2kW_openloop_THD
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance;
  chartInstance = (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *
  chartInstance, const mxArray *c1_THD, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_THD), &c1_thisId);
  sf_mex_destroy(&c1_THD);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_THD;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance;
  chartInstance = (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *)
    chartInstanceVoid;
  c1_THD = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_THD), &c1_thisId);
  sf_mex_destroy(&c1_THD);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i17;
  real_T c1_b_inData[513];
  int32_T c1_i18;
  real_T c1_u[513];
  const mxArray *c1_y = NULL;
  SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance;
  chartInstance = (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i17 = 0; c1_i17 < 513; c1_i17++) {
    c1_b_inData[c1_i17] = (*(real_T (*)[513])c1_inData)[c1_i17];
  }

  for (c1_i18 = 0; c1_i18 < 513; c1_i18++) {
    c1_u[c1_i18] = c1_b_inData[c1_i18];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 513), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[513])
{
  real_T c1_dv0[513];
  int32_T c1_i19;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                513);
  for (c1_i19 = 0; c1_i19 < 513; c1_i19++) {
    c1_y[c1_i19] = c1_dv0[c1_i19];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Y_mag;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[513];
  int32_T c1_i20;
  SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance;
  chartInstance = (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *)
    chartInstanceVoid;
  c1_Y_mag = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Y_mag), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Y_mag);
  for (c1_i20 = 0; c1_i20 < 513; c1_i20++) {
    (*(real_T (*)[513])c1_outData)[c1_i20] = c1_y[c1_i20];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i21;
  creal_T c1_b_inData[1024];
  int32_T c1_i22;
  creal_T c1_u[1024];
  const mxArray *c1_y = NULL;
  SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance;
  chartInstance = (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i21 = 0; c1_i21 < 1024; c1_i21++) {
    c1_b_inData[c1_i21] = (*(creal_T (*)[1024])c1_inData)[c1_i21];
  }

  for (c1_i22 = 0; c1_i22 < 1024; c1_i22++) {
    c1_u[c1_i22] = c1_b_inData[c1_i22];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 1U, 1U, 0U, 2, 1, 1024),
                FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_d_emlrt_marshallIn(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  creal_T c1_y[1024])
{
  creal_T c1_dcv1[1024];
  int32_T c1_i23;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dcv1, 1, 0, 1U, 1, 0U, 2, 1,
                1024);
  for (c1_i23 = 0; c1_i23 < 1024; c1_i23++) {
    c1_y[c1_i23] = c1_dcv1[c1_i23];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Y;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  creal_T c1_y[1024];
  int32_T c1_i24;
  SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance;
  chartInstance = (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *)
    chartInstanceVoid;
  c1_Y = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Y), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Y);
  for (c1_i24 = 0; c1_i24 < 1024; c1_i24++) {
    (*(creal_T (*)[1024])c1_outData)[c1_i24] = c1_y[c1_i24];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i25;
  real_T c1_b_inData[576];
  int32_T c1_i26;
  real_T c1_u[576];
  const mxArray *c1_y = NULL;
  SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance;
  chartInstance = (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i25 = 0; c1_i25 < 576; c1_i25++) {
    c1_b_inData[c1_i25] = (*(real_T (*)[576])c1_inData)[c1_i25];
  }

  for (c1_i26 = 0; c1_i26 < 576; c1_i26++) {
    c1_u[c1_i26] = c1_b_inData[c1_i26];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 576), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_e_emlrt_marshallIn(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[576])
{
  real_T c1_dv1[576];
  int32_T c1_i27;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv1, 1, 0, 0U, 1, 0U, 2, 1,
                576);
  for (c1_i27 = 0; c1_i27 < 576; c1_i27++) {
    c1_y[c1_i27] = c1_dv1[c1_i27];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_datavec;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[576];
  int32_T c1_i28;
  SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance;
  chartInstance = (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *)
    chartInstanceVoid;
  c1_datavec = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_datavec), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_datavec);
  for (c1_i28 = 0; c1_i28 < 576; c1_i28++) {
    (*(real_T (*)[576])c1_outData)[c1_i28] = c1_y[c1_i28];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_sim_Motor_2kW_openloop_THD_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[155];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i29;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  c1_b_info_helper(c1_info);
  c1_c_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 155), FALSE);
  for (c1_i29 = 0; c1_i29 < 155; c1_i29++) {
    c1_r0 = &c1_info[c1_i29];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i29);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i29);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i29);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i29);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i29);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i29);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i29);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i29);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[155])
{
  c1_info[0].context = "";
  c1_info[0].name = "mtimes";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[0].fileTimeLo = 1289483692U;
  c1_info[0].fileTimeHi = 0U;
  c1_info[0].mFileTimeLo = 0U;
  c1_info[0].mFileTimeHi = 0U;
  c1_info[1].context = "";
  c1_info[1].name = "nextpow2";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/nextpow2.m";
  c1_info[1].fileTimeLo = 1326691996U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/nextpow2.m!eml_scalar_nextpow2";
  c1_info[2].name = "abs";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[2].fileTimeLo = 1286786294U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[3].name = "eml_scalar_abs";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[3].fileTimeLo = 1286786312U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/nextpow2.m!eml_scalar_nextpow2";
  c1_info[4].name = "isfinite";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[4].fileTimeLo = 1286786358U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[5].name = "isinf";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c1_info[5].fileTimeLo = 1286786360U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[6].name = "isnan";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[6].fileTimeLo = 1286786360U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/nextpow2.m!eml_scalar_nextpow2";
  c1_info[7].name = "log2";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log2.m";
  c1_info[7].fileTimeLo = 1326691996U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log2.m!scalar_frexp";
  c1_info[8].name = "isfinite";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c1_info[8].fileTimeLo = 1286786358U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context = "";
  c1_info[9].name = "mpower";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[9].fileTimeLo = 1286786442U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[10].name = "power";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[10].fileTimeLo = 1336493296U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[11].name = "eml_scalar_eg";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[11].fileTimeLo = 1286786396U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[12].name = "eml_scalexp_alloc";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[12].fileTimeLo = 1330572434U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  c1_info[13].name = "floor";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[13].fileTimeLo = 1286786342U;
  c1_info[13].fileTimeHi = 0U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
  c1_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[14].name = "eml_scalar_floor";
  c1_info[14].dominantType = "double";
  c1_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[14].fileTimeLo = 1286786326U;
  c1_info[14].fileTimeHi = 0U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
  c1_info[15].context = "";
  c1_info[15].name = "fft";
  c1_info[15].dominantType = "double";
  c1_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/fft.m";
  c1_info[15].fileTimeLo = 1286786288U;
  c1_info[15].fileTimeHi = 0U;
  c1_info[15].mFileTimeLo = 0U;
  c1_info[15].mFileTimeHi = 0U;
  c1_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/fft.m";
  c1_info[16].name = "eml_fft";
  c1_info[16].dominantType = "char";
  c1_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m";
  c1_info[16].fileTimeLo = 1286786374U;
  c1_info[16].fileTimeHi = 0U;
  c1_info[16].mFileTimeLo = 0U;
  c1_info[16].mFileTimeHi = 0U;
  c1_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m";
  c1_info[17].name = "eml_const_nonsingleton_dim";
  c1_info[17].dominantType = "double";
  c1_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c1_info[17].fileTimeLo = 1286786296U;
  c1_info[17].fileTimeHi = 0U;
  c1_info[17].mFileTimeLo = 0U;
  c1_info[17].mFileTimeHi = 0U;
  c1_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m";
  c1_info[18].name = "eml_size_ispow2";
  c1_info[18].dominantType = "double";
  c1_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_ispow2.m";
  c1_info[18].fileTimeLo = 1286786398U;
  c1_info[18].fileTimeHi = 0U;
  c1_info[18].mFileTimeLo = 0U;
  c1_info[18].mFileTimeHi = 0U;
  c1_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_ispow2.m";
  c1_info[19].name = "floor";
  c1_info[19].dominantType = "double";
  c1_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[19].fileTimeLo = 1286786342U;
  c1_info[19].fileTimeHi = 0U;
  c1_info[19].mFileTimeLo = 0U;
  c1_info[19].mFileTimeHi = 0U;
  c1_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_ispow2.m";
  c1_info[20].name = "eml_index_class";
  c1_info[20].dominantType = "";
  c1_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[20].fileTimeLo = 1323134578U;
  c1_info[20].fileTimeHi = 0U;
  c1_info[20].mFileTimeLo = 0U;
  c1_info[20].mFileTimeHi = 0U;
  c1_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_ispow2.m";
  c1_info[21].name = "eml_unsigned_class";
  c1_info[21].dominantType = "char";
  c1_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c1_info[21].fileTimeLo = 1323134580U;
  c1_info[21].fileTimeHi = 0U;
  c1_info[21].mFileTimeLo = 0U;
  c1_info[21].mFileTimeHi = 0U;
  c1_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c1_info[22].name = "eml_index_class";
  c1_info[22].dominantType = "";
  c1_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[22].fileTimeLo = 1323134578U;
  c1_info[22].fileTimeHi = 0U;
  c1_info[22].mFileTimeLo = 0U;
  c1_info[22].mFileTimeHi = 0U;
  c1_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_ispow2.m";
  c1_info[23].name = "eml_size_ispow2";
  c1_info[23].dominantType = "coder.internal.indexInt";
  c1_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_ispow2.m";
  c1_info[23].fileTimeLo = 1286786398U;
  c1_info[23].fileTimeHi = 0U;
  c1_info[23].mFileTimeLo = 0U;
  c1_info[23].mFileTimeHi = 0U;
  c1_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m";
  c1_info[24].name = "eml_index_class";
  c1_info[24].dominantType = "";
  c1_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[24].fileTimeLo = 1323134578U;
  c1_info[24].fileTimeHi = 0U;
  c1_info[24].mFileTimeLo = 0U;
  c1_info[24].mFileTimeHi = 0U;
  c1_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m";
  c1_info[25].name = "eml_unsigned_class";
  c1_info[25].dominantType = "char";
  c1_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c1_info[25].fileTimeLo = 1323134580U;
  c1_info[25].fileTimeHi = 0U;
  c1_info[25].mFileTimeLo = 0U;
  c1_info[25].mFileTimeHi = 0U;
  c1_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m";
  c1_info[26].name = "max";
  c1_info[26].dominantType = "double";
  c1_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c1_info[26].fileTimeLo = 1311226516U;
  c1_info[26].fileTimeHi = 0U;
  c1_info[26].mFileTimeLo = 0U;
  c1_info[26].mFileTimeHi = 0U;
  c1_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c1_info[27].name = "eml_min_or_max";
  c1_info[27].dominantType = "char";
  c1_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[27].fileTimeLo = 1334042690U;
  c1_info[27].fileTimeHi = 0U;
  c1_info[27].mFileTimeLo = 0U;
  c1_info[27].mFileTimeHi = 0U;
  c1_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[28].name = "eml_scalar_eg";
  c1_info[28].dominantType = "double";
  c1_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[28].fileTimeLo = 1286786396U;
  c1_info[28].fileTimeHi = 0U;
  c1_info[28].mFileTimeLo = 0U;
  c1_info[28].mFileTimeHi = 0U;
  c1_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[29].name = "eml_scalexp_alloc";
  c1_info[29].dominantType = "double";
  c1_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[29].fileTimeLo = 1330572434U;
  c1_info[29].fileTimeHi = 0U;
  c1_info[29].mFileTimeLo = 0U;
  c1_info[29].mFileTimeHi = 0U;
  c1_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[30].name = "eml_index_class";
  c1_info[30].dominantType = "";
  c1_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[30].fileTimeLo = 1323134578U;
  c1_info[30].fileTimeHi = 0U;
  c1_info[30].mFileTimeLo = 0U;
  c1_info[30].mFileTimeHi = 0U;
  c1_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c1_info[31].name = "eml_scalar_eg";
  c1_info[31].dominantType = "double";
  c1_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[31].fileTimeLo = 1286786396U;
  c1_info[31].fileTimeHi = 0U;
  c1_info[31].mFileTimeLo = 0U;
  c1_info[31].mFileTimeHi = 0U;
  c1_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m";
  c1_info[32].name = "eml_dim_to_fore_permutation";
  c1_info[32].dominantType = "double";
  c1_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dim_to_fore_permutation.m";
  c1_info[32].fileTimeLo = 1286786296U;
  c1_info[32].fileTimeHi = 0U;
  c1_info[32].mFileTimeLo = 0U;
  c1_info[32].mFileTimeHi = 0U;
  c1_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dim_to_fore_permutation.m";
  c1_info[33].name = "eml_index_class";
  c1_info[33].dominantType = "";
  c1_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[33].fileTimeLo = 1323134578U;
  c1_info[33].fileTimeHi = 0U;
  c1_info[33].mFileTimeLo = 0U;
  c1_info[33].mFileTimeHi = 0U;
  c1_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dim_to_fore_permutation.m";
  c1_info[34].name = "eml_index_plus";
  c1_info[34].dominantType = "double";
  c1_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[34].fileTimeLo = 1286786378U;
  c1_info[34].fileTimeHi = 0U;
  c1_info[34].mFileTimeLo = 0U;
  c1_info[34].mFileTimeHi = 0U;
  c1_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[35].name = "eml_index_class";
  c1_info[35].dominantType = "";
  c1_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[35].fileTimeLo = 1323134578U;
  c1_info[35].fileTimeHi = 0U;
  c1_info[35].mFileTimeLo = 0U;
  c1_info[35].mFileTimeHi = 0U;
  c1_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dim_to_fore_permutation.m";
  c1_info[36].name = "min";
  c1_info[36].dominantType = "coder.internal.indexInt";
  c1_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[36].fileTimeLo = 1311226518U;
  c1_info[36].fileTimeHi = 0U;
  c1_info[36].mFileTimeLo = 0U;
  c1_info[36].mFileTimeHi = 0U;
  c1_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[37].name = "eml_min_or_max";
  c1_info[37].dominantType = "char";
  c1_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[37].fileTimeLo = 1334042690U;
  c1_info[37].fileTimeHi = 0U;
  c1_info[37].mFileTimeLo = 0U;
  c1_info[37].mFileTimeHi = 0U;
  c1_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[38].name = "eml_scalar_eg";
  c1_info[38].dominantType = "coder.internal.indexInt";
  c1_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[38].fileTimeLo = 1286786396U;
  c1_info[38].fileTimeHi = 0U;
  c1_info[38].mFileTimeLo = 0U;
  c1_info[38].mFileTimeHi = 0U;
  c1_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[39].name = "eml_scalexp_alloc";
  c1_info[39].dominantType = "coder.internal.indexInt";
  c1_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[39].fileTimeLo = 1330572434U;
  c1_info[39].fileTimeHi = 0U;
  c1_info[39].mFileTimeLo = 0U;
  c1_info[39].mFileTimeHi = 0U;
  c1_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c1_info[40].name = "eml_scalar_eg";
  c1_info[40].dominantType = "coder.internal.indexInt";
  c1_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[40].fileTimeLo = 1286786396U;
  c1_info[40].fileTimeHi = 0U;
  c1_info[40].mFileTimeLo = 0U;
  c1_info[40].mFileTimeHi = 0U;
  c1_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dim_to_fore_permutation.m";
  c1_info[41].name = "max";
  c1_info[41].dominantType = "coder.internal.indexInt";
  c1_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c1_info[41].fileTimeLo = 1311226516U;
  c1_info[41].fileTimeHi = 0U;
  c1_info[41].mFileTimeLo = 0U;
  c1_info[41].mFileTimeHi = 0U;
  c1_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dim_to_fore_permutation.m";
  c1_info[42].name = "colon";
  c1_info[42].dominantType = "double";
  c1_info[42].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[42].fileTimeLo = 1311226518U;
  c1_info[42].fileTimeHi = 0U;
  c1_info[42].mFileTimeLo = 0U;
  c1_info[42].mFileTimeHi = 0U;
  c1_info[43].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[43].name = "floor";
  c1_info[43].dominantType = "double";
  c1_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[43].fileTimeLo = 1286786342U;
  c1_info[43].fileTimeHi = 0U;
  c1_info[43].mFileTimeLo = 0U;
  c1_info[43].mFileTimeHi = 0U;
  c1_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c1_info[44].name = "intmin";
  c1_info[44].dominantType = "char";
  c1_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c1_info[44].fileTimeLo = 1311226518U;
  c1_info[44].fileTimeHi = 0U;
  c1_info[44].mFileTimeLo = 0U;
  c1_info[44].mFileTimeHi = 0U;
  c1_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c1_info[45].name = "intmax";
  c1_info[45].dominantType = "char";
  c1_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[45].fileTimeLo = 1311226516U;
  c1_info[45].fileTimeHi = 0U;
  c1_info[45].mFileTimeLo = 0U;
  c1_info[45].mFileTimeHi = 0U;
  c1_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c1_info[46].name = "intmin";
  c1_info[46].dominantType = "char";
  c1_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c1_info[46].fileTimeLo = 1311226518U;
  c1_info[46].fileTimeHi = 0U;
  c1_info[46].mFileTimeLo = 0U;
  c1_info[46].mFileTimeHi = 0U;
  c1_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c1_info[47].name = "intmax";
  c1_info[47].dominantType = "char";
  c1_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[47].fileTimeLo = 1311226516U;
  c1_info[47].fileTimeHi = 0U;
  c1_info[47].mFileTimeLo = 0U;
  c1_info[47].mFileTimeHi = 0U;
  c1_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c1_info[48].name = "eml_isa_uint";
  c1_info[48].dominantType = "coder.internal.indexInt";
  c1_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c1_info[48].fileTimeLo = 1286786384U;
  c1_info[48].fileTimeHi = 0U;
  c1_info[48].mFileTimeLo = 0U;
  c1_info[48].mFileTimeHi = 0U;
  c1_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[49].name = "eml_unsigned_class";
  c1_info[49].dominantType = "char";
  c1_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c1_info[49].fileTimeLo = 1323134580U;
  c1_info[49].fileTimeHi = 0U;
  c1_info[49].mFileTimeLo = 0U;
  c1_info[49].mFileTimeHi = 0U;
  c1_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[50].name = "eml_index_class";
  c1_info[50].dominantType = "";
  c1_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[50].fileTimeLo = 1323134578U;
  c1_info[50].fileTimeHi = 0U;
  c1_info[50].mFileTimeLo = 0U;
  c1_info[50].mFileTimeHi = 0U;
  c1_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[51].name = "intmax";
  c1_info[51].dominantType = "char";
  c1_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[51].fileTimeLo = 1311226516U;
  c1_info[51].fileTimeHi = 0U;
  c1_info[51].mFileTimeLo = 0U;
  c1_info[51].mFileTimeHi = 0U;
  c1_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[52].name = "eml_isa_uint";
  c1_info[52].dominantType = "coder.internal.indexInt";
  c1_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c1_info[52].fileTimeLo = 1286786384U;
  c1_info[52].fileTimeHi = 0U;
  c1_info[52].mFileTimeLo = 0U;
  c1_info[52].mFileTimeHi = 0U;
  c1_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[53].name = "eml_index_plus";
  c1_info[53].dominantType = "double";
  c1_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[53].fileTimeLo = 1286786378U;
  c1_info[53].fileTimeHi = 0U;
  c1_info[53].mFileTimeLo = 0U;
  c1_info[53].mFileTimeHi = 0U;
  c1_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dim_to_fore_permutation.m";
  c1_info[54].name = "eml_index_minus";
  c1_info[54].dominantType = "coder.internal.indexInt";
  c1_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[54].fileTimeLo = 1286786378U;
  c1_info[54].fileTimeHi = 0U;
  c1_info[54].mFileTimeLo = 0U;
  c1_info[54].mFileTimeHi = 0U;
  c1_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[55].name = "eml_index_class";
  c1_info[55].dominantType = "";
  c1_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[55].fileTimeLo = 1323134578U;
  c1_info[55].fileTimeHi = 0U;
  c1_info[55].mFileTimeLo = 0U;
  c1_info[55].mFileTimeHi = 0U;
  c1_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dim_to_fore_permutation.m";
  c1_info[56].name = "eml_index_plus";
  c1_info[56].dominantType = "coder.internal.indexInt";
  c1_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[56].fileTimeLo = 1286786378U;
  c1_info[56].fileTimeHi = 0U;
  c1_info[56].mFileTimeLo = 0U;
  c1_info[56].mFileTimeHi = 0U;
  c1_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m";
  c1_info[57].name = "permute";
  c1_info[57].dominantType = "double";
  c1_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/permute.m";
  c1_info[57].fileTimeLo = 1286786366U;
  c1_info[57].fileTimeHi = 0U;
  c1_info[57].mFileTimeLo = 0U;
  c1_info[57].mFileTimeHi = 0U;
  c1_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/permute.m";
  c1_info[58].name = "eml_index_class";
  c1_info[58].dominantType = "";
  c1_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[58].fileTimeLo = 1323134578U;
  c1_info[58].fileTimeHi = 0U;
  c1_info[58].mFileTimeLo = 0U;
  c1_info[58].mFileTimeHi = 0U;
  c1_info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/permute.m";
  c1_info[59].name = "eml_is_permutation";
  c1_info[59].dominantType = "coder.internal.indexInt";
  c1_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_permutation.m";
  c1_info[59].fileTimeLo = 1323134578U;
  c1_info[59].fileTimeHi = 0U;
  c1_info[59].mFileTimeLo = 0U;
  c1_info[59].mFileTimeHi = 0U;
  c1_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_permutation.m";
  c1_info[60].name = "eml_scalar_floor";
  c1_info[60].dominantType = "coder.internal.indexInt";
  c1_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[60].fileTimeLo = 1286786326U;
  c1_info[60].fileTimeHi = 0U;
  c1_info[60].mFileTimeLo = 0U;
  c1_info[60].mFileTimeHi = 0U;
  c1_info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_permutation.m";
  c1_info[61].name = "all";
  c1_info[61].dominantType = "logical";
  c1_info[61].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c1_info[61].fileTimeLo = 1286786434U;
  c1_info[61].fileTimeHi = 0U;
  c1_info[61].mFileTimeLo = 0U;
  c1_info[61].mFileTimeHi = 0U;
  c1_info[62].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c1_info[62].name = "eml_all_or_any";
  c1_info[62].dominantType = "char";
  c1_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c1_info[62].fileTimeLo = 1286786294U;
  c1_info[62].fileTimeHi = 0U;
  c1_info[62].mFileTimeLo = 0U;
  c1_info[62].mFileTimeHi = 0U;
  c1_info[63].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c1_info[63].name = "isequal";
  c1_info[63].dominantType = "double";
  c1_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[63].fileTimeLo = 1286786358U;
  c1_info[63].fileTimeHi = 0U;
  c1_info[63].mFileTimeLo = 0U;
  c1_info[63].mFileTimeHi = 0U;
}

static void c1_b_info_helper(c1_ResolvedFunctionInfo c1_info[155])
{
  c1_info[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[64].name = "eml_isequal_core";
  c1_info[64].dominantType = "double";
  c1_info[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c1_info[64].fileTimeLo = 1286786386U;
  c1_info[64].fileTimeHi = 0U;
  c1_info[64].mFileTimeLo = 0U;
  c1_info[64].mFileTimeHi = 0U;
  c1_info[65].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c1_info[65].name = "eml_const_nonsingleton_dim";
  c1_info[65].dominantType = "logical";
  c1_info[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c1_info[65].fileTimeLo = 1286786296U;
  c1_info[65].fileTimeHi = 0U;
  c1_info[65].mFileTimeLo = 0U;
  c1_info[65].mFileTimeHi = 0U;
  c1_info[66].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m";
  c1_info[66].name = "eml_fft";
  c1_info[66].dominantType = "char";
  c1_info[66].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m";
  c1_info[66].fileTimeLo = 1286786374U;
  c1_info[66].fileTimeHi = 0U;
  c1_info[66].mFileTimeLo = 0U;
  c1_info[66].mFileTimeHi = 0U;
  c1_info[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m";
  c1_info[67].name = "eml_assert_valid_dim";
  c1_info[67].dominantType = "double";
  c1_info[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c1_info[67].fileTimeLo = 1286786294U;
  c1_info[67].fileTimeHi = 0U;
  c1_info[67].mFileTimeLo = 0U;
  c1_info[67].mFileTimeHi = 0U;
  c1_info[68].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c1_info[68].name = "eml_scalar_floor";
  c1_info[68].dominantType = "double";
  c1_info[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[68].fileTimeLo = 1286786326U;
  c1_info[68].fileTimeHi = 0U;
  c1_info[68].mFileTimeLo = 0U;
  c1_info[68].mFileTimeHi = 0U;
  c1_info[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c1_info[69].name = "eml_index_class";
  c1_info[69].dominantType = "";
  c1_info[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[69].fileTimeLo = 1323134578U;
  c1_info[69].fileTimeHi = 0U;
  c1_info[69].mFileTimeLo = 0U;
  c1_info[69].mFileTimeHi = 0U;
  c1_info[70].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c1_info[70].name = "intmax";
  c1_info[70].dominantType = "char";
  c1_info[70].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[70].fileTimeLo = 1311226516U;
  c1_info[70].fileTimeHi = 0U;
  c1_info[70].mFileTimeLo = 0U;
  c1_info[70].mFileTimeHi = 0U;
  c1_info[71].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m";
  c1_info[71].name = "eml_size_ispow2";
  c1_info[71].dominantType = "coder.internal.indexInt";
  c1_info[71].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_ispow2.m";
  c1_info[71].fileTimeLo = 1286786398U;
  c1_info[71].fileTimeHi = 0U;
  c1_info[71].mFileTimeLo = 0U;
  c1_info[71].mFileTimeHi = 0U;
  c1_info[72].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c1_info[72].name = "eml_scalar_eg";
  c1_info[72].dominantType = "double";
  c1_info[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[72].fileTimeLo = 1286786396U;
  c1_info[72].fileTimeHi = 0U;
  c1_info[72].mFileTimeLo = 0U;
  c1_info[72].mFileTimeHi = 0U;
  c1_info[73].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c1_info[73].name = "eml_index_class";
  c1_info[73].dominantType = "";
  c1_info[73].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[73].fileTimeLo = 1323134578U;
  c1_info[73].fileTimeHi = 0U;
  c1_info[73].mFileTimeLo = 0U;
  c1_info[73].mFileTimeHi = 0U;
  c1_info[74].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c1_info[74].name = "min";
  c1_info[74].dominantType = "double";
  c1_info[74].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[74].fileTimeLo = 1311226518U;
  c1_info[74].fileTimeHi = 0U;
  c1_info[74].mFileTimeLo = 0U;
  c1_info[74].mFileTimeHi = 0U;
  c1_info[75].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c1_info[75].name = "eml_relop";
  c1_info[75].dominantType = "function_handle";
  c1_info[75].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c1_info[75].fileTimeLo = 1326691998U;
  c1_info[75].fileTimeHi = 0U;
  c1_info[75].mFileTimeLo = 0U;
  c1_info[75].mFileTimeHi = 0U;
  c1_info[76].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c1_info[76].name = "coder.internal.indexIntRelop";
  c1_info[76].dominantType = "";
  c1_info[76].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m";
  c1_info[76].fileTimeLo = 1326692322U;
  c1_info[76].fileTimeHi = 0U;
  c1_info[76].mFileTimeLo = 0U;
  c1_info[76].mFileTimeHi = 0U;
  c1_info[77].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass";
  c1_info[77].name = "eml_float_model";
  c1_info[77].dominantType = "char";
  c1_info[77].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c1_info[77].fileTimeLo = 1326691996U;
  c1_info[77].fileTimeHi = 0U;
  c1_info[77].mFileTimeLo = 0U;
  c1_info[77].mFileTimeHi = 0U;
  c1_info[78].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass";
  c1_info[78].name = "intmin";
  c1_info[78].dominantType = "char";
  c1_info[78].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c1_info[78].fileTimeLo = 1311226518U;
  c1_info[78].fileTimeHi = 0U;
  c1_info[78].mFileTimeLo = 0U;
  c1_info[78].mFileTimeHi = 0U;
  c1_info[79].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c1_info[79].name = "isnan";
  c1_info[79].dominantType = "double";
  c1_info[79].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[79].fileTimeLo = 1286786360U;
  c1_info[79].fileTimeHi = 0U;
  c1_info[79].mFileTimeLo = 0U;
  c1_info[79].mFileTimeHi = 0U;
  c1_info[80].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c1_info[80].name = "eml_index_minus";
  c1_info[80].dominantType = "double";
  c1_info[80].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[80].fileTimeLo = 1286786378U;
  c1_info[80].fileTimeHi = 0U;
  c1_info[80].mFileTimeLo = 0U;
  c1_info[80].mFileTimeHi = 0U;
  c1_info[81].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c1_info[81].name = "max";
  c1_info[81].dominantType = "coder.internal.indexInt";
  c1_info[81].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c1_info[81].fileTimeLo = 1311226516U;
  c1_info[81].fileTimeHi = 0U;
  c1_info[81].mFileTimeLo = 0U;
  c1_info[81].mFileTimeHi = 0U;
  c1_info[82].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c1_info[82].name = "eml_index_minus";
  c1_info[82].dominantType = "coder.internal.indexInt";
  c1_info[82].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[82].fileTimeLo = 1286786378U;
  c1_info[82].fileTimeHi = 0U;
  c1_info[82].mFileTimeLo = 0U;
  c1_info[82].mFileTimeHi = 0U;
  c1_info[83].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c1_info[83].name = "eml_index_rdivide";
  c1_info[83].dominantType = "coder.internal.indexInt";
  c1_info[83].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c1_info[83].fileTimeLo = 1286786380U;
  c1_info[83].fileTimeHi = 0U;
  c1_info[83].mFileTimeLo = 0U;
  c1_info[83].mFileTimeHi = 0U;
  c1_info[84].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c1_info[84].name = "eml_index_class";
  c1_info[84].dominantType = "";
  c1_info[84].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[84].fileTimeLo = 1323134578U;
  c1_info[84].fileTimeHi = 0U;
  c1_info[84].mFileTimeLo = 0U;
  c1_info[84].mFileTimeHi = 0U;
  c1_info[85].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c1_info[85].name = "eml_index_rdivide";
  c1_info[85].dominantType = "double";
  c1_info[85].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c1_info[85].fileTimeLo = 1286786380U;
  c1_info[85].fileTimeHi = 0U;
  c1_info[85].mFileTimeLo = 0U;
  c1_info[85].mFileTimeHi = 0U;
  c1_info[86].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c1_info[86].name = "eml_index_times";
  c1_info[86].dominantType = "coder.internal.indexInt";
  c1_info[86].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[86].fileTimeLo = 1286786380U;
  c1_info[86].fileTimeHi = 0U;
  c1_info[86].mFileTimeLo = 0U;
  c1_info[86].mFileTimeHi = 0U;
  c1_info[87].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[87].name = "eml_index_class";
  c1_info[87].dominantType = "";
  c1_info[87].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[87].fileTimeLo = 1323134578U;
  c1_info[87].fileTimeHi = 0U;
  c1_info[87].mFileTimeLo = 0U;
  c1_info[87].mFileTimeHi = 0U;
  c1_info[88].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c1_info[88].name = "mtimes";
  c1_info[88].dominantType = "double";
  c1_info[88].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[88].fileTimeLo = 1289483692U;
  c1_info[88].fileTimeHi = 0U;
  c1_info[88].mFileTimeLo = 0U;
  c1_info[88].mFileTimeHi = 0U;
  c1_info[89].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c1_info[89].name = "mrdivide";
  c1_info[89].dominantType = "double";
  c1_info[89].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[89].fileTimeLo = 1342782144U;
  c1_info[89].fileTimeHi = 0U;
  c1_info[89].mFileTimeLo = 1319697566U;
  c1_info[89].mFileTimeHi = 0U;
  c1_info[90].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[90].name = "rdivide";
  c1_info[90].dominantType = "double";
  c1_info[90].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[90].fileTimeLo = 1286786444U;
  c1_info[90].fileTimeHi = 0U;
  c1_info[90].mFileTimeLo = 0U;
  c1_info[90].mFileTimeHi = 0U;
  c1_info[91].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[91].name = "eml_div";
  c1_info[91].dominantType = "double";
  c1_info[91].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[91].fileTimeLo = 1313319010U;
  c1_info[91].fileTimeHi = 0U;
  c1_info[91].mFileTimeLo = 0U;
  c1_info[91].mFileTimeHi = 0U;
  c1_info[92].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!make_1q_cosine_table";
  c1_info[92].name = "eml_index_plus";
  c1_info[92].dominantType = "double";
  c1_info[92].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[92].fileTimeLo = 1286786378U;
  c1_info[92].fileTimeHi = 0U;
  c1_info[92].mFileTimeLo = 0U;
  c1_info[92].mFileTimeHi = 0U;
  c1_info[93].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!make_1q_cosine_table";
  c1_info[93].name = "eml_index_rdivide";
  c1_info[93].dominantType = "double";
  c1_info[93].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  c1_info[93].fileTimeLo = 1286786380U;
  c1_info[93].fileTimeHi = 0U;
  c1_info[93].mFileTimeLo = 0U;
  c1_info[93].mFileTimeHi = 0U;
  c1_info[94].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!make_1q_cosine_table";
  c1_info[94].name = "eml_int_forloop_overflow_check";
  c1_info[94].dominantType = "";
  c1_info[94].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[94].fileTimeLo = 1332132672U;
  c1_info[94].fileTimeHi = 0U;
  c1_info[94].mFileTimeLo = 0U;
  c1_info[94].mFileTimeHi = 0U;
  c1_info[95].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c1_info[95].name = "intmax";
  c1_info[95].dominantType = "char";
  c1_info[95].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[95].fileTimeLo = 1311226516U;
  c1_info[95].fileTimeHi = 0U;
  c1_info[95].mFileTimeLo = 0U;
  c1_info[95].mFileTimeHi = 0U;
  c1_info[96].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!make_1q_cosine_table";
  c1_info[96].name = "mtimes";
  c1_info[96].dominantType = "double";
  c1_info[96].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[96].fileTimeLo = 1289483692U;
  c1_info[96].fileTimeHi = 0U;
  c1_info[96].mFileTimeLo = 0U;
  c1_info[96].mFileTimeHi = 0U;
  c1_info[97].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!make_1q_cosine_table";
  c1_info[97].name = "cos";
  c1_info[97].dominantType = "double";
  c1_info[97].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[97].fileTimeLo = 1286786306U;
  c1_info[97].fileTimeHi = 0U;
  c1_info[97].mFileTimeLo = 0U;
  c1_info[97].mFileTimeHi = 0U;
  c1_info[98].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[98].name = "eml_scalar_cos";
  c1_info[98].dominantType = "double";
  c1_info[98].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c1_info[98].fileTimeLo = 1286786322U;
  c1_info[98].fileTimeHi = 0U;
  c1_info[98].mFileTimeLo = 0U;
  c1_info[98].mFileTimeHi = 0U;
  c1_info[99].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!make_1q_cosine_table";
  c1_info[99].name = "eml_index_minus";
  c1_info[99].dominantType = "double";
  c1_info[99].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[99].fileTimeLo = 1286786378U;
  c1_info[99].fileTimeHi = 0U;
  c1_info[99].mFileTimeLo = 0U;
  c1_info[99].mFileTimeHi = 0U;
  c1_info[100].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!make_1q_cosine_table";
  c1_info[100].name = "eml_index_minus";
  c1_info[100].dominantType = "coder.internal.indexInt";
  c1_info[100].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[100].fileTimeLo = 1286786378U;
  c1_info[100].fileTimeHi = 0U;
  c1_info[100].mFileTimeLo = 0U;
  c1_info[100].mFileTimeHi = 0U;
  c1_info[101].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!make_1q_cosine_table";
  c1_info[101].name = "sin";
  c1_info[101].dominantType = "double";
  c1_info[101].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[101].fileTimeLo = 1286786350U;
  c1_info[101].fileTimeHi = 0U;
  c1_info[101].mFileTimeLo = 0U;
  c1_info[101].mFileTimeHi = 0U;
  c1_info[102].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[102].name = "eml_scalar_sin";
  c1_info[102].dominantType = "double";
  c1_info[102].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c1_info[102].fileTimeLo = 1286786336U;
  c1_info[102].fileTimeHi = 0U;
  c1_info[102].mFileTimeLo = 0U;
  c1_info[102].mFileTimeHi = 0U;
  c1_info[103].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!make_twiddle_table";
  c1_info[103].name = "eml_index_class";
  c1_info[103].dominantType = "";
  c1_info[103].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[103].fileTimeLo = 1323134578U;
  c1_info[103].fileTimeHi = 0U;
  c1_info[103].mFileTimeLo = 0U;
  c1_info[103].mFileTimeHi = 0U;
  c1_info[104].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!make_twiddle_table";
  c1_info[104].name = "eml_index_times";
  c1_info[104].dominantType = "double";
  c1_info[104].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[104].fileTimeLo = 1286786380U;
  c1_info[104].fileTimeHi = 0U;
  c1_info[104].mFileTimeLo = 0U;
  c1_info[104].mFileTimeHi = 0U;
  c1_info[105].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!make_twiddle_table";
  c1_info[105].name = "eml_index_plus";
  c1_info[105].dominantType = "double";
  c1_info[105].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[105].fileTimeLo = 1286786378U;
  c1_info[105].fileTimeHi = 0U;
  c1_info[105].mFileTimeLo = 0U;
  c1_info[105].mFileTimeHi = 0U;
  c1_info[106].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!make_twiddle_table";
  c1_info[106].name = "eml_int_forloop_overflow_check";
  c1_info[106].dominantType = "";
  c1_info[106].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[106].fileTimeLo = 1332132672U;
  c1_info[106].fileTimeHi = 0U;
  c1_info[106].mFileTimeLo = 0U;
  c1_info[106].mFileTimeHi = 0U;
  c1_info[107].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!make_twiddle_table";
  c1_info[107].name = "eml_index_minus";
  c1_info[107].dominantType = "coder.internal.indexInt";
  c1_info[107].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[107].fileTimeLo = 1286786378U;
  c1_info[107].fileTimeHi = 0U;
  c1_info[107].mFileTimeLo = 0U;
  c1_info[107].mFileTimeHi = 0U;
  c1_info[108].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!ucls";
  c1_info[108].name = "eml_index_class";
  c1_info[108].dominantType = "";
  c1_info[108].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[108].fileTimeLo = 1323134578U;
  c1_info[108].fileTimeHi = 0U;
  c1_info[108].mFileTimeLo = 0U;
  c1_info[108].mFileTimeHi = 0U;
  c1_info[109].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!ucls";
  c1_info[109].name = "eml_unsigned_class";
  c1_info[109].dominantType = "char";
  c1_info[109].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c1_info[109].fileTimeLo = 1323134580U;
  c1_info[109].fileTimeHi = 0U;
  c1_info[109].mFileTimeLo = 0U;
  c1_info[109].mFileTimeHi = 0U;
  c1_info[110].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c1_info[110].name = "eml_index_plus";
  c1_info[110].dominantType = "double";
  c1_info[110].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[110].fileTimeLo = 1286786378U;
  c1_info[110].fileTimeHi = 0U;
  c1_info[110].mFileTimeLo = 0U;
  c1_info[110].mFileTimeHi = 0U;
  c1_info[111].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c1_info[111].name = "eml_index_plus";
  c1_info[111].dominantType = "coder.internal.indexInt";
  c1_info[111].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[111].fileTimeLo = 1286786378U;
  c1_info[111].fileTimeHi = 0U;
  c1_info[111].mFileTimeLo = 0U;
  c1_info[111].mFileTimeHi = 0U;
  c1_info[112].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c1_info[112].name = "eml_int_forloop_overflow_check";
  c1_info[112].dominantType = "";
  c1_info[112].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[112].fileTimeLo = 1332132672U;
  c1_info[112].fileTimeHi = 0U;
  c1_info[112].mFileTimeLo = 0U;
  c1_info[112].mFileTimeHi = 0U;
  c1_info[113].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m!r2br_r2dit_trig";
  c1_info[113].name = "eml_index_times";
  c1_info[113].dominantType = "double";
  c1_info[113].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[113].fileTimeLo = 1286786380U;
  c1_info[113].fileTimeHi = 0U;
  c1_info[113].mFileTimeLo = 0U;
  c1_info[113].mFileTimeHi = 0U;
  c1_info[114].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_fft.m";
  c1_info[114].name = "ipermute";
  c1_info[114].dominantType = "double";
  c1_info[114].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ipermute.m";
  c1_info[114].fileTimeLo = 1286786356U;
  c1_info[114].fileTimeHi = 0U;
  c1_info[114].mFileTimeLo = 0U;
  c1_info[114].mFileTimeHi = 0U;
  c1_info[115].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ipermute.m";
  c1_info[115].name = "eml_is_permutation";
  c1_info[115].dominantType = "coder.internal.indexInt";
  c1_info[115].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_permutation.m";
  c1_info[115].fileTimeLo = 1323134578U;
  c1_info[115].fileTimeHi = 0U;
  c1_info[115].mFileTimeLo = 0U;
  c1_info[115].mFileTimeHi = 0U;
  c1_info[116].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ipermute.m!invperm";
  c1_info[116].name = "eml_index_class";
  c1_info[116].dominantType = "";
  c1_info[116].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[116].fileTimeLo = 1323134578U;
  c1_info[116].fileTimeHi = 0U;
  c1_info[116].mFileTimeLo = 0U;
  c1_info[116].mFileTimeHi = 0U;
  c1_info[117].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ipermute.m";
  c1_info[117].name = "permute";
  c1_info[117].dominantType = "double";
  c1_info[117].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/permute.m";
  c1_info[117].fileTimeLo = 1286786366U;
  c1_info[117].fileTimeHi = 0U;
  c1_info[117].mFileTimeLo = 0U;
  c1_info[117].mFileTimeHi = 0U;
  c1_info[118].context = "";
  c1_info[118].name = "mrdivide";
  c1_info[118].dominantType = "double";
  c1_info[118].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[118].fileTimeLo = 1342782144U;
  c1_info[118].fileTimeHi = 0U;
  c1_info[118].mFileTimeLo = 1319697566U;
  c1_info[118].mFileTimeHi = 0U;
  c1_info[119].context = "";
  c1_info[119].name = "linspace";
  c1_info[119].dominantType = "double";
  c1_info[119].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c1_info[119].fileTimeLo = 1286786362U;
  c1_info[119].fileTimeHi = 0U;
  c1_info[119].mFileTimeLo = 0U;
  c1_info[119].mFileTimeHi = 0U;
  c1_info[120].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c1_info[120].name = "eml_scalar_eg";
  c1_info[120].dominantType = "double";
  c1_info[120].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[120].fileTimeLo = 1286786396U;
  c1_info[120].fileTimeHi = 0U;
  c1_info[120].mFileTimeLo = 0U;
  c1_info[120].mFileTimeHi = 0U;
  c1_info[121].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c1_info[121].name = "eml_scalar_floor";
  c1_info[121].dominantType = "double";
  c1_info[121].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[121].fileTimeLo = 1286786326U;
  c1_info[121].fileTimeHi = 0U;
  c1_info[121].mFileTimeLo = 0U;
  c1_info[121].mFileTimeHi = 0U;
  c1_info[122].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c1_info[122].name = "eml_index_class";
  c1_info[122].dominantType = "";
  c1_info[122].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[122].fileTimeLo = 1323134578U;
  c1_info[122].fileTimeHi = 0U;
  c1_info[122].mFileTimeLo = 0U;
  c1_info[122].mFileTimeHi = 0U;
  c1_info[123].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c1_info[123].name = "realmax";
  c1_info[123].dominantType = "char";
  c1_info[123].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c1_info[123].fileTimeLo = 1307622442U;
  c1_info[123].fileTimeHi = 0U;
  c1_info[123].mFileTimeLo = 0U;
  c1_info[123].mFileTimeHi = 0U;
  c1_info[124].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c1_info[124].name = "eml_realmax";
  c1_info[124].dominantType = "char";
  c1_info[124].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c1_info[124].fileTimeLo = 1326691996U;
  c1_info[124].fileTimeHi = 0U;
  c1_info[124].mFileTimeLo = 0U;
  c1_info[124].mFileTimeHi = 0U;
  c1_info[125].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c1_info[125].name = "eml_float_model";
  c1_info[125].dominantType = "char";
  c1_info[125].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c1_info[125].fileTimeLo = 1326691996U;
  c1_info[125].fileTimeHi = 0U;
  c1_info[125].mFileTimeLo = 0U;
  c1_info[125].mFileTimeHi = 0U;
  c1_info[126].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m";
  c1_info[126].name = "mtimes";
  c1_info[126].dominantType = "double";
  c1_info[126].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[126].fileTimeLo = 1289483692U;
  c1_info[126].fileTimeHi = 0U;
  c1_info[126].mFileTimeLo = 0U;
  c1_info[126].mFileTimeHi = 0U;
  c1_info[127].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c1_info[127].name = "mrdivide";
  c1_info[127].dominantType = "double";
  c1_info[127].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[127].fileTimeLo = 1342782144U;
  c1_info[127].fileTimeHi = 0U;
  c1_info[127].mFileTimeLo = 1319697566U;
  c1_info[127].mFileTimeHi = 0U;
}

static void c1_c_info_helper(c1_ResolvedFunctionInfo c1_info[155])
{
  c1_info[128].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c1_info[128].name = "mtimes";
  c1_info[128].dominantType = "double";
  c1_info[128].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[128].fileTimeLo = 1289483692U;
  c1_info[128].fileTimeHi = 0U;
  c1_info[128].mFileTimeLo = 0U;
  c1_info[128].mFileTimeHi = 0U;
  c1_info[129].context = "";
  c1_info[129].name = "abs";
  c1_info[129].dominantType = "double";
  c1_info[129].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[129].fileTimeLo = 1286786294U;
  c1_info[129].fileTimeHi = 0U;
  c1_info[129].mFileTimeLo = 0U;
  c1_info[129].mFileTimeHi = 0U;
  c1_info[130].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[130].name = "eml_dlapy2";
  c1_info[130].dominantType = "double";
  c1_info[130].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m";
  c1_info[130].fileTimeLo = 1307622440U;
  c1_info[130].fileTimeHi = 0U;
  c1_info[130].mFileTimeLo = 0U;
  c1_info[130].mFileTimeHi = 0U;
  c1_info[131].context = "";
  c1_info[131].name = "eml_li_find";
  c1_info[131].dominantType = "";
  c1_info[131].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m";
  c1_info[131].fileTimeLo = 1286786386U;
  c1_info[131].fileTimeHi = 0U;
  c1_info[131].mFileTimeLo = 0U;
  c1_info[131].mFileTimeHi = 0U;
  c1_info[132].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m";
  c1_info[132].name = "eml_index_class";
  c1_info[132].dominantType = "";
  c1_info[132].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[132].fileTimeLo = 1323134578U;
  c1_info[132].fileTimeHi = 0U;
  c1_info[132].mFileTimeLo = 0U;
  c1_info[132].mFileTimeHi = 0U;
  c1_info[133].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones";
  c1_info[133].name = "eml_index_class";
  c1_info[133].dominantType = "";
  c1_info[133].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[133].fileTimeLo = 1323134578U;
  c1_info[133].fileTimeHi = 0U;
  c1_info[133].mFileTimeLo = 0U;
  c1_info[133].mFileTimeHi = 0U;
  c1_info[134].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones";
  c1_info[134].name = "eml_int_forloop_overflow_check";
  c1_info[134].dominantType = "";
  c1_info[134].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[134].fileTimeLo = 1332132672U;
  c1_info[134].fileTimeHi = 0U;
  c1_info[134].mFileTimeLo = 0U;
  c1_info[134].mFileTimeHi = 0U;
  c1_info[135].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones";
  c1_info[135].name = "eml_index_plus";
  c1_info[135].dominantType = "double";
  c1_info[135].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[135].fileTimeLo = 1286786378U;
  c1_info[135].fileTimeHi = 0U;
  c1_info[135].mFileTimeLo = 0U;
  c1_info[135].mFileTimeHi = 0U;
  c1_info[136].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m";
  c1_info[136].name = "eml_int_forloop_overflow_check";
  c1_info[136].dominantType = "";
  c1_info[136].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[136].fileTimeLo = 1332132672U;
  c1_info[136].fileTimeHi = 0U;
  c1_info[136].mFileTimeLo = 0U;
  c1_info[136].mFileTimeHi = 0U;
  c1_info[137].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m";
  c1_info[137].name = "eml_index_plus";
  c1_info[137].dominantType = "double";
  c1_info[137].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[137].fileTimeLo = 1286786378U;
  c1_info[137].fileTimeHi = 0U;
  c1_info[137].mFileTimeLo = 0U;
  c1_info[137].mFileTimeHi = 0U;
  c1_info[138].context = "";
  c1_info[138].name = "norm";
  c1_info[138].dominantType = "double";
  c1_info[138].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[138].fileTimeLo = 1336493294U;
  c1_info[138].fileTimeHi = 0U;
  c1_info[138].mFileTimeLo = 0U;
  c1_info[138].mFileTimeHi = 0U;
  c1_info[139].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm";
  c1_info[139].name = "eml_index_class";
  c1_info[139].dominantType = "";
  c1_info[139].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[139].fileTimeLo = 1323134578U;
  c1_info[139].fileTimeHi = 0U;
  c1_info[139].mFileTimeLo = 0U;
  c1_info[139].mFileTimeHi = 0U;
  c1_info[140].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm";
  c1_info[140].name = "eml_xnrm2";
  c1_info[140].dominantType = "double";
  c1_info[140].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c1_info[140].fileTimeLo = 1299040776U;
  c1_info[140].fileTimeHi = 0U;
  c1_info[140].mFileTimeLo = 0U;
  c1_info[140].mFileTimeHi = 0U;
  c1_info[141].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c1_info[141].name = "eml_blas_inline";
  c1_info[141].dominantType = "";
  c1_info[141].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[141].fileTimeLo = 1299040768U;
  c1_info[141].fileTimeHi = 0U;
  c1_info[141].mFileTimeLo = 0U;
  c1_info[141].mFileTimeHi = 0U;
  c1_info[142].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m!below_threshold";
  c1_info[142].name = "length";
  c1_info[142].dominantType = "double";
  c1_info[142].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c1_info[142].fileTimeLo = 1303117406U;
  c1_info[142].fileTimeHi = 0U;
  c1_info[142].mFileTimeLo = 0U;
  c1_info[142].mFileTimeHi = 0U;
  c1_info[143].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c1_info[143].name = "eml_index_class";
  c1_info[143].dominantType = "";
  c1_info[143].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[143].fileTimeLo = 1323134578U;
  c1_info[143].fileTimeHi = 0U;
  c1_info[143].mFileTimeLo = 0U;
  c1_info[143].mFileTimeHi = 0U;
  c1_info[144].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c1_info[144].name = "eml_refblas_xnrm2";
  c1_info[144].dominantType = "double";
  c1_info[144].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[144].fileTimeLo = 1299040784U;
  c1_info[144].fileTimeHi = 0U;
  c1_info[144].mFileTimeLo = 0U;
  c1_info[144].mFileTimeHi = 0U;
  c1_info[145].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[145].name = "realmin";
  c1_info[145].dominantType = "char";
  c1_info[145].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c1_info[145].fileTimeLo = 1307622442U;
  c1_info[145].fileTimeHi = 0U;
  c1_info[145].mFileTimeLo = 0U;
  c1_info[145].mFileTimeHi = 0U;
  c1_info[146].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c1_info[146].name = "eml_realmin";
  c1_info[146].dominantType = "char";
  c1_info[146].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c1_info[146].fileTimeLo = 1307622444U;
  c1_info[146].fileTimeHi = 0U;
  c1_info[146].mFileTimeLo = 0U;
  c1_info[146].mFileTimeHi = 0U;
  c1_info[147].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c1_info[147].name = "eml_float_model";
  c1_info[147].dominantType = "char";
  c1_info[147].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c1_info[147].fileTimeLo = 1326691996U;
  c1_info[147].fileTimeHi = 0U;
  c1_info[147].mFileTimeLo = 0U;
  c1_info[147].mFileTimeHi = 0U;
  c1_info[148].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[148].name = "eml_index_class";
  c1_info[148].dominantType = "";
  c1_info[148].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[148].fileTimeLo = 1323134578U;
  c1_info[148].fileTimeHi = 0U;
  c1_info[148].mFileTimeLo = 0U;
  c1_info[148].mFileTimeHi = 0U;
  c1_info[149].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[149].name = "eml_index_minus";
  c1_info[149].dominantType = "double";
  c1_info[149].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[149].fileTimeLo = 1286786378U;
  c1_info[149].fileTimeHi = 0U;
  c1_info[149].mFileTimeLo = 0U;
  c1_info[149].mFileTimeHi = 0U;
  c1_info[150].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[150].name = "eml_index_times";
  c1_info[150].dominantType = "coder.internal.indexInt";
  c1_info[150].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[150].fileTimeLo = 1286786380U;
  c1_info[150].fileTimeHi = 0U;
  c1_info[150].mFileTimeLo = 0U;
  c1_info[150].mFileTimeHi = 0U;
  c1_info[151].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[151].name = "eml_index_plus";
  c1_info[151].dominantType = "coder.internal.indexInt";
  c1_info[151].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[151].fileTimeLo = 1286786378U;
  c1_info[151].fileTimeHi = 0U;
  c1_info[151].mFileTimeLo = 0U;
  c1_info[151].mFileTimeHi = 0U;
  c1_info[152].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[152].name = "eml_int_forloop_overflow_check";
  c1_info[152].dominantType = "";
  c1_info[152].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[152].fileTimeLo = 1332132672U;
  c1_info[152].fileTimeHi = 0U;
  c1_info[152].mFileTimeLo = 0U;
  c1_info[152].mFileTimeHi = 0U;
  c1_info[153].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[153].name = "abs";
  c1_info[153].dominantType = "double";
  c1_info[153].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[153].fileTimeLo = 1286786294U;
  c1_info[153].fileTimeHi = 0U;
  c1_info[153].mFileTimeLo = 0U;
  c1_info[153].mFileTimeHi = 0U;
  c1_info[154].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[154].name = "abs";
  c1_info[154].dominantType = "double";
  c1_info[154].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[154].fileTimeLo = 1286786294U;
  c1_info[154].fileTimeHi = 0U;
  c1_info[154].mFileTimeLo = 0U;
  c1_info[154].mFileTimeHi = 0U;
}

static void c1_eml_const_nonsingleton_dim
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance)
{
}

static void c1_fft(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance,
                   real_T c1_x, creal_T c1_y[1024])
{
  real_T c1_b_x;
  creal_T c1_y1[1024];
  int32_T c1_i30;
  creal_T c1_b_y1[1024];
  c1_b_x = c1_x;
  c1_eml_const_nonsingleton_dim(chartInstance);
  c1_eml_fft(chartInstance, c1_permute(chartInstance, c1_b_x), c1_y1);
  for (c1_i30 = 0; c1_i30 < 1024; c1_i30++) {
    c1_b_y1[c1_i30] = c1_y1[c1_i30];
  }

  c1_ipermute(chartInstance, c1_b_y1, c1_y);
}

static real_T c1_permute(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct
  *chartInstance, real_T c1_a)
{
  return c1_a;
}

static void c1_eml_fft(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct
  *chartInstance, real_T c1_x, creal_T c1_y[1024])
{
  real_T c1_b_x;
  int32_T c1_i31;
  static creal_T c1_dc0 = { 0.0, 0.0 };

  int32_T c1_i;
  int32_T c1_b_i;
  int32_T c1_a;
  int32_T c1_c;
  creal_T c1_temp;
  int32_T c1_b_a;
  int32_T c1_b_c;
  int32_T c1_c_a;
  int32_T c1_c_c;
  int32_T c1_d_a;
  int32_T c1_d_c;
  int32_T c1_e_a;
  int32_T c1_e_c;
  int32_T c1_iDelta;
  int32_T c1_iDelta2;
  int32_T c1_k;
  int32_T c1_iheight;
  int32_T c1_b;
  int32_T c1_ihi;
  int32_T c1_f_a;
  int32_T c1_b_b;
  int32_T c1_f_c;
  int32_T c1_g_a;
  int32_T c1_g_c;
  int32_T c1_h_a;
  int32_T c1_c_b;
  int32_T c1_h_c;
  int32_T c1_i_a;
  int32_T c1_i_c;
  int32_T c1_j_a;
  int32_T c1_j_c;
  int32_T c1_k_a;
  int32_T c1_k_c;
  int32_T c1_l_a;
  int32_T c1_l_c;
  int32_T c1_m_a;
  int32_T c1_d_b;
  int32_T c1_istart;
  int32_T c1_e_b;
  int32_T c1_j;
  int32_T c1_n_a;
  int32_T c1_m_c;
  int32_T c1_o_a;
  int32_T c1_n_c;
  static real_T c1_dv2[513] = { 1.0, 0.99998117528260111, 0.9999247018391445,
    0.9998305817958234, 0.99969881869620425, 0.99952941750109314,
    0.99932238458834954, 0.99907772775264536, 0.99879545620517241,
    0.99847558057329477, 0.99811811290014918, 0.99772306664419164,
    0.99729045667869021, 0.99682029929116567, 0.996312612182778,
    0.99576741446765982, 0.99518472667219693, 0.99456457073425542,
    0.99390697000235606, 0.9932119492347945, 0.99247953459871,
    0.99170975366909953, 0.99090263542778, 0.99005821026229712,
    0.989176509964781, 0.98825756773074946, 0.98730141815785843,
    0.98630809724459867, 0.98527764238894122, 0.984210092386929,
    0.98310548743121629, 0.98196386910955524, 0.98078528040323043,
    0.97956976568544052, 0.97831737071962765, 0.97702814265775439,
    0.97570213003852857, 0.97433938278557586, 0.97293995220556018,
    0.97150389098625178, 0.970031253194544, 0.96852209427441727,
    0.96697647104485207, 0.9653944416976894, 0.96377606579543984,
    0.96212140426904158, 0.96043051941556579, 0.9587034748958716,
    0.95694033573220882, 0.95514116830577078, 0.95330604035419386,
    0.95143502096900834, 0.94952818059303667, 0.94758559101774109,
    0.94560732538052128, 0.94359345816196039, 0.94154406518302081,
    0.93945922360218992, 0.937339011912575, 0.93518350993894761,
    0.932992798834739, 0.93076696107898371, 0.92850608047321559,
    0.92621024213831138, 0.92387953251128674, 0.9215140393420419,
    0.91911385169005777, 0.9166790599210427, 0.91420975570353069,
    0.91170603200542988, 0.90916798309052238, 0.90659570451491533,
    0.90398929312344334, 0.901348847046022, 0.89867446569395382,
    0.89596624975618522, 0.89322430119551532, 0.89044872324475788,
    0.88763962040285393, 0.88479709843093779, 0.881921264348355,
    0.87901222642863353, 0.8760700941954066, 0.87309497841829009,
    0.87008699110871146, 0.86704624551569265, 0.8639728561215867,
    0.86086693863776731, 0.85772861000027212, 0.85455798836540053,
    0.8513551931052652, 0.84812034480329723, 0.84485356524970712,
    0.84155497743689844, 0.83822470555483808, 0.83486287498638,
    0.83146961230254524, 0.8280450452577558, 0.82458930278502529,
    0.82110251499110465, 0.81758481315158371, 0.81403632970594841,
    0.81045719825259477, 0.80684755354379933, 0.80320753148064494,
    0.799537269107905, 0.79583690460888357, 0.79210657730021239,
    0.78834642762660634, 0.78455659715557524, 0.78073722857209449,
    0.77688846567323244, 0.773010453362737, 0.7691033376455797,
    0.765167265622459, 0.76120238548426178, 0.75720884650648457,
    0.75318679904361252, 0.74913639452345937, 0.745057785441466,
    0.74095112535495922, 0.73681656887736979, 0.73265427167241282,
    0.7284643904482252, 0.724247082951467, 0.72000250796138165,
    0.71573082528381859, 0.71143219574521643, 0.70710678118654757,
    0.7027547444572253, 0.69837624940897292, 0.69397146088965389,
    0.68954054473706683, 0.68508366777270036, 0.680600997795453,
    0.67609270357531592, 0.67155895484701833, 0.66699992230363747,
    0.66241577759017178, 0.65780669329707864, 0.65317284295377676,
    0.64851440102211244, 0.64383154288979139, 0.63912444486377573,
    0.63439328416364549, 0.629638238914927, 0.62485948814238634,
    0.6200572117632891, 0.61523159058062682, 0.61038280627630948,
    0.60551104140432555, 0.600616479383869, 0.59569930449243336,
    0.59075970185887416, 0.58579785745643886, 0.58081395809576453,
    0.57580819141784534, 0.57078074588696726, 0.56573181078361312,
    0.560661576197336, 0.55557023301960218, 0.55045797293660481,
    0.54532498842204646, 0.54017147272989285, 0.53499761988709715,
    0.52980362468629461, 0.524589682678469, 0.51935599016558964,
    0.51410274419322166, 0.508830142543107, 0.50353838372571758,
    0.49822766697278181, 0.49289819222978404, 0.487550160148436,
    0.48218377207912272, 0.47679923006332209, 0.47139673682599764,
    0.46597649576796618, 0.46053871095824, 0.45508358712634384,
    0.44961132965460654, 0.4441221445704292, 0.43861623853852766,
    0.43309381885315196, 0.42755509343028208, 0.42200027079979968,
    0.41642956009763715, 0.41084317105790391, 0.40524131400498986,
    0.39962419984564679, 0.3939920400610481, 0.38834504669882625,
    0.38268343236508978, 0.37700741021641826, 0.37131719395183749,
    0.36561299780477385, 0.35989503653498811, 0.35416352542049034,
    0.34841868024943456, 0.34266071731199438, 0.33688985339222005,
    0.33110630575987643, 0.32531029216226293, 0.31950203081601569,
    0.31368174039889152, 0.30784964004153487, 0.30200594931922808,
    0.29615088824362379, 0.29028467725446233, 0.28440753721127188,
    0.27851968938505306, 0.272621355449949, 0.26671275747489837,
    0.26079411791527551, 0.25486565960451457, 0.24892760574572015,
    0.24298017990326387, 0.2370236059943672, 0.23105810828067111,
    0.22508391135979283, 0.2191012401568698, 0.21311031991609136,
    0.20711137619221856, 0.2011046348420919, 0.19509032201612825,
    0.18906866414980619, 0.18303988795514095, 0.17700422041214875,
    0.17096188876030122, 0.16491312048996992, 0.15885814333386145,
    0.15279718525844344, 0.14673047445536175, 0.14065823933284921,
    0.13458070850712617, 0.12849811079379317, 0.1224106751992162,
    0.11631863091190475, 0.11022220729388306, 0.10412163387205459,
    0.0980171403295606, 0.091908956497132724, 0.0857973123444399,
    0.079682437971430126, 0.073564563599667426, 0.067443919563664051,
    0.061320736302208578, 0.055195244349689941, 0.049067674327418015,
    0.04293825693494082, 0.036807222941358832, 0.030674803176636626,
    0.024541228522912288, 0.01840672990580482, 0.012271538285719925,
    0.0061358846491544753, 0.0, -0.0061358846491544753, -0.012271538285719925,
    -0.01840672990580482, -0.024541228522912288, -0.030674803176636626,
    -0.036807222941358832, -0.04293825693494082, -0.049067674327418015,
    -0.055195244349689941, -0.061320736302208578, -0.067443919563664051,
    -0.073564563599667426, -0.079682437971430126, -0.0857973123444399,
    -0.091908956497132724, -0.0980171403295606, -0.10412163387205459,
    -0.11022220729388306, -0.11631863091190475, -0.1224106751992162,
    -0.12849811079379317, -0.13458070850712617, -0.14065823933284921,
    -0.14673047445536175, -0.15279718525844344, -0.15885814333386145,
    -0.16491312048996992, -0.17096188876030122, -0.17700422041214875,
    -0.18303988795514095, -0.18906866414980619, -0.19509032201612825,
    -0.2011046348420919, -0.20711137619221856, -0.21311031991609136,
    -0.2191012401568698, -0.22508391135979283, -0.23105810828067111,
    -0.2370236059943672, -0.24298017990326387, -0.24892760574572015,
    -0.25486565960451457, -0.26079411791527551, -0.26671275747489837,
    -0.272621355449949, -0.27851968938505306, -0.28440753721127188,
    -0.29028467725446233, -0.29615088824362379, -0.30200594931922808,
    -0.30784964004153487, -0.31368174039889152, -0.31950203081601569,
    -0.32531029216226293, -0.33110630575987643, -0.33688985339222005,
    -0.34266071731199438, -0.34841868024943456, -0.35416352542049034,
    -0.35989503653498811, -0.36561299780477385, -0.37131719395183749,
    -0.37700741021641826, -0.38268343236508978, -0.38834504669882625,
    -0.3939920400610481, -0.39962419984564679, -0.40524131400498986,
    -0.41084317105790391, -0.41642956009763715, -0.42200027079979968,
    -0.42755509343028208, -0.43309381885315196, -0.43861623853852766,
    -0.4441221445704292, -0.44961132965460654, -0.45508358712634384,
    -0.46053871095824, -0.46597649576796618, -0.47139673682599764,
    -0.47679923006332209, -0.48218377207912272, -0.487550160148436,
    -0.49289819222978404, -0.49822766697278181, -0.50353838372571758,
    -0.508830142543107, -0.51410274419322166, -0.51935599016558964,
    -0.524589682678469, -0.52980362468629461, -0.53499761988709715,
    -0.54017147272989285, -0.54532498842204646, -0.55045797293660481,
    -0.55557023301960218, -0.560661576197336, -0.56573181078361312,
    -0.57078074588696726, -0.57580819141784534, -0.58081395809576453,
    -0.58579785745643886, -0.59075970185887416, -0.59569930449243336,
    -0.600616479383869, -0.60551104140432555, -0.61038280627630948,
    -0.61523159058062682, -0.6200572117632891, -0.62485948814238634,
    -0.629638238914927, -0.63439328416364549, -0.63912444486377573,
    -0.64383154288979139, -0.64851440102211244, -0.65317284295377676,
    -0.65780669329707864, -0.66241577759017178, -0.66699992230363747,
    -0.67155895484701833, -0.67609270357531592, -0.680600997795453,
    -0.68508366777270036, -0.68954054473706683, -0.69397146088965389,
    -0.69837624940897292, -0.7027547444572253, -0.70710678118654757,
    -0.71143219574521643, -0.71573082528381859, -0.72000250796138165,
    -0.724247082951467, -0.7284643904482252, -0.73265427167241282,
    -0.73681656887736979, -0.74095112535495922, -0.745057785441466,
    -0.74913639452345937, -0.75318679904361252, -0.75720884650648457,
    -0.76120238548426178, -0.765167265622459, -0.7691033376455797,
    -0.773010453362737, -0.77688846567323244, -0.78073722857209449,
    -0.78455659715557524, -0.78834642762660634, -0.79210657730021239,
    -0.79583690460888357, -0.799537269107905, -0.80320753148064494,
    -0.80684755354379933, -0.81045719825259477, -0.81403632970594841,
    -0.81758481315158371, -0.82110251499110465, -0.82458930278502529,
    -0.8280450452577558, -0.83146961230254524, -0.83486287498638,
    -0.83822470555483808, -0.84155497743689844, -0.84485356524970712,
    -0.84812034480329723, -0.8513551931052652, -0.85455798836540053,
    -0.85772861000027212, -0.86086693863776731, -0.8639728561215867,
    -0.86704624551569265, -0.87008699110871146, -0.87309497841829009,
    -0.8760700941954066, -0.87901222642863353, -0.881921264348355,
    -0.88479709843093779, -0.88763962040285393, -0.89044872324475788,
    -0.89322430119551532, -0.89596624975618522, -0.89867446569395382,
    -0.901348847046022, -0.90398929312344334, -0.90659570451491533,
    -0.90916798309052238, -0.91170603200542988, -0.91420975570353069,
    -0.9166790599210427, -0.91911385169005777, -0.9215140393420419,
    -0.92387953251128674, -0.92621024213831138, -0.92850608047321559,
    -0.93076696107898371, -0.932992798834739, -0.93518350993894761,
    -0.937339011912575, -0.93945922360218992, -0.94154406518302081,
    -0.94359345816196039, -0.94560732538052128, -0.94758559101774109,
    -0.94952818059303667, -0.95143502096900834, -0.95330604035419386,
    -0.95514116830577078, -0.95694033573220882, -0.9587034748958716,
    -0.96043051941556579, -0.96212140426904158, -0.96377606579543984,
    -0.9653944416976894, -0.96697647104485207, -0.96852209427441727,
    -0.970031253194544, -0.97150389098625178, -0.97293995220556018,
    -0.97433938278557586, -0.97570213003852857, -0.97702814265775439,
    -0.97831737071962765, -0.97956976568544052, -0.98078528040323043,
    -0.98196386910955524, -0.98310548743121629, -0.984210092386929,
    -0.98527764238894122, -0.98630809724459867, -0.98730141815785843,
    -0.98825756773074946, -0.989176509964781, -0.99005821026229712,
    -0.99090263542778, -0.99170975366909953, -0.99247953459871,
    -0.9932119492347945, -0.99390697000235606, -0.99456457073425542,
    -0.99518472667219693, -0.99576741446765982, -0.996312612182778,
    -0.99682029929116567, -0.99729045667869021, -0.99772306664419164,
    -0.99811811290014918, -0.99847558057329477, -0.99879545620517241,
    -0.99907772775264536, -0.99932238458834954, -0.99952941750109314,
    -0.99969881869620425, -0.9998305817958234, -0.9999247018391445,
    -0.99998117528260111, -1.0 };

  creal_T c1_twid;
  static real_T c1_dv3[513] = { 0.0, -0.0061358846491544753,
    -0.012271538285719925, -0.01840672990580482, -0.024541228522912288,
    -0.030674803176636626, -0.036807222941358832, -0.04293825693494082,
    -0.049067674327418015, -0.055195244349689941, -0.061320736302208578,
    -0.067443919563664051, -0.073564563599667426, -0.079682437971430126,
    -0.0857973123444399, -0.091908956497132724, -0.0980171403295606,
    -0.10412163387205459, -0.11022220729388306, -0.11631863091190475,
    -0.1224106751992162, -0.12849811079379317, -0.13458070850712617,
    -0.14065823933284921, -0.14673047445536175, -0.15279718525844344,
    -0.15885814333386145, -0.16491312048996992, -0.17096188876030122,
    -0.17700422041214875, -0.18303988795514095, -0.18906866414980619,
    -0.19509032201612825, -0.2011046348420919, -0.20711137619221856,
    -0.21311031991609136, -0.2191012401568698, -0.22508391135979283,
    -0.23105810828067111, -0.2370236059943672, -0.24298017990326387,
    -0.24892760574572015, -0.25486565960451457, -0.26079411791527551,
    -0.26671275747489837, -0.272621355449949, -0.27851968938505306,
    -0.28440753721127188, -0.29028467725446233, -0.29615088824362379,
    -0.30200594931922808, -0.30784964004153487, -0.31368174039889152,
    -0.31950203081601569, -0.32531029216226293, -0.33110630575987643,
    -0.33688985339222005, -0.34266071731199438, -0.34841868024943456,
    -0.35416352542049034, -0.35989503653498811, -0.36561299780477385,
    -0.37131719395183749, -0.37700741021641826, -0.38268343236508978,
    -0.38834504669882625, -0.3939920400610481, -0.39962419984564679,
    -0.40524131400498986, -0.41084317105790391, -0.41642956009763715,
    -0.42200027079979968, -0.42755509343028208, -0.43309381885315196,
    -0.43861623853852766, -0.4441221445704292, -0.44961132965460654,
    -0.45508358712634384, -0.46053871095824, -0.46597649576796618,
    -0.47139673682599764, -0.47679923006332209, -0.48218377207912272,
    -0.487550160148436, -0.49289819222978404, -0.49822766697278181,
    -0.50353838372571758, -0.508830142543107, -0.51410274419322166,
    -0.51935599016558964, -0.524589682678469, -0.52980362468629461,
    -0.53499761988709715, -0.54017147272989285, -0.54532498842204646,
    -0.55045797293660481, -0.55557023301960218, -0.560661576197336,
    -0.56573181078361312, -0.57078074588696726, -0.57580819141784534,
    -0.58081395809576453, -0.58579785745643886, -0.59075970185887416,
    -0.59569930449243336, -0.600616479383869, -0.60551104140432555,
    -0.61038280627630948, -0.61523159058062682, -0.6200572117632891,
    -0.62485948814238634, -0.629638238914927, -0.63439328416364549,
    -0.63912444486377573, -0.64383154288979139, -0.64851440102211244,
    -0.65317284295377676, -0.65780669329707864, -0.66241577759017178,
    -0.66699992230363747, -0.67155895484701833, -0.67609270357531592,
    -0.680600997795453, -0.68508366777270036, -0.68954054473706683,
    -0.69397146088965389, -0.69837624940897292, -0.7027547444572253,
    -0.70710678118654757, -0.71143219574521643, -0.71573082528381859,
    -0.72000250796138165, -0.724247082951467, -0.7284643904482252,
    -0.73265427167241282, -0.73681656887736979, -0.74095112535495922,
    -0.745057785441466, -0.74913639452345937, -0.75318679904361252,
    -0.75720884650648457, -0.76120238548426178, -0.765167265622459,
    -0.7691033376455797, -0.773010453362737, -0.77688846567323244,
    -0.78073722857209449, -0.78455659715557524, -0.78834642762660634,
    -0.79210657730021239, -0.79583690460888357, -0.799537269107905,
    -0.80320753148064494, -0.80684755354379933, -0.81045719825259477,
    -0.81403632970594841, -0.81758481315158371, -0.82110251499110465,
    -0.82458930278502529, -0.8280450452577558, -0.83146961230254524,
    -0.83486287498638, -0.83822470555483808, -0.84155497743689844,
    -0.84485356524970712, -0.84812034480329723, -0.8513551931052652,
    -0.85455798836540053, -0.85772861000027212, -0.86086693863776731,
    -0.8639728561215867, -0.86704624551569265, -0.87008699110871146,
    -0.87309497841829009, -0.8760700941954066, -0.87901222642863353,
    -0.881921264348355, -0.88479709843093779, -0.88763962040285393,
    -0.89044872324475788, -0.89322430119551532, -0.89596624975618522,
    -0.89867446569395382, -0.901348847046022, -0.90398929312344334,
    -0.90659570451491533, -0.90916798309052238, -0.91170603200542988,
    -0.91420975570353069, -0.9166790599210427, -0.91911385169005777,
    -0.9215140393420419, -0.92387953251128674, -0.92621024213831138,
    -0.92850608047321559, -0.93076696107898371, -0.932992798834739,
    -0.93518350993894761, -0.937339011912575, -0.93945922360218992,
    -0.94154406518302081, -0.94359345816196039, -0.94560732538052128,
    -0.94758559101774109, -0.94952818059303667, -0.95143502096900834,
    -0.95330604035419386, -0.95514116830577078, -0.95694033573220882,
    -0.9587034748958716, -0.96043051941556579, -0.96212140426904158,
    -0.96377606579543984, -0.9653944416976894, -0.96697647104485207,
    -0.96852209427441727, -0.970031253194544, -0.97150389098625178,
    -0.97293995220556018, -0.97433938278557586, -0.97570213003852857,
    -0.97702814265775439, -0.97831737071962765, -0.97956976568544052,
    -0.98078528040323043, -0.98196386910955524, -0.98310548743121629,
    -0.984210092386929, -0.98527764238894122, -0.98630809724459867,
    -0.98730141815785843, -0.98825756773074946, -0.989176509964781,
    -0.99005821026229712, -0.99090263542778, -0.99170975366909953,
    -0.99247953459871, -0.9932119492347945, -0.99390697000235606,
    -0.99456457073425542, -0.99518472667219693, -0.99576741446765982,
    -0.996312612182778, -0.99682029929116567, -0.99729045667869021,
    -0.99772306664419164, -0.99811811290014918, -0.99847558057329477,
    -0.99879545620517241, -0.99907772775264536, -0.99932238458834954,
    -0.99952941750109314, -0.99969881869620425, -0.9998305817958234,
    -0.9999247018391445, -0.99998117528260111, -1.0, -0.99998117528260111,
    -0.9999247018391445, -0.9998305817958234, -0.99969881869620425,
    -0.99952941750109314, -0.99932238458834954, -0.99907772775264536,
    -0.99879545620517241, -0.99847558057329477, -0.99811811290014918,
    -0.99772306664419164, -0.99729045667869021, -0.99682029929116567,
    -0.996312612182778, -0.99576741446765982, -0.99518472667219693,
    -0.99456457073425542, -0.99390697000235606, -0.9932119492347945,
    -0.99247953459871, -0.99170975366909953, -0.99090263542778,
    -0.99005821026229712, -0.989176509964781, -0.98825756773074946,
    -0.98730141815785843, -0.98630809724459867, -0.98527764238894122,
    -0.984210092386929, -0.98310548743121629, -0.98196386910955524,
    -0.98078528040323043, -0.97956976568544052, -0.97831737071962765,
    -0.97702814265775439, -0.97570213003852857, -0.97433938278557586,
    -0.97293995220556018, -0.97150389098625178, -0.970031253194544,
    -0.96852209427441727, -0.96697647104485207, -0.9653944416976894,
    -0.96377606579543984, -0.96212140426904158, -0.96043051941556579,
    -0.9587034748958716, -0.95694033573220882, -0.95514116830577078,
    -0.95330604035419386, -0.95143502096900834, -0.94952818059303667,
    -0.94758559101774109, -0.94560732538052128, -0.94359345816196039,
    -0.94154406518302081, -0.93945922360218992, -0.937339011912575,
    -0.93518350993894761, -0.932992798834739, -0.93076696107898371,
    -0.92850608047321559, -0.92621024213831138, -0.92387953251128674,
    -0.9215140393420419, -0.91911385169005777, -0.9166790599210427,
    -0.91420975570353069, -0.91170603200542988, -0.90916798309052238,
    -0.90659570451491533, -0.90398929312344334, -0.901348847046022,
    -0.89867446569395382, -0.89596624975618522, -0.89322430119551532,
    -0.89044872324475788, -0.88763962040285393, -0.88479709843093779,
    -0.881921264348355, -0.87901222642863353, -0.8760700941954066,
    -0.87309497841829009, -0.87008699110871146, -0.86704624551569265,
    -0.8639728561215867, -0.86086693863776731, -0.85772861000027212,
    -0.85455798836540053, -0.8513551931052652, -0.84812034480329723,
    -0.84485356524970712, -0.84155497743689844, -0.83822470555483808,
    -0.83486287498638, -0.83146961230254524, -0.8280450452577558,
    -0.82458930278502529, -0.82110251499110465, -0.81758481315158371,
    -0.81403632970594841, -0.81045719825259477, -0.80684755354379933,
    -0.80320753148064494, -0.799537269107905, -0.79583690460888357,
    -0.79210657730021239, -0.78834642762660634, -0.78455659715557524,
    -0.78073722857209449, -0.77688846567323244, -0.773010453362737,
    -0.7691033376455797, -0.765167265622459, -0.76120238548426178,
    -0.75720884650648457, -0.75318679904361252, -0.74913639452345937,
    -0.745057785441466, -0.74095112535495922, -0.73681656887736979,
    -0.73265427167241282, -0.7284643904482252, -0.724247082951467,
    -0.72000250796138165, -0.71573082528381859, -0.71143219574521643,
    -0.70710678118654757, -0.7027547444572253, -0.69837624940897292,
    -0.69397146088965389, -0.68954054473706683, -0.68508366777270036,
    -0.680600997795453, -0.67609270357531592, -0.67155895484701833,
    -0.66699992230363747, -0.66241577759017178, -0.65780669329707864,
    -0.65317284295377676, -0.64851440102211244, -0.64383154288979139,
    -0.63912444486377573, -0.63439328416364549, -0.629638238914927,
    -0.62485948814238634, -0.6200572117632891, -0.61523159058062682,
    -0.61038280627630948, -0.60551104140432555, -0.600616479383869,
    -0.59569930449243336, -0.59075970185887416, -0.58579785745643886,
    -0.58081395809576453, -0.57580819141784534, -0.57078074588696726,
    -0.56573181078361312, -0.560661576197336, -0.55557023301960218,
    -0.55045797293660481, -0.54532498842204646, -0.54017147272989285,
    -0.53499761988709715, -0.52980362468629461, -0.524589682678469,
    -0.51935599016558964, -0.51410274419322166, -0.508830142543107,
    -0.50353838372571758, -0.49822766697278181, -0.49289819222978404,
    -0.487550160148436, -0.48218377207912272, -0.47679923006332209,
    -0.47139673682599764, -0.46597649576796618, -0.46053871095824,
    -0.45508358712634384, -0.44961132965460654, -0.4441221445704292,
    -0.43861623853852766, -0.43309381885315196, -0.42755509343028208,
    -0.42200027079979968, -0.41642956009763715, -0.41084317105790391,
    -0.40524131400498986, -0.39962419984564679, -0.3939920400610481,
    -0.38834504669882625, -0.38268343236508978, -0.37700741021641826,
    -0.37131719395183749, -0.36561299780477385, -0.35989503653498811,
    -0.35416352542049034, -0.34841868024943456, -0.34266071731199438,
    -0.33688985339222005, -0.33110630575987643, -0.32531029216226293,
    -0.31950203081601569, -0.31368174039889152, -0.30784964004153487,
    -0.30200594931922808, -0.29615088824362379, -0.29028467725446233,
    -0.28440753721127188, -0.27851968938505306, -0.272621355449949,
    -0.26671275747489837, -0.26079411791527551, -0.25486565960451457,
    -0.24892760574572015, -0.24298017990326387, -0.2370236059943672,
    -0.23105810828067111, -0.22508391135979283, -0.2191012401568698,
    -0.21311031991609136, -0.20711137619221856, -0.2011046348420919,
    -0.19509032201612825, -0.18906866414980619, -0.18303988795514095,
    -0.17700422041214875, -0.17096188876030122, -0.16491312048996992,
    -0.15885814333386145, -0.15279718525844344, -0.14673047445536175,
    -0.14065823933284921, -0.13458070850712617, -0.12849811079379317,
    -0.1224106751992162, -0.11631863091190475, -0.11022220729388306,
    -0.10412163387205459, -0.0980171403295606, -0.091908956497132724,
    -0.0857973123444399, -0.079682437971430126, -0.073564563599667426,
    -0.067443919563664051, -0.061320736302208578, -0.055195244349689941,
    -0.049067674327418015, -0.04293825693494082, -0.036807222941358832,
    -0.030674803176636626, -0.024541228522912288, -0.01840672990580482,
    -0.012271538285719925, -0.0061358846491544753, -0.0 };

  int32_T c1_p_a;
  int32_T c1_f_b;
  int32_T c1_q_a;
  int32_T c1_g_b;
  int32_T c1_o_c;
  int32_T c1_r_a;
  int32_T c1_p_c;
  creal_T c1_b_temp;
  int32_T c1_s_a;
  int32_T c1_h_b;
  int32_T c1_q_c;
  int32_T c1_t_a;
  int32_T c1_r_c;
  int32_T c1_u_a;
  int32_T c1_s_c;
  int32_T c1_v_a;
  int32_T c1_t_c;
  int32_T c1_w_a;
  int32_T c1_u_c;
  int32_T c1_x_a;
  int32_T c1_i_b;
  int32_T c1_y_a;
  int32_T c1_ab_a;
  int32_T c1_j_b;
  int32_T c1_bb_a;
  int32_T c1_i32;
  int32_T c1_cb_a;
  int32_T c1_db_a;
  int32_T c1_k_b;
  c1_eml_assert_valid_dim(chartInstance);
  c1_b_x = c1_x;
  c1_eml_scalar_eg(chartInstance);
  for (c1_i31 = 0; c1_i31 < 1024; c1_i31++) {
    c1_y[c1_i31] = c1_dc0;
  }

  c1_y[0].re = c1_b_x;
  c1_y[0].im = 0.0;
  c1_check_forloop_overflow_error(chartInstance);
  for (c1_i = 0; c1_i < 1023; c1_i += 2) {
    c1_b_i = c1_i;
    c1_a = c1_b_i;
    c1_c = c1_a;
    c1_temp = c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_c + 2, 1, 1024, 1, 0) - 1];
    c1_b_a = c1_b_i;
    c1_b_c = c1_b_a;
    c1_c_a = c1_b_i;
    c1_c_c = c1_c_a;
    c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_c + 2, 1, 1024, 1, 0) - 1].re =
      c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_c_c + 1, 1, 1024, 1, 0) - 1].re -
      c1_temp.re;
    c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_c + 2, 1, 1024, 1, 0) - 1].im =
      c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_c_c + 1, 1, 1024, 1, 0) - 1].im -
      c1_temp.im;
    c1_d_a = c1_b_i;
    c1_d_c = c1_d_a;
    c1_e_a = c1_b_i;
    c1_e_c = c1_e_a;
    c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_d_c + 1, 1, 1024, 1, 0) - 1].re =
      c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_e_c + 1, 1, 1024, 1, 0) - 1].re +
      c1_temp.re;
    c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_d_c + 1, 1, 1024, 1, 0) - 1].im =
      c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_e_c + 1, 1, 1024, 1, 0) - 1].im +
      c1_temp.im;
  }

  c1_iDelta = 2;
  c1_iDelta2 = 4;
  c1_k = 256;
  c1_iheight = 1021;
  while (c1_k > 0) {
    c1_b_i = 0;
    c1_b = c1_iheight;
    c1_ihi = c1_b;
    while (c1_b_i < c1_ihi) {
      c1_f_a = c1_b_i;
      c1_b_b = c1_iDelta;
      c1_f_c = c1_f_a + c1_b_b;
      c1_g_a = c1_f_c;
      c1_g_c = c1_g_a;
      c1_temp = c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_g_c + 1, 1, 1024, 1, 0)
        - 1];
      c1_h_a = c1_b_i;
      c1_c_b = c1_iDelta;
      c1_h_c = c1_h_a + c1_c_b;
      c1_i_a = c1_h_c;
      c1_i_c = c1_i_a;
      c1_j_a = c1_b_i;
      c1_j_c = c1_j_a;
      c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_i_c + 1, 1, 1024, 1, 0) - 1].re =
        c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_j_c + 1, 1, 1024, 1, 0) - 1].re
        - c1_temp.re;
      c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_i_c + 1, 1, 1024, 1, 0) - 1].im =
        c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_j_c + 1, 1, 1024, 1, 0) - 1].im
        - c1_temp.im;
      c1_k_a = c1_b_i;
      c1_k_c = c1_k_a;
      c1_l_a = c1_b_i;
      c1_l_c = c1_l_a;
      c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_k_c + 1, 1, 1024, 1, 0) - 1].re =
        c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_l_c + 1, 1, 1024, 1, 0) - 1].re
        + c1_temp.re;
      c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_k_c + 1, 1, 1024, 1, 0) - 1].im =
        c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_l_c + 1, 1, 1024, 1, 0) - 1].im
        + c1_temp.im;
      c1_m_a = c1_b_i;
      c1_d_b = c1_iDelta2;
      c1_b_i = c1_m_a + c1_d_b;
    }

    c1_istart = 1;
    c1_e_b = c1_k;
    for (c1_j = c1_e_b; c1_j < 512; c1_j = c1_ab_a + c1_j_b) {
      c1_n_a = c1_j;
      c1_m_c = c1_n_a;
      c1_o_a = c1_j;
      c1_n_c = c1_o_a;
      c1_twid.re = c1_dv2[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_m_c + 1, 1, 513, 1,
        0) - 1];
      c1_twid.im = c1_dv3[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_n_c + 1, 1, 513, 1,
        0) - 1];
      c1_b_i = c1_istart;
      c1_p_a = c1_b_i;
      c1_f_b = c1_iheight;
      c1_ihi = c1_p_a + c1_f_b;
      while (c1_b_i < c1_ihi) {
        c1_q_a = c1_b_i;
        c1_g_b = c1_iDelta;
        c1_o_c = c1_q_a + c1_g_b;
        c1_r_a = c1_o_c;
        c1_p_c = c1_r_a;
        c1_temp = c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_p_c + 1, 1, 1024, 1, 0)
          - 1];
        c1_b_temp = c1_temp;
        c1_temp.re = c1_twid.re * c1_b_temp.re - c1_twid.im * c1_b_temp.im;
        c1_temp.im = c1_twid.re * c1_b_temp.im + c1_twid.im * c1_b_temp.re;
        c1_s_a = c1_b_i;
        c1_h_b = c1_iDelta;
        c1_q_c = c1_s_a + c1_h_b;
        c1_t_a = c1_q_c;
        c1_r_c = c1_t_a;
        c1_u_a = c1_b_i;
        c1_s_c = c1_u_a;
        c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_r_c + 1, 1, 1024, 1, 0) - 1].re =
          c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_s_c + 1, 1, 1024, 1, 0) - 1].
          re - c1_temp.re;
        c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_r_c + 1, 1, 1024, 1, 0) - 1].im =
          c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_s_c + 1, 1, 1024, 1, 0) - 1].
          im - c1_temp.im;
        c1_v_a = c1_b_i;
        c1_t_c = c1_v_a;
        c1_w_a = c1_b_i;
        c1_u_c = c1_w_a;
        c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_t_c + 1, 1, 1024, 1, 0) - 1].re =
          c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_u_c + 1, 1, 1024, 1, 0) - 1].
          re + c1_temp.re;
        c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_t_c + 1, 1, 1024, 1, 0) - 1].im =
          c1_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_u_c + 1, 1, 1024, 1, 0) - 1].
          im + c1_temp.im;
        c1_x_a = c1_b_i;
        c1_i_b = c1_iDelta2;
        c1_b_i = c1_x_a + c1_i_b;
      }

      c1_y_a = c1_istart + 1;
      c1_istart = c1_y_a;
      c1_ab_a = c1_j;
      c1_j_b = c1_k;
    }

    c1_bb_a = c1_k;
    c1_i32 = c1_bb_a;
    c1_k = (c1_i32 + (c1_i32 < 0)) >> 1;
    c1_iDelta = c1_iDelta2;
    c1_cb_a = c1_iDelta;
    c1_iDelta2 = c1_cb_a << 1;
    c1_db_a = c1_iheight;
    c1_k_b = c1_iDelta;
    c1_iheight = c1_db_a - c1_k_b;
  }
}

static void c1_eml_assert_valid_dim
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance)
{
}

static void c1_eml_scalar_eg(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct
  *chartInstance)
{
}

static void c1_check_forloop_overflow_error
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance)
{
}

static void c1_ipermute(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct
  *chartInstance, creal_T c1_b[1024], creal_T c1_a[1024])
{
  int32_T c1_i33;
  for (c1_i33 = 0; c1_i33 < 1024; c1_i33++) {
    c1_a[c1_i33] = c1_b[c1_i33];
  }
}

static void c1_abs(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance,
                   creal_T c1_x[513], real_T c1_y[513])
{
  int32_T c1_k;
  real_T c1_b_k;
  creal_T c1_b_x;
  real_T c1_x1;
  real_T c1_x2;
  real_T c1_a;
  real_T c1_b;
  real_T c1_b_y;
  for (c1_k = 0; c1_k < 513; c1_k++) {
    c1_b_k = 1.0 + (real_T)c1_k;
    c1_b_x = c1_x[(int32_T)c1_b_k - 1];
    c1_x1 = c1_b_x.re;
    c1_x2 = c1_b_x.im;
    c1_a = muDoubleScalarAbs(c1_x1);
    c1_b = muDoubleScalarAbs(c1_x2);
    c1_b_y = muDoubleScalarHypot(c1_a, c1_b);
    c1_y[(int32_T)c1_b_k - 1] = c1_b_y;
  }
}

static void c1_b_abs(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct
                     *chartInstance, real_T c1_x[513], real_T c1_y[513])
{
  int32_T c1_k;
  real_T c1_b_k;
  real_T c1_b_x;
  real_T c1_b_y;
  for (c1_k = 0; c1_k < 513; c1_k++) {
    c1_b_k = 1.0 + (real_T)c1_k;
    c1_b_x = c1_x[(int32_T)c1_b_k - 1];
    c1_b_y = muDoubleScalarAbs(c1_b_x);
    c1_y[(int32_T)c1_b_k - 1] = c1_b_y;
  }
}

static void c1_eml_li_find(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct
  *chartInstance, boolean_T c1_x[513], int32_T c1_y_data[513], int32_T
  c1_y_sizes[2])
{
  int32_T c1_k;
  int32_T c1_i;
  int32_T c1_b_i;
  int32_T c1_a;
  const mxArray *c1_y = NULL;
  int32_T c1_tmp_sizes[2];
  int32_T c1_iv0[2];
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_loop_ub;
  int32_T c1_i36;
  int32_T c1_tmp_data[513];
  int32_T c1_i37;
  int32_T c1_j;
  int32_T c1_c_i;
  int32_T c1_d_i;
  int32_T c1_b_a;
  c1_k = 0;
  c1_check_forloop_overflow_error(chartInstance);
  for (c1_i = 1; c1_i < 514; c1_i++) {
    c1_b_i = c1_i - 1;
    if (c1_x[c1_b_i]) {
      c1_a = c1_k + 1;
      c1_k = c1_a;
    }
  }

  if (c1_k <= 513) {
  } else {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", "Assertion failed.", 15, 0U, 0U, 0U,
      2, 1, strlen("Assertion failed.")), FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, c1_y);
  }

  c1_tmp_sizes[0] = 1;
  c1_iv0[0] = 1;
  c1_iv0[1] = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c1_k);
  c1_tmp_sizes[1] = c1_iv0[1];
  c1_i34 = c1_tmp_sizes[0];
  c1_i35 = c1_tmp_sizes[1];
  c1_loop_ub = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c1_k) - 1;
  for (c1_i36 = 0; c1_i36 <= c1_loop_ub; c1_i36++) {
    c1_tmp_data[c1_i36] = 0;
  }

  for (c1_i37 = 0; c1_i37 < 2; c1_i37++) {
    c1_y_sizes[c1_i37] = c1_tmp_sizes[c1_i37];
  }

  c1_j = 1;
  c1_check_forloop_overflow_error(chartInstance);
  for (c1_c_i = 1; c1_c_i < 514; c1_c_i++) {
    c1_d_i = c1_c_i;
    if (c1_x[c1_d_i - 1]) {
      c1_y_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_j, 1, c1_y_sizes[1], 1, 0) -
        1] = c1_d_i;
      c1_b_a = c1_j + 1;
      c1_j = c1_b_a;
    }
  }
}

static real_T c1_norm(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct
                      *chartInstance, real_T c1_x[575])
{
  int32_T c1_n;
  int32_T c1_incx;
  c1_n = 575;
  c1_incx = 1;
  return dnrm232(&c1_n, &c1_x[0], &c1_incx);
}

static real_T c1_b_norm(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct
  *chartInstance, real_T c1_x)
{
  real_T c1_b_x;
  real_T c1_c_x;
  c1_b_x = c1_x;
  c1_c_x = c1_b_x;
  return muDoubleScalarAbs(c1_c_x);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance;
  chartInstance = (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_f_emlrt_marshallIn
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i38;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i38, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i38;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance;
  chartInstance = (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *)
    chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_g_emlrt_marshallIn
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance, const mxArray
   *c1_b_is_active_c1_sim_Motor_2kW_openloop_THD, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_sim_Motor_2kW_openloop_THD), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_sim_Motor_2kW_openloop_THD);
  return c1_y;
}

static uint8_T c1_h_emlrt_marshallIn
  (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *
  chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_sim_Motor_2kW_openloop_THD_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(873569180U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2078509571U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1179161902U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1553775212U);
}

mxArray *sf_c1_sim_Motor_2kW_openloop_THD_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Wo3iqYGEPiuPQXPoHVSriG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_sim_Motor_2kW_openloop_THD(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"THD\",},{M[8],M[0],T\"is_active_c1_sim_Motor_2kW_openloop_THD\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_sim_Motor_2kW_openloop_THD_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance;
    chartInstance = (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_sim_Motor_2kW_openloop_THDMachineNumber_,
           1,
           1,
           1,
           2,
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
            (_sim_Motor_2kW_openloop_THDMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_sim_Motor_2kW_openloop_THDMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_sim_Motor_2kW_openloop_THDMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"THD");
          _SFD_SET_DATA_PROPS(1,1,1,0,"stored_out");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,1,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2521);
        _SFD_CV_INIT_EML_WHILE(0,1,0,2149,2161,2424);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c1_THD;
          real_T *c1_stored_out;
          c1_stored_out = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c1_THD = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_THD);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_stored_out);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_sim_Motor_2kW_openloop_THDMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "kx7Uc0YcfZwdGf1wxLiiwF";
}

static void sf_opaque_initialize_c1_sim_Motor_2kW_openloop_THD(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_sim_Motor_2kW_openloop_THDInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_sim_Motor_2kW_openloop_THD
    ((SFc1_sim_Motor_2kW_openloop_THDInstanceStruct*) chartInstanceVar);
  initialize_c1_sim_Motor_2kW_openloop_THD
    ((SFc1_sim_Motor_2kW_openloop_THDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_sim_Motor_2kW_openloop_THD(void
  *chartInstanceVar)
{
  enable_c1_sim_Motor_2kW_openloop_THD
    ((SFc1_sim_Motor_2kW_openloop_THDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_sim_Motor_2kW_openloop_THD(void
  *chartInstanceVar)
{
  disable_c1_sim_Motor_2kW_openloop_THD
    ((SFc1_sim_Motor_2kW_openloop_THDInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_sim_Motor_2kW_openloop_THD(void
  *chartInstanceVar)
{
  sf_c1_sim_Motor_2kW_openloop_THD
    ((SFc1_sim_Motor_2kW_openloop_THDInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_sim_Motor_2kW_openloop_THD
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_sim_Motor_2kW_openloop_THD
    ((SFc1_sim_Motor_2kW_openloop_THDInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_sim_Motor_2kW_openloop_THD();/* state var info */
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

extern void sf_internal_set_sim_state_c1_sim_Motor_2kW_openloop_THD(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_sim_Motor_2kW_openloop_THD();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_sim_Motor_2kW_openloop_THD
    ((SFc1_sim_Motor_2kW_openloop_THDInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_sim_Motor_2kW_openloop_THD
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c1_sim_Motor_2kW_openloop_THD(S);
}

static void sf_opaque_set_sim_state_c1_sim_Motor_2kW_openloop_THD(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c1_sim_Motor_2kW_openloop_THD(S, st);
}

static void sf_opaque_terminate_c1_sim_Motor_2kW_openloop_THD(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_sim_Motor_2kW_openloop_THDInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_sim_Motor_2kW_openloop_THD
      ((SFc1_sim_Motor_2kW_openloop_THDInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_sim_Motor_2kW_openloop_THD_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_sim_Motor_2kW_openloop_THD
    ((SFc1_sim_Motor_2kW_openloop_THDInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_sim_Motor_2kW_openloop_THD(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_sim_Motor_2kW_openloop_THD
      ((SFc1_sim_Motor_2kW_openloop_THDInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_sim_Motor_2kW_openloop_THD(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_sim_Motor_2kW_openloop_THD_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(340551302U));
  ssSetChecksum1(S,(2434856984U));
  ssSetChecksum2(S,(1175241772U));
  ssSetChecksum3(S,(1491947735U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_sim_Motor_2kW_openloop_THD(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_sim_Motor_2kW_openloop_THD(SimStruct *S)
{
  SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *chartInstance;
  chartInstance = (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct *)malloc(sizeof
    (SFc1_sim_Motor_2kW_openloop_THDInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_sim_Motor_2kW_openloop_THDInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_sim_Motor_2kW_openloop_THD;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_sim_Motor_2kW_openloop_THD;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_sim_Motor_2kW_openloop_THD;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_sim_Motor_2kW_openloop_THD;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_sim_Motor_2kW_openloop_THD;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_sim_Motor_2kW_openloop_THD;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_sim_Motor_2kW_openloop_THD;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_sim_Motor_2kW_openloop_THD;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_sim_Motor_2kW_openloop_THD;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_sim_Motor_2kW_openloop_THD;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_sim_Motor_2kW_openloop_THD;
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

void c1_sim_Motor_2kW_openloop_THD_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_sim_Motor_2kW_openloop_THD(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_sim_Motor_2kW_openloop_THD(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_sim_Motor_2kW_openloop_THD(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_sim_Motor_2kW_openloop_THD_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
