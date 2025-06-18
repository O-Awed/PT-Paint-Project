#pragma once
#include "Figures/CFigure.h"
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "Copy.h"
#include "CCircle.h"
#include "CSquare.h"
#include "Figures/CRectangle.h"
#include "CHexagon.h"
#include "CTriangle.h"

class Paste : public Action
{
	Point P1;
	CFigure* PastedFigure; // Pointer to the pasted figure
public:
	Paste(ApplicationManager* am);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	~Paste();
};

