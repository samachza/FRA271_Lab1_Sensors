/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Encoder_reader_simulink.h
 *
 * Code generated for Simulink model 'Encoder_reader_simulink'.
 *
 * Model version                  : 3.1
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Wed Oct 15 09:38:19 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Encoder_reader_simulink_h_
#define Encoder_reader_simulink_h_
#ifndef Encoder_reader_simulink_COMMON_INCLUDES_
#define Encoder_reader_simulink_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "ext_mode.h"
#include "main.h"
#include "mw_stm32_utils.h"
#endif                            /* Encoder_reader_simulink_COMMON_INCLUDES_ */

#include "Encoder_reader_simulink_types.h"
#include "rtGetInf.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals for system '<S11>/Digital Port Read' */
typedef struct {
  boolean_T DigitalPortRead;           /* '<S11>/Digital Port Read' */
} B_DigitalPortRead_Encoder_rea_T;

/* Block states (default storage) for system '<S11>/Digital Port Read' */
typedef struct {
  stm32cube_blocks_DigitalPortR_T obj; /* '<S11>/Digital Port Read' */
  boolean_T objisempty;                /* '<S11>/Digital Port Read' */
} DW_DigitalPortRead_Encoder_re_T;

/* Block states (default storage) for system '<Root>/MATLAB Function' */
typedef struct {
  real_T offset;                       /* '<Root>/MATLAB Function' */
  int32_T sfEvent;                     /* '<Root>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/MATLAB Function' */
  boolean_T offset_not_empty;          /* '<Root>/MATLAB Function' */
  boolean_T init;                      /* '<Root>/MATLAB Function' */
  boolean_T init_not_empty;            /* '<Root>/MATLAB Function' */
} DW_MATLABFunction_Encoder_rea_T;

/* Block states (default storage) for system '<Root>/WrapAround' */
typedef struct {
  real_T old_count;                    /* '<Root>/WrapAround' */
  real_T total_count;                  /* '<Root>/WrapAround' */
  int32_T sfEvent;                     /* '<Root>/WrapAround' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/WrapAround' */
  boolean_T old_count_not_empty;       /* '<Root>/WrapAround' */
  boolean_T total_count_not_empty;     /* '<Root>/WrapAround' */
} DW_WrapAround_Encoder_reader__T;

/* Block signals (default storage) */
typedef struct {
  real_T Derivative;                   /* '<Root>/Derivative' */
  real_T Derivative1;                  /* '<Root>/Derivative1' */
  real_T Derivative2;                  /* '<Root>/Derivative2' */
  real_T Derivative3;                  /* '<Root>/Derivative3' */
  real_T Derivative4;                  /* '<Root>/Derivative4' */
  real_T Derivative5;                  /* '<Root>/Derivative5' */
  real_T Derivative6;                  /* '<Root>/Derivative6' */
  real_T Derivative7;                  /* '<Root>/Derivative7' */
  real_T Derivative10;                 /* '<Root>/Derivative10' */
  real_T Derivative11;                 /* '<Root>/Derivative11' */
  real_T Derivative8;                  /* '<Root>/Derivative8' */
  real_T Derivative9;                  /* '<Root>/Derivative9' */
  real_T pos_out;                      /* '<Root>/WrapAround2' */
  real_T pos_out_d;                    /* '<Root>/WrapAround1' */
  real_T pos_out_f;                    /* '<Root>/WrapAround' */
  uint32_T TIM3_Encoder2;              /* '<Root>/TIM3_Encoder2' */
  uint32_T TIM3_Encoder1;              /* '<Root>/TIM3_Encoder1' */
  uint32_T TIM3_Encoder;               /* '<Root>/TIM3_Encoder' */
  B_DigitalPortRead_Encoder_rea_T DigitalPortRead_n;/* '<S11>/Digital Port Read' */
  B_DigitalPortRead_Encoder_rea_T DigitalPortRead_m;/* '<S11>/Digital Port Read' */
  B_DigitalPortRead_Encoder_rea_T DigitalPortRead;/* '<S11>/Digital Port Read' */
} B_Encoder_reader_simulink_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_EncoderBlock_T obj; /* '<Root>/TIM3_Encoder2' */
  stm32cube_blocks_EncoderBlock_T obj_d;/* '<Root>/TIM3_Encoder1' */
  stm32cube_blocks_EncoderBlock_T obj_p;/* '<Root>/TIM3_Encoder' */
  real_T TimeStampA;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative' */
  real_T TimeStampB;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative' */
  real_T TimeStampA_p;                 /* '<Root>/Derivative1' */
  real_T LastUAtTimeA_g;               /* '<Root>/Derivative1' */
  real_T TimeStampB_n;                 /* '<Root>/Derivative1' */
  real_T LastUAtTimeB_c;               /* '<Root>/Derivative1' */
  real_T TimeStampA_h;                 /* '<Root>/Derivative2' */
  real_T LastUAtTimeA_b;               /* '<Root>/Derivative2' */
  real_T TimeStampB_b;                 /* '<Root>/Derivative2' */
  real_T LastUAtTimeB_d;               /* '<Root>/Derivative2' */
  real_T TimeStampA_b;                 /* '<Root>/Derivative3' */
  real_T LastUAtTimeA_d;               /* '<Root>/Derivative3' */
  real_T TimeStampB_bt;                /* '<Root>/Derivative3' */
  real_T LastUAtTimeB_l;               /* '<Root>/Derivative3' */
  real_T TimeStampA_i;                 /* '<Root>/Derivative4' */
  real_T LastUAtTimeA_o;               /* '<Root>/Derivative4' */
  real_T TimeStampB_j;                 /* '<Root>/Derivative4' */
  real_T LastUAtTimeB_a;               /* '<Root>/Derivative4' */
  real_T TimeStampA_d;                 /* '<Root>/Derivative5' */
  real_T LastUAtTimeA_i;               /* '<Root>/Derivative5' */
  real_T TimeStampB_g;                 /* '<Root>/Derivative5' */
  real_T LastUAtTimeB_j;               /* '<Root>/Derivative5' */
  real_T TimeStampA_m;                 /* '<Root>/Derivative6' */
  real_T LastUAtTimeA_d1;              /* '<Root>/Derivative6' */
  real_T TimeStampB_i;                 /* '<Root>/Derivative6' */
  real_T LastUAtTimeB_o;               /* '<Root>/Derivative6' */
  real_T TimeStampA_g;                 /* '<Root>/Derivative7' */
  real_T LastUAtTimeA_f;               /* '<Root>/Derivative7' */
  real_T TimeStampB_h;                 /* '<Root>/Derivative7' */
  real_T LastUAtTimeB_e;               /* '<Root>/Derivative7' */
  real_T TimeStampA_j;                 /* '<Root>/Derivative10' */
  real_T LastUAtTimeA_gt;              /* '<Root>/Derivative10' */
  real_T TimeStampB_d;                 /* '<Root>/Derivative10' */
  real_T LastUAtTimeB_m;               /* '<Root>/Derivative10' */
  real_T TimeStampA_iv;                /* '<Root>/Derivative11' */
  real_T LastUAtTimeA_e;               /* '<Root>/Derivative11' */
  real_T TimeStampB_a;                 /* '<Root>/Derivative11' */
  real_T LastUAtTimeB_cy;              /* '<Root>/Derivative11' */
  real_T TimeStampA_k;                 /* '<Root>/Derivative8' */
  real_T LastUAtTimeA_p;               /* '<Root>/Derivative8' */
  real_T TimeStampB_a4;                /* '<Root>/Derivative8' */
  real_T LastUAtTimeB_de;              /* '<Root>/Derivative8' */
  real_T TimeStampA_b2;                /* '<Root>/Derivative9' */
  real_T LastUAtTimeA_ek;              /* '<Root>/Derivative9' */
  real_T TimeStampB_jr;                /* '<Root>/Derivative9' */
  real_T LastUAtTimeB_g;               /* '<Root>/Derivative9' */
  DW_WrapAround_Encoder_reader__T sf_WrapAround2;/* '<Root>/WrapAround2' */
  DW_WrapAround_Encoder_reader__T sf_WrapAround1;/* '<Root>/WrapAround1' */
  DW_WrapAround_Encoder_reader__T sf_WrapAround;/* '<Root>/WrapAround' */
  DW_MATLABFunction_Encoder_rea_T sf_Reset2;/* '<Root>/Reset2' */
  DW_MATLABFunction_Encoder_rea_T sf_Reset1;/* '<Root>/Reset1' */
  DW_MATLABFunction_Encoder_rea_T sf_MATLABFunction;/* '<Root>/MATLAB Function' */
  DW_DigitalPortRead_Encoder_re_T DigitalPortRead_n;/* '<S11>/Digital Port Read' */
  DW_DigitalPortRead_Encoder_re_T DigitalPortRead_m;/* '<S11>/Digital Port Read' */
  DW_DigitalPortRead_Encoder_re_T DigitalPortRead;/* '<S11>/Digital Port Read' */
} DW_Encoder_reader_simulink_T;

/* Real-time Model Data Structure */
struct tag_RTM_Encoder_reader_simuli_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
extern B_Encoder_reader_simulink_T Encoder_reader_simulink_B;

/* Block states (default storage) */
extern DW_Encoder_reader_simulink_T Encoder_reader_simulink_DW;

/* Model entry point functions */
extern void Encoder_reader_simulink_initialize(void);
extern void Encoder_reader_simulink_step(void);
extern void Encoder_reader_simulink_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Encoder_reader_simul_T *const Encoder_reader_simulink_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Count2Deg' : Eliminated nontunable gain of 1
 * Block '<Root>/Count2Deg1' : Eliminated nontunable gain of 1
 * Block '<Root>/Count2Deg2' : Eliminated nontunable gain of 1
 * Block '<Root>/Count2Rad' : Eliminated nontunable gain of 1
 * Block '<Root>/Count2Rad1' : Eliminated nontunable gain of 1
 * Block '<Root>/Count2Rad2' : Eliminated nontunable gain of 1
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Encoder_reader_simulink'
 * '<S1>'   : 'Encoder_reader_simulink/Digital Port Read'
 * '<S2>'   : 'Encoder_reader_simulink/Digital Port Read1'
 * '<S3>'   : 'Encoder_reader_simulink/Digital Port Read2'
 * '<S4>'   : 'Encoder_reader_simulink/MATLAB Function'
 * '<S5>'   : 'Encoder_reader_simulink/Reset1'
 * '<S6>'   : 'Encoder_reader_simulink/Reset2'
 * '<S7>'   : 'Encoder_reader_simulink/WrapAround'
 * '<S8>'   : 'Encoder_reader_simulink/WrapAround1'
 * '<S9>'   : 'Encoder_reader_simulink/WrapAround2'
 * '<S10>'  : 'Encoder_reader_simulink/Digital Port Read/ECSoC'
 * '<S11>'  : 'Encoder_reader_simulink/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S12>'  : 'Encoder_reader_simulink/Digital Port Read1/ECSoC'
 * '<S13>'  : 'Encoder_reader_simulink/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S14>'  : 'Encoder_reader_simulink/Digital Port Read2/ECSoC'
 * '<S15>'  : 'Encoder_reader_simulink/Digital Port Read2/ECSoC/ECSimCodegen'
 */
#endif                                 /* Encoder_reader_simulink_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
