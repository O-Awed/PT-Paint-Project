#include "ClearAll.h"
#include"ApplicationManager.h"

ClearAll::ClearAll(ApplicationManager* AM) :Action(AM) {}

void ClearAll::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Clear All");
}

void ClearAll::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pManager->clear();
	pManager->setclipboard(NULL);
}

void ClearAll::Undo() {
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("You can't undo clear all");
}


void ClearAll::Redo() {
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("You can't redo clear all");
}

ClearAll::~ClearAll() {}