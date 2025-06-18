#include "SwitchToPlay.h"
#include"ApplicationManager.h"
#include "ApplicationManager.h"

SwitchToPlay::SwitchToPlay(ApplicationManager* AM) : Action(AM) {}
void SwitchToPlay::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Welcome to Playmode");
}

void SwitchToPlay::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();


}

void SwitchToPlay::Undo()
{
}

void SwitchToPlay::Redo()
{
}

SwitchToPlay::~SwitchToPlay()
{
}