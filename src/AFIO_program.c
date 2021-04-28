/****************************************************************************************/
/*	Author 					: 				John Atia Nafady							*/
/*	Date					: 				9 OCT 2020									*/	
/*	Version					: 				V01											*/	
/*																						*/
/*																						*/
/****************************************************************************************/

/****************************************************************************************/
/*	Author 					: 				John Atia Nafady							*/
/*	Date					: 				27 MAR 2021									*/
/*	Version					: 				V02											*/
/*																						*/
/*																						*/
/****************************************************************************************/
/*																						*/
/*																						*/	
/*									Not Compeleted										*/	
/*																						*/
/*																						*/
/****************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_private.h"
#include "AFIO_interface.h"
#include "AFIO_config.h"


void MAFIO_voidSetEXTIConfig(u8 Copy_u8Line , u8 Copy_u8PortMap)
{
	
	u8 local_u8Index = (Copy_u8Line/4);
	Copy_u8Line %= 4;
	AFIO->EXTICR[local_u8Index] &= ~(0b1111<<(Copy_u8Line*4));
	AFIO->EXTICR[local_u8Index] |= (Copy_u8PortMap<<(Copy_u8Line*4));
	
	/*
	AFIO->EXTICR[(Copy_u8Line/4)] &= ~(0b1111<<((Copy_u8Line%4)*4));
	AFIO->EXTICR[(Copy_u8Line/4)] &= ~(0b1111<<((Copy_u8Line%4)*4));
	*/
	
	
}

void MAFIO_voidTimerRemapPin(TIM_t Timer , TIM_REMAP_t TIM_REMAP)
{
	if(Timer == TIMER2)
	{
		switch(TIM_REMAP)
		{
		case TIM2_REMAP1:
			CLR_BIT(AFIO->MAPR , 9); SET_BIT(AFIO->MAPR , 8);
			break;
		case TIM2_REMAP2:
			SET_BIT(AFIO->MAPR , 9); CLR_BIT(AFIO->MAPR , 8);
			break;
		case TIM2_REMAP3:
			SET_BIT(AFIO->MAPR , 9); SET_BIT(AFIO->MAPR , 8);
			break;

		}
	}
}


