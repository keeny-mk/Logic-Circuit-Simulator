#include "AddLED.h"
#include "..\ApplicationManager.h"

AddLED::AddLED(ApplicationManager* pApp) :Action(pApp)
{
}

AddLED::~AddLED(void)
{
}

void AddLED::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("LED: Click to add the led");

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

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the LED

	pGInfo->PointsList[0].x = Cx - gateWidth / 2;
	pGInfo->PointsList[0].y = Cy - gateHeight / 2;
	pGInfo->PointsList[1].x = Cx + gateWidth / 2;
	pGInfo->PointsList[1].y = Cy + gateHeight / 2;
	LED* pA = new LED(pGInfo, AND2_FANOUT,false);
	pManager->AddComponent(pA);
}

void AddLED::Undo()
{}

void AddLED::Redo()
{}

