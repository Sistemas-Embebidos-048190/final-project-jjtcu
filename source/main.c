/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "app.h"

#include "Platform_Types.h"
#include "IoHwAb_gpio.h"
#include "IoHwAb_adc.h"
#include "IoHwAb_pwm.h"
#include "Rte_OS.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Application entry point.
 */
int main(void)
{
    /* Init board hardware. */
    BOARD_InitHardware();
	Init_Gear_Selection_Pins();
	Init_Brake_Pedal_Pins();
	Init_Shifter_Output_Pins();
	Init_ADC_Pins();
	TCM_LPADC_InitSensors();

	Pin_init_PWM();

	Rte_Init_Task();
	while(1){

		Gear_Selection_GetPosition();
		Brake_Pedal_Read();



//		g_PWM_LinePressure = 30;
//		g_PWM_TCC = 20;
//
//		LinePressure_SetDuty();
//		TCCPressure_SetDuty();


		TCM_Read_OutputSpeedSensor();
		TCM_Read_FluidTempSensor();
		TCM_Read_TurbineSpeedSensor();

		/*if(g_IO_Gear_Lever_Position==1){
			g_SOL_ShiftLock = 1;
			Set_Shift_Lock_Sol();}
		else{
			g_SOL_ShiftLock = 0;
			Set_Shift_Lock_Sol();}

		if(g_IO_Gear_Lever_Position==2){
			g_SOL_ClutchA = 1;
			Set_Shift_Sol_A();}
		else{
			g_SOL_ClutchA = 0;
			Set_Shift_Sol_A();}

		if(g_IO_Gear_Lever_Position==3){
			g_SOL_ClutchB = 1;
			Set_Shift_Sol_B();}
		else{
			g_SOL_ClutchB = 0;
			Set_Shift_Sol_B();}


		if(g_IO_Gear_Lever_Position==4){
			g_SOL_ClutchC = 1;
			Set_Shift_Sol_C();}
		else{
			g_SOL_ClutchC = 0;
			Set_Shift_Sol_C();}


		if(g_IO_Gear_Lever_Position==5){
			g_SOL_ClutchD = 1;
			Set_Shift_Sol_D();}
		else{
			g_SOL_ClutchD = 0;
			Set_Shift_Sol_D();}*/
	}

}

/*!
 * @brief Task responsible for printing of "Hello world." message.
 */

