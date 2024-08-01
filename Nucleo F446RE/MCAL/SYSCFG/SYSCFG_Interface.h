
#ifndef SYSCFG_INCLUDE_SYSCFG_INTERFACE_H_
#define SYSCFG_INCLUDE_SYSCFG_INTERFACE_H_
/* ======================================================================
 *							LINES
 * ====================================================================== */

typedef enum
{
    EXTI_LINE0 = 0,
    EXTI_LINE1,
    EXTI_LINE2,
    EXTI_LINE3,
    EXTI_LINE4,
    EXTI_LINE5,
    EXTI_LINE6,
    EXTI_LINE7,
    EXTI_LINE8,
    EXTI_LINE9,
    EXTI_LINE10,
    EXTI_LINE11,
    EXTI_LINE12,
    EXTI_LINE13,
    EXTI_LINE14,
    EXTI_LINE15
} EXTI_t;

typedef enum
{
    GPIO_PORTA = 0,
    GPIO_PORTB,
    GPIO_PORTC,
    GPIO_PORTD,
    GPIO_PORTE,
    GPIO_PORTF,
    GPIO_PORTG,
    GPIO_PORTH

} GPIO_PORT_t;


void SYSFG_voidSetEXTIPort(EXTI_t Local_u8Line, GPIO_PORT_t Local_u8Port);

#endif /* SYSCFG_INCLUDE_SYSCFG_INTERFACE_H_ */
