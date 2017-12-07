#pragma once

#ifndef ENDMENUSTATE_H
#define ENDMENUSTATE_H

#include "IGameState.h"
#include "Menu.h"
#include "Game.h"

class EndMenuState : public Menu, public IGameState
{
private:

public:
	EndMenuState();
	~EndMenuState();
	void HandleInput(Game* game, EventTypes* eventType);
	void Update();
	void Draw(SDL_Renderer* renderer);
	void Enter(Game* game);
};


#endif