#include "AddConnection.h"
#include"..\\Components\Connection.h"
#include "..\ApplicationManager.h"

AddConnection::AddConnection(ApplicationManager* pApp) :Action(pApp)
{
}

AddConnection::~AddConnection(void)
{
}

void AddConnection::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	if (pManager->CompCount < 2)
	{
		pUI->PrintMsg("You have to add two or more components");
		pUI->GetUserAction();
		return;
	}

	pUI->PrintMsg("Select the first component to add connection");

	pUI->GetPointClicked(Cx, Cy);
	while (pManager->Compare(Cx, Cy) == NULL)
	{
		pUI->PrintMsg("Select a component to add connection");

		pUI->GetPointClicked(Cx, Cy);
	}
	Component* c0 = pManager->Compare(Cx, Cy);


	pUI->PrintMsg("Select the second component");
	pUI->GetPointClicked(Cx1, Cy1);

	while (pManager->Compare(Cx1, Cy1) == pManager->Compare(Cx, Cy))
	{
		pUI->PrintMsg("Select a different Component");
		pUI->GetPointClicked(Cx1, Cy1);
		while (pManager->Compare(Cx1, Cy1) == NULL)
		{
			pUI->PrintMsg("Select the output pin of the first component");

			pUI->GetPointClicked(Cx1, Cy1);
			if (Cy1 <= pUI->getToolH()) {
				pUI->PrintMsg("Select the output pin of the first component");
			}
		}
	}
	while (pManager->Compare(Cx1, Cy1) == NULL)
	{
		pUI->PrintMsg("Select the input pin of the second component");

		pUI->GetPointClicked(Cx1, Cy1);
		while (pManager->Compare(Cx1, Cy1) == pManager->Compare(Cx, Cy))
		{
			pUI->PrintMsg("Select a different Component");
			pUI->GetPointClicked(Cx1, Cy1);

		}

	}

	Component* c1 = pManager->Compare(Cx1, Cy1);

	//Clear Status Bar
	pUI->ClearStatusBar();
	//Calculate the rectangle Corners


	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the AND2 gate

	/*pGInfo->PointsList[0].x = Cx;
	pGInfo->PointsList[0].y = Cy;
	pGInfo->PointsList[1].x = Cx1;
	pGInfo->PointsList[1].y = Cy1;
	*/


	c0->GetOutPin()->setStatus(LOW);

	pGInfo->PointsList[0].x = c0->m_pGfxInfo->PointsList[1].x;

	pGInfo->PointsList[0].y = c0->m_pGfxInfo->PointsList[1].y - pUI->getGateHeight() / 2;

	pGInfo->PointsList[1].x = c1->m_pGfxInfo->PointsList[0].x;

	if (c1->getCompType() == SWITCH || c1->getCompType() == INVERTER || c1->getCompType() == LEDT)
	{
		pGInfo->PointsList[1].y = c1->m_pGfxInfo->PointsList[0].y + pUI->getGateHeight() / 2;

	}
	else if (Cy1 > (c1->m_pGfxInfo->PointsList[0].y) && Cy1 < (c1->m_pGfxInfo->PointsList[0].y + pUI->getGateHeight() / 2))

		pGInfo->PointsList[1].y = c1->m_pGfxInfo->PointsList[0].y + pUI->getGateHeight() * 1 / 4;
	else
		pGInfo->PointsList[1].y = c1->m_pGfxInfo->PointsList[0].y + pUI->getGateHeight() * 3 / 4;
	Connection* pA = new Connection(pGInfo);
	pA->setSourcePin(c0->GetOutPin());

	if (pGInfo->PointsList[1].y == c1->m_pGfxInfo->PointsList[0].y + pUI->getGateHeight() * 3 / 4)
	{
		pA->setDestPin(c1->GetInPin(1));

	}
	else {
		pA->setDestPin(c1->GetInPin(0));
	}

	pManager->AddComponent(pA);
}
void AddConnection::Undo()
{}

void AddConnection::Redo()
{}