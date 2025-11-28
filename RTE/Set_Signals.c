/*
 * Set_Signals.c
 *
 *  Created on: Nov 24, 2025
 *      Author: joshu
 */

#include "Set_Signals.h"

// ============================================================================
// SET FUNCTIONS ONLY
// ============================================================================

// ECU → TCU
void Set_CAN_EngineRPM(uint32 value) {

	g_CAN_EngineRPM = value; }

void Set_CAN_EngineTorqueActual(sint32 value) {

	g_CAN_EngineTorqueActual = value; }

void Set_CAN_EngineCoolantTemp(sint32 value) {

	g_CAN_EngineCoolantTemp = value; }

void Set_CAN_ThrottlePosition(uint32 value) {

	g_CAN_ThrottlePosition = value; }


// ABS → TCU
void Set_CAN_VehicleSpeedRef(uint32 value) {

	g_CAN_VehicleSpeedRef = value; }

// BCM / Switch Panel
void Set_CAN_DriverModeSelection(uint32 value) {

	g_CAN_DriverModeSelection = value; }


// =====================
// DIRECT INPUT SIGNALS
// =====================
void Set_IO_BrakeLightSwitch(uint32 value) {

	g_IO_BrakeLightSwitch = value; }

void Set_IO_Gear_Lever_Position(uint32 value) {

	g_IO_Gear_Lever_Position = value; }


// =====================
// INTERNAL TRANSMISSION SENSORS
// =====================
void Set_TCM_TurbineSpeed_TSS(uint32 value) {

	g_TCM_TurbineSpeed_TSS = value; }

void Set_TCM_OutputSpeed_OSS(uint32 value) {

	g_TCM_OutputSpeed_OSS = value; }

void Set_TCM_FluidTemp_TFT(sint32 value) {

	g_TCM_FluidTemp_TFT = value; }


// ============================================================================
// CAN OUTPUT SIGNALS
// ============================================================================
void Set_CAN_TorqueReductionRequest(uint32 value) {

	g_CAN_TorqueReductionRequest = value; }

void Set_CAN_SelectedGear(uint32 value) {

	g_CAN_SelectedGear = value; }


// ============================================================================
// SOLENOID CONTROL OUTPUTS
// ============================================================================
void Set_PWM_LinePressure(uint32 value)

{ g_PWM_LinePressure = value; }

void Set_PWM_TCC(uint32 value) {

	g_PWM_TCC = value; }

void Set_SOL_ClutchParking(uint32 value){

	g_SOL_ClutchParking = value; }

void Set_SOL_ClutchNeutral(uint32 value){

	g_SOL_ClutchNeutral = value; }

void Set_SOL_ClutchReverse(uint32 value){

	g_SOL_ClutchReverse = value; }

void Set_SOL_ClutchA(uint32 value) {

	g_SOL_ClutchA = value; }

void Set_SOL_ClutchB(uint32 value) {

	g_SOL_ClutchB = value; }

void Set_SOL_ClutchC(uint32 value) {

	g_SOL_ClutchC = value; }

void Set_SOL_ClutchD(uint32 value) {

	g_SOL_ClutchD = value; }

void Set_SOL_ShiftLock(uint32 value) {

	g_SOL_ShiftLock = value; }


// ============================================================================
// INTERNAL LOGIC OUTPUTS
// ============================================================================
void Set_TCM_CurrentGear(uint32 value) {

	g_TCM_CurrentGear = value; }

void Set_TCM_TargetGear(uint32 value) {

	g_TCM_TargetGear = value; }

void Set_TCM_ShiftInProgress(uint32 value) {

	g_TCM_ShiftInProgress = value; }

void Set_TCM_ShiftQualityIndex(uint32 value) {

	g_TCM_ShiftQualityIndex = value; }


