#include "XNOR2.h"
XNOR2::XNOR2(GraphicsInfo* r_pGfxInfo, int r_FanOut, bool trf) :Gate(r_pGfxInfo, 2, r_FanOut)
{
	trueorfalse = trf;
	m_Label = "XNOR Gate";
	m_InputPins[0].setComponent(this);
	m_InputPins[1].setComponent(this);
}


void XNOR2::Operate()
{
	if (m_InputPins[0].getStatus() == LOW && m_InputPins[1].getStatus() == HIGH || m_InputPins[0].getStatus() == HIGH && m_InputPins[1].getStatus() == LOW) {
		m_OutputPin.setStatus(LOW);
	}
	else
	{
		m_OutputPin.setStatus(HIGH);
	}
}


// Function Draw
// Draws 2-input AND gate
void XNOR2::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawXNOR2(*m_pGfxInfo, trueorfalse);
}

//returns status of outputpin
int XNOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XNOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XNOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
bool XNOR2::selected(int cx, int cy)
{

	if (cx > m_pGfxInfo->PointsList[0].x&& cx < m_pGfxInfo->PointsList[1].x && cy > m_pGfxInfo->PointsList[0].y&& cy < m_pGfxInfo->PointsList[1].y)
		return (true);
	else
		return(false);
}

string XNOR2::save() {
	int x = m_pGfxInfo->PointsList[0].x;
	int y = m_pGfxInfo->PointsList[1].y;
	string name = "XNOR2";
	string result = name + "\t" + "1" + "\t" + m_Label + "\t" + to_string(x) + "\t" + to_string(y) + "\n";
	return result;
}
string XNOR2::PrintLabel() {


	return m_Label;
}
OutputPin* XNOR2::GetOutPin() {
	return &m_OutputPin;
}
InputPin* XNOR2::GetInPin(int i) {
	return &m_InputPins[i];
}
CompType XNOR2::getCompType()
{
	return XNOR;
}