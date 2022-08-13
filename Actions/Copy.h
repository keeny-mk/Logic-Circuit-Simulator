#ifndef _Copy_H
#define _Copy_H

#include "Action.h"
#include"..\Components\Component.h"
class Copy : public Action
{
private:

public:
	// Component* CompCo;
	Copy(ApplicationManager* pApp);
	virtual ~Copy(void);

	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
#endif