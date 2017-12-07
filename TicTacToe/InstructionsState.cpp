#include "InstructionsState.h"
#include "MainMenuState.h"
#include "CFG.h"

InstructionsState::InstructionsState()
{
	m_iActiveMenuOption = 0;
	m_iNumMenuOptions = 0;

	m_listMenuOptions.push_back(new MenuOption(250, 350, "BACK"));

	m_iNumMenuOptions = m_listMenuOptions.size();
}

InstructionsState::~InstructionsState()
{}

void InstructionsState::HandleInput(Game* game, EventTypes* eventType)
{
	switch(*eventType)
	{
		case EventType_Key_Return:
			switch(m_iActiveMenuOption)
			{
				case 0:
					game->SetState(CFG::stateMainMenu);
					break;
				default:
					break;
			}
			break;
	}
}

void InstructionsState::Update()
{
	
}

void InstructionsState::Draw(SDL_Renderer* renderer)
{
	std::string sInstruction1 = "FIRST TO PLACE 3 SYMBOLS IN A LINE WINS";
	std::string sInstruction2 = "LINE CAN BE ROW, COLUMN OR DIAGONAL";
	std::string sInstruction3 = "USE vKEYPAD 1 THROUGH 9v TO MARK ON BOARD";
	CFG::textRenderer->Draw(renderer, sInstruction1, 50, 100, 12, 255, 255, 255);
	CFG::textRenderer->Draw(renderer, sInstruction2, 50, 150, 12, 255, 255, 255);
	CFG::textRenderer->Draw(renderer, sInstruction3, 50, 200, 12, 255, 255, 255);

	Menu::Draw(renderer);	
}

void InstructionsState::Enter(Game* game)
{
	Menu::m_iActiveMenuOption = 0;
}