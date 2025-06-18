#pragma once
#include"Actions\Action.h"

class ClearAll :public Action {

public:
	ClearAll(ApplicationManager* AM);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	~ClearAll();
};
