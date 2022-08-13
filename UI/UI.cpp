#include "UI.h"

UI::UI()
{
	AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	DrawColor = BLACK;
	SelectColor = BLUE;
	ConnColor = RED;
	MsgColor = BLUE;
	BkGrndColor = WHITE;
	
	//Create the drawing window
	pWind = new window(width, height, wx, wy);	


	ChangeTitle("Logic Simulator Project");
	CreateSimulationToolBar();
	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar
}


int UI::getGateWidth() const
{
	return GATE_Width;
}

int UI::getGateHeight() const
{
	return GATE_Height;
}
void UI::setAppMode(MODE m1) {
	AppMode = m1;
}
MODE UI::getAppMode() {
	return AppMode;
}

//======================================================================================//
//								Input Functions 										//
//======================================================================================//

void UI::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);
	
	//Wait for mouse click
}

string UI::GetString()
{
	//Reads a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" is also supported
	//User should see what he is typing at the status bar


	string userInput;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);

		switch(Key)
		{
		case 27: //ESCAPE key is pressed
			PrintMsg("");
			return ""; //returns nothing as user has cancelled the input
		
		case 13:		//ENTER key is pressed
			return userInput;
		
		case 8:		//BackSpace is pressed
			if(userInput.size() > 0)
				userInput.resize(userInput.size() -1 );
			break;
		
		default:
			userInput+= Key;
		};
		
		PrintMsg(userInput);
	}

}

int UI::getToolH() {
	return ToolBarHeight;
}
//This function reads the position where the user clicks to determine the desired action
ActionType UI::GetUserAction() 
{	
	int x,y;
	
	
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
	if(AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_AND2: return ADD_AND_GATE_2;
			case ITM_OR2: return ADD_OR_GATE_2;
			case ITM_NOR2: return ADD_NOR_GATE_2;		
			case ITM_NAND2: return ADD_NAND_GATE_2;
			case ITM_XOR2: return ADD_XOR_GATE_2;
			case ITM_XNOR2: return ADD_XNOR_GATE_2;
			case ITM_LED: return ADD_LED;
			case ITM_Switch: return ADD_Switch;
			case ITM_INV: return ADD_INV;
			case ITM_MODULECIRCUIT: return ADD_MODULE_Gate;
			case ITM_CONNECTION: return ADD_CONNECTION;
			case ITM_EDITLABEL: return EDIT_Label;
			case ITM_Save: return SAVE;
			case ITM_Load: return LOAD;
			case ITM_COPY: return COPY;
			case ITM_CUT: return CUT;
			case ITM_PASTE: return PASTE;
			case ITM_MSLCT: return MSLCT;
			case ITM_DEL: return DEL;
			case ITM_EXIT: return EXIT;	
			
			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}
		if (y >= ToolBarHeight && y < (2 * ToolBarHeight)) {
			int ClickedItemOrder = (x / ToolItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_SIM:
				return SIM_MODE;
			case ITM_TRUTH:
				return DSN_MODE;
				break;
			default:
				break;
			}
		}
		if (y >= 2 * ToolBarHeight && y < height - StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a statement in the flowchart
		}
		//[2] User clicks on the drawing area
		if (y >= height - StatusBarHeight && y < height) {
			return STATUS_BAR;
		}
	}
	else	//Application is in Simulation mode
	{
		if (y >= ToolBarHeight && y < (2 * ToolBarHeight)) {
			int ClickedItemOrder = (x / ToolItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_SIM:
				break;
			case ITM_TRUTH:
				return DSN_MODE;
				break;
			}
		}
		if (y >= 2 * ToolBarHeight && y < height - StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a statement in the flowchart
		}
	}
}


//======================================================================================//
//								Output Functions										//
//======================================================================================//

//////////////////////////////////////////////////////////////////////////////////
void UI::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::CreateStatusBar() const
{
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, height-StatusBarHeight, width, height-StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(MsgColor); 
	pWind->DrawString(MsgX, height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(BkGrndColor);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(MsgX, height - MsgY, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void UI::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void UI::CreateDesignToolBar() 
{
	AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_AND2] = "images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_OR2]  = "images\\Menu\\Menu_OR2.jpg";
	MenuItemImages[ITM_XOR2] = "images\\Menu\\Menu_XOR.jpg";
	MenuItemImages[ITM_NAND2] = "images\\Menu\\Menu_NAND.jpg";
	MenuItemImages[ITM_NOR2] = "images\\Menu\\Menu_NOR.jpg";
	MenuItemImages[ITM_XNOR2] = "images\\Menu\\Menu_XNOR.jpg";
	MenuItemImages[ITM_EXIT] = "Images\\Menu\\Menu_Exit.jpg";
	MenuItemImages[ITM_INV] = "images\\Menu\\Menu_INV.jpg";
	MenuItemImages[ITM_MODULECIRCUIT]= "images\\Menu\\ModuleCircuit.jpg";
	MenuItemImages[ITM_Switch] = "images\\Menu\\Menu_Switch.jpg";
	MenuItemImages[ITM_LED] = "images\\Menu\\Menu_LED.jpg";
	MenuItemImages[ITM_CONNECTION] = "images\\Menu\\CONNECTION.jpg";
	MenuItemImages[ITM_EDITLABEL] = "images\\Menu\\edit.jpg";
	MenuItemImages[ITM_Save] = "images\\Menu\\Menu_Save.jpg";
	MenuItemImages[ITM_Load] = "images\\Menu\\Menu_Load.jpg";
	MenuItemImages[ITM_COPY] = "images\\Menu\\COPY.jpg";
	MenuItemImages[ITM_PASTE] = "images\\Menu\\PASTE.jpg";
	MenuItemImages[ITM_CUT] = "images\\Menu\\CUT.jpg";
	MenuItemImages[ITM_MSLCT] = "images\\Menu\\MSLCT.jpg";
	MenuItemImages[ITM_DEL] = "images\\Menu\\DELETE.jpg";



	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],i*ToolItemWidth,0,ToolItemWidth, ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);	

} 
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void UI::CreateSimulationToolBar()
{
	AppMode = SIMULATION;	//Simulation Mode
	string SimMenuImages[ITM_SIM_CNT];
	SimMenuImages[ITM_SIM] = "images\\Menu\\ON.jpeg";
	SimMenuImages[ITM_TRUTH] = "images\\Menu\\TRUTH.jpeg";
	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(SimMenuImages[i], i * ToolItemWidth, ToolBarHeight, ToolItemWidth, ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, 2 * ToolBarHeight, width, 2 * ToolBarHeight);
	


}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void UI::DrawAND2(const GraphicsInfo &r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_AND2_Hi.jpg";
	else  
		GateImage = "Images\\Gates\\Gate_AND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}
void UI::DrawOR2(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_OR_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_OR.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}
void UI::DrawXOR2(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XOR_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XOR.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}
void UI::DrawNAND2(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NAND_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NAND.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}

void UI::DrawNOR2(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOR_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOR.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}
void UI::DrawXNOR2(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XNOR_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XNOR.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
	
}
void UI::DrawINV(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\NOTHI.jpg";
	else
		GateImage = "Images\\Gates\\NOT.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}

//TODO: Add similar functions to draw all components
void UI::DrawLED(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\LED_ON.jpg";
	else
		GateImage = "Images\\Gates\\LED.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}
void UI::DrawSwitch(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\SWITCH_ON.jpg";
	else
		GateImage = "Images\\Gates\\SWITCH_OFF.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}
void UI::DrawMODULE(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\ModuleCircuit_Hi.jpg";
	else
		GateImage = "Images\\Gates\\ModuleCircuit.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);
}
void UI::DrawConnection(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	if (selected)
	{
		pWind->SetPen(RED, 3);
		pWind->DrawLine(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y);
	}
	else
	{
		pWind->SetPen(BLUE, 3);
		pWind->DrawLine(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y);
	}
}
void UI::DeleteGate(const GraphicsInfo& r_GfxInfo) const
{
	
	string GateImage= "Images\\Gates\\WHITE.jpg";
	pWind->DrawImage(GateImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, GATE_Width, GATE_Height);


}
void UI::DeleteConn(const GraphicsInfo& r_GfxInfo) {
	pWind->SetPen(WHITE, 3);
	pWind->DrawLine(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y);
}

UI::~UI()
{
	delete pWind;
}