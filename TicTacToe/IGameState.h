#pragma once

#ifndef IGAMESTATE_H
#define IGAMESTATE_H

#include "Constants.h"
#include "header.h"

class Game;

class IGameState
{
public:
	virtual ~IGameState(){};
	virtual void HandleInput(Game* game, EventTypes* eventType){};
	virtual void Update(){};
	virtual void Draw(SDL_Renderer* renderer){};
	virtual void Enter(Game* game){};					//Handles all Init code on state entry
};


#endif