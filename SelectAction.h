#pragma once
#include "Actions\Action.h"
#include "Figures/CFigure.h"

class SelectAction:public Action
{
	Point Pclicked;
	CFigure* FClicked;
	
public:
	SelectAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual void Undo();

	virtual void Redo();

	~SelectAction();
};

