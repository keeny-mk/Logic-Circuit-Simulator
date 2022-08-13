#include "SLCTDEL.h"
#include "..\ApplicationManager.h"

SLCTDEL::SLCTDEL(ApplicationManager* pApp) :Action(pApp)
{
}

SLCTDEL::~SLCTDEL(void)
{
}


void SLCTDEL::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("Select Component(s) to Delete");

	int Cx, Cy;
	pUI->GetPointClicked(Cx, Cy);
	Component* cs;
	while (pManager->Compare(Cx, Cy) != NULL)
	{
		 cs = pManager->Compare(Cx, Cy);
		 cs->trueorfalse = true;
		pUI->PrintMsg(cs->PrintLabel());
		pManager->addCompS(cs);
		pManager->UpdateInterface();

		pUI->GetPointClicked(Cx, Cy);
	}

}
void SLCTDEL::Redo()
{}

void SLCTDEL::Undo() {}