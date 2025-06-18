#pragma once
#include"Figures/CFigure.h"
#include<fstream>
#include"ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "Actions/Action.h"
#include "SaveAction.h"

SaveAction::SaveAction(ApplicationManager* pApp) : Action(pApp)
{
}

void SaveAction::ReadActionParameters()
{
}

void SaveAction::Execute()
{
	Input* pIn = pManager->GetInput();
	Output* pout = pManager->GetOutput();
	pout->PrintMessage("Enter File Name:");

	name = pIn->GetSrting(pout);

	fout.open(name + ".txt", ios::out);



	pManager->SaveAll(fout);

	fout.close();

	pout->PrintMessage("File Saved Successfully");
}

void SaveAction::Undo()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("You Can't Undo Save");
}

void SaveAction::Redo()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("You Can't Redo Save");
}
