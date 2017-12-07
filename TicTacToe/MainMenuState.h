#pragma once

#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "IGameState.h"
#include "Menu.h"

class Game;

class MainMenuState : public Menu, public IGameState
{
private:	
public:
	MainMenuState();
	~MainMenuState();
	void HandleInput(Game* game, EventTypes* eventType);
	void Update();
	void Draw(SDL_Renderer* renderer);
	void Enter(Game* game);
};


#endif