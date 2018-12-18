#ifndef LTDC_H
#define LTDC_H

#include "stm32f4xx_hal.h"
#include "fonts.h"
#include <string.h>
#include <stdlib.h>

/* Colors */

#define MyLCD_COLOR_BLUE ((uint32_t)0x0000FF)
#define MyLCD_COLOR_GREEN ((uint32_t)0x00FF00)
#define MyLCD_COLOR_RED ((uint32_t)0xFF0000)
#define MyLCD_COLOR_CYAN ((uint32_t)0x00FFFF)
#define MyLCD_COLOR_MAGENTA ((uint32_t)0xFF00FF)
#define MyLCD_COLOR_YELLOW ((uint32_t)0xFFFF00)
#define MyLCD_COLOR_LIGHTBLUE ((uint32_t)0x8080FF)
#define MyLCD_COLOR_LIGHTGREEN ((uint32_t)0x80FF80)
#define MyLCD_COLOR_LIGHTRED ((uint32_t)0xFF8080)
#define MyLCD_COLOR_LIGHTCYAN ((uint32_t)0x80FFFF)
#define MyLCD_COLOR_LIGHTMAGENTA ((uint32_t)0xFF80FF)
#define MyLCD_COLOR_LIGHTYELLOW ((uint32_t)0xFFFF80)
#define MyLCD_COLOR_DARKBLUE ((uint32_t)0x000080)
#define MyLCD_COLOR_DARKGREEN ((uint32_t)0x008000)
#define MyLCD_COLOR_DARKRED ((uint32_t)0x800000)
#define MyLCD_COLOR_DARKCYAN ((uint32_t)0x008080)
#define MyLCD_COLOR_DARKMAGENTA ((uint32_t)0x800080)
#define MyLCD_COLOR_DARKYELLOW ((uint32_t)0x808000)
#define MyLCD_COLOR_WHITE ((uint32_t)0xFFFFFF)
#define MyLCD_COLOR_LIGHTGRAY ((uint32_t)0xD3D3D3)
#define MyLCD_COLOR_GRAY ((uint32_t)0x808080)
#define MyLCD_COLOR_DARKGRAY ((uint32_t)0x404040)
#define MyLCD_COLOR_BLACK ((uint32_t)0x000000)
#define MyLCD_COLOR_BROWN ((uint32_t)0xA52A2A)
#define MyLCD_COLOR_ORANGE ((uint32_t)0xFFA500)
#define MyLCD_COLOR_TRANSPARENT ((uint32_t)0x000000)

/* Registers */
#define MyLCD_SLEEP_OUT            0x11   /* Sleep out register */
#define MyLCD_GAMMA                0x26   /* Gamma register */
#define MyLCD_DISPLAY_OFF          0x28   /* Display off register */
#define MyLCD_DISPLAY_ON           0x29   /* Display on register */
#define MyLCD_COLUMN_ADDR          0x2A   /* Colomn address register */
#define MyLCD_PAGE_ADDR            0x2B   /* Page address register */
#define MyLCD_GRAM                 0x2C   /* GRAM register */
#define MyLCD_MAC                  0x36   /* Memory Access Control register*/
#define MyLCD_PIXEL_FORMAT         0x3A   /* Pixel Format register */
#define MyLCD_WDB                  0x51   /* Write Brightness Display register */
#define MyLCD_WCD                  0x53   /* Write Control Display register*/
#define MyLCD_RGB_INTERFACE        0xB0   /* RGB Interface Signal Control */
#define MyLCD_FRC                  0xB1   /* Frame Rate Control register */
#define MyLCD_BPC                  0xB5   /* Blanking Porch Control register*/
#define MyLCD_DFC                  0xB6   /* Display Function Control register*/
#define MyLCD_POWER1               0xC0   /* Power Control 1 register */
#define MyLCD_POWER2               0xC1   /* Power Control 2 register */
#define MyLCD_VCOM1                0xC5   /* VCOM Control 1 register */
#define MyLCD_VCOM2                0xC7   /* VCOM Control 2 register */
#define MyLCD_POWERA               0xCB   /* Power control A register */
#define MyLCD_POWERB               0xCF   /* Power control B register */
#define MyLCD_PGAMMA               0xE0   /* Positive Gamma Correction register*/
#define MyLCD_NGAMMA               0xE1   /* Negative Gamma Correction register*/
#define MyLCD_DTCA                 0xE8   /* Driver timing control A */
#define MyLCD_DTCB                 0xEA   /* Driver timing control B */
#define MyLCD_POWER_SEQ            0xED   /* Power on sequence register */
#define MyLCD_3GAMMA_EN            0xF2   /* 3 Gamma enable register */
#define MyLCD_INTERFACE            0xF6   /* Interface control register */
#define MyLCD_PRC                  0xF7   /* Pump ratio control register */

typedef struct
{
  uint32_t TextColor;
  uint32_t BackColor;
  sFONT *pFont;
}MyLCD_DrawPropTypeDef;

typedef enum
{
  CENTER_MODE = 0x01, /* Center mode */
  RIGHT_MODE = 0x02, /* Right mode */
  LEFT_MODE = 0x03 /* Left mode */
}Text_AlignModeTypdef;


void MyLCD_PowerOn(void);
void MyLCD_WriteCommand(uint8_t com);
void MyLCD_WriteData(uint8_t data);

void MyLCD_Test(void);

/* Primitive graphics */
void MyLCD_FillScreen(uint32_t color);
void MyLCD_FillRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint32_t color);
void MyLCD_DrawPixel(uint32_t x, uint32_t y, uint32_t color);
void MyLCD_DrawLine(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t color);

/* Text */
void MyLCD_FontsInit(void);
void MyLCD_SetFont(sFONT *fonts);
void MyLCD_SetTextColor(uint32_t color);
void MyLCD_SetBackColor(uint32_t color);
void MyLCD_DrawChar(uint16_t x, uint16_t y, const uint8_t c);
void MyLCD_DrawString(uint16_t Xpos, uint16_t Ypos, uint8_t *Text, Text_AlignModeTypdef Mode);
void MyLCD_DrawCircle(uint16_t Xpos, uint16_t Ypos, uint16_t radius, uint32_t color);
void MyLCD_DrawCross(uint32_t x, uint32_t y, uint32_t color);
#endif /* LTDC_H */
