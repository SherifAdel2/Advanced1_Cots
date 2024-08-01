/********************************************************************************************/
/********************************************************************************************/
/**************************		Date:					            			*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 GPIO									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#include <stdint.h>


/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	PORTA,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF,
	PORTG,
	PORTH
}Port_t;	/* Number of MC's ports */

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
}Pin_t;		/* Number of MC's pins in one port */

typedef enum
{
	INPUT,
	OUTPUT,
	ALTERNATE_FUNCTION,
	ANALOG
}Mode_t;		/* Used in GPIO port mode register (GPIOx_MODER) */

typedef enum
{
	LOW,
	MEDIUM,
	FAST,
	HIGH
}Output_Speed_t; /* Used in GPIO port output speed register (GPIOx_OSPEEDR) */

typedef enum
{
	PUSH_PULL,
	OPEN_DRAIN
}OutputType_t;	/* Used in GPIO port output type register (GPIOx_OTYPER)R */

typedef enum
{
	NOPULL,
	POLLUP,
	PULLDOWN

}PullUpDown_t;	/* Used in GPIO port pull-up/pull-down register (GPIOx_PUPDR) */

typedef enum
{
	PIN_LOW,
	PIN_HIGH
}PinVal_t;	/* Used to set pin value */

typedef enum
{
	AF0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15
}ALtFunc_t;	/* Used in GPIO alternate function low register (GPIOx_AFRL) & GPIO alternate function high register (GPIOx_AFRH) */

typedef struct
{
	Port_t Port;
	Pin_t PinNum;
	Mode_t Mode;
	Output_Speed_t Speed;
	OutputType_t OutputType;
	PullUpDown_t PullType;
	ALtFunc_t AltFunc;
}GPIO_PinConfig_t;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:		GPIO_u8PinInit
 * Description:			Function to initialize the MC's pin mode in a specific port
 * Parameters (in):    	Pointer of GPIO_PinConfig_t
 * Parameters (out):   	u8
 * Return value:      	OK-->1 or Error-->0
*******************************************************************************/
uint8_t GPIO_u8PinInit(const GPIO_PinConfig_t* PinConfig );

/*******************************************************************************
 * Function Name:		GPIO_u8SetPinValue
 * Description:			Function to set the MC's pin in a specific port
 * Parameters (in):    	Port_t, Pin_t, & PinVal_t
 * Parameters (out):   	u8
 * Return value:      	OK-->1 or Error-->0
*******************************************************************************/
uint8_t GPIO_u8SetPinValue(Port_t Port, Pin_t PinNumb, PinVal_t PinVal );

/*******************************************************************************
 * Function Name:		GPIO_u8TogglePinValue
 * Description:			Function to toggle the MC's pin in a specific port
 * Parameters (in):    	Port_t, Pin_t
 * Parameters (out):   	u8
 * Return value:      	OK-->1 or Error-->0
*******************************************************************************/
uint8_t GPIO_u8TogglePinValue(Port_t Port, Pin_t PinNumb );

/*******************************************************************************
 * Function Name:		GPIO_u8GetPinValue
 * Description:			Function to get the MC's pin value in a specific port
 * Parameters (in):    	Port_t, Pin_t, & a pointer of PinVal_t to save the pin value in it
 * Parameters (out):   	u8
 * Return value:      	OK-->1 or Error-->0
*******************************************************************************/
uint8_t GPIO_u8GetPinValue(Port_t Port, Pin_t PinNumb, uint8_t *PinVal);


#endif
/********************************************************************************************/
/* END OF FILE: GPIO_interface.h                                                            */
/********************************************************************************************/
