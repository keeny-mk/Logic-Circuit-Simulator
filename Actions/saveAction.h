#ifndef _SAVE_ACTION_H
#define _SAVE_ACTION_H

#include "action.h"

class saveAction : public Action
{

public:
	saveAction(ApplicationManager* pApp);
	virtual ~saveAction(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif