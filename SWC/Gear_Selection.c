/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Gear_Selection.c
 *
 * Code generated for Simulink model 'TCU_Final'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Mon Dec  1 11:27:07 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtwtypes.h"
#include "Gear_Selection.h"
#include <math.h>
#include "TCU_Final_private.h"

/* Named constants for Chart: '<S1>/Gear_Selection' */
#define TCU_Final_IN_Fifth             ((uint8_T)1U)
#define TCU_Final_IN_First             ((uint8_T)2U)
#define TCU_Final_IN_Fourth            ((uint8_T)3U)
#define TCU_Final_IN_Gear_Selection    ((uint8_T)1U)
#define TCU_Final_IN_NO_ACTIVE_CHILD   ((uint8_T)0U)
#define TCU_Final_IN_Off               ((uint8_T)2U)
#define TCU_Final_IN_Second            ((uint8_T)4U)
#define TCU_Final_IN_Selection         ((uint8_T)3U)
#define TCU_Final_IN_Sixth             ((uint8_T)5U)
#define TCU_Final_IN_Third             ((uint8_T)6U)
#define TCU_Final_IN_drive             ((uint8_T)1U)
#define TCU_Final_IN_neutral           ((uint8_T)2U)
#define TCU_Final_IN_parking           ((uint8_T)3U)
#define TCU_Final_IN_primera           ((uint8_T)4U)
#define TCU_Final_IN_reverse           ((uint8_T)5U)
#define TCU_Final_IN_segunda           ((uint8_T)6U)
#define TCU_Final_IN_tercera           ((uint8_T)7U)

double fmax(double a, double b)
{
    return (a > b) ? a : b;
}

double fmin(double a, double b)
{
    return (a < b) ? a : b;
}


/* Forward declaration for local functions */
static real_T TCU_Final_UpdateDriveStyle(real_T Engine_RPM, real_T VehSpeed_kph,
  real_T Throttle_pct, DW_Gear_Selection_TCU_Final_T *localDW);
static void TCU_Final_GearShiftScheduler(real_T Engine_RPM, real_T VehSpeed_kph,
  real_T Throttle_pct, real_T Actual_Gear, real_T DriveMode, real_T DriveStyle,
  boolean_T *UpshiftReq, boolean_T *DownshiftReq);
static void TCU_Final_Gear_Selection_i(real_T rtu_Gear_Lever_Position, real_T
  rtu_Engine_RPM, real_T rtu_Vehicle_Speed_Reference, real_T
  rtu_Throttle_Position_Sensor, real_T rtu_Driver_Mode_Selection, boolean_T
  *rty_Shift_Solenoid_A, boolean_T *rty_Shift_Solenoid_B, boolean_T
  *rty_Shift_Solenoid_C, boolean_T *rty_Shift_Solenoid_D, real_T
  *rty_Torque_Reduction_Request, DW_Gear_Selection_TCU_Final_T *localDW);

/* Function for Chart: '<S1>/Gear_Selection' */
static real_T TCU_Final_UpdateDriveStyle(real_T Engine_RPM, real_T VehSpeed_kph,
  real_T Throttle_pct, DW_Gear_Selection_TCU_Final_T *localDW)
{
  real_T x;
  if (!localDW->initialized_not_empty) {
    localDW->prevSpeed = VehSpeed_kph;
    localDW->initialized_not_empty = true;
  }

  Throttle_pct = fmax(0.0, fmin(100.0, Throttle_pct));
  Engine_RPM = fmax(0.0, Engine_RPM);
  VehSpeed_kph = fmax(0.0, VehSpeed_kph);
  x = (VehSpeed_kph - localDW->prevSpeed) / 3.6 / 0.05;
  localDW->prevSpeed = VehSpeed_kph;
  localDW->styleState += ((((fmax(0.0, fmin(1.0, (Engine_RPM - 1500.0) / 2000.0))
    * 0.3 + Throttle_pct / 100.0 * 0.5) + fmin(fmax(x, 0.0) / 3.0, 1.0) * 0.2) -
    0.5) * 2.0 - localDW->styleState) * 0.02;
  return fmax(-1.0, fmin(1.0, localDW->styleState));
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for Chart: '<S1>/Gear_Selection' */
static void TCU_Final_GearShiftScheduler(real_T Engine_RPM, real_T VehSpeed_kph,
  real_T Throttle_pct, real_T Actual_Gear, real_T DriveMode, real_T DriveStyle,
  boolean_T *UpshiftReq, boolean_T *DownshiftReq)
{
  real_T downRpm;
  real_T styleFactor;
  real_T upRpm;
  static const real_T c[3] = { 0.85, 1.0, 1.15 };

  static const int16_T b[5] = { 2500, 2800, 3100, 3400, 3600 };

  static const int8_T d[6] = { 0, 15, 35, 60, 90, 120 };

  boolean_T guard1;
  Throttle_pct = fmax(0.0, fmin(100.0, Throttle_pct));
  DriveMode = fmax(0.0, fmin(2.0, DriveMode));
  Actual_Gear = fmax(1.0, fmin(6.0, rt_roundd_snf(Actual_Gear)));
  *UpshiftReq = false;
  *DownshiftReq = false;
  styleFactor = 0.2 * fmax(-1.0, fmin(1.0, DriveStyle)) + 1.0;
  upRpm = (rtInf);
  downRpm = (rtMinusInf);
  if (Actual_Gear < 6.0) {
    upRpm = c[(int32_T)(DriveMode + 1.0) - 1] * (real_T)b[(int32_T)Actual_Gear -
      1] * styleFactor + 4.0 * Throttle_pct;
  }

  if (Actual_Gear > 1.0) {
    downRpm = (((Actual_Gear - 1.0) - 1.0) * 200.0 + 1500.0) * c[(int32_T)
      (DriveMode + 1.0) - 1] * styleFactor + 2.0 * Throttle_pct;
  }

  if (VehSpeed_kph < 3.0) {
    *DownshiftReq = (Actual_Gear > 1.0);
  } else {
    guard1 = false;
    if ((Throttle_pct > 90.0) && (Engine_RPM < 3500.0)) {
      if (Actual_Gear > 1.0) {
        *DownshiftReq = true;
      } else {
        guard1 = true;
      }
    } else if ((Throttle_pct > 75.0) && (Engine_RPM < 4000.0) && (Actual_Gear >
                1.0)) {
      *DownshiftReq = true;
    } else {
      guard1 = true;
    }

    if (guard1) {
      if ((Engine_RPM < downRpm) && (Actual_Gear > 1.0)) {
        *DownshiftReq = true;
      } else if ((Engine_RPM > upRpm) && (Actual_Gear < 6.0)) {
        *UpshiftReq = (VehSpeed_kph >= d[(int32_T)Actual_Gear]);
      }
    }
  }
}

/* Function for Chart: '<S1>/Gear_Selection' */
static void TCU_Final_Gear_Selection_i(real_T rtu_Gear_Lever_Position, real_T
  rtu_Engine_RPM, real_T rtu_Vehicle_Speed_Reference, real_T
  rtu_Throttle_Position_Sensor, real_T rtu_Driver_Mode_Selection, boolean_T
  *rty_Shift_Solenoid_A, boolean_T *rty_Shift_Solenoid_B, boolean_T
  *rty_Shift_Solenoid_C, boolean_T *rty_Shift_Solenoid_D, real_T
  *rty_Torque_Reduction_Request, DW_Gear_Selection_TCU_Final_T *localDW)
{
  real_T DriveStyle;
  boolean_T DownshiftReq;
  boolean_T UpshiftReq;
  if (rtu_Gear_Lever_Position <= 3.0) {
    localDW->is_Gear_Selection = TCU_Final_IN_NO_ACTIVE_CHILD;
    localDW->is_c1_TCU_GS = TCU_Final_IN_Selection;
    localDW->is_Selection = TCU_Final_IN_parking;
    localDW->D = 0.0;
  } else {
    DriveStyle = TCU_Final_UpdateDriveStyle(rtu_Engine_RPM,
      rtu_Vehicle_Speed_Reference, rtu_Throttle_Position_Sensor, localDW);
    TCU_Final_GearShiftScheduler(rtu_Engine_RPM, rtu_Vehicle_Speed_Reference,
      rtu_Throttle_Position_Sensor, localDW->Current_Gear_State,
      rtu_Driver_Mode_Selection, DriveStyle, &UpshiftReq, &DownshiftReq);
    switch (localDW->is_Gear_Selection) {
     case TCU_Final_IN_Fifth:
      if (UpshiftReq && (localDW->Current_Gear_State == 5.0)) {
        *rty_Torque_Reduction_Request = 1.0;
        localDW->temporalCounter_i1 = 0U;
        localDW->is_Gear_Selection = TCU_Final_IN_Sixth;
        localDW->Current_Gear_State = 6.0;
      } else if (DownshiftReq && (localDW->Current_Gear_State == 5.0)) {
        *rty_Torque_Reduction_Request = 1.0;
        localDW->temporalCounter_i1 = 0U;
        localDW->is_Gear_Selection = TCU_Final_IN_Fourth;
        localDW->Current_Gear_State = 4.0;
      } else {
        *rty_Shift_Solenoid_A = false;
        *rty_Shift_Solenoid_B = false;
        *rty_Shift_Solenoid_C = true;
        *rty_Shift_Solenoid_D = true;
        *rty_Torque_Reduction_Request = 0.0;
      }
      break;

     case TCU_Final_IN_First:
      if (UpshiftReq && (localDW->Current_Gear_State == 1.0) &&
          (rtu_Gear_Lever_Position != 5.0)) {
        *rty_Torque_Reduction_Request = 1.0;
        localDW->temporalCounter_i1 = 0U;
        localDW->is_Gear_Selection = TCU_Final_IN_Second;
        localDW->Current_Gear_State = 2.0;
      } else {
        *rty_Shift_Solenoid_A = true;
        *rty_Shift_Solenoid_B = false;
        *rty_Shift_Solenoid_C = false;
        *rty_Shift_Solenoid_D = false;
        *rty_Torque_Reduction_Request = 0.0;
      }
      break;

     case TCU_Final_IN_Fourth:
      if (UpshiftReq && (localDW->Current_Gear_State == 4.0)) {
        *rty_Torque_Reduction_Request = 1.0;
        localDW->temporalCounter_i1 = 0U;
        localDW->is_Gear_Selection = TCU_Final_IN_Fifth;
        localDW->Current_Gear_State = 5.0;
      } else if (DownshiftReq && (localDW->Current_Gear_State == 4.0)) {
        *rty_Torque_Reduction_Request = 1.0;
        localDW->temporalCounter_i1 = 0U;
        localDW->is_Gear_Selection = TCU_Final_IN_Third;
        localDW->Current_Gear_State = 3.0;
      } else {
        *rty_Shift_Solenoid_A = false;
        *rty_Shift_Solenoid_B = true;
        *rty_Shift_Solenoid_C = true;
        *rty_Shift_Solenoid_D = false;
        *rty_Torque_Reduction_Request = 0.0;
      }
      break;

     case TCU_Final_IN_Second:
      if (UpshiftReq && (localDW->Current_Gear_State == 2.0) &&
          (rtu_Gear_Lever_Position != 6.0)) {
        *rty_Torque_Reduction_Request = 1.0;
        localDW->temporalCounter_i1 = 0U;
        localDW->is_Gear_Selection = TCU_Final_IN_Third;
        localDW->Current_Gear_State = 3.0;
      } else if (DownshiftReq && (localDW->Current_Gear_State == 2.0)) {
        *rty_Torque_Reduction_Request = 1.0;
        localDW->temporalCounter_i1 = 0U;
        localDW->is_Gear_Selection = TCU_Final_IN_First;
        localDW->Current_Gear_State = 1.0;
      } else {
        *rty_Shift_Solenoid_A = true;
        *rty_Shift_Solenoid_B = true;
        *rty_Shift_Solenoid_C = false;
        *rty_Shift_Solenoid_D = false;
        *rty_Torque_Reduction_Request = 0.0;
      }
      break;

     case TCU_Final_IN_Sixth:
      if (DownshiftReq && (localDW->Current_Gear_State == 6.0)) {
        *rty_Torque_Reduction_Request = 1.0;
        localDW->temporalCounter_i1 = 0U;
        localDW->is_Gear_Selection = TCU_Final_IN_Fifth;
        localDW->Current_Gear_State = 5.0;
      } else {
        *rty_Shift_Solenoid_A = false;
        *rty_Shift_Solenoid_B = false;
        *rty_Shift_Solenoid_C = false;
        *rty_Shift_Solenoid_D = true;
        *rty_Torque_Reduction_Request = 0.0;
      }
      break;

     default:
      /* case IN_Third: */
      if (UpshiftReq && (localDW->Current_Gear_State == 3.0) &&
          (rtu_Gear_Lever_Position != 7.0)) {
        *rty_Torque_Reduction_Request = 1.0;
        localDW->temporalCounter_i1 = 0U;
        localDW->is_Gear_Selection = TCU_Final_IN_Fourth;
        localDW->Current_Gear_State = 4.0;
      } else if (DownshiftReq && (localDW->Current_Gear_State == 3.0)) {
        *rty_Torque_Reduction_Request = 1.0;
        localDW->temporalCounter_i1 = 0U;
        localDW->is_Gear_Selection = TCU_Final_IN_Second;
        localDW->Current_Gear_State = 2.0;
      } else {
        *rty_Shift_Solenoid_A = true;
        *rty_Shift_Solenoid_B = true;
        *rty_Shift_Solenoid_C = true;
        *rty_Shift_Solenoid_D = false;
        *rty_Torque_Reduction_Request = 0.0;
      }
      break;
    }
  }
}

/* System initialize for atomic system: '<S1>/Gear_Selection' */
void TCU_Final_Gear_Selection_Init(boolean_T *rty_Shift_Solenoid_Park, boolean_T
  *rty_Shift_Solenoid_Reverse, boolean_T *rty_Shift_Solenoid_Neutral, boolean_T *
  rty_Shift_Solenoid_A, boolean_T *rty_Shift_Solenoid_B, boolean_T
  *rty_Shift_Solenoid_C, boolean_T *rty_Shift_Solenoid_D, real_T
  *rty_Torque_Reduction_Request)
{
  *rty_Shift_Solenoid_Park = false;
  *rty_Shift_Solenoid_Reverse = false;
  *rty_Shift_Solenoid_Neutral = false;
  *rty_Shift_Solenoid_A = false;
  *rty_Shift_Solenoid_B = false;
  *rty_Shift_Solenoid_C = false;
  *rty_Shift_Solenoid_D = false;
  *rty_Torque_Reduction_Request = 0.0;
}

/* Output and update for atomic system: '<S1>/Gear_Selection' */
void TCU_Final_Gear_Selection(real_T rtu_Ignition, real_T
  rtu_Gear_Lever_Position, real_T rtu_Engine_RPM, real_T
  rtu_Vehicle_Speed_Reference, real_T rtu_Throttle_Position_Sensor, boolean_T
  rtu_Brake_Pedal_Switch, real_T rtu_Driver_Mode_Selection, boolean_T
  *rty_Shift_Solenoid_Park, boolean_T *rty_Shift_Solenoid_Reverse, boolean_T
  *rty_Shift_Solenoid_Neutral, boolean_T *rty_Shift_Solenoid_A, boolean_T
  *rty_Shift_Solenoid_B, boolean_T *rty_Shift_Solenoid_C, boolean_T
  *rty_Shift_Solenoid_D, real_T *rty_Torque_Reduction_Request,
  DW_Gear_Selection_TCU_Final_T *localDW)
{
  if (localDW->temporalCounter_i1 < 31) {
    localDW->temporalCounter_i1++;
  }

  /* Chart: '<S1>/Gear_Selection' */
  if (localDW->is_active_c1_TCU_GS == 0) {
    localDW->is_active_c1_TCU_GS = 1U;
    localDW->is_c1_TCU_GS = TCU_Final_IN_Off;
  } else {
    switch (localDW->is_c1_TCU_GS) {
     case TCU_Final_IN_Gear_Selection:
      TCU_Final_Gear_Selection_i(rtu_Gear_Lever_Position, rtu_Engine_RPM,
        rtu_Vehicle_Speed_Reference, rtu_Throttle_Position_Sensor,
        rtu_Driver_Mode_Selection, rty_Shift_Solenoid_A, rty_Shift_Solenoid_B,
        rty_Shift_Solenoid_C, rty_Shift_Solenoid_D, rty_Torque_Reduction_Request,
        localDW);
      break;

     case TCU_Final_IN_Off:
      if (rtu_Ignition == 2.0) {
        localDW->is_c1_TCU_GS = TCU_Final_IN_Selection;
        localDW->is_Selection = TCU_Final_IN_parking;
        localDW->D = 0.0;
      }
      break;

     default:
      /* case IN_Selection: */
      if (rtu_Ignition == 0.0) {
        localDW->is_Selection = TCU_Final_IN_NO_ACTIVE_CHILD;
        localDW->is_c1_TCU_GS = TCU_Final_IN_Off;
      } else if (localDW->D >= 1.0) {
        localDW->is_Selection = TCU_Final_IN_NO_ACTIVE_CHILD;
        localDW->is_c1_TCU_GS = TCU_Final_IN_Gear_Selection;
        localDW->temporalCounter_i1 = 0U;
        localDW->is_Gear_Selection = TCU_Final_IN_First;
        localDW->Current_Gear_State = 1.0;
      } else {
        switch (localDW->is_Selection) {
         case TCU_Final_IN_drive:
          if (rtu_Gear_Lever_Position == 5.0) {
            localDW->is_Selection = TCU_Final_IN_primera;
          } else if (rtu_Gear_Lever_Position == 3.0) {
            localDW->is_Selection = TCU_Final_IN_neutral;
            localDW->D = 0.0;
          } else {
            *rty_Shift_Solenoid_Park = false;
            *rty_Shift_Solenoid_Reverse = false;
            *rty_Shift_Solenoid_Neutral = false;
            localDW->D = 1.0;
          }
          break;

         case TCU_Final_IN_neutral:
          if (rtu_Gear_Lever_Position == 4.0) {
            localDW->is_Selection = TCU_Final_IN_drive;
          } else if (rtu_Gear_Lever_Position == 2.0) {
            localDW->is_Selection = TCU_Final_IN_reverse;
            localDW->D = 0.0;
          } else {
            *rty_Shift_Solenoid_Park = false;
            *rty_Shift_Solenoid_Reverse = false;
            *rty_Shift_Solenoid_Neutral = true;
            *rty_Shift_Solenoid_A = false;
            *rty_Shift_Solenoid_B = false;
            *rty_Shift_Solenoid_C = false;
            *rty_Shift_Solenoid_D = false;
          }
          break;

         case TCU_Final_IN_parking:
          if ((rtu_Gear_Lever_Position >= 2.0) && rtu_Brake_Pedal_Switch) {
            localDW->is_Selection = TCU_Final_IN_reverse;
            localDW->D = 0.0;
          } else {
            *rty_Shift_Solenoid_Park = true;
            *rty_Shift_Solenoid_Reverse = false;
            *rty_Shift_Solenoid_Neutral = false;
            *rty_Shift_Solenoid_A = false;
            *rty_Shift_Solenoid_B = false;
            *rty_Shift_Solenoid_C = false;
            *rty_Shift_Solenoid_D = false;
          }
          break;

         case TCU_Final_IN_primera:
          if (rtu_Gear_Lever_Position == 6.0) {
            localDW->is_Selection = TCU_Final_IN_segunda;
          } else if (rtu_Gear_Lever_Position == 4.0) {
            localDW->is_Selection = TCU_Final_IN_drive;
          } else {
            *rty_Shift_Solenoid_Park = false;
            *rty_Shift_Solenoid_Reverse = false;
            *rty_Shift_Solenoid_Neutral = false;
            localDW->D = 1.0;
          }
          break;

         case TCU_Final_IN_reverse:
          if (rtu_Gear_Lever_Position == 3.0) {
            localDW->is_Selection = TCU_Final_IN_neutral;
            localDW->D = 0.0;
          } else if ((rtu_Gear_Lever_Position == 1.0) && rtu_Brake_Pedal_Switch)
          {
            localDW->is_Selection = TCU_Final_IN_parking;
            localDW->D = 0.0;
          } else {
            *rty_Shift_Solenoid_Park = false;
            *rty_Shift_Solenoid_Reverse = true;
            *rty_Shift_Solenoid_Neutral = false;
            *rty_Shift_Solenoid_A = false;
            *rty_Shift_Solenoid_B = false;
            *rty_Shift_Solenoid_C = false;
            *rty_Shift_Solenoid_D = false;
          }
          break;

         case TCU_Final_IN_segunda:
          if (rtu_Gear_Lever_Position == 7.0) {
            localDW->is_Selection = TCU_Final_IN_tercera;
          } else if (rtu_Gear_Lever_Position == 5.0) {
            localDW->is_Selection = TCU_Final_IN_primera;
          } else {
            *rty_Shift_Solenoid_Park = false;
            *rty_Shift_Solenoid_Reverse = false;
            *rty_Shift_Solenoid_Neutral = false;
            localDW->D = 1.0;
          }
          break;

         default:
          /* case IN_tercera: */
          if (rtu_Gear_Lever_Position == 6.0) {
            localDW->is_Selection = TCU_Final_IN_segunda;
          } else {
            *rty_Shift_Solenoid_Park = false;
            *rty_Shift_Solenoid_Reverse = false;
            *rty_Shift_Solenoid_Neutral = false;
            localDW->D = 1.0;
          }
          break;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Gear_Selection' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
