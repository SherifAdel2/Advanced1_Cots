/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Sherif Adel
 * @brief          : Main program body to set red led at port A pin 2
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#include "RCC_interface.h"
#include "GPIO_interface.h"

int main(void)
{
	RCC_set_CLK_status(HSI, ON);
	RCC_void_set_SYS_CLK(HSI);
	RCC_APB2_EnableClk(IOPA, ON);

	/* Configuration to set red led at port A pin 2 */
	GPIO_PinConfig_t RED_LED_PIN_Config =
	{
			.Port = PORTA,
			.PinNum = PIN2,
			.Mode = OUTPUT_2MHZ_Push_Pull
	};
	GPIO_u8PinInit(&RED_LED_PIN_Config);

	GPIO_u8SetPinValue(PORTA, PIN2, PIN_LOW);
    /* Loop forever */
	for(;;);
}
