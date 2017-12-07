#include "EndMenuState.h"
#include "MainMenuState.h"
#include "PlayState.h"

EndMenuState::EndMenuState()
{
	m_iActiveMenuOption = 0;
	m_iNumMenuOptions = 0;

	m_listMenuOptions.push_back(new MenuOption(250, 150, "REPLAY"));
	m_listMenuOptions.push_back(new MenuOption(250, 225, "GO TO MAIN MENU"));
	m_listMenuOptions.push_back(new MenuOption(250, 300, "EXIT"));

	m_iNumMenuOptions = m_listMenuOptions.size();
}

EndMenuState::~EndMenuState()
{}

void EndMenuState::HandleInput(Game* game, EventTypes* eventType)
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
					game->SetState(CFG::statePlay);
					break;
				case 1:
					game->SetState(CFG::stateMainMenu);
					break;
				case 2:
					CFG::bQuit = true;
					break;
				default:
					break;
			}
			break;
	}
}

void EndMenuState::Update()
{
	
}

void EndMenuState::Draw(SDL_Renderer* renderer)
{
	Menu::Draw(renderer);	
}

void EndMenuState::Enter(Game* game)
{
	Menu::m_iActiveMenuOption = 0;
}
