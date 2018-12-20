#include "GUI.h"
#include "WM.h"
#include "touch.h"

#define CUS_LIGHTBLUE		0x00FFD218
#define CUS_BACKGROUND		0x00101005
#define CUS_DARKGRAY		0x00333333
#define CUS_GRAY			0x00726B60
#define CUS_DARKESTGRAY		0x00202020

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

void drawTest(void)
{

	/* Rectangles */
	GUI_SetBkColor(CUS_BACKGROUND);
	GUI_Clear();
	GUI_SetDrawMode(GUI_DRAWMODE_NORMAL);
	GUI_SetFont(&GUI_Font8x16);

	GUI_SetColor(CUS_DARKGRAY);
	GUI_AA_FillRoundedRect(5, 5, 235, 47, 8);
	GUI_SetColor(CUS_LIGHTBLUE);
	GUI_AA_FillRoundedRect(5, 5, 26, 47, 8);
	GUI_SetColor(CUS_DARKGRAY);
	GUI_FillRect(15, 5, 30, 47);

	GUI_AA_FillRoundedRect(5, 49, 235, 91, 8);
	GUI_SetColor(GUI_BLACK);
	GUI_AA_FillRoundedRect(5, 49, 26, 91, 8);
	GUI_SetColor(CUS_DARKGRAY);
	GUI_FillRect(15, 49, 30, 91);

	GUI_AA_FillRoundedRect(5, 93, 235, 135, 8);
	GUI_SetColor(GUI_BLACK);
	GUI_AA_FillRoundedRect(5, 93, 26, 135, 8);
	GUI_SetColor(CUS_DARKGRAY);
	GUI_FillRect(15, 93, 30, 135);

	GUI_AA_FillRoundedRect(5, 137, 235, 179, 8);
	GUI_SetColor(GUI_BLACK);
	GUI_AA_FillRoundedRect(5, 137, 26, 179, 8);
	GUI_SetColor(CUS_DARKGRAY);
	GUI_FillRect(15, 137, 30, 179);


	GUI_AA_FillRoundedRect(35, 181, 235, 223, 8);
	GUI_AA_FillRoundedRect(35, 225, 235, 267, 8);
	GUI_AA_FillRoundedRect(35, 269, 235, 311, 8);


	GUI_SetColor(GUI_WHITE);
	GUI_FillRect(7, 188, 30, 196);
	GUI_SetColor(CUS_DARKESTGRAY);
	GUI_FillRect(7, 198, 30, 206);
	GUI_FillRect(7, 208, 30, 216);

	GUI_FillRect(7, 232, 30, 240);
	GUI_SetColor(GUI_WHITE);
	GUI_FillRect(7, 242, 30, 250);
	GUI_SetColor(CUS_DARKESTGRAY);
	GUI_FillRect(7, 252, 30, 260);

	GUI_FillRect(7, 276, 30, 284);
	GUI_FillRect(7, 286, 30, 294);
	GUI_SetColor(GUI_WHITE);
	GUI_FillRect(7, 296, 30, 304);

	/* Text */
	GUI_SetTextMode(GUI_TM_TRANS);
	GUI_EnableAlpha(1);
	GUI_SetColor(GUI_WHITE);
	GUI_DispStringAt("ALL DIM", 25, 18);
	GUI_DispStringAt("ALL CLEAR", 25, 62);
	GUI_DispStringAt("PRESENTATION MODE", 25, 106);
	GUI_DispStringAt("ALL AUTO", 25, 150);

	GUI_DispCharAt('1', 50, 194);
	GUI_DispCharAt('1', 50, 238);
	GUI_DispCharAt('1', 50, 282);

	GUI_DispCharAt('2', 83, 194);
	GUI_DispCharAt('2', 83, 238);
	GUI_DispCharAt('2', 83, 282);

	GUI_DispCharAt('3', 116, 194);
	GUI_DispCharAt('3', 116, 238);
	GUI_DispCharAt('3', 116, 282);

	GUI_DispCharAt('4', 149, 194);
	GUI_DispCharAt('4', 149, 238);
	GUI_DispCharAt('4', 149, 282);

	GUI_DispCharAt('5', 182, 194);
	GUI_DispCharAt('5', 182, 238);
	GUI_DispCharAt('5', 182, 282);

	GUI_DispCharAt('A', 215, 194);
	GUI_DispCharAt('A', 215, 238);
	GUI_DispCharAt('A', 215, 282);
	GUI_EnableAlpha(0);

	/* Lines under modes */
	GUI_SetColor(CUS_LIGHTBLUE);
	GUI_DrawLine(24, 35, 225, 35);
	GUI_SetColor(GUI_BLACK);
	GUI_DrawLine(24, 79, 225, 79);
	GUI_DrawLine(24, 123, 225, 123);
	GUI_DrawLine(24, 167, 225, 167);

	/* Lines under values */
	GUI_DrawLine(44, 211, 63, 211); /* For 1 */
	GUI_DrawLine(44, 255, 63, 255);
	GUI_DrawLine(44, 299, 63, 299);

	GUI_DrawLine(77, 211, 96, 211); /* For 2 */
	GUI_DrawLine(77, 255, 96, 255);
	GUI_DrawLine(77, 299, 96, 299);

	GUI_DrawLine(110, 211, 127, 211); /* For 3 */
	GUI_DrawLine(110, 255, 127, 255);
	GUI_DrawLine(110, 299, 127, 299);

	GUI_DrawLine(143, 211, 160, 211); /* For 4 */
	GUI_DrawLine(143, 255, 160, 255);
	GUI_DrawLine(143, 299, 160, 299);

	GUI_SetColor(CUS_LIGHTBLUE);
	GUI_DrawLine(176, 211, 193, 211); /* For 5 */
	GUI_DrawLine(176, 255, 193, 255);
	GUI_DrawLine(176, 299, 193, 299);

	GUI_SetColor(GUI_BLACK);
	GUI_DrawLine(209, 211, 226, 211); /* For Auto */
	GUI_DrawLine(209, 255, 226, 255);
	GUI_DrawLine(209, 299, 226, 299);
}

void graphicsMain(void)
{
	drawTest();
	while (1)
	{
		GUI_Delay(10);
	}
}

