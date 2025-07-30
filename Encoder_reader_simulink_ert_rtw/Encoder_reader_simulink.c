/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Encoder_reader_simulink.c
 *
 * Code generated for Simulink model 'Encoder_reader_simulink'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Jul 30 14:35:15 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Encoder_reader_simulink.h"
#include "Encoder_reader_simulink_types.h"
#include "rtwtypes.h"
#include "stm_timer_ll.h"
#include "Encoder_reader_simulink_private.h"

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

/* Model step function */
void Encoder_reader_simulink_step(void)
{
  {
    real_T lastTime;
    real_T tmp;
    real_T *lastU;

    /* MATLABSystem: '<Root>/TIM3_Encoder' */
    Encoder_reader_simulink_B.TIM3_Encoder = getTimerCounterValueForG4
      (Encoder_reader_simulink_DW.obj.TimerHandle, false, NULL);

    /* MATLAB Function: '<Root>/warp_around' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion1'
     */
    Encoder_reader_simulink_B.y = Encoder_reader_simulink_B.TIM3_Encoder;

    /* Derivative: '<Root>/Derivative' incorporates:
     *  Derivative: '<Root>/Derivative1'
     *  Derivative: '<Root>/Derivative2'
     *  Derivative: '<Root>/Derivative3'
     */
    tmp = Encoder_reader_simulink_M->Timing.t[0];
    if ((Encoder_reader_simulink_DW.TimeStampA >= tmp) &&
        (Encoder_reader_simulink_DW.TimeStampB >= tmp)) {
      /* Derivative: '<Root>/Derivative' */
      Encoder_reader_simulink_B.Derivative = 0.0;
    } else {
      lastTime = Encoder_reader_simulink_DW.TimeStampA;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA;
      if (Encoder_reader_simulink_DW.TimeStampA <
          Encoder_reader_simulink_DW.TimeStampB) {
        if (Encoder_reader_simulink_DW.TimeStampB < tmp) {
          lastTime = Encoder_reader_simulink_DW.TimeStampB;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA >= tmp) {
        lastTime = Encoder_reader_simulink_DW.TimeStampB;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB;
      }

      /* Derivative: '<Root>/Derivative' */
      Encoder_reader_simulink_B.Derivative = (Encoder_reader_simulink_B.y -
        *lastU) / (tmp - lastTime);
    }

    /* End of Derivative: '<Root>/Derivative' */
    /* Derivative: '<Root>/Derivative1' */
    if ((Encoder_reader_simulink_DW.TimeStampA_p >= tmp) &&
        (Encoder_reader_simulink_DW.TimeStampB_n >= tmp)) {
      /* Derivative: '<Root>/Derivative1' */
      Encoder_reader_simulink_B.Derivative1 = 0.0;
    } else {
      lastTime = Encoder_reader_simulink_DW.TimeStampA_p;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_g;
      if (Encoder_reader_simulink_DW.TimeStampA_p <
          Encoder_reader_simulink_DW.TimeStampB_n) {
        if (Encoder_reader_simulink_DW.TimeStampB_n < tmp) {
          lastTime = Encoder_reader_simulink_DW.TimeStampB_n;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_c;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_p >= tmp) {
        lastTime = Encoder_reader_simulink_DW.TimeStampB_n;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_c;
      }

      /* Derivative: '<Root>/Derivative1' */
      Encoder_reader_simulink_B.Derivative1 =
        (Encoder_reader_simulink_B.Derivative - *lastU) / (tmp - lastTime);
    }

    /* Derivative: '<Root>/Derivative2' */
    if ((Encoder_reader_simulink_DW.TimeStampA_h >= tmp) &&
        (Encoder_reader_simulink_DW.TimeStampB_b >= tmp)) {
      /* Derivative: '<Root>/Derivative2' */
      Encoder_reader_simulink_B.Derivative2 = 0.0;
    } else {
      lastTime = Encoder_reader_simulink_DW.TimeStampA_h;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_b;
      if (Encoder_reader_simulink_DW.TimeStampA_h <
          Encoder_reader_simulink_DW.TimeStampB_b) {
        if (Encoder_reader_simulink_DW.TimeStampB_b < tmp) {
          lastTime = Encoder_reader_simulink_DW.TimeStampB_b;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_d;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_h >= tmp) {
        lastTime = Encoder_reader_simulink_DW.TimeStampB_b;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_d;
      }

      /* Derivative: '<Root>/Derivative2' */
      Encoder_reader_simulink_B.Derivative2 = (Encoder_reader_simulink_B.y -
        *lastU) / (tmp - lastTime);
    }

    /* Derivative: '<Root>/Derivative3' */
    if ((Encoder_reader_simulink_DW.TimeStampA_b >= tmp) &&
        (Encoder_reader_simulink_DW.TimeStampB_bt >= tmp)) {
      /* Derivative: '<Root>/Derivative3' */
      Encoder_reader_simulink_B.Derivative3 = 0.0;
    } else {
      lastTime = Encoder_reader_simulink_DW.TimeStampA_b;
      lastU = &Encoder_reader_simulink_DW.LastUAtTimeA_d;
      if (Encoder_reader_simulink_DW.TimeStampA_b <
          Encoder_reader_simulink_DW.TimeStampB_bt) {
        if (Encoder_reader_simulink_DW.TimeStampB_bt < tmp) {
          lastTime = Encoder_reader_simulink_DW.TimeStampB_bt;
          lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_l;
        }
      } else if (Encoder_reader_simulink_DW.TimeStampA_b >= tmp) {
        lastTime = Encoder_reader_simulink_DW.TimeStampB_bt;
        lastU = &Encoder_reader_simulink_DW.LastUAtTimeB_l;
      }

      /* Derivative: '<Root>/Derivative3' */
      Encoder_reader_simulink_B.Derivative3 =
        (Encoder_reader_simulink_B.Derivative2 - *lastU) / (tmp - lastTime);
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

    *lastU = Encoder_reader_simulink_B.y;

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

    *lastU = Encoder_reader_simulink_B.y;

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
  }

  {                                    /* Sample time: [0.001s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      ((Encoder_reader_simulink_M->Timing.clockTick1) * 0.001);

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
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
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
  Encoder_reader_simulink_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  Encoder_reader_simulink_M->Sizes.checksums[0] = (3183133163U);
  Encoder_reader_simulink_M->Sizes.checksums[1] = (2619317314U);
  Encoder_reader_simulink_M->Sizes.checksums[2] = (1558935090U);
  Encoder_reader_simulink_M->Sizes.checksums[3] = (3944278181U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    Encoder_reader_simulink_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
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

  /* Start for MATLABSystem: '<Root>/TIM3_Encoder' */
  Encoder_reader_simulink_DW.obj.isInitialized = 0;
  Encoder_reader_simulink_DW.obj.matlabCodegenIsDeleted = false;
  Encoder_reader_SystemCore_setup(&Encoder_reader_simulink_DW.obj);
}

/* Model terminate function */
void Encoder_reader_simulink_terminate(void)
{
  uint8_T ChannelInfo;

  /* Terminate for MATLABSystem: '<Root>/TIM3_Encoder' */
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

  /* End of Terminate for MATLABSystem: '<Root>/TIM3_Encoder' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
