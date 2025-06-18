#include "RedoAction.h"

RedoAction::RedoAction(ApplicationManager* AM) :Action(AM){}

void RedoAction::ReadActionParameters(){}

void RedoAction::Execute()
{
	pManager->Redo();
}

void RedoAction::Undo() {}
void RedoAction::Redo() {}
RedoAction::~RedoAction() {}
