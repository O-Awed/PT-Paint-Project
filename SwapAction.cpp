#include "SwapAction.h"
#include "ApplicationManager.h"
#include "GUI/Output.h"
#include "Figures/CFigure.h"
#include <iostream>
SwapAction::SwapAction(ApplicationManager* pApp) : Action(pApp) {}

void SwapAction::ReadActionParameters() {
    // Me4 me7tag 7aga 
}

void SwapAction::Execute() {
    Output* pOut = pManager->GetOutput();

    // Check if exactly two figures are selected
    if (pManager->selectedcount() != 2) {
        pOut->PrintMessage("You must select two figures to swap.");
        return;
    }

 
  
    if (!pManager->getSelectedIndices(indices)) {
        pOut->PrintMessage("Error identifying selected figures.");
        return;
    }

    CFigure** figList = pManager->GetFigList();
    CFigure* temp = figList[indices[0]];
    figList[indices[0]] = figList[indices[1]];
    figList[indices[1]] = temp;
    GfxInfo tempGfxInfo = figList[indices[0]]->getGfxInfo();
    figList[indices[0]]->setGfxInfo(figList[indices[1]]->getGfxInfo());
    figList[indices[1]]->setGfxInfo(tempGfxInfo);

    figList[indices[0]]->swap(figList[indices[1]]);

    
    pManager->UpdateInterface();

    pOut->PrintMessage("Swapped the positions of the two selected figures.");
}
void SwapAction::Undo() {
    CFigure** figList = pManager->GetFigList();
    figList[indices[0]]->swap(figList[indices[1]]);
}

void SwapAction::Redo() {
    CFigure** figList = pManager->GetFigList();
    figList[indices[0]]->swap(figList[indices[1]]);
}