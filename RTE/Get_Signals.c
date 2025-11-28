/*
 * Get_Signals.c
 *
 *  Created on: Nov 24, 2025
 *      Author: joshu
 */

#include "Get_Signals.h"

// ============================================================================
// GET FUNCTIONS (USING POINTER ARGUMENT)
// ============================================================================

// ECU → TCU
void Get_CAN_EngineRPM(uint32 *value) { *value = g_CAN_EngineRPM; }
void Get_CAN_EngineTorqueActual(sint32 *value) { *value = g_CAN_EngineTorqueActual; }
void Get_CAN_EngineCoolantTemp(sint32 *value) { *value = g_CAN_EngineCoolantTemp; }
void Get_CAN_ThrottlePosition(uint32 *value) { *value = g_CAN_ThrottlePosition; }

// ABS → TCU
void Get_CAN_VehicleSpeedRef(uint32 *value) { *value = g_CAN_VehicleSpeedRef; }

// BCM / Switch Panel
void Get_CAN_DriverModeSelection(uint32 *value) { *value = g_CAN_DriverModeSelection; }


// =====================
// DIRECT INPUT SIGNALS
// =====================
void Get_IO_BrakeLightSwitch(uint32 *value) { *value = g_IO_BrakeLightSwitch; }
void Get_IO_Gear_Lever_Position(uint32 *value) { *value = g_IO_Gear_Lever_Position; }


// =====================
// INTERNAL TRANSMISSION SENSORS
// =====================
void Get_TCM_TurbineSpeed_TSS(uint32 *value) { *value = g_TCM_TurbineSpeed_TSS; }
void Get_TCM_OutputSpeed_OSS(uint32 *value) { *value = g_TCM_OutputSpeed_OSS; }
void Get_TCM_FluidTemp_TFT(sint32 *value) { *value = g_TCM_FluidTemp_TFT; }


// ============================================================================
// CAN OUTPUT SIGNALS
// ============================================================================
void Get_CAN_TorqueReductionRequest(uint32 *value) { *value = g_CAN_TorqueReductionRequest; }
void Get_CAN_SelectedGear(uint32 *value) { *value = g_CAN_SelectedGear; }


// ============================================================================
// SOLENOID CONTROL OUTPUTS (PWM / DIGITAL)
// ============================================================================
void Get_PWM_LinePressure(uint32 *value) { *value = g_PWM_LinePressure; }
void Get_PWM_TCC(uint32 *value) { *value = g_PWM_TCC; }

void Get_SOL_ClutchParking(uint32 *value){ *value = g_SOL_ClutchParking; }
void Get_SOL_ClutchReverse(uint32 *value){ *value = g_SOL_ClutchReverse; }
void Get_SOL_ClutchNeutral(uint32 *value){ *value = g_SOL_ClutchNeutral; }

void Get_SOL_ClutchA(uint32 *value) { *value = g_SOL_ClutchA; }
void Get_SOL_ClutchB(uint32 *value) { *value = g_SOL_ClutchB; }
void Get_SOL_ClutchC(uint32 *value) { *value = g_SOL_ClutchC; }
void Get_SOL_ClutchD(uint32 *value) { *value = g_SOL_ClutchD; }
void Get_SOL_ShiftLock(uint32 *value) { *value = g_SOL_ShiftLock; }


// ============================================================================
// INTERNAL LOGIC OUTPUTS
// ============================================================================
void Get_TCM_CurrentGear(uint32 *value) { *value = g_TCM_CurrentGear; }
void Get_TCM_TargetGear(uint32 *value) { *value = g_TCM_TargetGear; }
void Get_TCM_ShiftInProgress(uint32 *value) { *value = g_TCM_ShiftInProgress; }
void Get_TCM_ShiftQualityIndex(uint32 *value) { *value = g_TCM_ShiftQualityIndex; }

