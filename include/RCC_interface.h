/****************************************************************************************/
/*	Author 					: 				John Atia Nafady							*/
/*	Date					: 				29 SEP 2020									*/	
/*	Version					: 				V01											*/	
/*																						*/
/*																						*/
/****************************************************************************************/

#ifndef _RCC_INTERFACE_H_
#define _RCC_INTERFACE_H_

#define 				RCC_AHB 				0
#define 				RCC_APB1 				1
#define 				RCC_APB2 				2


void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(u8 Copy_u8BusID,u8 Copy_u8PerID);
void RCC_voidDisableClock(u8 Copy_u8BusID,u8 Copy_u8PerID);

#endif
