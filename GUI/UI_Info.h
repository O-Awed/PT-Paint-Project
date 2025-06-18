#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here

	ITM_RECT,		//Recangle item in menu

	ITM_SQR,		//Square item

	ITM_TRIG,		//Triangle item

	ITM_HEX,		//Hexagon item

	ITM_CIRC,		//Circle item

	ITM_UNDO,		//Undo item

	ITM_REDO,		//Redo item

	ITM_SELECT,     //Select item

	ITM_SWAP,		//Swap item

	ITM_RCCW,		//Rotate counter clockwise item

	ITM_RCW,		//Rotate clockwise item

	ITM_DELETE,		//Delete item

	ITM_COPY,		//Copy item

	ITM_CUT,		//Cut item

	ITM_PASTE,		//Paste item

	ITM_CLEARALL,	//Clear all items

	ITM_SAVE,		//Save item

	ITM_LOAD,		//Load item

	ITM_PLAY,		//Switch to play mode item

	ITM_EXIT,		//Exit item



	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here

	//TODO: Add more items names here

	ITM_MATCHING,	//Matching item in menu

	ITM_MISSING,	//Missing item

	ITM_DRAW,		//Switch to draw mode item

	ITM_EXIT2,		//Exit item


	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	    //Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		LineUnderTBWidth,	//line Under the Toolbar Pen Width
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed

}UI;	//create a global object UI

#endif