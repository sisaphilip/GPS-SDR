/* Include files */

#include "blascompat32.h"
#include "gen_sfun.h"
#include "c2_gen.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "gen_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c2_debug_family_names[6] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "u", "y" };

/* Function Declarations */
static void initialize_c2_gen(SFc2_genInstanceStruct *chartInstance);
static void initialize_params_c2_gen(SFc2_genInstanceStruct *chartInstance);
static void enable_c2_gen(SFc2_genInstanceStruct *chartInstance);
static void disable_c2_gen(SFc2_genInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_gen(SFc2_genInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_gen(SFc2_genInstanceStruct *chartInstance);
static void set_sim_state_c2_gen(SFc2_genInstanceStruct *chartInstance, const
  mxArray *c2_st);
static void finalize_c2_gen(SFc2_genInstanceStruct *chartInstance);
static void sf_c2_gen(SFc2_genInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[31]);
static real_T c2_emlrt_marshallIn(SFc2_genInstanceStruct *chartInstance, const
  mxArray *c2_y, const char_T *c2_name);
static uint8_T c2_b_emlrt_marshallIn(SFc2_genInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_gen, const char_T *c2_name);
static void init_dsm_address_info(SFc2_genInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_gen(SFc2_genInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_gen = 0U;
}

static void initialize_params_c2_gen(SFc2_genInstanceStruct *chartInstance)
{
}

static void enable_c2_gen(SFc2_genInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_gen(SFc2_genInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_gen(SFc2_genInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_gen(SFc2_genInstanceStruct *chartInstance)
{
  const mxArray *c2_st = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T *c2_d_y;
  c2_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2));
  c2_hoistedGlobal = *c2_d_y;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = chartInstance->c2_is_active_c2_gen;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_gen(SFc2_genInstanceStruct *chartInstance, const
  mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_y;
  c2_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
    "y");
  chartInstance->c2_is_active_c2_gen = c2_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 1)), "is_active_c2_gen");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_gen(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_gen(SFc2_genInstanceStruct *chartInstance)
{
}

static void sf_c2_gen(SFc2_genInstanceStruct *chartInstance)
{
  int32_T c2_previousEvent;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  uint32_T c2_debug_family_var_map[6];
  boolean_T c2_aVarTruthTableCondition_1;
  boolean_T c2_aVarTruthTableCondition_2;
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  real_T c2_y;
  real_T c2_a;
  real_T c2_b_a;
  real_T c2_ak;
  real_T c2_c;
  real_T c2_B;
  real_T c2_b_y;
  real_T c2_c_y;
  real_T c2_d_y;
  real_T *c2_b_u;
  real_T *c2_e_y;
  c2_e_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  _SFD_DATA_RANGE_CHECK(*c2_b_u, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_e_y, 1U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  c2_hoistedGlobal = *c2_b_u;
  c2_u = c2_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_aVarTruthTableCondition_1, c2_b_sf_marshall,
    0U);
  sf_debug_symbol_scope_add_eml(&c2_aVarTruthTableCondition_2, c2_b_sf_marshall,
    1U);
  sf_debug_symbol_scope_add_eml(&c2_nargin, c2_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c2_nargout, c2_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c2_u, c2_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c2_y, c2_sf_marshall, 5U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,3);
  c2_aVarTruthTableCondition_1 = FALSE;
  _SFD_EML_CALL(0,4);
  c2_aVarTruthTableCondition_2 = FALSE;

  /*  Example condition 1 */
  _SFD_EML_CALL(0,9);
  c2_aVarTruthTableCondition_1 = (c2_u >= 0.0);

  /*  Example condition 2 */
  _SFD_EML_CALL(0,13);
  c2_a = c2_u;
  c2_b_a = c2_a;
  c2_ak = c2_b_a;
  c2_c = muDoubleScalarPower(c2_ak, 2.0);
  c2_aVarTruthTableCondition_2 = (c2_c <= 1.0);
  _SFD_EML_CALL(0,15);
  if (CV_EML_COND(0, 0, c2_aVarTruthTableCondition_1)) {
    if (CV_EML_COND(0, 1, c2_aVarTruthTableCondition_2)) {
      CV_EML_MCDC(0, 0, TRUE);
      CV_EML_IF(0, 0, TRUE);
      _SFD_EML_CALL(0,16);
      CV_EML_FCN(0, 1);

      /*  Example action 1 called from D1 & D2 column in condition table */
      _SFD_EML_CALL(0,27);
      c2_y = c2_u;
      _SFD_EML_CALL(0,-27);
      goto label_1;
    }
  }

  CV_EML_MCDC(0, 0, FALSE);
  CV_EML_IF(0, 0, FALSE);
  _SFD_EML_CALL(0,17);
  if (!CV_EML_COND(0, 2, c2_aVarTruthTableCondition_1)) {
    if (!CV_EML_COND(0, 3, c2_aVarTruthTableCondition_2)) {
      CV_EML_MCDC(0, 1, TRUE);
      CV_EML_IF(0, 1, TRUE);
      _SFD_EML_CALL(0,18);
      CV_EML_FCN(0, 1);

      /*  Example action 1 called from D1 & D2 column in condition table */
      _SFD_EML_CALL(0,27);
      c2_y = c2_u;
      _SFD_EML_CALL(0,-27);
      goto label_2;
    }
  }

  CV_EML_MCDC(0, 1, FALSE);
  CV_EML_IF(0, 1, FALSE);

  /*  Default */
  _SFD_EML_CALL(0,20);
  CV_EML_FCN(0, 2);

  /*  Example action 2 called from D3 column in condition table */
  _SFD_EML_CALL(0,33);
  c2_B = c2_u;
  c2_b_y = c2_B;
  c2_c_y = c2_b_y;
  c2_d_y = c2_c_y;
  c2_y = 1.0 / c2_d_y;
  _SFD_EML_CALL(0,-33);
 label_2:
  ;
 label_1:
  ;
  _SFD_EML_CALL(0,-20);
  sf_debug_symbol_scope_pop();
  *c2_e_y = c2_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_genMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_genInstanceStruct *chartInstance;
  chartInstance = (SFc2_genInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  boolean_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_genInstanceStruct *chartInstance;
  chartInstance = (SFc2_genInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((boolean_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray *sf_c2_gen_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[31];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i0;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 31));
  for (c2_i0 = 0; c2_i0 < 31; c2_i0 = c2_i0 + 1) {
    c2_r0 = &c2_info[c2_i0];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
                    "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name",
                    "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i0);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[31])
{
  c2_info[0].context = "";
  c2_info[0].name = "false";
  c2_info[0].dominantType = "";
  c2_info[0].resolved = "[B]false";
  c2_info[0].fileLength = 0U;
  c2_info[0].fileTime1 = 0U;
  c2_info[0].fileTime2 = 0U;
  c2_info[1].context = "";
  c2_info[1].name = "ge";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved = "[B]ge";
  c2_info[1].fileLength = 0U;
  c2_info[1].fileTime1 = 0U;
  c2_info[1].fileTime2 = 0U;
  c2_info[2].context = "";
  c2_info[2].name = "logical";
  c2_info[2].dominantType = "logical";
  c2_info[2].resolved = "[B]logical";
  c2_info[2].fileLength = 0U;
  c2_info[2].fileTime1 = 0U;
  c2_info[2].fileTime2 = 0U;
  c2_info[3].context = "";
  c2_info[3].name = "mpower";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[3].fileLength = 3710U;
  c2_info[3].fileTime1 = 1238466688U;
  c2_info[3].fileTime2 = 0U;
  c2_info[4].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[4].name = "nargin";
  c2_info[4].dominantType = "";
  c2_info[4].resolved = "[B]nargin";
  c2_info[4].fileLength = 0U;
  c2_info[4].fileTime1 = 0U;
  c2_info[4].fileTime2 = 0U;
  c2_info[5].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[5].name = "gt";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved = "[B]gt";
  c2_info[5].fileLength = 0U;
  c2_info[5].fileTime1 = 0U;
  c2_info[5].fileTime2 = 0U;
  c2_info[6].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[6].name = "isa";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved = "[B]isa";
  c2_info[6].fileLength = 0U;
  c2_info[6].fileTime1 = 0U;
  c2_info[6].fileTime2 = 0U;
  c2_info[7].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[7].name = "isinteger";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved = "[B]isinteger";
  c2_info[7].fileLength = 0U;
  c2_info[7].fileTime1 = 0U;
  c2_info[7].fileTime2 = 0U;
  c2_info[8].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[8].name = "isscalar";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved = "[B]isscalar";
  c2_info[8].fileLength = 0U;
  c2_info[8].fileTime1 = 0U;
  c2_info[8].fileTime2 = 0U;
  c2_info[9].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[9].name = "ndims";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved = "[B]ndims";
  c2_info[9].fileLength = 0U;
  c2_info[9].fileTime1 = 0U;
  c2_info[9].fileTime2 = 0U;
  c2_info[10].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[10].name = "eq";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved = "[B]eq";
  c2_info[10].fileLength = 0U;
  c2_info[10].fileTime1 = 0U;
  c2_info[10].fileTime2 = 0U;
  c2_info[11].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[11].name = "size";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved = "[B]size";
  c2_info[11].fileLength = 0U;
  c2_info[11].fileTime1 = 0U;
  c2_info[11].fileTime2 = 0U;
  c2_info[12].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[12].name = "power";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[12].fileLength = 5380U;
  c2_info[12].fileTime1 = 1228126298U;
  c2_info[12].fileTime2 = 0U;
  c2_info[13].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[13].name = "eml_scalar_eg";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[13].fileLength = 3068U;
  c2_info[13].fileTime1 = 1240294410U;
  c2_info[13].fileTime2 = 0U;
  c2_info[14].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[14].name = "isstruct";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved = "[B]isstruct";
  c2_info[14].fileLength = 0U;
  c2_info[14].fileTime1 = 0U;
  c2_info[14].fileTime2 = 0U;
  c2_info[15].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c2_info[15].name = "class";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved = "[B]class";
  c2_info[15].fileLength = 0U;
  c2_info[15].fileTime1 = 0U;
  c2_info[15].fileTime2 = 0U;
  c2_info[16].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c2_info[16].name = "cast";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved = "[B]cast";
  c2_info[16].fileLength = 0U;
  c2_info[16].fileTime1 = 0U;
  c2_info[16].fileTime2 = 0U;
  c2_info[17].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c2_info[17].name = "plus";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved = "[B]plus";
  c2_info[17].fileLength = 0U;
  c2_info[17].fileTime1 = 0U;
  c2_info[17].fileTime2 = 0U;
  c2_info[18].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/allreal";
  c2_info[18].name = "isreal";
  c2_info[18].dominantType = "double";
  c2_info[18].resolved = "[B]isreal";
  c2_info[18].fileLength = 0U;
  c2_info[18].fileTime1 = 0U;
  c2_info[18].fileTime2 = 0U;
  c2_info[19].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[19].name = "eml_scalexp_alloc";
  c2_info[19].dominantType = "double";
  c2_info[19].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[19].fileLength = 808U;
  c2_info[19].fileTime1 = 1230527098U;
  c2_info[19].fileTime2 = 0U;
  c2_info[20].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[20].name = "minus";
  c2_info[20].dominantType = "double";
  c2_info[20].resolved = "[B]minus";
  c2_info[20].fileLength = 0U;
  c2_info[20].fileTime1 = 0U;
  c2_info[20].fileTime2 = 0U;
  c2_info[21].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[21].name = "not";
  c2_info[21].dominantType = "logical";
  c2_info[21].resolved = "[B]not";
  c2_info[21].fileLength = 0U;
  c2_info[21].fileTime1 = 0U;
  c2_info[21].fileTime2 = 0U;
  c2_info[22].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[22].name = "lt";
  c2_info[22].dominantType = "double";
  c2_info[22].resolved = "[B]lt";
  c2_info[22].fileLength = 0U;
  c2_info[22].fileTime1 = 0U;
  c2_info[22].fileTime2 = 0U;
  c2_info[23].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[23].name = "eml_scalar_floor";
  c2_info[23].dominantType = "double";
  c2_info[23].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[23].fileLength = 260U;
  c2_info[23].fileTime1 = 1209363190U;
  c2_info[23].fileTime2 = 0U;
  c2_info[24].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[24].name = "ne";
  c2_info[24].dominantType = "double";
  c2_info[24].resolved = "[B]ne";
  c2_info[24].fileLength = 0U;
  c2_info[24].fileTime1 = 0U;
  c2_info[24].fileTime2 = 0U;
  c2_info[25].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[25].name = "eml_error";
  c2_info[25].dominantType = "char";
  c2_info[25].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[25].fileLength = 315U;
  c2_info[25].fileTime1 = 1213959144U;
  c2_info[25].fileTime2 = 0U;
  c2_info[26].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[26].name = "strcmp";
  c2_info[26].dominantType = "char";
  c2_info[26].resolved = "[B]strcmp";
  c2_info[26].fileLength = 0U;
  c2_info[26].fileTime1 = 0U;
  c2_info[26].fileTime2 = 0U;
  c2_info[27].context = "";
  c2_info[27].name = "le";
  c2_info[27].dominantType = "double";
  c2_info[27].resolved = "[B]le";
  c2_info[27].fileLength = 0U;
  c2_info[27].fileTime1 = 0U;
  c2_info[27].fileTime2 = 0U;
  c2_info[28].context = "";
  c2_info[28].name = "mrdivide";
  c2_info[28].dominantType = "double";
  c2_info[28].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[28].fileLength = 800U;
  c2_info[28].fileTime1 = 1238466690U;
  c2_info[28].fileTime2 = 0U;
  c2_info[29].context =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[29].name = "rdivide";
  c2_info[29].dominantType = "double";
  c2_info[29].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[29].fileLength = 403U;
  c2_info[29].fileTime1 = 1244767952U;
  c2_info[29].fileTime2 = 0U;
  c2_info[30].context = "[ILX]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[30].name = "eml_div";
  c2_info[30].dominantType = "double";
  c2_info[30].resolved =
    "[ILX]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[30].fileLength = 4269U;
  c2_info[30].fileTime1 = 1228126226U;
  c2_info[30].fileTime2 = 0U;
}

static real_T c2_emlrt_marshallIn(SFc2_genInstanceStruct *chartInstance, const
  mxArray *c2_y, const char_T *c2_name)
{
  real_T c2_b_y;
  real_T c2_d0;
  sf_mex_import(c2_name, sf_mex_dup(c2_y), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_b_y = c2_d0;
  sf_mex_destroy(&c2_y);
  return c2_b_y;
}

static uint8_T c2_b_emlrt_marshallIn(SFc2_genInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_gen, const char_T *
  c2_name)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_name, sf_mex_dup(c2_b_is_active_c2_gen), &c2_u0, 1, 3, 0U, 0,
                0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_b_is_active_c2_gen);
  return c2_y;
}

static void init_dsm_address_info(SFc2_genInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_gen_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3684197099U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2170209655U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1377263859U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2974323446U);
}

mxArray *sf_c2_gen_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3478457061U);
    pr[1] = (double)(2703388307U);
    pr[2] = (double)(449190641U);
    pr[3] = (double)(2254146112U);
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

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c2_gen(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c2_gen\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_gen_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_genInstanceStruct *chartInstance;
    chartInstance = (SFc2_genInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_genMachineNumber_,
          2,
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
          init_script_number_translation(_genMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_genMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_genMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"u",0,
                              (MexFcnForType)c2_sf_marshall);
          _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"y",0,
                              (MexFcnForType)c2_sf_marshall);
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,3,2,0,0,0,0,4,2);
        _SFD_CV_INIT_EML_FCN(0,0,"tt_blk_kernel",0,-1,471);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",471,-1,580);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",580,-1,687);
        _SFD_CV_INIT_EML_IF(0,0,235,294,325,469);
        _SFD_CV_INIT_EML_IF(0,1,325,390,421,469);

        {
          static int condStart[] = { 239, 268 };

          static int condEnd[] = { 264, 293 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,0,239,293,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        {
          static int condStart[] = { 334, 364 };

          static int condEnd[] = { 359, 389 };

          static int pfixExpr[] = { 0, -1, 1, -1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,333,389,2,2,&(condStart[0]),&(condEnd[0]),5,
                                &(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c2_u;
          real_T *c2_y;
          c2_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_y);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_genMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_gen(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_genInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c2_gen((SFc2_genInstanceStruct*) chartInstanceVar);
  initialize_c2_gen((SFc2_genInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_gen(void *chartInstanceVar)
{
  enable_c2_gen((SFc2_genInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_gen(void *chartInstanceVar)
{
  disable_c2_gen((SFc2_genInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_gen(void *chartInstanceVar)
{
  sf_c2_gen((SFc2_genInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c2_gen(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_gen((SFc2_genInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c2_gen();/* state var info */
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

static void sf_internal_set_sim_state_c2_gen(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_gen();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_gen((SFc2_genInstanceStruct*)chartInfo->chartInstance,
                       mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c2_gen(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_gen(S);
}

static void sf_opaque_set_sim_state_c2_gen(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_gen(S, st);
}

static void sf_opaque_terminate_c2_gen(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_genInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_gen((SFc2_genInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_gen(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_gen((SFc2_genInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_gen(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("gen","gen",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("gen","gen",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("gen","gen",2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"gen","gen",2,1);
      sf_mark_chart_reusable_outputs(S,"gen","gen",2,1);
    }

    sf_set_rtw_dwork_info(S,"gen","gen",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(1833680382U));
  ssSetChecksum1(S,(1051040521U));
  ssSetChecksum2(S,(4082857262U));
  ssSetChecksum3(S,(4272134196U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_gen(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "gen", "gen",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Truth Table");
  }
}

static void mdlStart_c2_gen(SimStruct *S)
{
  SFc2_genInstanceStruct *chartInstance;
  chartInstance = (SFc2_genInstanceStruct *)malloc(sizeof(SFc2_genInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_genInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_gen;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_gen;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_gen;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_gen;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_gen;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_gen;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_gen;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_gen;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_gen;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_gen;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_gen;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  if (!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info(chartInstance);
  }

  chart_debug_initialization(S,1);
}

void c2_gen_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_gen(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_gen(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_gen(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_gen_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
