/****************************************************************************************/
/*	Author 					: 				John Atia Nafady							*/
/*	Date					: 				9 NOV 2020									*/	
/*	Version					: 				V01											*/	
/*																						*/
/*																						*/
/****************************************************************************************/

#ifndef _USART_INTERFACE_H_
#define _USART_INTERFACE_H_

void MUSART1_voidInit(void);
void MUSART1_voidTransmitChar(u8 Copy_u8Data);
void MUSART1_voidTransmitString(u8 Copy_u8Data[]);
u8	 MUSART1_u8ReceiveChar(void);
u8 	*MUSART1_u8PtrReceiveString(void);
void voidResetArray(u8 *arr);
/*
void MUSART1_voidTransmit(u8 arr[]);
void MUSART1_voidTransmit(u8 arr);
u8	 MUSART1_u8Receive(void);
*/



/********************************************************************************************
 *																					   	 	*
 * 	                                                                                     	*
 *                                                                                       	*
 *                                                                                       	*
 *										 USART2                                  		 	*
 *                                                                                       	*
 *                                                                                       	*
 *                                                                                       	*
 ********************************************************************************************/

void MUSART2_voidInit(void);
void MUSART2_voidTransmitChar(u8 Copy_u8Data);
void MUSART2_voidTransmitString(u8 *Copy_u8Data);
u8	 MUSART2_u8ReceiveChar(void);
u8 	*MUSART2_u8PtrReceiveString(void);


#endif
