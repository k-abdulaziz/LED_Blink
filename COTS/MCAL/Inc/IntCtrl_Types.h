/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum {
		RESET = -15,
		NMI = -14,
		HARD_FAULT = -13,
		MEM_MGMNT = -12,
		BUS_FAULT = -11,
		USAGE_FAULT = -10,
		SVCall = -5,
		Debug_Monitor = -4,
		PendSV = -2,
		SysTick = -1,
    GPIO_Port_A,
    GPIO_Port_B,
    GPIO_Port_C,
    GPIO_Port_D,
    GPIO_Port_E,
    UART0,
    UART1,
    SSI0,
    I2C0,
    PWM0_Fault,
    PWM0_Generator0,
    PWM0_Generator1,
    PWM0_Generator2,
    QEI0,
    ADC0_Sequence0,
    ADC0_Sequence1,
    ADC0_Sequence2,
    ADC0_Sequence3,
    Watchdog_Timers,
    Timer_0A_16_32_Bit,
    Timer_0B_16_32_Bit,
    Timer_1A_16_32_Bit,
    Timer_1B_16_32_Bit,
    Timer_2A_16_32_Bit,
    Timer_2B_16_32_Bit,
    Analog_Comparator0,
    Analog_Comparator1,
    System_Control = 28,
    Flash_EEPROM_Control,
    GPIO_Port_F,
    UART2 = 33,
    SSI1,
    Timer_3A_16_32_Bit,
    Timer_3B_16_32_Bit,
    I2C1,
    QEI1,
    CAN0,
    CAN1,
    Hibernation_Module = 43,
    USB,
    PWM_Generator3,
    uDMA_Software,
    uDMA_error,
    ADC1_sequence0,
    ADC1_sequence1,
    ADC1_sequence2,
    ADC1_sequence3,
    SSI2 = 57,
    SSI3,
    UART3,
    UART4,
    UART5,
    UART6,
    UART7,
    I2C2 = 68,
    I2C3,
    Timer_4A_16_32_Bit,
    Timer_4B_16_32_Bit,
    Timer_5A_16_32_Bit = 92,
    Timer_0A_32_64_Bit,
    Timer_0B_32_64_Bit,
    Timer_1A_32_64_Bit,
    Timer_1B_32_64_Bit,
    Timer_2A_32_64_Bit,
    Timer_2B_32_64_Bit,
    Timer_3A_32_64_Bit,
    Timer_3B_32_64_Bit,
    Timer_4A_32_64_Bit,
    Timer_4B_32_64_Bit,
    Timer_5A_32_64_Bit,
    Timer_5B_32_64_Bit,
    System_Exception,
    PWM1_Generator0 = 134,
    PWM1_Generator1,
    PWM1_Generator2,
    PWM1_Generator3,
    PWM1_Fault,
}IntCtrl_InterruptType;
 
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
