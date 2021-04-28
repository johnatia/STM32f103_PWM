/****************************************************************************************/
/*	Author 					: 				John Atia Nafady							*/
/*	Date					: 				9 OCT 2020									*/	
/*	Version					: 				V01											*/	
/*																						*/
/*																						*/
/****************************************************************************************/

#ifndef _AFIO_INTERFACE_H_
#define _AFIO_INTERFACE_H_

#define PA	0
#define PB	1
#define PC	2

typedef enum
{
	//For Timer2:
	//TIM2_REMAP1 is TIM2_CH1_ETR on PA15, TIM2_CH2 on PB3, TIM2_CH3 on PA2, TIM2_CH4 on PA3
	TIM2_REMAP1,
	//TIM2_REMAP2 is  TIM2_CH1_ETR on PA0, TIM2_CH2 on PA1, TIM2_CH3 on PB10, TIM2_CH4 on PB11
	TIM2_REMAP2,
	//TIM2_REMAP3 is TIM2_CH1_ETR on PA15, TIM2_CH2 on PB3, TIM2_CH3 on PB10, TIM2_CH4 on PB11
	TIM2_REMAP3
}TIM_REMAP_t;

typedef enum
{
	TIMER1,
	TIMER2,
	TIMER3,
	TIMER4
}TIM_t;

void MAFIO_voidSetEXTIConfig(u8 Copy_u8Line , u8 Copy_u8PortMap);
/*
 * Copy_u8PortMap could be: PA, PB or PC
 */

/*
 * Copy_u8Line = 0 : 15
 */
void MAFIO_voidTimerRemapPin(TIM_t Timer , TIM_REMAP_t TIM_REMAP);

#endif
