#include "Actions/Action.h"
#include "ApplicationManager.h"
#include <fstream>

class LoadAction : public Action {
    string name;
public:
    LoadAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void Undo();
    virtual void Redo();
    ~LoadAction();
};
