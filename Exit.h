#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"

class Exit : public Action
{

public:
	Exit(ApplicationManager* AM);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	~Exit();
};

