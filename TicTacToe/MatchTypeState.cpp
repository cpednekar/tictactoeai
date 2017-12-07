#include "MatchTypeState.h"
#include "MainMenuState.h"
#include "SymbolSelectState.h"


MatchTypeState::MatchTypeState()
{
	m_iActiveMenuOption = 0;
	m_iNumMenuOptions = 0;

	m_listMenuOptions.push_back(new MenuOption(200, 150, "PLAYER VS PLAYER"));
	m_listMenuOptions.push_back(new MenuOption(200, 225, "PLAYER VS COMPUTER"));
	m_listMenuOptions.push_back(new MenuOption(200, 300, "BACK"));

	m_iNumMenuOptions = m_listMenuOptions.size();
}

MatchTypeState::~MatchTypeState()
{}

void MatchTypeState::HandleInput(Game* game, EventTypes* eventType)
{
	switch(*eventType)
	{
		case EventType_Key_DownArrow:
			UpdateActiveMenuOption(Direction_Down);
			break;
		case EventType_Key_UpArrow:
			UpdateActiveMenuOption(Direction_Up);
			break;
		case EventType_Key_Return:
			switch(m_iActiveMenuOption)
			{
				case 0:
					game->SetState(CFG::stateSymbolSelect);
					game->SetGameType(GameType_PlayerVsPlayer);
					break;
				case 1:
					game->SetState(CFG::stateSymbolSelect);
					game->SetGameType(GameType_PlayerVsComputer);
					break;
				case 2:
					game->SetState(CFG::stateMainMenu);
					break;
			}
			break;
	}

}

void MatchTypeState::Update()
{
	
}

void MatchTypeState::Draw(SDL_Renderer* renderer)
{
	Menu::Draw(renderer);	
}

void MatchTypeState::Enter(Game* game)
{
	Menu::m_iActiveMenuOption = 0;
}