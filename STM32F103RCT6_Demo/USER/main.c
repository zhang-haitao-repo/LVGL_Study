//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//�о�԰����
//���̵�ַ��http://shop73023976.taobao.com
//
//  �� �� ��   : main.c
//  �� �� ��   : v2.0
//  ��    ��   : HuangKai
//  ��������   : 2018-10-31
//  ����޸�   : 
//  ��������   :��ʾ����(STM32F103ϵ��)
//              ˵��: 
//              ----------------------------------------------------------------
//              GND   ��Դ��
//              VCC   3.3v��Դ
//              SCL   PG12��SCLK��
//              SDA   PD5��MOSI��
//              RES   PD4
//              DC    PD15
//              CS    PD1
//              BLK   PE8
//              ----------------------------------------------------------------
// �޸���ʷ   :
// ��    ��   : 
// ��    ��   : HuangKai
// �޸�����   : �����ļ�
//��Ȩ���У�����ؾ���
//Copyright(C) �о�԰����2018-10-31
//All rights reserved
//******************************************************************************/
#include "delay.h"
#include "sys.h"
#include "stm32f10x_tim.h"
#include "led.h"
#include "lcd_init.h"
#include "lcd.h"
#include "pic.h"
#include "lv_port_disp.h"
#include "lvgl.h"
#include "lv_examples.h"
#include "FreeRTOS.h"
#include "task.h"

void TIM4_Init(uint16_t arr, uint16_t psc);

int flag_num = 1, lcd_num = 0;

void TIM2_Init(uint16_t arr, uint16_t psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

	NVIC_InitTypeDef NVIC_InitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); 
	TIM_TimeBaseStructure.TIM_Period = arr; 
	TIM_TimeBaseStructure.TIM_Prescaler =psc; 
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); 
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE ); 

	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn; 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4; 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 

	NVIC_Init(&NVIC_InitStructure); 

	TIM_Cmd(TIM2, ENABLE); 
}

void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2, TIM_IT_Update))
	{
		lv_tick_inc(1);
		flag_num++;
		if(flag_num >= 1000){
			lcd_num++;
			LED1 = lcd_num % 2;
			flag_num = 0;
		}
	}
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
}

/************************************************
������ʼ����
************************************************/
//�������ȼ�
#define START_TASK_PRIO 2
//�����ջ��С
#define START_STK_SIZE 128
//������
TaskHandle_t StartHandle;
//������
void startTask(void *pvParameters);

/************************************************
����GUI����
************************************************/
//�������ȼ�
#define GUI_TASK_PRIO 3
//�����ջ��С
#define GUI_STK_SIZE 128
//������
TaskHandle_t GuiHandle;
//������
void guiTask(void *pvParameters);

void lv_demo_pic()
{
	LV_IMG_DECLARE(leimu)
	lv_obj_t * img1 = lv_img_create(lv_scr_act());
	lv_img_set_src(img1, &leimu);
	lv_obj_align(img1, LV_ALIGN_CENTER, 0, -20);
	lv_obj_set_size(img1, 240, 240);

	lv_obj_center(img1);
}


int main(void)
{
	delay_init();
	LED_Init();//LED��ʼ��
	// TIM2_Init(999,71);
	LCD_Init();//LCD��ʼ��
//	lv_init();
//	lv_port_disp_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//����ϵͳ�ж����ȼ�����4	 
	
//	lv_demo_pic();
	
	xTaskCreate(startTask, "startTask", START_STK_SIZE, NULL, START_TASK_PRIO, &StartHandle);
	xTaskCreate(guiTask, "guiTask", GUI_STK_SIZE, NULL, GUI_TASK_PRIO, &GuiHandle);
	vTaskStartScheduler(); // �����������
	
	while(1)
	{

	}
}

// ��ʼ������
void startTask(void *pvParameters)
{
	
	while(1)
	{
		LED0 = 0;
		delay_xms(500);
		LED0 = 1;
		delay_xms(500);
	}
}

// ��ʾ������
void guiTask(void *pvParameters)
{
	
	
	while(1)
	{
		vTaskDelay(5);
//		lv_timer_handler();
	}
}

