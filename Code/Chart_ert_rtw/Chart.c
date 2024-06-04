/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Chart.c
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

#include "Chart.h"
#include "rtwtypes.h"
#include <math.h>
#include <stddef.h>

/* Named constants for Chart: '<Root>/Chart' */
#define CALL_EVENT                     (-1)
#define IN_Aggiunta_Tempo_Chiusura     ((uint8_T)1U)
#define IN_Aggiunta_Tempo_Lavoro       ((uint8_T)1U)
#define IN_Aperto                      ((uint8_T)1U)
#define IN_Aperto_Con_Ostacolo_Led     ((uint8_T)1U)
#define IN_Aperto_con_ostacolo         ((uint8_T)2U)
#define IN_Apertura                    ((uint8_T)1U)
#define IN_Blink_AOff                  ((uint8_T)1U)
#define IN_Blink_AOn                   ((uint8_T)2U)
#define IN_Blink_COff                  ((uint8_T)1U)
#define IN_Blink_COn                   ((uint8_T)2U)
#define IN_Blink_EOff                  ((uint8_T)1U)
#define IN_Blink_EOn                   ((uint8_T)2U)
#define IN_Blink_OOff                  ((uint8_T)1U)
#define IN_Blink_OOn                   ((uint8_T)2U)
#define IN_Chiuso                      ((uint8_T)1U)
#define IN_Chiusura                    ((uint8_T)2U)
#define IN_Errore                      ((uint8_T)2U)
#define IN_Fermo                       ((uint8_T)2U)
#define IN_In_Apertura                 ((uint8_T)3U)
#define IN_In_Chiusura                 ((uint8_T)3U)
#define IN_In_Errore                   ((uint8_T)1U)
#define IN_Inattivo                    ((uint8_T)3U)
#define IN_LED_Rosso_Errore            ((uint8_T)2U)
#define IN_LOGIC                       ((uint8_T)1U)
#define IN_LONGPRESSED1                ((uint8_T)1U)
#define IN_LONGPRESSED2                ((uint8_T)1U)
#define IN_LONGPRESSED3                ((uint8_T)1U)
#define IN_NO_ACTIVE_CHILD             ((uint8_T)0U)
#define IN_Ostacolo_Presente           ((uint8_T)3U)
#define IN_PRESSED1                    ((uint8_T)2U)
#define IN_PRESSED2                    ((uint8_T)2U)
#define IN_PRESSED3                    ((uint8_T)2U)
#define IN_RELEASED1                   ((uint8_T)3U)
#define IN_RELEASED2                   ((uint8_T)3U)
#define IN_RELEASED3                   ((uint8_T)3U)
#define IN_Tempo_Chiusura              ((uint8_T)2U)
#define IN_Tempo_Lavoro                ((uint8_T)2U)
#define OFF                            (0.0)
#define ON                             (1.0)
#define event_buttonpressed1           (0)
#define event_buttonpressed2           (1)
#define event_buttonpressed3           (2)
#define NumBitsPerChar                 8U

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Forward declaration for local functions */
static void Chiusura(const int32_T *sfEvent);
static void Cancello(const int32_T *sfEvent);
static real_T mod(real_T x);
static void Regolazione_Tempo_Lavoro(const int32_T *sfEvent);
static void Ostacolo(const int32_T *sfEvent);
static void Regolazione_Tempo_Chiusura(const int32_T *sfEvent);
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);

#define NOT_USING_NONFINITE_LITERALS   1

extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static void rt_InitInfAndNaN(size_t realSize);
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
static real_T rtGetInf(void);
static real32_T rtGetInfF(void);
static real_T rtGetMinusInf(void);
static real32_T rtGetMinusInfF(void);

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0.0F } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
static void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  boolean_T result = (boolean_T) 0;
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  if (bitsPerReal == 32U) {
    result = rtIsNaNF((real32_T)value);
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.fltVal = value;
    result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
                         ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                          (tmpVal.bitVal.words.wordL != 0) ));
  }

  return result;
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  IEEESingle tmp;
  tmp.wordL.wordLreal = value;
  return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                     (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
}

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

/* Function for Chart: '<Root>/Chart' */
static void Chiusura(const int32_T *sfEvent)
{
  /* Inport: '<Root>/P1' */
  if ((*sfEvent == event_buttonpressed1) && (rtU.P1 == OFF)) {
    switch (rtDW.is_Chiusura) {
     case IN_Chiuso:
      rtDW.Var_Chiuso = OFF;
      rtDW.is_Chiusura = IN_NO_ACTIVE_CHILD;
      break;

     case IN_Errore:
      switch (rtDW.is_Errore) {
       case IN_In_Errore:
        rtDW.is_In_Errore = IN_NO_ACTIVE_CHILD;
        rtDW.is_Errore = IN_NO_ACTIVE_CHILD;
        break;

       case IN_LED_Rosso_Errore:
        /* Outport: '<Root>/LedR' */
        rtY.LedR = OFF;
        rtDW.is_Errore = IN_NO_ACTIVE_CHILD;
        break;
      }

      rtDW.is_Chiusura = IN_NO_ACTIVE_CHILD;
      break;

     case IN_In_Chiusura:
      rtDW.is_In_Chiusura = IN_NO_ACTIVE_CHILD;
      rtDW.is_Chiusura = IN_NO_ACTIVE_CHILD;
      break;
    }

    rtDW.is_Cancello = IN_Apertura;
    rtDW.Var_Aperto = OFF;
    rtDW.temporalCounter_i1 = 0U;
    rtDW.is_Apertura = IN_In_Apertura;
    rtDW.temporalCounter_i2 = 0U;
    rtDW.is_In_Apertura = IN_Blink_AOff;

    /* Outport: '<Root>/LedY' */
    rtY.LedY = OFF;
  } else {
    switch (rtDW.is_Chiusura) {
     case IN_Chiuso:
      break;

     case IN_Errore:
      /* Inport: '<Root>/P2' */
      if (rtU.P2 == ON) {
        switch (rtDW.is_Errore) {
         case IN_In_Errore:
          rtDW.is_In_Errore = IN_NO_ACTIVE_CHILD;
          rtDW.is_Errore = IN_NO_ACTIVE_CHILD;
          break;

         case IN_LED_Rosso_Errore:
          rtDW.is_Errore = IN_NO_ACTIVE_CHILD;
          break;
        }

        rtDW.is_Chiusura = IN_Chiuso;

        /* Outport: '<Root>/LedG' */
        rtY.LedG = OFF;

        /* Outport: '<Root>/LedR' */
        rtY.LedR = OFF;

        /* Outport: '<Root>/LedY' */
        rtY.LedY = OFF;
        rtDW.Var_Chiuso = ON;
      } else if (rtDW.is_Errore == IN_In_Errore) {
        if (rtDW.temporalCounter_i1 >= 100U) {
          if (rtDW.is_In_Errore == IN_Blink_EOn) {
            /* Outport: '<Root>/LedY' */
            rtY.LedY = OFF;
            rtDW.is_In_Errore = IN_NO_ACTIVE_CHILD;
          } else {
            rtDW.is_In_Errore = IN_NO_ACTIVE_CHILD;
          }

          rtDW.is_Errore = IN_LED_Rosso_Errore;

          /* Outport: '<Root>/LedR' */
          rtY.LedR = ON;
        } else {
          switch (rtDW.is_In_Errore) {
           case IN_Blink_EOff:
            if (rtDW.temporalCounter_i2 >= 20U) {
              rtDW.temporalCounter_i2 = 0U;
              rtDW.is_In_Errore = IN_Blink_EOn;

              /* Outport: '<Root>/LedY' */
              rtY.LedY = ON;
            }
            break;

           case IN_Blink_EOn:
            if (rtDW.temporalCounter_i2 >= 20U) {
              rtDW.temporalCounter_i2 = 0U;
              rtDW.is_In_Errore = IN_Blink_EOff;

              /* Outport: '<Root>/LedY' */
              rtY.LedY = OFF;
            }
            break;
          }
        }
      }
      break;

     case IN_In_Chiusura:
      /* Inport: '<Root>/P2' */
      if ((rtU.P2 == ON) && (rtU.P1 == OFF)) {
        rtDW.is_In_Chiusura = IN_NO_ACTIVE_CHILD;
        rtDW.is_Chiusura = IN_Chiuso;

        /* Outport: '<Root>/LedG' */
        rtY.LedG = OFF;

        /* Outport: '<Root>/LedR' */
        rtY.LedR = OFF;

        /* Outport: '<Root>/LedY' */
        rtY.LedY = OFF;
        rtDW.Var_Chiuso = ON;
      } else if ((rtDW.temporalCounter_i1 >= (uint32_T)ceil(rtDW.TL * 10.0)) &&
                 (rtU.P2 == OFF)) {
        rtDW.is_In_Chiusura = IN_NO_ACTIVE_CHILD;
        rtDW.is_Chiusura = IN_Errore;
        rtDW.temporalCounter_i1 = 0U;
        rtDW.is_Errore = IN_In_Errore;
        rtDW.temporalCounter_i2 = 0U;
        rtDW.is_In_Errore = IN_Blink_EOff;

        /* Outport: '<Root>/LedY' */
        rtY.LedY = OFF;
      } else if (rtU.P1 == ON) {
        rtDW.is_In_Chiusura = IN_NO_ACTIVE_CHILD;
        rtDW.is_Chiusura = IN_NO_ACTIVE_CHILD;
        rtDW.is_Cancello = IN_Apertura;
        rtDW.Var_Aperto = OFF;
        rtDW.temporalCounter_i1 = 0U;
        rtDW.is_Apertura = IN_In_Apertura;
        rtDW.temporalCounter_i2 = 0U;
        rtDW.is_In_Apertura = IN_Blink_AOff;

        /* Outport: '<Root>/LedY' */
        rtY.LedY = OFF;
      } else {
        switch (rtDW.is_In_Chiusura) {
         case IN_Blink_COff:
          if (rtDW.temporalCounter_i2 >= 20U) {
            rtDW.temporalCounter_i2 = 0U;
            rtDW.is_In_Chiusura = IN_Blink_COn;

            /* Outport: '<Root>/LedY' */
            rtY.LedY = ON;
          }
          break;

         case IN_Blink_COn:
          if (rtDW.temporalCounter_i2 >= 20U) {
            rtDW.temporalCounter_i2 = 0U;
            rtDW.is_In_Chiusura = IN_Blink_COff;

            /* Outport: '<Root>/LedY' */
            rtY.LedY = OFF;
          }
          break;
        }
      }
      break;
    }
  }

  /* End of Inport: '<Root>/P1' */
}

/* Function for Chart: '<Root>/Chart' */
static void Cancello(const int32_T *sfEvent)
{
  switch (rtDW.is_Cancello) {
   case IN_Apertura:
    /* Inport: '<Root>/P1' */
    if ((*sfEvent == event_buttonpressed1) && (rtU.P1 == OFF)) {
      switch (rtDW.is_Apertura) {
       case IN_Aperto:
        /* Outport: '<Root>/LedG' */
        rtY.LedG = OFF;

        /* Outport: '<Root>/LedR' */
        rtY.LedR = OFF;
        rtDW.Var_Aperto = OFF;
        rtDW.is_Apertura = IN_NO_ACTIVE_CHILD;
        break;

       case IN_In_Apertura:
        rtDW.is_In_Apertura = IN_NO_ACTIVE_CHILD;
        rtDW.is_Apertura = IN_NO_ACTIVE_CHILD;
        break;

       default:
        rtDW.is_Apertura = IN_NO_ACTIVE_CHILD;
        break;
      }

      rtDW.is_Cancello = IN_Chiusura;
      rtDW.Var_Chiuso = OFF;
      rtDW.temporalCounter_i1 = 0U;
      rtDW.is_Chiusura = IN_In_Chiusura;
      rtDW.temporalCounter_i2 = 0U;
      rtDW.is_In_Chiusura = IN_Blink_COff;

      /* Outport: '<Root>/LedY' */
      rtY.LedY = OFF;
    } else {
      switch (rtDW.is_Apertura) {
       case IN_Aperto:
        if ((rtDW.temporalCounter_i1 >= (uint32_T)ceil(rtDW.TC * 10.0)) &&
            (rtU.P1 == OFF)) {
          /* Outport: '<Root>/LedG' */
          rtY.LedG = OFF;

          /* Outport: '<Root>/LedR' */
          rtY.LedR = OFF;
          rtDW.Var_Aperto = OFF;
          rtDW.is_Apertura = IN_NO_ACTIVE_CHILD;
          rtDW.is_Cancello = IN_Chiusura;
          rtDW.Var_Chiuso = OFF;
          rtDW.temporalCounter_i1 = 0U;
          rtDW.is_Chiusura = IN_In_Chiusura;
          rtDW.temporalCounter_i2 = 0U;
          rtDW.is_In_Chiusura = IN_Blink_COff;

          /* Outport: '<Root>/LedY' */
          rtY.LedY = OFF;
        } else if (rtU.P1 == ON) {
          rtDW.is_Apertura = IN_Aperto_con_ostacolo;

          /* Outport: '<Root>/LedG' */
          rtY.LedG = ON;

          /* Outport: '<Root>/LedR' */
          rtY.LedR = ON;

          /* Outport: '<Root>/LedY' */
          rtY.LedY = ON;
          rtDW.Var_Aperto = ON;
        }
        break;

       case IN_Aperto_con_ostacolo:
        if (rtU.P1 == OFF) {
          rtDW.temporalCounter_i1 = 0U;
          rtDW.is_Apertura = IN_Aperto;

          /* Outport: '<Root>/LedG' */
          rtY.LedG = ON;

          /* Outport: '<Root>/LedR' */
          rtY.LedR = ON;

          /* Outport: '<Root>/LedY' */
          rtY.LedY = ON;
          rtDW.Var_Aperto = ON;
        }
        break;

       case IN_In_Apertura:
        if (rtDW.temporalCounter_i1 >= (uint32_T)ceil(rtDW.TL * 10.0)) {
          rtDW.is_In_Apertura = IN_NO_ACTIVE_CHILD;
          rtDW.temporalCounter_i1 = 0U;
          rtDW.is_Apertura = IN_Aperto;

          /* Outport: '<Root>/LedG' */
          rtY.LedG = ON;

          /* Outport: '<Root>/LedR' */
          rtY.LedR = ON;

          /* Outport: '<Root>/LedY' */
          rtY.LedY = ON;
          rtDW.Var_Aperto = ON;
        } else {
          switch (rtDW.is_In_Apertura) {
           case IN_Blink_AOff:
            if (rtDW.temporalCounter_i2 >= 20U) {
              rtDW.temporalCounter_i2 = 0U;
              rtDW.is_In_Apertura = IN_Blink_AOn;

              /* Outport: '<Root>/LedY' */
              rtY.LedY = ON;
            }
            break;

           case IN_Blink_AOn:
            if (rtDW.temporalCounter_i2 >= 20U) {
              rtDW.temporalCounter_i2 = 0U;
              rtDW.is_In_Apertura = IN_Blink_AOff;

              /* Outport: '<Root>/LedY' */
              rtY.LedY = OFF;
            }
            break;
          }
        }
        break;
      }
    }
    break;

   case IN_Chiusura:
    Chiusura(sfEvent);
    break;

   case IN_Inattivo:
    /* Inport: '<Root>/P1' incorporates:
     *  Inport: '<Root>/P2'
     */
    if (((rtU.P1 == OFF) && (rtU.P2 == OFF)) || ((rtU.P1 == ON) && (rtU.P2 ==
          OFF)) || ((rtU.P1 == OFF) && (rtU.P2 == ON))) {
      rtDW.Var_Inattivo = OFF;
      rtDW.is_Cancello = IN_Chiusura;
      rtDW.Var_Chiuso = OFF;
      rtDW.temporalCounter_i1 = 0U;
      rtDW.is_Chiusura = IN_In_Chiusura;
      rtDW.temporalCounter_i2 = 0U;
      rtDW.is_In_Chiusura = IN_Blink_COff;

      /* Outport: '<Root>/LedY' */
      rtY.LedY = OFF;
    }
    break;
  }
}

/* Function for Chart: '<Root>/Chart' */
static real_T mod(real_T x)
{
  real_T r;
  if (rtIsNaN(x)) {
    r = (rtNaN);
  } else if (rtIsInf(x)) {
    r = (rtNaN);
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = fmod(x, 120.0);
    if (r == 0.0) {
      r = 0.0;
    } else if (x < 0.0) {
      r += 120.0;
    }
  }

  return r;
}

/* Function for Chart: '<Root>/Chart' */
static void Regolazione_Tempo_Lavoro(const int32_T *sfEvent)
{
  switch (rtDW.is_Regolazione_Tempo_Lavoro) {
   case IN_Aggiunta_Tempo_Lavoro:
    rtDW.is_Regolazione_Tempo_Lavoro = IN_Tempo_Lavoro;
    break;

   case IN_Tempo_Lavoro:
    if ((rtDW.Var_Chiuso != 0.0) && (*sfEvent == event_buttonpressed3)) {
      rtDW.is_Regolazione_Tempo_Lavoro = IN_Aggiunta_Tempo_Lavoro;
      rtDW.TL = mod(rtDW.TL) + 10.0;
    }
    break;
  }
}

/* Function for Chart: '<Root>/Chart' */
static void Ostacolo(const int32_T *sfEvent)
{
  switch (rtDW.is_Ostacolo) {
   case IN_Aperto_Con_Ostacolo_Led:
    rtDW.is_Ostacolo = IN_Fermo;
    break;

   case IN_Fermo:
    /* Inport: '<Root>/P1' */
    if (((rtDW.Var_Inattivo != 0.0) || (rtDW.Var_Chiuso != 0.0) ||
         (rtDW.Var_Aperto != 0.0)) && (*sfEvent == event_buttonpressed1) &&
        (rtU.P1 == ON)) {
      rtDW.temporalCounter_i3 = 0U;
      rtDW.is_Ostacolo = IN_Ostacolo_Presente;
      rtDW.temporalCounter_i4 = 0U;
      rtDW.is_Ostacolo_Presente = IN_Blink_OOff;

      /* Outport: '<Root>/LedG' */
      rtY.LedG = OFF;
    }
    break;

   case IN_Ostacolo_Presente:
    /* Inport: '<Root>/P1' */
    if ((rtDW.Var_Aperto != 0.0) && ((rtU.P1 == OFF) || (rtDW.temporalCounter_i3
          >= 300U))) {
      rtDW.is_Ostacolo_Presente = IN_NO_ACTIVE_CHILD;
      rtDW.is_Ostacolo = IN_Aperto_Con_Ostacolo_Led;

      /* Outport: '<Root>/LedG' */
      rtY.LedG = ON;
    } else if ((rtU.P1 == OFF) || ((rtDW.temporalCounter_i3 >= 300U) &&
                (rtDW.Var_Aperto == OFF))) {
      if (rtDW.is_Ostacolo_Presente == IN_Blink_OOn) {
        /* Outport: '<Root>/LedG' */
        rtY.LedG = OFF;
        rtDW.is_Ostacolo_Presente = IN_NO_ACTIVE_CHILD;
      } else {
        rtDW.is_Ostacolo_Presente = IN_NO_ACTIVE_CHILD;
      }

      rtDW.is_Ostacolo = IN_Fermo;
    } else if (*sfEvent == event_buttonpressed1) {
      rtDW.temporalCounter_i3 = 0U;
      rtDW.is_Ostacolo = IN_Ostacolo_Presente;
      rtDW.temporalCounter_i4 = 0U;
      rtDW.is_Ostacolo_Presente = IN_Blink_OOff;

      /* Outport: '<Root>/LedG' */
      rtY.LedG = OFF;
    } else {
      switch (rtDW.is_Ostacolo_Presente) {
       case IN_Blink_OOff:
        if (rtDW.temporalCounter_i4 >= 10U) {
          rtDW.temporalCounter_i4 = 0U;
          rtDW.is_Ostacolo_Presente = IN_Blink_OOn;

          /* Outport: '<Root>/LedG' */
          rtY.LedG = ON;
        }
        break;

       case IN_Blink_OOn:
        if (rtDW.temporalCounter_i4 >= 10U) {
          rtDW.temporalCounter_i4 = 0U;
          rtDW.is_Ostacolo_Presente = IN_Blink_OOff;

          /* Outport: '<Root>/LedG' */
          rtY.LedG = OFF;
        }
        break;
      }
    }
    break;
  }
}

/* Function for Chart: '<Root>/Chart' */
static void Regolazione_Tempo_Chiusura(const int32_T *sfEvent)
{
  switch (rtDW.is_Regolazione_Tempo_Chiusura) {
   case IN_Aggiunta_Tempo_Chiusura:
    rtDW.is_Regolazione_Tempo_Chiusura = IN_Tempo_Chiusura;
    break;

   case IN_Tempo_Chiusura:
    if ((rtDW.Var_Chiuso != 0.0) && (*sfEvent == event_buttonpressed2)) {
      rtDW.is_Regolazione_Tempo_Chiusura = IN_Aggiunta_Tempo_Chiusura;
      rtDW.TC = mod(rtDW.TC) + 10.0;
    }
    break;
  }
}

/* Model step function */
void Chart_step(void)
{
  int32_T sfEvent;

  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/B1'
   *  Inport: '<Root>/B2'
   *  Inport: '<Root>/B3'
   */
  if (rtDW.temporalCounter_i1 < MAX_uint32_T) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.temporalCounter_i2 < 31U) {
    rtDW.temporalCounter_i2++;
  }

  if (rtDW.temporalCounter_i3 < 511U) {
    rtDW.temporalCounter_i3++;
  }

  if (rtDW.temporalCounter_i4 < 15U) {
    rtDW.temporalCounter_i4++;
  }

  sfEvent = CALL_EVENT;
  if (rtDW.is_active_c1_Chart == 0U) {
    rtDW.is_active_c1_Chart = 1U;
    rtDW.is_c1_Chart = IN_LOGIC;
    rtDW.is_active_Cancello = 1U;
    rtDW.Var_Inattivo = ON;
    rtDW.Var_Aperto = OFF;
    rtDW.Var_Chiuso = OFF;
    rtDW.is_Cancello = IN_Inattivo;

    /* Outport: '<Root>/LedG' */
    rtY.LedG = OFF;

    /* Outport: '<Root>/LedR' */
    rtY.LedR = OFF;

    /* Outport: '<Root>/LedY' */
    rtY.LedY = OFF;
    rtDW.is_active_Regolazione_Tempo_Lav = 1U;
    rtDW.TL = 10.0;
    rtDW.is_Regolazione_Tempo_Lavoro = IN_Tempo_Lavoro;
    rtDW.is_active_Ostacolo = 1U;
    rtDW.is_Ostacolo = IN_Fermo;
    rtDW.is_active_BUTTON1 = 1U;
    rtDW.is_BUTTON1 = IN_RELEASED1;
    rtDW.is_active_BUTTON3 = 1U;
    rtDW.is_BUTTON3 = IN_RELEASED3;
    rtDW.is_active_BUTTON2 = 1U;
    rtDW.is_BUTTON2 = IN_RELEASED2;
    rtDW.is_active_Regolazione_Tempo_Chi = 1U;
    rtDW.TC = 10.0;
    rtDW.is_Regolazione_Tempo_Chiusura = IN_Tempo_Chiusura;
  } else if (rtDW.is_c1_Chart == IN_LOGIC) {
    if (rtDW.is_active_Cancello != 0U) {
      Cancello(&sfEvent);
    }

    if (rtDW.is_active_Regolazione_Tempo_Lav != 0U) {
      Regolazione_Tempo_Lavoro(&sfEvent);
    }

    if (rtDW.is_active_Ostacolo != 0U) {
      Ostacolo(&sfEvent);
    }

    if (rtDW.is_active_BUTTON1 != 0U) {
      switch (rtDW.is_BUTTON1) {
       case IN_LONGPRESSED1:
        if (rtU.B1 == OFF) {
          rtDW.is_BUTTON1 = IN_RELEASED1;
        } else {
          sfEvent = event_buttonpressed1;
          if (rtDW.is_active_Cancello != 0U) {
            Cancello(&sfEvent);
          }

          if (rtDW.is_active_Ostacolo != 0U) {
            Ostacolo(&sfEvent);
          }

          sfEvent = CALL_EVENT;
        }
        break;

       case IN_PRESSED1:
        if (rtU.B1 == OFF) {
          rtDW.is_BUTTON1 = IN_LONGPRESSED1;
          sfEvent = event_buttonpressed1;
          if (rtDW.is_active_Cancello != 0U) {
            Cancello(&sfEvent);
          }

          if (rtDW.is_active_Ostacolo != 0U) {
            Ostacolo(&sfEvent);
          }

          sfEvent = CALL_EVENT;
        }
        break;

       case IN_RELEASED1:
        if (rtU.B1 == ON) {
          rtDW.is_BUTTON1 = IN_PRESSED1;
        }
        break;
      }
    }

    if (rtDW.is_active_BUTTON3 != 0U) {
      switch (rtDW.is_BUTTON3) {
       case IN_LONGPRESSED3:
        if (rtU.B3 == OFF) {
          rtDW.is_BUTTON3 = IN_RELEASED3;
        } else {
          sfEvent = event_buttonpressed3;
          if (rtDW.is_active_Regolazione_Tempo_Lav != 0U) {
            Regolazione_Tempo_Lavoro(&sfEvent);
          }

          sfEvent = -1;
        }
        break;

       case IN_PRESSED3:
        if (rtU.B3 == OFF) {
          rtDW.is_BUTTON3 = IN_LONGPRESSED3;
          sfEvent = event_buttonpressed3;
          if (rtDW.is_active_Regolazione_Tempo_Lav != 0U) {
            Regolazione_Tempo_Lavoro(&sfEvent);
          }

          sfEvent = -1;
        }
        break;

       case IN_RELEASED3:
        if (rtU.B3 == ON) {
          rtDW.is_BUTTON3 = IN_PRESSED3;
        }
        break;
      }
    }

    if (rtDW.is_active_BUTTON2 != 0U) {
      switch (rtDW.is_BUTTON2) {
       case IN_LONGPRESSED2:
        if (rtU.B2 == OFF) {
          rtDW.is_BUTTON2 = IN_RELEASED2;
        } else {
          sfEvent = event_buttonpressed2;
          if (rtDW.is_active_Regolazione_Tempo_Chi != 0U) {
            Regolazione_Tempo_Chiusura(&sfEvent);
          }

          sfEvent = -1;
        }
        break;

       case IN_PRESSED2:
        if (rtU.B2 == OFF) {
          rtDW.is_BUTTON2 = IN_LONGPRESSED2;
          sfEvent = event_buttonpressed2;
          if (rtDW.is_active_Regolazione_Tempo_Chi != 0U) {
            Regolazione_Tempo_Chiusura(&sfEvent);
          }

          sfEvent = -1;
        }
        break;

       case IN_RELEASED2:
        if (rtU.B2 == ON) {
          rtDW.is_BUTTON2 = IN_PRESSED2;
        }
        break;
      }
    }

    if (rtDW.is_active_Regolazione_Tempo_Chi != 0U) {
      Regolazione_Tempo_Chiusura(&sfEvent);
    }
  }

  /* End of Chart: '<Root>/Chart' */
}

/* Model initialize function */
void Chart_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* SystemInitialize for Chart: '<Root>/Chart' */
  rtDW.TC = 10.0;
  rtDW.TL = 10.0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
