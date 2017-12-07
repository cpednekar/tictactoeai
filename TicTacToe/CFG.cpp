#include "CFG.h"
#include "MainMenuState.h"
#include "InstructionsState.h"
#include "MatchTypeState.h"
#include "SymbolSelectState.h"
#include "PlayState.h"
#include "EndMenuState.h"
#include "Player.h"


CFG::CFG()
{}

CFG::~CFG()
{
	delete stateMainMenu;
	delete stateInstructions;
	delete stateMatchType;
	delete stateSymbolSelect;
	delete statePlay;
	delete stateEndMenu;

	delete playerOne;
	delete playerTwo;

	stateMainMenu = NULL;
	stateInstructions = NULL;
	stateMatchType = NULL;
	stateSymbolSelect = NULL;
	statePlay = NULL;
	stateEndMenu = NULL;

	playerOne = NULL;
	playerTwo = NULL;
}


//Inits SDL objects
bool CFG::Init()
{
	//Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        sdlWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( sdlWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
			//Set Window Title and Border
			//SDL_SetWindowTitle(sdlWindow, "TIC TAC TOE");
			SDL_SetWindowBordered(sdlWindow, SDL_FALSE);

			//Create renderer
			sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);
			if(sdlRenderer == NULL)
			{
				printf( "Renderer could not be created! SDL_Error: %s\n", SDL_GetError() );
				success = false;
			}

			//Create Event object
			sdlMainEvent = new SDL_Event();
			if(sdlMainEvent == NULL)
			{
				printf("Event Object could not be created! SDL_Error: %s\n", SDL_GetError() );
				success = false;
			}
        }

    }

    return success;
}

//Loads Media
bool CFG::LoadMedia()
{
	bool success = true;
	
	textRenderer = new Text();
	textRenderer->SetFont(sdlRenderer, "font");
	imgSymbolX = new CIMG("x", sdlRenderer, 255, 0, 255);
	imgSymbolO = new CIMG("o", sdlRenderer, 255, 0, 255);
	imgBg = new CIMG("background", sdlRenderer);
	imgPopUp = new CIMG("pop_up", sdlRenderer);

	if(textRenderer == NULL || imgBg == NULL || imgPopUp == NULL || imgSymbolO == NULL || imgSymbolX == NULL)
	{
		success = false;
	}

	return success;
}

//Clears all SDL objects
void CFG::Close()
{
    //Destroy window
    SDL_DestroyWindow( sdlWindow );
    sdlWindow = NULL;

	//Destroy renderer
	SDL_DestroyRenderer( sdlRenderer );
	sdlRenderer = NULL;
		
    //Quit SDL subsystems
    SDL_Quit();
}


//Initialize Static Vars
MainMenuState* CFG::stateMainMenu = new MainMenuState();
InstructionsState* CFG::stateInstructions = new InstructionsState();
MatchTypeState* CFG::stateMatchType = new MatchTypeState();
SymbolSelectState* CFG::stateSymbolSelect = new SymbolSelectState();
PlayState* CFG::statePlay = new PlayState();
EndMenuState* CFG::stateEndMenu = new EndMenuState();

Player* CFG::playerOne = new Player("PLAYER ONE", Symbol_X);
Player* CFG::playerTwo = new Player("PLAYER TWO", Symbol_O);

const int CFG::infinity = 10;

const Pos CFG::boardDrawPos[3][3] = { { {120, 50}, {280, 50}, {420, 50} }, { {120, 190}, {280, 190}, {420, 190} }, { {120, 330}, {280, 330}, {420, 330} } };

bool CFG::bQuit = false;

const int CFG::SCREEN_WIDTH = 640;
const int CFG::SCREEN_HEIGHT = 480;

SDL_Window* CFG::sdlWindow = NULL;
SDL_Renderer* CFG::sdlRenderer = NULL;
SDL_Event* CFG::sdlMainEvent = NULL;

Text* CFG::textRenderer = NULL;
CIMG* CFG::imgSymbolX = NULL;
CIMG* CFG::imgSymbolO = NULL;
CIMG* CFG::imgBg = NULL;
CIMG* CFG::imgPopUp = NULL;

