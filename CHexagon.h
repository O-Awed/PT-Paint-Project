#pragma once 
#include "Figures\CFigure.h"

class CHexagon : public CFigure
{
private:
	Point v[6];
	Point Center;
	bool isRotated;
public:
	CHexagon();
	CHexagon(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool isPointInside(Point P);
	void pasteHexa(Point P1, Output* pOut);
	virtual void rotatecw();
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void rotateCCW();
	void swap(CFigure* fig);
	Point getcenter()const;
	void setcenter(Point c);
	virtual Point getcorner1()const;
	virtual Point getcorner2() const;
	virtual Point getcorner3() const;

};
