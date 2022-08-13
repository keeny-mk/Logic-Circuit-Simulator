#include "saveAction.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include < windows.h >
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;
saveAction::saveAction(ApplicationManager* pApp) :Action(pApp)
{
}

saveAction::~saveAction(void)
{
}

void saveAction::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	Component** compList = pManager->getCompList();
	int compCount = pManager->getCompCount();
	pUI->PrintMsg("Type the file name you want to save to: ");     //Print Action Message        
	string filename = pUI->GetString();
	pUI->ClearStatusBar();

	ofstream file;                                                              //create file with name filename
	file.open(filename + ".txt");
	file << "Components: \n";
	file << compCount << "\n";
	string line;
	for (int i = 0; i < compCount; i++) {
		line = compList[i]->save();
		cout << line;
		int ind;
		for (int j = 0; j < line.length(); j++) {
			if (line.at(j) == '1') {
				ind = j;
				break;
			}
		}
		line = line.substr(0, ind) + to_string(i + 1) + line.substr(ind + 1, line.length() - ind);

		file << line;                                                            //print line into a file
	}

}

void saveAction::Undo()
{}

void saveAction::Redo()
{}

