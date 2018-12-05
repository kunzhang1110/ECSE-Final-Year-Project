/* Include files */

#include "open_loop_control_sfun.h"
#include "c2_open_loop_control.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _open_loop_controlMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void open_loop_control_initializer(void)
{
}

void open_loop_control_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_open_loop_control_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==2) {
    c2_open_loop_control_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_open_loop_control_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2037250310U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1240062345U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1870552158U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2186891392U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2245234012U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1003782448U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3794293412U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(210564012U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 2:
        {
          extern void sf_c2_open_loop_control_get_check_sum(mxArray *plhs[]);
          sf_c2_open_loop_control_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2931452166U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3925833004U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2684440014U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(894576764U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_open_loop_control_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
        if (strcmp(aiChksum, "rImX2xksSyiuZnf1zeY06D") == 0) {
          extern mxArray *sf_c2_open_loop_control_get_autoinheritance_info(void);
          plhs[0] = sf_c2_open_loop_control_get_autoinheritance_info();
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

unsigned int sf_open_loop_control_get_eml_resolved_functions_info( int nlhs,
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
          *sf_c2_open_loop_control_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_open_loop_control_get_eml_resolved_functions_info();
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

void open_loop_control_debug_initialize(void)
{
  _open_loop_controlMachineNumber_ = sf_debug_initialize_machine(
    "open_loop_control","sfun",0,1,0,0,0);
  sf_debug_set_machine_event_thresholds(_open_loop_controlMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_open_loop_controlMachineNumber_,0);
}

void open_loop_control_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_open_loop_control_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "open_loop_control", "open_loop_control");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_open_loop_control_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
