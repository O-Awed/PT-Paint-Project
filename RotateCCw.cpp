#include "RotateCCw.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "figures/CFigure.h"

RotateCCw::RotateCCw(ApplicationManager* pApp) : Action(pApp)
{
	rFig = nullptr;
}

void RotateCCw::ReadActionParameters()
{
}

void RotateCCw::Execute()
{
    Output* pOut = pManager->GetOutput();

    // Get the selected figure
    rFig = pManager->getselected();
    if (pManager->selectedcount() > 1)
    {
        pOut->PrintMessage("Multiple figures selected. Please select only one figure to rotate.");
        return;
    }
    if (rFig == nullptr || !rFig->IsSelected())
    {
        pOut->PrintMessage("No figure selected to rotate.");
        return;
    }


    rFig->rotateCCW(); // deh betlef CCw bas kol lama bagy a8yar esmaha fe kol el classes el byegy 99 alf error fa seboha keda 


    pManager->UpdateInterface();
    pOut->PrintMessage("Figure rotated 90 degrees Counter clockwise.");
}

void RotateCCw::Undo()
{
	rFig->rotatecw(); // Undo the rotation by rotating back clockwise
}

void RotateCCw::Redo()
{
	rFig->rotateCCW(); // Redo the rotation by rotating counter-clockwise again
}

RotateCCw::~RotateCCw() {}

