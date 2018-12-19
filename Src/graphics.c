#include "GUI.h"
#include "WM.h"

void DrawPlay(int x, int y, int size)
{
GUI_POINT pPoint[3];
pPoint[0].x = 0;
pPoint[0].y = 0;
pPoint[1].x = size;
pPoint[1].y = size / 2;
pPoint[2].x = 0;
pPoint[2].y = size;
GUI_AA_FillPolygon(pPoint, 3, x, y);
}

void graphicsMain(void)
{
	GUI_SetBkColor(GUI_DARKBLUE);
	GUI_Clear();
	GUI_SetDrawMode(GUI_DRAWMODE_NORMAL);
	GUI_SetFont(&GUI_Font8x16);
	GUI_DispString("Hello from origin");
	GUI_DispStringAt("Hello here, I'm at:20,30", 20,30);

	GUI_RECT pRect = {50, 60, 200, 220};
	GUI_DrawRect(50, 60, 200, 220);
	GUI_DispStringInRectWrap("Hello from rectangle, my name is STM32F4 and I love C programming", &pRect, GUI_TA_VCENTER |
	GUI_TA_HCENTER, GUI_WRAPMODE_WORD);

	GUI_SetColor(GUI_DARKMAGENTA);
	DrawPlay(40, 220, 50);

	/*
	GUI_SetColor(GUI_RED);
	GUI_FillCircle(100,100,50);
	GUI_SetColor(GUI_WHITE);
	GUI_SetDrawMode(GUI_DRAWMODE_REV);
	GUI_FillCircle(120,120,50);

	GUI_SetDrawMode(GUI_DRAWMODE_NORMAL);
	GUI_SetColor(GUI_ORANGE);
	GUI_AA_FillCircle(200,200,40);
	*/
	while (1)
	{


	}
}
