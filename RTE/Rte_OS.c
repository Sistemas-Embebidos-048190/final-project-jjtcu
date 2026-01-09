
#include "Rte_OS.h"
#include "TCU_Final.h"
#include "Comm_can.h"
#include "IoHwAb_pwm.h"


/* Task priorities. */
#define Comm_Tx_Task_PRIORITY (configMAX_PRIORITIES - 1)
#define Comm_Rx_Task_PRIORITY (configMAX_PRIORITIES - 1)
#define TCM_logic_Task_PRIORITY (configMAX_PRIORITIES - 1)
#define TCM_task_PRIORITY (configMAX_PRIORITIES - 1)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void Comm_Tx_Task(void *pvParameters);
static void Comm_Rx_Task(void *pvParameters);
static void TCM_logic_Task(void *pvParameters);
static void TCM_task(void *pvParameters);


// INIT_TASK

void Rte_Init_Task(void){

		// CREACION DE Comm_Tx_Task

	if (xTaskCreate(Comm_Tx_Task, "Comm_Tx_Task", configMINIMAL_STACK_SIZE + 100, NULL, Comm_Tx_Task_PRIORITY, NULL) != pdPASS)
		{
			PRINTF("Task creation failed!.\r\n");
			while (1);


		// CREACION DE Comm_Rx_Task
		}
	if (xTaskCreate(Comm_Rx_Task, "Comm_Rx_Task", configMINIMAL_STACK_SIZE + 100, NULL, Comm_Rx_Task_PRIORITY, NULL) != pdPASS)
		{
			PRINTF("Task creation failed!.\r\n");
			while (1);

		}


	if (xTaskCreate(TCM_logic_Task, "TCM_logic_Task", configMINIMAL_STACK_SIZE + 100, NULL, TCM_logic_Task_PRIORITY, NULL) != pdPASS)
		{



			PRINTF("Task creation failed!.\r\n");
			while (1);

		}
	if (xTaskCreate(TCM_task, "TCM_task", configMINIMAL_STACK_SIZE + 100, NULL, TCM_task_PRIORITY, NULL) != pdPASS)
		{
			PRINTF("Task creation failed!.\r\n");
			while (1);

		}


		vTaskStartScheduler();
		for (;;);

}

static void Comm_Tx_Task(void *pvParameters)
{
    for (;;)
    {

    	LinePressure_SetDuty();
    	vTaskDelay(pdMS_TO_TICKS(100));

    }
}

static void Comm_Rx_Task(void *pvParameters){
	for (;;)
	{

		Can_Update();


	}

}


static void TCM_logic_Task(void *pvParameters){

	for (;;)
	{
		// CONEXIONES
		TCU_Final_U.Ignition = 2;
		uint32 GearLevel_Temp = 0;
		Read_IO_Gear_Lever_Position( &GearLevel_Temp);
		TCU_Final_U.Gear_Level_Position = (real_T)GearLevel_Temp;

		uint32 RPM_Temp = 0;
		Read_CAN_EngineRPM(&RPM_Temp);
		TCU_Final_U.Engine_RPM = (real_T)RPM_Temp;

		uint32 Speed_Temp = 0;
		Read_CAN_VehicleSpeedRef( &Speed_Temp );
		TCU_Final_U.Vehicle_Speed_Reference = (real_T)Speed_Temp;

		uint32 Throttle_Temp = 0;
		Read_CAN_ThrottlePosition( &Throttle_Temp);
		TCU_Final_U.Throttle_Position_Sensor = (real_T)Throttle_Temp;

		Read_IO_BrakeLightSwitch( (uint32*)&TCU_Final_U.Brake_Pedal_Switch);
		Read_CAN_DriverModeSelection( (uint32*)&TCU_Final_U.Driver_Mode_Selection);

		sint32 Temp_Temp =0;
		Read_TCM_FluidTemp_TFT( &Temp_Temp);
		TCU_Final_U.Transmission_Fluid_Temp = (real_T)Temp_Temp;

		sint32 Torque_Temp = 0;
		Read_CAN_EngineTorqueActual( &Torque_Temp);
		TCU_Final_U.Engine_Torque_Actual = (real_T)Torque_Temp;

		uint32 OSS_Temp =0;
		Read_TCM_OutputSpeed_OSS( &OSS_Temp);
		TCU_Final_U.Output_Speed_Sensor = (real_T)OSS_Temp;

		Write_SOL_ClutchParking( TCU_Final_Y.Shift_Solenoid_Park);
		Write_SOL_ClutchReverse( TCU_Final_Y.Shift_Solenoid_Reverse);
		Write_SOL_ClutchNeutral( TCU_Final_Y.Shift_Solenoid_Neutral);
		Write_SOL_ClutchA( TCU_Final_Y.Shift_Solenoid_A);
		Write_SOL_ClutchB( TCU_Final_Y.Shift_Solenoid_B);
		Write_SOL_ClutchC( TCU_Final_Y.Shift_Solenoid_C);
		Write_SOL_ClutchD( TCU_Final_Y.Shift_Solenoid_D);
		Write_CAN_TorqueReductionRequest( TCU_Final_Y.Torque_Reduction_Request);
		Write_PWM_LinePressure( TCU_Final_Y.Line_Pressure_Control_Solenoid);
		Write_PWM_TCC( (TCU_Final_Y.TCC_Control_Solenoid)*2);

		TCU_Final_step();

    	vTaskDelay(pdMS_TO_TICKS(100));

	}


}


static void TCM_task(void *pvParameters){

	for (;;)
	{


		Update_Pin_Values();

    	vTaskDelay(pdMS_TO_TICKS(100));

	}


}





























