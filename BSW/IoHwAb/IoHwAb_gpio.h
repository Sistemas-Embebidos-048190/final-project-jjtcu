#ifndef IOHWAB_GPIO_H
#define IOHWAB_GPIO_H

#include "app.h"
#include "fsl_port.h"
#include "board.h"
#include "fsl_common.h"
#include "fsl_port.h"
#include "Platform_Types.h"
#include "Global_Signals.h"

#include "Rte_Write.h"
#include "Rte_Read.h"

// GEAR SELECTION
void Init_Gear_Selection_Pins(void);
gear_selector_t Gear_Selection_GetPosition(void);

// BRAKE PEDAL
void Init_Brake_Pedal_Pins(void);
void Brake_Pedal_Read(void);

// SHIFT SOLENOID
void Init_Shifter_Output_Pins(void);
void Set_Shift_Lock_Sol(void);
void Set_Shift_Sol_A(void);
void Set_Shift_Sol_B(void);
void Set_Shift_Sol_C(void);
void Set_Shift_Sol_D(void);
void Set_Shift_Sol_PARKING(void);
void Set_Shift_Sol_REVERSE(void);
void Set_Shift_Sol_NEUTRAL(void);










#endif /* IOHWAB_GPIO_H */
