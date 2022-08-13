#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include"Actions/AddINV.h"
#include"Actions/AddLED.h"
#include"Actions/AddNANDgate2.h"
#include"Actions/AddNORgate2.h"
#include"Actions/AddORgate2.h"
#include"Actions/AddSwitch.h"
#include"Actions/AddXNORgate2.h"
#include"Actions/AddXORgate2.h"
#include"Actions/AddConnection.h"
#include"Actions/AddMODULEgate.h"
#include"Actions/SLCT.h"
#include"Actions/saveAction.h"
#include"Actions/loadAction.h"
#include"EditLabel.h"
#include <iostream>
#include"Actions/Copy.h"
#include"Actions/Paste.h"
#include"Actions/Cut.h"
#include"UI/UI.h"
#include"Actions/SLCTDEL.h"
#include"Actions/Delete.h"
using namespace std;

ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the UI Object & Initialize the UI
	pUI = new UI;
}

////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
		CompList[CompCount++] = pComp;
	
}
Component* ApplicationManager::Compare(int x, int y) const
{
	int count = 0;
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i] != NULL)
		{
			if (CompList[i]->selected(x, y)) {
				return CompList[i];
				count++;
			}
		}
	}
	if (count == 0)
		return NULL;
	
}

////////////////////////////////////////////////////////////////////
void ApplicationManager::setCopiedComp(Component* mComp)
{
	CompCo = mComp;
}
Component* ApplicationManager::getCopiedComp()
{
	return CompCo;
}
void ApplicationManager::setCutComp(Component* mComp)
{
	CompCu = mComp;
}
Component* ApplicationManager::getCutComp()
{
	return CompCu;
}
void ApplicationManager::setCopy(Component* mComp, int X, int Y)
{
	int gateWidth = pUI->getGateWidth();
	int gateHeight = pUI->getGateHeight();
	GraphicsInfo* pGInfo = new GraphicsInfo(2); 
	pGInfo->PointsList[0].x = X - gateWidth / 2;
	pGInfo->PointsList[0].y = Y - gateHeight / 2;
	pGInfo->PointsList[1].x = X + gateWidth / 2;
	pGInfo->PointsList[1].y = Y + gateHeight / 2;
	CompType CT = mComp->getCompType();
	switch (CT)
	{
	case (NAND):{NAND2* pA = new NAND2(pGInfo, AND2_FANOUT, false); AddComponent(pA);break;}
	case (AND): {AND2* pA = new AND2(pGInfo, AND2_FANOUT, false); AddComponent(pA); break; }
	case (OR): { OR2* pA = new OR2(pGInfo, AND2_FANOUT, false); AddComponent(pA); break; }
	case (NOR): { NOR2* pA = new NOR2(pGInfo, AND2_FANOUT, false); AddComponent(pA); break; }
	case (XOR): {XOR2* pA = new XOR2(pGInfo, AND2_FANOUT, false); AddComponent(pA); break; }
	case (XNOR): { XNOR2* pA = new XNOR2(pGInfo, AND2_FANOUT, false); AddComponent(pA); break; }
	case (SWITCH): {Switch* pA = new Switch(pGInfo, AND2_FANOUT, false); AddComponent(pA); break; }
	case (INVERTER): { INV* pA = new INV(pGInfo, AND2_FANOUT, false); AddComponent(pA); break; }
	case (LEDT): {LED* pA = new LED(pGInfo, AND2_FANOUT, false); AddComponent(pA); break; }
	}
	
}

void ApplicationManager::setCut(Component* mComp, int X, int Y)
{
	int gateWidth = pUI->getGateWidth();
	int gateHeight = pUI->getGateHeight();
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i] == CompCu)
		{
		
			pUI->DeleteGate(*(CompList[i]->m_pGfxInfo));
			CompList[i]->m_pGfxInfo->PointsList[0].x = X - gateWidth / 2;
			CompList[i]->m_pGfxInfo->PointsList[0].y = Y - gateHeight / 2;
			CompList[i]->m_pGfxInfo->PointsList[1].x = X + gateWidth / 2;
			CompList[i]->m_pGfxInfo->PointsList[1].y = Y + gateHeight / 2;
		}
	}
}
void ApplicationManager::addCompS(Component* mComp)
{
	CompS[C_S++] = mComp;
}

void ApplicationManager::DeleteCompS()
{
	for (int i = 0; i < C_S; i++)
	{
		for (int j = 0; j < CompCount; j++)
		{
			if (CompS[i] == CompList[j])
			{
				for (int k = 0; k < CompCount; k++) {
					if (CompList[k]->getCompType() == CON) {
						for (int L = 0; L < 2; L++)
							if (CompS[i]->GetOutPin() == CompList[k]->GetOutPin() || CompS[i]->GetInPin(L) == CompList[k]->GetInPin(L)) {
								pUI->DeleteConn(*(CompList[j]->m_pGfxInfo));
							}
					}
				}
				pUI->DeleteGate(*(CompList[j]->m_pGfxInfo));
				CompList[j] = NULL;
				break;
			}

		}
	}
}


ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return pUI->GetUserAction(); 	
	
}
////////////////////////////////////////////////////////////////////
Component** ApplicationManager::getCompList() {
	return CompList;
}
int ApplicationManager::getCompCount() {
	return CompCount;
}
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	int x, y;
	Action* pAct = NULL;
	switch (ActType)
	{
		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);
			break;
		case ADD_OR_GATE_2:
			pAct = new AddORgate2(this);
			break;
		case ADD_NOR_GATE_2:
			pAct = new AddNORgate2(this);
			break;
		case ADD_XOR_GATE_2:
			pAct = new AddXORgate2(this);
			break;
		case ADD_XNOR_GATE_2:
			pAct = new AddXNORgate2(this);
			break;
		case ADD_NAND_GATE_2:
			pAct = new AddNANDgate2(this);
			break;
		case ADD_INV:
			pAct = new AddINV(this);
			break;
		case ADD_Switch:
			pAct = new AddSwitch(this);
			break;
		case ADD_LED:
			pAct = new AddLED(this);
			break;
		case ADD_CONNECTION:
			pAct = new AddConnection(this);
			break;
		case ADD_MODULE_Gate:
			pAct = new AddMODULEgate(this);
			break;
		case SELECT:
			pAct = new SLCT(this);
			break;
		case COPY:
			pAct = new Copy(this);
			break;
		case CUT:
			pAct = new Cut(this);
			break;
		case PASTE:
			pAct = new Paste(this);
			break;
		case MSLCT:
			pAct = new SLCTDEL(this);
			break;
		case DEL:
			pAct = new Delete(this);
			break;
		case SAVE:
		    pAct = new saveAction(this);
			break;
		case LOAD:
			pAct = new loadAction(this);
			cout << "load";
			break;
		case EDIT_Label:
			pAct = new EditLabel(this);
			break;
		case EXIT:
			pUI->ClearDrawingArea();
			break;
		case SIM_MODE:
			simON();
			break;
		case DSN_MODE:
			pUI->setAppMode(DESIGN);
			pUI->PrintMsg("Design Mode");
			for (int i = 0; i < CompCount; i++) {
				if (CompList[i]->getCompType() == LEDT) {
					CompList[i]->trueorfalse = false;
				}
			}
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
		for(int i=0; i<CompCount; i++)
			if(CompList[i]!=NULL)  CompList[i]->Draw(pUI);

}

////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}

////////////////////////////////////////////////////////////////////
void ApplicationManager::simON() {
	bool flag = false;

	for (int i = 0; i < CompCount; i++) {
		if (CompList[i] != NULL) {
			for (int j = 1; j < 3; j++) {
				if (CompList[i]->GetOutPinStatus() == NCON || CompList[i]->GetInputPinStatus(j) == NCON) {
					pUI->PrintMsg("Please Connect All gates");
					flag = true;
				}
			}
		}
		else {

		}
	}
	if (flag == false) {
		pUI->setAppMode(SIMULATION);
		switchON();
		pUI->PrintMsg("Simulation Mode");
	}
}

void ApplicationManager::switchON() {
	for (int j = 0; j < CompCount; j++) {
		for (int i = 0; i < CompCount; i++) {
			if (CompList[i]->getCompType() != SWITCH) {
				if (CompList[i]->getCompType() == CON) {
					CompList[i]->Operate();
				}

			}
		}
		for (int i = 0; i < CompCount; i++) {
			if (CompList[i]->getCompType() != SWITCH) {
				CompList[i]->Operate();
			}
		}
	}
}
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete pUI;
	
}