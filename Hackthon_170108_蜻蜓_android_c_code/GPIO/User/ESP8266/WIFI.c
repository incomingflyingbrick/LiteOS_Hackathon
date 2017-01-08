#include "WIFI.h"
#include <stdio.h>  
#include <string.h>  
#include <stdbool.h>
#include "bsp_esp8266.h"


volatile uint8_t ucTcpClosedFlag = 0;

char cStr [ 1500 ] = { 0 };
#define event_PM2d5_finish 	0x00000002


/**
  * @brief  ESP8266 ��Sta Tcp Client��͸��
  * @param  ��
  * @retval ��
  */
void ESP8266_StaTcpClient_UnvarnishTest ( void )
{
	uint8_t ucStatus;
	
	char cStr [ 100 ] = { 0 };
	char tmp[20];
		
  printf ( "\r\n�������� ESP8266 ......\r\n" );

	macESP8266_CH_ENABLE();							//ʹ�� macESP8266ģ��
	
	ESP8266_AT_Test ();									//��WF-ESP8266ģ�����AT��������
	
	ESP8266_Net_Mode_Choose ( STA );		//ѡ��WF-ESP8266ģ��Ĺ���ģʽ

  while ( ! ESP8266_JoinAP ( macUser_ESP8266_ApSsid, macUser_ESP8266_ApPwd ) );	//WF-ESP8266ģ�������ⲿWiFi
	
	ESP8266_Enable_MultipleId ( DISABLE );//�����Ƿ������
	ESP8266_Inquire_ApIp(tmp,10);
	printf("%s",tmp);
	printf("\r\n");
	printf("------------------------");
	while ( !	ESP8266_Link_Server ( enumTCP, macUser_ESP8266_TcpServer_IP, macUser_ESP8266_TcpServer_Port, Single_ID_0 ) );//WF-ESP8266ģ�������ⲿ������
	printf("linkSer OK");
	while ( ! ESP8266_UnvarnishSend () );//�ȴ�����WF-ESP8266ģ�����͸�����ͳɹ�
	
	printf ( "\r\n���� ESP8266 ���\r\n" );
	
	
	while ( 1 )
	{		
		float *pm2d5 = 0;
		UINT32 uwEvent;
		//printf ( "\r\n1gjfyu\r\n" );
		uwEvent = LOS_EventRead(&WIFI_event, event_PM2d5_finish, LOS_WAITMODE_OR, 1500);//����WiFi�¼�ͬ������
		printf ( "\r\n���� 123 ���\r\n" );
		if(uwEvent == event_PM2d5_finish)
		{
			LOS_QueueRead(g_uwQueue, &pm2d5, 4, 0);
			
			sprintf ( cStr,"%.2f\r\n", *pm2d5);
			
			ESP8266_SendString ( ENABLE, cStr, 0, Single_ID_0 );               //��������
			//ESP8266_SendString ( ENABLE, "500\r\n", 0, Single_ID_0 );
		}
			
		LOS_TaskDelay ( 5000 );
		
		if ( ucTcpClosedFlag )                                             //����Ƿ�ʧȥ����
		{
			ESP8266_ExitUnvarnishSend ();                                    //�˳�͸��ģʽ
			
			do ucStatus = ESP8266_Get_LinkStatus ();                         //��ȡ����״̬
			while ( ! ucStatus );
			
			if ( ucStatus == 4 )                                             //ȷ��ʧȥ���Ӻ�����
			{
				printf ( "\r\n���������ȵ�ͷ����� ......\r\n" );
				
				while ( ! ESP8266_JoinAP ( macUser_ESP8266_ApSsid, macUser_ESP8266_ApPwd ) );
				
				while ( !	ESP8266_Link_Server ( enumTCP, macUser_ESP8266_TcpServer_IP, macUser_ESP8266_TcpServer_Port, Single_ID_0 ) );
				
				printf ( "\r\n�����ȵ�ͷ������ɹ�\r\n" );

			}
			
			while ( ! ESP8266_UnvarnishSend () );		
			
		}
	}
	
		
}


