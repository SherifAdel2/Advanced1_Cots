/*
 * EXTI_program.c
 *
 *  Created on: Jul 30, 2024
 *      Author: Sharif Adel
 */

#include <stdio.h>

#include "../Lib/stm32f103xx.h"
#include "../Lib/ErrorType.h"

#include "EXTI_private.h"
#include "EXTI_interface.h"

/* Local array of pointers to f(x) with length equal to the number of EXTI lines W.R.T. to the line's index */
static void (*EXTI_PTR_TO_FUNCTION[NUMER_OF_EXTI_LINES]) (void) = { NULL };

/*******************************************************************************
* Function Name:		EXTI_voidEnableEXTI
* Description:			Function to enable the required external interrupt line
* Parameters (in):    	EXTI_LINE_t
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void EXTI_voidEnableEXTI(EXTI_LINE_t Local_u8Line)
{
	/* Enable the EXTI line using Interrupt mask register (EXTI_IMR) */
	EXTI->IMR |= (ONE_BIT_MASK << Local_u8Line);
}

/*******************************************************************************
* Function Name:		EXTI_voidDisableEXTI
* Description:			Function to disable the required external interrupt line
* Parameters (in):    	EXTI_LINE_t
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void EXTI_voidDisableEXTI(EXTI_LINE_t Local_u8Line)
{
	/* Disable the EXTI line using Interrupt mask register (EXTI_IMR) */
	EXTI->IMR &= ~(ONE_BIT_MASK << Local_u8Line);
}


/*******************************************************************************
* Function Name:		EXTI_voidSetTriggerSelection
* Description:			Function to set the required detecting edge of trigger to the external external interrupt line
* Parameters (in):    	EXTI_LINE_t, & TRIG_SELECT_t
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void EXTI_voidSetTriggerSelection(EXTI_LINE_t Local_u8Line, TRIG_SELECT_t Local_u8TriggerSelection)
{
	if(Local_u8TriggerSelection == RISING_TRG)
	{
		/* Set Rising Trigger Selection */
		EXTI->RTSR |=  (ONE_BIT_MASK << Local_u8Line);
		/* Clear falling Trigger Selection bit to disable it and make rising detection edge only */
		EXTI->FTSR &= ~(ONE_BIT_MASK << Local_u8Line);
	}
	else if (Local_u8TriggerSelection == FALLING_TRG)
	{
		/* Set Falling Trigger Selection */
		EXTI->FTSR |=  (ONE_BIT_MASK << Local_u8Line);
		/* Clear Rising Trigger Selection bit to disable it and make falling detection edge only */
		EXTI->RTSR &= ~(ONE_BIT_MASK << Local_u8Line);
	}
	else
	{
		/* Set both rising and falling Trigger Selection */
		EXTI->RTSR |=  (ONE_BIT_MASK << Local_u8Line);
		EXTI->FTSR |=  (ONE_BIT_MASK << Local_u8Line);
	}
}


/*******************************************************************************
* Function Name:		EXTI_voidInit
* Description:			Function to initialize the required interrupt W.R.T. required: trigger, enable/disable, call back f(X)
* Parameters (in):    	Interrupt_t
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void EXTI_voidInit(EXTI_Config_t *Local_PtrEXTIConfg)
{
	/* Set the required trigger edge detection */
	EXTI_voidSetTriggerSelection(Local_PtrEXTIConfg->line, Local_PtrEXTIConfg->trigger);


	if(Local_PtrEXTIConfg->status == EXTI_ENABLE)
	{
		/* Enable the EXTI line using Interrupt mask register (EXTI_IMR) */
		EXTI->IMR |=  (ONE_BIT_MASK << Local_PtrEXTIConfg->line);
	}
	else if(Local_PtrEXTIConfg->status == EXTI_DISABLE)
	{
		/* Disable the EXTI line using Interrupt mask register (EXTI_IMR) */
		EXTI->IMR &= ~(ONE_BIT_MASK << Local_PtrEXTIConfg->line);
	}
	/* Initialize Call Back Function */
	EXTI_voidSetCallBack(Local_PtrEXTIConfg->line, Local_PtrEXTIConfg->Copy_PtrFuncEXTI);
}


/*******************************************************************************
* Function Name:		EXTI_voidClearPendingFlag
* Description:			Function to clear the pending flag of the required external interrupt line
* Parameters (in):    	EXTI_LINE_t
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void EXTI_voidClearPendingFlag(EXTI_LINE_t Local_u8Line)
{
	/* Clear Pending Flag */
	EXTI->PR |= (ONE_BIT_MASK << Local_u8Line);
}

/*******************************************************************************
* Function Name:		EXTI_voidInit
* Description:			Function to initialize the required interrupt
* Parameters (in):    	Interrupt_t
* Parameters (out):   	uint8_t
* Return value:      	uint8_t
********************************************************************************/
uint8_t EXTI_voidReadPendingFlag(EXTI_LINE_t Local_u8Line)
{
	/* Return Pending Flag */
	return ( (EXTI->PR >> Local_u8Line) & 0x01 );
}

/*******************************************************************************
* Function Name:		EXTI_voidSetSoftwareTrigger
* Description:			Function to set a S.W. trigger to the required external interrupt line
* Parameters (in):    	EXTI_LINE_t
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void EXTI_voidSetSoftwareTrigger(EXTI_LINE_t Local_u8Line)
{
	EXTI->SWIER |= (ONE_BIT_MASK << Local_u8Line);
}


/*******************************************************************************
* Function Name:		EXTI_voidSetCallBack
* Description:			Function to set a S.W. trigger to the required external interrupt line
* Parameters (in):    	EXTI_LINE_t, & pointer to function for the required ISR f(x) needed
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void EXTI_voidSetCallBack(EXTI_LINE_t Local_u8Line, void (*Local_PtrFunc)(void))
{
	/* Put the input f(x) inside the specific index in our array of pointers W.R.T. given EXTI line as I/P */
	EXTI_PTR_TO_FUNCTION[Local_u8Line] = Local_PtrFunc;
}

/*==============================================================================================================================================
 * HANDLERS SECTION: the ISR when the external interrupt happens
 *==============================================================================================================================================*/

void EXTI0_IRQHandler(void)
{
	/* Clear Pending Flag as it's doesn't cleared by H.W. after entering the ISR */
	EXTI_voidClearPendingFlag(EXTI0);

	/* IF not empty then we passed a needed function from main using EXTI_voidSetCallBack f(x) */
	if (EXTI_PTR_TO_FUNCTION[EXTI0] != NULL)
	{
		EXTI_PTR_TO_FUNCTION[EXTI0]();	/* Make the required f(x) that passed from main using EXTI_voidSetCallBack */
	}
}

void EXTI2_IRQHandler(void)
{
	/* Clear Pending Flag */
	EXTI_voidClearPendingFlag(EXTI2);

	if (EXTI_PTR_TO_FUNCTION[EXTI2] != NULL)
	{
		EXTI_PTR_TO_FUNCTION[EXTI2]();
	}
}

void EXTI3_IRQHandler(void)
{
	/* Clear Pending Flag */
	EXTI_voidClearPendingFlag(EXTI3);

	if (EXTI_PTR_TO_FUNCTION[EXTI3] != NULL)
	{
		EXTI_PTR_TO_FUNCTION[EXTI3]();
	}
}

void EXTI4_IRQHandler(void)
{
	/* Clear Pending Flag */
	EXTI_voidClearPendingFlag(EXTI4);

	if (EXTI_PTR_TO_FUNCTION[EXTI4] != NULL)
	{
		EXTI_PTR_TO_FUNCTION[EXTI4]();
	}
}

void EXTI9_5_IRQHandler(void)
{
	if( EXTI_voidReadPendingFlag(EXTI5) )
	{
		/* Clear Pending Flag as it's doesn't cleared by H.W. after entering the ISR */
		EXTI_voidClearPendingFlag(EXTI5);

		/* IF not empty then we passed a needed function from main using EXTI_voidSetCallBack f(x) */
		if (EXTI_PTR_TO_FUNCTION[EXTI5] != NULL)
		{
			EXTI_PTR_TO_FUNCTION[EXTI5]();	/* Make the required f(x) that passed from main using EXTI_voidSetCallBack */
		}
	}

	else if( EXTI_voidReadPendingFlag(EXTI6) )
	{
		/* Clear Pending Flag as it's doesn't cleared by H.W. after entering the ISR */
		EXTI_voidClearPendingFlag(EXTI6);

		/* IF not empty then we passed a needed function from main using EXTI_voidSetCallBack f(x) */
		if (EXTI_PTR_TO_FUNCTION[EXTI6] != NULL)
		{
			EXTI_PTR_TO_FUNCTION[EXTI6]();	/* Make the required f(x) that passed from main using EXTI_voidSetCallBack */
		}
	}

	else if( EXTI_voidReadPendingFlag(EXTI7) )
	{
		/* Clear Pending Flag as it's doesn't cleared by H.W. after entering the ISR */
		EXTI_voidClearPendingFlag(EXTI7);

		/* IF not empty then we passed a needed function from main using EXTI_voidSetCallBack f(x) */
		if (EXTI_PTR_TO_FUNCTION[EXTI7] != NULL)
		{
			EXTI_PTR_TO_FUNCTION[EXTI7]();	/* Make the required f(x) that passed from main using EXTI_voidSetCallBack */
		}
	}

	else if( EXTI_voidReadPendingFlag(EXTI8) )
	{
		/* Clear Pending Flag as it's doesn't cleared by H.W. after entering the ISR */
		EXTI_voidClearPendingFlag(EXTI8);

		/* IF not empty then we passed a needed function from main using EXTI_voidSetCallBack f(x) */
		if (EXTI_PTR_TO_FUNCTION[EXTI8] != NULL)
		{
			EXTI_PTR_TO_FUNCTION[EXTI8]();	/* Make the required f(x) that passed from main using EXTI_voidSetCallBack */
		}
	}

	else if( EXTI_voidReadPendingFlag(EXTI9) )
	{
		/* Clear Pending Flag as it's doesn't cleared by H.W. after entering the ISR */
		EXTI_voidClearPendingFlag(EXTI9);

		/* IF not empty then we passed a needed function from main using EXTI_voidSetCallBack f(x) */
		if (EXTI_PTR_TO_FUNCTION[EXTI9] != NULL)
		{
			EXTI_PTR_TO_FUNCTION[EXTI9]();	/* Make the required f(x) that passed from main using EXTI_voidSetCallBack */
		}
	}
}

void EXTI15_10_IRQHandler(void)
{
	if( EXTI_voidReadPendingFlag(EXTI10) )
	{
		/* Clear Pending Flag as it's doesn't cleared by H.W. after entering the ISR */
		EXTI_voidClearPendingFlag(EXTI10);

		/* IF not empty then we passed a needed function from main using EXTI_voidSetCallBack f(x) */
		if (EXTI_PTR_TO_FUNCTION[EXTI10] != NULL)
		{
			EXTI_PTR_TO_FUNCTION[EXTI10]();	/* Make the required f(x) that passed from main using EXTI_voidSetCallBack */
		}
	}

	else if( EXTI_voidReadPendingFlag(EXTI11) )
	{
		/* Clear Pending Flag as it's doesn't cleared by H.W. after entering the ISR */
		EXTI_voidClearPendingFlag(EXTI11);

		/* IF not empty then we passed a needed function from main using EXTI_voidSetCallBack f(x) */
		if (EXTI_PTR_TO_FUNCTION[EXTI11] != NULL)
		{
			EXTI_PTR_TO_FUNCTION[EXTI11]();	/* Make the required f(x) that passed from main using EXTI_voidSetCallBack */
		}
	}

	else if( EXTI_voidReadPendingFlag(EXTI12) )
	{
		/* Clear Pending Flag as it's doesn't cleared by H.W. after entering the ISR */
		EXTI_voidClearPendingFlag(EXTI12);

		/* IF not empty then we passed a needed function from main using EXTI_voidSetCallBack f(x) */
		if (EXTI_PTR_TO_FUNCTION[EXTI12] != NULL)
		{
			EXTI_PTR_TO_FUNCTION[EXTI12]();	/* Make the required f(x) that passed from main using EXTI_voidSetCallBack */
		}
	}

	else if( EXTI_voidReadPendingFlag(EXTI13) )
	{
		/* Clear Pending Flag as it's doesn't cleared by H.W. after entering the ISR */
		EXTI_voidClearPendingFlag(EXTI13);

		/* IF not empty then we passed a needed function from main using EXTI_voidSetCallBack f(x) */
		if (EXTI_PTR_TO_FUNCTION[EXTI13] != NULL)
		{
			EXTI_PTR_TO_FUNCTION[EXTI13]();	/* Make the required f(x) that passed from main using EXTI_voidSetCallBack */
		}
	}

	else if( EXTI_voidReadPendingFlag(EXTI14) )
	{
		/* Clear Pending Flag as it's doesn't cleared by H.W. after entering the ISR */
		EXTI_voidClearPendingFlag(EXTI14);

		/* IF not empty then we passed a needed function from main using EXTI_voidSetCallBack f(x) */
		if (EXTI_PTR_TO_FUNCTION[EXTI14] != NULL)
		{
			EXTI_PTR_TO_FUNCTION[EXTI14]();	/* Make the required f(x) that passed from main using EXTI_voidSetCallBack */
		}
	}

	else if( EXTI_voidReadPendingFlag(EXTI15) )
	{
		/* Clear Pending Flag as it's doesn't cleared by H.W. after entering the ISR */
		EXTI_voidClearPendingFlag(EXTI15);

		/* IF not empty then we passed a needed function from main using EXTI_voidSetCallBack f(x) */
		if (EXTI_PTR_TO_FUNCTION[EXTI16] != NULL)
		{
			EXTI_PTR_TO_FUNCTION[EXTI17]();	/* Make the required f(x) that passed from main using EXTI_voidSetCallBack */
		}
	}
}



/*
 *  EXTI line 16 is connected to the PVD output
    EXTI line 17 is connected to the RTC Alarm event
    EXTI line 18 is connected to the USB Wake-up event
 *  EXTI line 19 is connected to the Ethernet Wake-up event available only in connectivity line devices)
*/

/*  EXTI line 16 is connected to the PVD output */
void PVD_IRQHandler(void)
{
	/* Clear Pending Flag */
	EXTI_voidClearPendingFlag(EXTI16);

	if (EXTI_PTR_TO_FUNCTION[EXTI16] != NULL)
	{
		EXTI_PTR_TO_FUNCTION[EXTI16]();
	}
}
/*   EXTI line 17 is connected to the RTC Alarm event
 *  --> RTC alarm through EXTI line interrupt */
void RTCAlarm_IRQHandler(void)
{
	/* Clear Pending Flag */
	EXTI_voidClearPendingFlag(EXTI17);

	if (EXTI_PTR_TO_FUNCTION[EXTI17] != NULL)
	{
		EXTI_PTR_TO_FUNCTION[EXTI17]();
	}
}

/*   EXTI line 18 is connected to the USB Wake-up event
 *  --> USB On-The-Go FS Wake-up through EXTI line interrupt */
void OTG_FS_WKUP_IRQHandler(void)
{
	/* Clear Pending Flag */
	EXTI_voidClearPendingFlag(EXTI18);

	if (EXTI_PTR_TO_FUNCTION[EXTI18] != NULL)
	{
		EXTI_PTR_TO_FUNCTION[EXTI18]();
	}
}

/*   EXTI line 19 is connected to the Ethernet Wake-up event (available only in connectivity */
void ETH_WKUP_IRQHandler(void)
{
	/* Clear Pending Flag */
	EXTI_voidClearPendingFlag(EXTI19);

	if (EXTI_PTR_TO_FUNCTION[EXTI19] != NULL)
	{
		EXTI_PTR_TO_FUNCTION[EXTI19]();
	}
}






