/*
 * GPIO_program.c
 *
 *  Created on: Jul 11, 2024
 *      Author: Sharif Adel
 */

#include "GPIO_private.h"
#include "GPIO_interface.h"
#include "../Lib/Stm32F446xx.h"
#include "../Lib/ErrorType.h"
#include <stdint.h>	/* Contains types as uint8_t , ... */



static GPIO_RegDef_t* GPIOPort[GPIO_PERIPHERAL_NUM] = { GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF, GPIOG, GPIOH };



/****************************************************************
 *   @fn         GPIO_u8PinInit
 *   @brief      The function initializes the GPIO pin according to the input parameters
 *   @param[in]  PinConfig: the initialization values of the pin
 *   @retVal     ErrorStatus
*****************************************************************/
uint8_t GPIO_u8PinInit(const GPIO_PinConfig_t* PinConfig)
{
	//GPIO_RegDef_t* Local_Selected_Port = (GPIO_RegDef_t*)(uint32_t)(GPIOA_BASE_ADDRESS + (0x400UL * PinConfig->Port));
	uint8_t Local_u8ErrorState = OK;
	if(PinConfig != NULL)
	{
		if((PinConfig->Port <= PORTH) && (PinConfig->PinNum <= PIN15))
		{
			/* Configure the port mode using GPIO port mode register (GPIOx_MODER). */
			GPIOPort[PinConfig->Port]->MODER &= ~(MODER_MASK << (PinConfig->PinNum)*MODER_PIN_ACCESS);
			GPIOPort[PinConfig->Port]->MODER |=  (PinConfig->Mode << (PinConfig->PinNum)*MODER_PIN_ACCESS);

			/* Configure the I/O pull-up or pull-down using GPIO port pull-up/pull-down register (GPIOx_PUPDR) */
			GPIOPort[PinConfig->Port]->PUPDR &= ~(PUPDR_MASK << (PinConfig->PinNum)*PUPDR_PIN_ACCESS);
			GPIOPort[PinConfig->Port]->PUPDR |=  (PinConfig->PullType << (PinConfig->PinNum)*PUPDR_PIN_ACCESS);

			/* Select GPIO Output type & Output speed in case of general purpose output or Alternate function */
			if((PinConfig->Mode == OUTPUT) || (PinConfig->Mode == ALTERNATE_FUNCTION))
			{
				/* Configure the output type of the I/O port using GPIO port output type register  (GPIOx_OTYPER). */
				GPIOPort[PinConfig->Port]->OTYPER &= ~(OTYPER_MASK << (PinConfig->PinNum));
				GPIOPort[PinConfig->Port]->OTYPER |=  (PinConfig->OutputType << (PinConfig->PinNum));

				/*  Configure the I/O output speed using GPIO port output speed register (GPIOx_OSPEEDR) */
				GPIOPort[PinConfig->Port]->OSPEEDR &= ~(OPSEEDR_MASK << (PinConfig->PinNum)*OPSEEDR_PIN_ACCESS);
				GPIOPort[PinConfig->Port]->OSPEEDR |=  (PinConfig->Speed << (PinConfig->PinNum)*OPSEEDR_PIN_ACCESS);
				if(PinConfig ->Mode == ALTERNATE_FUNCTION)
				{
					uint8_t Local_u8RegNum =(PinConfig ->PinNum / AFR_PIN_SHIFTING);
					uint8_t Local_u8BitNum =(PinConfig ->PinNum % AFR_PIN_SHIFTING);
					(GPIOPort[PinConfig -> Port] -> AFR[Local_u8RegNum]) &= ~(AFR_MASK << (Local_u8BitNum * AFR_PIN_ACCESS));
					(GPIOPort[PinConfig -> Port] -> AFR[Local_u8RegNum]) |= ((PinConfig->AltFunc) << (Local_u8BitNum * AFR_PIN_ACCESS));
				}
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

uint8_t GPIO_u8SetPinValue(Port_t Port,Pin_t PinNum,PinVal_t PinVal)
{
	uint8_t Local_u8ErrorState = OK;
	if (( Port <= PORTH) && ( PinNum <= PIN15))
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
	if (( Port <= PORTH) && ( PinNum <= PIN15))
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
	if (( Port <= PORTH) && ( PinNum <= PIN15))
	{
		*Copy_pu8Result =IDR_MASK &((GPIOPort[Port] ->IDR)>>PinNum);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}

