/****************************************************************************************/
/*	Author 					: 				John Atia Nafady							*/
/*	Date					: 				11 OCT 2020									*/	
/*	Version					: 				V01											*/	
/*																						*/
/*																						*/
/****************************************************************************************/

#ifndef _STK_PRIVATE_H_
#define _STK_PRIVATE_H_

void (*Callback)(void);
// Registers											
#define 		STK_BASE_ADDRESS			0xE000E010
#define			STK_CTRL					*((volatile u32*)(STK_BASE_ADDRESS+0x00))
#define			STK_LOAD					*((volatile u32*)(STK_BASE_ADDRESS+0x04))
#define			STK_VAL						*((volatile u32*)(STK_BASE_ADDRESS+0x08))
#define			STK_CALIB					*((volatile u32*)(STK_BASE_ADDRESS+0x0C))

//BITS of STK_CTRL Register
#define			COUNTFLAG					16
#define			CLKSOURCE					2
#define			TICKINT						1
#define			MODE						0


#define 		AHB							0
#define 		AHB_DIV_8					1


#define 		STK_SINGLE_INTERVAL			0
#define 		STK_PERIODIC_INTERVAL		1


#endif
