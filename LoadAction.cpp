#include "LoadAction.h"
#include "GUI/Output.h"
#include"CTriangle.h"
#include"CSquare.h"
#include"Figures\CRectangle.h"
#include"CCircle.h"
#include"CHexagon.h"
#include<fstream>
#include "ApplicationManager.h"
#include "GUI/Output.h"
#include "GUI\Input.h"
#include "Actions/Action.h"
#include"Figures/CFigure.h"
#include "SaveAction.h"
LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp)
{
}

void LoadAction::ReadActionParameters()
{

}

void LoadAction::Execute()
{
	Input* pIn = pManager->GetInput();
	Output* pout = pManager->GetOutput();
	string type;
	pout->PrintMessage("Enter File to Load from Name:");

	name = pIn->GetSrting(pout);


	ifstream fin;

	fin.open(name + ".txt", ios::in);
	if (fin.fail())
	{
		pout->PrintMessage(name + ".txt" + "doesn't exist");
	}
	else {
		pManager->clear();
		int figcnt;
		fin >> figcnt;
		for (int i = 0; i < figcnt; i++)
		{

			CFigure* F;
			fin >> type;
			if (type == "Square") F = new CSquare;
			else if (type == "Hexagon") F = new CHexagon;
			else if (type == "circle") F = new CCircle;
			else if (type == "Rectangle") F = new CRectangle;
			else if (type == "triangle") F = new CTriangle;
			else break;

			F->Load(fin);
			pManager->AddFigure(F);
		}
		pManager->UpdateInterface();
		pManager->UnSelectA();
		fin.close();
		pout->PrintMessage("File loaded");
	}
}

void LoadAction::Undo(){}
void LoadAction::Redo(){}
LoadAction::~LoadAction(){}