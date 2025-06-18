#pragma once
#include "Figures/CFigure.h"
#include "SelectAction.h"

class CTriangle:public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
	Point Center;
public:
	CTriangle();
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool isPointInside(Point P); 
	Point* pasteTri(Point P1, Output* pOut);
	virtual void rotateCCW();
	virtual void rotatecw();
	virtual void Save(ofstream& OutFile);
	Point getcenter() const;
	void setcenter(Point c);
	void swap(CFigure* fig);
	void setcorner(Point c);
	virtual Point getcorner1()const;
	virtual Point getcorner2() const;
	virtual Point getcorner3() const;	
	virtual void Load(ifstream& Infile);
};
