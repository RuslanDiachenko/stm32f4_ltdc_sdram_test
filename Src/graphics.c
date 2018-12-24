#include "GUI.h"
#include "WM.h"
#include "touch.h"

#define CUS_LIGHTBLUE		0x00FFD218
#define CUS_BACKGROUND		0x00101005
#define CUS_DARKGRAY		0x00333333
#define CUS_GRAY			0x00726B60
#define CUS_DARKESTGRAY		0x00202020

enum
{
	ZONE_TOP = 0,
	ZONE_MID,
	ZONE_BOT,
	MAX_ZONES_NUM
};

typedef enum
{
	NOT_ACTIVE = 0,
	ALL_DIM,
	ALL_CLEAR,
	PRESENTATION,
	ALL_AUTO
} ui_mode_t;

typedef enum
{
	NOT_AVAILABLE = 0,
	L_ONE,
	L_TWO,
	L_THREE,
	L_FOUR,
	L_FIVE,
	L_AUTO
} ui_zone_state_t;

typedef struct
{
	ui_mode_t mode;
	ui_zone_state_t state[MAX_ZONES_NUM];
} ui_state_t;

static ui_state_t uiState_g;

void UI_SetDefault(void)
{
	uiState_g.mode = NOT_ACTIVE;
	uiState_g.state[ZONE_TOP] = L_ONE;
	uiState_g.state[ZONE_MID] = L_ONE;
	uiState_g.state[ZONE_BOT] = L_ONE;
}

void UI_SetState(ui_state_t uiState)
{
	uiState_g.mode = uiState.mode;
	uiState_g.state[ZONE_TOP] = uiState.state[ZONE_TOP];
	uiState_g.state[ZONE_MID] = uiState.state[ZONE_MID];
	uiState_g.state[ZONE_BOT] = uiState.state[ZONE_BOT];
}

void UI_GetState(ui_state_t *uiState)
{
	uiState->mode = uiState_g.mode;
	uiState->state[ZONE_TOP] = uiState_g.state[ZONE_TOP];
	uiState->state[ZONE_MID] = uiState_g.state[ZONE_MID];
	uiState->state[ZONE_BOT] = uiState_g.state[ZONE_BOT];
}

static void drawAllNotActive(void)
{

	/* Rectangles */
	GUI_SetBkColor(CUS_BACKGROUND);
	GUI_Clear();
	GUI_SetDrawMode(GUI_DRAWMODE_NORMAL);
	GUI_SetTextMode(GUI_TM_NORMAL);
	GUI_SetFont(&GUI_Font8x16);

	GUI_SetColor(CUS_DARKGRAY);
	GUI_FillRoundedRect(5, 5, 235, 47, 8);
	GUI_SetColor(GUI_BLACK);
	GUI_FillRoundedRect(5, 5, 26, 47, 8);
	GUI_SetColor(CUS_DARKGRAY);
	GUI_FillRect(15, 5, 30, 47);

	GUI_FillRoundedRect(5, 49, 235, 91, 8);
	GUI_SetColor(GUI_BLACK);
	GUI_FillRoundedRect(5, 49, 26, 91, 8);
	GUI_SetColor(CUS_DARKGRAY);
	GUI_FillRect(15, 49, 30, 91);

	GUI_FillRoundedRect(5, 93, 235, 135, 8);
	GUI_SetColor(GUI_BLACK);
	GUI_FillRoundedRect(5, 93, 26, 135, 8);
	GUI_SetColor(CUS_DARKGRAY);
	GUI_FillRect(15, 93, 30, 135);

	GUI_FillRoundedRect(5, 137, 235, 179, 8);
	GUI_SetColor(GUI_BLACK);
	GUI_FillRoundedRect(5, 137, 26, 179, 8);
	GUI_SetColor(CUS_DARKGRAY);
	GUI_FillRect(15, 137, 30, 179);


	GUI_FillRoundedRect(35, 181, 235, 223, 8);
	GUI_FillRoundedRect(35, 225, 235, 267, 8);
	GUI_FillRoundedRect(35, 269, 235, 311, 8);


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
	GUI_SetColor(GUI_BLACK);
	GUI_DrawLine(24, 35, 225, 35);
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

	GUI_DrawLine(176, 211, 193, 211); /* For 5 */
	GUI_DrawLine(176, 255, 193, 255);
	GUI_DrawLine(176, 299, 193, 299);

	GUI_DrawLine(209, 211, 226, 211); /* For Auto */
	GUI_DrawLine(209, 255, 226, 255);
	GUI_DrawLine(209, 299, 226, 299);
}

static void disablePrevMode(ui_mode_t mode)
{
	switch (mode)
	{
	case ALL_DIM:
		/* Activity indicator */
		GUI_SetColor(GUI_BLACK);
		GUI_FillRoundedRect(5, 5, 26, 47, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 5, 26, 47);

		/* Text underline */
		GUI_SetColor(GUI_BLACK);
		GUI_DrawLine(24, 35, 225, 35);

		/* One char */
		GUI_SetColor(GUI_WHITE);
		GUI_DispCharAt('A', 25, 18);
		break;

	case ALL_CLEAR:
		GUI_SetColor(GUI_BLACK);
		GUI_FillRoundedRect(5, 49, 26, 91, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 49, 26, 91);

		GUI_SetColor(GUI_BLACK);
		GUI_DrawLine(24, 79, 225, 79);

		GUI_SetColor(GUI_WHITE);
		GUI_DispCharAt('A', 25, 62);
		break;

	case PRESENTATION:
		GUI_SetColor(GUI_BLACK);
		GUI_FillRoundedRect(5, 93, 26, 135, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 93, 26, 135);

		GUI_SetColor(GUI_BLACK);
		GUI_DrawLine(24, 123, 225, 123);

		GUI_SetColor(GUI_WHITE);
		GUI_DispCharAt('P', 25, 106);
		break;

	case ALL_AUTO:
		GUI_SetColor(GUI_BLACK);
		GUI_FillRoundedRect(5, 137, 26, 179, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 137, 26, 179);

		GUI_SetColor(GUI_BLACK);
		GUI_DrawLine(24, 167, 225, 167);

		GUI_SetColor(GUI_WHITE);
		GUI_DispCharAt('A', 25, 150);
		break;

	default:
		break;
	}
}

static void enableNextMode(ui_mode_t mode)
{
	switch (mode)
	{
	case ALL_DIM:
		/* Activity indicator */
		GUI_SetColor(CUS_LIGHTBLUE);
		GUI_FillRoundedRect(5, 5, 26, 47, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 5, 26, 47);

		/* Text underline */
		GUI_SetColor(CUS_LIGHTBLUE);
		GUI_DrawLine(24, 35, 225, 35);

		GUI_SetColor(GUI_WHITE);
		GUI_DispCharAt('A', 25, 18);
		break;

	case ALL_CLEAR:
		GUI_SetColor(CUS_LIGHTBLUE);
		GUI_FillRoundedRect(5, 49, 26, 91, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 49, 26, 91);

		GUI_SetColor(CUS_LIGHTBLUE);
		GUI_DrawLine(24, 79, 225, 79);

		GUI_SetColor(GUI_WHITE);
		GUI_DispCharAt('A', 25, 62);
		break;

	case PRESENTATION:
		GUI_SetColor(CUS_LIGHTBLUE);
		GUI_FillRoundedRect(5, 93, 26, 135, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 93, 26, 135);

		GUI_SetColor(CUS_LIGHTBLUE);
		GUI_DrawLine(24, 123, 225, 123);

		GUI_SetColor(GUI_WHITE);
		GUI_DispCharAt('P', 25, 106);
		break;

	case ALL_AUTO:
		GUI_SetColor(CUS_LIGHTBLUE);
		GUI_FillRoundedRect(5, 137, 26, 179, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 137, 26, 179);

		GUI_SetColor(CUS_LIGHTBLUE);
		GUI_DrawLine(24, 167, 225, 167);

		GUI_SetColor(GUI_WHITE);
		GUI_DispCharAt('A', 25, 150);
		break;

	default:
		break;
	}
}

static void disablePrevZoneState(ui_zone_state_t zoneState, uint8_t numOfZone)
{
	switch (numOfZone)
	{
	case ZONE_TOP:
		switch (zoneState)
		{
		case L_ONE:
			GUI_SetColor(CUS_DARKGRAY);
			GUI_FillRoundedRect(35, 181, 73, 223, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('1', 50, 194);
			GUI_SetColor(GUI_BLACK);
			GUI_DrawLine(44, 211, 63, 211);
			break;

		case L_TWO:
			GUI_SetColor(CUS_DARKGRAY);
			GUI_FillRoundedRect(67, 181, 106, 223, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('2', 83, 194);
			GUI_SetColor(GUI_BLACK);
			GUI_DrawLine(77, 211, 96, 211);
			break;

		case L_THREE:
			GUI_SetColor(CUS_DARKGRAY);
			GUI_FillRoundedRect(100, 181, 139, 223, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('3', 116, 194);
			GUI_SetColor(GUI_BLACK);
			GUI_DrawLine(110, 211, 127, 211);
			break;

		case L_FOUR:
			GUI_SetColor(CUS_DARKGRAY);
			GUI_FillRoundedRect(132, 181, 171, 223, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('4', 149, 194);
			GUI_SetColor(GUI_BLACK);
			GUI_DrawLine(143, 211, 160, 211);
			break;

		case L_FIVE:
			GUI_SetColor(CUS_DARKGRAY);
			GUI_FillRoundedRect(165, 181, 204, 223, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('5', 182, 194);
			GUI_SetColor(GUI_BLACK);
			GUI_DrawLine(176, 211, 193, 211);
			break;

		case L_AUTO:
			GUI_SetColor(CUS_DARKGRAY);
			GUI_FillRoundedRect(200, 181, 235, 223, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('A', 215, 194);
			GUI_SetColor(GUI_BLACK);
			GUI_DrawLine(209, 211, 226, 211);
			break;
		default:
			break;
		}
		break;

	case ZONE_MID:
		switch (zoneState)
		{
		case L_ONE:
			GUI_SetColor(CUS_DARKGRAY);
			GUI_FillRoundedRect(35, 225, 73, 267, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('1', 50, 238);
			GUI_SetColor(GUI_BLACK);
			GUI_DrawLine(44, 255, 63, 255);
			break;

		case L_TWO:
			GUI_SetColor(CUS_DARKGRAY);
			GUI_FillRoundedRect(67, 225, 106, 267, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('2', 83, 238);
			GUI_SetColor(GUI_BLACK);
			GUI_DrawLine(77, 255, 96, 255);
			break;

		case L_THREE:
			GUI_SetColor(CUS_DARKGRAY);
			GUI_FillRoundedRect(100, 225, 139, 267, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('3', 116, 238);
			GUI_SetColor(GUI_BLACK);
			GUI_DrawLine(110, 255, 127, 255);
			break;

		case L_FOUR:
			GUI_SetColor(CUS_DARKGRAY);
			GUI_FillRoundedRect(132, 225, 171, 267, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('4', 149, 238);
			GUI_SetColor(GUI_BLACK);
			GUI_DrawLine(143, 255, 160, 255);
			break;

		case L_FIVE:
			GUI_SetColor(CUS_DARKGRAY);
			GUI_FillRoundedRect(165, 225, 204, 267, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('5', 182, 238);
			GUI_SetColor(GUI_BLACK);
			GUI_DrawLine(176, 255, 193, 255);
			break;

		case L_AUTO:
			GUI_SetColor(CUS_DARKGRAY);
			GUI_FillRoundedRect(200, 225, 235, 267, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('A', 215, 238);
			GUI_SetColor(GUI_BLACK);
			GUI_DrawLine(209, 255, 226, 255);
			break;
		default:
			break;
		}
		break;

	case ZONE_BOT:
		switch (zoneState)
		{
		case L_ONE:
			GUI_SetColor(CUS_DARKGRAY);
			GUI_FillRoundedRect(35, 269, 73, 311, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('1', 50, 282);
			GUI_SetColor(GUI_BLACK);
			GUI_DrawLine(44, 299, 63, 299);
			break;

		case L_TWO:
			GUI_SetColor(CUS_DARKGRAY);
			GUI_FillRoundedRect(67, 269, 106, 311, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('2', 83, 282);
			GUI_SetColor(GUI_BLACK);
			GUI_DrawLine(77, 299, 96, 299);
			break;

		case L_THREE:
			GUI_SetColor(CUS_DARKGRAY);
			GUI_FillRoundedRect(100, 269, 139, 311, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('3', 116, 282);
			GUI_SetColor(GUI_BLACK);
			GUI_DrawLine(110, 299, 127, 299);
			break;

		case L_FOUR:
			GUI_SetColor(CUS_DARKGRAY);
			GUI_FillRoundedRect(132, 269, 171, 311, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('4', 149, 282);
			GUI_SetColor(GUI_BLACK);
			GUI_DrawLine(143, 299, 160, 299);
			break;

		case L_FIVE:
			GUI_SetColor(CUS_DARKGRAY);
			GUI_FillRoundedRect(165, 269, 204, 311, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('5', 182, 282);
			GUI_SetColor(GUI_BLACK);
			GUI_DrawLine(176, 299, 193, 299);
			break;

		case L_AUTO:
			GUI_SetColor(CUS_DARKGRAY);
			GUI_FillRoundedRect(200, 269, 235, 311, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('A', 215, 282);
			GUI_SetColor(GUI_BLACK);
			GUI_DrawLine(209, 299, 226, 299);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

static void enableNextZoneState(ui_zone_state_t zoneState, uint8_t numOfZone)
{
	switch (numOfZone)
	{
	case ZONE_TOP:
		switch (zoneState)
		{
		case L_ONE:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_FillRoundedRect(35, 181, 73, 223, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('1', 50, 194);
			GUI_DrawLine(44, 211, 63, 211);
			break;

		case L_TWO:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_FillRoundedRect(67, 181, 106, 223, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('2', 83, 194);
			GUI_DrawLine(77, 211, 96, 211);
			break;

		case L_THREE:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_FillRoundedRect(100, 181, 139, 223, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('3', 116, 194);
			GUI_DrawLine(110, 211, 127, 211);
			break;

		case L_FOUR:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_FillRoundedRect(132, 181, 171, 223, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('4', 149, 194);
			GUI_DrawLine(143, 211, 160, 211);
			break;

		case L_FIVE:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_FillRoundedRect(165, 181, 204, 223, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('5', 182, 194);
			GUI_DrawLine(176, 211, 193, 211);
			break;

		case L_AUTO:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_FillRoundedRect(200, 181, 235, 223, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('A', 215, 194);
			GUI_DrawLine(209, 211, 226, 211);
			break;
		default:
			break;
		}
		break;

	case ZONE_MID:
		switch (zoneState)
		{
		case L_ONE:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_FillRoundedRect(35, 225, 73, 267, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('1', 50, 238);
			GUI_DrawLine(44, 255, 63, 255);
			break;

		case L_TWO:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_FillRoundedRect(67, 225, 106, 267, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('2', 83, 238);
			GUI_DrawLine(77, 255, 96, 255);
			break;

		case L_THREE:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_FillRoundedRect(100, 225, 139, 267, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('3', 116, 238);
			GUI_DrawLine(110, 255, 127, 255);
			break;

		case L_FOUR:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_FillRoundedRect(132, 225, 171, 267, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('4', 149, 238);
			GUI_DrawLine(143, 255, 160, 255);
			break;

		case L_FIVE:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_FillRoundedRect(165, 225, 204, 267, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('5', 182, 238);
			GUI_DrawLine(176, 255, 193, 255);
			break;

		case L_AUTO:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_FillRoundedRect(200, 225, 235, 267, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('A', 215, 238);
			GUI_DrawLine(209, 255, 226, 255);
			break;
		default:
			break;
		}
		break;

	case ZONE_BOT:
		switch (zoneState)
		{
		case L_ONE:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_FillRoundedRect(35, 269, 73, 311, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('1', 50, 282);
			GUI_DrawLine(44, 299, 63, 299);
			break;

		case L_TWO:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_FillRoundedRect(67, 269, 106, 311, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('2', 83, 282);
			GUI_DrawLine(77, 299, 96, 299);
			break;

		case L_THREE:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_FillRoundedRect(100, 269, 139, 311, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('3', 116, 282);
			GUI_DrawLine(110, 299, 127, 299);
			break;

		case L_FOUR:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_FillRoundedRect(132, 269, 171, 311, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('4', 149, 282);
			GUI_DrawLine(143, 299, 160, 299);
			break;

		case L_FIVE:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_FillRoundedRect(165, 269, 204, 311, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('5', 182, 282);
			GUI_DrawLine(176, 299, 193, 299);
			break;

		case L_AUTO:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_FillRoundedRect(200, 269, 235, 311, 8);
			GUI_SetColor(GUI_WHITE);
			GUI_DispCharAt('A', 215, 282);
			GUI_DrawLine(209, 299, 226, 299);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

static void enableNextZoneMode(ui_zone_state_t zoneState, uint8_t numOfZone)
{
	switch (numOfZone)
	{
	case ZONE_TOP:
		switch (zoneState)
		{
		case L_ONE:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_DrawLine(44, 211, 63, 211);
			break;
		case L_TWO:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_DrawLine(77, 211, 96, 211);
			break;
		case L_THREE:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_DrawLine(110, 211, 127, 211);
			break;
		case L_FOUR:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_DrawLine(143, 211, 160, 211);
			break;
		case L_FIVE:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_DrawLine(176, 211, 193, 211);
			break;
		case L_AUTO:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_DrawLine(209, 211, 226, 211);
			break;
		default:
			break;
		}
		break;
	case ZONE_MID:
		switch (zoneState)
		{
		case L_ONE:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_DrawLine(44, 255, 63, 255);
			break;
		case L_TWO:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_DrawLine(77, 255, 96, 255);
			break;
		case L_THREE:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_DrawLine(110, 255, 127, 255);
			break;
		case L_FOUR:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_DrawLine(143, 255, 160, 255);
			break;
		case L_FIVE:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_DrawLine(176, 255, 193, 255);
			break;
		case L_AUTO:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_DrawLine(209, 255, 226, 255);
			break;
		default:
			break;
		}
		break;
	case ZONE_BOT:
		switch (zoneState)
		{
		case L_ONE:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_DrawLine(44, 299, 63, 299);
			break;
		case L_TWO:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_DrawLine(77, 299, 96, 299);
			break;
		case L_THREE:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_DrawLine(110, 299, 127, 299);
			break;
		case L_FOUR:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_DrawLine(143, 299, 160, 299);
			break;
		case L_FIVE:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_DrawLine(176, 299, 193, 299);
			break;
		case L_AUTO:
			GUI_SetColor(CUS_LIGHTBLUE);
			GUI_DrawLine(209, 299, 226, 299);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

static void setZoneMode(ui_mode_t mode)
{
	ui_state_t state;
	switch (mode)
	{
	case ALL_DIM:
		enableNextZoneMode(L_FIVE, ZONE_TOP);
		enableNextZoneMode(L_FIVE, ZONE_MID);
		enableNextZoneMode(L_FIVE, ZONE_BOT);
		state.mode = ALL_DIM;
		state.state[0] = L_FIVE;
		state.state[1] = L_FIVE;
		state.state[2] = L_FIVE;
		break;
	case ALL_CLEAR:
		enableNextZoneMode(L_ONE, ZONE_TOP);
		enableNextZoneMode(L_ONE, ZONE_MID);
		enableNextZoneMode(L_ONE, ZONE_BOT);
		state.mode = ALL_CLEAR;
		state.state[0] = L_ONE;
		state.state[1] = L_ONE;
		state.state[2] = L_ONE;
		break;
	case PRESENTATION:
		enableNextZoneMode(L_THREE, ZONE_TOP);
		enableNextZoneMode(L_TWO, ZONE_MID);
		enableNextZoneMode(L_FIVE, ZONE_BOT);
		state.mode = PRESENTATION;
		state.state[0] = L_THREE;
		state.state[1] = L_TWO;
		state.state[2] = L_FIVE;
		break;
	case ALL_AUTO:
		enableNextZoneMode(L_AUTO, ZONE_TOP);
		enableNextZoneMode(L_AUTO, ZONE_MID);
		enableNextZoneMode(L_AUTO, ZONE_BOT);
		state.mode = ALL_AUTO;
		state.state[0] = L_AUTO;
		state.state[1] = L_AUTO;
		state.state[2] = L_AUTO;
		break;
	default:
		return;
	}
	UI_SetState(state);
}

void UI_ChangeMode(ui_mode_t mode)
{
	ui_state_t prevState;
	UI_GetState(&prevState);
	if (prevState.mode)
	{
		disablePrevZoneState(prevState.state[ZONE_TOP], ZONE_TOP);
		disablePrevZoneState(prevState.state[ZONE_MID], ZONE_MID);
		disablePrevZoneState(prevState.state[ZONE_BOT], ZONE_BOT);
		disablePrevMode(prevState.mode);
		enableNextMode(mode);
		setZoneMode(mode);
	}
	else
	{
		disablePrevZoneState(prevState.state[ZONE_TOP], ZONE_TOP);
		disablePrevZoneState(prevState.state[ZONE_MID], ZONE_MID);
		disablePrevZoneState(prevState.state[ZONE_BOT], ZONE_BOT);
		enableNextMode(mode);
		setZoneMode(mode);
	}
}

void UI_ChangeZoneState(ui_zone_state_t state, uint8_t numOfZone)
{
	ui_state_t prevState, nextState;
	UI_GetState(&prevState);
	nextState = prevState;

	if (prevState.mode)
	{
		disablePrevMode(prevState.mode);
		disablePrevZoneState(prevState.state[numOfZone], numOfZone);
		if (numOfZone == ZONE_TOP)
		{
			enableNextZoneState(prevState.state[ZONE_MID], ZONE_MID);
			enableNextZoneState(prevState.state[ZONE_BOT], ZONE_BOT);
			nextState.state[ZONE_MID] = prevState.state[ZONE_MID];
			nextState.state[ZONE_BOT] = prevState.state[ZONE_BOT];
		}
		else if (numOfZone == ZONE_MID)
		{
			enableNextZoneState(prevState.state[ZONE_TOP], ZONE_TOP);
			enableNextZoneState(prevState.state[ZONE_BOT], ZONE_BOT);
			nextState.state[ZONE_TOP] = prevState.state[ZONE_TOP];
			nextState.state[ZONE_BOT] = prevState.state[ZONE_BOT];
		}
		else if (numOfZone == ZONE_BOT)
		{
			enableNextZoneState(prevState.state[ZONE_MID], ZONE_MID);
			enableNextZoneState(prevState.state[ZONE_TOP], ZONE_TOP);
			nextState.state[ZONE_MID] = prevState.state[ZONE_MID];
			nextState.state[ZONE_TOP] = prevState.state[ZONE_TOP];
		}
	}
	else
	{
		disablePrevZoneState(prevState.state[numOfZone], numOfZone);
	}
	enableNextZoneState(state, numOfZone);
	nextState.state[numOfZone] = state;
	UI_SetState(nextState);
}

void graphicsMain(void)
{
	GUI_SetBkColor(GUI_TRANSPARENT);
	GUI_SelectLayer(1);
	GUI_Clear();
	GUI_SetBkColor(GUI_TRANSPARENT);
	GUI_SelectLayer(0);
	tp_state_t tpState;
	ui_state_t uiState;
	UI_SetDefault();
	UI_GetState(&uiState);
	drawAllNotActive();

	UI_ChangeMode(uiState.mode);
	UI_ChangeZoneState(uiState.state[ZONE_TOP], ZONE_TOP);
	UI_ChangeZoneState(uiState.state[ZONE_MID], ZONE_MID);
	UI_ChangeZoneState(uiState.state[ZONE_BOT], ZONE_BOT);

	while (1)
	{

		TP_GetState(&tpState);
		if (tpState.touchDetected)
		{
			if (tpState.x > 5 && tpState.x < 235 && tpState.y > 5 && tpState.y < 40)
			{
				UI_ChangeMode(ALL_DIM);
			}
			else if (tpState.x > 5 && tpState.x < 235 && tpState.y > 49 && tpState.y < 91)
			{
				UI_ChangeMode(ALL_CLEAR);
			}
			else if (tpState.x > 5 && tpState.x < 235 && tpState.y > 93 && tpState.y < 135)
			{
				UI_ChangeMode(PRESENTATION);
			}
			else if (tpState.x > 5 && tpState.x < 235 && tpState.y > 137 && tpState.y < 179)
			{
				UI_ChangeMode(ALL_AUTO);
			}


			else if (tpState.x > 33 && tpState.x < 66 && tpState.y > 181 && tpState.y < 223)
			{
				UI_ChangeZoneState(L_ONE, ZONE_TOP);
			}
			else if (tpState.x > 75 && tpState.x < 100 && tpState.y > 181 && tpState.y < 223)
			{
				UI_ChangeZoneState(L_TWO, ZONE_TOP);
			}
			else if (tpState.x > 108 && tpState.x < 133 && tpState.y > 181 && tpState.y < 223)
			{
				UI_ChangeZoneState(L_THREE, ZONE_TOP);
			}
			else if (tpState.x > 140 && tpState.x < 173 && tpState.y > 181 && tpState.y < 223)
			{
				UI_ChangeZoneState(L_FOUR, ZONE_TOP);
			}
			else if (tpState.x > 177 && tpState.x < 205 && tpState.y > 181 && tpState.y < 223)
			{
				UI_ChangeZoneState(L_FIVE, ZONE_TOP);
			}
			else if (tpState.x > 210 && tpState.x < 235 && tpState.y > 181 && tpState.y < 223)
			{
				UI_ChangeZoneState(L_AUTO, ZONE_TOP);
			}


			else if (tpState.x > 33 && tpState.x < 66 && tpState.y > 225 && tpState.y < 267)
			{
				UI_ChangeZoneState(L_ONE, ZONE_MID);
			}
			else if (tpState.x > 75 && tpState.x < 100 && tpState.y > 225 && tpState.y < 267)
			{
				UI_ChangeZoneState(L_TWO, ZONE_MID);
			}
			else if (tpState.x > 108 && tpState.x < 133 && tpState.y > 225 && tpState.y < 267)
			{
				UI_ChangeZoneState(L_THREE, ZONE_MID);
			}
			else if (tpState.x > 140 && tpState.x < 173 && tpState.y > 225 && tpState.y < 267)
			{
				UI_ChangeZoneState(L_FOUR, ZONE_MID);
			}
			else if (tpState.x > 177 && tpState.x < 205 && tpState.y > 225 && tpState.y < 267)
			{
				UI_ChangeZoneState(L_FIVE, ZONE_MID);
			}
			else if (tpState.x > 210 && tpState.x < 235 && tpState.y > 225 && tpState.y < 267)
			{
				UI_ChangeZoneState(L_AUTO, ZONE_MID);
			}


			else if (tpState.x > 33 && tpState.x < 66 && tpState.y > 269 && tpState.y < 311)
			{
				UI_ChangeZoneState(L_ONE, ZONE_BOT);
			}
			else if (tpState.x > 75 && tpState.x < 100 && tpState.y > 269 && tpState.y < 311)
			{
				UI_ChangeZoneState(L_TWO, ZONE_BOT);
			}
			else if (tpState.x > 108 && tpState.x < 133 && tpState.y > 269 && tpState.y < 311)
			{
				UI_ChangeZoneState(L_THREE, ZONE_BOT);
			}
			else if (tpState.x > 140 && tpState.x < 173 && tpState.y > 269 && tpState.y < 311)
			{
				UI_ChangeZoneState(L_FOUR, ZONE_BOT);
			}
			else if (tpState.x > 177 && tpState.x < 205 && tpState.y > 269 && tpState.y < 311)
			{
				UI_ChangeZoneState(L_FIVE, ZONE_BOT);
			}
			else if (tpState.x > 210 && tpState.x < 235 && tpState.y > 269 && tpState.y < 311)
			{
				UI_ChangeZoneState(L_AUTO, ZONE_BOT);
			}
			HAL_Delay(50);
		}

		/*
		TP_GetState(&tpState);
		if (tpState.touchDetected)
		{
			sprintf(str, "x=%3d, y=%3d", tpState.x, tpState.y);
			GUI_SetColor(GUI_WHITE);
			GUI_DrawPixel(tpState.x, tpState.y);
			GUI_SetColor(GUI_BLACK);
			GUI_FillRect(20,300,220,320);
			GUI_SetColor(GUI_WHITE);
			GUI_DispStringAt(str, 20, 300);
			HAL_Delay(10);
		}
		HAL_Delay(1);
		*/
	}
}

void drawTest(void)
{

	/* Rectangles */
	GUI_SetBkColor(CUS_BACKGROUND);
	GUI_Clear();
	GUI_SetDrawMode(GUI_DRAWMODE_NORMAL);
	GUI_SetTextMode(GUI_TM_NORMAL);
	GUI_SetFont(&GUI_Font8x16);

	GUI_SetColor(CUS_DARKGRAY);
	GUI_FillRoundedRect(5, 5, 235, 47, 8);
	GUI_SetColor(CUS_LIGHTBLUE);
	GUI_FillRoundedRect(5, 5, 26, 47, 8);
	GUI_SetColor(CUS_DARKGRAY);
	GUI_FillRect(15, 5, 30, 47);

	GUI_FillRoundedRect(5, 49, 235, 91, 8);
	GUI_SetColor(GUI_BLACK);
	GUI_FillRoundedRect(5, 49, 26, 91, 8);
	GUI_SetColor(CUS_DARKGRAY);
	GUI_FillRect(15, 49, 30, 91);

	GUI_FillRoundedRect(5, 93, 235, 135, 8);
	GUI_SetColor(GUI_BLACK);
	GUI_FillRoundedRect(5, 93, 26, 135, 8);
	GUI_SetColor(CUS_DARKGRAY);
	GUI_FillRect(15, 93, 30, 135);

	GUI_FillRoundedRect(5, 137, 235, 179, 8);
	GUI_SetColor(GUI_BLACK);
	GUI_FillRoundedRect(5, 137, 26, 179, 8);
	GUI_SetColor(CUS_DARKGRAY);
	GUI_FillRect(15, 137, 30, 179);


	GUI_FillRoundedRect(35, 181, 235, 223, 8);
	GUI_FillRoundedRect(35, 225, 235, 267, 8);
	GUI_FillRoundedRect(35, 269, 235, 311, 8);


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

/*
 * 	switch (uiState.mode)
	{
	case NOT_ACTIVE:
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRoundedRect(5, 5, 235, 47, 8);
		GUI_SetColor(GUI_BLACK);
		GUI_FillRoundedRect(5, 5, 26, 47, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 5, 30, 47);

		GUI_FillRoundedRect(5, 49, 235, 91, 8);
		GUI_SetColor(GUI_BLACK);
		GUI_FillRoundedRect(5, 49, 26, 91, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 49, 30, 91);

		GUI_FillRoundedRect(5, 93, 235, 135, 8);
		GUI_SetColor(GUI_BLACK);
		GUI_FillRoundedRect(5, 93, 26, 135, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 93, 30, 135);

		GUI_FillRoundedRect(5, 137, 235, 179, 8);
		GUI_SetColor(GUI_BLACK);
		GUI_FillRoundedRect(5, 137, 26, 179, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 137, 30, 179);

		GUI_SetColor(GUI_BLACK);
		GUI_DrawLine(24, 35, 225, 35);
		GUI_DrawLine(24, 79, 225, 79);
		GUI_DrawLine(24, 123, 225, 123);
		GUI_DrawLine(24, 167, 225, 167);

		GUI_SetTextMode(GUI_TM_TRANS);
		GUI_EnableAlpha(1);
		GUI_SetColor(GUI_WHITE);
		GUI_DispStringAt("ALL DIM", 25, 18);
		GUI_DispStringAt("ALL CLEAR", 25, 62);
		GUI_DispStringAt("PRESENTATION MODE", 25, 106);
		GUI_DispStringAt("ALL AUTO", 25, 150);
		GUI_EnableAlpha(0);

		break;

	case ALL_DIM:
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRoundedRect(5, 5, 235, 47, 8);
		GUI_SetColor(CUS_LIGHTBLUE);
		GUI_FillRoundedRect(5, 5, 26, 47, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 5, 30, 47);

		GUI_FillRoundedRect(5, 49, 235, 91, 8);
		GUI_SetColor(GUI_BLACK);
		GUI_FillRoundedRect(5, 49, 26, 91, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 49, 30, 91);

		GUI_FillRoundedRect(5, 93, 235, 135, 8);
		GUI_SetColor(GUI_BLACK);
		GUI_FillRoundedRect(5, 93, 26, 135, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 93, 30, 135);

		GUI_FillRoundedRect(5, 137, 235, 179, 8);
		GUI_SetColor(GUI_BLACK);
		GUI_FillRoundedRect(5, 137, 26, 179, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 137, 30, 179);

		GUI_SetColor(CUS_LIGHTBLUE);
		GUI_DrawLine(24, 35, 225, 35);
		GUI_SetColor(GUI_BLACK);
		GUI_DrawLine(24, 79, 225, 79);
		GUI_DrawLine(24, 123, 225, 123);
		GUI_DrawLine(24, 167, 225, 167);

		GUI_SetTextMode(GUI_TM_TRANS);
		GUI_EnableAlpha(1);
		GUI_SetColor(GUI_WHITE);
		GUI_DispStringAt("ALL DIM", 25, 18);
		GUI_DispStringAt("ALL CLEAR", 25, 62);
		GUI_DispStringAt("PRESENTATION MODE", 25, 106);
		GUI_DispStringAt("ALL AUTO", 25, 150);
		GUI_EnableAlpha(0);

		break;

	case ALL_CLEAR:
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRoundedRect(5, 5, 235, 47, 8);
		GUI_SetColor(GUI_BLACK);
		GUI_FillRoundedRect(5, 5, 26, 47, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 5, 30, 47);

		GUI_FillRoundedRect(5, 49, 235, 91, 8);
		GUI_SetColor(CUS_LIGHTBLUE);
		GUI_FillRoundedRect(5, 49, 26, 91, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 49, 30, 91);

		GUI_FillRoundedRect(5, 93, 235, 135, 8);
		GUI_SetColor(GUI_BLACK);
		GUI_FillRoundedRect(5, 93, 26, 135, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 93, 30, 135);

		GUI_FillRoundedRect(5, 137, 235, 179, 8);
		GUI_SetColor(GUI_BLACK);
		GUI_FillRoundedRect(5, 137, 26, 179, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 137, 30, 179);

		GUI_SetColor(GUI_BLACK);
		GUI_DrawLine(24, 35, 225, 35);
		GUI_SetColor(CUS_LIGHTBLUE);
		GUI_DrawLine(24, 79, 225, 79);
		GUI_SetColor(GUI_BLACK);
		GUI_DrawLine(24, 123, 225, 123);
		GUI_DrawLine(24, 167, 225, 167);

		GUI_SetTextMode(GUI_TM_TRANS);
		GUI_EnableAlpha(1);
		GUI_SetColor(GUI_WHITE);
		GUI_DispStringAt("ALL DIM", 25, 18);
		GUI_DispStringAt("ALL CLEAR", 25, 62);
		GUI_DispStringAt("PRESENTATION MODE", 25, 106);
		GUI_DispStringAt("ALL AUTO", 25, 150);
		GUI_EnableAlpha(0);

		break;

	case PRESENTATION:
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRoundedRect(5, 5, 235, 47, 8);
		GUI_SetColor(GUI_BLACK);
		GUI_FillRoundedRect(5, 5, 26, 47, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 5, 30, 47);

		GUI_FillRoundedRect(5, 49, 235, 91, 8);
		GUI_SetColor(GUI_BLACK);
		GUI_FillRoundedRect(5, 49, 26, 91, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 49, 30, 91);

		GUI_FillRoundedRect(5, 93, 235, 135, 8);
		GUI_SetColor(CUS_LIGHTBLUE);
		GUI_FillRoundedRect(5, 93, 26, 135, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 93, 30, 135);

		GUI_FillRoundedRect(5, 137, 235, 179, 8);
		GUI_SetColor(GUI_BLACK);
		GUI_FillRoundedRect(5, 137, 26, 179, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 137, 30, 179);

		GUI_SetColor(GUI_BLACK);
		GUI_DrawLine(24, 35, 225, 35);
		GUI_DrawLine(24, 79, 225, 79);
		GUI_SetColor(CUS_LIGHTBLUE);
		GUI_DrawLine(24, 123, 225, 123);
		GUI_SetColor(GUI_BLACK);
		GUI_DrawLine(24, 167, 225, 167);

		GUI_SetTextMode(GUI_TM_TRANS);
		GUI_EnableAlpha(1);
		GUI_SetColor(GUI_WHITE);
		GUI_DispStringAt("ALL DIM", 25, 18);
		GUI_DispStringAt("ALL CLEAR", 25, 62);
		GUI_DispStringAt("PRESENTATION MODE", 25, 106);
		GUI_DispStringAt("ALL AUTO", 25, 150);
		GUI_EnableAlpha(0);

		break;

	case ALL_AUTO:
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRoundedRect(5, 5, 235, 47, 8);
		GUI_SetColor(GUI_BLACK);
		GUI_FillRoundedRect(5, 5, 26, 47, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 5, 30, 47);

		GUI_FillRoundedRect(5, 49, 235, 91, 8);
		GUI_SetColor(GUI_BLACK);
		GUI_FillRoundedRect(5, 49, 26, 91, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 49, 30, 91);

		GUI_FillRoundedRect(5, 93, 235, 135, 8);
		GUI_SetColor(GUI_BLACK);
		GUI_FillRoundedRect(5, 93, 26, 135, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 93, 30, 135);

		GUI_FillRoundedRect(5, 137, 235, 179, 8);
		GUI_SetColor(CUS_LIGHTBLUE);
		GUI_FillRoundedRect(5, 137, 26, 179, 8);
		GUI_SetColor(CUS_DARKGRAY);
		GUI_FillRect(15, 137, 30, 179);

		GUI_SetColor(GUI_BLACK);
		GUI_DrawLine(24, 35, 225, 35);
		GUI_DrawLine(24, 79, 225, 79);
		GUI_DrawLine(24, 123, 225, 123);
		GUI_SetColor(CUS_LIGHTBLUE);
		GUI_DrawLine(24, 167, 225, 167);

		GUI_SetTextMode(GUI_TM_TRANS);
		GUI_EnableAlpha(1);
		GUI_SetColor(GUI_WHITE);
		GUI_DispStringAt("ALL DIM", 25, 18);
		GUI_DispStringAt("ALL CLEAR", 25, 62);
		GUI_DispStringAt("PRESENTATION MODE", 25, 106);
		GUI_DispStringAt("ALL AUTO", 25, 150);
		GUI_EnableAlpha(0);

		break;
	}
*/
