/****************************************************************************************/
/*	Author 					: 				John Atia Nafady							*/
/*	Date					: 				29 SEP 2020									*/	
/*	Version					: 				V01											*/	
/*																						*/
/*																						*/
/****************************************************************************************/

#ifndef _RCC_CONFIG_H_
#define _RCC_CONFIG_H_

/****************
clock types options:
 RCC_HSE_CRYSTAL
 RCC_HSE_RC
 RCC_HSI
 RCC_PLL
*******************/
#define RCC_CLOCK_TYPE 			 RCC_HSE_CRYSTAL

/******************
Note: select value if and only if you have selected RCC_PLL as input
clock types options:
RCC_PLL_IN_HSI_DIV_2

RCC_PLL_IN_HSE_DIV_2
RCC_PLL_IN_HSE

RCC_PLL_IN_HSE_RC
RCC_PLL_IN_HSE_CRYSTAL
RCC_PLL_IN_HSE_RC_DIV_2
RCC_PLL_IN_HSE_CRYSTAL_DIV_2
option: PLL multiplication factor = 2 : 16
*******************/
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT			RCC_PLL_IN_HSI_DIV_2
#define RCC_PLL_MUL_VAL			2
#endif





#endif
