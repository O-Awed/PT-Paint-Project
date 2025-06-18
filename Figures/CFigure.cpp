#include "CFigure.h"
#include "../ApplicationManager.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	FigureGfxInfo.isFilled = false;
}
CFigure::CFigure()
{
}
GfxInfo CFigure::getGfxInfo()
{
	return FigGfxInfo;
}
void CFigure::setGfxInfo(const GfxInfo& gfxInfo)
{
	FigGfxInfo = gfxInfo;
}


void CFigure::setDrawClr(GfxInfo FigureGfxInfo){
FigGfxInfo = FigureGfxInfo;
if (FigGfxInfo.DrawClr == BLACK)
{
	DrawColor = "Not_Filled";
		FillColor = "Not_Filled";
}
else if (FigGfxInfo.DrawClr == BLUE)
{
	DrawColor = "Blue";
	FillColor = "Blue";
}
else if (FigGfxInfo.DrawClr == GREEN)
{
	DrawColor = "Green";
	FillColor = "Green";
}
else if (FigGfxInfo.DrawClr == YELLOW)
{
	DrawColor = "Yellow";
	FillColor = "Yellow";
}
else if (FigGfxInfo.DrawClr == RED)
{
	DrawColor = "Red";
	FillColor = "Red";
}
else if (FigGfxInfo.DrawClr == ORANGE)
{
	DrawColor = "Orange";
	FillColor = "Orange";
}
else if (FigGfxInfo.DrawClr == NULL)
{
	DrawColor = "Not_Filled";
	FillColor = "Not_Filled";
}
else if (FigGfxInfo.isFilled == false)
{ 
	DrawColor = "Not_Filled";
	FillColor = "Not_Filled";
}
else if (FigGfxInfo.FillClr == GREY)
{
	DrawColor= "Not_Filled";
	FillColor = "Not_Filled";
}
}


void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::setID(int id)
{
	ID = id;
}

int CFigure::getID()
{
	return ID;
}

string CFigure::gettype()
{
	return Type;
}

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.DrawClr = Fclr;
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
color CFigure::stringtocolor(string clr)
{
	Output* pout{};

	if (clr == "Black")
		return BLACK;
	else if (clr == "Blue")
		return BLUE;
	else if (clr == "Red")
		return RED;
	else if (clr == "Green")
		return GREEN;
	else if (clr == "Yellow")
		return YELLOW;
	else if (clr == "Orange")
		return ORANGE;
	else if (clr == "Not_Filled")
		return FigGfxInfo.isFilled = false;
	else return NULL;
}




