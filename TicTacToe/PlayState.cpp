#include "PlayState.h"
#include "EndMenuState.h"
#include "CFG.h"

PlayState::PlayState()
{
	m_game = NULL;
}

PlayState::~PlayState()
{}

void PlayState::HandleInput(Game* game, EventTypes* eventType)
{
	bool turnTaken = false;

	if(!game->GameOver())
	{
		turnTaken = game->TakeTurn(eventType);
		if(turnTaken){
			if(game->IsCurrentPlayer(CFG::playerOne)){
				game->SetCurrentPlayer(CFG::playerTwo);
			}
			else{
				game->SetCurrentPlayer(CFG::playerOne);
			}
		}
	}
	else
	{
		switch(*eventType)
		{
			case EventType_Key_Return:
				game->SetState(CFG::stateEndMenu);
				break;
			default:
				break;
		}
	}
	
}

void PlayState::Update()
{
	
}

void PlayState::Draw(SDL_Renderer* renderer)
{
	//Draw background
	CFG::imgBg->Draw(renderer, 0, 0);

	//Draw board
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(m_game->PositionMarkedX(i, j)){
				CFG::imgSymbolX->Draw(renderer, CFG::boardDrawPos[i][j].x, CFG::boardDrawPos[i][j].y);
			}
			else if(m_game->PositionMarkedO(i, j)){
				CFG::imgSymbolO->Draw(renderer, CFG::boardDrawPos[i][j].x, CFG::boardDrawPos[i][j].y);
			}
		}
	}

	//Draw current turn message
	std::string sCurrentTurnMessage = "CURRENT TURN : " + ((m_game->IsCurrentPlayer(CFG::playerOne)) ? CFG::playerOne->ToString() : CFG::playerTwo->ToString());
	CFG::textRenderer->Draw(renderer, sCurrentTurnMessage, (CFG::SCREEN_WIDTH - CFG::textRenderer->GetTextWidth(sCurrentTurnMessage, 8)) / 2, 450, 8, 255, 0, 0);

	//Draw Popup
	if(m_game->GameOver())
	{
		std::string sGameOverMessage = m_game->GetGameOverMessage();
		std::string sInstruction = "PRESS RETURN";
		CFG::imgPopUp->Draw(renderer, 145, 140);
		CFG::textRenderer->Draw(renderer, sGameOverMessage,(CFG::SCREEN_WIDTH - CFG::textRenderer->GetTextWidth(sGameOverMessage, 16)) / 2, 225, 16, 255, 255, 255);
		CFG::textRenderer->Draw(renderer, sInstruction, (CFG::SCREEN_WIDTH - CFG::textRenderer->GetTextWidth(sInstruction, 8)) / 2, 275, 8, 255, 255, 255);
	}

}

void PlayState::Enter(Game* game)
{
	game->ClearBoard();
	game->SetCurrentPlayer(CFG::playerOne);
	m_game = game;
}
