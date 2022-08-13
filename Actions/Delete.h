#ifndef _Delete_H
#define _Delete_H

#include "Action.h"
#include"..\Components\Component.h"
class Delete:public Action
{
private:
	Component* CompS[];

public:
	Delete(ApplicationManager* pApp);
	virtual ~Delete(void);

	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
#endif