#include "RotateCw.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "figures/CFigure.h"

RotateCw::RotateCw(ApplicationManager* pApp) : Action(pApp)
{
	rFig = nullptr; // Initialize the figure pointer
}

void RotateCw::ReadActionParameters()
{
}

void RotateCw::Execute()
{
    Output* pOut = pManager->GetOutput();
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


    rFig->rotatecw();


    pManager->UpdateInterface();
    pOut->PrintMessage("Figure rotated 90 degrees clockwise.");
}
void RotateCw::Undo(){
	rFig->rotateCCW();
}

void RotateCw::Redo(){
	rFig->rotatecw();
}