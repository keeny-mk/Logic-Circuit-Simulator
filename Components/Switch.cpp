#include "Switch.h"


Switch::Switch(GraphicsInfo* r_pGfxInfo, int r_FanOut, bool trf) :Gate(r_pGfxInfo, 2, r_FanOut)
{
	trueorfalse = trf;
	m_Label = "Switch";
	m_InputPins[0].setComponent(this);
	m_InputPins[1].setComponent(this);
	m_InputPins[0].setStatus(HIGH);
	m_InputPins[1].setStatus(HIGH);
}


void Switch::Operate()
{
	if (trueorfalse) {
		m_OutputPin.setStatus(HIGH);
	}
	else {
		m_OutputPin.setStatus(LOW);
	}


}


// Function Draw
// Draws 2-input AND gate
void Switch::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawSwitch(*m_pGfxInfo, trueorfalse);
}

//returns status of outputpin
int Switch::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int Switch::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void Switch::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

bool Switch::selected(int cx, int cy)
{

	if (cx > m_pGfxInfo->PointsList[0].x&& cx < m_pGfxInfo->PointsList[1].x && cy > m_pGfxInfo->PointsList[0].y&& cy < m_pGfxInfo->PointsList[1].y)
		return (true);
	else
		return(false);
}

string Switch::save() {
	int x = m_pGfxInfo->PointsList[0].x;
	int y = m_pGfxInfo->PointsList[1].y;
	string name = "Switch";
	string result = name + "\t" + "1" + "\t" + m_Label + "\t" + to_string(x) + "\t" + to_string(y) + "\n";
	return result;
}
string Switch::PrintLabel() {


	return m_Label;
}
OutputPin* Switch::GetOutPin() {
	return &m_OutputPin;
}
InputPin* Switch::GetInPin(int i) {
	return &m_InputPins[0];
}
CompType Switch::getCompType()
{
	return SWITCH;
}