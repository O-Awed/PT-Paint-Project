#include "CutAction.h"
CutAction::CutAction(ApplicationManager* AM):Action(AM)
{
}
void CutAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Selected Figure is Cut");
}

void CutAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if ((pManager->getselected() != NULL && pManager->selectedcount() != 0)) {
		pManager->setIsCut(true);
		cfig = pManager->getselected();
		c = cfig->getGfxInfo().DrawClr;

		cfig->ChngFillClr(GRAY);                            //rayes e3mel 7etet el colors

		pManager->setclipboard(cfig);
	}
	else
		pOut->PrintMessage("Select a Figure First");
}

void CutAction::Undo() {
	cfig->ChngFillClr(c);
	pManager->setIsCut(false);
	pManager->setclipboard(NULL);
}

void CutAction::Redo() {
	cfig->ChngFillClr(GRAY);
	pManager->setIsCut(true);
	pManager->setclipboard(cfig);
}

CutAction::~CutAction(){}
