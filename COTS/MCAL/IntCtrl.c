/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl_Cfg.h"
#include "IntCtrl.h"
#include "IntCtrl_Types.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	
/* Enable Exceptions */
#define Enable_Exceptions()    __asm("CPSIE I \n")

/* Disable Exceptions */
#define Disable_Exceptions()   __asm("CPSID I \n")

/* Enable Faults */
#define Enable_Faults()        __asm("CPSIE F \n")

/* Disable Faults */
#define Disable_Faults()       __asm("CPSID F \n") 

/* Witing for Interrupt (LP Mode) */
#define Wait_For_Interrupt()   __asm("WFI \n")

#define VECTKEY_RESET    			 0x05FA
#define PRIGROUP_OFFSET     	 0x8u
#define VECTKEY_OFFSET   			 16u
#define PRI_REG_RESERVED			 5u
#define PRI_FIELDS             4u 
#define EN_FIELDS              32u


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCtrl_Init(void)
{
    IntCtrl_InterruptType Interrupt_Number;
    uint8 u8_counter = 0, Index_No;
    uint32 PRI_Bit_Offset, EN_Bit_Offset;
	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
    uint32 PriorityGroupingTemp = (uint32) Group_SubGroup_Type & 7UL; /*assure 0-7 value*/
    APINT = (VECTKEY_RESET << VECTKEY_OFFSET) | (PriorityGroupingTemp << PRIGROUP_OFFSET);
    //Enable_Exceptions();
		//Enable_Faults();

    /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  
    for(u8_counter = 0; u8_counter < Number_of_Interrupts; u8_counter++)
    {
    	Interrupt_Number = IntCtrl_Config_Array[u8_counter].Interrupt_Number;
			Index_No = Interrupt_Number / WORD_LENGTH_BYTES;
			PRI_Bit_Offset = (((Interrupt_Number % PRI_FIELDS) * PRIGROUP_OFFSET) + 5);
		
		if(Interrupt_Number >= 0)
		{
		#if		(Group_SubGroup_Type == PRIGROUP_XXX)
    		NVIC->PRI[Index_No] |= (IntCtrl_Config_Array[u8_counter].Group_Priority << PRI_Bit_Offset);
		#elif	(Group_SubGroup_Type == PRIGROUP_XXY)
    		NVIC->PRI[Index_No] |= (IntrCtrl_Config_Array[u8_counter].Group_Priority << (PRI_Bit_Offset + 1));
    		NVIC->PRI[Index_No] |= (IntrCtrl_Config_Array[u8_counter].Sub_Group_Priority << PRI_Bit_Offset);
    	#elif	(Group_SubGroup_Type == PRIGROUP_XYY)	
			NVIC->PRI[Index_No] |= (IntrCtrl_Config_Array[u8_counter].Group_Priority << (PRI_Bit_Offset + 2));
			NVIC->PRI[Index_No] |= (IntrCtrl_Config_Array[u8_counter].Sub_Group_Priority << PRI_Bit_Offset);
   		#elif	(Group_SubGroup_Type == PRIGROUP_YYY)
    		NVIC->PRI[Index_No] |= (IntrCtrl_Config_Array[u8_counter].Sub_Group_Priority << PRI_Bit_Offset);
    	#endif
			
			/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
    	Index_No = Interrupt_Number / WORD_LENGTH_BITS;
			EN_Bit_Offset = (Interrupt_Number % EN_FIELDS);
      Set_Bit(EN(Index_No), EN_Bit_Offset);
    }
		
		else
		{
			uint32 tempPriority;
			if (IntCtrl_Config_Array[u8_counter].Interrupt_Number 	== 	MEM_MGMNT)
			{
				tempPriority = SYSPRI1;
				tempPriority &= ~(0x7UL << 5);
				tempPriority |=	(uint32)IntCtrl_Config_Array[u8_counter].Group_Priority << 5;
				SYSPRI1 = tempPriority;
				SYSHNDCTRL	|=	0x00010000UL;
			}
		
			else if	(IntCtrl_Config_Array[u8_counter].Interrupt_Number 	== 	BUS_FAULT)
			{
				tempPriority = SYSPRI1;
				tempPriority &= ~(0x7UL << 13);
				tempPriority |=	(uint32)IntCtrl_Config_Array[u8_counter].Group_Priority << 13;
				SYSPRI1 = tempPriority;
				SYSHNDCTRL	|=	0x00020000UL;
			}
		
			else if (IntCtrl_Config_Array[u8_counter].Interrupt_Number 	==	USAGE_FAULT)
			{
				tempPriority = SYSPRI1;
				tempPriority &= ~(0x7UL << 21);
				tempPriority |=	(uint32)IntCtrl_Config_Array[u8_counter].Group_Priority << 21;
				SYSPRI1 = tempPriority;
				SYSHNDCTRL	|=	0x00040000UL;
			}
		
			else if (IntCtrl_Config_Array[u8_counter].Interrupt_Number 	== 	SVCall)
			{
				tempPriority = SYSPRI2;
				tempPriority &= ~(0x7UL << 29);
				tempPriority |=	(uint32)IntCtrl_Config_Array[u8_counter].Group_Priority << 29;
				SYSPRI2 = tempPriority;
			}
			
			else if (IntCtrl_Config_Array[u8_counter].Interrupt_Number 	== 	Debug_Monitor)
			{
				tempPriority = SYSPRI3;
				tempPriority &= ~(0x7UL << 5);
				tempPriority |=	(uint32)IntCtrl_Config_Array[u8_counter].Group_Priority << 5;
				SYSPRI3 = tempPriority;
			}
			
			else if (IntCtrl_Config_Array[u8_counter].Interrupt_Number 	== 	PendSV)
			{
				tempPriority = SYSPRI3;
				tempPriority &= ~(0x7UL << 21);
				tempPriority |= (uint32)IntCtrl_Config_Array[u8_counter].Group_Priority  << 21;
				SYSPRI3 = tempPriority;
			}
		
			else if (IntCtrl_Config_Array[u8_counter].Interrupt_Number 	== 	SysTick)
			{
				tempPriority = SYSPRI3;
				tempPriority &= ~(0x7UL << 29);
				tempPriority |=	(uint32)IntCtrl_Config_Array[u8_counter].Group_Priority << 29;
				SYSPRI3 = tempPriority;
				STCTRL.Bit.INTEN	=	1UL;
			}
		}
	}
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
