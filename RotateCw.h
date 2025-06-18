#pragma once
#include "Actions\Action.h"
#include "Figures/CFigure.h"

// Rotate Clockwise Action class
class RotateCw : public Action
{
private:
    CFigure* rFig;
public:
    RotateCw(ApplicationManager* pApp);

    // Reads parameters required for rotation
    virtual void ReadActionParameters();

    // Executes the rotation action
    virtual void Execute();

	// Undo the rotation action
    virtual void Undo();

	// Redo the rotation action
	virtual void Redo();
};
