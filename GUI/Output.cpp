
#include "Output.h"
#include<iostream>
Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 60;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = BLACK;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

void Output::GetUserColor(Input* pInput, color& c,color & f) const
{// Prompt the user to input a color
	PrintMessage("Do u wanna change fill color yes or no");

	// Get the user's input as a string
	string userInput = pInput->GetSrting(const_cast<Output*>(this));
	GfxInfo fill;
	fill.isFilled = false;
	// Map the input string to a corresponding color
	if (userInput == "yes" || userInput == "YES") {
		PrintMessage("Please enter a color (e.g.,r for RED,g for GREEN, b for BLUE,y for Yellow,o for ORANGE):");
		string userInput = pInput->GetSrting(const_cast<Output*>(this));

		if (userInput == "r" || userInput == "R") {
			fill.isFilled = true;
			c = RED;
			f = RED;
		}
		else if (userInput == "g" || userInput == "G") {
			fill.isFilled = true;
			c = GREEN;
			f = GREEN;
		}
		else if (userInput == "b" || userInput == "B") {
			fill.isFilled = true;
			c = BLUE;
			f = BLUE;
		}
		else if (userInput == "y" || userInput == "Y") {
			fill.isFilled = true;
			c = YELLOW;
			f = YELLOW;
		}
		else if (userInput == "bl" || userInput == "BL") {
			fill.isFilled = true;
			c = BLACK;
			f = BLACK;
		}
		else if (userInput == "o" || userInput == "O") {
			fill.isFilled = true;
			c = ORANGE;
			f = ORANGE;
		}
		else if (userInput == "o" || userInput == "O") {
			fill.isFilled = true;
			c = ORANGE;
			f = ORANGE;
		}
		else
			c = NULL;
		fill.isFilled = false;
	}
	else {
		fill.isFilled = false;
		c = NULL;
		return;
	}
}




window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];

	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";

	MenuItemImages[ITM_SQR] = "images\\MenuItems\\Menu_Sqr.jpg";

	MenuItemImages[ITM_TRIG] = "images\\MenuItems\\Menu_Trig.jpg";

	MenuItemImages[ITM_HEX] = "images\\MenuItems\\Menu_Hex.jpg";

	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Menu_Circ.jpg";

	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\Menu_Undo.jpg";

	MenuItemImages[ITM_REDO] = "images\\MenuItems\\Menu_Redo.jpg";

	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";

	MenuItemImages[ITM_SWAP] = "images\\MenuItems\\Menu_Swap.jpg";

	MenuItemImages[ITM_RCCW] = "images\\MenuItems\\Menu_RCCW.jpg";

	MenuItemImages[ITM_RCW] = "images\\MenuItems\\Menu_RCW.jpg";

	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_Delete.jpg";

	MenuItemImages[ITM_COPY] = "images\\MenuItems\\Menu_Copy.jpg";

	MenuItemImages[ITM_CUT] = "images\\MenuItems\\Menu_Cut.jpg";

	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\Menu_Paste.jpg";

	MenuItemImages[ITM_CLEARALL] = "images\\MenuItems\\Menu_ClearAll.jpg";

	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Menu_Save.jpg";

	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_Load.jpg";

	MenuItemImages[ITM_PLAY] = "images\\MenuItems\\Menu_Play.jpg";

	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;

	string MenuItemImages[PLAY_ITM_COUNT];
	
	MenuItemImages[ITM_MATCHING] = "images\\MenuItems\\Menu_Matching.jpg";

	MenuItemImages[ITM_MISSING] = "images\\MenuItems\\Menu_Missing.jpg";

	MenuItemImages[ITM_DRAW] = "images\\MenuItems\\Menu_Draw.jpg";

	MenuItemImages[ITM_EXIT2] = "images\\MenuItems\\Menu_Exit.jpg";
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	CreateDrawToolBar();


}

void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
	CreateDrawToolBar();

}

void Output::DrawCirc(Point Center, Point P2, GfxInfo CircGfxInfo, bool selected) const
{
	int rad;
	rad = pow(pow(Center.x - P2.x, 2) + pow(Center.y - P2.y, 2), 0.5);
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawCircle(Center.x, Center.y, rad, style);
	CreateDrawToolBar();
	
}

void Output::DrawHexa(const int Xcoord[6], const int Ycoord[6], GfxInfo HexaGfxInfo, bool selected) const
{
    color DrawingClr;
    if (selected)
        DrawingClr = UI.HighlightColor; // Figure should be drawn highlighted
    else
        DrawingClr = HexaGfxInfo.DrawClr;

    pWind->SetPen(DrawingClr, 1);
    drawstyle style;
    if (HexaGfxInfo.isFilled)
    {
        style = FILLED;
        pWind->SetBrush(HexaGfxInfo.FillClr);
    }
    else
        style = FRAME;

    // Draw the hexagon using the passed coordinates
    pWind->DrawPolygon(Xcoord, Ycoord, 6, style);
    CreateDrawToolBar();
}


void Output::DrawSquare(Point Center, GfxInfo SquareGfxInfo, bool selected) const
{
	cout << "Drawing square at center: (" << Center.x << ", " << Center.y << ")\n";
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = SquareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (SquareGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SquareGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int vert = 4;
	int coordx[4] = { Center.x - 50,Center.x - 50,Center.x + 50,Center.x + 50 };
	int coordy[4] = { Center.y - 50,Center.y + 50,Center.y + 50,Center.y - 50 };


	pWind->DrawPolygon(coordx, coordy, vert, style);
	CreateDrawToolBar();
	
}

bool Output::getSave() const
{
	PrintMessage("Do you want to save first? (y/n)");
	Input* pIn = CreateInput();
	string userInput = pIn->GetSrting(const_cast<Output*>(this));
	if (userInput == "y" || userInput == "Y")
		return true;
	else
		return false;
}

Output::~Output()
{
	delete pWind;
}

