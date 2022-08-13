#include "SLCT.h"
#include "..\ApplicationManager.h"

SLCT::SLCT(ApplicationManager* pApp) :Action(pApp)
{
}

SLCT::~SLCT(void)
{
}

void SLCT::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Get Center point of the Gate
	pUI->GetPointClicked(Cx, Cy);

	if (pUI->getAppMode() == SIMULATION) {
		if (pManager->Compare(Cx, Cy) != NULL)
		{
			Component* cs = pManager->Compare(Cx, Cy);
			if (cs->getCompType() != SWITCH) {

				for (int j = 0; j < ((pManager->CompCount)); j++)
				{
					if (pManager->CompList[j] != NULL)
					{
						if (pManager->CompList[j]->trueorfalse == true)
						{
							if (cs != pManager->CompList[j])
								pManager->CompList[j]->trueorfalse = false;
						}
					}
				}
				cs->trueorfalse = !(cs->trueorfalse);
				pUI->PrintMsg(cs->PrintLabel());
			}
			else {
				if (cs->trueorfalse == true) {
					cs->trueorfalse = false;
				}
				else {
					cs->trueorfalse = true;
				}
				cs->Operate();
				pManager->switchON();
			}
		}
	}
	else {
		if (pManager->Compare(Cx, Cy) != NULL)
		{
			Component* cs = pManager->Compare(Cx, Cy);

			for (int j = 0; j < ((pManager->CompCount)); j++)
			{
				if (pManager->CompList[j] != NULL)
				{
					if (pManager->CompList[j]->trueorfalse == true)
					{
						if (cs != pManager->CompList[j])
							pManager->CompList[j]->trueorfalse = false;
					}
				}
			}
			cs->trueorfalse = !(cs->trueorfalse);
			pUI->PrintMsg(cs->PrintLabel());
		}
	}
}

void SLCT::Redo()
{}

void SLCT::Undo() {}