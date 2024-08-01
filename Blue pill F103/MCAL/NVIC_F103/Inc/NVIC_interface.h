
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/*******************************************************************************
********************************************************************************
********************************************************************************
********************************************************************************
*                        		Definitions                                    *
********************************************************************************
********************************************************************************
********************************************************************************/


/*******************************************************************************
*                        	NVIC INTERTUPT NUMBER                              *
*******************************************************************************/
typedef enum {
	NVIC_WWDG                   = 0,    /*!< Window Watch-dog Interrupt */
	NVIC_PVD                    = 1,    /*!< PVD through EXTI Line Detection Interrupt */
	NVIC_TAMPER	             	= 2,    /*!< Tamper and TimeStamp interrupts through the EXTI line */
	NVIC_RTC               		= 3,    /*!< RTC Wake-up interrupt through the EXTI line */
	NVIC_FLASH                  = 4,    /*!< FLASH global Interrupt */
	NVIC_RCC	                = 5,    /*!< RCC global Interrupt */
	NVIC_EXTI0                  = 6,    /*!< EXTI Line0 Interrupt */
	NVIC_EXTI1                  = 7,    /*!< EXTI Line1 Interrupt */
	NVIC_EXTI2                  = 8,    /*!< EXTI Line2 Interrupt */
	NVIC_EXTI3                  = 9,    /*!< EXTI Line3 Interrupt */
	NVIC_EXTI4                  = 10,   /*!< EXTI Line4 Interrupt */
	NVIC_DMA1_Channel1          = 11,   /*!< DMA1 Stream 0 global Interrupt */
	NVIC_DMA1_Channel2          = 12,   /*!< DMA1 Stream 1 global Interrupt */
	NVIC_DMA1_Channel3          = 13,   /*!< DMA1 Stream 2 global Interrupt */
	NVIC_DMA1_Channel4          = 14,   /*!< DMA1 Stream 3 global Interrupt */
	NVIC_DMA1_Channel5          = 15,   /*!< DMA1 Stream 4 global Interrupt */
	NVIC_DMA1_Channel6          = 16,   /*!< DMA1 Stream 5 global Interrupt */
	NVIC_DMA1_Channel7          = 17,   /*!< DMA1 Stream 6 global Interrupt */
	NVIC_ADC1_2                 = 18,   /*!< ADC1, ADC2 and ADC3 global Interrupts */
	NVIC_USB_HP_CAN_TX          = 19,   /*!< CAN1 TX Interrupt */
	NVIC_USB_LP_CAN_RX0         = 20,   /*!< CAN1 RX0 Interrupt */
	NVIC_CAN1_RX1               = 21,   /*!< CAN1 RX1 Interrupt */
	NVIC_CAN1_SCE               = 22,   /*!< CAN1 SCE Interrupt */
	NVIC_EXTI9_5                = 23,   /*!< External Line[9:5] Interrupts */
	NVIC_TIM1_BRK_TIM9          = 24,   /*!< TIM1 Break interrupt and TIM9 global interrupt */
	NVIC_TIM1_UP_TIM10          = 25,   /*!< TIM1 Update Interrupt and TIM10 global interrupt */
	NVIC_TIM1_TRG_COM_TIM11     = 26,   /*!< TIM1 Trigger and Computation Interrupt and TIM11 global interrupt */
	NVIC_TIM1_CC                = 27,   /*!< TIM1 Capture Compare Interrupt */
	NVIC_TIM2                   = 28,   /*!< TIM2 global Interrupt */
	NVIC_TIM3                   = 29,   /*!< TIM3 global Interrupt */
	NVIC_TIM4                   = 30,   /*!< TIM4 global Interrupt */
	NVIC_I2C1_EV                = 31,   /*!< I2C1 Event Interrupt */
	NVIC_I2C1_ER                = 32,   /*!< I2C1 Error Interrupt */
	NVIC_I2C2_EV                = 33,   /*!< I2C2 Event Interrupt */
	NVIC_I2C2_ER                = 34,   /*!< I2C2 Error Interrupt */
	NVIC_SPI1                   = 35,   /*!< SPI1 global Interrupt */
	NVIC_SPI2                   = 36,   /*!< SPI2 global Interrupt */
	NVIC_USART1                 = 37,   /*!< USART1 global Interrupt */
	NVIC_USART2                 = 38,   /*!< USART2 global Interrupt */
	NVIC_USART3                 = 39,   /*!< USART3 global Interrupt */
	NVIC_EXTI15_10              = 40,   /*!< External Line[15:10] Interrupts */
	NVIC_RTC_Alarm              = 41,   /*!< RTC Alarm (A and B) through EXTI Line Interrupt */
	NVIC_USBWakeUp            	= 42,   /*!< USB OTG FS Wake-up through EXTI line interrupt */
	NVIC_TIM8_BRK_TIM12         = 43,   /*!< TIM8 Break Interrupt and TIM12 global interrupt */
	NVIC_TIM8_UP_TIM13          = 44,   /*!< TIM8 Update Interrupt and TIM13 global interrupt */
	NVIC_TIM8_TRG_COM_TIM14     = 45,   /*!< TIM8 Trigger and Computation Interrupt and TIM14 global interrupt */
	NVIC_TIM8_CC                = 46,   /*!< TIM8 Capture Compare Interrupt */
	NVIC_ADC3           		= 47,   /*!< DMA1 Stream7 Interrupt */
	NVIC_FSMC                   = 48,   /*!< FMC global Interrupt */
	NVIC_SDIO                   = 49,   /*!< SDIO global Interrupt */
	NVIC_TIM5                   = 50,   /*!< TIM5 global Interrupt */
	NVIC_SPI3                   = 51,   /*!< SPI3 global Interrupt */
	NVIC_UART4                  = 52,   /*!< UART4 global Interrupt */
	NVIC_UART5                  = 53,   /*!< UART5 global Interrupt */
	NVIC_TIM6               	= 54,   /*!< TIM6 global and DAC1&2 under-run error */
	NVIC_TIM7                   = 55,   /*!< TIM7 global interrupt */
	NVIC_DMA2_Channel1          = 56,   /*!< DMA2 channel 0 global Interrupt */
	NVIC_DMA2_Channel2          = 57,   /*!< DMA2 channel 1 global Interrupt */
	NVIC_DMA2_Channel3          = 58,   /*!< DMA2 channel 2 global Interrupt */
	NVIC_DMA2_Channel4_5        = 59,   /*!< DMA2 channel 3 global Interrupt */
}Interrupt_t;



typedef enum {
	Four_Bit_Group_Zero_Bit_sub,
	Three_Bit_Group_One_Bit_sub=4,
	Two_Bit_Group_Two_Bit_sub,
	One_Bit_Group_Three_Bit_sub,
	Zero_Bit_Group_Four_Bit_sub
}NVIC_GroupPriorityCfg;


/*******************************************************************************
*                      Functions Prototypes                                   *
*******************************************************************************/

/*******************************************************************************
* Function Name:		NVIC_vEnableInterrupt
* Description:			Function to enable the required interrupt
* Parameters (in):    	Interrupt_t
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void NVIC_vEnableInterrupt(Interrupt_t copy_eInterrupt);

/*******************************************************************************
* Function Name:		NVIC_vDisableInterrupt
* Description:			Function to disable the required interrupt
* Parameters (in):    	Interrupt_t
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void NVIC_vDisableInterrupt(Interrupt_t copy_eInterrupt);

/*******************************************************************************
* Function Name:		NVIC_vSetPendingFlag
* Description:			Function to set the pending flag of the required interrupt
* Parameters (in):    	Interrupt_t
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void NVIC_vSetPendingFlag(Interrupt_t copy_eInterrupt);

/*******************************************************************************
* Function Name:		NVIC_vClearPendingFlag
* Description:			Function to clear the pending flag of the required interrupt
* Parameters (in):    	Interrupt_t
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void NVIC_vClearPendingFlag(Interrupt_t copy_eInterrupt);

/*******************************************************************************
* Function Name:		NVIC_vGetActiveFlag
* Description:			Function to get the active flag of the required interrupt
* Parameters (in):    	Interrupt_t, and a pointer(*) of uint8_t for the flag status
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void NVIC_vGetActiveFlag(Interrupt_t copy_eInterrupt, uint8_t *copy_u8flagStatus);

/*******************************************************************************
* Function Name:		NVIC_vSetPriorityCfg
* Description:			Function to set the priority control flag of the required interrupt
* Parameters (in):    	Interrupt_t
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void NVIC_vSetPriorityCfg(NVIC_GroupPriorityCfg copy_eGroupPriorityCfg);

/*******************************************************************************
* Function Name:		NVIC_vSetInterruptPriority
* Description:			Function to set the interrupt priority of the required interrupt
* Parameters (in):    	Interrupt_t, and a uint8_t of the priority number
* Parameters (out):   	void
* Return value:      	void
********************************************************************************/
void NVIC_vSetInterruptPriority(Interrupt_t copy_eInterrupt,uint8_t copy_u8Priority);


#endif
