//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//中景园电子
//店铺地址：http://shop73023976.taobao.com
//
//  文 件 名   : main.c
//  版 本 号   : v2.0
//  作    者   : HuangKai
//  生成日期   : 2018-10-31
//  最近修改   : 
//  功能描述   :演示例程(STM32F103系列)
//              说明: 
//              ----------------------------------------------------------------
//              GND   电源地
//              VCC   3.3v电源
//              SCL   PG12（SCLK）
//              SDA   PD5（MOSI）
//              RES   PD4
//              DC    PD15
//              CS    PD1
//              BLK   PE8
//              ----------------------------------------------------------------
// 修改历史   :
// 日    期   : 
// 作    者   : HuangKai
// 修改内容   : 创建文件
//版权所有，盗版必究。
//Copyright(C) 中景园电子2018-10-31
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

void TIM4_Init(uint16_t arr, uint16_t psc);


int flag_num = 1, lcd_num = 0;

void TIM4_Init(uint16_t arr, uint16_t psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

	NVIC_InitTypeDef NVIC_InitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE); 
	TIM_TimeBaseStructure.TIM_Period = arr; 
	TIM_TimeBaseStructure.TIM_Prescaler =psc; 
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); 
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE ); 

	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn; 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4; 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 

	NVIC_Init(&NVIC_InitStructure); 

	TIM_Cmd(TIM4, ENABLE); 
}

void TIM4_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM4, TIM_IT_Update))
	{
		lv_tick_inc(1);
//		flag_num++;
//		if(flag_num >= 1000){
//			lcd_num++;
//			flag_num = 0;
//		}
	}
	TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
}

int main(void)
{
	delay_init();
	LED_Init();//LED初始化
	TIM4_Init(999,71);
	LCD_Init();//LCD初始化
	// LCD_Fill(0,0,LCD_W,LCD_H,WHITE);
	// LED0=0;
	
	lv_init();
	lv_port_disp_init();
	lv_example_meter_1();
	while(1)
	{
		lv_timer_handler();
		delay_ms(5);
	}
}

