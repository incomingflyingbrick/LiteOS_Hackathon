#ifndef  __WIFI_H
#define	 __WIFI_H



#include "stm32f10x.h"
#include "los_task.h"
#include "bsp_esp8266.h"
#include "los_queue.h"

/********************************** �û���Ҫ���õĲ���**********************************/
#define      macUser_ESP8266_ApSsid                       "TechTemple Office"                //Ҫ���ӵ��ȵ������
#define      macUser_ESP8266_ApPwd                        "f39ac7e2d0"           //Ҫ���ӵ��ȵ����Կ

#define      macUser_ESP8266_TcpServer_IP                 "10.1.17.250"      //Ҫ���ӵķ������� IP
#define      macUser_ESP8266_TcpServer_Port               "65535"               //Ҫ���ӵķ������Ķ˿�



/********************************** �ⲿȫ�ֱ��� ***************************************/
extern volatile uint8_t ucTcpClosedFlag;
extern UINT32 g_uwQueue;
extern EVENT_CB_S WIFI_event;

/********************************** ���Ժ������� ***************************************/
void                     ESP8266_StaTcpClient_UnvarnishTest  ( void );



#endif

