#ifndef _GAME_H_
#define _GAME_H_

/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/

// STL
#include <cstdint>
#include <vector>
#include <list>

// Project
#include "ball.h"
#include "GraphicsObject.h"

/******************************************************************************
 ************************* DEFINE AND CONSTANT SECTION ************************
 ******************************************************************************/

/******************************************************************************
 ***************************** TYPE DEFINITION ********************************
 ******************************************************************************/

/******************************************************************************
 ******************************** CLASS USED **********************************
 ******************************************************************************/

// Project
class Window;
class Surface;
class Sprite;

/******************************************************************************
 ****************************** CLASS DEFINITION ******************************
 ******************************************************************************/

/**
  * @class Game
  *
  * @brief The Game class provides interface to the game management.
  */
class Game
{

	/**************************************************************************
	 ***************************** PUBLIC SECTION *****************************
	 **************************************************************************/

public:

	/******************************* ATTRIBUTES *******************************/

	/******************************** METHODS *********************************/

	Game();
	virtual ~Game();

	void initialize();
	void finalize();

	void loop();

	
	int frameID = 1;

	/**************************************************************************
	 **************************** PROTECTED SECTION ***************************
	 **************************************************************************/

protected:

	/******************************* ATTRIBUTES *******************************/

	/**
	 * Graphics window
	 */
	Window* window_;

	/******************************** METHODS *********************************/

	/**
	 * Render
	 */
	void draw( double dt );

	/**
	 * Keyboard management
	 */
	void keyboard( const std::uint8_t* keys );

	/**************************************************************************
	 ***************************** PRIVATE SECTION ****************************
	 **************************************************************************/

private:

	/******************************* ATTRIBUTES *******************************/

	/**
	 * World associated graphics data
	 */
	Surface* planche_;
	//Graphics::GraphicsObject* currentobj_;
	std::vector< Graphics::GraphicsObject* > graphicsObjects;
	std::vector< Sprite* > sprites_;
	
	/**
	 * Game data (balls, etc...)
	 */
	std::vector< Ball > balls_;

	/**
	 * Grid map of presence
	 */
	//std::vector< std::vector< bool > > presenceMap_;
	std::list< std::vector< bool > > presenceMap_;
	std::uint8_t grid_nbRows_;
	std::uint8_t grid_nbColumns_;
	std::uint8_t grid_tileSize_;

	/******************************** METHODS *********************************/

	/**
	 * Draw background map
	 */
	void drawMap();

};

#endif
