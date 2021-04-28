/****************************************************************************************/
/*	Author 					: 				John Atia Nafady							*/
/*	Date					: 				3 OCT 2020									*/	
/*	Version					: 				V01											*/	
/*																						*/
/*																						*/
/****************************************************************************************/

#ifndef _NVIC_INTERFACE_H_
#define _NVIC_INTERFACE_H_

void MNVIC_voidEnableInterrupt(u8 Copy_u8PerID);
void MNVIC_voidDisableInterrupt(u8 Copy_u8PerID);
void MNVIC_voidSetPendingFlag(u8 Copy_u8PerID);
void MNVIC_voidClearPendingFlag(u8 Copy_u8PerID);
u8 MNVIC_voidGetActiveFlag(u8 Copy_u8PerID);
void MNVIC_voidSetPriority(s8 Copy_s8InterruptID,u8 Copy_u8GroupPriorty,u8 Copy_u8SubPriorty,u32 Copy_u32Group);



/*********************
 * Priority Options:
 *  NVIC_Group4_SUB0
 *  NVIC_Group3_SUB1
 *  NVIC_Group2_SUB2
 *  NVIC_Group1_SUB3
 *  NVIC_Group0_SUB4
 *********************/

#define NVIC_GROUP_SUB_DISTRIBUTION 		NVIC_GROUP2_SUB2

#define 	NVIC_GROUP4_SUB0			0x05FA0300	// 4 bits for group & 0 bit for sub
#define 	NVIC_GROUP3_SUB1			0x05FA0400	// 3 bits for group & 1 bit for sub
#define 	NVIC_GROUP2_SUB2			0x05FA0500	// 2 bits for group & 2 bit for sub
#define 	NVIC_GROUP1_SUB3			0x05FA0600	// 1 bits for group & 3 bit for sub
#define 	NVIC_GROUP0_SUB4			0x05FA0700	// 0 bits for group & 4 bit for sub


#endif
