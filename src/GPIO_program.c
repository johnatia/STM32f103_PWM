/****************************************************************************************/
/*	Author 					: 				John Atia Nafady							*/
/*	Date					: 				1 OCT 2020									*/	
/*	Version					: 				V01											*/	
/*																						*/
/*																						*/
/****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "GPIO_interface.h"
#include "GPIO_config.h"
#include "GPIO_private.h"

void gPIO_voidSetPinDir(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
	switch(Copy_u8Port)
	{
		case GPIOA:
			if(Copy_u8Pin<8)
			{
				GPIOA_CRL &= ~((0x0f)<<(Copy_u8Pin*4));
				GPIOA_CRL |= ((Copy_u8Mode)<<(Copy_u8Pin*4));
			}
			else if(Copy_u8Pin<16)
			{
				GPIOA_CRH &= ~((0x0f)<<((Copy_u8Pin-8)*4));
				GPIOA_CRH |= ((Copy_u8Mode)<<((Copy_u8Pin-8)*4));
			}
			break;
		
		case GPIOB:
			if(Copy_u8Pin<8)
			{
				GPIOB_CRL &= ~((0x0f)<<(Copy_u8Pin*4));
				GPIOB_CRL |= ((Copy_u8Mode)<<(Copy_u8Pin*4));
			}
			else if(Copy_u8Pin<16)
			{
				GPIOB_CRH &= ~((0x0f)<<((Copy_u8Pin-8)*4));
				GPIOB_CRH |= ((Copy_u8Mode)<<((Copy_u8Pin-8)*4));
			}
			break;
		
		case GPIOC:
			if(Copy_u8Pin<8)
			{
				GPIOC_CRL &= ~((0x0f)<<(Copy_u8Pin*4));
				GPIOC_CRL |= ((Copy_u8Mode)<<(Copy_u8Pin*4));
			}
			else if(Copy_u8Pin<16)
			{
				GPIOC_CRH &= ~((0x0f)<<((Copy_u8Pin-8)*4));
				GPIOC_CRH |= ((Copy_u8Mode)<<((Copy_u8Pin-8)*4));
			}
			break;
	}
	
}

void gPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	switch(Copy_u8Port)
	{
		case GPIOA:
			if(Copy_u8Value == HIGH)
			{
				SET_BIT(GPIOA_ODR, Copy_u8Pin);
			}
			else if(Copy_u8Value == LOW)
			{
				CLR_BIT(GPIOA_ODR, Copy_u8Pin);
			}
			break;
		case GPIOB:
			if(Copy_u8Value == HIGH)
			{
				SET_BIT(GPIOB_ODR, Copy_u8Pin);
			}
			else if(Copy_u8Value == LOW)
			{
				CLR_BIT(GPIOB_ODR, Copy_u8Pin);
			}
			break;
		
		case GPIOC:
			if(Copy_u8Value == HIGH)
			{
				SET_BIT(GPIOC_ODR, Copy_u8Pin);
			}
			else if(Copy_u8Value == LOW)
			{
				CLR_BIT(GPIOC_ODR, Copy_u8Pin);
			}
			break;
		
	}
}

u8 gPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 local_u8Result=0;
	switch(Copy_u8Port)
	{
		case GPIOA:
			local_u8Result=GET_BIT(GPIOA_IDR,Copy_u8Pin);
			break;
		case GPIOB:
			local_u8Result=GET_BIT(GPIOB_IDR,Copy_u8Pin);
			break;
		
		case GPIOC:
			local_u8Result=GET_BIT(GPIOC_IDR,Copy_u8Pin);
			break;
	}
	return local_u8Result;

}

/*
u8 gPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
		case GPIOA:
			return GET_BIT(GPIOA_IDR,Copy_u8Pin);
			break;
		case GPIOB:
			return GET_BIT(GPIOB_IDR,Copy_u8Pin);
			break;
		
		case GPIOC:
			return GET_BIT(GPIOC_IDR,Copy_u8Pin);
			break;
	}
}

*/

