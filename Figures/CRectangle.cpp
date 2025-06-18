#include "CRectangle.h"
#include <fstream>
#include <iostream>
CRectangle::CRectangle()
{
	Type = "Rectangle";
}
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	setDrawClr(FigureGfxInfo);
	Type = "Rectangle";
	FigureGfxInfo.isFilled = false;

}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle::isPointInside(Point P)
{
	if (P.x >= Corner1.x && P.x <= Corner2.x && P.y >= Corner1.y && P.y <= Corner2.y)
		return true;
	return false;
}

Point CRectangle::PasteRec(Point P1, Output* pOut)
{
	Point P2;
	P2.x = P1.x + abs(Corner1.x - Corner2.x);
	P2.y = P1.y + abs(Corner1.y - Corner2.y);

	pOut->DrawRect(P1, P2, FigGfxInfo);

	return P2;
}

Point CRectangle::GetCorner1()
{
	return Corner1;
}

Point CRectangle::GetCorner2()
{
	return Corner2;
}

void CRectangle::rotateCCW()  // Counter Clockwise
{
	Center.x = (Corner1.x + Corner2.x)/2;
	Center.y = (Corner1.y + Corner2.y ) / 2;

	int newX1 = Center.x + (Corner1.y - Center.y);
	int newY1 = Center.y - (Corner1.x - Center.x);

	int newX2 = Center.x + (Corner2.y - Center.y);
	int newY2 = Center.y - (Corner2.x - Center.x);

	


	Corner1.x = newX1;
	Corner1.y = newY1;

	Corner2.x = newX2;
	Corner2.y = newY2;



}

void CRectangle::rotatecw()  // Clockwise
{
	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y) / 2;

	int newX1 = Center.x - (Corner1.y - Center.y);
	int newY1 = Center.y + (Corner1.x - Center.x);

	int newX2 = Center.x - (Corner2.y - Center.y);
	int newY2 = Center.y + (Corner2.x - Center.x);




	Corner1.x = newX1;
	Corner1.y = newY1;

	Corner2.x = newX2;
	Corner2.y = newY2;

}
void CRectangle::Save(ofstream& OutFile)
{
	OutFile.app;
	OutFile << Type << " " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << " " << DrawColor << " " << FillColor << endl;
}

void CRectangle::swap(CFigure* fig)
{
	if (fig->gettype() == "triangle") {

		Point tempCenter = getcenter();
		setcenter(fig->getcenter());
		fig->setcenter(tempCenter);
		GfxInfo tempGfxInfo = getGfxInfo();
		setGfxInfo(fig->getGfxInfo());
		fig->setGfxInfo(tempGfxInfo);


	}
	if (fig->gettype() == "Rectangle") {

		Point tempCenter = getcenter();
		setcenter(fig->getcenter());
		fig->setcenter(tempCenter);
		GfxInfo tempGfxInfo = getGfxInfo();
		setGfxInfo(fig->getGfxInfo());
		fig->setGfxInfo(tempGfxInfo);
	}
	if (fig->gettype() == "Hexagon") {
		Point tempCenter = getcenter();
		setcenter(fig->getcenter());
		fig->setcenter(tempCenter);
		GfxInfo tempGfxInfo = getGfxInfo();
		setGfxInfo(fig->getGfxInfo());
		fig->setGfxInfo(tempGfxInfo);

	}
	if (fig->gettype() == "Square") {
		Point tempCenter = getcenter();
		setcenter(fig->getcenter());
		fig->setcenter(tempCenter);
		GfxInfo tempGfxInfo = getGfxInfo();
		setGfxInfo(fig->getGfxInfo());
		fig->setGfxInfo(tempGfxInfo);

	}
	if (fig->gettype() == "circle") {
		Point tempCenter = getcenter();
		setcenter(fig->getcenter());
		fig->setcenter(tempCenter);
		GfxInfo tempGfxInfo = getGfxInfo();
		setGfxInfo(fig->getGfxInfo());
		fig->setGfxInfo(tempGfxInfo);

	}
}

Point CRectangle::getcenter() const
{
	Point center;
	center.x = (Corner1.x + Corner2.x) / 2;
	center.y = (Corner1.y + Corner2.y) / 2;
	return center;
}

void CRectangle::setcenter(Point c)
{
	Point currentCenter = getcenter();
	Point offset;
	offset.x = c.x - currentCenter.x;
	offset.y = c.y - currentCenter.y;

	Corner1.x += offset.x;
	Corner1.y += offset.y;

	Corner2.x += offset.x;
	Corner2.y += offset.y;

	Center = c;
}

Point CRectangle::getcorner1() const
{
	return Point();
}

Point CRectangle::getcorner2() const
{
	return Point();
}

Point CRectangle::getcorner3() const
{
	return Point();
}
void CRectangle::Load(ifstream& Infile)
{
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> DrawColor >> FillColor;
	FigGfxInfo.DrawClr = stringtocolor(DrawColor);
	FigGfxInfo.FillClr = stringtocolor(FillColor);
}