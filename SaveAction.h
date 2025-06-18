
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include <fstream>



class SaveAction : public Action
{
private:

	ofstream fout;
public:
	string name;
	SaveAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};


