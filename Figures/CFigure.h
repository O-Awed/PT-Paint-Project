#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	string Type;
	string DrawColor;
	string FillColor;
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure();
	GfxInfo getGfxInfo();
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	void setID(int id);
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	int getID();
	string gettype();
	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual void rotateCCW() = 0;
	virtual void rotatecw() = 0; 
    void setGfxInfo(const GfxInfo& gfxInfo);
	void setDrawClr(GfxInfo FigureGfxInfo);
	virtual void Save(ofstream& OutFile) = 0;
	virtual bool isPointInside(Point P) = 0;	
	virtual void swap(CFigure* fig) = 0;
	virtual Point getcenter()const = 0;
	virtual void setcenter(Point c)= 0;
	virtual Point getcorner1()const = 0;
	virtual Point getcorner2() const = 0;
	virtual Point getcorner3() const = 0;
	color stringtocolor(string);


	virtual void Load(ifstream& Infile) = 0;// elhakhod beha elstrings mn eltxt files lel load function - seif 
	//checks whether a point is inside the figure or not	
	// This function would get called into CCircle, CRectangle, CTriangle, etc. class directly
	// Kyro kan katabha fe kol class bas nesy ye call fe SelectAction.cpp  -Awad

	// Don't delete Rayes w Kyro ta2reban kano bygarabo 7aga -awad
	// Law 7asal 7aga sheel el line da
	
};

#endif