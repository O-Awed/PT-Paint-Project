#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: 
				return DRAW_RECT;

			case ITM_SQR: 
				return DRAW_SQR;

			case ITM_TRIG: 
				return DRAW_TRIG;

			case ITM_HEX: 
				return DRAW_HEX; 	   

			case ITM_CIRC: 
				return DRAW_CIRC;

			case ITM_UNDO: 
				return UNDO;

			case ITM_REDO: 
				return REDO;

			case ITM_SELECT: 
				return SELECT; 

			case ITM_SWAP: 
				return SWAP;

			case ITM_RCCW: 
				return RCCW;

			case ITM_RCW: 
				return RCW;

			case ITM_DELETE:
				return DEL;

			case ITM_COPY: 
				return COPY;

			case ITM_CUT: 
				return CUT;

			case ITM_PASTE:	
				return PASTE;

			case ITM_CLEARALL: 
				return CLRALL;

			case ITM_SAVE: 
				return SAVE;

			case ITM_LOAD: 
				return LOAD;

			case ITM_PLAY: 
				return TO_PLAY;

			case ITM_EXIT:
				return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_PLAY)	//GUI is in PLAY mode
	{

		if (y >= 0 && y < UI.ToolBarHeight) {

			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder) {

			case    ITM_MATCHING: 
				return MATCHING;	

			case	ITM_MISSING:  
				return MISSING;	

			case	ITM_DRAW:  
				return TO_DRAW;

			case	ITM_EXIT2: 
				return EXIT;		

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		return TO_PLAY;	//just for now. This should be updated

		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		return STATUS;
	}
}
/////////////////////////////////

Input::~Input()
{
}
