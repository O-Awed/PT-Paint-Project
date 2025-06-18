#pragma once
#include"Actions\Action.h"
#include"ApplicationManager.h"
class Copy : public Action
{
	CFigure* Clipboard;

public:
	Copy(ApplicationManager* AM);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	~Copy();
};
