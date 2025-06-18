#include "SelectAction.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "ApplicationManager.h"
#include <iostream>
using namespace std;

SelectAction::SelectAction(ApplicationManager* pApp):Action(pApp)
{}

void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->getFigCount() == 0)
		pOut->PrintMessage("Draw a figure first");
	else
		pOut->PrintMessage("Select a figure");

	//Read Point clicked
	pIn->GetPointClicked(Pclicked.x, Pclicked.y);

	pOut->ClearStatusBar();

}
void SelectAction::Execute()
{
    //This action needs to read some parameters first
    ReadActionParameters();
    Output* pOut = pManager->GetOutput();
    CFigure* Figp = pManager->GetFigure(Pclicked);

    if (pManager->getFigCount() != 0) {
        if (Figp != NULL) {
            if (Figp->IsSelected()) {
                Figp->SetSelected(false);
                pOut->PrintMessage("Ok ,figure is unselected");
            }
            else
            {
                Figp->SetSelected(true);
                pManager->setselected(Figp);
                string figureType = Figp->gettype();
                pOut->PrintMessage("Nice! u selected a figure: "+figureType);
            }
        }
        else {
            pManager->UnSelectA();
            pOut->PrintMessage("No figure selected, all figures are unselected");
        }
    }
}

void SelectAction::Undo() {
    // Me4 mota2aked law sha8ala
    /*if (pManager->getselected() != NULL) {
        pManager->getselected()->SetSelected(false);
    }*/
    return;
}

void SelectAction::Redo() {
	// Me4 mota2aked law sha8ala
	/*if (pManager->getselected() != NULL) {
		pManager->getselected()->SetSelected(true);
	}*/
	return;
}


