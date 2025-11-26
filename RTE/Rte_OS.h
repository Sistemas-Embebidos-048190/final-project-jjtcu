#ifndef RTE_OS_H
#define RTE_OS_H

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

#include "fsl_common.h"
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "app.h"

#include "Platform_Types.h"

#include "IoHwAb_gpio.h"


// Init_Task
void Rte_Init_Task(void);





#endif /* RTE_OS_H */
