/*
 * Rte_Write.c
 *
 *  Created on: Nov 24, 2025
 *      Author: joshu
 */

#include "Rte_Write.h"

// ECU → TCU
void Write_CAN_EngineRPM(uint16 value)
{
    Set_CAN_EngineRPM(value);
}

void Write_CAN_EngineTorqueActual(sint16 value)
{
    Set_CAN_EngineTorqueActual(value);
}

void Write_CAN_EngineCoolantTemp(sint16 value)
{
    Set_CAN_EngineCoolantTemp(value);
}

void Write_CAN_ThrottlePosition(uint8 value)
{
    Set_CAN_ThrottlePosition(value);
}


// ABS → TCU
void Write_CAN_VehicleSpeedRef(uint16 value)
{
    Set_CAN_VehicleSpeedRef(value);
}


// BCM / Switch Panel
void Write_CAN_DriverModeSelection(uint8 value)
{
    Set_CAN_DriverModeSelection(value);
}


// =====================
// DIRECT INPUT SIGNALS
// =====================
void Write_IO_BrakeLightSwitch(uint8 value)
{
    Set_IO_BrakeLightSwitch(value);
}

void Write_IO_Gear_Lever_Position(uint8 value)
{
    Set_IO_Gear_Lever_Position(value);
}


// =====================
// INTERNAL TRANSMISSION SENSORS
// =====================
void Write_TCM_TurbineSpeed_TSS(uint16 value)
{
    Set_TCM_TurbineSpeed_TSS(value);
}

void Write_TCM_OutputSpeed_OSS(uint16 value)
{
    Set_TCM_OutputSpeed_OSS(value);
}

void Write_TCM_FluidTemp_TFT(sint16 value)
{
    Set_TCM_FluidTemp_TFT(value);
}


// ============================================================================
// CAN OUTPUT SIGNALS
// ============================================================================
void Write_CAN_TorqueReductionRequest(uint8 value)
{
    Set_CAN_TorqueReductionRequest(value);
}

void Write_CAN_SelectedGear(uint8 value)
{
    Set_CAN_SelectedGear(value);
}


// ============================================================================
// SOLENOID CONTROL OUTPUTS
// ============================================================================
void Write_PWM_LinePressure(uint16 value)
{
    Set_PWM_LinePressure(value);
}

void Write_PWM_TCC(uint16 value)
{
    Set_PWM_TCC(value);
}

void Write_SOL_ClutchA(uint8 value)
{
    Set_SOL_ClutchA(value);
}

void Write_SOL_ClutchB(uint8 value)
{
    Set_SOL_ClutchB(value);
}

void Write_SOL_ClutchC(uint8 value)
{
    Set_SOL_ClutchC(value);
}

void Write_SOL_ClutchD(uint8 value)
{
    Set_SOL_ClutchD(value);
}

void Write_SOL_ShiftLock(uint8 value)
{
    Set_SOL_ShiftLock(value);
}


// ============================================================================
// INTERNAL LOGIC OUTPUTS
// ============================================================================
void Write_TCM_CurrentGear(uint8 value)
{
    Set_TCM_CurrentGear(value);
}

void Write_TCM_TargetGear(uint8 value)
{
    Set_TCM_TargetGear(value);
}

void Write_TCM_ShiftInProgress(uint8 value)
{
    Set_TCM_ShiftInProgress(value);
}

void Write_TCM_ShiftQualityIndex(uint8 value)
{
    Set_TCM_ShiftQualityIndex(value);
}
