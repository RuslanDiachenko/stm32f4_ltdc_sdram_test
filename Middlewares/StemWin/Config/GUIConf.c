#include "GUI.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/

// Define the available number of bytes available for the GUI

#define GUI_NUMBYTES  (140 * 1024)

//
// 32 bit aligned memory area
//
U32 aMemory[GUI_NUMBYTES / 4];

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       GUI_X_Config
*
* Purpose:
*   Called during the initialization process in order to set up the
*   available memory for the GUI.
*/
void GUI_X_Config(void) {
  //
  // Assign memory to STemWin
  //
  GUI_ALLOC_AssignMemory(aMemory, GUI_NUMBYTES);
  //
  // Set default font
  //
  GUI_SetDefaultFont(GUI_FONT_6X8);
}
