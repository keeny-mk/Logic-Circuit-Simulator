#include "LED.h"

LED::LED(GraphicsInfo* r_pGfxInfo, int r_FanOut, bool truorfalse) :Gate(r_pGfxInfo, 2, r_FanOut)
{
	trueorfalse = truorfalse;
	m_Label = "LED";
	m_InputPins[0].setComponent(this);
	m_InputPins[1].setComponent(this);
	m_InputPins[1].setStatus(HIGH);
	m_OutputPin.setStatus(HIGH);
}


void LED::Operate()
{
	if (m_InputPins[0].getStatus() == HIGH)
	{
		trueorfalse = true;
	}
	else {
		trueorfalse = false;
	}
}



// Function Draw
// Draws 2-input AND gate
void LED::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawLED(*m_pGfxInfo, trueorfalse);
}
int LED::GetOutPinStatus()
{
	return 0;
}

//returns status of Inputpin #n
int LED::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
bool LED::selected(int cx, int cy)
{

	if (cx > m_pGfxInfo->PointsList[0].x&& cx < m_pGfxInfo->PointsList[1].x && cy > m_pGfxInfo->PointsList[0].y&& cy < m_pGfxInfo->PointsList[1].y)
		return (true);
	else
		return(false);
}
string LED::save() {
	int x = m_pGfxInfo->PointsList[0].x;
	int y = m_pGfxInfo->PointsList[1].y;
	string name = "LED";
	string result = name + "\t" + "1" + "\t" + m_Label + "\t" + to_string(x) + "\t" + to_string(y) + "\n";
	return result;
}
string LED::PrintLabel() {


	return m_Label;
}
OutputPin* LED::GetOutPin() {
	return &m_OutputPin;
}
InputPin* LED::GetInPin(int i) {
	return &m_InputPins[0];
}
CompType LED::getCompType()
{
	return LEDT;
}