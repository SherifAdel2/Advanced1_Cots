
#include <stdio.h>
#include <stdint.h>
#include "../../LIB/Stm32F466xx.h"
#include "../../LIB/ErrorType.h"

#include "DMA1_private.h"
#include "DMA1_config.h"
#include "DMA1_interface.h"

static void (*ptr_callBack[9])(void);
uint8_t DMA1_init(DMA1_CONFIGRATION_t* config)
{
	uint8_t Local_u8ErrorState = OK;

	if(config!=NULL)
	{
		if(config->channelNum>CHANNEL7||config->streamNum>STREAM7)
		{
			Local_u8ErrorState = NOK;

		}
		/*****choose channel******/
		DMA1_SCRx(config->streamNum)&=~(DMA1_CHSEL_MASK<<DMA1_SCR_CHSEL);
		DMA1_SCRx(config->streamNum)|=(config->channelNum<<DMA1_SCR_CHSEL);
		/*****choose priority******/
		DMA1_SCRx(config->streamNum)&=~(DMA1_PRIORITY_MASK <<DMA1_SCR_PRIORITY );
		DMA1_SCRx(config->streamNum)|=(config->priority<<DMA1_SCR_PRIORITY );
		/*****choose increment mode for periphral******/
		DMA1_SCRx(config->streamNum)&=~( DMA1_PINC_MASK <<DMA1_SCR_PINC );
		DMA1_SCRx(config->streamNum)|=(config->Periphral_state<<DMA1_SCR_PINC );
		/*****choose increment mode for memory******/
		DMA1_SCRx(config->streamNum)&=~(DMA1_MINC_MASK<<DMA1_SCR_MINC );
		DMA1_SCRx(config->streamNum)|=(config->Memory_state<<DMA1_SCR_MINC );
		/*****choose Transmition_type******/
		DMA1_SCRx(config->streamNum)&=~(DMA1_TRANSIMITION_MODE_MASK <<DMA1_SCR_DMA1_TRANSIMITION_MODE );
		DMA1_SCRx(config->streamNum)|=(config->transimition_mode<<DMA1_SCR_DMA1_TRANSIMITION_MODE );
		/**enable interrupt***/
		DMA1_SCRx(config->streamNum)|=(1<<4);

		/******* configure mode*****/
		DMA1_SFCRx(config->streamNum)&=~(DMA1_MODE_MASK <<DMA1_SCR_MODE);
		DMA1_SFCRx(config->streamNum)|=(config->mode<<DMA1_SCR_MODE);
		/***thrsholderselectoin*****/
		DMA1_SFCRx(config->streamNum)&=~(DMA1_THRESHOLDER_MASK );
		DMA1_SFCRx(config->streamNum)|=(config->thresholder);
		/****transmition size****/
		DMA1_SCRx(config->streamNum)&=~(DMA1_TRANSIMITION_SIZE_MASK <<DMA1_SCR_PSIZE);
		DMA1_SCRx(config->streamNum)|=(config->Transmition_size<<DMA1_SCR_PSIZE);
		DMA1_SCRx(config->streamNum)&=~(DMA1_TRANSIMITION_SIZE_MASK <<DMA1_SCR_MSIZE);
		DMA1_SCRx(config->streamNum)|=(config->Transmition_size<<DMA1_SCR_MSIZE);

	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}
	return Local_u8ErrorState;
}
void DMA1_send_Data(DMA1_CONFIGRATION_t* config,uint32_t* src_address,uint32_t* destination_address,uint16_t  size)
{
	DMA1_SNDTRx(config->streamNum)=size;
	DMA1_SPARx(config->streamNum)=src_address;
	DMA1_SM0ARx(config->streamNum)=destination_address;
	DMA1_SCRx(config->streamNum)|=(1<<0);
}
uint8_t DMA1_setCallBack(DMA1_STREAM_t stream,void (*ptr)(void))
{
	uint8_t Local_u8ErrorState = OK;

	if(ptr!=NULL)
	{
		if(stream>7)
		{
			Local_u8ErrorState=NOK;
		}
		ptr_callBack[stream]=ptr;
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}
void DMA1_Stream0_IRQHandler()
{
	DMA1_IFCR[DMA1_IFCR_LOW]=(DMA1_HIGH <<DMA1_LIFCR_CTCIF0);
	ptr_callBack[STREAM0]();
}
void DMA1_Stream1_IRQHandler()
{
	DMA1_IFCR[DMA1_IFCR_LOW]=(DMA1_HIGH <<DMA1_LIFCR_CTCIF1);
	ptr_callBack[STREAM1]();
}
void DMA1_Stream2_IRQHandler()
{
	DMA1_IFCR[DMA1_IFCR_LOW]=(DMA1_HIGH <<DMA1_LIFCR_CTCIF2);
	ptr_callBack[STREAM2]();
}
void DMA1_Stream3_IRQHandler()
{
	DMA1_IFCR[DMA1_IFCR_LOW]=(DMA1_HIGH <<DMA1_LIFCR_CTCIF3);
	ptr_callBack[STREAM3]();
}
void DMA1_Stream4_IRQHandler()
{
	DMA1_IFCR[DMA1_IFCR_HIGH]=(DMA1_HIGH <<DMA1_HIFCR_CTCIF4);
	ptr_callBack[STREAM4]();
}
void DMA1_Stream5_IRQHandler()
{
	DMA1_IFCR[DMA1_IFCR_HIGH]=(DMA1_HIGH <<DMA1_HIFCR_CTCIF5);
	ptr_callBack[STREAM5]();
}
void DMA1_Stream6_IRQHandler()
{
	DMA1_IFCR[DMA1_IFCR_HIGH]=(DMA1_HIGH <<DMA1_HIFCR_CTCIF6);
	ptr_callBack[STREAM6]();
}
void DMA1_Stream7_IRQHandler()
{
	DMA1_IFCR[DMA1_IFCR_HIGH]=(DMA1_HIGH <<DMA1_HIFCR_CTCIF7);
	ptr_callBack[STREAM7]();
}


