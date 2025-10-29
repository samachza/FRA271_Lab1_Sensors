/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Encoder_reader_simulink_private.h
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

#ifndef Encoder_reader_simulink_private_h_
#define Encoder_reader_simulink_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Encoder_reader_simulink.h"
#include "Encoder_reader_simulink_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern void Encoder_re_DigitalPortRead_Init(DW_DigitalPortRead_Encoder_re_T
  *localDW);
extern void Encoder_reader__DigitalPortRead(B_DigitalPortRead_Encoder_rea_T
  *localB);
extern void Encoder_rea_MATLABFunction_Init(DW_MATLABFunction_Encoder_rea_T
  *localDW);
extern void Encoder_reader_s_MATLABFunction(real_T rtu_pos_in, boolean_T
  rtu_home, real_T *rty_pos_home, DW_MATLABFunction_Encoder_rea_T *localDW);
extern void Encoder_reader__WrapAround_Init(DW_WrapAround_Encoder_reader__T
  *localDW);
extern void Encoder_reader_simul_WrapAround(real_T rtu_count_in, real_T
  *rty_pos_out, DW_WrapAround_Encoder_reader__T *localDW);
extern void Encoder_re_DigitalPortRead_Term(DW_DigitalPortRead_Encoder_re_T
  *localDW);

#endif                                 /* Encoder_reader_simulink_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
