/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Chart.h
 *
 * Code generated for Simulink model 'Chart'.
 *
 * Model version                  : 1.94
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Jun  3 18:06:16 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Chart_h_
#define RTW_HEADER_Chart_h_
#ifndef Chart_COMMON_INCLUDES_
#define Chart_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Chart_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T TC;                           /* '<Root>/Chart' */
  real_T TL;                           /* '<Root>/Chart' */
  real_T Var_Inattivo;                 /* '<Root>/Chart' */
  real_T Var_Chiuso;                   /* '<Root>/Chart' */
  real_T Var_Aperto;                   /* '<Root>/Chart' */
  uint32_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint16_T temporalCounter_i3;         /* '<Root>/Chart' */
  uint8_T is_active_c1_Chart;          /* '<Root>/Chart' */
  uint8_T is_c1_Chart;                 /* '<Root>/Chart' */
  uint8_T is_active_Cancello;          /* '<Root>/Chart' */
  uint8_T is_Cancello;                 /* '<Root>/Chart' */
  uint8_T is_Apertura;                 /* '<Root>/Chart' */
  uint8_T is_In_Apertura;              /* '<Root>/Chart' */
  uint8_T is_Chiusura;                 /* '<Root>/Chart' */
  uint8_T is_Errore;                   /* '<Root>/Chart' */
  uint8_T is_In_Errore;                /* '<Root>/Chart' */
  uint8_T is_In_Chiusura;              /* '<Root>/Chart' */
  uint8_T is_active_Regolazione_Tempo_Lav;/* '<Root>/Chart' */
  uint8_T is_Regolazione_Tempo_Lavoro; /* '<Root>/Chart' */
  uint8_T is_active_Ostacolo;          /* '<Root>/Chart' */
  uint8_T is_Ostacolo;                 /* '<Root>/Chart' */
  uint8_T is_Ostacolo_Presente;        /* '<Root>/Chart' */
  uint8_T is_active_BUTTON1;           /* '<Root>/Chart' */
  uint8_T is_BUTTON1;                  /* '<Root>/Chart' */
  uint8_T is_active_BUTTON3;           /* '<Root>/Chart' */
  uint8_T is_BUTTON3;                  /* '<Root>/Chart' */
  uint8_T is_active_BUTTON2;           /* '<Root>/Chart' */
  uint8_T is_BUTTON2;                  /* '<Root>/Chart' */
  uint8_T is_active_Regolazione_Tempo_Chi;/* '<Root>/Chart' */
  uint8_T is_Regolazione_Tempo_Chiusura;/* '<Root>/Chart' */
  uint8_T temporalCounter_i2;          /* '<Root>/Chart' */
  uint8_T temporalCounter_i4;          /* '<Root>/Chart' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T P1;                           /* '<Root>/P1' */
  real_T P2;                           /* '<Root>/P2' */
  real_T B1;                           /* '<Root>/B1' */
  real_T B2;                           /* '<Root>/B2' */
  real_T B3;                           /* '<Root>/B3' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T LedG;                         /* '<Root>/LedG' */
  real_T LedR;                         /* '<Root>/LedR' */
  real_T LedY;                         /* '<Root>/LedY' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void Chart_initialize(void);
extern void Chart_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('state/Chart')    - opens subsystem state/Chart
 * hilite_system('state/Chart/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'state'
 * '<S1>'   : 'state/Chart'
 */
#endif                                 /* RTW_HEADER_Chart_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
