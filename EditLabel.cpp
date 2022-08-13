#include "EditLabel.h"
#include "ApplicationManager.h"
#include "Components\Component.h"

EditLabel::EditLabel(ApplicationManager* pApp) :Action(pApp)
{
}

EditLabel::~EditLabel(void)
{
}

void EditLabel::Execute()
{


	int Cx, Cy;

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("Edit Label: choose gate");

	//Get Center point of the Gate
	pUI->GetPointClicked(Cx, Cy);

	if (pManager->Compare(Cx, Cy) != NULL)
	{

		Component* cs = pManager->Compare(Cx, Cy);
		pUI->ClearStatusBar();
		cs->m_Label = pUI->GetString();
		pUI->ClearStatusBar();


	}


}
		
void EditLabel::Undo(){}
void EditLabel::Redo(){}
	
