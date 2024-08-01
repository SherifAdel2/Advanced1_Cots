

#ifndef  UART_INTERFACE_H
#define  UART_INTERFACE_H
/******************************************************************************/
/************************ @USARTindex_t ***************************************/
/******************************************************************************/
typedef enum{
			USART_1   =0,
			USART_2     ,
			USART_3     ,
			 UART_4     ,
			 UART_5     ,
			USART_6
}USARTindex_t;
/******************************************************************************/
/************************ @UsartRX_t ******************************************/
/******************************************************************************/
typedef enum{
			RECEIVER_DISABLE   =0,
			RECEIVER_ENABLE
}Receiver_t;
/******************************************************************************/
/************************ @UsartTX_t ******************************************/
/******************************************************************************/
typedef enum{
			TRANSMITTER_DISABLE   =0,
			TRANSMITTER_ENABLE
}Transmitter_t;
/******************************************************************************/
/************************ @RXNEinterrupt_t ************************************/
/******************************************************************************/
typedef enum{
			RXNE_INTERRUPT_DISABLE   =0,
			RXNE_INTERRUPT_ENABLE
}RXNEinterrupt_t;
/******************************************************************************/
/************************ @TransmetCompleteInterrupt_t ************************/
/******************************************************************************/
typedef enum{
			TRANSMITTER_COMPLETE_INTERRUPT_DISABLE   =0,
			TRANSMITTER_COMPLETE_INTERRUPT_ENABLE
}TransmetCompleteInterrupt_t;
/******************************************************************************/
/************************ @TXNEinterrupt_t ************************************/
/******************************************************************************/
typedef enum{
			TXE_INTERRUPT_DISABLE   =0,
			TXE_INTERRUPT_ENABLE
}TXEinterrupt_t;

/******************************************************************************/
/************************ @ParitySelection_t **********************************/
/******************************************************************************/
typedef enum{
			PARITY_SELECTION_EVEN   =0,
			PARITY_SELECTION_ODD
}ParitySelection_t;
/******************************************************************************/
/************************ @ParityControl_t ************************************/
/******************************************************************************/
typedef enum{
			PARITY_CONTROL_DISABLE   =0,
			PARITY_CONTROL_ENABLE
}ParityControl_t;

/******************************************************************************/
/************************ @WordLength_t ***************************************/
/******************************************************************************/
typedef enum{
			DATA_8_BITS   =0,
			DATA_9_BITS
}WordLength_t;
/******************************************************************************/
/************************ @OverSampling_t *************************************/
/******************************************************************************/

typedef enum{
			BY_16      =0,
			BY_8
}OverSampling_t;
/******************************************************************************/
/************************ @StopBit_t ******************************************/
/******************************************************************************/
/*
 * The 0.5 Stop bit and 1.5 Stop bit are not available for UART4 & UART5
 */
typedef enum{
			HALF_BIT       =0,
			ONE_BIT          ,
			ONE_AND_HALF_BIT ,
			TWO_BIT
}StopBit_t;

/******************************************************************************/
/************************ @ErrorTnterrupt_t ***********************************/
/******************************************************************************/

typedef enum{
			INHIBITED       =0,
			GENERATED
}ErrorTnterrupt_t;
/******************************************************************************/
/************************ @DMAresevier_t **************************************/
/******************************************************************************/

typedef enum{
			DMAR_DISABLE       =0,
			DMAR_ENABLE
}DMAresevier_t;
/******************************************************************************/
/************************ @DMAtransmitter_t ***********************************/
/******************************************************************************/

typedef enum{
			DMAT_DISABLE       =0,
			DMAT_ENABLE
}DMAtransmitter_t;

/********************************************************/
/******* @USARTconfig_t *********************************/
/********************************************************/

typedef struct{
			USARTindex_t                       USARTindex                 ;
			Receiver_t                         Receiver                   ;
			Transmitter_t                      Transmitter                ;
			RXNEinterrupt_t                    RXNEinterrupt              ;
			TransmetCompleteInterrupt_t        TransmetCompleteInterrupt  ;
			TXEinterrupt_t                     TXEinterrupt               ;
			ParitySelection_t                  ParitySelection            ;
			ParityControl_t                    ParityControl              ;
			WordLength_t                       WordLength                 ;
			OverSampling_t                     OverSampling               ;
			StopBit_t                          StopBit_t                  ;
			ErrorTnterrupt_t                   ErrorTnterrupt             ;
			DMAresevier_t                      DMAresevier                ;
			DMAtransmitter_t                   DMAtransmitter             ;
}USARTconfig_t;
/*************************************************************************************************************************************/
/********************************************************* Functions Prototype *******************************************************/
/*************************************************************************************************************************************/


uint8_t MUSART_u8SetConfiguration ( const USARTconfig_t* USARTconfig );

uint8_t  MUSART_u8ReceiveCharSynch     ( USARTindex_t Copy_USARTindex , uint8_t * Copy_pu8DataChar  );

uint8_t  MUSART_u8ReceiveCharNonSynch     ( USARTindex_t Copy_USARTindex ,  uint8_t * Copy_pu8DataChar  );

uint8_t  MUSART_u8ReceiveArraySynch  (  USARTindex_t Copy_USARTindex , uint8_t * Copy_pu8DataArray , uint8_t Copy_u8ArraySize );

uint8_t  MUSART_u8TransmitCharSynch     ( USARTindex_t Copy_USARTindex , uint8_t  Copy_u8DataChar  );

uint8_t  MUSART_u8TransmitArraySynch  ( USARTindex_t Copy_USARTindex , uint8_t * Copy_pu8DataArray );

uint8_t MUSART_u8TransmitSynch ( USARTindex_t Copy_USARTindex , uint8_t * Copy_pu8DataArray , uint8_t Copy_u8ArraySize );

void   MUSART_voidClearFlags( USARTindex_t Copy_USARTindex );


/*************************************************************************************************************************************/
/*************************************************************************************************************************************/
/*************************************************************************************************************************************/





#endif
