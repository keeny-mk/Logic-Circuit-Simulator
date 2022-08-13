#include "Connection.h"


Connection::Connection(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{

}

OutputPin* Connection::GetOutPin() {
	return SrcPin;
}
void Connection::setSourcePin(OutputPin* pSrcPin)
{
	SrcPin = pSrcPin;
}

OutputPin* Connection::getSourcePin()
{
	return SrcPin;
}


void Connection::setDestPin(InputPin* pDstPin)
{
	DstPin = pDstPin;
}

InputPin* Connection::getDestPin()
{
	return DstPin;
}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(UI* pUI)
{
	pUI->DrawConnection(*m_pGfxInfo, trueorfalse);
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}


bool Connection::selected(int cx, int cy)
{


	if (cx > m_pGfxInfo->PointsList[0].x&& cx < m_pGfxInfo->PointsList[1].x && cy > m_pGfxInfo->PointsList[0].y&& cy < m_pGfxInfo->PointsList[1].y)
		return (true);
	else
		return(false);
}

string Connection::save() {
	return "notimplemented";
};
string Connection::PrintLabel() { return ""; }
InputPin* Connection::GetInPin(int i) {
	return  DstPin;
}
CompType Connection::getCompType()
{
	return CON;
}