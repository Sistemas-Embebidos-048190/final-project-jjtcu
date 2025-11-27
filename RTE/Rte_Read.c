/*
 * Rte_Read.c
 *
 *  Created on: Nov 24, 2025
 *      Author: joshu
 */

#include "Rte_Read.h"



// ============================================================================
// ECU → TCU
// ============================================================================
void Read_CAN_EngineRPM(uint16 *value)
{
    Get_CAN_EngineRPM(value);
}

void Read_CAN_EngineTorqueActual(sint16 *value)
{
    Get_CAN_EngineTorqueActual(value);
}

void Read_CAN_EngineCoolantTemp(sint16 *value)
{
    Get_CAN_EngineCoolantTemp(value);
}

void Read_CAN_ThrottlePosition(uint8 *value)
{
    Get_CAN_ThrottlePosition(value);
}


// ============================================================================
// ABS → TCU
// ============================================================================
void Read_CAN_VehicleSpeedRef(uint16 *value)
{
    Get_CAN_VehicleSpeedRef(value);
}


// ============================================================================
// BCM / Switch Panel
// ============================================================================
void Read_CAN_DriverModeSelection(uint8 *value)
{
    Get_CAN_DriverModeSelection(value);
}


// ============================================================================
// DIRECT INPUT SIGNALS
// ============================================================================
void Read_IO_BrakeLightSwitch(uint8 *value)
{
    Get_IO_BrakeLightSwitch(value);
}

void Read_IO_Gear_Lever_Position(uint8 *value)
{
    Get_IO_Gear_Lever_Position(value);
}


// ============================================================================
// INTERNAL TRANSMISSION SENSORS
// ============================================================================
void Read_TCM_TurbineSpeed_TSS(uint16 *value)
{
    Get_TCM_TurbineSpeed_TSS(value);
}

void Read_TCM_OutputSpeed_OSS(uint16 *value)
{
    Get_TCM_OutputSpeed_OSS(value);
}

void Read_TCM_FluidTemp_TFT(sint16 *value)
{
    Get_TCM_FluidTemp_TFT(value);
}


// ============================================================================
// CAN OUTPUT SIGNALS
// ============================================================================
void Read_CAN_TorqueReductionRequest(uint8 *value)
{
    Get_CAN_TorqueReductionRequest(value);
}

void Read_CAN_SelectedGear(uint8 *value)
{
    Get_CAN_SelectedGear(value);
}


// ============================================================================
// SOLENOID CONTROL OUTPUTS (PWM / DIGITAL)
// ============================================================================
void Read_PWM_LinePressure(uint16 *value)
{
    Get_PWM_LinePressure(value);
}

void Read_PWM_TCC(uint16 *value)
{
    Get_PWM_TCC(value);
}

void Read_SOL_ClutchA(uint8 *value)
{
    Get_SOL_ClutchA(value);
}

void Read_SOL_ClutchB(uint8 *value)
{
    Get_SOL_ClutchB(value);
}

void Read_SOL_ClutchC(uint8 *value)
{
    Get_SOL_ClutchC(value);
}

void Read_SOL_ClutchD(uint8 *value)
{
    Get_SOL_ClutchD(value);
}

void Read_SOL_ShiftLock(uint8 *value)
{
    Get_SOL_ShiftLock(value);
}


// ============================================================================
// INTERNAL LOGIC OUTPUTS
// ============================================================================
void Read_TCM_CurrentGear(uint8 *value)
{
    Get_TCM_CurrentGear(value);
}

void Read_TCM_TargetGear(uint8 *value)
{
    Get_TCM_TargetGear(value);
}

void Read_TCM_ShiftInProgress(uint8 *value)
{
    Get_TCM_ShiftInProgress(value);
}

void Read_TCM_ShiftQualityIndex(uint8 *value)
{
    Get_TCM_ShiftQualityIndex(value);
}


