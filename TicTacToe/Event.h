#pragma once

#ifndef EVENT_H
#define EVENT_H

#include "Constants.h"
#include "header.h"

class Event
{
private:
	//SDL_Keysym iKeySym;
	bool m_bKeyPressed;
	EventTypes* m_event;

public:
	Event();
	~Event();
	EventTypes* HandleInput(SDL_Event* sdlEvent);

};

#endif