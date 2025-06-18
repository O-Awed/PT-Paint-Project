#include "Paste.h"

Paste::Paste(ApplicationManager* am) :Action(am)
{}

void Paste::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Choose a point to paste in");
	pIn->GetPointClicked(P1.x, P1.y);
}

void Paste::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ReadActionParameters();

	CRectangle* R = dynamic_cast<CRectangle*> (pManager->getClipboard());
	CSquare* S = dynamic_cast<CSquare*>(pManager->getClipboard());
	CTriangle* T = dynamic_cast<CTriangle*>(pManager->getClipboard());
	CCircle* C = dynamic_cast<CCircle*>(pManager->getClipboard());
	CHexagon* H = dynamic_cast<CHexagon*>(pManager->getClipboard());


	if (R != NULL)
	{
		if (pManager->getIsCut())
		{
			Point P2 = R->PasteRec(P1, pOut);
			GfxInfo RGfx = pManager->getClipboard()->getGfxInfo();
			PastedFigure = new CRectangle(P1, P2, RGfx);
			pManager->AddFigure(PastedFigure);
			pManager->deleteFig(pManager->getselected());
		}
		else
		{
			Point P2 = R->PasteRec(P1, pOut);
			GfxInfo RGfx = pManager->getClipboard()->getGfxInfo();
			PastedFigure = new CRectangle(P1, P2, RGfx);
			pManager->AddFigure(PastedFigure);
		}
	}
	if (S != NULL)
	{
		if (pManager->getIsCut())
		{
			S->pasteSqr(P1, pOut);
			GfxInfo SGfx = pManager->getClipboard()->getGfxInfo();
			PastedFigure = new CSquare(P1, SGfx);
			pManager->AddFigure(PastedFigure);
			pManager->deleteFig(pManager->getselected());
		}
		else {
			S->pasteSqr(P1, pOut);
			GfxInfo SGfx = pManager->getClipboard()->getGfxInfo();
			PastedFigure = new CSquare(P1, SGfx);
			pManager->AddFigure(PastedFigure);
		}
	}
	if (T != NULL)
	{
		if (pManager->getIsCut())
		{
			Point* P = T->pasteTri(P1, pOut);                       //dont forget addfigure - kyro
			GfxInfo TGfx = pManager->getClipboard()->getGfxInfo();
			PastedFigure = new CTriangle(P[0], P[1], P[2], TGfx);
			pManager->AddFigure(PastedFigure);
			pManager->deleteFig(pManager->getselected());
			delete[] P;
		}
		else
		{
			Point* P = T->pasteTri(P1, pOut);                       //dont forget addfigure - kyro
			GfxInfo TGfx = pManager->getClipboard()->getGfxInfo();
			PastedFigure = new CTriangle(P[0], P[1], P[2], TGfx);
			pManager->AddFigure(PastedFigure);
			delete[] P;
		}
	}
	if (C != NULL)
	{
		if (pManager->getIsCut())
		{
			Point P2 = C->pasteCrc(P1, pOut);
			GfxInfo CGfx = pManager->getClipboard()->getGfxInfo();
			PastedFigure = new CCircle(P1, P2, CGfx);
			pManager->AddFigure(PastedFigure);
			pManager->deleteFig(pManager->getselected());
		}
		else {
			Point P2 = C->pasteCrc(P1, pOut);
			GfxInfo CGfx = pManager->getClipboard()->getGfxInfo();
			PastedFigure = new CCircle(P1, P2, CGfx);
			pManager->AddFigure(PastedFigure);
		}
	}
	if (H != NULL)
	{
		if (pManager->getIsCut())
		{
			H->pasteHexa(P1, pOut);
			GfxInfo SGfx = pManager->getClipboard()->getGfxInfo();
			PastedFigure = new CHexagon(P1, SGfx);
			pManager->AddFigure(PastedFigure);
			pManager->deleteFig(pManager->getselected());
		}
		else
		{
			H->pasteHexa(P1, pOut);
			GfxInfo SGfx = pManager->getClipboard()->getGfxInfo();
			PastedFigure = new CHexagon(P1, SGfx);
			pManager->AddFigure(PastedFigure);
		}
	}
}

void Paste::Undo() {
	// Remove the pasted figure
	if (PastedFigure) {
		pManager->deleteFig(PastedFigure); 
		PastedFigure = nullptr;           
		pManager->UpdateInterface();      
	}
}

void Paste::Redo() {
	Execute(); // Re-execute the paste action
}

Paste::~Paste() {}
