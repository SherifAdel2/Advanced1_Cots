/*
 * AFIO_interface.h
 *
 *  Created on: Aug 1, 2024
 *      Author: Sharif Adel
 */

#ifndef AFIO_INTERFACE_H_
#define AFIO_INTERFACE_H_


/*******************************************************************************
*                        		Definitions                                    *
*******************************************************************************/
typedef enum
{
    EXTI_LINE0 = 0,
    EXTI_LINE1,
    EXTI_LINE2,
    EXTI_LINE3,
    EXTI_LINE4,
    EXTI_LINE5,
    EXTI_LINE6,
    EXTI_LINE7,
    EXTI_LINE8,
    EXTI_LINE9,
    EXTI_LINE10,
    EXTI_LINE11,
    EXTI_LINE12,
    EXTI_LINE13,
    EXTI_LINE14,
    EXTI_LINE15
} EXTI_t;

typedef enum
{
    GPIO_PORTA = 0,
    GPIO_PORTB,
    GPIO_PORTC,
    GPIO_PORTD,
    GPIO_PORTE,
    GPIO_PORTF,
    GPIO_PORTG,
} GPIO_PORT_t;

/*******************************************************************************
*                      Functions Prototypes                                   *
*******************************************************************************/

/*******************************************************************************
* Function Name:		AFIO_u8SetEXTIPortSource
* Description:			Function to set the port source of EXTIx
* Parameters (in):    	EXTI_t --> The EXTI number
* 						GPIO_PORT_t --> The required Port
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
u8 AFIO_u8SetEXTIPortSource(EXTI_t Local_u8Line, GPIO_PORT_t Local_u8port);

#endif /* AFIO_INTERFACE_H_ */
