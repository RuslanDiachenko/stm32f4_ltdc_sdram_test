#ifndef LTDC_H
#define LTDC_H

#include "stm32f4xx_hal.h"
#include <string.h>
#include <stdlib.h>

#define LCD_SLEEP_OUT            0x11   /* Sleep out register */
#define LCD_GAMMA                0x26   /* Gamma register */
#define LCD_DISPLAY_OFF          0x28   /* Display off register */
#define LCD_DISPLAY_ON           0x29   /* Display on register */
#define LCD_COLUMN_ADDR          0x2A   /* Colomn address register */
#define LCD_PAGE_ADDR            0x2B   /* Page address register */
#define LCD_GRAM                 0x2C   /* GRAM register */
#define LCD_MAC                  0x36   /* Memory Access Control register*/
#define LCD_PIXEL_FORMAT         0x3A   /* Pixel Format register */
#define LCD_WDB                  0x51   /* Write Brightness Display register */
#define LCD_WCD                  0x53   /* Write Control Display register*/
#define LCD_RGB_INTERFACE        0xB0   /* RGB Interface Signal Control */
#define LCD_FRC                  0xB1   /* Frame Rate Control register */
#define LCD_BPC                  0xB5   /* Blanking Porch Control register*/
#define LCD_DFC                  0xB6   /* Display Function Control register*/
#define LCD_POWER1               0xC0   /* Power Control 1 register */
#define LCD_POWER2               0xC1   /* Power Control 2 register */
#define LCD_VCOM1                0xC5   /* VCOM Control 1 register */
#define LCD_VCOM2                0xC7   /* VCOM Control 2 register */
#define LCD_POWERA               0xCB   /* Power control A register */
#define LCD_POWERB               0xCF   /* Power control B register */
#define LCD_PGAMMA               0xE0   /* Positive Gamma Correction register*/
#define LCD_NGAMMA               0xE1   /* Negative Gamma Correction register*/
#define LCD_DTCA                 0xE8   /* Driver timing control A */
#define LCD_DTCB                 0xEA   /* Driver timing control B */
#define LCD_POWER_SEQ            0xED   /* Power on sequence register */
#define LCD_3GAMMA_EN            0xF2   /* 3 Gamma enable register */
#define LCD_INTERFACE            0xF6   /* Interface control register */
#define LCD_PRC                  0xF7   /* Pump ratio control register */

void LCD_PowerOn(void);
void LCD_WriteCommand(uint8_t com);
void LCD_WriteData(uint8_t data);

void LCD_Test(void);
void LCD_FillScreen_565(uint32_t color);
void LCD_FillRectangle_565(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
void LCD_DrawPixel_565(uint32_t x, uint32_t y, uint16_t color);
void LCD_DrawLine_565(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t color);

void LCD_FillScreen(uint32_t color);
void LCD_FillRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
void LCD_DrawPixel(uint32_t x, uint32_t y, uint16_t color);
void LCD_DrawLine(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t color);

#endif /* LTDC_H */
