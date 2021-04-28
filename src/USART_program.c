/****************************************************************************************/
/*	Author 					: 				John Atia Nafady							*/
/*	Date					: 				9 NOV 2020									*/	
/*	Version					: 				V01											*/	
/*																						*/
/*																						*/
/****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"


void MUSART1_voidInit(void)
{
	u64 Mantissa = F_CPU/(16*USART1_BAUDRATE);
	f32 Fraction = ( ( F_CPU/(16.0*USART1_BAUDRATE) ) - Mantissa) * 16;
	u8 Fraction_IntegerPart;

	if( Fraction  > 15.0)
	{
		Mantissa++;
		Fraction = 0;
		Fraction_IntegerPart= Fraction;
	}
	else{
		Fraction_IntegerPart = Fraction;
		if( ( (Fraction-Fraction_IntegerPart) * 10) >= 5 )
		{
			Fraction_IntegerPart++;
		}
	}
	//Set BaudRate of USART1
	USART1->BRR = (Mantissa << 4 ) | (Fraction_IntegerPart);

	//for 9600 BAUDRATE -> BRR = 0x341
	//USART1->BRR = 0x341;
	//for 115200 BAUDRATE -> BRR = 0x045
	//USART1->BRR = 0x045;
	//for 250000 BAUDRATE -> BRR = 0x020
	//USART1->BRR = 0x020;
	//Receiver enable
	SET_BIT(USART1->CR1 , 2);
	//Transmitter  enable
	SET_BIT(USART1->CR1 , 3);
	//USART enable
	SET_BIT(USART1->CR1 , 13);
	//Clear Status Register
	USART1->SR = 0;
}

void MUSART1_voidTransmitChar(u8 Copy_u8Data)
{
		USART1->DR = Copy_u8Data;
		//Wait till Transmission complete
		while(GET_BIT(USART1->SR , 6) == 0);
		//Clear TC Flag Bit
		CLR_BIT(USART1->SR , 6);
}

void MUSART1_voidTransmitString(u8 Copy_u8Data[])
{
	u8 i=0;
	while(Copy_u8Data[i] != '\0')
	{
		MUSART1_voidTransmitChar(Copy_u8Data[i]);
		i++;
	}
}

u8	 MUSART1_u8ReceiveChar(void)
{
	u32 timeout = 0;
	u8 Local_u8ReceivedData = 0;
	//Wait till Receive Data From USART
	while(GET_BIT(USART1->SR , 5) == 0)
	{
		timeout++;
		if(timeout == 1000000)
		{
			Local_u8ReceivedData = 255;
			break;
		}
	}
	if(Local_u8ReceivedData == 0)
	{
		//Read Data Register
		Local_u8ReceivedData = USART1->DR;
	}
	//Clear RXNE Flag Bit
	CLR_BIT(USART1->SR , 5);
	//Return Received Data
	return Local_u8ReceivedData;
}

/*
u8	 MUSART1_u8ReceiveChar(void)
{
	//Wait till Receive Data From USART
	while(GET_BIT(USART1->SR , 5) == 0);
	//Clear RXNE Flag Bit
	CLR_BIT(USART1->SR , 5);
	//Return Data Register
	return (USART1->DR);
}
*/



u8 	*MUSART1_u8PtrReceiveString(void)
{
	u8 i=0;
	static u8 Local_u8String[100];

	//Reset Data in the Array
	voidResetArray(Local_u8String);

	while(1)
	{
		Local_u8String[i]=MUSART1_u8ReceiveChar();
		if(Local_u8String[i] == '\n')		{i++;	break;}
		i++;
	}
	Local_u8String[i] = '\0';
	return Local_u8String;
}


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
void MUSART2_voidInit(void)
{
	u64 Mantissa = F_CPU/(16*USART2_BAUDRATE);
	f32 Fraction = ( ( F_CPU/(16.0*USART2_BAUDRATE) ) - Mantissa) * 16;
	u8 Fraction_IntegerPart;

	if( Fraction  > 15.0)
	{
		Mantissa++;
		Fraction = 0;
		Fraction_IntegerPart= Fraction;
	}
	else{
		Fraction_IntegerPart = Fraction;
		if( ( (Fraction-Fraction_IntegerPart) * 10) >= 5 )
		{
			Fraction_IntegerPart++;
		}
	}
	//Set BaudRate of USART2
	USART2->BRR = (Mantissa << 4 ) | (Fraction_IntegerPart);

	//Receiver enable
	SET_BIT(USART2->CR1 , 2);
	//Transmitter  enable
	SET_BIT(USART2->CR1 , 3);
	//USART enable
	SET_BIT(USART2->CR1 , 13);
	//Clear Status Register
	USART2->SR = 0;
}

void MUSART2_voidTransmitChar(u8 Copy_u8Data)
{
		USART2->DR = Copy_u8Data;
		//Wait till Transmission complete
		while(GET_BIT(USART2->SR , 6) == 0);
		//Clear TC Flag Bit
		CLR_BIT(USART2->SR , 6);
}

void MUSART2_voidTransmitString(u8* Copy_u8Data)
{
	u8 i=0;
	while(Copy_u8Data[i] != '\0')
	{
		MUSART2_voidTransmitChar(Copy_u8Data[i]);
		i++;
	}
}

u8	 MUSART2_u8ReceiveChar(void)
{
	u32 timeout = 0;
	u8 Local_u8ReceivedData = 0;
	//Wait till Receive Data From USART
	while(GET_BIT(USART2->SR , 5) == 0)
	{
		timeout++;
		if(timeout == 1000000)
		{
			Local_u8ReceivedData = 255;
			break;
		}
	}
	if(Local_u8ReceivedData == 0)
	{
		//Read Data Register
		Local_u8ReceivedData = USART2->DR;
	}
	//Clear RXNE Flag Bit
	CLR_BIT(USART2->SR , 5);
	//Return Received Data
	return Local_u8ReceivedData;
}

u8 	*MUSART2_u8PtrReceiveString(void)
{
	u8 i=0;
	static u8 Local_u8String2[100];

	//Reset Data in the Array
	voidResetArray(Local_u8String2);

	while(1)
	{
		Local_u8String2[i]=MUSART2_u8ReceiveChar();
		if(Local_u8String2[i] == '\n')		{i++;	break;}
		i++;
	}
	Local_u8String2[i] = '\0';
	return Local_u8String2;
}



void voidResetArray(u8 *arr)
{
	u8 i=0;
	while(arr[i] != '\0')
	{
		arr[i]='\0';
		i++;
	}
}
