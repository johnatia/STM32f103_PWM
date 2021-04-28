/****************************************************************************************/
/*	Author 					: 				John Atia Nafady							*/
/*	Date					: 				9 NOV 2020									*/	
/*	Version					: 				V01											*/	
/*																						*/
/*																						*/
/****************************************************************************************/

#ifndef _USART_PRIVATE_H_
#define _USART_PRIVATE_H_


typedef struct
{
		volatile u32 SR;
		volatile u32 DR;
		volatile u32 BRR;
		volatile u32 CR1;
		volatile u32 CR2;
		volatile u32 CR3;
		volatile u32 GTPR;
}USART_REG;

#define USART1  		((volatile USART_REG*)0x40013800)
#define USART2  		((volatile USART_REG*)0x40004400)
#define USART3  		((volatile USART_REG*)0x40004800)

#endif
