/****************************************************************************************/
/*	Author 					: 				John Atia Nafady							*/
/*	Date					: 				9 OCT 2020									*/	
/*	Version					: 				V01											*/	
/*																						*/
/*																						*/
/****************************************************************************************/

#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_

typedef struct{
	
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
	
}EXTI_REG;

#define EXTI 	((volatile EXTI_REG *)0x40010400)

#define RISING_EDGE		 	0
#define FALLING_EDGE		1		
#define ON_CHANGE	 		2	



#endif
