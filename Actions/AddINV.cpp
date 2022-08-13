#include "AddINV.h"
#include "..\ApplicationManager.h"

AddINV::AddINV(ApplicationManager* pApp) :Action(pApp)
{
}

AddINV::~AddINV(void)
{
}

void AddINV::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("2-Input Inverter: Click to add the gate");

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

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the inverter gate

	pGInfo->PointsList[0].x = Cx - gateWidth / 2;
	pGInfo->PointsList[0].y = Cy - gateHeight / 2;
	pGInfo->PointsList[1].x = Cx + gateWidth / 2;
	pGInfo->PointsList[1].y = Cy + gateHeight / 2;
	INV* pA = new INV(pGInfo, AND2_FANOUT,false);
	pManager->AddComponent(pA);
}

void AddINV::Undo()
{}

void AddINV::Redo()
{}


