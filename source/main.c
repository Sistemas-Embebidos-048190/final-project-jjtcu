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


	Init_All_Pins();
//	Pin_init_PWM();
	Rte_Init_Task();
	while(1){
//		g_PWM_LinePressure = 4.5;
//		g_PWM_TCC = 4.5;
//		LinePressure_SetDuty();
//		TCCPressure_SetDuty();
//		g_PWM_LinePressure = 5;
//		g_PWM_TCC = 5;
//		LinePressure_SetDuty();
//		TCCPressure_SetDuty();
//		g_PWM_LinePressure = 12;
//		g_PWM_TCC = 12;
//		LinePressure_SetDuty();
//		TCCPressure_SetDuty();
//		g_PWM_LinePressure = 12.5;
//		g_PWM_TCC = 12.5;
//		LinePressure_SetDuty();
//		TCCPressure_SetDuty();
	}

}

/*!
 * @brief Task responsible for printing of "Hello world." message.
 */

