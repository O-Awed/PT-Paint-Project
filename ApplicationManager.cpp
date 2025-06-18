#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "AddSquareAction.h"
#include "AddTriangleAction.h"
#include "AddCircleAction.h"
#include "AddHexaAction.h"
#include "CCircle.h"
#include "SelectAction.h"
#include "Copy.h"
#include "Paste.h"
#include "RotateCCw.h"
#include "Delete.h"
#include "ClearAll.h"
#include "RotateCw.h"
#include <ostream>
#include "SwapAction.h"
#include "SaveAction.h"
#include "CutAction.h"
#include "UndoAction.h"
#include "RedoAction.h"
#include "Exit.h"
#include <iostream>
#include "LoadAction.h"
#include "Switchtoplay.h"
// kol action class e3mel include lel header file 

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;
	ActCount = 0;             // Initialize the action count
	ActIndex = -1;            // Initialize the action index
	Clipboard = NULL;
	SelectedFig = NULL;

	//Create an array of figure pointers and set them to NULL	

	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;

	for (int i = 0; i < 500; i++)
		ActList[i] = NULL; 

}

//==================================================================================//
//						Selection Management Functions								//
//==================================================================================//

void ApplicationManager::setselected(CFigure* sf) {
	SelectedFig = sf;
}

CFigure* ApplicationManager::getselected() {
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsSelected())
			SelectedFig = FigList[i];
		break;
	}
	return SelectedFig;
}

int ApplicationManager::selectedcount() {   //3amalt selectedcount 3a4an asta3melha fel copy
	int c = 0;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsSelected())
			c++;
	}
	return c;
}
bool ApplicationManager::getSelectedIndices(int indices[2]) {
	int count = 0;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsSelected()) {
			indices[count++] = i;
			if (count == 2) break;
		}
	}
	return count == 2;                             // Ensure exactly two figures are selected
}
int ApplicationManager::getFigCount()
{
	return FigCount;
}

void ApplicationManager::UnSelectA() {             //Benesta3melha fel add fig
	for (int i = 0; i < FigCount; i++) {
		FigList[i]->SetSelected(false);
	}
}

void ApplicationManager::selectedToSwap(CFigure* SL[]) {
	int sc = 0; 
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsSelected()) {
			SL[sc] = FigList[i];
			sc++;
		}
	}
}

//==================================================================================//
//						Clipboard Management Functions		-awad					//
//==================================================================================//

void ApplicationManager::setclipboard(CFigure* sf) //the clipboard to store on it the selected figure
{
	Clipboard = sf;
}
CFigure* ApplicationManager::getClipboard()
{
	return Clipboard;
}
void ApplicationManager::setIsCut(bool ic)
{
	iscut = ic;
}

bool ApplicationManager::getIsCut()
{
	return iscut;
}

void ApplicationManager::setGfxInfo(GfxInfo fig)
{
	cutfig = fig;
}

//==================================================================================//
//						Delete Management Functions		-awad		     			//
//==================================================================================//

void ApplicationManager::deleteFig(CFigure* Dfigure) { // bt3mel select lel figure el 3ayz a3mel 3aleha delete
	for (int i = 0; i < FigCount; i++)
	{
		if (Dfigure == FigList[i])
		{
			delete FigList[i];
			FigList[i] = NULL;
			FigCount--;
			for (int j = i; j < FigCount; j++)        // Bazabat el list 3a4an ma yeb2ash fe gaps // 7elwa menak di ya awad- kyro
				FigList[j] = FigList[j + 1];
		}
	}
}


void ApplicationManager::clear() {                    //lel clear all 
	for (int i = 0; i < FigCount; i++) {
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT: {
		pAct = new AddRectAction(this);
		break;
	}

	case DRAW_SQR: {
		pAct = new AddSquareAction(this);
		break;
	}

	case DRAW_TRIG: {
		pAct = new AddTriangleAction(this);
		break;
	}

	case DRAW_CIRC: {
		pAct = new AddCircleAction(this);
		break;
	}

	case DRAW_HEX: {
		pAct = new AddHexaAction(this);
		break;
	}
	case LOAD: {
		pAct = new LoadAction(this);
		break;
	}
	case UNDO: {
		pAct = new UndoAction(this);
		break;
	}

	case REDO: {
		pAct = new RedoAction(this);
		break;
	}

	case RCCW: {
		pAct = new RotateCCw(this);
		break;
	}
	case RCW: {
		pAct = new RotateCw(this); 
			break;
	}

	case DEL: {
		CFigure* dFig = getselected();
		pAct = new Delete(this, dFig);
		break;
	}

	case CLRALL: {
		pAct = new ClearAll(this);
		break;
	}
	case SWAP: {
		pAct = new SwapAction(this);
		break;
	}

	case SELECT: {
		pAct = new SelectAction(this);
		break;
	}
	case SAVE: {
		pAct = new SaveAction(this);
		break;
	}
	case COPY: {
		pAct = new Copy(this);
		break;	
	}

	case PASTE: {
		pAct = new Paste(this);
		break;
	}
	case CUT: {
		pAct = new CutAction(this);
		break;
	}
    case EXIT: {

		pAct = new Exit(this);

		///create ExitAction here
		// Hane3mel function exit derived men action
		// w ne5aleh yes2al el user law 3awez y save abl el exit

		break;
	}
	case TO_PLAY: {
		pAct = new SwitchToPlay(this);
		break;
	}
	case STATUS: {              	//a click on the status bar ==> no action
		return;
	}
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute(); //Execute
		
		ActList[ActCount] = pAct;       //Add action to list
		ActIndex++;
		ActCount++;                     //Increase the action count
		if (ActIndex < ActCount - 1) {
			for (int i = ActIndex + 1; i < ActCount; i++) {
				delete ActList[i];      //3a4an azabat el count
				ActList[i] = nullptr;   //Ma7ade4 yel3ab feha
			}
			ActCount = ActIndex + 1;    //Update the action count
		}
	}
}

//==================================================================================//
//                      Undo Redo Management Functions                              //
//==================================================================================//

void ApplicationManager::Undo()
{
	if (ActIndex >= 0 
		&& ActList[ActIndex] != nullptr
		&& ActIndex < ActCount) {
		
		ActList[ActIndex]->Undo();
		ActIndex--;
	}
	else {
		pOut->PrintMessage("No actions to undo");
	}
}

void ApplicationManager::Redo()
{
	if (ActIndex <= ActCount - 1
		&& ActList[ActIndex] != nullptr) {

		ActList[ActIndex]->Redo();  // Ha5aleha execute tany
	}                                  // Law fe wa2t momken a3mel redo
	else {
		pOut->PrintMessage("No actions to redo");
	}
}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
	{
		FigList[FigCount] = pFig;
		pFig->setID(FigCount);
		FigCount++;

	}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(Point P) const
{
	CFigure* Figp = NULL;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->isPointInside(P)) {
			Figp = FigList[i];
		}
	}
	return Figp;

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const {
	// Clear the drawing area
	pOut->ClearDrawArea();

	// Redraw all figures
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i] != nullptr) {
			FigList[i]->Draw(pOut);
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////

void ApplicationManager::SaveAll(ofstream& prout) const
{
	prout << FigCount << endl;
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(prout);

	}
}
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];

	for (int i = 0; i < ActCount; i++) {
		if (ActList[i] != nullptr) {
			delete ActList[i];
			ActList[i] = nullptr;
		}
	}

	delete pIn;
	delete pOut;
	
}

CFigure** ApplicationManager::GetFigList()
{
		return FigList;
}



