/****************************************************************************************/
/*	Author 					: 				John Atia Nafady							*/
/*	Date					: 				11 OCT 2020									*/	
/*	Version					: 				V01											*/	
/*																						*/
/*																						*/
/****************************************************************************************/

#ifndef _STK_INTERFACE_H_
#define _STK_INTERFACE_H_

/*
MSTK_voidInit(): MCAL SysTick Core Peripheral Initialization function returns and takes void
Select Clock
Enable/Disable SysTick Interrupt
Enable/Disable SysTick
*/
void MSTK_voidInit(void);

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);

void Delay(u32 Copy_u32TimeInMicroSeconds);

void MSTK_voidSetSingleInterval(u32 Copy_u32Ticks , void (*Copy_ptr)(void) );

void MSTK_voidSetPeriodicInterval(u32 Copy_u32Ticks , void (*Copy_ptr)(void) );

void MSTK_voidStopInterval(void);

u32 MSTK_u32GetElapsedTime(void);

u32 MSTK_u32GetRemainingTime(void);


#endif
