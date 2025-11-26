
#include "Rte_OS.h"

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




    }
}

static void Comm_Rx_Task(void *pvParameters){
	for (;;)
	{

		uint8 comm_rx=1;

	}

}


static void TCM_logic_Task(void *pvParameters){

	for (;;)
	{

		uint8 TCM_Log=1;

	}


}


static void TCM_task(void *pvParameters){

	for (;;)
	{

		uint8 TCM=1;

	}


}





























