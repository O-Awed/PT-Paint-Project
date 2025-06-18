#pragma once
#include "Actions\Action.h"

class AddSquareAction:public Action
{
private:
	Point P1; //square centre
	GfxInfo RectGfxInfo;
public:
	AddSquareAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

	//Undo action	
	virtual void Undo();

	//Redo action
	virtual void Redo();

	//Destructor
	~AddSquareAction();
};

