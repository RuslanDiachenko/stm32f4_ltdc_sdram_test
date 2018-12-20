/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.32                          *
*        Compiled Oct  8 2015, 11:59:02                              *
*        (c) 2015 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END

#include "DIALOG.h"
#include "IMAGE.h"
#include "main.h"
#include <stdlib.h>
/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_FRAMEWIN_0  (GUI_ID_USER + 0x00)
#define ID_BUTTON_0  (GUI_ID_USER + 0x01)
#define ID_CHECKBOX_0  (GUI_ID_USER + 0x02)

#define MYWIDGET_CI_UNPRESSED 	0
#define MYWIDGET_CI_PRESSED 	1
#define MYWIDGET_CI_DISABLED 	2

// USER START (Optionally insert additional defines)
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "CheckBox", ID_FRAMEWIN_0, 0, 0, 240, 320, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_0, 62, 27, 80, 20, 0, 0x0, 0 },
  { CHECKBOX_CreateIndirect, "Checkbox", ID_CHECKBOX_0, 63, 78, 80, 20, 0, 0x0, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  static uint8_t checkBoxState = 0;
  WM_HWIN hItem;
  int     NCode;
  int     Id;
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'CheckBox'
    //
    hItem = pMsg->hWin;
    FRAMEWIN_SetTitleVis(hItem, 0);
    FRAMEWIN_SetTitleHeight(hItem, 14);
    //
    // Initialization of 'Checkbox'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_0);
    CHECKBOX_SetText(hItem, "Check");
    // USER START (Optionally insert additional code for further widget initialization)
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_BUTTON_0: // Notifications sent by 'Button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
    	  if (checkBoxState)
    	  {
    		  HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
    	  }
    	  else
    	  {
    		  HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
    	  }
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_CHECKBOX_0: // Notifications sent by 'Checkbox'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        // USER START (Optionally insert code for reacting on notification message)
    	  checkBoxState = !checkBoxState;
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;
  // USER START (Optionally insert additional message handling)
  // USER END
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       CreateCheckBox
*/
WM_HWIN CreateCheckBox(void);
WM_HWIN CreateCheckBox(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

/* Custom widget */

typedef WM_HMEM MYWIDGET_Handle;

typedef struct
{
	U8			pressed;
	GUI_COLOR	aBkColor[3];
	GUI_COLOR	aTextColor[3];
	GUI_COLOR	focusColor;
	const char *pText;
	int 		NumExtraBytes;
} MYWIDGET_Obj;

const MYWIDGET_Obj MYWIDGET_Default = {
 0, 												/* U8 Pressed; 				*/
 { GUI_DARKBLUE, GUI_LIGHTBLUE, GUI_GRAY }, 		/* GUI_COLOR aBkColor[3];   */
 { GUI_WHITE, GUI_DARKGRAY, GUI_LIGHTGRAY }, 		/* GUI_COLOR aTextColor[3]; */
 GUI_ORANGE, 										/* GUI_COLOR FocusColor;	*/
 NULL, 												/* const char * pText;		*/
 0 													/* int NumExtraBytes;		*/
};

MYWIDGET_Handle MW_Create(int x0, int y0, int xSize, int ySize, WM_HWIN hWinParent, U32 Style, const char *pText, WM_CALLBACK *cb, int numExtraBytes);
void MYWIDGET_Callback(WM_MESSAGE *pMsg);

WM_HWIN MW_Create(int x0, int y0, int xSize, int ySize, WM_HWIN hWinParent, U32 Style, const char *pText, WM_CALLBACK *cb, int numExtraBytes)
{
	WM_HWIN 		hWin;
	MYWIDGET_Obj	myWidget;
	WM_CALLBACK		*pfUsed;

	if (cb)
	{
		pfUsed = cb;
	}
	else
	{
		pfUsed = MYWIDGET_Callback;
	}
	hWin = WM_CreateWindowAsChild(x0, y0, xSize, ySize, hWinParent, Style, pfUsed, sizeof(MYWIDGET_Obj) + numExtraBytes);

	myWidget = MYWIDGET_Default;
	myWidget.NumExtraBytes = numExtraBytes;

	if (pText)
	{
		myWidget.pText = pText;
	}
	WM_SetUserData(hWin, &myWidget, sizeof(MYWIDGET_Obj));
	return hWin;
}

void MYWIDGET_Callback(WM_MESSAGE *pMsg)
{
	MYWIDGET_Handle hWin;
	GUI_PID_STATE	*pState;
	MYWIDGET_Obj	myWidget;
	GUI_RECT		winRect;
	int				colorIndex;

	hWin = pMsg->MsgId;

	WM_GetWindowRectEx(hWin, &winRect);
	GUI_MoveRect(&winRect, -winRect.x0, -winRect.y0);
	WM_GetUserData(hWin, &myWidget, sizeof(MYWIDGET_Obj));

	switch (pMsg->MsgId)
	{
	case WM_PAINT:
	 /* Determine the color according to the current state */
		if (WM_IsEnabled(hWin))
		{
			if (myWidget.pressed)
			{
				colorIndex = MYWIDGET_CI_PRESSED;
			}
			else
			{
				colorIndex = MYWIDGET_CI_UNPRESSED;
			}
		}
		else
		{
			colorIndex = MYWIDGET_CI_DISABLED;
		}

		/* Draw the background */
		GUI_SetColor(myWidget.aBkColor[colorIndex]);
		GUI_FillRectEx(&winRect);
		/* Draw the focus rectangle */
		if (WM_HasFocus(hWin))
		{
			GUI_SetColor(myWidget.focusColor);
			GUI_DrawRectEx(&winRect);
		}
		/* Display the text */
		GUI_SetColor(myWidget.aTextColor[colorIndex]);
		GUI_SetTextMode(GUI_TM_TRANS);
		GUI_DispStringInRect(myWidget.pText, &winRect, GUI_TA_HCENTER | GUI_TA_VCENTER);
		break;

	case WM_TOUCH:
		 if (pMsg->Data.p)
		 {
			 pState = (GUI_PID_STATE *)pMsg->Data.p;
			 if (myWidget.pressed != pState->Pressed)
			 {
				 myWidget.pressed = pState->Pressed;
				 WM_SetUserData(hWin, &myWidget, sizeof(MYWIDGET_Obj));
				 if (myWidget.pressed)
				 {
					 WM_SetFocus(hWin);
				 }
				 WM_InvalidateWindow(hWin);
			 }
		 }
		 else
		 {
			 myWidget.pressed = 0;
			 WM_SetUserData(hWin, &myWidget, sizeof(MYWIDGET_Obj));
			 WM_InvalidateWindow(hWin);
		 }
		 break;
	case WM_SET_FOCUS:
		if (pMsg->Data.v)
		{
			pMsg->Data.v = 0;
		}
		WM_InvalidateWindow(hWin);
		break;
	default:
		WM_DefaultProc(pMsg);
	}
}

int MYWIDGET_GetUserData(MYWIDGET_Handle hWin, void * pDest, int SizeOfBuffer)
{
 MYWIDGET_Obj MyWidget;
 int NumBytes;
 U8 * pExtraBytes;

 if (SizeOfBuffer <= 0)
 {
	 return 0;
 }

 WM_GetUserData(hWin, &MyWidget, sizeof(MYWIDGET_Obj));
 pExtraBytes = (U8 *)malloc(sizeof(MYWIDGET_Obj) + MyWidget.NumExtraBytes);
 if (pExtraBytes)
 {
	 WM_GetUserData(hWin, pExtraBytes, sizeof(MYWIDGET_Obj) + MyWidget.NumExtraBytes);
	 if (SizeOfBuffer >= MyWidget.NumExtraBytes)
	 {
		 NumBytes = MyWidget.NumExtraBytes;
	 }
	 else
	 {
		 NumBytes = SizeOfBuffer;
	 }
	 GUI_MEMCPY(pDest, pExtraBytes + sizeof(MYWIDGET_Obj), NumBytes);
	 free(pExtraBytes);
	 return NumBytes;
 }
 return 0;
}

int MYWIDGET_SetUserData(MYWIDGET_Handle hWin, void * pSrc, int SizeOfBuffer)
{
 MYWIDGET_Obj MyWidget;
 int NumBytes;
 U8 * pExtraBytes;
 if (SizeOfBuffer <= 0)
 {
	 return 1;
 }
 WM_GetUserData(hWin, &MyWidget, sizeof(MYWIDGET_Obj));
 pExtraBytes = (U8 *)malloc(sizeof(MYWIDGET_Obj) + MyWidget.NumExtraBytes);
 if (pExtraBytes)
 {
	 WM_GetUserData(hWin, pExtraBytes,
	 sizeof(MYWIDGET_Obj) + MyWidget.NumExtraBytes);
	 if (SizeOfBuffer >= MyWidget.NumExtraBytes)
	 {
		 NumBytes = MyWidget.NumExtraBytes;
	 }
	 else
	 {
		 NumBytes = SizeOfBuffer;
	 }
	 GUI_MEMCPY(pExtraBytes + sizeof(MYWIDGET_Obj), pSrc, NumBytes);
	 WM_SetUserData(hWin, pExtraBytes,
	 sizeof(MYWIDGET_Obj) + MyWidget.NumExtraBytes);
	 free(pExtraBytes);
	 return 0;
 }
 return 1;
}

/* Final callback of MyWidget */
void _cbMyWidget(WM_MESSAGE *pMsg)
{
	 GUI_RECT WinRect;
	 char acText[20] = { 0 };
	 switch (pMsg->MsgId) {
	 case WM_PAINT:
		 MYWIDGET_Callback(pMsg);
		 MYWIDGET_GetUserData(pMsg->hWin, acText, sizeof(acText));
		 GUI_SetColor(GUI_WHITE);
		 GUI_SetTextMode(GUI_TM_TRANS);
		 WM_GetWindowRectEx(pMsg->hWin, &WinRect);
		 GUI_MoveRect(&WinRect, -WinRect.x0, -WinRect.y0);
		 GUI_DispStringInRect(acText, &WinRect, GUI_TA_HCENTER | GUI_TA_VCENTER);
		 break;
	 default:
		 MYWIDGET_Callback(pMsg);
	 }
}

/* pool */
void mainWindow(void)
{
	GUI_SetBkColor(GUI_BLACK);
	GUI_SetColor(GUI_DARKGRAY);
	GUI_AA_FillRoundedRect(10, 10, 230, 40, 8);
	//GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	//GUI_ExecDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, 0, 0, 0);

	/*
	MYWIDGET_Handle		hMyWidget;
	char				acExtraBytes[] = "ExtraBytes";
	hMyWidget = MW_Create(10,10,100,50,WM_HBKWIN, WM_CF_SHOW, NULL, _cbMyWidget, strlen("ExtraBytes"));
	MYWIDGET_SetUserData(hMyWidget, acExtraBytes, strlen(acExtraBytes));
	BUTTON_Create(10,100,100,50,0, WM_CF_SHOW); */
	while (1)
	{
		//GUI_ExecDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, 0, 0, 0);
		GUI_Delay(10);
	}
}
// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
