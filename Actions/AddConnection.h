
#ifndef _ADD_Connection_H
#define _ADD_Connection_H

#include "action.h"
#include "..\\Components\Connection.h"

class AddConnection : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	 int Cx, Cy, Cx1, Cy1;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	
public:
	
	AddConnection(ApplicationManager* pApp);
	virtual ~AddConnection(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif