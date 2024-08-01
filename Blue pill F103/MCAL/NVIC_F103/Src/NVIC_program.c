/*
 * NVIC_program.c
 *
 *  Created on: Jul 24, 2024
 *      Author: Sharif Adel
 */



/*******************************************************************************
*                        		Inclusions                                     *
*******************************************************************************/
#include <stdint.h>
#include "../Lib/STD_TYPES.h"
#include "../Lib/common_macros.h"
#include "../LIB/stm32f103xx.h"
#include "NVIC_private.h"
#include "NVIC_interface.h"

/*******************************************************************************
*                           Global Variables                                  *
*******************************************************************************/



/*******************************************************************************
*                      Functions Definitions                                   *
*******************************************************************************/

/*******************************************************************************
* Function Name:		NVIC_vEnableInterrupt
* Description:			Function to enable the required interrupt
* Parameters (in):    	Interrupt_t
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void NVIC_vEnableInterrupt(Interrupt_t copy_eInterrupt)
{
	/*
	uint8_t Local_u8BitNum = copy_eInterrupt % 32;		// Calculate the required bit number
	uint8_t Local_u8RegNum = copy_eInterrupt / 32;		// Calculate the required bit number

	NVIC->ISER[Local_u8RegNum] = (1<< Local_u8BitNum);	// Set the required bit in the required register number in ISER to enable the interrupt for the required interrupt given
	*/

	/* This line  */
	NVIC->NVIC_ISER[copy_eInterrupt / NUMBER_OF_REGISTER_BITS] =
			( ONE_BIT_MASK << (copy_eInterrupt % NUMBER_OF_REGISTER_BITS) );
}



/*  NOTEEEE : most of the implementation of the functions will be the same as the one of  NVIC_vEnableInterrupt */



/*******************************************************************************
* Function Name:		NVIC_vDisableInterrupt
* Description:			Function to disable the required interrupt
* Parameters (in):    	Interrupt_t
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void NVIC_vDisableInterrupt(Interrupt_t copy_eInterrupt)
{
	NVIC->NVIC_ICER[copy_eInterrupt / NUMBER_OF_REGISTER_BITS] =
			( ONE_BIT_MASK << (copy_eInterrupt % NUMBER_OF_REGISTER_BITS) );
}

/*******************************************************************************
* Function Name:		NVIC_vSetPendingFlag
* Description:			Function to set the pending flag of the required interrupt
* Parameters (in):    	Interrupt_t
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void NVIC_vSetPendingFlag(Interrupt_t copy_eInterrupt)
{
	NVIC->NVIC_ISPR[copy_eInterrupt / NUMBER_OF_REGISTER_BITS] =
			( ONE_BIT_MASK << (copy_eInterrupt % NUMBER_OF_REGISTER_BITS) );
}

/*******************************************************************************
* Function Name:		NVIC_vClearPendingFlag
* Description:			Function to clear the pending flag of the required interrupt
* Parameters (in):    	Interrupt_t
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void NVIC_vClearPendingFlag(Interrupt_t copy_eInterrupt)
{
	NVIC->NVIC_ICPR[copy_eInterrupt / NUMBER_OF_REGISTER_BITS] =
			( ONE_BIT_MASK << (copy_eInterrupt % NUMBER_OF_REGISTER_BITS) );
}

/*******************************************************************************
* Function Name:		NVIC_vGetActiveFlag
* Description:			Function to get the active flag of the required interrupt
* Parameters (in):    	Interrupt_t, and a pointer(*) of uint8_t for the flag status
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void NVIC_vGetActiveFlag(Interrupt_t copy_eInterrupt, uint8_t *copy_u8flagStatus)
{
	*copy_u8flagStatus= GET_BIT(NVIC->NVIC_IABR[copy_eInterrupt / NUMBER_OF_REGISTER_BITS],
			(copy_eInterrupt % NUMBER_OF_REGISTER_BITS) );
}

/*******************************************************************************
* Function Name:		NVIC_vSetPriorityCfg
* Description:			Function to set the priority control flag of the required interrupt
* Parameters (in):    	Interrupt_t
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void NVIC_vSetPriorityCfg(NVIC_GroupPriorityCfg copy_eGroupPriorityCfg)
{
	SCB->AIRCR = (VECTKEY << VECTKEY_PIN_ACCESS) | (copy_eGroupPriorityCfg << GROUP_PIN_ACCESS);
}

/*******************************************************************************
* Function Name:		NVIC_vSetInterruptPriority
* Description:			Function to set the interrupt priority of the required interrupt
* Parameters (in):    	Interrupt_t, and a uint8_t of the priority number
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void NVIC_vSetInterruptPriority(Interrupt_t copy_eInterrupt,uint8_t copy_u8Priority)
{
	if(copy_eInterrupt < 0)
	{

	}
	else if (copy_eInterrupt >= 0)
	{
		NVIC->NVIC_IPR[copy_eInterrupt] = copy_u8Priority << API_VALID_BITS_MASK;
	}
}

