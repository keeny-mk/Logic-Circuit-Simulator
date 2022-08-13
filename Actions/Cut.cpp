#include "Cut.h"
#include "..\ApplicationManager.h"

Cut::Cut(ApplicationManager* pApp) :Action(pApp)
{
}

Cut::~Cut(void)
{
}


void Cut::Execute()
{
	UI* pUI = pManager->GetUI();

	int Cx, Cy;
	do
	{
		pUI->PrintMsg("Select Component to Cut.");
		pUI->GetPointClicked(Cx, Cy);
	} while ((pManager->Compare(Cx, Cy)) == NULL);

	// CompCu = pManager->Compare(Cx, Cy);

	pUI->PrintMsg("Cut.");

	pManager->setCutComp(pManager->Compare(Cx, Cy));
}

void Cut::Redo()
{}

void Cut::Undo() {}