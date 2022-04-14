//
// Created by Administrator on 2022/4/6.
//

#ifndef LCDPROJECT_LCD_INIT_H
#define LCDPROJECT_LCD_INIT_H

#include <stdint-gcc.h>
#include <main.h>
#include "cmsis_os.h"
#include "delay.h"

#define USE_HORIZONTAL 0  //


#define LCD_W 240
#define LCD_H 240


#define LCD_SCLK_Clr() HAL_GPIO_WritePin(GPIO_CLK_GPIO_Port, GPIO_CLK_Pin, GPIO_PIN_RESET)
#define LCD_SCLK_Set() HAL_GPIO_WritePin(GPIO_CLK_GPIO_Port, GPIO_CLK_Pin, GPIO_PIN_SET)

#define LCD_MOSI_Clr() HAL_GPIO_WritePin(GPIO_MISO_GPIO_Port, GPIO_MISO_Pin, GPIO_PIN_RESET)//SDA=MOSI
#define LCD_MOSI_Set() HAL_GPIO_WritePin(GPIO_MISO_GPIO_Port, GPIO_MISO_Pin, GPIO_PIN_SET)

#define LCD_RES_Clr()  HAL_GPIO_WritePin(GPIO_RES_GPIO_Port, GPIO_RES_Pin, GPIO_PIN_RESET)//RES
#define LCD_RES_Set()  HAL_GPIO_WritePin(GPIO_RES_GPIO_Port, GPIO_RES_Pin, GPIO_PIN_SET)

#define LCD_DC_Clr()   HAL_GPIO_WritePin(GPIO_DC_GPIO_Port, GPIO_DC_Pin, GPIO_PIN_RESET)//DC
#define LCD_DC_Set()   HAL_GPIO_WritePin(GPIO_DC_GPIO_Port, GPIO_DC_Pin, GPIO_PIN_SET)

#define LCD_CS_Clr()   HAL_GPIO_WritePin(GPIO_CS_GPIO_Port, GPIO_CS_Pin, GPIO_PIN_RESET)//CS
#define LCD_CS_Set()   HAL_GPIO_WritePin(GPIO_CS_GPIO_Port, GPIO_CS_Pin, GPIO_PIN_SET)

#define LCD_BLK_Clr()  HAL_GPIO_WritePin(GPIO_BLK_GPIO_Port, GPIO_BLK_Pin, GPIO_PIN_RESET)//BLK
#define LCD_BLK_Set()  HAL_GPIO_WritePin(GPIO_BLK_GPIO_Port, GPIO_BLK_Pin, GPIO_PIN_SET)

void LCD_Writ_Bus(uint8_t dat);
void LCD_WR_DATA8(uint8_t dat);
void LCD_WR_DATA(uint16_t dat);
void LCD_WR_REG(uint8_t dat);
void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);
void LCD_Init(void);

#endif //LCDPROJECT_LCD_INIT_H
