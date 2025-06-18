#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"

class UndoAction : public Action
{
	
public:
	UndoAction(ApplicationManager* AM);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	~UndoAction();
};