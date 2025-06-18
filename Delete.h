#pragma once

#include "Actions\Action.h"
#include "Figures\CFigure.h"
#include "ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"

class Delete : public Action {

	CFigure* dFig;  // Bet4eel el figure el hayet3emelo delete

public:

	Delete(ApplicationManager*, CFigure*);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	~Delete();

};
