#include "IntCtrl.h"
#include "Port.h"
#include "Dio.h"
#include "SysTick.h"

void LED_Blink(void);

static uint8 ON_Time = 2;
static uint8 OFF_Time = 4;
extern SysTickCounter;

void LED_Blink(void)
{
	if(LED_STATUS() == Low) // LED_OFF
	{
		if(SysTickCounter >= OFF_Time)
		{
			LED_ON();
			SysTickCounter = 0; //RESET COUNTER
		}
	}
	else if (LED_STATUS() == High)// LED_ON
	{
		if(SysTickCounter >= ON_Time)
		{
			LED_OFF();
			SysTickCounter = 0; //RESET COUNTER
		}
	}
}

int main(void)
{
	//IntCtrl_Init();
	//Port_Init(Ports_Config);
	LED_Init();
	SysTick_Init(SysTick_Config);
	SysTick_Start();
	while(1)
	{
		SysTick_SetCallback(LED_Blink);
	}
	return 0;
}