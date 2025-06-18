#include "AddCircleAction.h"
#include "ApplicationManager.h"
#include "Actions\Action.h"
#include "GUI\input.h"
#include "GUI\Output.h"
AddCircleAction::AddCircleAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddCircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at Center");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at radius");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	CircGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	pOut->GetUserColor(pIn, CircGfxInfo.FillClr,CircGfxInfo.DrawClr);
	if (CircGfxInfo.FillClr == NULL)// el 7al el wa7eed el la2eto 3alshan asala7 fill color  
	{
		CircGfxInfo.isFilled = false;
	}
	else
	{
		CircGfxInfo.isFilled = true;
	}
	pOut->ClearStatusBar();
	
}

//Execute the action
void AddCircleAction::Execute()
{
	pManager->UnSelectA();
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CCircle* C= new CCircle(P1, P2, CircGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(C);
}

// Undo the action
void AddCircleAction::Undo() {
	pManager->UnSelectA();
	pManager->setselected(pManager->GetFigure(P1));
	pManager->deleteFig(pManager->getselected());
}

void AddCircleAction::Redo() {
	CCircle* C = new CCircle(P1, P2, CircGfxInfo);
	pManager->AddFigure(C);
}

AddCircleAction::~AddCircleAction(){}
