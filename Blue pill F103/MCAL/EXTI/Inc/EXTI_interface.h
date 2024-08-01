/*
 * EXTI_interface.h
 *
 *  Created on: Jul 30, 2024
 *      Author: Sharif Adel
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#include <stdint.h>

/*******************************************************************************
*                        		Definitions                                    *
*******************************************************************************/
typedef enum
{
	EXTI_ENABLE,
	EXTI_DISABLE
}EXTI_STATE_t;

typedef enum
{
	EXTI0 = 0,   /*!< EXTI Line0 */
	EXTI1,       /*!< EXTI Line1 */
	EXTI2,       /*!< EXTI Line2 */
	EXTI3,       /*!< EXTI Line3 */
	EXTI4,       /*!< EXTI Line4 */
	EXTI5,       /*!< EXTI Line5 */
	EXTI6,       /*!< EXTI Line6 */
	EXTI7,       /*!< EXTI Line7 */
	EXTI8,       /*!< EXTI Line8 */
	EXTI9,       /*!< EXTI Line9 */
	EXTI10,      /*!< EXTI Line10 */
	EXTI11,      /*!< EXTI Line11 */
	EXTI12,      /*!< EXTI Line12 */
	EXTI13,      /*!< EXTI Line13 */
	EXTI14,      /*!< EXTI Line14 */
	EXTI15,      /*!< EXTI Line15 */
	EXTI16,      /*!< EXTI Line16 */
	EXTI17,      /*!< EXTI Line17 */
	EXTI18,      /*!< EXTI Line18 */
	EXTI19 /*!< EXTI Line19 */

} EXTI_LINE_t;

typedef enum
{
	RISING_TRG,
	FALLING_TRG,
	ON_CHANGE_TRG	/* Both rising and falling trigger edge */
}TRIG_SELECT_t;


typedef struct
{
	EXTI_LINE_t		line;
	TRIG_SELECT_t	trigger;
	EXTI_STATE_t	status;
	void (*Copy_PtrFuncEXTI) (void);	/* Pointer to function to be executed when an EXTI happens */
}EXTI_Config_t;


/*******************************************************************************
*                      Functions Prototypes                                   *
*******************************************************************************/

/*******************************************************************************
* Function Name:		EXTI_voidEnableEXTI
* Description:			Function to enable the required external interrupt line
* Parameters (in):    	EXTI_LINE_t
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void EXTI_voidEnableEXTI(EXTI_LINE_t Local_u8Line);

/*******************************************************************************
* Function Name:		EXTI_voidDisableEXTI
* Description:			Function to disable the required external interrupt line
* Parameters (in):    	EXTI_LINE_t
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void EXTI_voidDisableEXTI(EXTI_LINE_t Local_u8Line);

/*******************************************************************************
* Function Name:		EXTI_voidSetTriggerSelection
* Description:			Function to set the required edge of trigger to the external interrupt line
* Parameters (in):    	EXTI_LINE_t, & TRIG_SELECT_t
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void EXTI_voidSetTriggerSelection(EXTI_LINE_t Local_u8Line, TRIG_SELECT_t Local_u8TriggerSelection);

/*******************************************************************************
* Function Name:		EXTI_voidSetSoftwareTrigger
* Description:			Function to set a S.W. trigger to the required external interrupt line
* Parameters (in):    	EXTI_LINE_t
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void EXTI_voidSetSoftwareTrigger(EXTI_LINE_t Local_u8Line);



/*******************************************************************************
* Function Name:		EXTI_voidInit
* Description:			Function to initialize the required interrupt
* Parameters (in):    	Interrupt_t
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void EXTI_voidInit(EXTI_Config_t *Local_PtrEXTIConfg);


/*******************************************************************************
* Function Name:		EXTI_voidClearPendingFlag
* Description:			Function to clear the pending flag of the required external interrupt line
* Parameters (in):    	EXTI_LINE_t
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void EXTI_voidClearPendingFlag(EXTI_LINE_t Local_u8Line);

/*******************************************************************************
* Function Name:		EXTI_voidInit
* Description:			Function to initialize the required interrupt
* Parameters (in):    	Interrupt_t
* Parameters (out):   	uint8_t
* Return value:      	uint8_t
********************************************************************************/
uint8_t EXTI_voidReadPendingFlag(EXTI_LINE_t Local_u8Line);

/*******************************************************************************
* Function Name:		EXTI_voidSetCallBack
* Description:			Function to set a S.W. trigger to the required external interrupt line
* Parameters (in):    	EXTI_LINE_t, & pointer to function for the required ISR f(x) needed
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void EXTI_voidSetCallBack(EXTI_LINE_t Local_u8Line, void (*Local_PtrFunc)(void));


#endif /* EXTI_INTERFACE_H_ */
