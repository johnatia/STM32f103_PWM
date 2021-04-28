/****************************************************************************************/
/*	Author 					: 				John Atia Nafady							*/
/*	Date					: 				9 OCT 2020									*/	
/*	Version					: 				V01											*/	
/*																						*/
/*																						*/
/****************************************************************************************/

#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_


#define RISING_EDGE		 	0
#define FALLING_EDGE		1
#define ON_CHANGE	 		2


void MEXTI_voidInit();
void MEXTI_voidEnableEXTI(u8 Copy_u8Line);
void MEXTI_voidDisableEXTI(u8 Copy_u8Line);
void MEXTI_voidSwTrigger(u8 Copy_u8Line);
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line , u8 Copy_u8Mode);
void MEXTI_voidSetCallBack(void (*ptr)(void) , u8 Copy_u8Line);


#endif
