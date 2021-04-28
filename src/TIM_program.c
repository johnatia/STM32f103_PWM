/****************************************************************************************/
/*	Author 					: 				John Atia Nafady							*/
/*	Date					: 				13 JAN 2021									*/
/*	Version					: 				V01											*/
/*																						*/
/*																						*/
/****************************************************************************************/

/****************************************************************************************/
/*	Author 					: 				John Atia Nafady							*/
/*	Date					: 				27 MAR 2021									*/
/*	Version					: 				V02											*/
/*																						*/
/*																						*/
/****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIM_interface.h"
#include "TIM_config.h"
#include "TIM_private.h"

static volatile u8 TIM1_u8TimeIntervalMode = 5;
static volatile u8 TIM2_u8TimeIntervalMode = 5;
static volatile u8 TIM3_u8TimeIntervalMode = 5;
static volatile u8 TIM4_u8TimeIntervalMode = 5;
void(*TIM1_CallBack)(void);
void(*TIM2_CallBack)(void);
void(*TIM3_CallBack)(void);
void(*TIM4_CallBack)(void);


void TIM_voidInit(TIMx_t* TIMx)
{
	//Reset Registers
	TIMx->CR1  = 0;
	TIMx->DIER = 0;
	TIMx->SR   = 0;

#if(SYSTEM_CLK_DIVISION == NO_CLK_DIVISION)
	CLR_BIT(TIMx->CR1 , 8);
	CLR_BIT(TIMx->CR1 , 9);
#elif(SYSTEM_CLK_DIVISION == CLK_DIVISION_2)
	SET_BIT(TIMx->CR1 , 8);
	CLR_BIT(TIMx->CR1 , 9);
#elif(SYSTEM_CLK_DIVISION == CLK_DIVISION_4)
	CLR_BIT(TIMx->CR1 , 8);
	SET_BIT(TIMx->CR1 , 9);
#endif
	//Set Bit7 ARPE to activate Auto-reload preload enable, TIMx_ARR register is buffered
	SET_BIT(TIMx-> CR1 , 7);
#if(COUNTER_MODE == DOWN_COUNTER)
	//Set Bit4 DIR to use Counter as down counter
	SET_BIT(TIMx-> CR1 , 4);
#elif(COUNTER_MODE == UP_COUNTER)
	//Reset Bit4 DIR to use Counter as up counter
	CLR_BIT(TIMx-> CR1 , 4);
#endif
	//Set Bit2 URS to generate an update interrupt or DMA request Only  at counter overflow/underflow Mode
	SET_BIT(TIMx-> CR1 , 2);
	//CLR Bit0 UIE to disable Update interrupt
	CLR_BIT(TIMx->DIER , 0);
}
void TIM_voidSetBusyWait(TIMx_t* TIMx , u16 TIM_u16Prescaler , u16 TIM_u16Ticks )
{
	//CK_CNT = fCK_PSC/(TIM1->PSC+1)
	//Counter Clk = ClkFreq/(Prescaler+1)
	//Set Prescaler
	TIMx->PSC = ( TIM_u16Prescaler - 1 );
	//Auto reload value
	TIMx->ARR = TIM_u16Ticks;
	//Set Bit0 UG to update Counter & Prescaler
	SET_BIT(TIMx->EGR , 0);
	//Set Bit0 CEN to enable counter
	SET_BIT(TIMx-> CR1, 0);
	//wait till interrupt flag
	while( GET_BIT(TIMx->SR , 0) == 0 );
	//CLR Bit0 CEN to disable counter
	CLR_BIT(TIMx-> CR1, 0);
	//Clear Interrupt Flag
	CLR_BIT(TIMx->SR , 0) ;
}


void TIM_voidSetSingleInterval(TIMx_t* TIMx , u16 TIM_u16Prescaler ,  u16 TIM_u16Ticks , void(*PtrToFunc)(void) )
{
	switch((u32)TIMx)
	{
	case (TIM1_BASE_ADDRESS):

		TIM1_u8TimeIntervalMode = TIM1_SINGLE_INTERVAL;
		//Save Callback Function
		TIM1_CallBack = PtrToFunc;
		break;

	case (TIM2_BASE_ADDRESS):

		TIM2_u8TimeIntervalMode = TIM2_SINGLE_INTERVAL;
		//Save Callback Function
		TIM2_CallBack = PtrToFunc;
		break;

	case (TIM3_BASE_ADDRESS):

		TIM3_u8TimeIntervalMode = TIM3_SINGLE_INTERVAL;
		//Save Callback Function
		TIM3_CallBack = PtrToFunc;
		break;

	case (TIM4_BASE_ADDRESS):

		TIM4_u8TimeIntervalMode = TIM4_SINGLE_INTERVAL;
		//Save Callback Function
		TIM4_CallBack = PtrToFunc;
		break;
	}

	//CK_CNT = fCK_PSC/(TIM1->PSC+1)
	//Counter Clk = ClkFreq/(Prescaler+1)
	//Set Prescaler
	TIMx->PSC = ( TIM_u16Prescaler - 1 );
	//Auto reload value
	TIMx->ARR = TIM_u16Ticks;
	//Set Bit0 UG to update Counter & Prescaler
	SET_BIT(TIMx->EGR , 0);
	//Set Bit0 UIE to Enable Update interrupt
	SET_BIT(TIMx->DIER , 0);
	//Set Bit0 CEN to enable counter
	SET_BIT(TIMx-> CR1, 0);
}
void TIM_voidSetPeriodicInterval(TIMx_t* TIMx ,  u16 TIM_u16Prescaler , u16 TIM_u16Ticks , void(*PtrToFunc)(void) )
{

	switch((u32)TIMx)
	{
	case TIM1_BASE_ADDRESS:
		TIM1_u8TimeIntervalMode = TIM1_PERIODIC_INTERVAL;
		//Save Callback Function
		TIM1_CallBack = PtrToFunc;
		break;
	case TIM2_BASE_ADDRESS:
		TIM2_u8TimeIntervalMode = TIM2_PERIODIC_INTERVAL;
		//Save Callback Function
		TIM2_CallBack = PtrToFunc;
		break;
	case TIM3_BASE_ADDRESS:
		TIM3_u8TimeIntervalMode = TIM3_PERIODIC_INTERVAL;
		//Save Callback Function
		TIM3_CallBack = PtrToFunc;
		break;
	case TIM4_BASE_ADDRESS:
		TIM4_u8TimeIntervalMode = TIM4_PERIODIC_INTERVAL;
		//Save Callback Function
		TIM4_CallBack = PtrToFunc;
		break;
	}
//	if(TIMx == TIM1_BASE_ADDRESS)
//	{
//		TIM1_u8TimeIntervalMode = TIM1_PERIODIC_INTERVAL;
//		//Save Callback Function
//		TIM1_CallBack = PtrToFunc;
//	}
//	else if(TIMx == TIM2_BASE_ADDRESS)
//		{
//		TIM2_u8TimeIntervalMode = TIM2_PERIODIC_INTERVAL;
//		//Save Callback Function
//		TIM2_CallBack = PtrToFunc;
//		}
//
//	else if(TIMx == TIM3_BASE_ADDRESS)
//		{
//		TIM3_u8TimeIntervalMode = TIM3_PERIODIC_INTERVAL;
//		//Save Callback Function
//		TIM3_CallBack = PtrToFunc;
//		}
//
//	else if(TIMx == TIM4_BASE_ADDRESS)
//		{
//		TIM4_u8TimeIntervalMode = TIM4_PERIODIC_INTERVAL;
//		//Save Callback Function
//		TIM4_CallBack = PtrToFunc;
//		}

	//Counter Clk = ClkFreq/(Prescaler+1)
	TIMx->PSC = ( TIM_u16Prescaler - 1 );
	//Auto reload value
	TIMx->ARR = TIM_u16Ticks;
	//Set Bit0 UG to update Counter & Prescaler
	SET_BIT(TIMx->EGR , 0);
	//Set Bit0 CEN to enable counter
	SET_BIT(TIMx-> CR1, 0);
	//Set Bit0 UIE to Enable Update interrupt
	SET_BIT(TIMx->DIER , 0);
}

u16  TIM_u16GetElapsedTime(TIMx_t* TIMx)
{
	u16 local_u16Reslut=0;
	local_u16Reslut = ( (TIMx->ARR) - (TIMx->CNT) );
	return local_u16Reslut;
}
u16  TIM_u16GetRemainingTime(TIMx_t* TIMx)
{
	return TIMx->CNT;
}


void TIM_voidConfigurePWM(TIMx_t* TIMx, TIM_Channel_t TIM_Channel , TIM_ChannelPolarity_t TIM_ChannelPolarity , PWM_Mode_t PWM_Mode)
{
	switch(TIM_Channel)
	{
	case TIM_CHANNEL_1 :
		if(PWM_Mode == PWM_MODE_1)
		//Bit(OC1M) Output compare 1 Preload enable to Select PWM Mode 1 for Channel 1
		{
			TIMx->CCMR1 &=~(1<<4);
			TIMx->CCMR1 |= (1<<5) | (1<<6) ;
		}
		else if(PWM_Mode == PWM_MODE_2)
		{
			TIMx->CCMR1 |= (1<<4) | (1<<5) | (1<<6) ;
		}
		//Set Bit (OC1PE) for Channel 1
		SET_BIT(TIMx->CCMR1 , 3);
		if(TIM_ChannelPolarity == ActiveHigh)
		{
			//Bit1 CC1P: Capture/Compare 1 output polarity , Polarity of Channel 1 is active High
			CLR_BIT(TIMx->CCER , 1);
		}

		else if(TIM_ChannelPolarity == ActiveLow)
		{
			//Bit1 CC1P: Capture/Compare 1 output polarity ,Polarity of Channel 1 is active Low
			SET_BIT(TIMx->CCER , 1);
		}
		//activate Channel 1 Bit0 CC1E: Capture/Compare 1 output enable
		SET_BIT(TIMx->CCER , 0);
		break;

					/***************************************************/

	case TIM_CHANNEL_2 :
		if(PWM_Mode == PWM_MODE_1)
		{
		//Bit(OC2M) Output compare 2 Preload enable to Select PWM Mode 1 for Channel 2
			TIMx->CCMR1 &=~(1<<12); 		TIMx->CCMR1 |= (1<<13) | (1<<14) ;
		}
		else if(PWM_Mode == PWM_MODE_2)
		{
			TIMx->CCMR1 |= (1<<12) | (1<<13) | (1<<14) ;
		}
		//Set Bit (OC2PE) for Channel 2
		SET_BIT(TIMx->CCMR1 , 11);
		if(TIM_ChannelPolarity == ActiveHigh)
		{
			//Bit5 CC2P: Capture/Compare 2 output polarity , Polarity of Channel 2 is active High
			CLR_BIT(TIMx->CCER , 5);
		}

		else if(TIM_ChannelPolarity == ActiveLow)
		{
			//Bit5 CC2P: Capture/Compare 2 output polarity , Polarity of Channel 2 is active Low
			SET_BIT(TIMx->CCER , 5);
		}
		//activate Channel 2 Bit4 CC2E: Capture/Compare 2 output enable
		SET_BIT(TIMx->CCER , 4);
		break;
						/***************************************************/
	case TIM_CHANNEL_3 :
		if(PWM_Mode == PWM_MODE_1)
		{
			//Bit(OC3M) Output compare 3 Preload enable to Select PWM Mode 1 for Channel 3
			TIMx->CCMR2 &=~(1<<4); 		TIMx->CCMR2 |= (1<<5) | (1<<6) ;
		}
		else if(PWM_Mode == PWM_MODE_2)
		{
			TIMx->CCMR2 |= (1<<4) | (1<<5) | (1<<6) ;
		}
		//Set Bit (OC3PE) for Channel 3
		SET_BIT(TIMx->CCMR2 , 3);
		if(TIM_ChannelPolarity == ActiveHigh)
		{
			//Bit9 CC3P: Capture/Compare 3 output polarity , Polarity of Channel 3 is active High
			CLR_BIT(TIMx->CCER , 9);
		}
		else if(TIM_ChannelPolarity == ActiveLow)
		{
			//Bit9 CC3P: Capture/Compare 3 output polarity , Polarity of Channel 3 is active Low
			SET_BIT(TIMx->CCER , 9);
		}
		//activate Channel 3 Bit8 CC3E: Capture/Compare 3 output enable
		SET_BIT(TIMx->CCER , 8);
		break;
					/***************************************************/
	case TIM_CHANNEL_4 :
		if(PWM_Mode == PWM_MODE_1)
		{
			//Bit(OC4M) Output compare 4 Preload enable to Select PWM Mode 1 for Channel 4
			TIMx->CCMR2 &=~(1<<12); 		TIMx->CCMR2 |= (1<<13) | (1<<14) ;
		}

		else if(PWM_Mode == PWM_MODE_2)
		{
			TIMx->CCMR2 |= (1<<12) | (1<<13) | (1<<14) ;
		}
		//Set Bit (OC4PE) for Channel 4
		SET_BIT(TIMx->CCMR2 , 11);
		if(TIM_ChannelPolarity == ActiveHigh)
		{
			//Bit13 CC4P: Capture/Compare 3 output polarity ,Polarity of Channel 4 is active High
			CLR_BIT(TIMx->CCER , 13);
		}

		else if(TIM_ChannelPolarity == ActiveLow)
		{
			//Bit13 CC4P: Capture/Compare 3 output polarity , Polarity of Channel 4 is active Low
			SET_BIT(TIMx->CCER , 13);
		}
		//activate Channel 4 Bit12 CC4E: Capture/Compare 4 output enable
		SET_BIT(TIMx->CCER , 12);
		break;
	}
}

void TIM_voidSetDutyCycle(TIMx_t* TIMx, TIM_Channel_t TIM_Channel , u16 TIM_u16DutyCycle )
{
	switch(TIM_Channel)
	{
	case TIM_CHANNEL_1 :
		//Set Duty Cycle for Channel 1
		TIMx->CCR1 = TIM_u16DutyCycle;
		break;
	case TIM_CHANNEL_2 :

		//Set Duty Cycle for Channel 1
		TIMx->CCR2 = TIM_u16DutyCycle;
		break;
	case TIM_CHANNEL_3 :

		//Set Duty Cycle for Channel 1
		TIMx->CCR3 = TIM_u16DutyCycle;
		break;
	case TIM_CHANNEL_4 :

		//Set Duty Cycle for Channel 1
		TIMx->CCR4 = TIM_u16DutyCycle;
		break;
	}

}
void TIM_voidStartPWM(TIMx_t* TIMx, u16 TIM_u16Prescaler , u16 TIM_u16Period)
{
	//Set Prescaler
	TIMx->PSC = ( TIM_u16Prescaler - 1 );
	//Auto reload value
	TIMx->ARR = TIM_u16Period-1;
	//BIT (ARPE)  Auto-reload preload enable
	SET_BIT(TIMx->CR1 , 7);
	//Set Bit0 UG to update Counter & Prescaler
	SET_BIT(TIMx->EGR , 0);
	//Set Bit0 CEN to enable counter
	SET_BIT(TIMx-> CR1, 0);
}


void TIM1_UP_IRQHandler(void)
{
	if(TIM1_u8TimeIntervalMode == TIM1_SINGLE_INTERVAL)
	{
		//CLR Bit0 UIE to Disable Update interrupt
		CLR_BIT(TIM1->DIER , 0);
		//CLR Bit0 CEN to disable counter
		CLR_BIT(TIM1-> CR1, 0);
	}
	TIM1_CallBack();
	//Clear UnderFlow Interrupt Flag
	CLR_BIT(TIM1->SR , 0) ;
}

void TIM2_IRQHandler(void)
{
	if(TIM2_u8TimeIntervalMode == TIM2_SINGLE_INTERVAL)
	{
		//CLR Bit0 UIE to Disable Update interrupt
		CLR_BIT(TIM2->DIER , 0);
		//CLR Bit0 CEN to disable counter
		CLR_BIT(TIM2-> CR1, 0);
	}
	TIM2_CallBack();
	//Clear UnderFlow Interrupt Flag
	CLR_BIT(TIM2->SR , 0) ;
}

void TIM3_IRQHandler(void)
{
	if(TIM3_u8TimeIntervalMode == TIM3_SINGLE_INTERVAL)
	{
		//CLR Bit0 UIE to Disable Update interrupt
		CLR_BIT(TIM3->DIER , 0);
		//CLR Bit0 CEN to disable counter
		CLR_BIT(TIM3-> CR1, 0);
	}
	TIM3_CallBack();
	//Clear UnderFlow Interrupt Flag
	CLR_BIT(TIM3->SR , 0) ;
}

void TIM4_IRQHandler(void)
{
	if(TIM4_u8TimeIntervalMode == TIM4_SINGLE_INTERVAL)
	{
		//CLR Bit0 UIE to Disable Update interrupt
		CLR_BIT(TIM4->DIER , 0);
		//CLR Bit0 CEN to disable counter
		CLR_BIT(TIM4-> CR1, 0);
	}
	TIM4_CallBack();
	//Clear UnderFlow Interrupt Flag
	CLR_BIT(TIM4->SR , 0) ;
}

//void GPTIM2_voidStartPWM(u16 u16Prescaler , u16 u16DutyCycle ,u16 u16Period, u8 Channel)
//void GPTIM2_voidStartPWM(void)
//void GPTIM2_voidStartPWM(u16 TIM_u16Prescaler , u16 TIM_u16DutyCycle ,u16 TIM_u16Period , TIM_ChannelTypeDef TIM_u8Channel)
//{
//	switch(TIM_u8Channel)
//	{
//	case TIM_CHANNEL_1 :
//		//Bit(OC1M) Output compare 1 Preload enable to Select PWM Mode 1 for Channel 1
//		GPTIM2->CCMR1 &=~(1<<4); 		GPTIM2->CCMR1 |= (1<<5) | (1<<6) ;
//		//Set Bit (OC1PE) for Channel 1
//		SET_BIT(GPTIM2->CCMR1 , 3);
//		//Polarity of Channel 1 is active High
//		CLR_BIT(GPTIM2->CCER , 1);
//		//Set Duty Cycle for Channel 1
//		GPTIM2->CCR1 = TIM_u16DutyCycle;
//		//activate Channel 1 Bit 0CC1E: Capture/Compare 1 output enable
//		SET_BIT(GPTIM2->CCER , 0);
//		break;
//	case TIM_CHANNEL_2 :
//
//		break;
//	case TIM_CHANNEL_3 :
//
//		break;
//	case TIM_CHANNEL_4 :
//
//		break;
//	}
//
//
//	//CK_CNT = fCK_PSC/(TIM1->PSC+1)
//	//Counter Clk = ClkFreq/(Prescaler+1)
//	//Set Prescaler
//	GPTIM2->PSC = ( TIM_u16Prescaler - 1 );
//	//Auto reload value
//	GPTIM2->ARR = TIM_u16Period-1;
//	//BIT (ARPE)  Auto-reload preload enable
//	SET_BIT(GPTIM2->CR1 , 7);
//	//Set Bit0 UG to update Counter & Prescaler
//	SET_BIT(GPTIM2->EGR , 0);
//	//Set Bit0 CEN to enable counter
//	SET_BIT(GPTIM2-> CR1, 0);
//}

