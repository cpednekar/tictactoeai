#pragma once

#ifndef MATCHTYPESTATE
#define MATCHTYPESTATE

#include "IGameState.h"
#include "Menu.h"
#include "Game.h"

class MatchTypeState : public Menu, public IGameState
{
private:	
public:
	MatchTypeState();
	~MatchTypeState();
	void HandleInput(Game* game, EventTypes* eventType);
	void Update();
	void Draw(SDL_Renderer* renderer);
	void Enter(Game* game);
};


#endif