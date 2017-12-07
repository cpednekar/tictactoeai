#include "Event.h"

Event::Event()
{
	m_bKeyPressed = false;
	m_event = new EventTypes(EventType_None);
}

Event::~Event()
{
	delete m_event;
	m_event = NULL;
}

EventTypes* Event::HandleInput(SDL_Event* sdlEvent)
{
	*m_event = EventType_None;				//Must be first line in order to avoid repeated inputs every frame

	if(sdlEvent->type == SDL_KEYDOWN)
	{
		switch(sdlEvent->key.keysym.sym)
		{
			case SDLK_UP:
			case SDLK_DOWN:
			case SDLK_RETURN:
			case SDLK_KP_1:
			case SDLK_KP_2:
			case SDLK_KP_3:
			case SDLK_KP_4:
			case SDLK_KP_5:
			case SDLK_KP_6:
			case SDLK_KP_7:
			case SDLK_KP_8:
			case SDLK_KP_9:
				m_bKeyPressed = true;
				break;
			default:
				m_bKeyPressed = false;
				break;
		}
	}
	
	if(sdlEvent->type == SDL_KEYUP)
	{
		if(m_bKeyPressed)
		{
			switch(sdlEvent->key.keysym.sym)
			{
				case SDLK_UP:
					*m_event = EventType_Key_UpArrow;
					break;
				case SDLK_DOWN:
					*m_event = EventType_Key_DownArrow;
					break;
				case SDLK_RETURN:
					*m_event = EventType_Key_Return;
					break;
				case SDLK_KP_1:
					*m_event = EventType_KeyPad_1;
					break;
				case SDLK_KP_2:
					*m_event = EventType_KeyPad_2;
					break;
				case SDLK_KP_3:
					*m_event = EventType_KeyPad_3;
					break;
				case SDLK_KP_4:
					*m_event = EventType_KeyPad_4;
					break;
				case SDLK_KP_5:
					*m_event = EventType_KeyPad_5;
					break;
				case SDLK_KP_6:
					*m_event = EventType_KeyPad_6;
					break;
				case SDLK_KP_7:
					*m_event = EventType_KeyPad_7;
					break;
				case SDLK_KP_8:
					*m_event = EventType_KeyPad_8;
					break;
				case SDLK_KP_9:
					*m_event = EventType_KeyPad_9;
					break;
				default:
					*m_event = EventType_None;
					break;
			}

			m_bKeyPressed = false;
		}
	}

	if(sdlEvent->type == SDL_MOUSEBUTTONDOWN)
	{
		if(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)){
			m_bKeyPressed = true;
		}
	}
	
	if(sdlEvent->type == SDL_MOUSEBUTTONUP)
	{
		if(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)){
			*m_event = EventType_MouseButton_Left;
			m_bKeyPressed = false;
		}
	}


	return m_event;
}