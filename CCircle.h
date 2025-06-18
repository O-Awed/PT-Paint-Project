#pragma once
#include "Figures\CFigure.h"

class CCircle: public CFigure
{
private:
	Point Centre;
	Point Radius;
public:
	CCircle();
	CCircle(Point,Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool isPointInside(Point);
	Point pasteCrc(Point P1, Output* pOut);
	virtual void rotateCCW();
	virtual void rotatecw();
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	void swap(CFigure* fig);
	Point getcenter()const;
	void setcenter(Point c);
	virtual Point getcorner1()const ;
	virtual Point getcorner2() const ;
	virtual Point getcorner3() const ;
	
};

