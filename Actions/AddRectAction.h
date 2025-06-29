#ifndef ADD_RECT_ACTION_H
#define ADD_RECT_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class AddRectAction: public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
public:
	AddRectAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute() ;
	
	//Undo action
	virtual void Undo();

	//Redo action
	virtual void Redo();

	//Destructor
	~AddRectAction();
};

#endif