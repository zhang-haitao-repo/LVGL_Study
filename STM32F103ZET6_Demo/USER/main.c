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

int i = 0;
lv_obj_t *obj;
lv_obj_t *arc;

void lv_demo()
{
	
    static lv_style_t style;
    
		obj = lv_obj_create(lv_scr_act());
		arc = lv_arc_create(obj);

    
    lv_obj_set_size(obj, 220, 220);

    lv_style_init(&style);
    lv_style_set_arc_color(&style, lv_palette_main(LV_PALETTE_RED));
    lv_style_set_arc_width(&style, 4);

    lv_obj_set_size(arc, 190, 190);


    lv_obj_add_style(arc, &style, 0);

    lv_obj_center(obj);
    lv_obj_center(arc);
}

static lv_obj_t * meter;

static void set_value(void * indic, int32_t v)
{
    lv_meter_set_indicator_end_value(meter, indic, v);
}

void lv_example_meter_3(void)
{
    meter = lv_meter_create(lv_scr_act());
    lv_obj_set_size(meter, 220, 220);
    lv_obj_center(meter);

    /*Create a scale for the minutes*/
    /*61 ticks in a 360 degrees range (the last and the first line overlaps)*/
    lv_meter_scale_t * scale_min = lv_meter_add_scale(meter);
    lv_meter_set_scale_ticks(meter, scale_min, 61, 1, 10, lv_palette_main(LV_PALETTE_GREY));
    lv_meter_set_scale_range(meter, scale_min, 0, 60, 360, 270);

    /*Create another scale for the hours. It's only visual and contains only major ticks*/
    lv_meter_scale_t * scale_hour = lv_meter_add_scale(meter);
    lv_meter_set_scale_ticks(meter, scale_hour, 12, 0, 0, lv_palette_main(LV_PALETTE_GREY));               /*12 ticks*/
    lv_meter_set_scale_major_ticks(meter, scale_hour, 1, 2, 20, lv_color_black(), 10);    /*Every tick is major*/
    lv_meter_set_scale_range(meter, scale_hour, 1, 12, 330, 300);       /*[1..12] values in an almost full circle*/

    LV_IMG_DECLARE(img_hand)

//    /*Add a the hands from images*/
    lv_meter_indicator_t * indic_min = lv_meter_add_needle_img(meter, scale_min, &img_hand, 5, 5);
    lv_meter_indicator_t * indic_hour = lv_meter_add_needle_img(meter, scale_min, &img_hand, 5, 5);

    /*Create an animation to set the value*/
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_exec_cb(&a, set_value);
    lv_anim_set_values(&a, 0, 60);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_time(&a, 60000);     /*2 sec for 1 turn of the minute hand (1 hour)*/
    lv_anim_set_var(&a, indic_min);
    lv_anim_start(&a);

    lv_anim_set_var(&a, indic_hour);
    lv_anim_set_time(&a, 60*60000);    /*24 sec for 1 turn of the hour hand*/
    lv_anim_set_values(&a, 0, 60);
    lv_anim_start(&a);
}

void lv_demo_pic()
{
	LV_IMG_DECLARE(leimu_1)
	lv_obj_t * img1 = lv_img_create(lv_scr_act());
	lv_img_set_src(img1, &leimu_1);
	lv_obj_align(img1, LV_ALIGN_CENTER, 0, -20);
	lv_obj_set_size(img1, 240, 240);

	lv_obj_center(img1);
	
	
}

int main(void)
{
	int j = 0;
	delay_init();
	LED_Init();//LED初始化
	TIM4_Init(999,71);
	LCD_Init();//LCD初始化
	// LCD_Fill(0,0,LCD_W,LCD_H,WHITE);
	// LED0=0;
	
	lv_init();
	lv_port_disp_init();
	lv_demo_pic();
	while(1)
	{
		lv_timer_handler();
		delay_ms(5);
	}
}

