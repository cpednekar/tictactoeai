#pragma once

#ifndef CFG_H
#define CFG_H

#include "CIMG.h"
#include "Text.h"
#include "Structures.h"

class MainMenuState;
class InstructionsState;
class MatchTypeState;
class SymbolSelectState;
class PlayState;
class EndMenuState;
class Player;

class CFG
{

public:
	CFG();
	~CFG();

	static MainMenuState* stateMainMenu;
	static InstructionsState* stateInstructions;
	static MatchTypeState* stateMatchType;
	static SymbolSelectState* stateSymbolSelect;
	static PlayState* statePlay;
	static EndMenuState* stateEndMenu;

	static Player* playerOne;			//Always human
	static Player* playerTwo;			//Human or AI

	static const int infinity;

	static const Pos boardDrawPos[3][3];

	static bool bQuit;

	/********************** SDL Rendering and Event Handling *********************************/

	static const int SCREEN_WIDTH;
	static const int SCREEN_HEIGHT;

	static Text* textRenderer;
	static CIMG* imgSymbolX;
	static CIMG* imgSymbolO;
	static CIMG* imgBg;
	static CIMG* imgPopUp;

	static SDL_Window* sdlWindow;
	static SDL_Renderer* sdlRenderer;
	static SDL_Event* sdlMainEvent;

	static bool Init();
	static bool LoadMedia();
	static void Close();
};


#endif