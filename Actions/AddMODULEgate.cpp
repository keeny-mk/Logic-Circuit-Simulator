#include "AddMODULEgate.h"
#include "..\ApplicationManager.h"
#include <iostream>
using namespace std;

AddMODULEgate::AddMODULEgate(ApplicationManager* pApp) :Action(pApp)
{
}

AddMODULEgate::~AddMODULEgate(void)
{
}

void AddMODULEgate::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	cout << "entered";
	//Print Action Message
	pUI->PrintMsg("5-Input Module: Click to add");
	cout << "passed";

	//Get Center point of the Gate
	do
	{
		pUI->GetPointClicked(Cx, Cy);
	} while (Cy < 210);

	//Clear Status Bars
	pUI->ClearStatusBar();
	//Calculate the rectangle Corners
	int gateWidth = pUI->getGateWidth();
	int gateHeight = pUI->getGateHeight();

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the NAND2 gate

	pGInfo->PointsList[0].x = Cx - gateWidth / 2;
	pGInfo->PointsList[0].y = Cy - gateHeight / 2;
	pGInfo->PointsList[1].x = Cx + gateWidth / 2;
	pGInfo->PointsList[1].y = Cy + gateHeight / 2;
	MODULEgate* pA = new MODULEgate(pGInfo, AND2_FANOUT, false);
	pManager->AddComponent(pA);
}

void AddMODULEgate::Undo()
{}

void AddMODULEgate::Redo()
{}

