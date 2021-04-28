/****************************************************************************************/
/*	Author 					: 				John Atia Nafady							*/
/*	Date					: 				15 OCT 2020									*/
/*	Version					: 				V01											*/
/*																						*/
/*																						*/
/****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "GPIO_interface.h"
#include "AFIO_interface.h"
#include "EXTI_interface.h"
#include "TIM_interface.h"
#include "USART_interface.h"

volatile s16 x =0;
volatile u8 bool = 0;
void func1(void)
{
	gPIO_voidSetPinValue(GPIOC , PIN13 , bool);
	bool ^= (1<<0);

}
void main(void)
{
	/* Initialize Clock */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, 2); 	//Enable RCC for GPIOA
	RCC_voidEnableClock(RCC_APB2, 3); 	//Enable RCC for GPIOB
	RCC_voidEnableClock(RCC_APB2, 4); 	//Enable RCC for GPIOC
	RCC_voidEnableClock(RCC_APB2, 0); 	//Enable RCC for AFIO
	RCC_voidEnableClock(RCC_APB2, 11);	//Enable RCC for TIMER1
	RCC_voidEnableClock(RCC_APB1 , 0);	//Enable RCC for GPTimer2
	RCC_voidEnableClock(RCC_APB1 , 1);	//Enable RCC for GPTIMER3


	/* SysTick */
	MSTK_voidInit();  					//Initialize SysTick
	//TIM1_voidInit();					//Initialize Timer1
	TIM_voidInit(TIM2);
	TIM_voidInit(TIM3);
	/* GPIO Initialization */
	gPIO_voidSetPinDir(GPIOC , PIN13 , OUT_PUSHPULL_2MHz);

	//Select TIM2 Channel 1,2,3  as OUTPUT
	//Remap TIMER2
	MAFIO_voidTimerRemapPin(TIMER2 , TIM2_REMAP2 );
	//gPIO_voidSetPinDir(GPIOA , PIN0 , OUT_PUSHPULL_2MHz);
	gPIO_voidSetPinDir(GPIOA , PIN1 , ALTRNATIVE_FUNC_PUSHPULL);
	//gPIO_voidSetPinDir(GPIOA , PIN2 , ALTRNATIVE_FUNC_PUSHPULL);
	//gPIO_voidSetPinDir(GPIOA , PIN3 , ALTRNATIVE_FUNC_PUSHPULL);

	gPIO_voidSetPinDir(GPIOB , PIN10 , ALTRNATIVE_FUNC_PUSHPULL);


	MNVIC_voidEnableInterrupt(28);	//Enable NVIC for GPTimer2
	MNVIC_voidEnableInterrupt(29);	//Enable NVIC for GPTimer3

	TIM_voidSetPeriodicInterval(TIM3 , 8000 , 1000 , func1);
	TIM_voidConfigurePWM(TIM2 ,TIM_CHANNEL_2 , ActiveHigh , PWM_MODE_1);
	//TIM_voidConfigurePWM(TIM2 ,TIM_CHANNEL_3 , ActiveHigh , PWM_MODE_2);
	//TIM_voidConfigurePWM(TIM2 ,TIM_CHANNEL_4 , ActiveHigh , PWM_MODE_2);
	TIM_voidStartPWM(TIM2 , 8 , 1000);

	while(1)
	{

		for(x = 0; x <=1000; x++)
		{
			TIM_voidSetDutyCycle(TIM2 ,TIM_CHANNEL_3 ,x);
			TIM_voidSetDutyCycle(TIM2 ,TIM_CHANNEL_2 , x);
			MSTK_voidSetBusyWait(2000);
		}

		for(x = 1000; x >= 0; x--)
		{
			TIM_voidSetDutyCycle(TIM2 ,TIM_CHANNEL_3 , x);
			TIM_voidSetDutyCycle(TIM2 ,TIM_CHANNEL_2 , x);
			MSTK_voidSetBusyWait(2000);
		}


	}
}


