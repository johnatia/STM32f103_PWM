/****************************************************************************************/
/*	Author 					: 				John Atia Nafady							*/
/*	Date					: 				9 OCT 2020									*/	
/*	Version					: 				V01											*/	
/*																						*/
/*																						*/
/****************************************************************************************/

#ifndef _AFIO_PRIVATE_H_
#define _AFIO_PRIVATE_H_

typedef struct{
	
	u32 EVCR;
	u32 MAPR;
	u32 EXTICR[4];
	u32 MAPR2;

	
}AFIO_REG;

#define AFIO 	((volatile AFIO_REG *)0x40010000)
//#define




#endif
