
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#include "std_types.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	HSI, HSE, HSE_Bypass, PLL
}RCC_type;

typedef enum
{
	OFF , ON
}RCC_status;

typedef enum
{
	div_1, div_2
}RCC_HSE_config;

typedef enum
{
	div2, div3, div4, div5, div6, div7, div8, div9, div10, div11, div12, div13, div14, div15, div16
}RCC_PLL_config;

typedef enum
{
	HSI_DIV_2, HSE_2
}RCC_PLL_source;

typedef enum
{
	DMA1, DMA2, SRAM, FLITF=4, CRC=6, FSMC=8, SDIO=10
}RCC_AHB_peripheral;

typedef enum
{
	TIM2, TIM3, TIM4, TIM5, TIM6, TIM7, TIM12, TIM13, TIM14, WWDG=11, SPI2=14, SPI3,
	USART2=17, USART3, USART4, USART5, I2C1, I2C2, USB, CAN=25, BKP=27, PWR, DAC
}RCC_APB1_peripheral;

typedef enum
{
	AFIO, IOPA=2, IOPB, IOPC, IOPD, IOPE, IOPF, IOPG, ADC1, ADC2, TIM1, SPI1,
	TIM8, USART1, ADC3, TIM9=19, TIM10, TIM11
}RCC_APB2_peripheral;









/*******************************************************************************
*                      				RCC                     		           *
*******************************************************************************/
//******************************** Bass addresses  *********************************
#define RCC_BASE_ADDRESS	0x40021000

//******************************** PINs Declaration *********************************
#define CR_HSION 			0
#define CR_HSIRDY 			1
#define CR_HSITRIM_5_INDEX	3
#define CR_HSEON			16
#define CR_HSERDY 			17
#define CR_HSEBYP 			18
#define CR_CSSON			19
#define CR_PLLON			24
#define CR_PLLRDY 			25

//******************************** __RCC_CFGR__ *********************************
#define CFGR_SW0 				0
#define CFGR_SW1 				1
#define CFGR_SWS0 				2
#define CFGR_SWS1	 			3
#define CFGR_4_HPRE_INDEX 		4
#define CFGR_PPRE1_3_INDEX		8
#define CFGR_PPRE2_3_INDEX		11
#define CFGR_ADCPRE0 			14
#define CFGR_ADCPRE1			15
#define CFGR_PLL_SRC 			16
#define CFGR_PLL_XTRPE 			17
#define CFGR_PLL_MUL_4_INDEX	18
#define CFGR_USE_PRE 			22
#define CFGR_MCO_3_INDEX		24


//******************************** Registers Declaration *********************************
typedef struct
{
	volatile u32 CR;
	volatile u32 CFGR;

	volatile u32 CIR;

	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;

	volatile u32 AHBENR;

	volatile u32 APB2ENR;
	volatile u32 APB1ENR;

	volatile u32 BDCR;
	volatile u32 CSR;
	volatile u32 AHBSTR;
	volatile u32 CFGR2;
}RCC_Reg_t;

#define RCC  ( (RCC_Reg_t*)(RCC_BASE_ADDRESS) )










/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:		RCC_set_CLK_status
 * Description:			Function to enable the system clock source
 * Parameters (in):    	RCC_type, & RCC_status
 * Parameters (out):   	u8
 * Return value:      	OK-->1 or Error-->0
*******************************************************************************/
u8 RCC_set_CLK_status(RCC_type type , RCC_status state);

/*******************************************************************************
 * Function Name:		RCC_void_set_CLK
 * Description:			Function to set the system clock source
 * Parameters (in):    	RCC_type
 * Parameters (out):   	u8
 * Return value:      	OK-->1 or Error-->0
*******************************************************************************/
u8 RCC_void_set_SYS_CLK(RCC_type type);

/*******************************************************************************
 * Function Name:		RCC_void_HSE_config
 * Description:			Function to set the configuration of HSE clock source
 * Parameters (in):    	RCC_config
 * Parameters (out):   	void
 * Return value:      	void
*******************************************************************************/
void RCC_void_HSE_config(RCC_HSE_config config);

/*******************************************************************************
 * Function Name:		RCC_void_PLL_config
 * Description:			Function to set the configuration of PLL clock source
 * Parameters (in):    	RCC_PLL_config, RCC_PLL_source
 * Parameters (out):   	void
 * Return value:      	void
*******************************************************************************/
void RCC_void_PLL_config(RCC_PLL_config config, RCC_PLL_source source);

/*******************************************************************************
 * Function Name:		RCC_AHB_EnableClk
 * Description:			Function to set the Enable(ON)/Disable(OFF) of a given peripheral on AHB bus
 * Parameters (in):    	RCC_AHB_peripheral, RCC_status
 * Parameters (out):   	u8
 * Return value:      	OK-->1 or Error-->0
*******************************************************************************/
u8 RCC_AHB_EnableClk(RCC_AHB_peripheral peripheral, RCC_status state);

/*******************************************************************************
 * Function Name:		RCC_APB1_EnableClk
 * Description:			Function to set the Enable(ON)/Disable(OFF) of a given peripheral on APB1 bus
 * Parameters (in):    	RCC_APB1_peripheral, RCC_status
 * Parameters (out):   	u8
 * Return value:      	OK-->1 or Error-->0
*******************************************************************************/
u8 RCC_APB1_EnableClk(RCC_APB1_peripheral peripheral, RCC_status state);

/*******************************************************************************
 * Function Name:		RCC_APB2_EnableClk
 * Description:			Function to set the Enable(ON)/Disable(OFF) of a given peripheral on APB2 bus
 * Parameters (in):    	RCC_APB2_peripheral, RCC_status
 * Parameters (out):   	u8
 * Return value:      	OK-->1 or Error-->0
*******************************************************************************/
u8 RCC_APB2_EnableClk(RCC_APB2_peripheral peripheral, RCC_status state);

#endif /* RCC_PRIVATE_H_ */
