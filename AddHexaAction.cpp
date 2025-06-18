#include "AddHexaAction.h"
#include "CHexagon.h"
#include "ApplicationManager.h"
#include "Actions\Action.h"
#include "GUI\input.h"
#include "GUI\Output.h"

AddHexaAction::AddHexaAction(ApplicationManager* pApp) : Action(pApp)
{
}

void AddHexaAction::ReadActionParameters()
{
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at the center");

	pIn->GetPointClicked(P1.x, P1.y);

	

	HexaGfxInfo.isFilled = false;	
	pOut->GetUserColor(pIn, HexaGfxInfo.FillClr,HexaGfxInfo.DrawClr);
	if (HexaGfxInfo.FillClr == NULL)// el 7al el wa7eed el la2eto 3alshan asala7 fill color
	{
		HexaGfxInfo.isFilled = false;
	}
	else
	{
		HexaGfxInfo.isFilled = true;
	}
	pOut->ClearStatusBar();
}

//Execute the action
void AddHexaAction::Execute()
{
	pManager->UnSelectA();

	ReadActionParameters();


	CHexagon* H = new CHexagon(P1, HexaGfxInfo);

	pManager->AddFigure(H);
}

void AddHexaAction::Undo() {
	pManager->UnSelectA();
	pManager->setselected(pManager->GetFigure(P1));
	pManager->deleteFig(pManager->getselected());
}

void AddHexaAction::Redo() {
	CHexagon* H = new CHexagon(P1, HexaGfxInfo);
	pManager->AddFigure(H);
} 

AddHexaAction::~AddHexaAction(){}