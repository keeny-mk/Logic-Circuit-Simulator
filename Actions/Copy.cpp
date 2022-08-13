#include "Copy.h"
#include "..\ApplicationManager.h"

Copy::Copy(ApplicationManager* pApp) :Action(pApp)
{
}

Copy::~Copy(void)
{
}


void Copy::Execute() 
{
	UI* pUI = pManager->GetUI();

	int Cx, Cy;
	do
	{
		pUI->PrintMsg("Select Component to Copy.");
		pUI->GetPointClicked(Cx, Cy);
	} while ((pManager->Compare(Cx, Cy)) == NULL);


	pUI->PrintMsg("Copied.");

	pManager->setCopiedComp(pManager->Compare(Cx, Cy));


}
void Copy::Redo()
{}

void Copy::Undo() {}