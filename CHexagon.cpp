#include "CHexagon.h"
#include "CTriangle.h"
#include <fstream>
#include  <iostream>

CHexagon::CHexagon()
{
	Type = "Hexagon";
}

CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	Center = P1;
	v[0] = { Center.x + 60, Center.y };
	v[1] = { Center.x + 30, Center.y + 52 };
	v[2] = { Center.x - 30, Center.y + 52 };
	v[3] = { Center.x - 60, Center.y };
	v[4] = { Center.x - 30, Center.y - 52 };
	v[5] = { Center.x + 30, Center.y - 52 };
	setDrawClr(FigureGfxInfo);
	Type = "Hexagon";
}

	void CHexagon::Draw(Output * pOut) const {
		int Xcoord[6], Ycoord[6];
		for (int i = 0; i < 6; i++) {
			Xcoord[i] = v[i].x;
			Ycoord[i] = v[i].y;
		}
		pOut->DrawHexa(Xcoord, Ycoord, FigGfxInfo, Selected);
	}

void CHexagon::rotateCCW() {
	for (int i = 0; i < 6; i++) {
		int x = v[i].x;
		int y = v[i].y;
		v[i].x = Center.x - (y - Center.y); 
		v[i].y = Center.y + (x - Center.x);
	}
	isRotated = !isRotated;
}

void CHexagon::swap(CFigure* fig) {
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

Point CHexagon::getcenter() const
{
	return Center;
}
void CHexagon::setcenter(Point c) {
	Center = c;

	v[0] = { Center.x + 60, Center.y };
	v[1] = { Center.x + 30, Center.y + 52 };
	v[2] = { Center.x - 30, Center.y + 52 };
	v[3] = { Center.x - 60, Center.y };
	v[4] = { Center.x - 30, Center.y - 52 };
	v[5] = { Center.x + 30, Center.y - 52 };

}

Point CHexagon::getcorner1() const
{
	return Point();
}

Point CHexagon::getcorner2() const
{
	return Point();
}

Point CHexagon::getcorner3() const
{
	return Point();
}


	bool CHexagon::isPointInside(Point P) {                 
		Point P1 = { Center.x + 60, Center.y };
		Point P2 = { Center.x + 30, Center.y + 52 };
		Point P3 = { Center.x - 30, Center.y + 52 };
		Point P4 = { Center.x - 60, Center.y };
		Point P5 = { Center.x - 30, Center.y - 52 };
		Point P6 = { Center.x + 30, Center.y - 52 };

		CTriangle a(P1, P2, Center, FigGfxInfo);
		CTriangle b(P2, P3, Center, FigGfxInfo);
		CTriangle c(P3, P4, Center, FigGfxInfo);
		CTriangle d(P4, P5, Center, FigGfxInfo);
		CTriangle e(P5, P6, Center, FigGfxInfo);
		CTriangle f(P6, P1, Center, FigGfxInfo);

		if (a.isPointInside(P) ||
			b.isPointInside(P) ||
			c.isPointInside(P) ||
			d.isPointInside(P) ||
			e.isPointInside(P) ||
			f.isPointInside(P))
			return true;
		return NULL;
	}

void CHexagon::pasteHexa(Point P1, Output* pOut)
{
	Point newcorners[6];

		newcorners[0] = { P1.x + 60, P1.y };
		newcorners[1] = { P1.x + 30, P1.y + 52 };
		newcorners[2] = { P1.x - 30, P1.y + 52 };
		newcorners[3] = { P1.x - 60, P1.y };
		newcorners[4] = { P1.x - 30, P1.y - 52 };
		newcorners[5] = { P1.x + 30, P1.y - 52 };

		int Xcoord[6], Ycoord[6];
		for (int i = 0; i < 6; i++) {
			Xcoord[i] = newcorners[i].x;
			Ycoord[i] = newcorners[i].y;
		}
		pOut->DrawHexa(Xcoord, Ycoord, FigGfxInfo, Selected);
}

void CHexagon::rotatecw()
{
	for (int i = 0; i < 6; i++) {
		int x = v[i].x;
		int y = v[i].y;
		v[i].x = Center.x + (y - Center.y); 
		v[i].y = Center.y - (x - Center.x);
	}
	isRotated = !isRotated;
}

void CHexagon::Save(ofstream& OutFile)
{
	OutFile << Type << " " << ID << " " << Center.x << " " << Center.y << " " << DrawColor << " " << FillColor << endl;
}
void CHexagon::Load(ifstream& Infile)
{
	Infile >> ID >> Center.x >> Center.y >> DrawColor >> FillColor;
	FigGfxInfo.DrawClr = stringtocolor(DrawColor);
	FigGfxInfo.FillClr = stringtocolor(FillColor);
}

