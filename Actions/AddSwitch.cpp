#include "AddSwitch.h"
#include "..\ApplicationManager.h"

AddSwitch::AddSwitch(ApplicationManager* pApp) :Action(pApp)
{
}

AddSwitch::~AddSwitch(void)
{
}

void AddSwitch::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Switch: Click to add the switch");

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

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the AND2 gate

	pGInfo->PointsList[0].x = Cx - gateWidth / 2;
	pGInfo->PointsList[0].y = Cy - gateHeight / 2;
	pGInfo->PointsList[1].x = Cx + gateWidth / 2;
	pGInfo->PointsList[1].y = Cy + gateHeight / 2;
	Switch* pA = new Switch(pGInfo, AND2_FANOUT,false);
	pManager->AddComponent(pA);
}

void AddSwitch::Undo()
{}

void AddSwitch::Redo()
{}

