#ifndef _LOAD_ACTION_H
#define _LOAD_ACTION_H

#include "action.h"

class loadAction : public Action
{

public:
	loadAction(ApplicationManager* pApp);
	virtual ~loadAction(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif