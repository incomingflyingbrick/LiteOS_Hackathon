#ifndef __ADC_H
#define	__ADC_H


#include "stm32f10x.h"

// ע�⣺����ADC�ɼ���IO����û�и��ã�����ɼ���ѹ����Ӱ��
/********************ADC����ͨ�������ţ�����**************************/
#define    macADC_APBxClock_FUN             RCC_APB2PeriphClockCmd

// ������ ADC1/2�����ʹ��ADC3���ж���ص�Ҫ�ĳ�ADC3��
//#define    macADCx                          ADC1
//#define    macADC_CLK                       RCC_APB2Periph_ADC1
#define    macADCx                          ADC2
#define    macADC_CLK                       RCC_APB2Periph_ADC2							
//#define    macADCx                          ADC3
//#define    macADC_CLK                       RCC_APB2Periph_ADC3



#define    macADC_GPIO_APBxClock_FUN        RCC_APB2PeriphClockCmd
#define    macADC_GPIO_CLK                  RCC_APB2Periph_GPIOC  
#define    macADC_PORT                      GPIOC
#define    macADC_PIN                       GPIO_Pin_1
#define    macADC_CHANNEL                   ADC_Channel_11

#define    macSIGNAL_GPIO_APBxClock_FUN        RCC_APB2PeriphClockCmd
#define    macSIGNAL_GPIO_CLK                  RCC_APB2Periph_GPIOB  
#define    macSINGAL_PORT                      GPIOB
#define    macSIGNAL_POUT                      GPIO_Pin_6

#define    Signal_High						GPIO_SetBits(macSINGAL_PORT, macSIGNAL_POUT)							
#define    Signal_Low							GPIO_ResetBits(macSINGAL_PORT,  macSIGNAL_POUT)



/**************************��������********************************/
void               ADCx_Init                               (void);


#endif /* __ADC_H */

