#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\UI\UI.h"
#include "OutputPin.h"
#include "InputPin.h"

//Base class for classes Gate, Switch, and LED.
class Component
{
private:
public:
	string m_Label;
public:
	GraphicsInfo* m_pGfxInfo;

	//The parameters required to draw a component

	bool trueorfalse;
	Component(GraphicsInfo* r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(UI*) = 0;	//for each component to Draw itself

	virtual string PrintLabel() = 0;
	virtual int GetOutPinStatus() = 0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n) = 0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s) = 0;	//set status of Inputpin # n, to be used by connection class.
	virtual bool selected(int cx, int cy) = 0;
	virtual OutputPin* GetOutPin() = 0;
	virtual InputPin* GetInPin(int i) = 0;
	Component();
	virtual string save() = 0;
	virtual CompType getCompType() = 0;
	//Destructor must be virtual
	virtual ~Component();
};

#endif