/*
 * Global_Signals.c
 *
 *  Created on: Nov 24, 2025
 *      Author: joshu
 */

#include "Global_Signals.h"

// ============================================================================
// TCU SIGNAL LIST (Inputs & Outputs)
// ============================================================================

// =====================
// CAN INPUT SIGNALS
// =====================

// ECU → TCU
uint16 g_CAN_EngineRPM;               // Engine_RPM
sint16  g_CAN_EngineTorqueActual;      // Engine_Torque_Actual (puede ser negativo)
sint16  g_CAN_EngineCoolantTemp;       // Engine_Coolant_Temp
uint8  g_CAN_ThrottlePosition;        // Throttle_Position_Sensor (0-100%)
//uint8  g_CAN_EngineLoad;              // Engine_Load (0-100%)

// ABS → TCU
uint16 g_CAN_VehicleSpeedRef;        // Vehicle_Speed_Reference

// BCM / Switch Panel
uint8 g_CAN_DriverModeSelection;      // Driver_Mode_Selection (0=Eco,1=Sport)


// =====================
// DIRECT INPUT SIGNALS
// =====================
uint8  g_IO_BrakeLightSwitch;         // Brake Light Switch (0/1)
uint8  g_IO_Gear_Lever_Position;

// =====================
// INTERNAL TRANSMISSION SENSORS
// =====================
uint16 g_TCM_TurbineSpeed_TSS;       // Turbine/Input Speed Sensor
uint16 g_TCM_OutputSpeed_OSS;        // Output Speed Sensor
sint16 g_TCM_FluidTemp_TFT;          // Transmission Fluid Temperature


// ============================================================================
// TCU OUTPUT SIGNALS
// ============================================================================

// =====================
// CAN OUTPUT SIGNALS
// =====================
uint8  g_CAN_TorqueReductionRequest;  // Torque_Reduction_Request
uint8  g_CAN_SelectedGear;            // Marcha mostrada en cluster (P,R,N,D,1-6)



// =====================
// SOLENOID CONTROL OUTPUTS (PWM / DIGITAL)
// =====================
uint16 g_PWM_LinePressure;           // Solenoide presión de línea
uint16 g_PWM_TCC;                    // Solenoide Torque Converter Clutch (TCC)
uint8 g_SOL_ClutchA;                 // Solenoide embrague A (on-coming/off-going)
uint8 g_SOL_ClutchB;                 // Solenoide embrague B
uint8 g_SOL_ClutchC;                 // Solenoide embrague C
uint8 g_SOL_ClutchD;                 // Solenoide embrague D
uint8 g_SOL_ShiftLock;               // solenoide de bloqueo


// =====================
// INTERNAL LOGIC OUTPUTS
// =====================
uint8  g_TCM_CurrentGear;             // Gear_Selection_State (1-6, P,R,N,D)
uint8  g_TCM_TargetGear;              // Gear solicitado por mapa
uint8  g_TCM_ShiftInProgress;         // Estado de transición (0/1)
uint8  g_TCM_ShiftQualityIndex;       // Parámetro interno de suavidad del cambio (+/-1)

