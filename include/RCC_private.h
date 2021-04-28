/****************************************************************************************/
/*	Author 					: 				John Atia Nafady							*/
/*	Date					: 				29 SEP 2020									*/	
/*	Version					: 				V01											*/	
/*																						*/
/*																						*/
/****************************************************************************************/

#ifndef _RCC_PRIVATE_H_
#define _RCC_PRIVATE_H_

/*				REGISTERS DEFINITIONS				*/
#define 					RCC_CR 								*((volatile u32*)0x40021000)
#define 					RCC_CFGR							*((volatile u32*)0x40021004)	
#define 					RCC_CIR 							*((volatile u32*)0x40021008)
#define 					RCC_APB2RSTR						*((volatile u32*)0x4002100C)	
#define 					RCC_APB1RSTR						*((volatile u32*)0x40021010)	
#define 					RCC_AHBENR							*((volatile u32*)0x40021014)	
#define 					RCC_APB2ENR							*((volatile u32*)0x40021018)	
#define 					RCC_APB1ENR							*((volatile u32*)0x4002101C)	
#define 					RCC_BDCR							*((volatile u32*)0x40021020)	
#define 					RCC_CSR								*((volatile u32*)0x40021024)	

#define RCC_HSE_CRYSTAL						0
#define RCC_HSE_RC							1	
#define RCC_HSI								2	
#define RCC_PLL								3

#define RCC_PLL_IN_HSE_RC					0
#define RCC_PLL_IN_HSE_CRYSTAL		  		1
#define	RCC_PLL_IN_HSE_RC_DIV_2			  	2
#define	RCC_PLL_IN_HSE_CRYSTAL_DIV_2		3
#endif
                                    
