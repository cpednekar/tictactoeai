#include "MainMenuState.h"
#include "InstructionsState.h"
#include "MatchTypeState.h"
#include "CFG.h"
#include "Game.h"


MainMenuState::MainMenuState()
{
	m_iActiveMenuOption = 0;
	m_iNumMenuOptions = 0;

	m_listMenuOptions.push_back(new MenuOption(250, 150, "NEW GAME"));
	m_listMenuOptions.push_back(new MenuOption(250, 225, "HOW TO PLAY?"));
	m_listMenuOptions.push_back(new MenuOption(250, 300, "EXIT"));

	m_iNumMenuOptions = m_listMenuOptions.size();
}

MainMenuState::~MainMenuState()
{}

void MainMenuState::HandleInput(Game* game, EventTypes* eventType)
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
					game->SetState(CFG::stateMatchType);
					break;
				case 1:
					game->SetState(CFG::stateInstructions);
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

void MainMenuState::Update()
{
	
}

void MainMenuState::Draw(SDL_Renderer* renderer)
{
	CFG::textRenderer->Draw(renderer, "TIC TAC TOE", 50, 50, 48, 255, 255, 0);
	CFG::textRenderer->Draw(renderer, "@ CHANDAN PEDNEKAR 2017", 430, 450, 8, 255, 255, 255);
	CFG::textRenderer->Draw(renderer, "UP/DOWN : NAVIGATE, RETURN : SELECT", 10, 450, 8, 255, 255, 255);

	Menu::Draw(renderer);	
}

void MainMenuState::Enter(Game* game)
{
	Menu::m_iActiveMenuOption = 0;
}

