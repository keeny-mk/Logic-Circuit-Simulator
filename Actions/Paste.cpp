#include "Paste.h"
#include "..\ApplicationManager.h"

Paste::Paste(ApplicationManager* pApp) :Action(pApp)
{
}

Paste::~Paste(void)
{
}

void Paste::Execute()
{
	UI* pUI = pManager->GetUI();
	
	pUI->PrintMsg("Click to Paste");

	int X, Y;
	pUI->GetPointClicked(X, Y);
	pUI->ClearStatusBar();
	
	CompCo = pManager->getCopiedComp();
	CompCu = pManager->getCutComp();

 if (CompCo != NULL)
 {
	
	 pManager->setCopy(CompCo, X, Y);
	 pManager->setCopiedComp(NULL);
 }

 if (CompCu != NULL)
 {
	 pManager->setCut(CompCu, X, Y);
	 pManager->setCutComp(NULL);
 }
	
}
 void Paste:: Undo()
{}
 void Paste ::Redo()
{}