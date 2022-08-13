#ifndef _MODULEgate_H
#define _MODULEgate_H

/*
  Class MODULEgate
  -----------
  represent the 5-input MODULE gate
*/

#include "Gate.h"

class MODULEgate :public Gate
{
public:
	OutputPin* m_OutputPins;
	MODULEgate(GraphicsInfo* r_pGfxInfo, int r_FanOut, bool truorfals);
	virtual void Operate();	//Calculates the output of the module gate
	virtual void Draw(UI*);	//Draws  gate
	bool selected(int cx, int cy);
	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual OutputPin* GetOutPin();
	virtual InputPin* GetInPin(int i);
	virtual CompType getCompType();
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual string save();
	virtual string PrintLabel();

};

#endif