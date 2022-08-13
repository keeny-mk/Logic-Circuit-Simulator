#ifndef _Cut_H
#define _Cut_H

#include "Action.h"
#include"..\Components\Component.h"
class Cut : public Action
{
private:

public:
	// Component* CompCu;
	Cut (ApplicationManager* pApp);
	virtual ~Cut(void);

	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
#endif