/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    22 JULY 2023	           		 		*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 RCC									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/


/********************************************************************************************/
/* Include libraries                                                                        */
/********************************************************************************************/
#include <stdint.h>
#include <stdio.h>

#include "../../LIB/Stm32F466xx.h"
#include "../../LIB/ErrorType.h"
#include "../../LIB/Utils.h"

/********************************************************************************************/
/* Include Component Files                                                                  */
/********************************************************************************************/
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_AHB1EnableCLK(PeripheralAHB1_t peripheral)
{
	SET_BIT(RCC->AHB1ENR,peripheral);
}

void RCC_AHB1DisableCLK(PeripheralAHB1_t peripheral)
{
	CLR_BIT(RCC->AHB1ENR,peripheral);
}

void RCC_AHB2EnableCLK(PeripheralAHB2_t peripheral)
{
	SET_BIT(RCC->AHB2ENR,peripheral);
}
void RCC_AHB2DisableCLK(PeripheralAHB2_t peripheral)
{
	CLR_BIT(RCC->AHB2ENR,peripheral);
}

void RCC_APB1EnableCLK(PeripheralAPB1_t peripheral)
{
	SET_BIT(RCC->APB1ENR,peripheral);
}

void RCC_APB1DisableCLK(PeripheralAPB1_t peripheral)
{
	CLR_BIT(RCC->APB1ENR,peripheral);
}

void RCC_APB2EnableCLK(PeripheralAPB2_t peripheral)
{
	SET_BIT(RCC->APB2ENR,peripheral);
}

void RCC_APB2DisableCLK(PeripheralAPB2_t peripheral)
{
	CLR_BIT(RCC->APB2ENR,peripheral);
}


