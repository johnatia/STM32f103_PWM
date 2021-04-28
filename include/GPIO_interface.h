/****************************************************************************************/
/*	Author 					: 				John Atia Nafady							*/
/*	Date					: 				1 OCT 2020									*/	
/*	Version					: 				V01											*/	
/*																						*/
/*																						*/
/****************************************************************************************/

#ifndef _GPIO_INTERFACE_H_
#define _GPIO_INTERFACE_H_

#define GPIOA 		0
#define GPIOB 		1
#define GPIOC		2

#define PIN0		0
#define PIN1		1
#define PIN2		2
#define PIN3		3
#define PIN4		4
#define PIN5		5
#define PIN6		6
#define PIN7		7
#define PIN8		8
#define PIN9		9
#define PIN10		10
#define PIN11		11
#define PIN12		12
#define PIN13		13
#define PIN14		14
#define PIN15		15

/* Modes & Configurations 													*/
/* For INPUT																*/
#define IN_ANALOG								0b0000
#define IN_FLOATING 							0b0100
#define IN_ANALOG								0b0000
#define IN_PULLUP_PULLDOWN						0b1000
/* For Genral Purpose OUTPUT, there're Push-Pull & Open_Drain				*/
#define OUT_PUSHPULL_10MHz						0b0001
#define OUT_PUSHPULL_2MHz						0b0010
#define OUT_PUSHPULL_50MHz						0b0011
/* Remains Alternate Function OUTPUT, there're Push-Pull & Open_Drain		*/
#define ALTRNATIVE_FUNC_PUSHPULL				0b1011

#ifndef	LOW
#define LOW				0
#endif
#ifndef	HIGH
#define HIGH 			1
#endif

void gPIO_voidSetPinDir(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);
void gPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
u8 gPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);


#endif
