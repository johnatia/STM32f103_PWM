/****************************************************************************************/
/*	Author 					: 				John Atia Nafady							*/
/*	Date					: 				13 JAN 2021									*/
/*	Version					: 				V01											*/
/*																						*/
/*																						*/
/****************************************************************************************/

#ifndef _TIM_INTERFACE_H_
#define _TIM_INTERFACE_H_

#include "TIM_private.h"


//typedef struct{
//
//	void (*CallBack)(void);
//}TIM_HandlerTypeDef;

//typedef struct
//{
//	GPTIM2 TIM2 ;
//
//}HTIM;

typedef	enum
{
	TIM_CHANNEL_1 = 1,
	TIM_CHANNEL_2,
	TIM_CHANNEL_3,
	TIM_CHANNEL_4
}TIM_Channel_t;

typedef enum
{
	ActiveHigh = 0,
	ActiveLow

}TIM_ChannelPolarity_t;

typedef enum
{
	PWM_MODE_1 = 1,
	PWM_MODE_2
}PWM_Mode_t;



void TIM_voidInit(TIMx_t* TIMx);
void TIM_voidSetBusyWait(TIMx_t* TIMx , u16 TIM_u16Prescaler , u16 TIM_u16Ticks );
void TIM_voidSetSingleInterval(TIMx_t* TIMx , u16 TIM_u16Prescaler ,  u16 TIM_u16Ticks , void(*PtrToFunc)(void) );
void TIM_voidSetPeriodicInterval(TIMx_t* TIMx ,  u16 TIM_u16Prescaler , u16 TIM_u16Ticks , void(*PtrToFunc)(void) );
u16  TIM_u16GetElapsedTime(TIMx_t* TIMx);
u16  TIM_u16GetRemainingTime(TIMx_t* TIMx);
void TIM_voidConfigurePWM(TIMx_t* TIMx, TIM_Channel_t TIM_Channel , TIM_ChannelPolarity_t TIM_ChannelPolarity , PWM_Mode_t PWM_Mode);
void TIM_voidSetDutyCycle(TIMx_t* TIMx, TIM_Channel_t TIM_Channel , u16 TIM_u16DutyCycle );
void TIM_voidStartPWM(TIMx_t* TIMx, u16 TIM_u16Prescaler , u16 TIM_u16Period);


//void MCAL_voidTIM_PWM(u32 *TIM_Address , );
//void GPTIM2_voidStartPWM(u16 TIM_u16Prescaler , u16 TIM_u16DutyCycle ,u16 TIM_u16Period , TIM_ChannelTypeDef TIM_u8Channel);



#endif
