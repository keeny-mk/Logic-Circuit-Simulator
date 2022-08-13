#include "Delete.h"
#include "..\ApplicationManager.h"

Delete::Delete(ApplicationManager* pApp) :Action(pApp)
{
}

Delete::~Delete(void)
{
}

void Delete::Execute()
{
	UI* pUI = pManager->GetUI();
	
	pManager->DeleteCompS();



	pUI->PrintMsg("Components Deleted.");

	
}
void Delete::Undo()
{}
void Delete::Redo()
{}