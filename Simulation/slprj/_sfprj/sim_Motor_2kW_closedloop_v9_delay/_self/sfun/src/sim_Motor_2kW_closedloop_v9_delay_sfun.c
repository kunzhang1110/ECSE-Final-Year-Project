/* Include files */

#include "sim_Motor_2kW_closedloop_v9_delay_sfun.h"
#include "c2_sim_Motor_2kW_closedloop_v9_delay.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _sim_Motor_2kW_closedloop_v9_delayMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void sim_Motor_2kW_closedloop_v9_delay_initializer(void)
{
}

void sim_Motor_2kW_closedloop_v9_delay_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_sim_Motor_2kW_closedloop_v9_delay_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==2) {
    c2_sim_Motor_2kW_closedloop_v9_delay_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  return 0;
}

unsigned int sf_sim_Motor_2kW_closedloop_v9_delay_process_check_sum_call( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3137398449U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2059744525U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2628844096U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3219931584U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(307405229U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(11246377U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2764188863U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(650652222U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 2:
        {
          extern void sf_c2_sim_Motor_2kW_closedloop_v9_delay_get_check_sum
            (mxArray *plhs[]);
          sf_c2_sim_Motor_2kW_closedloop_v9_delay_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3564696471U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(678668628U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1090454852U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3896867807U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2745905335U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3021060793U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2460664759U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2839664535U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_sim_Motor_2kW_closedloop_v9_delay_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        if (strcmp(aiChksum, "NT71xzZ5CQ2By7l0u9xUqF") == 0) {
          extern mxArray
            *sf_c2_sim_Motor_2kW_closedloop_v9_delay_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c2_sim_Motor_2kW_closedloop_v9_delay_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int
  sf_sim_Motor_2kW_closedloop_v9_delay_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        extern const mxArray
          *sf_c2_sim_Motor_2kW_closedloop_v9_delay_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_sim_Motor_2kW_closedloop_v9_delay_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void sim_Motor_2kW_closedloop_v9_delay_debug_initialize(void)
{
  _sim_Motor_2kW_closedloop_v9_delayMachineNumber_ = sf_debug_initialize_machine
    ("sim_Motor_2kW_closedloop_v9_delay","sfun",0,1,0,0,0);
  sf_debug_set_machine_event_thresholds
    (_sim_Motor_2kW_closedloop_v9_delayMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds
    (_sim_Motor_2kW_closedloop_v9_delayMachineNumber_,0);
}

void sim_Motor_2kW_closedloop_v9_delay_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_sim_Motor_2kW_closedloop_v9_delay_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "sim_Motor_2kW_closedloop_v9_delay", "sim_Motor_2kW_closedloop_v9_delay");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_sim_Motor_2kW_closedloop_v9_delay_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
