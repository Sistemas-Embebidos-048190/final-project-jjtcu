#include "IoHwAb_gpio.h"


void Init_Gear_Selection_Pins(void){
    /* Enables the clock for PORT0 controller: Enables clock */
    //CLOCK_EnableClock(kCLOCK_Port0);
    /* Enables the clock for PORT1 , PORT2: Enables clock */
    CLOCK_EnableClock(kCLOCK_Port1);
    CLOCK_EnableClock(kCLOCK_Port2);
    CLOCK_EnableClock(kCLOCK_Port3);
    CLOCK_EnableClock(kCLOCK_Port0);
    CLOCK_EnableClock(kCLOCK_Gpio0);
    CLOCK_EnableClock(kCLOCK_Gpio1);
    CLOCK_EnableClock(kCLOCK_Gpio2);
    CLOCK_EnableClock(kCLOCK_Gpio3);

    const port_pin_config_t intput_pin_config = {
        /* Internal pull-up/down resistor is disabled */
        kPORT_PullDisable,
        /* Low internal pull resistor value is selected. */
        kPORT_LowPullResistor,
        /* Fast slew rate is configured */
        kPORT_FastSlewRate,
        /* Passive input filter is disabled */
        kPORT_PassiveFilterDisable,
        /* Open drain output is disabled */
        kPORT_OpenDrainDisable,
        /* Low drive strength is configured */
        kPORT_LowDriveStrength,
        /* Pin is configured as PIO0_10 */
        kPORT_MuxAlt0,
        /* Digital input enabled */
        kPORT_InputBufferEnable,
        /* Digital input is not inverted */
        kPORT_InputNormal,
        /* Pin Control Register fields [15:0] are not locked */
        kPORT_UnlockRegister
    };

    /* SET PIN CONFIG GEAR SELECTION */
    PORT_SetPinConfig(PORT3, 5U, &intput_pin_config); //PARKING
    PORT_SetPinConfig(PORT1, 13U, &intput_pin_config); //REVERSE
    PORT_SetPinConfig(PORT2, 0U,  &intput_pin_config); //NEUTRAL
    PORT_SetPinConfig(PORT1, 23U, &intput_pin_config); //DRIVE
    PORT_SetPinConfig(PORT0, 29U,  &intput_pin_config); //FIRST
    PORT_SetPinConfig(PORT1, 9U,  &intput_pin_config); //SECOND
    PORT_SetPinConfig(PORT3, 4U, &intput_pin_config); //THIRD

    gpio_pin_config_t Pin_Gear_config = {
        kGPIO_DigitalInput,
        0,
    };
    GPIO_PinInit(GPIO3, 5U, &Pin_Gear_config);
    GPIO_PinInit(GPIO1, 13U, &Pin_Gear_config);
    GPIO_PinInit(GPIO2, 0U,  &Pin_Gear_config);
    GPIO_PinInit(GPIO1, 23U, &Pin_Gear_config);
    GPIO_PinInit(GPIO0, 29U,  &Pin_Gear_config);
    GPIO_PinInit(GPIO1, 9U,  &Pin_Gear_config);
    GPIO_PinInit(GPIO3, 4U, &Pin_Gear_config);
}

gear_selector_t Gear_Selection_GetPosition(void)
{
    uint32 pinParking = GPIO_PinRead(GPIO3, 5U); // P3_5
    uint32 pinReverse = GPIO_PinRead(GPIO1, 13U); // P1_13
    uint32 pinNeutral = GPIO_PinRead(GPIO2, 0U);  // P2_0
    uint32 pinDrive   = GPIO_PinRead(GPIO1, 23U); // P1_23
    uint32 pinFirst   = GPIO_PinRead(GPIO0, 29U);  // P3_3
    uint32 pinSecond  = GPIO_PinRead(GPIO1, 9U);  // P1_9
    uint32 pinThird   = GPIO_PinRead(GPIO3, 4U); // P3_4

    if (pinParking)
    {
        Write_IO_Gear_Lever_Position(GEAR_PARKING);
    }
    else if (pinReverse)
    {
        Write_IO_Gear_Lever_Position(GEAR_REVERSE);
    }
    else if (pinNeutral)
    {
        Write_IO_Gear_Lever_Position(GEAR_NEUTRAL);
    }
    else if (pinDrive)
    {
        Write_IO_Gear_Lever_Position(GEAR_DRIVE);
    }
    else if (pinFirst)
    {
        Write_IO_Gear_Lever_Position(GEAR_FIRST);
    }
    else if (pinSecond)
    {
        Write_IO_Gear_Lever_Position(GEAR_SECOND);
    }
    else if (pinThird)
    {
        Write_IO_Gear_Lever_Position(GEAR_THIRD);
    }
    else
    {
        // Ningún pin activo o estado inválido
        Write_IO_Gear_Lever_Position(GEAR_INVALID);
    }


}


// brake pedal sensor

void Init_Brake_Pedal_Pins(void){

    // habilitar relojes
    CLOCK_EnableClock(kCLOCK_Port1);
    CLOCK_EnableClock(kCLOCK_Gpio1);

    // Pin Config
    const port_pin_config_t intput_pin_config = {
        /* Internal pull-up/down resistor is disabled */
        kPORT_PullDisable,
        /* Low internal pull resistor value is selected. */
        kPORT_LowPullResistor,
        /* Fast slew rate is configured */
        kPORT_FastSlewRate,
        /* Passive input filter is disabled */
        kPORT_PassiveFilterDisable,
        /* Open drain output is disabled */
        kPORT_OpenDrainDisable,
        /* Low drive strength is configured */
        kPORT_LowDriveStrength,
        /* Pin is configured as PIO0_10 */
        kPORT_MuxAlt0,
        /* Digital input enabled */
        kPORT_InputBufferEnable,
        /* Digital input is not inverted */
        kPORT_InputNormal,
        /* Pin Control Register fields [15:0] are not locked */
        kPORT_UnlockRegister
    };

    /* SET Pin Config */
    PORT_SetPinConfig(PORT1, 14U, &intput_pin_config); //BRAKE PEDAL

    gpio_pin_config_t Pin_Gear_config = {
        kGPIO_DigitalInput,
        0,
    };
    GPIO_PinInit(GPIO1, 14U, &Pin_Gear_config);
}

void Brake_Pedal_Read(void)
{
    uint8 pinBrake_Pedal = GPIO_PinRead(GPIO1, 14U); // P1_14

    /* Aquí lo lógico es escribir al RTE del freno, no la palanca de cambios */
    Write_IO_BrakeLightSwitch(pinBrake_Pedal);

}

void Init_Shifter_Output_Pins(void)
{
    /* Habilitar clocks para los puertos */
    CLOCK_EnableClock(kCLOCK_Port1);
    CLOCK_EnableClock(kCLOCK_Port4);

    /* Configuración común para pines GPIO como salida */
    const port_pin_config_t output_pin_config = {
        kPORT_PullDisable,
        kPORT_LowPullResistor,
        kPORT_FastSlewRate,
        kPORT_PassiveFilterDisable,
        kPORT_OpenDrainDisable,
        kPORT_LowDriveStrength,
        kPORT_MuxAlt0,             // ALT0 = GPIO
        kPORT_InputBufferDisable,  // No necesitamos lectura
        kPORT_InputNormal,
        kPORT_UnlockRegister
    };

    /* ----- SHIFT LOCK SOL (P1_12) ----- */
    PORT_SetPinConfig(PORT1, 12U, &output_pin_config);

    /* ----- SHIFT PARK SOL (P1_16) ----- */
	PORT_SetPinConfig(PORT1, 16U, &output_pin_config);

	/* ----- SHIFT REVERSE SOL (P1_18) ----- */
	PORT_SetPinConfig(PORT1, 18U, &output_pin_config);

	/* ----- SHIFT NEUTRAL SOL (P1_19) ----- */
	PORT_SetPinConfig(PORT1, 19U, &output_pin_config);

    /* ----- SHIFT SOL A (P4_4) ----- */
    PORT_SetPinConfig(PORT4, 4U, &output_pin_config);

    /* ----- SHIFT SOL B (P1_22) ----- */
    PORT_SetPinConfig(PORT1, 22U, &output_pin_config);

    /* ----- SHIFT SOL C (P1_17) ----- */
    PORT_SetPinConfig(PORT1, 17U, &output_pin_config);

    /* ----- SHIFT SOL D (P1_15) -----*/
    PORT_SetPinConfig(PORT1, 15U, &output_pin_config);

    /* Inicializar GPIO como salidas */
    gpio_pin_config_t out_config = {
        kGPIO_DigitalOutput,
        0  // Estado inicial en LOW
    };

    GPIO_PinInit(GPIO1, 12U, &out_config);
    GPIO_PinInit(GPIO4, 4U,  &out_config);
    GPIO_PinInit(GPIO1, 22U, &out_config);
    GPIO_PinInit(GPIO1, 17U, &out_config);
    GPIO_PinInit(GPIO1, 15U, &out_config);
    GPIO_PinInit(GPIO1, 16U, &out_config);
    GPIO_PinInit(GPIO1, 18U, &out_config);
    GPIO_PinInit(GPIO1, 19U, &out_config);

}

void Set_Shift_Lock_Sol(void)
{
    uint32 state = 0;

    /* Antes: Read_SOL_ShiftLock_FromHW(state);  (mal por nombre y por puntero) */
    Read_SOL_ShiftLock(&state);

    if (state)
    {
        GPIO_PinWrite(GPIO1, 12U, 1);
    }
    else
    {
        GPIO_PinWrite(GPIO1, 12U, 0);
    }
}

void Set_Shift_Sol_A(void)
{
    uint32 state = 0;

    // Leer del RTE (salida lógica SOL_ClutchA)
    Read_SOL_ClutchA(&state);

    if (state)
    {
        GPIO_PinWrite(GPIO4, 4U, 1);
    }
    else
    {
        GPIO_PinWrite(GPIO4, 4U, 0);
    }
}

void Set_Shift_Sol_B(void)
{
    uint32 state = 0;

    // Leer del RTE (salida lógica SOL_ClutchB)
    Read_SOL_ClutchB(&state);

    if (state)
    {
        GPIO_PinWrite(GPIO1, 22U, 1);
    }
    else
    {
        GPIO_PinWrite(GPIO1, 22U, 0);
    }
}

void Set_Shift_Sol_C(void)
{
    uint32 state = 0;

    // Leer del RTE (salida lógica SOL_ClutchC)
    Read_SOL_ClutchC(&state);

    if (state)
    {
        GPIO_PinWrite(GPIO1, 17U, 1);
    }
    else
    {
        GPIO_PinWrite(GPIO1, 17U, 0);
    }
}

void Set_Shift_Sol_D(void)
{
    uint32 state = 0;

    // Leer del RTE (salida lógica SOL_ClutchD)
    Read_SOL_ClutchD(&state);

    if (state)
    {
        GPIO_PinWrite(GPIO1, 15U, 1);
    }
    else
    {
        GPIO_PinWrite(GPIO1, 15U, 0);
    }
}

void Set_Shift_Sol_PARKING(void)
{
    uint32 state = 0;

    // Leer del RTE (salida lógica SOL_ClutchD)
    Read_SOL_ClutchParking(&state);

    if (state)
    {
        GPIO_PinWrite(GPIO1, 16U, 1);
    }
    else
    {
        GPIO_PinWrite(GPIO1, 16U, 0);
    }
}

void Set_Shift_Sol_REVERSE(void)
{
    uint32 state = 0;

    // Leer del RTE (salida lógica SOL_ClutchD)
    Read_SOL_ClutchReverse(&state);

    if (state)
    {
        GPIO_PinWrite(GPIO1, 18U, 1);
    }
    else
    {
        GPIO_PinWrite(GPIO1, 18U, 0);
    }
}

void Set_Shift_Sol_NEUTRAL(void)
{
    uint32 state = 0;

    // Leer del RTE (salida lógica SOL_ClutchD)
    Read_SOL_ClutchNeutral(&state);

    if (state)
    {
        GPIO_PinWrite(GPIO1, 19U, 1);
    }
    else
    {
        GPIO_PinWrite(GPIO1, 19U, 0);
    }
}
