#pragma once

#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "IGameState.h"
#include "Game.h"

class PlayState : public IGameState
{
private:
	Game* m_game;				//Pointer needed to check game's state every frame for drawing

public:
	PlayState();
	~PlayState();
	void HandleInput(Game* game, EventTypes* eventType);
	void Update();
	void Draw(SDL_Renderer* renderer);
	void Enter(Game* game);
};

#endif