#include "CSquare.h"
#include <fstream>
#include <iostream>>

CSquare::CSquare()
{
	Type = "Square";
}
CSquare::CSquare(Point p, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = p;
	setDrawClr(FigureGfxInfo);
	Type = "Square";

}

void CSquare::Draw(Output* pOut) const
{
	Point Center=getcenter();
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}
bool CSquare::isPointInside(Point P)
{
	if (P.x >= Center.x - 50 && P.x <= Center.x + 50 && P.y >= Center.y - 50  && P.y <= Center.y + 50 )
		return true;
	return NULL;
}

void CSquare::pasteSqr(Point P1, Output* pOut)
{
	pOut->DrawSquare(P1, FigGfxInfo);
	return;
}

void CSquare::rotateCCW()
{
}

void CSquare::rotatecw()
{
}
void CSquare::Save(ofstream& OutFile)
{
	OutFile << Type << " " << ID << " " << Center.x << " " << Center.y << " " << DrawColor << " " << FillColor << endl;
}

void CSquare::swap(CFigure* fig) {
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

Point CSquare::getcenter()const
{
	return Center;
}

void CSquare::setcenter(Point c)
{
	Center = c;
}

Point CSquare::getcorner1() const
{
    return Point();
}

Point CSquare::getcorner2() const
{
    return Point();
}

Point CSquare::getcorner3() const
{
    return Point();
}
void CSquare::Load(ifstream& Infile)
{
	Infile >> ID >> Center.x >> Center.y >> DrawColor >> FillColor;
	FigGfxInfo.DrawClr = stringtocolor(DrawColor);
	FigGfxInfo.FillClr = stringtocolor(FillColor);
}