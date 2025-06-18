#include "Copy.h"
#include"Figures/CFigure.h"
#include "ApplicationManager.h"
#include "SelectAction.h"
#include "Actions/Action.h"
#include "Figures/CFigure.h"
#include <iostream>
using namespace std;

Copy::Copy(ApplicationManager* AM) :Action(AM)
{
}
void Copy::ReadActionParameters()   //law neset 7ad ye4el el pOut 1 w 2 w 3 dool -awad
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

}

void Copy::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	Clipboard = pManager->getselected();
	if ((Clipboard != NULL))
	{ 
		pManager->setclipboard(Clipboard);
		pOut->PrintMessage("Figure has been copied");
	}
	else
		pOut->PrintMessage("Copy a Figure first");
	return;
}

void  Copy::Undo() {
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Undo Copy"); 
	pManager->setclipboard(NULL);
}

void  Copy::Redo() {
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Redo Copy");
	pManager->setclipboard(Clipboard);
}

Copy::~Copy(){}
