/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Encoder_reader_simulink.c
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

#include "Encoder_reader_simulink.h"
#include "rtwtypes.h"
#include "Encoder_reader_simulink_types.h"
#include "Encoder_reader_simulink_private.h"
#include "stm_timer_ll.h"

/* Named constants for MATLAB Function: '<Root>/MATLAB Function' */
#define Encoder_reader_simul_CALL_EVENT (-1)

/* Named constants for MATLAB Function: '<Root>/WrapAround' */
#define Encoder_reader_sim_CALL_EVENT_e (-1)

/* Block signals (default storage) */
B_Encoder_reader_simulink_T Encoder_reader_simulink_B;

/* Block states (default storage) */
DW_Encoder_reader_simulink_T Encoder_reader_simulink_DW;

/* Real-time model */
static RT_MODEL_Encoder_reader_simul_T Encoder_reader_simulink_M_;
RT_MODEL_Encoder_reader_simul_T *const Encoder_reader_simulink_M =
  &Encoder_reader_simulink_M_;

/* Forward declaration for local functions */
static void Encoder_reader_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj);
static void Encoder_read_SystemCore_setup_j(stm32cube_blocks_EncoderBlock_T *obj);
static void Encoder_rea_SystemCore_setup_j2(stm32cube_blocks_EncoderBlock_T *obj);

/* System initialize for atomic system: */
void Encoder_re_DigitalPortRead_Init(DW_DigitalPortRead_Encoder_re_T *localDW)
{
  /* Start for MATLABSystem: '<S11>/Digital Port Read' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void Encoder_reader__DigitalPortRead(B_DigitalPortRead_Encoder_rea_T *localB)
{
  uint32_T pinReadLoc;

  /* MATLABSystem: '<S11>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

  /* MATLABSystem: '<S11>/Digital Port Read' */
  localB->DigitalPortRead = ((pinReadLoc & 8192U) != 0U);
}

/* Termination for atomic system: */
void Encoder_re_DigitalPortRead_Term(DW_DigitalPortRead_Encoder_re_T *localDW)
{
  /* Terminate for MATLABSystem: '<S11>/Digital Port Read' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S11>/Digital Port Read' */
}

/*
 * System initialize for atomic system:
 *    '<Root>/MATLAB Function'
 *    '<Root>/Reset1'
 *    '<Root>/Reset2'
 */
void Encoder_rea_MATLABFunction_Init(DW_MATLABFunction_Encoder_rea_T *localDW)
{
  localDW->offset_not_empty = true;
  localDW->init = true;
  localDW->init_not_empty = true;
  localDW->sfEvent = Encoder_reader_simul_CALL_EVENT;
}

/*
 * Output and update for atomic system:
 *    '<Root>/MATLAB Function'
 *    '<Root>/Reset1'
 *    '<Root>/Reset2'
 */
void Encoder_reader_s_MATLABFunction(real_T rtu_pos_in, boolean_T rtu_home,
  real_T *rty_pos_home, DW_MATLABFunction_Encoder_rea_T *localDW)
{
  localDW->sfEvent = Encoder_reader_simul_CALL_EVENT;
  if (rtu_home) {
    localDW->offset = rtu_pos_in;
  }

  *rty_pos_home = rtu_pos_in - localDW->offset;
}

/*
 * System initialize for atomic system:
 *    '<Root>/WrapAround'
 *    '<Root>/WrapAround1'
 *    '<Root>/WrapAround2'
 */
void Encoder_reader__WrapAround_Init(DW_WrapAround_Encoder_reader__T *localDW)
{
  localDW->old_count_not_empty = true;
  localDW->total_count_not_empty = true;
  localDW->sfEvent = Encoder_reader_sim_CALL_EVENT_e;
}

/*
 * Output and update for atomic system:
 *    '<Root>/WrapAround'
 *    '<Root>/WrapAround1'
 *    '<Root>/WrapAround2'
 */
void Encoder_reader_simul_WrapAround(real_T rtu_count_in, real_T *rty_pos_out,
  DW_WrapAround_Encoder_reader__T *localDW)
{
  real_T diff;
  localDW->sfEvent = Encoder_reader_sim_CALL_EVENT_e;
  diff = rtu_count_in - localDW->old_count;
  if (diff > 30719.5) {
    diff -= 61440.0;
  } else if (diff < -30719.5) {
    diff += 61440.0;
  }

  localDW->total_count += diff;
  *rty_pos_out = localDW->total_count;
  localDW->old_count = rtu_count_in;
}

static void Encoder_reader_SystemCore_setup(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/TIM3_Encoder' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void Encoder_read_SystemCore_setup_j(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder1' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM4;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder1' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder1' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/TIM3_Encoder1' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void Encoder_rea_SystemCore_setup_j2(stm32cube_blocks_EncoderBlock_T *obj)
{
  uint8_T ChannelInfo;
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder2' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder2' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  ChannelInfo = ENABLE_CH;

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder2' */
  enableTimerChannel1(obj->TimerHandle, ChannelInfo);
  enableTimerChannel2(obj->TimerHandle, ChannelInfo);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/TIM3_Encoder2' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

/* Model step function */
void Encoder_reader_simulink_step(void)
{
  {
    real_T pos_home_k;
    real_T pos_home_l;
    real_T *lastU;

    /* MATLABSystem: '<Root>/TIM3_Encoder' */
    Encoder_reader_simulink_B.TIM3_Encoder = getTimerCounterValueForG4
      (Encoder_reader_simulink_DW.obj_p.TimerHandle, false, NULL);
    Encoder_reader__DigitalPortRead(&Encoder_reader_simulink_B.DigitalPortRead);

    /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion1'
     */
    Encoder_reader_s_MATLABFunction((real_T)
      Encoder_reader_simulink_B.TIM3_Encoder,
      Encoder_reader_simulink_B.DigitalPortRead.DigitalPortRead, &pos_home_l,
      &Encoder_reader_simulink_DW.sf_MATLABFunction);

    /* MATLAB Function: '<Root>/WrapAround' */
    Encoder_reader_simul_WrapAround(pos_home_l,
      &Encoder_reader_simulink_B.pos_out_f,
      &Encoder_reader_simulink_DW.sf_WrapAround);

    /* Derivative: '<Root>/Derivative' incorporates:
     *  Derivative: '<Root>/Derivative1'
     *  Derivative: '<Root>/Derivative10'
     *  Derivative: '<Root>/Derivative11'
     *  Derivative: '<Root>/Derivative2'
     *  Derivative: '<Root>/Derivative3'
     *  Derivative: '<Root>/Derivative4'
     *  Derivative: '<Root>/Derivative5'
     *  Derivative: '<Root>/Derivative6'
     *  Derivative: '<Root>/Derivative7'
     *  Derivative: '<Root>/Derivative8'
     *  Derivative: '<Root>/Derivative9'
     */
    pos_home_l = Encoder_reader_simulink_M->Timing.t[0];
    if ((Encoder_reader_simulink_DW.TimeStampA >= pos_home_l) &&
        (Encoder_reader_simulink_DW.TimeStampB >= pos_home_l)) {
      /* Derivative: '<Root>/Derivative' */
      Encoder_reader_simulink_B.Derivative = 0.0;
    } else {
      pos_home_k = Encoder_reader_simulink_DW.TimeStampA;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA;
      if (Encoder_reader_simulink_DW.TimeStampA <
          Encoder_reader_simulink_DW.TimeStampB) {
        if (Encoder_reader_simulink_DW.TimeStampB < pos_home_l) {
          pos_home_k = Encoder_reader_simulink_DW.TimeStampB;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA >= pos_home_l) {
        pos_home_k = Encoder_reader_simulink_DW.TimeStampB;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB;
      }

      /* Derivative: '<Root>/Derivative' */
      Encoder_reader_simulink_B.Derivative =
        (Encoder_reader_simulink_B.pos_out_f - *lastU) / (pos_home_l -
        pos_home_k);
    }

    /* End of Derivative: '<Root>/Derivative' */
    /* Derivative: '<Root>/Derivative1' */
    if ((Encoder_reader_simulink_DW.TimeStampA_p >= pos_home_l) &&
        (Encoder_reader_simulink_DW.TimeStampB_n >= pos_home_l)) {
      /* Derivative: '<Root>/Derivative1' */
      Encoder_reader_simulink_B.Derivative1 = 0.0;
    } else {
      pos_home_k = Encoder_reader_simulink_DW.TimeStampA_p;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_g;
      if (Encoder_reader_simulink_DW.TimeStampA_p <
          Encoder_reader_simulink_DW.TimeStampB_n) {
        if (Encoder_reader_simulink_DW.TimeStampB_n < pos_home_l) {
          pos_home_k = Encoder_reader_simulink_DW.TimeStampB_n;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_c;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_p >= pos_home_l) {
        pos_home_k = Encoder_reader_simulink_DW.TimeStampB_n;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_c;
      }

      /* Derivative: '<Root>/Derivative1' */
      Encoder_reader_simulink_B.Derivative1 =
        (Encoder_reader_simulink_B.Derivative - *lastU) / (pos_home_l -
        pos_home_k);
    }

    /* Derivative: '<Root>/Derivative2' */
    if ((Encoder_reader_simulink_DW.TimeStampA_h >= pos_home_l) &&
        (Encoder_reader_simulink_DW.TimeStampB_b >= pos_home_l)) {
      /* Derivative: '<Root>/Derivative2' */
      Encoder_reader_simulink_B.Derivative2 = 0.0;
    } else {
      pos_home_k = Encoder_reader_simulink_DW.TimeStampA_h;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_b;
      if (Encoder_reader_simulink_DW.TimeStampA_h <
          Encoder_reader_simulink_DW.TimeStampB_b) {
        if (Encoder_reader_simulink_DW.TimeStampB_b < pos_home_l) {
          pos_home_k = Encoder_reader_simulink_DW.TimeStampB_b;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_d;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_h >= pos_home_l) {
        pos_home_k = Encoder_reader_simulink_DW.TimeStampB_b;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_d;
      }

      /* Derivative: '<Root>/Derivative2' */
      Encoder_reader_simulink_B.Derivative2 =
        (Encoder_reader_simulink_B.pos_out_f - *lastU) / (pos_home_l -
        pos_home_k);
    }

    /* Derivative: '<Root>/Derivative3' */
    if ((Encoder_reader_simulink_DW.TimeStampA_b >= pos_home_l) &&
        (Encoder_reader_simulink_DW.TimeStampB_bt >= pos_home_l)) {
      /* Derivative: '<Root>/Derivative3' */
      Encoder_reader_simulink_B.Derivative3 = 0.0;
    } else {
      pos_home_k = Encoder_reader_simulink_DW.TimeStampA_b;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_d;
      if (Encoder_reader_simulink_DW.TimeStampA_b <
          Encoder_reader_simulink_DW.TimeStampB_bt) {
        if (Encoder_reader_simulink_DW.TimeStampB_bt < pos_home_l) {
          pos_home_k = Encoder_reader_simulink_DW.TimeStampB_bt;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_l;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_b >= pos_home_l) {
        pos_home_k = Encoder_reader_simulink_DW.TimeStampB_bt;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_l;
      }

      /* Derivative: '<Root>/Derivative3' */
      Encoder_reader_simulink_B.Derivative3 =
        (Encoder_reader_simulink_B.Derivative2 - *lastU) / (pos_home_l -
        pos_home_k);
    }

    /* MATLABSystem: '<Root>/TIM3_Encoder1' */
    Encoder_reader_simulink_B.TIM3_Encoder1 = getTimerCounterValueForG4
      (Encoder_reader_simulink_DW.obj_d.TimerHandle, false, NULL);
    Encoder_reader__DigitalPortRead(&Encoder_reader_simulink_B.DigitalPortRead_m);

    /* MATLAB Function: '<Root>/Reset1' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion2'
     */
    Encoder_reader_s_MATLABFunction((real_T)
      Encoder_reader_simulink_B.TIM3_Encoder1,
      Encoder_reader_simulink_B.DigitalPortRead_m.DigitalPortRead, &pos_home_k,
      &Encoder_reader_simulink_DW.sf_Reset1);

    /* MATLAB Function: '<Root>/WrapAround1' */
    Encoder_reader_simul_WrapAround(pos_home_k,
      &Encoder_reader_simulink_B.pos_out_d,
      &Encoder_reader_simulink_DW.sf_WrapAround1);

    /* Derivative: '<Root>/Derivative4' */
    if ((Encoder_reader_simulink_DW.TimeStampA_i >= pos_home_l) &&
        (Encoder_reader_simulink_DW.TimeStampB_j >= pos_home_l)) {
      /* Derivative: '<Root>/Derivative4' */
      Encoder_reader_simulink_B.Derivative4 = 0.0;
    } else {
      pos_home_k = Encoder_reader_simulink_DW.TimeStampA_i;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_o;
      if (Encoder_reader_simulink_DW.TimeStampA_i <
          Encoder_reader_simulink_DW.TimeStampB_j) {
        if (Encoder_reader_simulink_DW.TimeStampB_j < pos_home_l) {
          pos_home_k = Encoder_reader_simulink_DW.TimeStampB_j;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_a;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_i >= pos_home_l) {
        pos_home_k = Encoder_reader_simulink_DW.TimeStampB_j;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_a;
      }

      /* Derivative: '<Root>/Derivative4' */
      Encoder_reader_simulink_B.Derivative4 =
        (Encoder_reader_simulink_B.pos_out_d - *lastU) / (pos_home_l -
        pos_home_k);
    }

    /* Derivative: '<Root>/Derivative5' */
    if ((Encoder_reader_simulink_DW.TimeStampA_d >= pos_home_l) &&
        (Encoder_reader_simulink_DW.TimeStampB_g >= pos_home_l)) {
      /* Derivative: '<Root>/Derivative5' */
      Encoder_reader_simulink_B.Derivative5 = 0.0;
    } else {
      pos_home_k = Encoder_reader_simulink_DW.TimeStampA_d;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_i;
      if (Encoder_reader_simulink_DW.TimeStampA_d <
          Encoder_reader_simulink_DW.TimeStampB_g) {
        if (Encoder_reader_simulink_DW.TimeStampB_g < pos_home_l) {
          pos_home_k = Encoder_reader_simulink_DW.TimeStampB_g;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_j;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_d >= pos_home_l) {
        pos_home_k = Encoder_reader_simulink_DW.TimeStampB_g;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_j;
      }

      /* Derivative: '<Root>/Derivative5' */
      Encoder_reader_simulink_B.Derivative5 =
        (Encoder_reader_simulink_B.Derivative4 - *lastU) / (pos_home_l -
        pos_home_k);
    }

    /* Derivative: '<Root>/Derivative6' */
    if ((Encoder_reader_simulink_DW.TimeStampA_m >= pos_home_l) &&
        (Encoder_reader_simulink_DW.TimeStampB_i >= pos_home_l)) {
      /* Derivative: '<Root>/Derivative6' */
      Encoder_reader_simulink_B.Derivative6 = 0.0;
    } else {
      pos_home_k = Encoder_reader_simulink_DW.TimeStampA_m;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_d1;
      if (Encoder_reader_simulink_DW.TimeStampA_m <
          Encoder_reader_simulink_DW.TimeStampB_i) {
        if (Encoder_reader_simulink_DW.TimeStampB_i < pos_home_l) {
          pos_home_k = Encoder_reader_simulink_DW.TimeStampB_i;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_o;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_m >= pos_home_l) {
        pos_home_k = Encoder_reader_simulink_DW.TimeStampB_i;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_o;
      }

      /* Derivative: '<Root>/Derivative6' */
      Encoder_reader_simulink_B.Derivative6 =
        (Encoder_reader_simulink_B.pos_out_d - *lastU) / (pos_home_l -
        pos_home_k);
    }

    /* Derivative: '<Root>/Derivative7' */
    if ((Encoder_reader_simulink_DW.TimeStampA_g >= pos_home_l) &&
        (Encoder_reader_simulink_DW.TimeStampB_h >= pos_home_l)) {
      /* Derivative: '<Root>/Derivative7' */
      Encoder_reader_simulink_B.Derivative7 = 0.0;
    } else {
      pos_home_k = Encoder_reader_simulink_DW.TimeStampA_g;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_f;
      if (Encoder_reader_simulink_DW.TimeStampA_g <
          Encoder_reader_simulink_DW.TimeStampB_h) {
        if (Encoder_reader_simulink_DW.TimeStampB_h < pos_home_l) {
          pos_home_k = Encoder_reader_simulink_DW.TimeStampB_h;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_e;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_g >= pos_home_l) {
        pos_home_k = Encoder_reader_simulink_DW.TimeStampB_h;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_e;
      }

      /* Derivative: '<Root>/Derivative7' */
      Encoder_reader_simulink_B.Derivative7 =
        (Encoder_reader_simulink_B.Derivative6 - *lastU) / (pos_home_l -
        pos_home_k);
    }

    /* MATLABSystem: '<Root>/TIM3_Encoder2' */
    Encoder_reader_simulink_B.TIM3_Encoder2 = getTimerCounterValueForG4
      (Encoder_reader_simulink_DW.obj.TimerHandle, false, NULL);
    Encoder_reader__DigitalPortRead(&Encoder_reader_simulink_B.DigitalPortRead_n);

    /* MATLAB Function: '<Root>/Reset2' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion3'
     */
    Encoder_reader_s_MATLABFunction((real_T)
      Encoder_reader_simulink_B.TIM3_Encoder2,
      Encoder_reader_simulink_B.DigitalPortRead_n.DigitalPortRead, &pos_home_k,
      &Encoder_reader_simulink_DW.sf_Reset2);

    /* MATLAB Function: '<Root>/WrapAround2' */
    Encoder_reader_simul_WrapAround(pos_home_k,
      &Encoder_reader_simulink_B.pos_out,
      &Encoder_reader_simulink_DW.sf_WrapAround2);

    /* Derivative: '<Root>/Derivative10' */
    if ((Encoder_reader_simulink_DW.TimeStampA_j >= pos_home_l) &&
        (Encoder_reader_simulink_DW.TimeStampB_d >= pos_home_l)) {
      /* Derivative: '<Root>/Derivative10' */
      Encoder_reader_simulink_B.Derivative10 = 0.0;
    } else {
      pos_home_k = Encoder_reader_simulink_DW.TimeStampA_j;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_gt;
      if (Encoder_reader_simulink_DW.TimeStampA_j <
          Encoder_reader_simulink_DW.TimeStampB_d) {
        if (Encoder_reader_simulink_DW.TimeStampB_d < pos_home_l) {
          pos_home_k = Encoder_reader_simulink_DW.TimeStampB_d;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_m;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_j >= pos_home_l) {
        pos_home_k = Encoder_reader_simulink_DW.TimeStampB_d;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_m;
      }

      /* Derivative: '<Root>/Derivative10' */
      Encoder_reader_simulink_B.Derivative10 =
        (Encoder_reader_simulink_B.pos_out - *lastU) / (pos_home_l - pos_home_k);
    }

    /* Derivative: '<Root>/Derivative11' */
    if ((Encoder_reader_simulink_DW.TimeStampA_iv >= pos_home_l) &&
        (Encoder_reader_simulink_DW.TimeStampB_a >= pos_home_l)) {
      /* Derivative: '<Root>/Derivative11' */
      Encoder_reader_simulink_B.Derivative11 = 0.0;
    } else {
      pos_home_k = Encoder_reader_simulink_DW.TimeStampA_iv;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_e;
      if (Encoder_reader_simulink_DW.TimeStampA_iv <
          Encoder_reader_simulink_DW.TimeStampB_a) {
        if (Encoder_reader_simulink_DW.TimeStampB_a < pos_home_l) {
          pos_home_k = Encoder_reader_simulink_DW.TimeStampB_a;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_cy;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_iv >= pos_home_l) {
        pos_home_k = Encoder_reader_simulink_DW.TimeStampB_a;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_cy;
      }

      /* Derivative: '<Root>/Derivative11' */
      Encoder_reader_simulink_B.Derivative11 =
        (Encoder_reader_simulink_B.Derivative10 - *lastU) / (pos_home_l -
        pos_home_k);
    }

    /* Derivative: '<Root>/Derivative8' */
    if ((Encoder_reader_simulink_DW.TimeStampA_k >= pos_home_l) &&
        (Encoder_reader_simulink_DW.TimeStampB_a4 >= pos_home_l)) {
      /* Derivative: '<Root>/Derivative8' */
      Encoder_reader_simulink_B.Derivative8 = 0.0;
    } else {
      pos_home_k = Encoder_reader_simulink_DW.TimeStampA_k;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_p;
      if (Encoder_reader_simulink_DW.TimeStampA_k <
          Encoder_reader_simulink_DW.TimeStampB_a4) {
        if (Encoder_reader_simulink_DW.TimeStampB_a4 < pos_home_l) {
          pos_home_k = Encoder_reader_simulink_DW.TimeStampB_a4;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_de;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_k >= pos_home_l) {
        pos_home_k = Encoder_reader_simulink_DW.TimeStampB_a4;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_de;
      }

      /* Derivative: '<Root>/Derivative8' */
      Encoder_reader_simulink_B.Derivative8 = (Encoder_reader_simulink_B.pos_out
        - *lastU) / (pos_home_l - pos_home_k);
    }

    /* Derivative: '<Root>/Derivative9' */
    if ((Encoder_reader_simulink_DW.TimeStampA_b2 >= pos_home_l) &&
        (Encoder_reader_simulink_DW.TimeStampB_jr >= pos_home_l)) {
      /* Derivative: '<Root>/Derivative9' */
      Encoder_reader_simulink_B.Derivative9 = 0.0;
    } else {
      pos_home_k = Encoder_reader_simulink_DW.TimeStampA_b2;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_ek;
      if (Encoder_reader_simulink_DW.TimeStampA_b2 <
          Encoder_reader_simulink_DW.TimeStampB_jr) {
        if (Encoder_reader_simulink_DW.TimeStampB_jr < pos_home_l) {
          pos_home_k = Encoder_reader_simulink_DW.TimeStampB_jr;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_g;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_b2 >= pos_home_l) {
        pos_home_k = Encoder_reader_simulink_DW.TimeStampB_jr;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_g;
      }

      /* Derivative: '<Root>/Derivative9' */
      Encoder_reader_simulink_B.Derivative9 =
        (Encoder_reader_simulink_B.Derivative8 - *lastU) / (pos_home_l -
        pos_home_k);
    }
  }

  {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative' */
    if (Encoder_reader_simulink_DW.TimeStampA == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA;
    } else if (Encoder_reader_simulink_DW.TimeStampB == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB;
    } else if (Encoder_reader_simulink_DW.TimeStampA <
               Encoder_reader_simulink_DW.TimeStampB) {
      Encoder_reader_simulink_DW.TimeStampA =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA;
    } else {
      Encoder_reader_simulink_DW.TimeStampB =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB;
    }

    *lastU = Encoder_reader_simulink_B.pos_out_f;

    /* End of Update for Derivative: '<Root>/Derivative' */

    /* Update for Derivative: '<Root>/Derivative1' */
    if (Encoder_reader_simulink_DW.TimeStampA_p == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_p =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_g;
    } else if (Encoder_reader_simulink_DW.TimeStampB_n == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_n =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_c;
    } else if (Encoder_reader_simulink_DW.TimeStampA_p <
               Encoder_reader_simulink_DW.TimeStampB_n) {
      Encoder_reader_simulink_DW.TimeStampA_p =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_g;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_n =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_c;
    }

    *lastU = Encoder_reader_simulink_B.Derivative;

    /* End of Update for Derivative: '<Root>/Derivative1' */

    /* Update for Derivative: '<Root>/Derivative2' */
    if (Encoder_reader_simulink_DW.TimeStampA_h == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_h =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_b;
    } else if (Encoder_reader_simulink_DW.TimeStampB_b == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_b =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_d;
    } else if (Encoder_reader_simulink_DW.TimeStampA_h <
               Encoder_reader_simulink_DW.TimeStampB_b) {
      Encoder_reader_simulink_DW.TimeStampA_h =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_b;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_b =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_d;
    }

    *lastU = Encoder_reader_simulink_B.pos_out_f;

    /* End of Update for Derivative: '<Root>/Derivative2' */

    /* Update for Derivative: '<Root>/Derivative3' */
    if (Encoder_reader_simulink_DW.TimeStampA_b == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_b =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_d;
    } else if (Encoder_reader_simulink_DW.TimeStampB_bt == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_bt =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_l;
    } else if (Encoder_reader_simulink_DW.TimeStampA_b <
               Encoder_reader_simulink_DW.TimeStampB_bt) {
      Encoder_reader_simulink_DW.TimeStampA_b =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_d;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_bt =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_l;
    }

    *lastU = Encoder_reader_simulink_B.Derivative2;

    /* End of Update for Derivative: '<Root>/Derivative3' */

    /* Update for Derivative: '<Root>/Derivative4' */
    if (Encoder_reader_simulink_DW.TimeStampA_i == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_i =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_o;
    } else if (Encoder_reader_simulink_DW.TimeStampB_j == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_j =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_a;
    } else if (Encoder_reader_simulink_DW.TimeStampA_i <
               Encoder_reader_simulink_DW.TimeStampB_j) {
      Encoder_reader_simulink_DW.TimeStampA_i =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_o;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_j =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_a;
    }

    *lastU = Encoder_reader_simulink_B.pos_out_d;

    /* End of Update for Derivative: '<Root>/Derivative4' */

    /* Update for Derivative: '<Root>/Derivative5' */
    if (Encoder_reader_simulink_DW.TimeStampA_d == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_d =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_i;
    } else if (Encoder_reader_simulink_DW.TimeStampB_g == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_g =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_j;
    } else if (Encoder_reader_simulink_DW.TimeStampA_d <
               Encoder_reader_simulink_DW.TimeStampB_g) {
      Encoder_reader_simulink_DW.TimeStampA_d =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_i;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_g =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_j;
    }

    *lastU = Encoder_reader_simulink_B.Derivative4;

    /* End of Update for Derivative: '<Root>/Derivative5' */

    /* Update for Derivative: '<Root>/Derivative6' */
    if (Encoder_reader_simulink_DW.TimeStampA_m == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_m =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_d1;
    } else if (Encoder_reader_simulink_DW.TimeStampB_i == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_i =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_o;
    } else if (Encoder_reader_simulink_DW.TimeStampA_m <
               Encoder_reader_simulink_DW.TimeStampB_i) {
      Encoder_reader_simulink_DW.TimeStampA_m =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_d1;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_i =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_o;
    }

    *lastU = Encoder_reader_simulink_B.pos_out_d;

    /* End of Update for Derivative: '<Root>/Derivative6' */

    /* Update for Derivative: '<Root>/Derivative7' */
    if (Encoder_reader_simulink_DW.TimeStampA_g == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_g =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_f;
    } else if (Encoder_reader_simulink_DW.TimeStampB_h == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_h =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_e;
    } else if (Encoder_reader_simulink_DW.TimeStampA_g <
               Encoder_reader_simulink_DW.TimeStampB_h) {
      Encoder_reader_simulink_DW.TimeStampA_g =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_f;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_h =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_e;
    }

    *lastU = Encoder_reader_simulink_B.Derivative6;

    /* End of Update for Derivative: '<Root>/Derivative7' */

    /* Update for Derivative: '<Root>/Derivative10' */
    if (Encoder_reader_simulink_DW.TimeStampA_j == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_j =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_gt;
    } else if (Encoder_reader_simulink_DW.TimeStampB_d == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_d =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_m;
    } else if (Encoder_reader_simulink_DW.TimeStampA_j <
               Encoder_reader_simulink_DW.TimeStampB_d) {
      Encoder_reader_simulink_DW.TimeStampA_j =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_gt;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_d =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_m;
    }

    *lastU = Encoder_reader_simulink_B.pos_out;

    /* End of Update for Derivative: '<Root>/Derivative10' */

    /* Update for Derivative: '<Root>/Derivative11' */
    if (Encoder_reader_simulink_DW.TimeStampA_iv == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_iv =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_e;
    } else if (Encoder_reader_simulink_DW.TimeStampB_a == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_a =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_cy;
    } else if (Encoder_reader_simulink_DW.TimeStampA_iv <
               Encoder_reader_simulink_DW.TimeStampB_a) {
      Encoder_reader_simulink_DW.TimeStampA_iv =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_e;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_a =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_cy;
    }

    *lastU = Encoder_reader_simulink_B.Derivative10;

    /* End of Update for Derivative: '<Root>/Derivative11' */

    /* Update for Derivative: '<Root>/Derivative8' */
    if (Encoder_reader_simulink_DW.TimeStampA_k == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_k =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_p;
    } else if (Encoder_reader_simulink_DW.TimeStampB_a4 == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_a4 =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_de;
    } else if (Encoder_reader_simulink_DW.TimeStampA_k <
               Encoder_reader_simulink_DW.TimeStampB_a4) {
      Encoder_reader_simulink_DW.TimeStampA_k =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_p;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_a4 =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_de;
    }

    *lastU = Encoder_reader_simulink_B.pos_out;

    /* End of Update for Derivative: '<Root>/Derivative8' */

    /* Update for Derivative: '<Root>/Derivative9' */
    if (Encoder_reader_simulink_DW.TimeStampA_b2 == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampA_b2 =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_ek;
    } else if (Encoder_reader_simulink_DW.TimeStampB_jr == (rtInf)) {
      Encoder_reader_simulink_DW.TimeStampB_jr =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_g;
    } else if (Encoder_reader_simulink_DW.TimeStampA_b2 <
               Encoder_reader_simulink_DW.TimeStampB_jr) {
      Encoder_reader_simulink_DW.TimeStampA_b2 =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_ek;
    } else {
      Encoder_reader_simulink_DW.TimeStampB_jr =
        Encoder_reader_simulink_M->Timing.t[0];
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_g;
    }

    *lastU = Encoder_reader_simulink_B.Derivative8;

    /* End of Update for Derivative: '<Root>/Derivative9' */
  }

  {                                    /* Sample time: [0.01s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      ((Encoder_reader_simulink_M->Timing.clockTick1) * 0.01);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1, extmodeTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Encoder_reader_simulink_M->Timing.t[0] =
    ((time_T)(++Encoder_reader_simulink_M->Timing.clockTick0)) *
    Encoder_reader_simulink_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Encoder_reader_simulink_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Encoder_reader_simulink_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Encoder_reader_simulink_M->solverInfo,
                          &Encoder_reader_simulink_M->Timing.simTimeStep);
    rtsiSetTPtr(&Encoder_reader_simulink_M->solverInfo, &rtmGetTPtr
                (Encoder_reader_simulink_M));
    rtsiSetStepSizePtr(&Encoder_reader_simulink_M->solverInfo,
                       &Encoder_reader_simulink_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Encoder_reader_simulink_M->solverInfo,
                          (&rtmGetErrorStatus(Encoder_reader_simulink_M)));
    rtsiSetRTModelPtr(&Encoder_reader_simulink_M->solverInfo,
                      Encoder_reader_simulink_M);
  }

  rtsiSetSimTimeStep(&Encoder_reader_simulink_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&Encoder_reader_simulink_M->solverInfo,
    false);
  rtsiSetIsContModeFrozen(&Encoder_reader_simulink_M->solverInfo, false);
  rtsiSetSolverName(&Encoder_reader_simulink_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Encoder_reader_simulink_M,
             &Encoder_reader_simulink_M->Timing.tArray[0]);
  rtmSetTFinal(Encoder_reader_simulink_M, -1);
  Encoder_reader_simulink_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Encoder_reader_simulink_M->Sizes.checksums[0] = (3042737896U);
  Encoder_reader_simulink_M->Sizes.checksums[1] = (635574717U);
  Encoder_reader_simulink_M->Sizes.checksums[2] = (3061995041U);
  Encoder_reader_simulink_M->Sizes.checksums[3] = (3353944923U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[13];
    Encoder_reader_simulink_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Encoder_reader_simulink_M->extModeInfo,
      &Encoder_reader_simulink_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Encoder_reader_simulink_M->extModeInfo,
                        Encoder_reader_simulink_M->Sizes.checksums);
    rteiSetTPtr(Encoder_reader_simulink_M->extModeInfo, rtmGetTPtr
                (Encoder_reader_simulink_M));
  }

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  Encoder_reader_simulink_DW.TimeStampA = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative1' */
  Encoder_reader_simulink_DW.TimeStampA_p = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_n = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative2' */
  Encoder_reader_simulink_DW.TimeStampA_h = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_b = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative3' */
  Encoder_reader_simulink_DW.TimeStampA_b = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_bt = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative4' */
  Encoder_reader_simulink_DW.TimeStampA_i = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_j = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative5' */
  Encoder_reader_simulink_DW.TimeStampA_d = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_g = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative6' */
  Encoder_reader_simulink_DW.TimeStampA_m = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_i = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative7' */
  Encoder_reader_simulink_DW.TimeStampA_g = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_h = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative10' */
  Encoder_reader_simulink_DW.TimeStampA_j = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_d = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative11' */
  Encoder_reader_simulink_DW.TimeStampA_iv = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_a = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative8' */
  Encoder_reader_simulink_DW.TimeStampA_k = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_a4 = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative9' */
  Encoder_reader_simulink_DW.TimeStampA_b2 = (rtInf);
  Encoder_reader_simulink_DW.TimeStampB_jr = (rtInf);

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function' */
  Encoder_rea_MATLABFunction_Init(&Encoder_reader_simulink_DW.sf_MATLABFunction);

  /* SystemInitialize for MATLAB Function: '<Root>/WrapAround' */
  Encoder_reader__WrapAround_Init(&Encoder_reader_simulink_DW.sf_WrapAround);

  /* SystemInitialize for MATLAB Function: '<Root>/Reset1' */
  Encoder_rea_MATLABFunction_Init(&Encoder_reader_simulink_DW.sf_Reset1);

  /* SystemInitialize for MATLAB Function: '<Root>/WrapAround1' */
  Encoder_reader__WrapAround_Init(&Encoder_reader_simulink_DW.sf_WrapAround1);

  /* SystemInitialize for MATLAB Function: '<Root>/Reset2' */
  Encoder_rea_MATLABFunction_Init(&Encoder_reader_simulink_DW.sf_Reset2);

  /* SystemInitialize for MATLAB Function: '<Root>/WrapAround2' */
  Encoder_reader__WrapAround_Init(&Encoder_reader_simulink_DW.sf_WrapAround2);

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder' */
  Encoder_reader_simulink_DW.obj_p.isInitialized = 0;
  Encoder_reader_simulink_DW.obj_p.matlabCodegenIsDeleted = false;
  Encoder_reader_SystemCore_setup(&Encoder_reader_simulink_DW.obj_p);
  Encoder_re_DigitalPortRead_Init(&Encoder_reader_simulink_DW.DigitalPortRead);

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder1' */
  Encoder_reader_simulink_DW.obj_d.isInitialized = 0;
  Encoder_reader_simulink_DW.obj_d.matlabCodegenIsDeleted = false;
  Encoder_read_SystemCore_setup_j(&Encoder_reader_simulink_DW.obj_d);
  Encoder_re_DigitalPortRead_Init(&Encoder_reader_simulink_DW.DigitalPortRead_m);

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder2' */
  Encoder_reader_simulink_DW.obj.isInitialized = 0;
  Encoder_reader_simulink_DW.obj.matlabCodegenIsDeleted = false;
  Encoder_rea_SystemCore_setup_j2(&Encoder_reader_simulink_DW.obj);
  Encoder_re_DigitalPortRead_Init(&Encoder_reader_simulink_DW.DigitalPortRead_n);
}

/* Model terminate function */
void Encoder_reader_simulink_terminate(void)
{
  uint8_T ChannelInfo;

  /* Terminate for MATLABSystem: '<Root>/TIM3_Encoder' */
  if (!Encoder_reader_simulink_DW.obj_p.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Encoder_reader_simulink_DW.obj_p.isInitialized == 1) &&
        Encoder_reader_simulink_DW.obj_p.isSetupComplete) {
      disableCounter(Encoder_reader_simulink_DW.obj_p.TimerHandle);
      disableTimerInterrupts(Encoder_reader_simulink_DW.obj_p.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(Encoder_reader_simulink_DW.obj_p.TimerHandle,
                           ChannelInfo);
      disableTimerChannel2(Encoder_reader_simulink_DW.obj_p.TimerHandle,
                           ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/TIM3_Encoder' */
  Encoder_re_DigitalPortRead_Term(&Encoder_reader_simulink_DW.DigitalPortRead);

  /* Terminate for MATLABSystem: '<Root>/TIM3_Encoder1' */
  if (!Encoder_reader_simulink_DW.obj_d.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Encoder_reader_simulink_DW.obj_d.isInitialized == 1) &&
        Encoder_reader_simulink_DW.obj_d.isSetupComplete) {
      disableCounter(Encoder_reader_simulink_DW.obj_d.TimerHandle);
      disableTimerInterrupts(Encoder_reader_simulink_DW.obj_d.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(Encoder_reader_simulink_DW.obj_d.TimerHandle,
                           ChannelInfo);
      disableTimerChannel2(Encoder_reader_simulink_DW.obj_d.TimerHandle,
                           ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/TIM3_Encoder1' */
  Encoder_re_DigitalPortRead_Term(&Encoder_reader_simulink_DW.DigitalPortRead_m);

  /* Terminate for MATLABSystem: '<Root>/TIM3_Encoder2' */
  if (!Encoder_reader_simulink_DW.obj.matlabCodegenIsDeleted) {
    Encoder_reader_simulink_DW.obj.matlabCodegenIsDeleted = true;
    if ((Encoder_reader_simulink_DW.obj.isInitialized == 1) &&
        Encoder_reader_simulink_DW.obj.isSetupComplete) {
      disableCounter(Encoder_reader_simulink_DW.obj.TimerHandle);
      disableTimerInterrupts(Encoder_reader_simulink_DW.obj.TimerHandle, 0);
      ChannelInfo = ENABLE_CH;
      disableTimerChannel1(Encoder_reader_simulink_DW.obj.TimerHandle,
                           ChannelInfo);
      disableTimerChannel2(Encoder_reader_simulink_DW.obj.TimerHandle,
                           ChannelInfo);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/TIM3_Encoder2' */
  Encoder_re_DigitalPortRead_Term(&Encoder_reader_simulink_DW.DigitalPortRead_n);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
