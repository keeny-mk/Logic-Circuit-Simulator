#pragma once
#ifndef _EDIT_LABEL_H
#define _EDIT_LABEL_H

#include "Actions/Action.h"
#include "Components/Component.h"

class EditLabel : public Action
{

public:
	EditLabel(ApplicationManager* pApp);
	virtual ~EditLabel(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

#endif