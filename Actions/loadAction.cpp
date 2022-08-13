using namespace std;
#include <string>
#include<fstream>
#include<iostream>
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include < windows.h >
#include "loadAction.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include < windows.h >
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "..\Components\AND2.h"
#include "..\Components\INV.h"
#include "..\Components\LED.h"
#include "..\Components\NAND2.h"
#include "..\Components\NOR2.h"
#include "..\Components\OR2.h"
#include "..\Components\Switch.h"
#include "..\Components\XNOR2.h"
#include "..\Components\XOR2.h"
using namespace std;

loadAction::loadAction(ApplicationManager* pApp) :Action(pApp)
{
}

loadAction::~loadAction(void)
{
}

void loadAction::Execute()
{
	UI* pUI = pManager->GetUI();
	Component** compList = pManager->getCompList();
	int compCount = pManager->getCompCount();
	pUI->PrintMsg("Type the file name you want to load from: ");     //Print Action Message        
	string filename = pUI->GetString();
	pUI->ClearStatusBar();
	ifstream file(filename+".txt");
	string comptype;
	string ID;
	string X, Y;
	string Label;
	string line;
	int flag = 0;

	while (getline(file, line)) {
		// using printf() in all tests for consistency
		//split the line at space and fill the required variables
		bool flag_comptype = true;
		bool flag_ID = false;
		bool flag_label = false;
		bool flag_x = false;
		bool flag_y = false;
		int ind;
		flag += 1;
		if (flag >= 2) {
			for (int i = 0; i < line.length(); i++) {
				if (line.at(i) == '\t' && flag_comptype) {
					comptype = line.substr(0, i);
					flag_comptype = false;
					flag_ID = true;
					ind = i;
				}
				else if (line.at(i) == '\t' && flag_ID) {
					ID = line.substr(ind + 1, i - ind);
					flag_ID = false;
					flag_label = true;
					ind = i;
				}
				else if (line.at(i) == '\t' && flag_label) {
					Label = line.substr(ind + 1, i - ind);
					flag_label = false;
					flag_x = true;
					ind = i;
				}
				else if (line.at(i) == '\t' && flag_x) {
					X = line.substr(ind + 1, i - ind);
					flag_x = false;
					flag_y = true;
					ind = i;
				}
				else if (flag_y) {
					Y = line.substr(ind + 1, line.length() - ind);
					flag_comptype = true;
					flag_y = false;
				}
				//cout << comptype << "\t" << ID << "\t" << Label << "\t" << X << "\t" << Y << endl;
			}
		
		}

		//create the components
		int gateWidth = pUI->getGateWidth();
		int gateHeight = pUI->getGateHeight();
		if (strcmp(comptype.c_str(), "AND2") == 0) {
			GraphicsInfo* pGInfo = new GraphicsInfo(2);
			pGInfo->PointsList[0].x = stoi(X) + gateWidth;
			pGInfo->PointsList[0].y = stoi(Y);
			pGInfo->PointsList[1].x = stoi(X) - gateWidth;
			pGInfo->PointsList[1].y = stoi(Y) - gateHeight;
			AND2* pA = new AND2(pGInfo, AND2_FANOUT, false);
			pManager->AddComponent(pA);
		}
		else if (strcmp(comptype.c_str(), "NAND2") == 0) {
			GraphicsInfo* pGInfo = new GraphicsInfo(2);
			pGInfo->PointsList[0].x = stoi(X) + gateWidth;
			pGInfo->PointsList[0].y = stoi(Y);
			pGInfo->PointsList[1].x = stoi(X) - gateWidth;
			pGInfo->PointsList[1].y = stoi(Y) - gateHeight;
			NAND2* pA = new NAND2(pGInfo, AND2_FANOUT, false);
			pManager->AddComponent(pA);
		}
		else if (strcmp(comptype.c_str(), "OR2") == 0) {
			GraphicsInfo* pGInfo = new GraphicsInfo(2);
			pGInfo->PointsList[0].x = stoi(X) + gateWidth;
			pGInfo->PointsList[0].y = stoi(Y);
			pGInfo->PointsList[1].x = stoi(X) - gateWidth;
			pGInfo->PointsList[1].y = stoi(Y) - gateHeight;
			OR2* pA = new OR2(pGInfo, AND2_FANOUT, false);
			pManager->AddComponent(pA);
		}
		else if (strcmp(comptype.c_str(), "NOR2") == 0) {
			GraphicsInfo* pGInfo = new GraphicsInfo(2);
			pGInfo->PointsList[0].x = stoi(X) + gateWidth;
			pGInfo->PointsList[0].y = stoi(Y);
			pGInfo->PointsList[1].x = stoi(X) - gateWidth;
			pGInfo->PointsList[1].y = stoi(Y) - gateHeight;
			NOR2* pA = new NOR2(pGInfo, AND2_FANOUT, false);
			pManager->AddComponent(pA);
		}
		else if (strcmp(comptype.c_str(), "XOR2") == 0) {
			GraphicsInfo* pGInfo = new GraphicsInfo(2);
			pGInfo->PointsList[0].x = stoi(X) + gateWidth;
			pGInfo->PointsList[0].y = stoi(Y);
			pGInfo->PointsList[1].x = stoi(X) - gateWidth;
			pGInfo->PointsList[1].y = stoi(Y) - gateHeight;
			XOR2* pA = new XOR2(pGInfo, AND2_FANOUT, false);
			pManager->AddComponent(pA);
		}
		else if (strcmp(comptype.c_str(), "XNOR2") == 0) {
			GraphicsInfo* pGInfo = new GraphicsInfo(2);
			pGInfo->PointsList[0].x = stoi(X) + gateWidth;
			pGInfo->PointsList[0].y = stoi(Y);
			pGInfo->PointsList[1].x = stoi(X) - gateWidth;
			pGInfo->PointsList[1].y = stoi(Y) - gateHeight;
			XNOR2* pA = new XNOR2(pGInfo, AND2_FANOUT, false);
			pManager->AddComponent(pA);
		}
		else if (strcmp(comptype.c_str(), "INV") == 0) {
			GraphicsInfo* pGInfo = new GraphicsInfo(2);
			pGInfo->PointsList[0].x = stoi(X) + gateWidth;
			pGInfo->PointsList[0].y = stoi(Y);
			pGInfo->PointsList[1].x = stoi(X) - gateWidth;
			pGInfo->PointsList[1].y = stoi(Y) - gateHeight;
			INV* pA = new INV(pGInfo, AND2_FANOUT, false);
			pManager->AddComponent(pA);
		}
		else if (strcmp(comptype.c_str(), "LED") == 0) {
			GraphicsInfo* pGInfo = new GraphicsInfo(2);
			pGInfo->PointsList[0].x = stoi(X) + gateWidth;
			pGInfo->PointsList[0].y = stoi(Y);
			pGInfo->PointsList[1].x = stoi(X) - gateWidth;
			pGInfo->PointsList[1].y = stoi(Y) - gateHeight;
			LED* pA = new LED(pGInfo, AND2_FANOUT, false);
			pManager->AddComponent(pA);
		}
		else if (strcmp(comptype.c_str(), "Switch") == 0) {
			GraphicsInfo* pGInfo = new GraphicsInfo(2);
			pGInfo->PointsList[0].x = stoi(X) + gateWidth;
			pGInfo->PointsList[0].y = stoi(Y);
			pGInfo->PointsList[1].x = stoi(X) - gateWidth;
			pGInfo->PointsList[1].y = stoi(Y) - gateHeight;
			Switch* pA = new Switch(pGInfo, AND2_FANOUT, false);
			pManager->AddComponent(pA);
		}

	}
}
void loadAction::Undo()
{}

void loadAction::Redo()
{}
