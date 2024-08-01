
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

/*******************************************************************************
*                        		SYSTICK TYPE	                               *
*******************************************************************************/
/* SysTick control and status register (STK_CTRL) : BITS */
#define CTRL_ENABLE_BIT					0
#define CTRL_TICK_INT_BIT				1
#define CTRL_CLKSOURCE_BIT				2
#define CTRL_COUNTER_FLAG				16

/* The RELOAD value can be any value in the range 0x00000001-0x00FFFFFF */
#define MAX_RELOAD_VALUE_REGISTER		0x00FFFFFFU


#endif
