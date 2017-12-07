#include "Game.h"
#include "Event.h"
#include "CFG.h"

Game* g_gameObject = NULL;
Event* g_eventHandler = NULL;


int main(int argc, char* args[])
{
	//Start up SDL and create window
	if( !CFG::Init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
		if( !CFG::LoadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {			
			g_eventHandler = new Event();
			g_gameObject = new Game();		
	
			while(!CFG::bQuit)
			{
				SDL_PollEvent(CFG::sdlMainEvent);
				g_gameObject->HandleInput(g_eventHandler->HandleInput(CFG::sdlMainEvent));
				SDL_RenderClear(CFG::sdlRenderer);
				g_gameObject->Draw(CFG::sdlRenderer);
				SDL_RenderPresent(CFG::sdlRenderer);
			}
			
			
        }
    }

    //Free resources and Close SDL
	CFG::Close();

    return 0;
}
