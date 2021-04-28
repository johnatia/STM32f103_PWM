/****************************************************************************************/
/*	Author 					: 				John Atia Nafady							*/
/*	Date					: 				13 JAN 2021									*/
/*	Version					: 				V01											*/
/*																						*/
/*																						*/
/****************************************************************************************/

#ifndef _TIM_CONFIG_H_
#define _TIM_CONFIG_H_
/*
select COUNTER_MODE to:
UP_COUNTER
DOWN_COUNTER
*/
#define COUNTER_MODE					UP_COUNTER
#define SYSTEM_CLK   					8000000
/*
 * you can Select between:
 * NO_CLK_DIVISION
 * CLK_DIVISION_2
 * CLK_DIVISION_4
 */
#define SYSTEM_CLK_DIVISION				NO_CLK_DIVISION

#endif
