#pragma once
#include "Actions/Action.h"

class SwapAction : public Action {
private:
	int indices[2]; 
public:
    SwapAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void Undo();
	virtual void Redo();
};