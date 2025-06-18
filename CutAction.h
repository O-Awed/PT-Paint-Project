#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "Figures/CFigure.h"

class CutAction : public Action
{
	CFigure* cfig;
	color c;

public:
	CutAction(ApplicationManager* AM);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	~CutAction();
};