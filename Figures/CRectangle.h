#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Center;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	CRectangle();
	virtual void Draw(Output* pOut) const;
	virtual bool isPointInside(Point P);
	Point PasteRec(Point, Output*);
	Point GetCorner1();
	Point GetCorner2();
	virtual void rotateCCW();
	virtual void rotatecw();
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	void swap(CFigure* fig);
	Point getcenter()const;
	void setcenter(Point c);
	virtual Point getcorner1()const;
	virtual Point getcorner2() const;
	virtual Point getcorner3() const;
};

#endif