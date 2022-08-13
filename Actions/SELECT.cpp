#include "SELECT.h"
#include "..\ApplicationManager.h"

SELECT::SELECT(ApplicationManager* pApp) :Action(pApp)
{
}

SELECT::~SELECT(void)
{
}

void SELECT::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Get Center point of the Gate
	pUI->GetPointClicked(Cx, Cy);

	Component *cs=pManager->Compare(Cx, Cy);
	cs->Draw(pUI);
	


}

void SELECT::Undo()
{}

void SELECT::Redo()
{}

