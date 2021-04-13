// Include class definition
#include "GameCore.h"

// Graphics library
#include <SDL.h>

using namespace Core;

//bool GameCore::_isInitialized = false;

GameCore::GameCore()
{
}

bool GameCore::initialize()
{
	// Initialize graphics library
	if ( SDL_Init( SDL_INIT_VIDEO ) == 0 )
	{
		return false;
	}

	// Initialize Audio library
	// ...

	// Network library initialization
	// ...

	//_isInitialized = true;

	return true;
}

bool GameCore::finalize()
{
	// Finalize graphics library
	SDL_Quit();

	// Initialize Audio library
	// ...

	// Network library initialization
	// ...

	//_isInitialized = false;

	return true;
}
