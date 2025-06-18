#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"

class RedoAction : public Action
{

public:
	RedoAction(ApplicationManager* AM);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	~RedoAction();
};
