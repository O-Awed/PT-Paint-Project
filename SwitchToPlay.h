 #pragma once
#include "Actions/Action.h"


class SwitchToPlay : public Action
{


public:
	SwitchToPlay(ApplicationManager* AM);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
	~SwitchToPlay();

};