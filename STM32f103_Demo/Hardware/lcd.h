//
// Created by Administrator on 2022/4/6.
//

#ifndef LCDPROJECT_LCD_H
#define LCDPROJECT_LCD_H
#include "main.h"

void LCD_Fill(uint16_t xsta,uint16_t ysta,uint16_t xend,uint16_t yend,uint16_t color);//Ö¸¶¨ÇøÓòÌî³äÑÕÉ«
void LCD_DrawPoint(uint16_t x,uint16_t y,uint16_t color);//ÔÚÖ¸¶¨Î»ÖÃ»­Ò»¸öµã
void LCD_DrawLine(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color);//ÔÚÖ¸¶¨Î»ÖÃ»­Ò»ÌõÏß
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,uint16_t color);//ÔÚÖ¸¶¨Î»ÖÃ»­Ò»¸ö¾ØÐÎ
void Draw_Circle(uint16_t x0,uint16_t y0,uint8_t r,uint16_t color);//ÔÚÖ¸¶¨Î»ÖÃ»­Ò»¸öÔ²

void LCD_ShowChinese(uint16_t x,uint16_t y,uint8_t *s,uint16_t fc,uint16_t bc,uint8_t sizey,uint8_t mode);//ÏÔÊ¾ºº×Ö´®
void LCD_ShowChinese12x12(uint16_t x,uint16_t y,uint8_t *s,uint16_t fc,uint16_t bc,uint8_t sizey,uint8_t mode);//ÏÔÊ¾µ¥¸ö12x12ºº×Ö
void LCD_ShowChinese16x16(uint16_t x,uint16_t y,uint8_t *s,uint16_t fc,uint16_t bc,uint8_t sizey,uint8_t mode);//ÏÔÊ¾µ¥¸ö16x16ºº×Ö
void LCD_ShowChinese24x24(uint16_t x,uint16_t y,uint8_t *s,uint16_t fc,uint16_t bc,uint8_t sizey,uint8_t mode);//ÏÔÊ¾µ¥¸ö24x24ºº×Ö
void LCD_ShowChinese32x32(uint16_t x,uint16_t y,uint8_t *s,uint16_t fc,uint16_t bc,uint8_t sizey,uint8_t mode);//ÏÔÊ¾µ¥¸ö32x32ºº×Ö

void LCD_ShowChar(uint16_t x,uint16_t y,uint8_t num,uint16_t fc,uint16_t bc,uint8_t sizey,uint8_t mode);//ÏÔÊ¾Ò»¸ö×Ö·û
void LCD_ShowString(uint16_t x,uint16_t y,const uint8_t *p,uint16_t fc,uint16_t bc,uint8_t sizey,uint8_t mode);//ÏÔÊ¾×Ö·û´®
uint32_t mypow(uint8_t m,uint8_t n);//ÇóÃÝ
void LCD_ShowIntNum(uint16_t x,uint16_t y,uint16_t num,uint8_t len,uint16_t fc,uint16_t bc,uint8_t sizey);//ÏÔÊ¾ÕûÊý±äÁ¿
void LCD_ShowFloatNum1(uint16_t x,uint16_t y,float num,uint8_t len,uint16_t fc,uint16_t bc,uint8_t sizey);//ÏÔÊ¾Á½Î»Ð¡Êý±äÁ¿

void LCD_ShowPicture(uint16_t x,uint16_t y,uint16_t length,uint16_t width,const uint8_t pic[]);//ÏÔÊ¾Í¼Æ¬

#define WHITE         	 0xFFFF
#define BLACK         	 0x0000
#define BLUE           	 0x001F
#define BRED             0XF81F
#define GRED 			       0XFFE0
#define GBLUE			       0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40
#define BRRED 			 0XFC07
#define GRAY  			 0X8430
#define DARKBLUE      	 0X01CF
#define LIGHTBLUE      	 0X7D7C
#define GRAYBLUE       	 0X5458
#define LIGHTGREEN     	 0X841F
#define LGRAY 			 0XC618
#define LGRAYBLUE        0XA651
#define LBBLUE           0X2B12

#endif //LCDPROJECT_LCD_H
