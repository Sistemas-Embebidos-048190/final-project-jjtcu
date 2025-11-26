/*
 * Rte_Read.h
 *
 *  Created on: Nov 24, 2025
 *      Author: joshu
 */

#ifndef RTE_READ_H_
#define RTE_READ_H_

#include "Global_Signals.h"
#include "Get_Signals.h"



// ECU → TCU
void Read_CAN_EngineRPM(uint16 *value);
void Read_CAN_EngineTorqueActual(sint16 *value);
void Read_CAN_EngineCoolantTemp(sint16 *value);
void Read_CAN_ThrottlePosition(uint8 *value);

// ABS → TCU
void Read_CAN_VehicleSpeedRef(uint16 *value);

// BCM / Switch Panel
void Read_CAN_DriverModeSelection(uint8 *value);

// DIRECT INPUT SIGNALS
void Read_IO_BrakeLightSwitch(uint8 *value);
void Read_IO_Gear_Lever_Position(uint8 *value);

// INTERNAL TRANSMISSION SENSORS
void Read_TCM_TurbineSpeed_TSS(uint16 *value);
void Read_TCM_OutputSpeed_OSS(uint16 *value);
void Read_TCM_FluidTemp_TFT(sint16 *value);

// CAN OUTPUT SIGNALS
void Read_CAN_TorqueReductionRequest(uint8 *value);
void Read_CAN_SelectedGear(uint8 *value);

// SOLENOID CONTROL OUTPUTS (PWM / DIGITAL)
void Read_PWM_LinePressure(uint16 *value);
void Read_PWM_TCC(uint16 *value);
void Read_SOL_ClutchA(uint8 *value);
void Read_SOL_ClutchB(uint8 *value);
void Read_SOL_ClutchC(uint8 *value);
void Read_SOL_ClutchD(uint8 *value);
void Read_SOL_ShiftLock(uint8 *value);

// INTERNAL LOGIC OUTPUTS
void Read_TCM_CurrentGear(uint8 *value);
void Read_TCM_TargetGear(uint8 *value);
void Read_TCM_ShiftInProgress(uint8 *value);
void Read_TCM_ShiftQualityIndex(uint8 *value);



#endif /* RTE_READ_H_ */
