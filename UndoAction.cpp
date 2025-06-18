#include "UndoAction.h"

UndoAction::UndoAction(ApplicationManager* AM) :Action(AM){}

void UndoAction::ReadActionParameters(){}

void UndoAction::Execute(){
	pManager->Undo();
}

void UndoAction::Undo() {}
void UndoAction::Redo() {}
UndoAction::~UndoAction() {}