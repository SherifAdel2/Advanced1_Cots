

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

/*******************************************************************************
*                        		Definitions                                    *
*******************************************************************************/
//******************************* Clock Source ********************************
typedef enum
{
	EXTERNAL_AHB_PRE_8,
	PROCESSOR_CLOCK_AHB
}STK_CLKSOURCE;

/*typedef enum
{
	ENABLE,
	DISABLE
}STK_STATE; */
/*******************************************************************************
*                      		 Functions Prototypes                              *
*******************************************************************************/

/*******************************************************************************
* Function Name:		STK_u8Init
* Description:			Function to init the systick clock source while it's disabled
* Parameters (in):    	STK_CLKSOURCE
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
u8 STK_u8Init(const STK_CLKSOURCE ClockSource);

/*******************************************************************************
* Function Name:		STK_u8SetuSBusyWait
* Description:			Function to create microsecond delay with the systick timer
* Parameters (in):    	The number of ticks required to delay
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/

/*******************************************************************************
* Function Name:		STK_u8Disbale
* Description:			Function to stop and disable the systick timer
* Parameters (in):    	void
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
void STK_u8Disbale(void);

/*******************************************************************************
* Function Name:		STK_u8SetuSBusyWait
* Description:			Function to create a one microsecond delay with the systick timer
* Parameters (in):    	The number of ticks required to delay
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
u8 STK_u8SetuSBusyWait(u32 Copy_u32TimeInUs);

/*******************************************************************************
* Function Name:		STK_u8SetmSBusyWait
* Description:			Function to create millisecond delay with the systick timer
* Parameters (in):    	The number of ticks required to delay
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
u8 STK_u8SetmSBusyWait(u32 Copy_u32msTime);

/*******************************************************************************
* Function Name:		STK_u8SetIntervalSingle
* Description:			Function to create single shot interrupt
* Parameters (in):    	The number of ticks required to fire the interrupt
* 						Pointer to fuction to be the systick handler
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
u8 STK_u8SetIntervalSingle(u32 Copy_u32NumOfTicks, void(*Copy_pf)(void));

/*******************************************************************************
* Function Name:		STK_u8SetIntervalPeriodic
* Description:			Function to create periodic interrupt
* Parameters (in):    	The number of ticks required to fire the interrupt
* 						Pointer to fuction to be the systick handler
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
u8 STK_u8SetIntervalPeriodic(u32 Copy_u32NumOfTicks, void(*Copy_pf)(void));



/*******************************************************************************
* Function Name:		STK_u8GetElapsedTime
* Description:			Function to calculate the elapsed time
* Parameters (in):    	Pointer to variable to save the elapsed time in it
* Parameters (out):   	void
* Return value:      	None
********************************************************************************/
u8 STK_u8GetElapsedTime      (u32 * Copy_pu32ElapsedTime);

/*******************************************************************************
* Function Name:		STK_u8GetRemainingTime
* Description:			Function to calculate the remaining time
* Parameters (in):    	Pointer to variable to save the remaining time in it
* Parameters (out):   	void
* Return value:      	None
********************************************************************************/
u8 STK_u8GetRemainingTime    (u32 * Copy_pu32RemainingTime);

#endif
