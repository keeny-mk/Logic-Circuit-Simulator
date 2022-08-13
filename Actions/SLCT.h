#ifndef _SLCT_H
#define _SLCT_H

#include "Action.h"

class SLCT : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	SLCT(ApplicationManager* pApp);
	virtual ~SLCT(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif