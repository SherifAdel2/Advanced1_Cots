
/*******************************************************************************
*                        		Inclusions                                     *
*******************************************************************************/
#include "../Lib/common_macros.h"
#include "../Lib/STD_TYPES.h"
#include "../Lib/common_macros.h"
#include "../LIB/stm32f103xx.h"

#include "STK_interface.h"
#include "STK_private.h"

/*******************************************************************************
*                           Global Variables                                  *
*******************************************************************************/



/*******************************************************************************
*                      Functions Definitions                                   *
*******************************************************************************/

/*******************************************************************************
* Function Name:		STK_u8Init
* Description:			Function to init the systick clock source while it's disabled
* Parameters (in):    	STK_CLKSOURCE
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
u8 STK_u8Init(const STK_CLKSOURCE ClockSource)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if(ClockSource == EXTERNAL_AHB_PRE_8)
	{
		CLEAR_BIT(STK->CTRL,CTRL_CLKSOURCE_BIT);
	}
	else if(ClockSource == PROCESSOR_CLOCK_AHB)
	{
		SET_BIT(STK->CTRL,CTRL_CLKSOURCE_BIT);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}


/*******************************************************************************
* Function Name:		STK_u8Stop
* Description:			Function to stop and disable the systick timer
* Parameters (in):    	void
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
void STK_u8Disbale(void)
{
	/* Clear enable bit to disable the systick timer */
	CLEAR_BIT(STK->CTRL, CTRL_ENABLE_BIT);
	/* Disable exception */
	CLEAR_BIT(STK->CTRL, CTRL_TICK_INT_BIT);


	/* Make it equal zero as a write of any value clears the field to 0, and also clears the COUNTFLAG bit in the
	STK_CTRL register to 0. */
	STK->VAL =  0;

	/* A start value of 0 is possible, but has no effect because the SysTick exception request and COUNTFLAG are
	activated when counting from 1 to 0 */
	STK->LOAD = 0;
}

/*******************************************************************************
* Function Name:		STK_u8SetuSBusyWait
* Description:			Function to create a one microsecond delay with the systick timer
* Parameters (in):    	The number of ticks required to delay
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
u8 STK_u8SetuSBusyWait(u32 Copy_u32Time_us)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u32 Local_u32LoadValue;

	/* NOTE:-
	If i need to reload the load R. with a value that make the flag set for the first time after 1 second
	i need to but a value that is equal to the value of the system Frequency (F_CPU) as
	the time for an increment/decrement in the timer is equal to 1/F_CPU
	so by multiply F_CPU * 1/F_CPU the result will be equal 1
	and the equation is: -
	Number of overflow/underflow = (Needed time in seconds) / (Resolution{value of LOAD R.} * time for 1 increment/decrement)
	so in the numerator up if i want 1 Ms that = 1 * 10^-3, so  we will get in the denumerator
	10^3 * (Resolution{value of LOAD R.} * time for 1 increment/decrement), and 10^6 for millisecond */

	if( GET_BIT(STK->CTRL, CTRL_CLKSOURCE_BIT) )
	{
		/* PROCESSOR_CLOCK_AHB */
		Local_u32LoadValue = (F_CPU / 1000000) * Copy_u32Time_us;	/* 8 00 000 come from the numerator 1 microsecond = 10^-6 seconds */
	}
	else
	{
		/* EXTERNAL_AHB_PRE_8 */
		/* 8 00 000 come from the numerator 1 microsecond = 10^-6 seconds
		   and the pre-scaler = 8 */
		Local_u32LoadValue = (F_CPU / 8000000) * Copy_u32Time_us;	/* 1 00 000 come from the numerator 1 microsecond = 10^-6 seconds */
		/* Note : F_CPU/ 1 000 000 = T_timer * 1 000 000 */
	}

	if(Local_u32LoadValue <= MAX_RELOAD_VALUE_REGISTER)
	{
		/* Disable exception */
		CLEAR_BIT(STK->CTRL, CTRL_TICK_INT_BIT);
		/* Load the required delay in  */
		STK->LOAD = Local_u32LoadValue;
		/* Enable the timer */
		SET_BIT(STK->CTRL, CTRL_ENABLE_BIT);
		/* Make it equal zero as a write of any value clears the field to 0, and also clears the COUNTFLAG bit in the
		STK_CTRL register to 0. */
		STK->VAL =  0;
		/* Wait until timer reach zero and COUNTER flag bit set to one */
		while(GET_BIT(STK->CTRL, CTRL_COUNTER_FLAG) == 0);
		/* Disable the timer */
		STK_u8Disbale();
	}
	else
		Local_u8ErrorState = STD_TYPES_NOK;
	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		STK_u8SetmSBusyWait
* Description:			Function to create millisecond delay with the systick timer
* Parameters (in):    	The number of ticks required to delay
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
u8 STK_u8SetmSBusyWait(u32 Copy_u32Time_ms)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	for(u32 i = 0 ; i < Copy_u32Time_ms ; i++)
	{
		STK_u8SetuSBusyWait(1000);
	}

	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		STK_u8SetIntervalSingle
* Description:			Function to create single shot interrupt
* Parameters (in):    	The number of ticks required to fire the interrupt
* 						Pointer to fuction to be the systick handler
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
u8 STK_u8SetIntervalSingle(u32 Copy_u32Time_us, void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;



	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		STK_u8SetIntervalPeriodic
* Description:			Function to create periodic interrupt
* Parameters (in):    	The number of ticks required to fire the interrupt
* 						Pointer to fuction to be the systick handler
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
u8 STK_u8SetIntervalPeriodic(u32 Copy_u32Time_us, void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;



	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		STK_u8GetElapsedTime
* Description:			Function to calculate the elapsed time
* Parameters (in):    	Pointer to variable to save the elapsed time in it
* Parameters (out):   	void
* Return value:      	None
********************************************************************************/
u8 STK_u8GetElapsedTime(u32 * Copy_pu32ElapsedTime)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if(Copy_pu32ElapsedTime != NULL)
	{
		*Copy_pu32ElapsedTime = (STK->LOAD - STK->VAL) ;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		STK_u8GetRemainingTime
* Description:			Function to calculate the remaining time
* Parameters (in):    	Pointer to variable to save the remaining time in it
* Parameters (out):   	void
* Return value:      	None
********************************************************************************/
u8 STK_u8GetRemainingTime    (u32 * Copy_pu32RemainingTime)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if(Copy_pu32RemainingTime != NULL)
	{
		*Copy_pu32RemainingTime = STK->VAL ;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}

/*******************************************************************************
*                       Interrupt Service Routines                            *
*******************************************************************************
void SysTick_Handler(void)
{
	if(STK_u8ModeOfInterval == STK_u8_SINGLE_INTERVAL)
	{
		/* Disable and Stop The Timer *
		CLR_BIT(STK->CTRL,0);
		CLR_BIT(STK->CTRL,1);
		STK->LOAD = 0;
		STK->VAL  = 0;
	}
	if(STK_Pf != NULL)
	{
		STK_Pf();
	}
	/* Clear The Interrupt Flag *
	CLR_BIT(STK->CTRL,16);
}
*/
