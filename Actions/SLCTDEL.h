#ifndef _SLCTDEL_H
#define _SLCTDEL_H

#include "Action.h"
#include"..\Components\Component.h"
class SLCTDEL : public Action
{
private:

public:
	// Component* CompCo;
	SLCTDEL(ApplicationManager* pApp);
	virtual ~SLCTDEL(void);

	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
#endif