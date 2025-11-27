/*
 * Get_Signals.h
 *
 *  Created on: Nov 24, 2025
 *      Author: joshu
 */

#ifndef GET_SIGNALS_H_
#define GET_SIGNALS_H_

#include "Platform_Types.h"
#include "Global_Signals.h"

// ============================================================================
// GET FUNCTION PROTOTYPES (USING POINTER ARGUMENT)
// ============================================================================

// ECU → TCU
void Get_CAN_EngineRPM(uint16 *value);
void Get_CAN_EngineTorqueActual(sint16 *value);
void Get_CAN_EngineCoolantTemp(sint16 *value);
void Get_CAN_ThrottlePosition(uint8 *value);

// ABS → TCU
void Get_CAN_VehicleSpeedRef(uint16 *value);

// BCM / Switch Panel
void Get_CAN_DriverModeSelection(uint8 *value);


// =====================
// DIRECT INPUT SIGNALS
// =====================
void Get_IO_BrakeLightSwitch(uint8 *value);
void Get_IO_Gear_Lever_Position(uint8 *value);


// =====================
// INTERNAL TRANSMISSION SENSORS
// =====================
void Get_TCM_TurbineSpeed_TSS(uint16 *value);
void Get_TCM_OutputSpeed_OSS(uint16 *value);
void Get_TCM_FluidTemp_TFT(sint16 *value);


// ============================================================================
// CAN OUTPUT SIGNALS
// ============================================================================
void Get_CAN_TorqueReductionRequest(uint8 *value);
void Get_CAN_SelectedGear(uint8 *value);


// ============================================================================
// SOLENOID CONTROL OUTPUTS (PWM / DIGITAL)
// ============================================================================
void Get_PWM_LinePressure(uint16 *value);
void Get_PWM_TCC(uint16 *value);

void Get_SOL_ClutchA(uint8 *value);
void Get_SOL_ClutchB(uint8 *value);
void Get_SOL_ClutchC(uint8 *value);
void Get_SOL_ClutchD(uint8 *value);
void Get_SOL_ShiftLock(uint8 *value);


// ============================================================================
// INTERNAL LOGIC OUTPUTS
// ============================================================================
void Get_TCM_CurrentGear(uint8 *value);
void Get_TCM_TargetGear(uint8 *value);
void Get_TCM_ShiftInProgress(uint8 *value);
void Get_TCM_ShiftQualityIndex(uint8 *value);


#endif /* GET_SIGNALS_H_ */
