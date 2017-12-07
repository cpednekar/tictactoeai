#include "SymbolSelectState.h"
#include "MatchTypeState.h"
#include "PlayState.h"

SymbolSelectState::SymbolSelectState()
{
	m_iActiveMenuOption = 0;
	m_iNumMenuOptions = 0;

	m_listMenuOptions.push_back(new MenuOption(250, 150, "CHOOSE X"));
	m_listMenuOptions.push_back(new MenuOption(250, 225, "CHOOSE O"));
	m_listMenuOptions.push_back(new MenuOption(250, 300, "BACK"));

	m_iNumMenuOptions = m_listMenuOptions.size();
}

SymbolSelectState::~SymbolSelectState()
{}

void SymbolSelectState::HandleInput(Game* game, EventTypes* eventType)
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
					CFG::playerOne->SetSymbol(Symbol_X);
					CFG::playerTwo->SetSymbol(Symbol_O);
					game->SetState(CFG::statePlay);
					break;
				case 1:
					CFG::playerOne->SetSymbol(Symbol_O);
					CFG::playerTwo->SetSymbol(Symbol_X);
					game->SetState(CFG::statePlay);
					break;
				case 2:
					game->SetState(CFG::stateMatchType);
					break;
			}
			break;
	}

}

void SymbolSelectState::Update()
{
	
}

void SymbolSelectState::Draw(SDL_Renderer* renderer)
{
	Menu::Draw(renderer);	
}

void SymbolSelectState::Enter(Game* game)
{
	Menu::m_iActiveMenuOption = 0;
}

