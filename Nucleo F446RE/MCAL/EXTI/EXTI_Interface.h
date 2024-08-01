
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


typedef enum
{
	RISING_TRG = 0, /*!< EXTI Trigger Rising Edge */
	FALLING_TRG,    /*!< EXTI Trigger Falling Edge */
	ON_CHANGE_TRG   /*!< EXTI Trigger On Change */

} TRIG_SELECT_t;

typedef enum
{
	NOT_PENDED = 0, /*!< EXTI Line Not Pending */
	PENDED          /*!< EXTI Line Pending */
} EXTI_PEND_t;

typedef enum
{
	EXTI_DISABLE = 0, /*!< EXTI Line Disabled */
	EXTI_ENABLE       /*!< EXTI Line Enabled */

} EXTI_STATE_t;


typedef enum
{
	EXTI0 = 0,   /*!< EXTI Line0 */
	EXTI1,       /*!< EXTI Line1 */
	EXTI2,       /*!< EXTI Line2 */
	EXTI3,       /*!< EXTI Line3 */
	EXTI4,       /*!< EXTI Line4 */
	EXTI5,       /*!< EXTI Line5 */
	EXTI6,       /*!< EXTI Line6 */
	EXTI7,       /*!< EXTI Line7 */
	EXTI8,       /*!< EXTI Line8 */
	EXTI9,       /*!< EXTI Line9 */
	EXTI10,      /*!< EXTI Line10 */
	EXTI11,      /*!< EXTI Line11 */
	EXTI12,      /*!< EXTI Line12 */
	EXTI13,      /*!< EXTI Line13 */
	EXTI14,      /*!< EXTI Line14 */
	EXTI15,      /*!< EXTI Line15 */
	EXTI16,      /*!< EXTI Line16 */
	EXTI17,      /*!< EXTI Line17 */
	EXTI18,      /*!< EXTI Line18 */
	EXTI20 = 20, /*!< EXTI Line20 */
	EXTI21,      /*!< EXTI Line21 */
	EXTI22       /*!< EXTI Line22 */
} EXTI_LINE_t;

typedef struct
{
	EXTI_LINE_t EXTILine;           /*!< EXTI Line Number */
	TRIG_SELECT_t TriggerSelection; /*!< EXTI Trigger Selection */
	EXTI_STATE_t EXTIStatus;        /*!< EXTI Line Status */
	void (*Copy_PtrFuncEXTI)(void); /*!< Pointer to function to be executed when EXTI interrupt occurs */
} EXTI_Config_t;


void EXTI_voidInit(EXTI_Config_t *Local_PtrEXTIConfg);

void EXTI_voidEnableEXTI(EXTI_LINE_t Local_u8Line);

void EXTI_voidDisableEXTI(EXTI_LINE_t Local_u8Line);

void EXTI_voidClearPendingFlag(EXTI_LINE_t Local_u8Line);

void EXTI_voidReadPendingFlag(EXTI_LINE_t Local_u8Line, EXTI_PEND_t *EXTIStatus);

void EXTI_voidSetSoftwareTrigger(EXTI_LINE_t Local_u8Line);

void EXTI_voidSetTriggerSelection(EXTI_LINE_t Local_u8Line, TRIG_SELECT_t Local_u8TriggerSelection);

void EXTI_voidSetCallBack(EXTI_LINE_t Local_u8Line, void (*Local_PtrFunc)(void));

#endif /* EXTI_INTERFACE_H_ */
