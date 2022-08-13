#ifndef _LED_H
#define _LED_H


#include "Gate.h"
class LED :
	public Gate
{
public:
	LED(GraphicsInfo* r_pGfxInfo, int r_FanOut, bool truorfals);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(UI*);	//Draws 2-input gate
	virtual int GetOutPinStatus();
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	bool selected(int cx, int cy);
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual string save();
	virtual string PrintLabel();
	virtual OutputPin* GetOutPin();
	virtual InputPin* GetInPin(int i);
	virtual CompType getCompType();
};
#endif
