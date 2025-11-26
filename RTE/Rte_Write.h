/*
 * Rte_Write.h
 *
 *  Created on: Nov 24, 2025
 *      Author: joshu
 */

#ifndef RTE_WRITE_H_
#define RTE_WRITE_H_

#include "Global_Signals.h"
#include "Set_Signals.h"



// ECU → TCU
void Write_CAN_EngineRPM(uint16 value);
void Write_CAN_EngineTorqueActual(sint16 value);
void Write_CAN_EngineCoolantTemp(sint16 value);
void Write_CAN_ThrottlePosition(uint8 value);

// ABS → TCU
void Write_CAN_VehicleSpeedRef(uint16 value);

// BCM / Switch Panel
void Write_CAN_DriverModeSelection(uint8 value);

// DIRECT INPUT SIGNALS
void Write_IO_BrakeLightSwitch(uint8 value);
void Write_IO_Gear_Lever_Position(uint8 value);

// INTERNAL TRANSMISSION SENSORS
void Write_TCM_TurbineSpeed_TSS(uint16 value);
void Write_TCM_OutputSpeed_OSS(uint16 value);
void Write_TCM_FluidTemp_TFT(sint16 value);

// CAN OUTPUT SIGNALS
void Write_CAN_TorqueReductionRequest(uint8 value);
void Write_CAN_SelectedGear(uint8 value);

// SOLENOID CONTROL OUTPUTS
void Write_PWM_LinePressure(uint16 value);
void Write_PWM_TCC(uint16 value);
void Write_SOL_ClutchA(uint8 value);
void Write_SOL_ClutchB(uint8 value);
void Write_SOL_ClutchC(uint8 value);
void Write_SOL_ClutchD(uint8 value);
void Write_SOL_ShiftLock(uint8 value);

// INTERNAL LOGIC OUTPUTS
void Write_TCM_CurrentGear(uint8 value);
void Write_TCM_TargetGear(uint8 value);
void Write_TCM_ShiftInProgress(uint8 value);
void Write_TCM_ShiftQualityIndex(uint8 value);






#endif /* RTE_WRITE_H_ */


