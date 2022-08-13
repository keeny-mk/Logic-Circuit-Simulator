#include"XOR2.h"

XOR2::XOR2(GraphicsInfo* r_pGfxInfo, int r_FanOut, bool trf) :Gate(r_pGfxInfo, 2, r_FanOut)
{
	trueorfalse = trf;
	m_Label = "XOR Gate";
	m_InputPins[0].setComponent(this);
	m_InputPins[1].setComponent(this);
}


void XOR2::Operate()
{
	if (m_InputPins[0].getStatus() == LOW && m_InputPins[1].getStatus() == HIGH || m_InputPins[0].getStatus() == HIGH && m_InputPins[1].getStatus() == LOW) {
		m_OutputPin.setStatus(HIGH);
	}
	else
	{
		m_OutputPin.setStatus(LOW);
	}
}


// Function Draw
// Draws 2-input AND gate
void XOR2::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawXOR2(*m_pGfxInfo, trueorfalse);
}

//returns status of outputpin
int XOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
bool XOR2::selected(int cx, int cy)
{

	if (cx > m_pGfxInfo->PointsList[0].x&& cx < m_pGfxInfo->PointsList[1].x && cy > m_pGfxInfo->PointsList[0].y&& cy < m_pGfxInfo->PointsList[1].y)
		return (true);
	else
		return(false);
}


string XOR2::save() {
	int x = m_pGfxInfo->PointsList[0].x;
	int y = m_pGfxInfo->PointsList[1].y;
	string name = "XOR2";
	string result = name + "\t" + "1" + "\t" + m_Label + "\t" + to_string(x) + "\t" + to_string(y) + "\n";
	return result;
}
string XOR2::PrintLabel() {


	return m_Label;
}
OutputPin* XOR2::GetOutPin() {
	return &m_OutputPin;
}
InputPin* XOR2::GetInPin(int i) {
	return &m_InputPins[i];
}
CompType XOR2::getCompType()
{
	return XOR;
}