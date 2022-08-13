#ifndef _ADD_MODULE_GATE_H
#define _ADD_MODULE_GATE_H

#include "action.h"
#include "..\Components\MODULEgate.h"

class AddMODULEgate : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddMODULEgate(ApplicationManager* pApp);
	virtual ~AddMODULEgate(void);

	//Execute action (code depends on action type)
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();


};

#endif