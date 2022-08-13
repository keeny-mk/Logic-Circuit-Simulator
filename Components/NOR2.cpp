#include "NOR2.h"
#include"Component.h"
NOR2::NOR2(GraphicsInfo* r_pGfxInfo, int r_FanOut, bool trf) :Gate(r_pGfxInfo, 2, r_FanOut)
{
	trueorfalse = trf;
	m_Label = "NOR Gate";
	m_InputPins[0].setComponent(this);
	m_InputPins[1].setComponent(this);
}


void NOR2::Operate()
{
	if (m_InputPins[0].getStatus() == LOW && m_InputPins[1].getStatus() == LOW) {
		m_OutputPin.setStatus(HIGH);
	}
	else
	{
		m_OutputPin.setStatus(LOW);
	}
}


// Function Draw
// Draws 2-input AND gate
void NOR2::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawNOR2(*m_pGfxInfo, trueorfalse);
}

//returns status of outputpin
int NOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
bool NOR2::selected(int cx, int cy)
{

	if (cx > m_pGfxInfo->PointsList[0].x&& cx < m_pGfxInfo->PointsList[1].x && cy > m_pGfxInfo->PointsList[0].y&& cy < m_pGfxInfo->PointsList[1].y)
		return (true);
	else
		return(false);
}

string NOR2::save() {
	int x = m_pGfxInfo->PointsList[0].x;
	int y = m_pGfxInfo->PointsList[1].y;
	string name = "NOR2";
	string result = name + "\t" + "1" + "\t" + m_Label + "\t" + to_string(x) + "\t" + to_string(y) + "\n";
	return result;
}
string NOR2::PrintLabel() {


	return m_Label;
}
OutputPin* NOR2::GetOutPin() {
	return &m_OutputPin;
}
InputPin* NOR2::GetInPin(int i) {
	return &m_InputPins[i];
}
CompType NOR2::getCompType()
{
	return NOR;
}