
#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#include <stdint.h>	/* Contains types as uint8_t , ... */

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	PORTA,
	PORTB,
	PORTC,
	PORTD,
	PORTE
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
	INPUT_Analog    = 0b0000,
	INPUT_Floating  = 0b0100,
	INPUT_Pull_Down = 0b1000,
	INPUT_Pull_Up   = 0b11000,

	OUTPUT_10MHZ_Push_Pull = 0b0001,
	OUTPUT_10MHZ_Open_Drain = 0b0101,
	ALTERNATIVE_10MHZ_Push_Pull = 0b1001,
	ALTERNATIVE_10MHZ_Open_Drain = 0b1101,

	OUTPUT_2MHZ_Push_Pull = 0b0010,
	OUTPUT_2MHZ_Open_Drain = 0b0110,
	ALTERNATIVE_2MHZ_Push_Pull = 0b1010,
	ALTERNATIVE_2MHZ_Open_Drain = 0b1110,

	OUTPUT_50MHZ_Push_Pull = 0b0011,
	OUTPUT_50MHZ_Open_Drain = 0b0111,
	ALTERNATIVE_50MHZ_Push_Pull = 0b1011,
	ALTERNATIVE_50MHZ_Open_Drain = 0b1111,

}Mode_t;		/* Used in GPIO Port configuration register low (GPIOx_CRL) and Port configuration register high (GPIOx_CRH) */

/* NOTE !!!!
 * Mode_t is not fully correct as to handle the case of INPUT Pull Down/UP as they have
 *  the same mode bits in the data sheet */


typedef enum
{
	PIN_LOW,
	PIN_HIGH
}PinValue_t;	/* Used to set pin value */

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
	//ALtFunc_t AltFunc;
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
uint8_t GPIO_u8SetPinValue(Port_t Port, Pin_t PinNumb, PinValue_t PinVal );

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
