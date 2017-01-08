#include "bsp_adc.h"

__IO uint16_t ADC_ConvertedValue;


/**
  * @brief  ADC GPIO ��ʼ��
  * @param  ��
  * @retval ��
  */
static void ADCx_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// �� �˿�ʱ��
	macADC_GPIO_APBxClock_FUN ( macADC_GPIO_CLK, ENABLE );
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph,ENABLE)
	// ���� ADC IO ����ģʽ
	GPIO_InitStructure.GPIO_Pin = macADC_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;	
	GPIO_Init(macADC_PORT, &GPIO_InitStructure);		

	RCC_APB2PeriphClockCmd(macSIGNAL_GPIO_CLK,ENABLE);
	GPIO_InitStructure.GPIO_Pin = macSIGNAL_POUT;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(macSINGAL_PORT, &GPIO_InitStructure);
}
 

/**
  * @brief  ����ADC����ģʽ
  * @param  ��
  * @retval ��
  */
static void ADCx_Mode_Config(void)
{
	ADC_InitTypeDef ADC_InitStructure;	

	// ��ADCʱ��
	macADC_APBxClock_FUN ( macADC_CLK, ENABLE );
	
	// ADC ģʽ����
	// ֻʹ��һ��ADC�����ڵ�ģʽ
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	
	// ��ֹɨ��ģʽ����ͨ����Ҫ����ͨ������Ҫ
	ADC_InitStructure.ADC_ScanConvMode = DISABLE ; 

	// ����ת��ģʽ
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;

	// �����ⲿ����ת���������������
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;

	// ת������Ҷ���
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	
	// ת��ͨ��1��
	ADC_InitStructure.ADC_NbrOfChannel = 1;	
		
	// ��ʼ��ADC
	ADC_Init(macADCx, &ADC_InitStructure);
	
	// ����ADCʱ�ӣΪPCLK2��8��Ƶ����9MHz
	RCC_ADCCLKConfig(RCC_PCLK2_Div8); 
	
	// ���� ADC ͨ��ת��˳��Ϊ1����һ��ת��������ʱ��Ϊ55.5��ʱ������
	ADC_RegularChannelConfig(macADCx, macADC_CHANNEL, 1, ADC_SampleTime_55Cycles5);
	
	// ADC ת�����������жϣ����жϷ�������ж�ȡת��ֵ
	ADC_ITConfig(macADCx, ADC_IT_EOC, DISABLE);
	
	// ����ADC ������ʼת��
	ADC_Cmd(macADCx, ENABLE);
	
	// ��ʼ��ADC У׼�Ĵ���  
	ADC_ResetCalibration(macADCx);
	// �ȴ�У׼�Ĵ�����ʼ�����
	while(ADC_GetResetCalibrationStatus(macADCx));
	
	// ADC��ʼУ׼
	ADC_StartCalibration(macADCx);
	// �ȴ�У׼���
	while(ADC_GetCalibrationStatus(macADCx));
	
	
}



/**
  * @brief  ADC��ʼ��
  * @param  ��
  * @retval ��
  */
void ADCx_Init(void)
{
	ADCx_GPIO_Config();
	ADCx_Mode_Config();
	//ADC_NVIC_Config();
}
/*********************************************END OF FILE**********************/
