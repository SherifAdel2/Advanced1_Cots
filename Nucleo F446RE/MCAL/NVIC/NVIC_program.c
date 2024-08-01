/********************************************************************************************/
/********************************************************************************************/
/**************************		Author:  Ahmed Mohamed Mohamed Hassanien        *************/
/**************************		Date:    31 JULY 2023	           		 		*************/
/**************************		Layer:   MCAL								   	*************/
/**************************		SWC:	 NVIC									*************/
/**************************		Version: 1.00 	             					*************/
/********************************************************************************************/
/********************************************************************************************/

/********************************************************************************************/
/* Include libraries                                                                        */
/********************************************************************************************/
#include <stdint.h>

#include "../../LIB/Stm32F466xx.h"
#include "../../LIB/Utils.h"

/********************************************************************************************/
/* Include Component Files                                                                  */
/********************************************************************************************/
#include "NVIC_config.h"
#include "NVIC_private.h"
#include "NVIC_interface.h"

void NVIC_vEnableInterrupt(Interrupt_t copy_eInterrupt)
{
	NVIC->NVIC_ISER[copy_eInterrupt/32]= 0b1 << copy_eInterrupt % 32 ;
}
void NVIC_vDisableInterrupt(Interrupt_t copy_eInterrupt)
{
	NVIC->NVIC_ICER[copy_eInterrupt/32]= 0b1 << copy_eInterrupt % 32 ;
}
void NVIC_vSetPendingFlag(Interrupt_t copy_eInterrupt)
{
	NVIC->NVIC_ISPR[copy_eInterrupt/32]= 0b1 << copy_eInterrupt % 32 ;

}
void NVIC_vClearPendingFlag(Interrupt_t copy_eInterrupt)
{
	NVIC->NVIC_ICPR[copy_eInterrupt/32]= 0b1 << copy_eInterrupt % 32 ;

}
void NVIC_vGetActiveFlag(Interrupt_t copy_eInterrupt, uint8_t *copy_u8flagStatus)
{
	*copy_u8flagStatus = GET_BIT( NVIC->NVIC_IABR[copy_eInterrupt/32],  copy_eInterrupt % 32 );
}

void NVIC_vSetPriorityCfg(NVIC_GroupPriorityCfg copy_eGroupPriorityCfg)
{
	SCB->AIRCR= VECTKEY<<16 | copy_eGroupPriorityCfg << 8;
}
void NVIC_vSetInterruptPriority(Interrupt_t copy_eInterrupt,uint8_t copy_u8Priority)
{
	if (copy_eInterrupt<0)
	{
		SCB->SHP[copy_eInterrupt+12] = copy_u8Priority << 4;
	}
	else if (copy_eInterrupt>=0)
	{
		NVIC->NVIC_IPR[copy_eInterrupt] = copy_u8Priority << 4;
	}
}
