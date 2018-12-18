#include "ltdc.h"
#include "main.h"

#define swap(a,b) {int16_t t=a;a=b;b=t;}

extern LTDC_HandleTypeDef hltdc;
extern SPI_HandleTypeDef hspi5;
extern DMA2D_HandleTypeDef hdma2d;

uint16_t X_SIZE = 240, Y_SIZE = 320;

MyLCD_DrawPropTypeDef lcdProp;

const uint8_t *ch;

void MyLCD_PowerOn(void)
{
	MyLCD_WriteCommand(0xCA);
	MyLCD_WriteData(0xC3);
	MyLCD_WriteData(0x08);
	MyLCD_WriteData(0x50);
	MyLCD_WriteCommand(MyLCD_POWERB);
	MyLCD_WriteData(0x00);
	MyLCD_WriteData(0xC1);
	MyLCD_WriteData(0x30);
	MyLCD_WriteCommand(MyLCD_POWER_SEQ);
	MyLCD_WriteData(0x64);
	MyLCD_WriteData(0x03);
	MyLCD_WriteData(0x12);
	MyLCD_WriteData(0x81);
	MyLCD_WriteCommand(MyLCD_DTCA);
	MyLCD_WriteData(0x85);
	MyLCD_WriteData(0x00);
	MyLCD_WriteData(0x78);
	MyLCD_WriteCommand(MyLCD_POWERA);
	MyLCD_WriteData(0x39);
	MyLCD_WriteData(0x2C);
	MyLCD_WriteData(0x00);
	MyLCD_WriteData(0x34);
	MyLCD_WriteData(0x02);
	MyLCD_WriteCommand(MyLCD_PRC);
	MyLCD_WriteData(0x20);
	MyLCD_WriteCommand(MyLCD_DTCB);
	MyLCD_WriteData(0x00);
	MyLCD_WriteData(0x00);
	MyLCD_WriteCommand(MyLCD_FRC);
	MyLCD_WriteData(0x00);
	MyLCD_WriteData(0x1B);
	MyLCD_WriteCommand(MyLCD_DFC);
	MyLCD_WriteData(0x0A);
	MyLCD_WriteData(0xA2);
	MyLCD_WriteCommand(MyLCD_POWER1);
	MyLCD_WriteData(0x10);
	MyLCD_WriteCommand(MyLCD_POWER2);
	MyLCD_WriteData(0x10);
	MyLCD_WriteCommand(MyLCD_VCOM1);
	MyLCD_WriteData(0x45);
	MyLCD_WriteData(0x15);
	MyLCD_WriteCommand(MyLCD_VCOM2);
	MyLCD_WriteData(0x90);
	MyLCD_WriteCommand(MyLCD_MAC);
	MyLCD_WriteData(0xC8);
	MyLCD_WriteCommand(MyLCD_3GAMMA_EN);
	MyLCD_WriteData(0x00);
	MyLCD_WriteCommand(MyLCD_RGB_INTERFACE);
	MyLCD_WriteData(0xC2);
	MyLCD_WriteCommand(MyLCD_DFC);
	MyLCD_WriteData(0x0A);
	MyLCD_WriteData(0xA7);
	MyLCD_WriteData(0x27);
	MyLCD_WriteData(0x04);

	/* colomn address set */
	MyLCD_WriteCommand(MyLCD_COLUMN_ADDR);
	MyLCD_WriteData(0x00);
	MyLCD_WriteData(0x00);
	MyLCD_WriteData(0x00);
	MyLCD_WriteData(0xEF);
	/* Page Address Set */
	MyLCD_WriteCommand(MyLCD_PAGE_ADDR);
	MyLCD_WriteData(0x00);
	MyLCD_WriteData(0x00);
	MyLCD_WriteData(0x01);
	MyLCD_WriteData(0x3F);
	MyLCD_WriteCommand(MyLCD_INTERFACE);
	MyLCD_WriteData(0x01);
	MyLCD_WriteData(0x00);
	MyLCD_WriteData(0x06);

	MyLCD_WriteCommand(MyLCD_GRAM);
	HAL_Delay(100);

	MyLCD_WriteCommand(MyLCD_GAMMA);
	MyLCD_WriteData(0x01);

	MyLCD_WriteCommand(MyLCD_PGAMMA);
	MyLCD_WriteData(0x0F);
	MyLCD_WriteData(0x29);
	MyLCD_WriteData(0x24);
	MyLCD_WriteData(0x0C);
	MyLCD_WriteData(0x0E);
	MyLCD_WriteData(0x09);
	MyLCD_WriteData(0x4E);
	MyLCD_WriteData(0x78);
	MyLCD_WriteData(0x3C);
	MyLCD_WriteData(0x09);
	MyLCD_WriteData(0x13);
	MyLCD_WriteData(0x05);
	MyLCD_WriteData(0x17);
	MyLCD_WriteData(0x11);
	MyLCD_WriteData(0x00);
	MyLCD_WriteCommand(MyLCD_NGAMMA);
	MyLCD_WriteData(0x00);
	MyLCD_WriteData(0x16);
	MyLCD_WriteData(0x1B);
	MyLCD_WriteData(0x04);
	MyLCD_WriteData(0x11);
	MyLCD_WriteData(0x07);
	MyLCD_WriteData(0x31);
	MyLCD_WriteData(0x33);
	MyLCD_WriteData(0x42);
	MyLCD_WriteData(0x05);
	MyLCD_WriteData(0x0C);
	MyLCD_WriteData(0x0A);
	MyLCD_WriteData(0x28);
	MyLCD_WriteData(0x2F);
	MyLCD_WriteData(0x0F);

	MyLCD_WriteCommand(MyLCD_SLEEP_OUT);
	HAL_Delay(100);
	MyLCD_WriteCommand(MyLCD_DISPLAY_ON);
	/* GRAM start writing */
	MyLCD_WriteCommand(MyLCD_GRAM);
}

void MyLCD_WriteCommand(uint8_t com)
{
	uint8_t buf[2] = {com, 0};
	HAL_GPIO_WritePin(LTDC_WRX_GPIO_Port, LTDC_WRX_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LTDC_NCS_GPIO_Port, LTDC_NCS_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi5, buf, 1, 100);
	HAL_GPIO_WritePin(LTDC_NCS_GPIO_Port, LTDC_NCS_Pin, GPIO_PIN_SET);
}

void MyLCD_WriteData(uint8_t data)
{
	uint8_t buf[2] = {data, 0};
	HAL_GPIO_WritePin(LTDC_WRX_GPIO_Port, LTDC_WRX_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LTDC_NCS_GPIO_Port, LTDC_NCS_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi5, buf, 1, 100);
	HAL_GPIO_WritePin(LTDC_NCS_GPIO_Port, LTDC_NCS_Pin, GPIO_PIN_SET);
}

void MyLCD_FillScreen(uint32_t color)
{
	hdma2d.Init.Mode = DMA2D_R2M;
	hdma2d.Init.OutputOffset = 0;
	if (HAL_DMA2D_Init(&hdma2d) == HAL_OK)
	{
		if (HAL_DMA2D_Start(&hdma2d, color, hltdc.LayerCfg[0].FBStartAdress,
				hltdc.LayerCfg[0].ImageWidth, hltdc.LayerCfg[0].ImageHeight) == HAL_OK)
		{
			HAL_DMA2D_PollForTransfer(&hdma2d, 10);
		}
	}/*
	uint32_t n = hltdc.LayerCfg[0].ImageHeight*hltdc.LayerCfg[0].ImageWidth;
	for (uint32_t i = 0; i < (n); i++)
	{
		*(__IO uint32_t*) (hltdc.LayerCfg[0].FBStartAdress + (i*3)) = color;
	}*/
}

void MyLCD_Test(void)
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

void MyLCD_FillRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint32_t color)
{
	if(x1 > x2) swap(x1, x2);
	if(y1 > y2) swap(y1, y2);

	uint32_t addr = 0;
	addr = (hltdc.LayerCfg[0].FBStartAdress) + 3*(y1*hltdc.LayerCfg[0].ImageWidth + x1);
	hdma2d.Init.Mode = DMA2D_R2M;
	hdma2d.Init.OutputOffset = hltdc.LayerCfg[0].ImageWidth-(x2-x1);

	if (HAL_DMA2D_Init(&hdma2d) == HAL_OK)
	{
		if (HAL_DMA2D_Start(&hdma2d, color, addr, x2-x1, y2-y1) == HAL_OK)
		{
			HAL_DMA2D_PollForTransfer(&hdma2d, 10);
		}
	}/*
	uint32_t xPos, yPos;

	if(x1 > x2) swap(x1, x2);
	if(y1 > y2) swap(y1, y2);

	for (yPos = y1; yPos <= y2; yPos++)
	{
		for (xPos = x1; xPos <= x2; xPos++)
		{
			*(__IO uint32_t*) (hltdc.LayerCfg[0].FBStartAdress + (3*(yPos*hltdc.LayerCfg[0].ImageWidth + xPos))) = color;
		}
	}*/
}

void MyLCD_DrawCircle(uint16_t Xpos, uint16_t Ypos, uint16_t radius, uint32_t color)
{
    int x = -radius, y = 0, err = 2-2*radius, e2;
    do {/*
    	if (HAL_DMA2D_Init(&hdma2d) == HAL_OK)
    	{
    		if (HAL_DMA2D_Start(&hdma2d, color, hltdc.LayerCfg[0].FBStartAdress + (2*((Xpos-x) + 240*(Ypos+y)))
    				, 1, 1) == HAL_OK)
    		{
    			HAL_DMA2D_PollForTransfer(&hdma2d, 10);
    		}
    	}
    	if (HAL_DMA2D_Init(&hdma2d) == HAL_OK)
    	{
    		if (HAL_DMA2D_Start(&hdma2d, color, hltdc.LayerCfg[0].FBStartAdress + (2*((Xpos+x) + 240*(Ypos+y)))
   				, 1, 1) == HAL_OK)
    	    {
      			HAL_DMA2D_PollForTransfer(&hdma2d, 10);
    		}
    	}
    	if (HAL_DMA2D_Init(&hdma2d) == HAL_OK)
    	{
    		if (HAL_DMA2D_Start(&hdma2d, color, hltdc.LayerCfg[0].FBStartAdress + (2*((Xpos+x) + 240*(Ypos-y)))
    				, 1, 1) == HAL_OK)
    		{
    			HAL_DMA2D_PollForTransfer(&hdma2d, 10);
    		}
    	}
    	if (HAL_DMA2D_Init(&hdma2d) == HAL_OK)
    	{
    		if (HAL_DMA2D_Start(&hdma2d, color, hltdc.LayerCfg[0].FBStartAdress + (2*((Xpos-x) + 240*(Ypos-y)))
   				, 1, 1) == HAL_OK)
    	    {
      			HAL_DMA2D_PollForTransfer(&hdma2d, 10);
    		}
    	}*/
        *(__IO uint16_t*) (hltdc.LayerCfg[0].FBStartAdress + (2*((Xpos-x) + 240*(Ypos+y)))) = color;
        *(__IO uint16_t*) (hltdc.LayerCfg[0].FBStartAdress + (2*((Xpos+x) + 240*(Ypos+y)))) = color;
        *(__IO uint16_t*) (hltdc.LayerCfg[0].FBStartAdress + (2*((Xpos+x) + 240*(Ypos-y)))) = color;
        *(__IO uint16_t*) (hltdc.LayerCfg[0].FBStartAdress + (2*((Xpos-x) + 240*(Ypos-y)))) = color;

        e2 = err;
        if (e2 <= y) {
            err += ++y*2+1;
            if (-x == y && e2 <= x) e2 = 0;
        }
        if (e2 > x) err += ++x*2+1;
    }
    while (x <= 0);
}

void MyLCD_DrawPixel(uint32_t x, uint32_t y, uint32_t color)
{
	hdma2d.Init.Mode = DMA2D_R2M;
	hdma2d.Init.OutputOffset = 0;
	if (HAL_DMA2D_Init(&hdma2d) == HAL_OK)
	{
		if (HAL_DMA2D_Start(&hdma2d, color, hltdc.LayerCfg[0].FBStartAdress + (3*(y*hltdc.LayerCfg[0].ImageWidth + x))
				, 1, 1) == HAL_OK)
		{
			HAL_DMA2D_PollForTransfer(&hdma2d, 10);
		}
	}
	//*(__IO uint32_t*) (hltdc.LayerCfg[0].FBStartAdress + (3*(y*hltdc.LayerCfg[0].ImageWidth + x))) = color;
}

void MyLCD_DrawCross(uint32_t x, uint32_t y, uint32_t color)
{
	MyLCD_DrawPixel(x, y, color);
	for (uint8_t i = 1; i < 4; i++)
		MyLCD_DrawPixel(x+i, y, color);
	for (uint8_t i = 1; i < 4; i++)
		MyLCD_DrawPixel(x, y+i, color);
	for (uint8_t i = 1; i < 4; i++)
		MyLCD_DrawPixel(x-i, y, color);
	for (uint8_t i = 1; i < 4; i++)
		MyLCD_DrawPixel(x, y-i, color);
}

void MyLCD_DrawLine(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t color)
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
		if (steep) MyLCD_DrawPixel(y1,x1,color);
		else MyLCD_DrawPixel(x1,y1,color);
		err-=dy;
		if (err<0)
		{
			y1 += ystep;
			err+=dx;
		}
	}
}

void MyLCD_FontsInit(void)
{
	lcdProp.BackColor = MyLCD_COLOR_BLACK;
	lcdProp.TextColor = MyLCD_COLOR_GREEN;
	lcdProp.pFont = &Font16;
}

void MyLCD_SetFont(sFONT *fonts)
{
	lcdProp.pFont = fonts;
}

void MyLCD_SetTextColor(uint32_t color)
{
	lcdProp.TextColor = color;
}

void MyLCD_SetBackColor(uint32_t color)
{
	lcdProp.BackColor = color;
}

void MyLCD_DrawChar(uint16_t x, uint16_t y, const uint8_t c)
{
  uint16_t height, width;
  uint8_t offset;
  uint8_t *pchar;
  uint32_t line;

  ch = &lcdProp.pFont->table[(c-' ') * lcdProp.pFont->Height * ((lcdProp.pFont->Width + 7) / 8)];
  height = lcdProp.pFont->Height;
  width = lcdProp.pFont->Width;
  offset = 8*((width + 7)/8) - width;

  for (uint32_t i = 0; i < height; i++)
  {
	  pchar = ((uint8_t *)ch + (width + 7)/8 * i);
	  switch ((width + 7)/8)
	  {
	  	  case 1:
	  		  line = pchar[0];
	  		  break;
	  	  case 2:
	  		  line = (pchar[0] << 8) | pchar[1];
	  		  break;
	  	  case 3:
	  	  default:
	  		  line = (pchar[0]<< 16) | (pchar[1]<< 8) | pchar[2];
	  		  break;
	  }

	  for (uint32_t j = 0; j < width; j++)
	  {
		  if (line & (1 << (width- j + offset- 1)))
		  {
			  MyLCD_DrawPixel((x + j), y, lcdProp.TextColor);
		  }
		  else
		  {
			  MyLCD_DrawPixel((x + j), y, lcdProp.BackColor);
		  }
	  }
	  y++;
  }
}

void MyLCD_DrawString(uint16_t Xpos, uint16_t Ypos, uint8_t *Text, Text_AlignModeTypdef Mode)
{
	uint16_t ref_column = 1, i = 0;
	uint32_t size = 0, xsize = 0;
	uint8_t *ptr = Text;
	while (*ptr++) size++;
	xsize = (X_SIZE/lcdProp.pFont->Width);

	switch (Mode)
	{
		case CENTER_MODE:
			ref_column = Xpos + ((xsize - size) * lcdProp.pFont->Width) / 2;
			break;
		case RIGHT_MODE:
			ref_column = - Xpos + ((xsize - size) * lcdProp.pFont->Width);
			break;
		case LEFT_MODE:
		default:
			ref_column = Xpos;
			break;
	}

	if ((ref_column < 1) || (ref_column >= 0x8000))
	{
		ref_column = 1;
	}
	while ((*Text != 0) & (((X_SIZE - (i*lcdProp.pFont->Width)) & 0xFFFF) >= lcdProp.pFont->Width))
	{
		MyLCD_DrawChar(ref_column, Ypos, *Text);
		ref_column += lcdProp.pFont->Width;
		Text++;
		i++;
	}
}
