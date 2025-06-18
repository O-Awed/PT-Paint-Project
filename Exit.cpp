#include "Exit.h"
#include<fstream>
#include"ApplicationManager.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "Actions/Action.h"

Exit::Exit(ApplicationManager* AM) :Action(AM) {}

void Exit::ReadActionParameters() {}

void Exit::Execute()
{

	Output* pOut = pManager->GetOutput();
	bool s = pOut->getSave();
	if (s) {

		string name;
		ofstream fout;

		Input* pIn = pManager->GetInput();
		Output* pout = pManager->GetOutput();
		pout->PrintMessage("Enter File Name:");

		name = pIn->GetSrting(pout);

		fout.open(name + ".txt", ios::out);
		
		pManager->SaveAll(fout);

		fout.close();

		pout->PrintMessage("File Saved Successfully");
	}
}

void Exit::Undo() {}
void Exit::Redo() {}
Exit::~Exit() {}