#include "INV.h"
INV::INV(GraphicsInfo* r_pGfxInfo, int r_FanOut, bool trf) :Gate(r_pGfxInfo, 2, r_FanOut)
{
	trueorfalse = trf;
	m_Label = "Inverter";
	m_InputPins[0].setComponent(this);

}


void INV::Operate()
{
	if (m_InputPins[0].getStatus() == HIGH)
	{
		m_OutputPin.setStatus(LOW);

	}
	else {
		m_OutputPin.setStatus(HIGH);
	}
}


// Function Draw
// Draws 2-input AND gate
void INV::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawINV(*m_pGfxInfo, trueorfalse);
}

//returns status of outputpin
int INV::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int INV::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void INV::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
bool INV::selected(int cx, int cy)
{

	if (cx > m_pGfxInfo->PointsList[0].x&& cx < m_pGfxInfo->PointsList[1].x && cy > m_pGfxInfo->PointsList[0].y&& cy < m_pGfxInfo->PointsList[1].y)
		return (true);
	else
		return(false);
}
string INV::save() {
	int x = m_pGfxInfo->PointsList[0].x;
	int y = m_pGfxInfo->PointsList[1].y;
	string name = "INV";
	string result = name + "\t" + "1" + "\t" + m_Label + "\t" + to_string(x) + "\t" + to_string(y) + "\n";
	return result;
}
string INV::PrintLabel() {


	return m_Label;
}
OutputPin* INV::GetOutPin() {
	return &m_OutputPin;
}
InputPin* INV::GetInPin(int i) {
	return &m_InputPins[0];
}
CompType INV::getCompType()
{
	return INVERTER;
}