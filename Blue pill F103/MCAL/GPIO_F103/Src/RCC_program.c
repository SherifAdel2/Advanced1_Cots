/*
 * RCC_program.c
 *
 *  Created on: Jul 2, 2024
 *      Author: Sharif Adel
 */


/*******************************************************************************
*                        		Inclusions                                     *
*******************************************************************************/
#include "common_macros.h"

//#include "RCC_private.h"
#include "RCC_config.h"
#include "RCC_interface.h"

//#include "../Lib/stm32f103xx.h"


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*******************************************************************************
* Function Name:		RCC_set_CLK_status
********************************************************************************
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Steps: -
 * 1- Set the value of HSITRIM Bits 7:3 to be 16 as there is no error in the clock
 * and CSS ON Bit 19 to enable the clock security system
 * 2- Enable/Disable the given RCC_type
*******************************************************************************/
u8 RCC_set_CLK_status(RCC_type type , RCC_status state)
{
	u32 Local_u32TimeOut = 0;

	/* Step1: - */
	RCC->CR = (RCC->CR & ~(0b11111 << CR_HSITRIM_5_INDEX)) | (RCC_u8_HSI_TRIM << CR_HSITRIM_5_INDEX);
	SET_BIT(RCC->CR, CR_CSSON);

	/* Step 2: - */
	if(type == HSI && state == ON)
	{
		/* Enable HSI clock */
		RCC->CR |= (1<<CR_HSION);	/* In CR Bit 0 HSION: Internal high-speed clock enable */
		while( (GET_BIT(RCC->CR , CR_HSIRDY) == 0) && Local_u32TimeOut < MAX_TimeOut )
		{
			Local_u32TimeOut++;
		}
		if(Local_u32TimeOut == MAX_TimeOut)
		{
			return 0;	// Error as the enabling of the HSI take a long time than expected
		}
	}
	else if(type == HSI && state == OFF)
	{
		/* Disable HSI clock */
		RCC->CR &= ~(1<<CR_HSION);	/*  Bit 0 HSION: Internal high-speed clock enable */
	}
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	else if((type == HSE || type == HSE_Bypass) && state == ON)
	{
		if(type == HSE)
			/* In CR Bit 18 HSEBYP, 0: external 4-16 MHz oscillator not bypassed */
			CLEAR_BIT(RCC->CR,CR_HSEBYP);
		else
			/* In CR Bit 18 HSEBYP, 1: external 4-16 MHz oscillator bypassed with external clock */
			SET_BIT(RCC->CR,CR_HSEBYP);
		SET_BIT(RCC->CR,CR_HSEON);	/*In CR Bit 16 HSEON: HSE clock enable, 1: HSE oscillator ON */
		while( (GET_BIT(RCC->CR, CR_HSERDY)== 0) && Local_u32TimeOut < MAX_TimeOut)
		{
			Local_u32TimeOut++;
		}
		if(Local_u32TimeOut == MAX_TimeOut)
			return 0;	// Error as the enabling of the HSE take a long time than expected
	}
	else if((type == HSE || type == HSE_Bypass) && state == OFF)
	{
		CLEAR_BIT(RCC->CR,CR_HSEON);	/*In CR Bit 16 HSEON: HSE clock enable, 1: HSE oscillator OFF */
	}
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	else if(type == PLL && state == ON)
	{
		SET_BIT(RCC->CR, CR_PLLON);	/* In CR Bit 24 PLLON: PLL enable, 1: PLL ON */
		while( (GET_BIT(RCC->CR, CR_PLLRDY)== 0) && Local_u32TimeOut < MAX_TimeOut)
		{
			Local_u32TimeOut++;
		}
		if(Local_u32TimeOut == MAX_TimeOut)
			return 0;	// Error as the enabling of the HSE take a long time than expected
	}
	else if(type == PLL && state == OFF)
	{
		SET_BIT(RCC->CR, CR_PLLON);	/* In CR Bit 24 PLLON: PLL enable, 1: PLL OFF */
	}
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	else
	{
		return 0;	// Error in data input
	}
	return 1;		// Correct input

}

/*******************************************************************************
* Function Name:		RCC_void_set_CLK
********************************************************************************/
u8 RCC_void_set_SYS_CLK(RCC_type type)
{
	if(type == HSI)
	{
		/* In CFGR Bits 1:0 SW: System clock switch, & 00: HSI selected as system clock */
		CLEAR_BIT(RCC->CFGR, CFGR_SW0);
		CLEAR_BIT(RCC->CFGR, CFGR_SW1);
	}
	else if(type == HSE || type == HSE_Bypass )
	{
		/* In CFGR Bits 1:0 SW: System clock switch, & 01: HSE selected as system clock */
		SET_BIT(RCC->CFGR, CFGR_SW0);
		CLEAR_BIT(RCC->CFGR, CFGR_SW1);
	}
	else if(type == PLL)
	{
		/* In CFGR Bits 1:0 SW: System clock switch, & 10: PLL selected as system clock */
		CLEAR_BIT(RCC->CFGR, CFGR_SW0);
		SET_BIT(RCC->CFGR, CFGR_SW1);
	}
	else
	{
		return 0;	// Error in data input
	}
	return 1;		// Correct input
}

/*******************************************************************************
* Function Name:		RCC_void_HSE_config
********************************************************************************/
void RCC_void_HSE_config(RCC_HSE_config config)
{
	/* In RCC_CFGR : Bit 17 PLLXTPRE: HSE divider for PLL entry */
	RCC->CFGR = (RCC->CFGR & ~(1<<CFGR_PLL_XTRPE)) | (config << CFGR_PLL_XTRPE);
}

/*******************************************************************************
* Function Name:		RCC_void_PLL_config
********************************************************************************/
void RCC_void_PLL_config(RCC_PLL_config config, RCC_PLL_source source)
{
	/* In RCC_CFGR : Bits 21:18 PLLMUL: PLL multiplication factor */
	RCC->CFGR = (RCC->CFGR & ~(0b1111<<CFGR_PLL_MUL_4_INDEX)) | (config << CFGR_PLL_MUL_4_INDEX);
	/* In RCC_CFGR : Bit 16 PLLSRC: PLL entry clock source */
	RCC->CFGR = (RCC->CFGR & ~(1<<CFGR_PLL_SRC)) | (config << CFGR_PLL_SRC);
}

/*******************************************************************************
* Function Name:		RCC_AHB_EnableClk
********************************************************************************/
u8 RCC_AHB_EnableClk(RCC_AHB_peripheral peripheral, RCC_status state)
{
	if(state == ON)
		SET_BIT(RCC->AHBENR, peripheral);
	else if(state == OFF)
		CLEAR_BIT(RCC->AHBENR, peripheral);
	else
	{
		return 0;	// Error in data input
	}
	return 1;		// Correct input
}

/*******************************************************************************
* Function Name:		RCC_APB1_EnableClk
********************************************************************************/
u8 RCC_APB1_EnableClk(RCC_APB1_peripheral peripheral, RCC_status state)
{
	if(state == ON)
		SET_BIT(RCC->APB1ENR, peripheral);
	else if(state == OFF)
		CLEAR_BIT(RCC->APB1ENR, peripheral);
	else
	{
		return 0;	// Error in data input
	}
	return 1;		// Correct input
}

/*******************************************************************************
* Function Name:		RCC_APB2_EnableClk
********************************************************************************/
u8 RCC_APB2_EnableClk(RCC_APB2_peripheral peripheral, RCC_status state)
{
	if(state == ON)
		SET_BIT(RCC->APB2ENR, peripheral);
	else if(state == OFF)
		CLEAR_BIT(RCC->APB2ENR, peripheral);
	else
	{
		return 0;	// Error in data input
	}
	return 1;		// Correct input
}
