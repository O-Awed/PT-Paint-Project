#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions\Action.h"
#include <fstream>


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	         //Max no of figures

private:
	int FigCount;		                 //Actual number of figures
	
	CFigure* FigList[MaxFigCount];	     //List of all figures (Array of pointers)

	Action* ActList[500];                //List of all actions
	int ActCount;                        //Actual number of actions
	int ActIndex;                        //Index of the last action in the list

	CFigure* SelectedFig;                //Pointer to the selected figure

	Input *pIn;
	Output *pOut;

	CFigure* Clipboard;                  //Pointer to copied/cut figure
	bool iscut = false;
	GfxInfo cutfig;


public:	
	ApplicationManager(); 
	void SaveAll(ofstream& prout) const;
	~ApplicationManager();
	CFigure** GetFigList();

	// -- Selection Management Functions

	void setselected(CFigure* sf);        //Set the selected figure
	CFigure* getselected();               //Gets the selected figure
	int selectedcount();                  //Gets the number of selected figures
	bool getSelectedIndices(int indices[2]);
	int getFigCount();                    //Gets the number of figures in the list
	void UnSelectA();                     //Unselects all the selected figure
	void selectedToSwap(CFigure* SL[]);   //Selects the figures to swap

	// -- Clipboard Management Functions

	void setclipboard(CFigure* c);        //Set the clipboard to store on it figures
	CFigure* getClipboard();
	void setIsCut(bool);
	bool getIsCut();
	void setGfxInfo(GfxInfo);

	// -- Delete Management Functions

	void deleteFig(CFigure* Dfigure);
	void clear();
	
	// -- Action-Related Functions
	
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ;       //Creates an action and executes it

	// -- Undo Redo Management Functions 

	void Undo();
	void Redo();                        

	// -- Figures Management Functions

	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(Point P) const;      //Search for a figure given a point inside the figure
		
	// -- Interface Management Functions

	Input *GetInput() const;                //Return pointer to the input
	Output *GetOutput() const;              //Return pointer to the output
	void UpdateInterface() const;	        //Redraws all the drawing window	

	// -- Save/Load Functions
	

};

#endif