#pragma once

#ifndef SYMBOLSELECTSTATE
#define SYMBOLSELECTSTATE

#include "IGameState.h"
#include "Menu.h"
#include "Game.h"

class SymbolSelectState : public Menu, public IGameState
{
private:	
public:
	SymbolSelectState();
	~SymbolSelectState();
	void HandleInput(Game* game, EventTypes* eventType);
	void Update();
	void Draw(SDL_Renderer* renderer);
	void Enter(Game* game);
};

#endif