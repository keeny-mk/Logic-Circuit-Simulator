#include "MODULEgate.h"
#include "XNOR2.h"
#include "NOR2.h"
#include "AND2.h"
#include "NAND2.h"
#include "XOR2.h"
#include "OR2.h";

MODULEgate::MODULEgate(GraphicsInfo* r_pGfxInfo, int r_FanOut, bool truorfalse) :Gate(r_pGfxInfo, 5, r_FanOut)
{
	trueorfalse = truorfalse;
	m_Label = "Module Gate";
	//m_OutputPins[0] = NCON;
	//m_OutputPins[1] = NCON;
	m_InputPins[0].setComponent(this);
	m_InputPins[1].setComponent(this);
	m_InputPins[2].setComponent(this);
	m_InputPins[3].setComponent(this);
	m_InputPins[4].setComponent(this);
}


void MODULEgate::Operate()
{
	//int gateWidth = 50;
	//int gateHeight = 50;
	//GraphicsInfo* pGInfo = new GraphicsInfo(2);
	//int Cx = 50;
	//int Cy = 50;
	//pGInfo->PointsList[0].x = Cx - gateWidth / 2;
	//pGInfo->PointsList[0].y = Cy - gateHeight / 2;
	//pGInfo->PointsList[1].x = Cx + gateWidth / 2;
	//pGInfo->PointsList[1].y = Cy + gateHeight / 2;
	////initialize building blocks
	//AND2* and_gate = new AND2(pGInfo, AND2_FANOUT, false);
	//NAND2* nand_gate = new NAND2(pGInfo, AND2_FANOUT, false);
	//XOR2* xor_gate = new XOR2(pGInfo, AND2_FANOUT, false);
	//XNOR2* xnor_gate = new XNOR2(pGInfo, AND2_FANOUT, false);
	//NOR2* nor_gate = new NOR2(pGInfo, AND2_FANOUT, false);
	//OR2* or_gate = new OR2(pGInfo, AND2_FANOUT, false);
	////use building blocks to calculate
	//// calculate the output of each gate.

	//// calculation of the first output pen F0.
	//xnor_gate->setInputPinStatus(1, m_InputPins[3].getStatus());
	//xnor_gate->setInputPinStatus(2, m_InputPins[2].getStatus());
	//xnor_gate->Operate();
	//int x1 = xnor_gate->GetOutPinStatus();
	//STATUS x1_status;
	//if (x1 == 1) x1_status = HIGH;
	//else x1_status = LOW;
	////////////////////////////////////////////////
	//nor_gate->setInputPinStatus(1, m_InputPins[1].getStatus());
	//nor_gate->setInputPinStatus(2, m_InputPins[2].getStatus());
	//nor_gate->Operate();
	//int x2 = nor_gate->GetOutPinStatus();
	//STATUS x2_status;
	//if (x2 == 1) x2_status = HIGH;
	//else x2_status = LOW;
	//and_gate->setInputPinStatus(1, m_InputPins[3].getStatus());
	//and_gate->setInputPinStatus(2, m_InputPins[4].getStatus());
	//and_gate->Operate();
	//int x4= and_gate->GetOutPinStatus();
	//STATUS x4_status;
	//if (x4 == 1) x4_status = HIGH;
	//else x4_status = LOW;
	//xnor_gate->setInputPinStatus(1, m_InputPins[1].getStatus());
	//xnor_gate->setInputPinStatus(2, m_InputPins[5].getStatus());
	//xnor_gate->Operate();
	//int x5 = xnor_gate->GetOutPinStatus();
	//STATUS x5_status;
	//if (x5 == 1) x5_status = HIGH;
	//else x5_status = LOW;

	//xnor_gate->setInputPinStatus(1,x1_status);
	//xnor_gate->setInputPinStatus(2,x2_status);
	//xnor_gate->Operate();
	//int x3 = xnor_gate->GetOutPinStatus();
	//STATUS x3_status;
	//if (x3 == 1) x3_status = HIGH;
	//else x3_status = LOW;

	//nand_gate->setInputPinStatus(1, x4_status);
	//nand_gate->setInputPinStatus(2, x5_status);
	//nand_gate->Operate();
	//int x6 = nand_gate->GetOutPinStatus();
	//STATUS x6_status;
	//if (x6 == 1) x6_status = HIGH;
	//else x6_status = LOW;

	//nor_gate->setInputPinStatus(1, x3_status);
	//nor_gate->setInputPinStatus(2, x6_status);
	//nor_gate->Operate();
	//int F0 = nor_gate->GetOutPinStatus();
	//STATUS F0_status;
	//if (F0 == 1) F0_status = HIGH;
	//else F0_status = LOW;
	//// calculation of the second output pen F1.

	//and_gate->setInputPinStatus(1, m_InputPins[4].getStatus());
	//and_gate->setInputPinStatus(2, m_InputPins[5].getStatus());
	//and_gate->Operate();
	//int x7 = and_gate->GetOutPinStatus();
	//STATUS x7_status;
	//if (x7 == 1) x7_status = HIGH;
	//else x7_status = LOW;


	//xor_gate->setInputPinStatus(1, m_InputPins[1].getStatus());
	//xor_gate->setInputPinStatus(2, m_InputPins[3].getStatus());
	//xor_gate->Operate();
	//int x8 = xor_gate->GetOutPinStatus();
	//STATUS x8_status;
	//if (x8 == 1) x8_status = HIGH;
	//else x8_status = LOW;


	//xnor_gate->setInputPinStatus(1, m_InputPins[2].getStatus());
	//xnor_gate->setInputPinStatus(2, m_InputPins[3].getStatus());
	//xnor_gate->Operate();
	//int x10 = xnor_gate->GetOutPinStatus();
	//STATUS x10_status;
	//if (x10 == 1) x10_status = HIGH;
	//else x10_status = LOW;


	//or_gate->setInputPinStatus(1, m_InputPins[3].getStatus());
	//or_gate->setInputPinStatus(2, m_InputPins[3].getStatus());
	//or_gate->Operate();
	//int x11 = or_gate->GetOutPinStatus();
	//STATUS x11_status;
	//if (x11 == 1) x11_status = HIGH;
	//else x11_status = LOW;


	//xnor_gate->setInputPinStatus(1, x7_status);
	//xnor_gate->setInputPinStatus(2, x8_status);
	//xnor_gate->Operate();
	//int x9 = xnor_gate->GetOutPinStatus();
	//STATUS x9_status;
	//if (x9 == 1) x9_status = HIGH;
	//else x9_status = LOW;

	//and_gate->setInputPinStatus(1, x10_status);
	//and_gate->setInputPinStatus(2, x11_status);
	//and_gate->Operate();
	//int x12 = xnor_gate->GetOutPinStatus();
	//STATUS x12_status;
	//if (x12 == 1) x12_status = HIGH;
	//else x12_status = LOW;

	//and_gate->setInputPinStatus(1, x9_status);
	//and_gate->setInputPinStatus(2, x12_status);
	//and_gate->Operate();
	//int F1 = xnor_gate->GetOutPinStatus();
	//STATUS F1_status;
	//if (F1 == 1) F1_status = HIGH;
	//else F1_status = LOW;

	//
	//m_OutputPins[0].setStatus(F0_status);
	//m_OutputPins[1].setStatus(F1_status);
}


// Function Draw
// Draws 2-input AND gate
void MODULEgate::Draw(UI* pUI)
{
	//Call output class and pass gate drawing info to it.
	pUI->DrawMODULE(*m_pGfxInfo, trueorfalse);
}

//returns status of outputpin
int MODULEgate::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int MODULEgate::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void MODULEgate::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

bool MODULEgate::selected(int cx, int cy)
{

	if (cx > m_pGfxInfo->PointsList[0].x&& cx < m_pGfxInfo->PointsList[1].x && cy > m_pGfxInfo->PointsList[0].y&& cy < m_pGfxInfo->PointsList[1].y)
		return (true);
	else
		return(false);
}
string  MODULEgate::PrintLabel() {

	return m_Label;

}

string MODULEgate::save() {
	int x = m_pGfxInfo->PointsList[0].x;
	int y = m_pGfxInfo->PointsList[1].y;
	string name = "Module";
	string result = name + "\t" + "1" + "\t" + m_Label + "\t" + to_string(x) + "\t" + to_string(y) + "\n";
	return result;
}

OutputPin* MODULEgate::GetOutPin() {
	return &m_OutputPin;
}
InputPin* MODULEgate::GetInPin(int i) {
	return &m_InputPins[i];
}
CompType MODULEgate::getCompType()
{
	return MODULE;
}

