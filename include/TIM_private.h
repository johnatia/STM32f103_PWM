/****************************************************************************************/
/*	Author 					: 				John Atia Nafady							*/
/*	Date					: 				13 JAN 2021									*/
/*	Version					: 				V01											*/
/*																						*/
/*																						*/
/****************************************************************************************/

#ifndef _TIM_PRIVATE_H_
#define _TIM_PRIVATE_H_

/***********************************************PRIVATE************************************/

typedef struct{
	volatile u32 CR1		;
	volatile u32 CR2		;
	volatile u32 SMCR		;
	volatile u32 DIER		;
	volatile u32 SR			;
	volatile u32 EGR    	;
	volatile u32 CCMR1  	;
    volatile u32 CCMR2  	;
    volatile u32 CCER   	;
    volatile u32 CNT    	;
    volatile u32 PSC    	;
    volatile u32 ARR    	;
	volatile u32 RCR		;		//This Register is for Timer 1 only and Reserved for Timer 2 , 3 , 4
    volatile u32 CCR1   	;
    volatile u32 CCR2   	;
    volatile u32 CCR3   	;
    volatile u32 CCR4   	;
    volatile u32 BDTR 		;		//This Register is for Timer 1 only and Reserved for Timer 2 , 3 , 4
	volatile u32 DCR    	;
	volatile u32 DMAR   	;
}TIMx_t;
#define 		TIM1_BASE_ADDRESS				0x40012C00
#define 		TIM2_BASE_ADDRESS				0x40000000
#define 		TIM3_BASE_ADDRESS				0x40000400
#define 		TIM4_BASE_ADDRESS				0x40000800
#define 		TIM1							((TIMx_t*)(TIM1_BASE_ADDRESS))
#define 		TIM2							((TIMx_t*)(TIM2_BASE_ADDRESS))
#define 		TIM3							((TIMx_t*)(TIM3_BASE_ADDRESS))
#define 		TIM4							((TIMx_t*)(TIM4_BASE_ADDRESS))



//#define 		TIM2							((volatile GPTIM_TypeDef*)(TIM2_BASE_ADDRESS))
#define 		TIM1_SINGLE_INTERVAL			0
#define 		TIM1_PERIODIC_INTERVAL			1
#define 		TIM2_SINGLE_INTERVAL			0
#define 		TIM2_PERIODIC_INTERVAL			1
#define 		TIM3_SINGLE_INTERVAL			0
#define 		TIM3_PERIODIC_INTERVAL			1
#define 		TIM4_SINGLE_INTERVAL			0
#define 		TIM4_PERIODIC_INTERVAL			1

#define 		DOWN_COUNTER					0
#define			UP_COUNTER						1
#define			NO_CLK_DIVISION                 1
#define			CLK_DIVISION_2                  2
#define			CLK_DIVISION_4					4

#endif
/***********************************************PRIVATE************************************/

