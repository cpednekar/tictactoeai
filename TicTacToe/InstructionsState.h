#pragma once

#ifndef INSTRUCTIONSSTATE_H
#define INSTRUCTIONSSTATE_H

#include "IGameState.h"
#include "Menu.h"
#include "Game.h"

class InstructionsState : public Menu, public IGameState
{
private:

public:
	InstructionsState();
	~InstructionsState();
	void HandleInput(Game* game, EventTypes* eventType);
	void Update();
	void Draw(SDL_Renderer* renderer);
	void Enter(Game* game);
};


#endif