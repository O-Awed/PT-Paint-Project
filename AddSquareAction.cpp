#include "AddSquareAction.h"
#include "CSquare.h"
#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

AddSquareAction::AddSquareAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddSquareAction::ReadActionParameters()
{
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();

		pOut->PrintMessage("New Square: Click on centre");

		pIn->GetPointClicked(P1.x, P1.y);

		RectGfxInfo.isFilled = false;	
		pOut->GetUserColor(pIn, RectGfxInfo.FillClr,RectGfxInfo.DrawClr);
		if (RectGfxInfo.FillClr == NULL)// el 7al el wa7eed el la2eto 3alshan asala7 fill color
		{
			RectGfxInfo.isFilled = false;
		}
		else
		{
			RectGfxInfo.isFilled = true;
		}
		pOut->ClearStatusBar();
}

void AddSquareAction::Execute()
{
	ReadActionParameters();
	pManager->UnSelectA();
	CSquare* S = new CSquare(P1, RectGfxInfo);
	pManager->AddFigure(S);
}

void AddSquareAction::Undo() {
	pManager->UnSelectA();
	pManager->setselected(pManager->GetFigure(P1));
	pManager->deleteFig(pManager->getselected());
}

void AddSquareAction::Redo() {
	CSquare* S = new CSquare(P1, RectGfxInfo);
	pManager->AddFigure(S);
}

AddSquareAction::~AddSquareAction(){}