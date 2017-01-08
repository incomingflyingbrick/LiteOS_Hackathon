#include "pm2d5.h"

static void delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
}


float Get_PM2d5(void)
{
		uint16_t tmp = 0;
		float pm = 0;
		ADC_SoftwareStartConvCmd(macADCx, ENABLE);// ����û�в����ⲿ����������ʹ���������ADCת�� 
		Signal_Low;
		delay(500);
		tmp = ADC_GetConversionValue(macADCx);	
		delay(40);
		Signal_High;
		//Delay(30);
		pm = 0.17*tmp-0.1;
		printf("\r\n The current AD value = %f \r\n", pm); 
		printf("\r\n\r\n");
		return pm;
}


