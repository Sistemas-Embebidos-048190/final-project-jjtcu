/*
 * Set_Signals.h
 *
 *  Created on: Nov 24, 2025
 *      Author: joshu
 */

#ifndef SET_SIGNALS_H_
#define SET_SIGNALS_H_

#include "Platform_Types.h"
#include "Global_Signals.h"

// ECU → TCU
void Set_CAN_EngineRPM(uint16 value);
void Set_CAN_EngineTorqueActual(sint16 value);
void Set_CAN_EngineCoolantTemp(sint16 value);
void Set_CAN_ThrottlePosition(uint8 value);

// ABS → TCU
void Set_CAN_VehicleSpeedRef(uint16 value);

// BCM / Switch Panel
void Set_CAN_DriverModeSelection(uint8 value);


// =====================
// DIRECT INPUT SIGNALS
// =====================
void Set_IO_BrakeLightSwitch(uint8 value);
void Set_IO_Gear_Lever_Position(uint8 value);


// =====================
// INTERNAL TRANSMISSION SENSORS
// =====================
void Set_TCM_TurbineSpeed_TSS(uint16 value);
void Set_TCM_OutputSpeed_OSS(uint16 value);
void Set_TCM_FluidTemp_TFT(sint16 value);


// ============================================================================
// CAN OUTPUT SIGNALS
// ============================================================================
void Set_CAN_TorqueReductionRequest(uint8 value);
void Set_CAN_SelectedGear(uint8 value);


// ============================================================================
// SOLENOID CONTROL OUTPUTS (PWM / DIGITAL)
// ============================================================================
void Set_PWM_LinePressure(uint16 value);
void Set_PWM_TCC(uint16 value);

void Set_SOL_ClutchA(uint8 value);
void Set_SOL_ClutchB(uint8 value);
void Set_SOL_ClutchC(uint8 value);
void Set_SOL_ClutchD(uint8 value);
void Set_SOL_ShiftLock(uint8 value);


// ============================================================================
// INTERNAL LOGIC OUTPUTS
// ============================================================================
void Set_TCM_CurrentGear(uint8 value);
void Set_TCM_TargetGear(uint8 value);
void Set_TCM_ShiftInProgress(uint8 value);
void Set_TCM_ShiftQualityIndex(uint8 value);



#endif /* SET_SIGNALS_H_ */
