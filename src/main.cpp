/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/

//// Graphics library
//#include <SDL.h>

// Project
#include "game.h"

// STL
#include <vector>
#include <string>
#include <map>
#include <numeric> // iota
#include <iostream>
#include <algorithm> // minmax_element
#include <random>
#include <functional> // bind

#include <list>

#include "GameCore.h"
#include "SceneManager.h"

/******************************************************************************
 ****************************** NAMESPACE SECTION *****************************
 ******************************************************************************/

using namespace Core;
using namespace Graphics;

/******************************************************************************
 ************************* DEFINE AND CONSTANT SECTION ************************
 ******************************************************************************/

/******************************************************************************
 ***************************** TYPE DEFINITION ********************************
 ******************************************************************************/

/******************************************************************************
 ***************************** METHOD DEFINITION ******************************
 ******************************************************************************/

/******************************************************************************
 * Main entry program
 *
 * @param argc Number of arguments
 * @param argv List of arguments
 *
 * @return flag telling whether or not it succeeds
 ******************************************************************************/
int main( int argc, char** argv )
{
	// Initialize library
	GameCore::initialize();

	//SceneManager::get().addGraphicsObject(  );

	// Game management
	Game* game = new Game();
	// - initialization
	game->initialize();
	// - main event loop
	game->loop();
	// - finalization
	game->finalize();
	delete game;
	game = nullptr;

	// Finalize library
	GameCore::finalize();

	return 0;
}
