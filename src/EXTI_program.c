/****************************************************************************************/
/*	Author 					: 				John Atia Nafady							*/
/*	Date					: 				9 OCT 2020									*/	
/*	Version					: 				V01											*/	
/*																						*/
/*																						*/
/****************************************************************************************/

/****************************************************************************************/
/*																						*/
/*																						*/	
/*									Not Compeleted										*/	
/*																						*/
/*																						*/
/****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


static void (*EXTI_CallBack[16])(void);

void MEXTI_voidInit()
{
	#if 	EXTI_MODE == RISING_EDGE
		SET_BIT(EXTI -> RTSR , EXTI_LINE);
	#elif 	EXTI_MODE == FALLING_EDGE
		SET_BIT(EXTI -> FTSR , EXTI_LINE);
	#elif 	EXTI_MODE == ON_CHANGE
		SET_BIT(EXTI -> RTSR , EXTI_LINE);	
		SET_BIT(EXTI -> FTSR , EXTI_LINE);	
	#endif
}

void MEXTI_voidEnableEXTI(u8 Copy_u8Line)
{	
	SET_BIT(EXTI->IMR , Copy_u8Line);
}

void MEXTI_voidDisableEXTI(u8 Copy_u8Line)
{
	CLR_BIT(EXTI->IMR , Copy_u8Line);
}

void MEXTI_voidSwTrigger(u8 Copy_u8Line)
{
	SET_BIT(EXTI->IMR , Copy_u8Line);
	CLR_BIT(EXTI->PR , Copy_u8Line); //Set Pending Flag
	SET_BIT(EXTI->SWIER , Copy_u8Line);
}

void MEXTI_voidSetSignalLatch(u8 Copy_u8Line , u8 Copy_u8Mode)
{
	SET_BIT(EXTI->IMR , Copy_u8Line);
	switch(Copy_u8Mode)
	{
		case RISING_EDGE		:		SET_BIT(EXTI -> RTSR , Copy_u8Line);	break;
		case FALLING_EDGE		:		SET_BIT(EXTI -> FTSR , Copy_u8Line);	break;
		case ON_CHANGE			:		SET_BIT(EXTI -> RTSR , Copy_u8Line);
										SET_BIT(EXTI -> FTSR , Copy_u8Line);	break;
	}
}

void MEXTI_voidSetCallBack(void (*ptr)(void) , u8 Copy_u8Line)
{
	EXTI_CallBack[Copy_u8Line]=ptr;
}

void EXTI0_IRQHandler(void)
{
	EXTI_CallBack[0]();
	SET_BIT(EXTI->PR , 0); //Clear Pending Flag
}

void EXTI1_IRQHandler(void)
{
	EXTI_CallBack[1]();
	SET_BIT(EXTI->PR , 1); //Clear Pending Flag
}

void EXTI2_IRQHandler(void)
{
	EXTI_CallBack[2]();
	SET_BIT(EXTI->PR , 2); //Clear Pending Flag
}
