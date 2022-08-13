#include "OR2.h"
OR2::OR2(GraphicsInfo* r_pGfxInfo, int r_FanOut, bool trf) :Gate(r_pGfxInfo, 2, r_FanOut)
{
	trueorfalse = trf;
	m_Label = "OR Gate";
	m_InputPins[0].setComponent(this);
	m_InputPins[1].setComponent(this);
}


void OR2::Operate()
{
	if (m_InputPins[0].getStatus() == LOW && m_InputPins[1].getStatus() == LOW) {
		m_OutputPin.setStatus(LOW);
	}
	else
	{
		m_OutputPin.setStatus(HIGH);
	}
}


// Function Draw
// Draws 2-input AND gate
void OR2::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawOR2(*m_pGfxInfo, trueorfalse);
}

//returns status of outputpin
int OR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int OR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void OR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
bool OR2::selected(int cx, int cy)
{

	if (cx > m_pGfxInfo->PointsList[0].x&& cx < m_pGfxInfo->PointsList[1].x && cy > m_pGfxInfo->PointsList[0].y&& cy < m_pGfxInfo->PointsList[1].y)
		return (true);
	else
		return(false);
}

string OR2::save() {
	int x = m_pGfxInfo->PointsList[0].x;
	int y = m_pGfxInfo->PointsList[1].y;
	string name = "OR2";
	string result = name + "\t" + "1" + "\t" + m_Label + "\t" + to_string(x) + "\t" + to_string(y) + "\n";
	return result;
}
string OR2::PrintLabel() {


	return m_Label;
}
OutputPin* OR2::GetOutPin() {
	return &m_OutputPin;
}
InputPin* OR2::GetInPin(int i) {
	return &m_InputPins[i];
}
CompType OR2::getCompType()
{
	return OR;
}