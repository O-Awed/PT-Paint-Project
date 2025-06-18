#include "AddTriangleAction.h"
#include "CTriangle.h"
#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

AddTriangleAction::AddTriangleAction(ApplicationManager* pApp):Action(pApp)
{}

void AddTriangleAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");

	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second corner");

	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at third corner");

	pIn->GetPointClicked(P3.x, P3.y);

	TriGfxInfo.isFilled = false;
	pOut->GetUserColor(pIn, TriGfxInfo.FillClr, TriGfxInfo.DrawClr);
	if (TriGfxInfo.FillClr == NULL)// el 7al el wa7eed el la2eto 3alshan asala7 fill color
	{
		TriGfxInfo.isFilled = false;
	}
	else
	{
		TriGfxInfo.isFilled = true;
	}
	pOut->ClearStatusBar();
	

}

void AddTriangleAction::Execute()
{
	pManager->UnSelectA();
	ReadActionParameters();
	CTriangle* T = new CTriangle(P1, P2, P3, TriGfxInfo);
	pManager->AddFigure(T);
}

void AddTriangleAction::Undo() {
	pManager->UnSelectA();
	pManager->setselected(pManager->GetFigure(P1));
	pManager->deleteFig(pManager->getselected());
}

void AddTriangleAction::Redo() {
	CTriangle* T = new CTriangle(P1, P2, P3, TriGfxInfo);
	pManager->AddFigure(T);
}

AddTriangleAction::~AddTriangleAction(){}
