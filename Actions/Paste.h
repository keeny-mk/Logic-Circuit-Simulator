#ifndef _Paste_H
#define _Paste_H

#include "Action.h"
#include"..\Components\Component.h"
class Paste : public Action
{
private:
	Component* CompCo;
	Component* CompCu;

public:
	Paste(ApplicationManager* pApp);
	virtual ~Paste(void);

	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
#endif