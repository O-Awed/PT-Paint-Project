#include "Actions\Action.h"

class AddHexaAction : public Action
{
private:
	Point P1;
	GfxInfo HexaGfxInfo;
public:
	AddHexaAction(ApplicationManager* pApp);

	//Reads Hexagon parameters
	virtual void ReadActionParameters();

	//Add hexagon to the ApplicationManager
	virtual void Execute();

	//Undo action
	virtual void Undo();

	//Redo action
	virtual void Redo();

	//Destructor
	~AddHexaAction();

};