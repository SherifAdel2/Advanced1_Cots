/*
 * AFIO_program.c
 *
 *  Created on: Aug 1, 2024
 *      Author: Sharif Adel
 */

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "../Lib/stm32f103xx.h"

/*******************************************************************************
* Function Name:		AFIO_u8SetEXTIPortSource
* Description:			Function to set the port source of EXTIx
* Parameters (in):    	EXTI_t --> The EXTI number
* 						GPIO_PORT_t --> The required Port
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
void AFIO_u8SetEXTIPortSource(EXTI_t Local_u8Line, GPIO_PORT_t Local_u8port)
{
	/*uint8_t Local_u8RegIndex = Local_u8Line / EXTICR_LINE_BITS;
	uint8_t Local_u8Port_ShiftIndex = (Local_u8port % EXTICR_LINE_BITS_ACCESS) * EXTICR_LINE_BITS_ACCESS;
	AFIO->EXTICR[Local_u8RegIndex] &= ~(EXTICR_LINE_BITS_MASK << Local_u8Port_ShiftIndex);
	AFIO->EXTICR[Local_u8RegIndex] |=  (Local_u8port << Local_u8Port_ShiftIndex);*/

	AFIO->EXTICR[Local_u8Line / EXTICR_LINE_BITS] =
			(  AFIO->EXTICR[Local_u8Line / EXTICR_LINE_BITS] &
			  ~(EXTICR_LINE_BITS_MASK << ( (Local_u8port % EXTICR_LINE_BITS_ACCESS) * EXTICR_LINE_BITS_ACCESS ))
			) |
			(Local_u8port << (Local_u8port % EXTICR_LINE_BITS_ACCESS) * EXTICR_LINE_BITS_ACCESS);

}
