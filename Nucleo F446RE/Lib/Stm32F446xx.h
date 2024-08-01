

/********************************************************************************************/
/* Guard of file will call one time in .c  			                                        */
/********************************************************************************************/
#ifndef STM33F446xx_H_
/#define STM33F446xx_H_

/**************************************** Various Memories Base Addresses **********************/

#define FLASH_BASE_ADDRESS				0x08000000UL		/* !< FLASH(up to 1 MB) base address in the alias region                         */
#define SRAM1_BASE_ADDRESS				0x20000000UL		/* !< SRAM1(112 KB) base address in the alias region                             */
#define SYSTEM_MEMORY_BASE_ADDRESS		0x1FFF0000UL		/* System flash memory that is reserved to the system and you can read only it that contain the bootloader of the system */ 
//#define SRAM2_BASE            0x /* !< SRAM2(16 KB) base address in the alias region                              */
//#define PERIPH_BASE           0x /* !< Peripheral base address in the alias region                                */
//#define BKPSRAM_BASE          0x /* !< Backup SRAM(4 KB) base address in the alias region                         */
//#define FMC_R_BASE            0x /* !< FMC registers base address                                                 */
//#define QSPI_R_BASE           0x /* !< QuadSPI registers base address                                             */
//#define SRAM1_BB_BASE         0x /* !< SRAM1(112 KB) base address in the bit-band region                          */
//#define SRAM2_BB_BASE         0x /* !< SRAM2(16 KB) base address in the bit-band region                           */
//#define PERIPH_BB_BASE        0x /* !< Peripheral base address in the bit-band region                             */
//#define BKPSRAM_BB_BASE       0x /* !< Backup SRAM(4 KB) base address in the bit-band region                      */
//#define FLASH_END             0x /* !< FLASH end address                                                          */
//#define FLASH_OTP_BASE        0x /* !< Base address of : (up to 528 Bytes) embedded FLASH OTP Area                */
//#define FLASH_OTP_END         0x /* !< End address of : (up to 528 Bytes) embedded FLASH OTP Area                 */



/**************************************** GPIO Register Definition Structure **********************/
#define GPIOA_BASE_ADDRESS 				0x40020000UL
#define GPIOB_BASE_ADDRESS 				0x40020400UL
#define GPIOC_BASE_ADDRESS 				0x40020800UL
#define GPIOD_BASE_ADDRESS 				0x40020C00UL
#define GPIOE_BASE_ADDRESS 				0x40021000UL
#define GPIOF_BASE_ADDRESS 				0x40021400UL
#define GPIOG_BASE_ADDRESS 				0x40021800UL
#define GPIOH_BASE_ADDRESS 				0x40021C00UL

typedef struct
{
	volatile u32 MODER;					/* GPIO PORT Mode Register */
	volatile u32 OTYPER;				/* GPIO PORT Output type Register */
	volatile u32 OSPEEDR;				/* GPIO PORT Output speed Register */
	volatile u32 PUPDR;					/* GPIO PORT Pull up/down Register */
	volatile u32 IDR;					/* GPIO PORT Input Data Register */
	volatile u32 ODR;					/* GPIO PORT Output Data Register */
	volatile u32 BSRR;					/* GPIO PORT Bit Set/Reset Register */
	volatile u32 LCKR;					/* GPIO PORT Lock Register */
	volatile u32 AFR[2];				/* GPIO PORT Alternate function Register */
}GPIO_RegDef_t;

/**************************************** GPIO Peripheral Definition  *****************************/
#define GPIOA       		((GPIO_RegDef_t*)GPIOA_BASE_ADDRESS)
#define GPIOB				((GPIO_RegDef_t*)GPIOB_BASE_ADDRESS)
#define GPIOC				((GPIO_RegDef_t*)GPIOC_BASE_ADDRESS)
#define GPIOD				((GPIO_RegDef_t*)GPIOD_BASE_ADDRESS)
#define GPIOE				((GPIO_RegDef_t*)GPIOE_BASE_ADDRESS)
#define GPIOF				((GPIO_RegDef_t*)GPIOF_BASE_ADDRESS)
#define GPIOG				((GPIO_RegDef_t*)GPIOG_BASE_ADDRESS)
#define GPIOH				((GPIO_RegDef_t*)GPIOH_BASE_ADDRESS)



/**************************************** RCC Register Definition Structure **********************/
#define RCC_BASE_ADDRESS				0x40023800U

typedef struct {
	volatile u32 CR;				/* Clock control register */
	volatile u32 PLLCFGR;			/* PLL configuration register */
	volatile u32 CFGR;				/* Clock configuration register */
	volatile u32 CIR;				/* Clock interrupt register */
	volatile u32 AHB1RSTR;			/* AHB1 peripheral reset register */
	volatile u32 AHB2RSTR;			/* AHB2 peripheral reset register */
	volatile u32 AHB3RSTR;			/* AHB3 peripheral reset register */
	uint32_t RESERVED0;				/* Reserved */
	volatile u32 APB1RSTR;			/* APB1 peripheral reset register */
	volatile u32 APB2RSTR;			/* APB2 peripheral reset register */
	uint32_t RESERVED1[2];			/* Reserved */
	volatile uint32_t AHB1ENR;		/* AHB1 peripheral clock enable register */
	volatile uint32_t AHB2ENR;		/* AHB2 peripheral clock enable register */
	volatile uint32_t AHB3ENR;		/* AHB3 peripheral clock enable register */
	uint32_t RESERVED2;				/* Reserved */
	volatile uint32_t APB1ENR;		/* APB1 peripheral clock enable register */
	volatile uint32_t APB2ENR;		/* APB2 peripheral clock enable register */
	uint32_t RESERVED3[2];			/* Reserved */
	volatile uint32_t AHB1LPENR;	/* AHB1 peripheral clock enable in low power mode register */
	volatile uint32_t AHB2LPENR;	/* AHB2 peripheral clock enable in low power mode register */
	volatile uint32_t AHB3LPENR;	/* AHB3 peripheral clock enable in low power mode register */
	uint32_t RESERVED4;				/* Reserved */
	volatile uint32_t APB1LPENR;	/* APB1 peripheral clock enable in low power mode register */
	volatile uint32_t APB2LPENR;	/* APB2 peripheral clock enable in low power mode register */
	uint32_t RESERVED5[2];			/* Reserved */
	volatile uint32_t BDCR;			/* Backup domain control register */
	volatile uint32_t CSR;			/* Clock control & status register */
	uint32_t RESERVED6[2];			/* Reserved */
	volatile uint32_t SSCGR;		/* Spread spectrum clock generation register */
	volatile uint32_t PLLI2SCFGR	/* PLLI2S configuration register */
} RCC_RegDef_t;


/**************************************** RCC Peripheral Definition  *****************************/
#define RCC       	   ((RCC_RegDef_t*)RCC_BASE_ADDRESS)



///******************************* STK Register Definition Structure *******************************/
//#define SysTick_BASE_ADDRESS 			0xE000E010UL
//
//typedef struct {
//	volatile uint32_t CTRL;
//	volatile uint32_t LOAD;
//	volatile uint32_t VAL;
//	volatile uint32_t CALIB;
//
//}MSTK_RegDef_t;
//
//#define STK  		   ((MSTK_RegDef_t*)SysTick_BASE_ADDRESS)
//
///******************************* NVIC Register Definition Structure *******************************/
//#define NVIC_BASE_ADDRESS 	   			0xE000E100UL
//
//typedef struct {
//	volatile uint32_t NVIC_ISER[8];
//	volatile uint32_t Reserved1[24];
//	volatile uint32_t NVIC_ICER[8];
//	volatile uint32_t Reserved2[24];
//	volatile uint32_t NVIC_ISPR[8];
//	volatile uint32_t Reserved3[24];
//	volatile uint32_t NVIC_ICPR[8];
//	volatile uint32_t Reserved4[24];
//	volatile uint32_t NVIC_IABR[8];
//	volatile uint32_t Reserved5[24];
//	volatile uint8_t  NVIC_IPR[240];
//	volatile uint32_t Reserved6[644];
//	volatile uint32_t NVIC_STIR;
//
//}NVIC_RegDef_t;
//
//#define NVIC  		   ((NVIC_RegDef_t*)NVIC_BASE_ADDRESS)
//
///******************************* SCB Register Definition Structure *******************************/
//#define SCB_BASE_ADDRESS 	   			0xE000E008UL
//
//typedef struct {
//	uint32_t ACTLR;
//	uint32_t CPUID;
//	uint32_t ICSR;
//	uint32_t VTOR;
//	uint32_t AIRCR;
//	uint32_t SCR;
//	uint32_t CCR;
//	uint8_t  SHP[12U];
//	uint32_t SHCSR;
//}SCB_RegDef_t;
//
//#define  SCB  		   ((SCB_RegDef_t*)SCB_BASE_ADDRESS)
//
///******************************* SYSCFG Register Definition Structure *******************************/
//
//#define SYSCFG_BASE_ADDRESS		  	0x40013800UL
//
//typedef struct
//{
//	volatile uint32_t MEMRMP;	 	/* SYSCFG Memory Remap Register */
//	volatile uint32_t PMC;		 	/* SYSCFG Peripheral Mode Configuration Register */
//	volatile uint32_t EXTICR[4]; 	/* SYSCFG External Interrupt Configuration Registers*/
//	uint32_t RESERVED0[2];
//	volatile uint32_t CMPCR; 		/* Compensation Cell Control Register */
//	uint32_t RESERVED1[2];
//	volatile uint32_t CFGR; 		/* SYSCFG Configuration Register */
//
//} SYSCFG_RegDef_t;
//
//#define SYSCFG 			((SYSCFG_RegDef_t *)SYSCFG_BASE_ADDRESS)
//
///******************************* EXTI Register Definition Structure *******************************/
//
//#define EXTI_BASE_ADDRESS		    0x40013C00UL
//
//typedef struct
//{
//	volatile uint32_t IMR;	 /* Interrupt Mask Register */
//	volatile uint32_t EMR;	 /* Event Mask Register */
//	volatile uint32_t RTSR;	 /* Rising Trigger Selection Register */
//	volatile uint32_t FTSR;	 /* Falling Trigger Selection Register */
//	volatile uint32_t SWIER; /* Software Interrupt Event Register */
//	volatile uint32_t PR;	 /* Pending Register */
//} EXTI_RegDef_t;
//
//#define EXTI			 ((EXTI_RegDef_t *)EXTI_BASE_ADDRESS)
//
//
///******************************* UART Register Definition Structure *******************************/
//
//#define USART1_BASE_ADDRESS 0x40011000UL
//#define USART2_BASE_ADDRESS 0x40004400UL
//#define USART3_BASE_ADDRESS 0x40004800UL
//#define UART4_BASE_ADDRESS  0x40004C00UL
//#define UART5_BASE_ADDRESS  0x40005000UL
//#define USART6_BASE_ADDRESS 0x40011400UL
//
//typedef struct {
//	volatile uint32_t SR;
//	volatile uint32_t DR;
//	volatile uint32_t BRR;
//	volatile uint32_t CR1;
//	volatile uint32_t CR2;
//	volatile uint32_t CR3;
//	volatile uint32_t GTPR;
//}USART_RegDef_t;
//
//#define  USART1  	   ((USART_RegDef_t*)USART1_BASE_ADDRESS)
//#define  USART2 	   ((USART_RegDef_t*)USART2_BASE_ADDRESS)
//#define  USART3 	   ((USART_RegDef_t*)USART3_BASE_ADDRESS)
//#define  UART4  	   ((USART_RegDef_t*)UART4_BASE_ADDRESS)
//#define  UART5  	   ((USART_RegDef_t*)UART5_BASE_ADDRESS)
//#define  USART6 	   ((USART_RegDef_t*)USART6_BASE_ADDRESS)
//
///******************************* I2C Register Definition Structure *******************************/
//#define I2C3_BASE_ADDRESS 0x40005C00UL
//#define I2C2_BASE_ADDRESS 0x40005800UL
//#define I2C1_BASE_ADDRESS 0x40005400UL
//
//typedef struct
//{
//	volatile uint32_t I2C_CR1;
//	volatile uint32_t I2C_CR2;
//	volatile uint32_t I2C_OAR1;
//	volatile uint32_t I2C_OAR2;
//	volatile uint32_t I2C_DR;
//	volatile uint32_t I2C_SR1;
//	volatile uint32_t I2C_SR2;
//	volatile uint32_t I2C_CCR;
//	volatile uint32_t I2C_TRISE;
//	volatile uint32_t I2C_FLTR;
//}I2C_RegDef_t;
//
//#define I2C1 ((I2C_RegDef_t *)I2C1_BASE_ADDRESS)
//#define I2C2 ((I2C_RegDef_t *)I2C2_BASE_ADDRESS)
//#define I2C3 ((I2C_RegDef_t *)I2C3_BASE_ADDRESS)
//
//typedef enum
//{
//	I2C_PE = 0,		   /* Peripheral Enable */
//	I2C_SMBUS = 1,	   /* SMBus Mode */
//	I2C_SMBTYPE = 3,   /* SMBus Type */
//	I2C_ENARP = 4,	   /* ARP Enable */
//	I2C_ENPEC = 5,	   /* PEC Enable */
//	I2C_ENGC = 6,	   /* General Call Enable */
//	I2C_NOSTRETCH = 7, /* Clock Stretching Disable (Slave mode) */
//	I2C_START = 8,	   /* Start Generation */
//	I2C_STOP = 9,	   /* Stop Generation */
//	I2C_ACK = 10,	   /* Acknowledge Enable */
//	I2C_POS = 11,	   /* Acknowledge/PEC Position (for data reception) */
//	I2C_PECC = 12,	   /* Packet Error Checking */
//	I2C_ALERT = 13,	   /* SMBus Alert */
//	I2C_SWRST = 15	   /* Software Reset */
//
//} I2C_CR1_BITS_t;
//
//typedef enum
//{
//	I2C_FREQ = 0,	  /* Peripheral Clock Frequency */
//	I2C_ITERREN = 8,  /* Error Interrupt Enable */
//	I2C_ITEVTEN = 9,  /* Event Interrupt Enable */
//	I2C_ITBUFEN = 10, /* Buffer Interrupt Enable */
//	I2C_DMAEN = 11,	  /* DMA Requests Enable */
//	I2C_LAST = 12	  /* DMA Last Transfer */
//
//} I2C_CR2_BITS_t;
//
//typedef enum
//{
//	I2C_ADD0 = 0,	 /* Interface Address */
//	I2C_ADD = 1,	 /* Interface Address */
//	I2C_ADDMODE = 15 /* Addressing Mode (Slave mode) */
//
//} I2C_OAR1_BITS_t;
//
//typedef enum
//{
//	I2C_ENDUAL = 0, /* Dual addressing mode enable */
//	I2C_ADD2 = 1	/* Interface Address */
//
//} I2C_OAR2_BITS_t;
//
//typedef enum
//{
//	I2C_SB = 0,		  /* Start Bit (Master mode) */
//	I2C_ADDR = 1,	  /* Address sent (master mode)/matched (slave mode) */
//	I2C_BTF = 2,	  /* Byte Transfer Finished */
//	I2C_ADD10 = 3,	  /* 10-bit header sent (Master mode) */
//	I2C_STOPF = 4,	  /* Stop detection (Slave mode) */
//	I2C_RXNE = 6,	  /* Data Register not Empty (receivers) */
//	I2C_TXE = 7,	  /* Data Register Empty (transmitters) */
//	I2C_BERR = 8,	  /* Bus Error */
//	I2C_ARLO = 9,	  /* Arbitration Lost (master mode) */
//	I2C_AF = 10,	  /* Acknowledge Failure */
//	I2C_OVR = 11,	  /* Overrun/Underrun */
//	I2C_PECERR = 12,  /* PEC Error in reception */
//	I2C_TIMEOUT = 14, /* Timeout or Tlow Error */
//	I2C_SMBALERT = 15 /* SMBus Alert */
//
//} I2C_SR1_BITS_t;
//
//typedef enum
//{
//	I2C_MSL = 0,		/* Master/Slave */
//	I2C_BUSY = 1,		/* Bus Busy */
//	I2C_TRA = 2,		/* Transmitter/Receiver */
//	I2C_GENCALL = 4,	/* General Call Address (Slave mode) */
//	I2C_SMBDEFAULT = 5, /* SMBus Device Default Address (Slave mode) */
//	I2C_SMBHOST = 6,	/* SMBus Host Header (Slave mode) */
//	I2C_DUALF = 7,		/* Dual Flag (Slave mode) */
//	I2C_PEC = 8			/* Packet Error Checking Register */
//
//} I2C_SR2_BITS_t;
//
//typedef enum
//{
//	I2C_CCR = 0,   /* Clock Control Register */
//	I2C_DUTY = 14, /* Fast Mode Duty Cycle */
//	I2C_F_S = 15,  /* I2C Master Mode Selection */
//
//} I2C_CCR_BITS_t;
//
//typedef enum
//{
//	I2C_TRISE = 0 /* Maximum Rise Time in Fast/Standard mode (Master mode) */
//
//} I2C_TRISE_BITS_t;
//
//typedef enum
//{
//	I2C_DNF = 0,  /* Digital Noise Filter */
//	I2C_ANOFF = 4 /* Analog Noise Filter OFF */
//
//} I2C_FLTR_BITS_t;
//
//
//
//
///******************** SPI Register Definition Structure ****************/
//
//
//#define SPI3_BASE_ADDRESS		    0x40003C00UL
//#define SPI2_BASE_ADDRESS		    0x40003800UL
//
//#define SPI4_BASE_ADDRESS		    0x40013400UL
//#define SPI1_BASE_ADDRESS		    0x40013000UL
//typedef struct
//{
//	volatile uint32_t SPI_CR1;
//	volatile uint32_t SPI_CR2;
//	volatile uint32_t SPI_SR;
//	volatile uint32_t SPI_DR;
//	volatile uint32_t SPI_CRCPR;
//	volatile uint32_t SPI_RXCRCR;
//	volatile uint32_t SPI_TXCRCR;
//	volatile uint32_t SPI_I2SCFGR;
//	volatile uint32_t SPI_I2SPR;
//}SPI_RegDef_t;
//
//#define SPI1	((SPI_RegDef_t*)SPI1_BASE_ADDRESS)
//#define SPI2	((SPI_RegDef_t*)SPI2_BASE_ADDRESS)
//#define SPI3	((SPI_RegDef_t*)SPI3_BASE_ADDRESS)
//#define SPI4	((SPI_RegDef_t*)SPI4_BASE_ADDRESS)
///******************************* DMA Register Definition Structure *******************************/
//#define DMA1_BASE_ADDRESS		 0x40026000U
//#define DMA2_BASE_ADDRESS		 0x40026400U
//
//typedef struct
//{
//	volatile uint32_t CR;	/* DMA Stream x Configuration Register */
//	volatile uint32_t NDTR; /* DMA Stream x Number of Data Register */
//	volatile uint32_t PAR;	/* DMA Stream x Peripheral Address Register */
//	volatile uint32_t M0AR; /* DMA Stream x Memory 0 Address Register */
//	volatile uint32_t M1AR; /* DMA Stream x Memory 1 Address Register */
//	volatile uint32_t FCR;	/* DMA Stream x FIFO Control Register */
//
//} DMA_Stream_RegDef_t;
//
//#define DMA1              ((DMA_RegDef_t *)DMA1_BASE_ADDRESS)
//#define DMA2              ((DMA_RegDef_t *)DMA2_BASE_ADDRESS)
//
//
//
///********************* Macros for DMA registers            *************************/
//#define DMA1_ISR ((uint32_t*)(DMA1_BASE_ADDRESS))
//#define DMA1_IFCR ((uint32_t*)(DMA1_BASE_ADDRESS+8))
//#define DMA1_SCRx(X) (*(uint32_t*)(DMA1_BASE_ADDRESS+0x010UL+0x018UL*X))
//#define DMA1_SNDTRx(X) (*(uint32_t*)(DMA1_BASE_ADDRESS+0x014+0x018*X))
//#define DMA1_SPARx(X) (*(uint32_t*)(DMA1_BASE_ADDRESS+0x018+0x018*X))
//#define DMA1_SM0ARx(X) (*(uint32_t*)(DMA1_BASE_ADDRESS+0x01c+0x018*X))
//#define DMA1_SM1ARx(X) (*(uint32_t*)(DMA1_BASE_ADDRESS+0x020+0x018*X))
//#define DMA1_SFCRx(X) (*(uint32_t*)(DMA1_BASE_ADDRESS+0x024+0x018*X))
//
///************************************************************************************/
///******************************** Register Access ***********************************/
///************************************************************************************/
//#define  DMA1_SCR_CHSEL                             25
//#define  DMA1_SCR_PRIORITY                          16
//#define  DMA1_SCR_PINC                              9
//#define  DMA1_SCR_MINC                              10
//#define  DMA1_SCR_DMA1_TRANSIMITION_MODE            6
//#define  DMA1_SCR_MODE                              2
//#define  DMA1_SCR_PSIZE                             11
//#define  DMA1_SCR_MSIZE                             13
//#define  DMA1_IFCR_LOW                              0
//#define  DMA1_IFCR_HIGH                             1
//#define  DMA1_HIGH                                  1
//#define  DMA1_LOW                                   0
//#define  DMA1_LIFCR_CTCIF0                          5
//#define  DMA1_LIFCR_CTCIF1                          11
//#define  DMA1_LIFCR_CTCIF2                          21
//#define  DMA1_LIFCR_CTCIF3                          27
//#define  DMA1_HIFCR_CTCIF4                          5
//#define  DMA1_HIFCR_CTCIF5                          11
//#define  DMA1_HIFCR_CTCIF6                          21
//#define  DMA1_HIFCR_CTCIF7                          27
//
//
//
//
//
//
#endif
/********************************************************************************************/
/* END OF FILE: STM32F446xx.h                                                               */
/********************************************************************************************/