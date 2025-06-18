#pragma once
#include "CCircle.h"
#include"Actions/Action.h"
class AddCircleAction:public Action
{
	private:
		Point P1, P2; //Rectangle Corners
		GfxInfo CircGfxInfo;
	public:
		AddCircleAction(ApplicationManager* pApp);

		//Reads rectangle parameters
		virtual void ReadActionParameters();

		//Add rectangle to the ApplicationManager
		virtual void Execute();

		//Undo the action
		virtual void Undo();

		//Redo the action
		virtual void Redo();

		~AddCircleAction();
	
};

