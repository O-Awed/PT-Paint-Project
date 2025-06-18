#include "CTriangle.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
using namespace std;
#include <iostream>
#include <fstream>
#include "CCircle.h"
CTriangle::CTriangle()
{
	Type = "triangle";
}
CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;

	setDrawClr(FigureGfxInfo);
	Type = "triangle";
}

void CTriangle::Draw(Output* pOut) const
{
	pOut->DrawTri(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}

bool CTriangle::isPointInside(Point P)
{
	//El tare2a de la2etha esmaha el determinant method bas ana me4 fahemha awy -Awad 
	float area = 0.5 * (-Corner2.y * Corner3.x + Corner1.y * (-Corner2.x + Corner3.x) + Corner1.x * (Corner2.y - Corner3.y) + Corner2.x * Corner3.y);
	float s = 1 / (2 * area) * (Corner1.y * Corner3.x - Corner1.x * Corner3.y + (Corner3.y - Corner1.y) * P.x + (Corner1.x - Corner3.x) * P.y);
	float t = 1 / (2 * area) * (Corner1.x * Corner2.y - Corner1.y * Corner2.x + (Corner1.y - Corner2.y) * P.x + (Corner2.x - Corner1.x) * P.y);
	if (s > 0 && t > 0 && 1 - s - t > 0)
	{
	  return true;
	}
	return NULL;
}

Point* CTriangle::pasteTri(Point P1, Output* pOut)
{                                                       // di kda hteshta8al 3eib 3aleko -kyro
	Point* newcorners = new Point[3];
	Point oldcentre;
	oldcentre.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	oldcentre.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
	Point diff;
	diff.x = P1.x - oldcentre.x;
	diff.y = P1.y - oldcentre.y;
	newcorners[0].x = Corner1.x + diff.x;
	newcorners[0].y = Corner1.y + diff.y;
	newcorners[1].x = Corner2.x + diff.x;
	newcorners[1].y = Corner2.y + diff.y;
	newcorners[2].x = Corner3.x + diff.x;
	newcorners[2].y = Corner3.y + diff.y;
	pOut->DrawTri(newcorners[0], newcorners[1], newcorners[2], FigGfxInfo);
	return newcorners;

	/*   Da beta3 kyro
	Point P12[2];
	Point Diff;

	Diff.x = P1.x - Corner1.x;
	Diff.y = P1.y - Corner1.y;

	// Apply the offset to Corner2 and Corner3
	P12[0].x = Corner2.x + Diff.x;
	P12[0].y = Corner2.y + Diff.y;

	P12[1].x = Corner3.x + Diff.x;
	P12[1].y = Corner3.y + Diff.y;

	pOut->DrawTri(P1, P12[0], P12[1], FigGfxInfo);
	
	return P12;
	*/
}
void CTriangle::rotateCCW()
{
	Center.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	Center.y = (Corner1.y + Corner2.y + Corner3.y) / 3;

	int newX1 = Center.x + (Corner1.y - Center.y);
	int newY1 = Center.y - (Corner1.x - Center.x);

	int newX2 = Center.x + (Corner2.y - Center.y);
	int newY2 = Center.y - (Corner2.x - Center.x);

	int newX3 = Center.x + (Corner3.y - Center.y);
	int newY3 = Center.y - (Corner3.x - Center.x);


	Corner1.x = newX1;
	Corner1.y = newY1;

	Corner2.x = newX2;
	Corner2.y = newY2;

	Corner3.x = newX3;
	Corner3.y = newY3;


}

void CTriangle::rotatecw()
{
	Center.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	Center.y = (Corner1.y + Corner2.y + Corner3.y) / 3;

	int newX1 = Center.x - (Corner1.y - Center.y);
	int newY1 = Center.y + (Corner1.x - Center.x);

	int newX2 = Center.x - (Corner2.y - Center.y);
	int newY2 = Center.y + (Corner2.x - Center.x);

	int newX3 = Center.x - (Corner3.y - Center.y);
	int newY3 = Center.y + (Corner3.x - Center.x);


	Corner1.x = newX1;
	Corner1.y = newY1;

	Corner2.x = newX2;
	Corner2.y = newY2;

	Corner3.x = newX3;
	Corner3.y = newY3;


}
void CTriangle::Save(ofstream& OutFile)
{
	{
		OutFile << Type << " " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << Corner3.x << " " << Corner3.y << " " << DrawColor << " " << FillColor << endl;
	}
}

Point CTriangle::getcenter() const
{
	Point center;
	center.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	center.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
	return center;
}


void CTriangle::setcenter(Point c)
{
	Point currentCenter = getcenter();
	Point offset;
	offset.x = c.x - currentCenter.x;
	offset.y = c.y - currentCenter.y;

	Corner1.x += offset.x;
	Corner1.y += offset.y;

	Corner2.x += offset.x;
	Corner2.y += offset.y;

	Corner3.x += offset.x;
	Corner3.y += offset.y;
}

void CTriangle::swap(CFigure* fig)
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

void CTriangle::setcorner(Point c)
{
	Point Center;
	Center.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	Center.y = (Corner1.y + Corner2.y + Corner3.y) / 3;

	Point newc;
	newc.x = c.x - Center.x;
	newc.y = c.y - Center.y;

	Corner1.x += newc.x;
	Corner1.y += newc.y;

	Corner2.x += newc.x;
	Corner2.y += newc.y;

	Corner3.x += newc.x;
	Corner3.y += newc.y;
}

Point CTriangle::getcorner1() const
{
	return Corner1;
}

Point CTriangle::getcorner2() const
{
	return Corner2;
}

Point CTriangle::getcorner3() const
{
	return Corner3;
}
void CTriangle::Load(ifstream& Infile)
{
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> DrawColor >> FillColor;
	FigGfxInfo.DrawClr = stringtocolor(DrawColor);
	FigGfxInfo.FillClr = stringtocolor(FillColor);
}

 