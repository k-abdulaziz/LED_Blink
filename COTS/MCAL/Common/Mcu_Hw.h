/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  Header file for Registers definitions
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct {
    uint32 VECACT     :8;
    uint32            :3;
    uint32 RETBASE    :1;
    uint32 VECPEND    :8;
    uint32            :2;
    uint32 ISRPEND    :1;
    uint32 ISRPRE     :1;
    uint32            :1;
    uint32 PENDSTCLR  :1;
    uint32 PENDSTSET  :1;
    uint32 UNPENDSV   :1;
    uint32 PENDSV     :1;
    uint32            :2;
    uint32 NMISET     :1;
}INTCTRL_BitField;

typedef union {
    uint32           Reg;
    INTCTRL_BitField Bit;
}INTRCTRL_Tag;

typedef struct
{
    uint32 EN[5];
    uint32 res__0[27];
    uint32 DIS[5];
    uint32 res__1[27];
    uint32 PEND[5];
    uint32 res__2[27];
    uint32 UNPEND[5];
    uint32 res__3[27];
    uint32 ACTIVE[5];
    uint32 res__4[59];
    uint32 PRI[35];
    uint32 res__5[669];
    uint32 SWTRIG;
}NVIC_REG_Type;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define ARM_CORTEXM4_PERI_BASE_ADDRESS          0xE000E000
#define NVIC_BASE_ADDRESS          0x100
#define SYSTEM_CONTROL_BASE_ADDRESS 0x400FE000

/**********************************************************************************************************************
 *  System Timer (SysTick) Registers
 *********************************************************************************************************************/
typedef struct 
{
    uint32 ENABLE   :1;
    uint32 INTEN    :1;
    uint32 CLK_SRC  :1;
    uint32          :13;
    uint32 COUNT    :1;
    uint32          :15;
}STCTRL_BF;

typedef union 
{
    uint32    Reg;
    STCTRL_BF Bit;
}STCTRL_Tag;

#define STCTRL					  (*((volatile STCTRL_Tag*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x010)))
#define STRELOAD					(*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x014)))
#define STCURRENT         (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x018)))

/**********************************************************************************************************************
 *  System Control Registers
 *********************************************************************************************************************/
#define SYSCTL_PPTimer               (*(volatile uint32*)(SYSTEM_CONTROL_BASE_ADDRESS + 0x304))
#define SYSCTL_RCC					 (*(volatile uint32*)(SYSTEM_CONTROL_BASE_ADDRESS + 0x060))
#define SYSCTL_RCC2					 (*(volatile uint32*)(SYSTEM_CONTROL_BASE_ADDRESS + 0x070))
#define	SYSCTL_RCGC2				 (*(volatile uint32*)(SYSTEM_CONTROL_BASE_ADDRESS + 0x108))
#define SYSCTL_PLLSTAT				 (*((volatile uint32*)(SYSTEM_CONTROL_BASE_ADDRESS + 0x168)))
#define SYSCTL_RCGCGPIO				 (*((volatile uint32*)(SYSTEM_CONTROL_BASE_ADDRESS + 0x608)))
#define SYSCTL_RCGCWTIMER			 (*((volatile uint32*)(SYSTEM_CONTROL_BASE_ADDRESS + 0x65C)))
#define SYSCTL_RCGCTIMER			 (*((volatile uint32*)(SYSTEM_CONTROL_BASE_ADDRESS + 0x604)))

/**********************************************************************************************************************
 *  GPIO Register Map
 *********************************************************************************************************************/
#define GPIO_LOCK_KEY (uint32)0x4C4F434B

#define GPIO_APB
#ifdef  GPIO_APB
#define GPIO_BASE_ADDRESS(n)  (n<4?((0x40004000)+((n)*0x1000)): ((0x40024000)+((n-4)*0x1000)))

#define GPIODATA(n)			  		(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0x3FC)))
#define GPIODIR(n)			  		(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0x400)))
#define GPIOIS(n)					    (*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0x404)))
#define GPIOIBE(n)				  	(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0x408)))
#define GPIOIEV(n)				  	(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0x40C)))
#define GPIOIM(n)					    (*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0x410)))
#define GPIORIS(n)				  	(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0x414)))
#define GPIOMIS(n)				  	(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0x418)))
#define GPIOICR(n)				  	(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0x41C)))
#define GPIOAFSEL(n)			  	(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0x420)))
#define GPIODR2R(n)				  	(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0x500)))
#define GPIODR4R(n)				  	(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0x504)))
#define GPIODR8R(n)				  	(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0x508)))
#define GPIOODR(n)				  	(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0x50C)))
#define GPIOPUR(n)					  (*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0x510)))
#define GPIOPDR(n)				  	(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0x514)))
#define GPIOSLR(n)				  	(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0x518)))
#define GPIODEN(n)				  	(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0x51C)))
#define GPIOLOCK(n)					  (*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0x520)))
#define GPIOCR(n)					    (*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0x524)))
#define GPIOAMSEL(n)				  (*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0x528)))
#define GPIOPCTL(n)					  (*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0x52C)))
#define GPIOADCCTL(n)				  (*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0x530)))
#define GPIODMACTL(n)				  (*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0x534)))
#define GPIOPeriphID4(n)			(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0xFD0)))
#define GPIOPeriphID5(n)			(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0xFD4)))
#define GPIOPeriphID6(n)			(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0xFD8)))
#define GPIOPeriphID7(n)			(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0xFDC)))
#define GPIOPeriphID0(n)			(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0xFE0)))
#define GPIOPeriphID1(n)			(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0xFE4)))
#define GPIOPeriphID2(n)			(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0xFE8)))
#define GPIOPeriphID3(n)			(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0xFEC)))
#define GPIOPCellID0(n)				(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0xFF0)))
#define GPIOPCellID1(n)				(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0xFF4)))
#define GPIOPCellID2(n)				(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0xFF8)))
#define GPIOPCellID3(n)				(*((volatile uint32*)(GPIO_BASE_ADDRESS(n) + 0xFFC)))
#elif GPIO_AHB
#error "Not Supported"
#endif
/**********************************************************************************************************************
 *  Nested Vectored Interrupt Controller (NVIC) Registers
 *********************************************************************************************************************/
#define NVIC					    ((volatile NVIC_REG_Type*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + NVIC_BASE_ADDRESS))
#define EN(n)					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x100 + (n/4)*4)))
#define EN0					        (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x100)))
#define EN1					        (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x104)))
#define EN2                         (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x108)))
#define EN3					        (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x10C)))
#define EN4                         (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x110)))
#define DIS(n)					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x180 + (n/4)*4)))
#define DIS0					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x180)))
#define DIS1					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x184)))
#define DIS2                        (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x188)))
#define DIS3					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x18C)))
#define DIS4                        (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x190)))
#define PEND0					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x200)))
#define PEND1					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x204)))
#define PEND2                       (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x208)))
#define PEND3					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x20C)))
#define PEND4                       (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x210)))
#define UNPEND0					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x280)))
#define UNPEND1					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x284)))
#define UNPEND2                     (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x288)))
#define UNPEND3					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x28C)))
#define UNPEND4                     (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x290)))
#define ACTIVE0					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x300)))
#define ACTIVE1					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x304)))
#define ACTIVE2                     (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x308)))
#define ACTIVE3					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x30C)))
#define ACTIVE4                     (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x310)))
#define PRI(n)					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x400 + (n/4)*4)))
#define PRI0					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x400)))
#define PRI1					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x404)))
#define PRI2                        (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x408)))
#define PRI3					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x40C)))
#define PRI4                        (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x410)))
#define PRI5					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x414)))
#define PRI6					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x418)))
#define PRI7                        (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x41C)))
#define PRI8					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x420)))
#define PRI9                        (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x424)))
#define PRI10					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x428)))
#define PRI11					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x42C)))
#define PRI12                       (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x430)))
#define PRI13					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x434)))
#define PRI14                       (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x438)))
#define PRI15					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x43C)))
#define PRI16					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x440)))
#define PRI17                       (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x444)))
#define PRI18					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x448)))
#define PRI19                       (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x44C)))
#define PRI20					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x450)))
#define PRI21					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x454)))
#define PRI22                       (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x458)))
#define PRI23					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x45C)))
#define PRI24                       (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x460)))
#define PRI25					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x464)))
#define PRI26					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x468)))
#define PRI27                       (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x46C)))
#define PRI28					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x470)))
#define PRI29                       (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x474)))
#define PRI30					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x478)))
#define PRI31					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x47C)))
#define PRI32                       (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x480)))
#define PRI33					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x484)))
#define PRI34                       (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x488)))
#define SWTRIG                      (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0xF00)))

/**********************************************************************************************************************
 *  System Control Block (SCB) Registers
 *********************************************************************************************************************/
#define ACTLR					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0x008)))
#define CPUID					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0xD00)))
#define INTRCTRL                    (*((volatile INTRCTRL_Tag*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0xD04)))
#define VTABLE					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0xD08)))
#define APINT                       (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0xD0C)))
#define SYSCTRL					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0xD10)))
#define CFGCTRL						(*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0xD14)))
#define SYSPRI1						(*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0xD18)))
#define SYSPRI2						(*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0xD1C)))
#define SYSPRI3					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0xD20)))
#define SYSHNDCTRL				    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0xD24)))
#define FAULTSTAT				    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0xD28)))
#define HFAULTSTAT				    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0xD2C)))
#define MMADR					    (*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0xD34)))
#define FAULTADDR					(*((volatile uint32*)(ARM_CORTEXM4_PERI_BASE_ADDRESS + 0xD38)))


#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: MCcu_Hw.h
 *********************************************************************************************************************/
