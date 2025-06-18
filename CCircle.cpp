#include "CCircle.h"
#include <fstream>
#include "CTriangle.h"
#include <iostream>

CCircle::CCircle()
{
	Type = "circle";
}
CCircle::CCircle(Point P1,Point p2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Centre = P1;
	Radius = p2; 
	Type = "circle";
	setDrawClr(FigureGfxInfo);
}

void CCircle::Draw(Output* pOut) const
{
	pOut->DrawCirc(Centre, Radius, FigGfxInfo, Selected);
}

bool CCircle::isPointInside(Point P)
{
	int dsq = (P.x - Centre.x) * (P.x - Centre.x) + (P.y - Centre.y) * (P.y - Centre.y);
	int radius = (Radius.x - Centre.x) * (Radius.x - Centre.x) + (Radius.y - Centre.y) * (Radius.y - Centre.y);
	if (dsq <= radius)
		return true;
	else
		return false;
}

Point CCircle::pasteCrc(Point P1, Output* pOut)
{
	Point P2;
	P2.x = P1.x + Radius.x-Centre.x;
	P2.y = P1.y + Radius.y-Centre.y;
	pOut->DrawCirc(P1, P2, FigGfxInfo);
	return P2;
}

void CCircle::rotateCCW()
{
	
}

void CCircle::rotatecw()
{
}

void CCircle::Save(ofstream& OutFile)
{
	OutFile << Type << " " << ID << " " << Centre.x << " " << Centre.y << " " << Radius.x << " " << Radius.y << " " << " " << DrawColor << " " << FillColor << endl;
}

void CCircle::swap(CFigure* fig)
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

Point CCircle::getcenter() const
{
	return Centre;
}

void CCircle::setcenter(Point c)
{
	Point offset;
	offset.x = c.x - Centre.x;
	offset.y = c.y - Centre.y;

	Centre.x = c.x;
	Centre.y = c.y;

	Radius.x += offset.x;
	Radius.y += offset.y;
}

Point CCircle::getcorner1() const
{
	return Point();
}

Point CCircle::getcorner2() const
{
	return Point();
}

Point CCircle::getcorner3() const
{
	return Point();
}
void CCircle::Load(ifstream& Infile)
{
	Infile >> ID >> Centre.x >> Centre.y >> Radius.x >> Radius.y >> DrawColor >> FillColor;

	FigGfxInfo.DrawClr = stringtocolor(DrawColor);

	FigGfxInfo.FillClr = stringtocolor(FillColor);

}