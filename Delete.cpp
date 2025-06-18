#include "Delete.h"

Delete::Delete(ApplicationManager* pApp, CFigure* fig) :Action(pApp), dFig(fig)
{
}

void  Delete::ReadActionParameters()
{
}

void Delete::Execute() {
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int Count = pManager->getFigCount();
	if (pManager->selectedcount() != 0)
	{
		CFigure** list = pManager->GetFigList();
		for (int i = 0; i < Count; i++)
		{
			if (list[i]->IsSelected())
			{
				pManager->deleteFig(list[i]);
			}
		}
		pOut->PrintMessage("Figure(s) has been deleted");
	}
	else
		pOut->PrintMessage("Select a figure first");
}

void Delete::Undo() {
	pManager->AddFigure(dFig); 
}
void Delete::Redo() {
	pManager->deleteFig(dFig);
}

Delete::~Delete() {}