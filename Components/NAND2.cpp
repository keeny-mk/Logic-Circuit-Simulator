#include "NAND2.h"


NAND2::NAND2(GraphicsInfo* r_pGfxInfo, int r_FanOut, bool trf) :Gate(r_pGfxInfo, 2, r_FanOut)
{
	trueorfalse = trf;
	m_Label = "NAND Gate";
	m_InputPins[0].setComponent(this);
	m_InputPins[1].setComponent(this);
}


void NAND2::Operate()
{
	if (m_InputPins[0].getStatus() == HIGH && m_InputPins[1].getStatus() == HIGH) {
		m_OutputPin.setStatus(LOW);
	}
	else
	{
		m_OutputPin.setStatus(HIGH);
	}
}


// Function Draw
// Draws 2-input AND gate
void NAND2::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawNAND2(*m_pGfxInfo, trueorfalse);
}

//returns status of outputpin
int NAND2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NAND2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NAND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

bool NAND2::selected(int cx, int cy)
{

	if (cx > m_pGfxInfo->PointsList[0].x&& cx < m_pGfxInfo->PointsList[1].x && cy > m_pGfxInfo->PointsList[0].y&& cy < m_pGfxInfo->PointsList[1].y)
		return (true);
	else
		return(false);
}

string NAND2::save() {
	int x = m_pGfxInfo->PointsList[0].x;
	int y = m_pGfxInfo->PointsList[1].y;
	string name = "NAND2";
	string result = name + "\t" + "1" + "\t" + m_Label + "\t" + to_string(x) + "\t" + to_string(y) + "\n";
	return result;
}
string NAND2::PrintLabel() {


	return m_Label;
}
OutputPin* NAND2::GetOutPin() {
	return &m_OutputPin;
}
InputPin* NAND2::GetInPin(int i) {
	return &m_InputPins[i];
}
CompType NAND2::getCompType()
{
	return NAND;
}