#include "ltdc.h"
#include "main.h"

#define swap(a,b) {int16_t t=a;a=b;b=t;}

extern LTDC_HandleTypeDef hltdc;
extern SPI_HandleTypeDef hspi5;

void LCD_PowerOn(void)
{
	LCD_WriteCommand(0xCA);
	LCD_WriteData(0xC3);
	LCD_WriteData(0x08);
	LCD_WriteData(0x50);
	LCD_WriteCommand(LCD_POWERB);
	LCD_WriteData(0x00);
	LCD_WriteData(0xC1);
	LCD_WriteData(0x30);
	LCD_WriteCommand(LCD_POWER_SEQ);
	LCD_WriteData(0x64);
	LCD_WriteData(0x03);
	LCD_WriteData(0x12);
	LCD_WriteData(0x81);
	LCD_WriteCommand(LCD_DTCA);
	LCD_WriteData(0x85);
	LCD_WriteData(0x00);
	LCD_WriteData(0x78);
	LCD_WriteCommand(LCD_POWERA);
	LCD_WriteData(0x39);
	LCD_WriteData(0x2C);
	LCD_WriteData(0x00);
	LCD_WriteData(0x34);
	LCD_WriteData(0x02);
	LCD_WriteCommand(LCD_PRC);
	LCD_WriteData(0x20);
	LCD_WriteCommand(LCD_DTCB);
	LCD_WriteData(0x00);
	LCD_WriteData(0x00);
	LCD_WriteCommand(LCD_FRC);
	LCD_WriteData(0x00);
	LCD_WriteData(0x1B);
	LCD_WriteCommand(LCD_DFC);
	LCD_WriteData(0x0A);
	LCD_WriteData(0xA2);
	LCD_WriteCommand(LCD_POWER1);
	LCD_WriteData(0x10);
	LCD_WriteCommand(LCD_POWER2);
	LCD_WriteData(0x10);
	LCD_WriteCommand(LCD_VCOM1);
	LCD_WriteData(0x45);
	LCD_WriteData(0x15);
	LCD_WriteCommand(LCD_VCOM2);
	LCD_WriteData(0x90);
	LCD_WriteCommand(LCD_MAC);
	LCD_WriteData(0xC8);
	LCD_WriteCommand(LCD_3GAMMA_EN);
	LCD_WriteData(0x00);
	LCD_WriteCommand(LCD_RGB_INTERFACE);
	LCD_WriteData(0xC2);
	LCD_WriteCommand(LCD_DFC);
	LCD_WriteData(0x0A);
	LCD_WriteData(0xA7);
	LCD_WriteData(0x27);
	LCD_WriteData(0x04);

	/* colomn address set */
	LCD_WriteCommand(LCD_COLUMN_ADDR);
	LCD_WriteData(0x00);
	LCD_WriteData(0x00);
	LCD_WriteData(0x00);
	LCD_WriteData(0xEF);
	/* Page Address Set */
	LCD_WriteCommand(LCD_PAGE_ADDR);
	LCD_WriteData(0x00);
	LCD_WriteData(0x00);
	LCD_WriteData(0x01);
	LCD_WriteData(0x3F);
	LCD_WriteCommand(LCD_INTERFACE);
	LCD_WriteData(0x01);
	LCD_WriteData(0x00);
	LCD_WriteData(0x06);

	LCD_WriteCommand(LCD_GRAM);
	HAL_Delay(100);

	LCD_WriteCommand(LCD_GAMMA);
	LCD_WriteData(0x01);

	LCD_WriteCommand(LCD_PGAMMA);
	LCD_WriteData(0x0F);
	LCD_WriteData(0x29);
	LCD_WriteData(0x24);
	LCD_WriteData(0x0C);
	LCD_WriteData(0x0E);
	LCD_WriteData(0x09);
	LCD_WriteData(0x4E);
	LCD_WriteData(0x78);
	LCD_WriteData(0x3C);
	LCD_WriteData(0x09);
	LCD_WriteData(0x13);
	LCD_WriteData(0x05);
	LCD_WriteData(0x17);
	LCD_WriteData(0x11);
	LCD_WriteData(0x00);
	LCD_WriteCommand(LCD_NGAMMA);
	LCD_WriteData(0x00);
	LCD_WriteData(0x16);
	LCD_WriteData(0x1B);
	LCD_WriteData(0x04);
	LCD_WriteData(0x11);
	LCD_WriteData(0x07);
	LCD_WriteData(0x31);
	LCD_WriteData(0x33);
	LCD_WriteData(0x42);
	LCD_WriteData(0x05);
	LCD_WriteData(0x0C);
	LCD_WriteData(0x0A);
	LCD_WriteData(0x28);
	LCD_WriteData(0x2F);
	LCD_WriteData(0x0F);

	LCD_WriteCommand(LCD_SLEEP_OUT);
	HAL_Delay(100);
	LCD_WriteCommand(LCD_DISPLAY_ON);
	/* GRAM start writing */
	LCD_WriteCommand(LCD_GRAM);
}

void LCD_WriteCommand(uint8_t com)
{
	uint8_t buf[2] = {com, 0};
	HAL_GPIO_WritePin(LTDC_WRX_GPIO_Port, LTDC_WRX_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LTDC_NCS_GPIO_Port, LTDC_NCS_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi5, buf, 1, 100);
	HAL_GPIO_WritePin(LTDC_NCS_GPIO_Port, LTDC_NCS_Pin, GPIO_PIN_SET);
}

void LCD_WriteData(uint8_t data)
{
	uint8_t buf[2] = {data, 0};
	HAL_GPIO_WritePin(LTDC_WRX_GPIO_Port, LTDC_WRX_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LTDC_NCS_GPIO_Port, LTDC_NCS_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi5, buf, 1, 100);
	HAL_GPIO_WritePin(LTDC_NCS_GPIO_Port, LTDC_NCS_Pin, GPIO_PIN_SET);
}

void LCD_FillScreen(uint32_t color)
{
	uint32_t n = hltdc.LayerCfg[0].ImageHeight*hltdc.LayerCfg[0].ImageWidth;
	for (uint32_t i = 0; i < (n); i++)
	{
		*(__IO uint32_t*) (hltdc.LayerCfg[0].FBStartAdress + (i*3)) = color;
	}
}

void LCD_Test(void)
{
	uint32_t color = 0x00;
	uint32_t n = hltdc.LayerCfg[0].ImageHeight*hltdc.LayerCfg[0].ImageWidth;
	for (uint32_t i = 0; i < (n); i++)
	{
		*(__IO uint32_t*) (hltdc.LayerCfg[0].FBStartAdress + (i*3)) = color;
		color++;
		if (color == 0xFFFFFF)
		{
			color = 0x00;
		}
	}
}

void LCD_FillRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint32_t color)
{
	uint32_t xPos, yPos;
	if(x1 > x2) swap(x1, x2);
	if(y1 > y2) swap(y1, y2);

	for (yPos = y1; yPos <= y2; yPos++)
	{
		for (xPos = x1; xPos <= x2; xPos++)
		{
			*(__IO uint32_t*) (hltdc.LayerCfg[0].FBStartAdress + (3*(yPos*hltdc.LayerCfg[0].ImageWidth + xPos))) = color;
		}
	}
}

//void LCD_FillRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t );

void LCD_DrawPixel(uint32_t x, uint32_t y, uint32_t color)
{
	*(__IO uint32_t*) (hltdc.LayerCfg[0].FBStartAdress + (3*(y*hltdc.LayerCfg[0].ImageWidth + x))) = color;
}

void LCD_DrawLine(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t color)
{
	int steep = abs(y2-y1)>abs(x2-x1);
	if (steep)
	{
		swap(x1,y1);
		swap(x2,y2);
	}
	if (x1>x2)
	{
		swap(x1,x2);
		swap(y1,y2);
	}
		int dx,dy;
		dx=x2-x1;
		dy=abs(y2-y1);
		int err=dx/2;
		int ystep;
		if(y1<y2) ystep = 1;
	else  ystep = -1;
	for (;x1<=x2;x1++)
	{
		if (steep) LCD_DrawPixel(y1,x1,color);
		else LCD_DrawPixel(x1,y1,color);
		err-=dy;
		if (err<0)
		{
			y1 += ystep;
			err+=dx;
		}
	}
}
