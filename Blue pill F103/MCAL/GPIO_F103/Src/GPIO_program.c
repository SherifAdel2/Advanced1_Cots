/*
 * GPIO_program.c
 *
 *  Created on: Jul 11, 2024
 *      Author: Sharif Adel
 */

#include "GPIO_private.h"
#include "GPIO_interface.h"
#include "../Lib/stm32f103xx.h"
#include "../Lib/ErrorType.h"
#include <stdint.h>	/* Contains types as uint8_t , ... */


static GPIO_RegDef_t* GPIOPort[GPIO_PERIPHERAL_NUM] = { GPIOA, GPIOB, GPIOC, GPIOD, GPIOE};


/****************************************************************
 *   @fn         GPIO_u8PinInit
 *   @brief      The function initializes the GPIO pin according to the input parameters
 *   @param[in]  PinConfig: the initialization values of the pin
 *   @retVal     ErrorStatus
*****************************************************************/
uint8_t GPIO_u8PinInit(const GPIO_PinConfig_t* PinConfig)
{
	uint8_t Local_u8ErrorState = OK; /* Used to return the error's value & type. */
	if(PinConfig != NULL)
	{
		if((PinConfig->Port <= PORTE) && (PinConfig->PinNum <= PIN15))	/* Quick check it the I/P is out of band range */
		{
			/*  Mode_t is not fully correct as to handle the case of INPUT Pull Down/UP as they have the same mode bits
			 * in the data sheet */
			uint8_t mode = PinConfig->Mode & MODE_BITS;
			/* Set/Clear ODR bit in case of INPUT Pull Down/UP */
			if(PinConfig->Mode == INPUT_Pull_Down)
			{	/* Clear in case of  Input pull-down */
				GPIOPort[PinConfig->Port]->ODR &= ~(1<< PinConfig->PinNum);
			}
			else if(PinConfig->Mode == INPUT_Pull_Up)
			{
				/* Set in case of  Input pull-Up */
				GPIOPort[PinConfig->Port]->ODR |=  (1<< PinConfig->PinNum);
			}


			if(PinConfig->PinNum < PIN8)
			{

				/* Configure the port mode (I/P or Analog with pull up/down or floating)
				 *  or (O/P or Alternative with open drain or push-pull)
				 *  using register low (GPIOx_CRL),
				 *  W.R.T. input mode value W.R.T. Mode_t ENUM configurations */
				/* First clear the CRL_PIN_ACCESS bits, then second insert the mode value bits */
				GPIOPort[PinConfig->Port]->CRL = ( GPIOPort[PinConfig->Port]->CRL &
						~(CR_MASK << PinConfig->PinNum * CR_PIN_ACCESS) )|
						(mode << PinConfig->PinNum * CR_PIN_ACCESS);
			}
			else
			{

				/* Configure the port mode (I/P or Analog with pull up/down or floating) or
				 * (O/P or Alternative with open drain or push-pull),
				 *  using register low (GPIOx_CRL),
				 *  W.R.T. input mode value W.R.T. Mode_t ENUM configurations */

				/* First clear the CRL_PIN_ACCESS bits, then second insert the mode value bits */
				GPIOPort[PinConfig->Port]->CRH = ( GPIOPort[PinConfig->Port]->CRH &
						~(CR_MASK << PinConfig->PinNum * CR_PIN_ACCESS) )|
						(mode << PinConfig->PinNum * CR_PIN_ACCESS);
			}

		}
		else
		{
			Local_u8ErrorState = OUT_OF_RANGE;
		}
	}
	else
	{
		Local_u8ErrorState =NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}

uint8_t GPIO_u8SetPinValue(Port_t Port,Pin_t PinNum,PinValue_t PinVal)
{
	uint8_t Local_u8ErrorState = OK;
	if (( Port <= PORTE) && ( PinNum <= PIN15))
	{
		switch(PinVal)
		{
		case PIN_LOW:
			(GPIOPort[Port] ->BSRR) = 1<< (16+ PinNum);	/* This is better than the below one as it done in 1 clock cycle */
			/*(GPIOPort[Port] ->ODR) &= ~(ODR_MASK <<PinNum);*/	/* Done in 3 or more clock cycles */
			break;
		case PIN_HIGH:
			(GPIOPort[Port] ->BSRR) = 1<< (PinNum);
			/*(GPIOPort[ Port] -> ODR) |= (PinVal<< PinNum);*/
			break;
		default:
			Local_u8ErrorState = NOK;
			break;
		}
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}

/****************************************************************/
/*   @fn         GPIO_u8TogglePinValue
 *   @brief      The function sets the pin using PinVal
 *   @param[in]  Port: The port number, get options @Port_t enum
 *   @param[in]  PinNum: The pin number, get options @pin_t enum
 *   @retVal     ErrorStatus
 */
uint8_t GPIO_u8TogglePinValue(Port_t Port,Pin_t PinNum)
{
	uint8_t Local_u8ErrorState = OK;
	if (( Port <= PORTE) && ( PinNum <= PIN15))
	{
		GPIOPort[Port]->ODR ^= (ODR_MASK<<PinNum);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}

/****************************************************************/
/*   @fn         GPIO_u8ReadPinValue
 *   @brief      The function sets the pin using PinVal
*    @param[in]  Port: The port number, get options @Port_t enum
 *   @param[in]  PinNum: The pin number, get options @pin_t enum
 *   @retVal     PinVal: The output value, get options @PinVal_t enum
 */
uint8_t GPIO_u8GetPinValue(Port_t Port,Pin_t PinNum,uint8_t *Copy_pu8Result)
{
	uint8_t Local_u8ErrorState = OK;
	if (( Port <= PORTE) && ( PinNum <= PIN15))
	{
		*Copy_pu8Result =IDR_MASK &((GPIOPort[Port] ->IDR)>>PinNum);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}

