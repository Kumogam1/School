#ifndef _SURFACE_H_
#define _SURFACE_H_

/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/

// STL
#include <string>

/******************************************************************************
 ************************* DEFINE AND CONSTANT SECTION ************************
 ******************************************************************************/

/******************************************************************************
 ***************************** TYPE DEFINITION ********************************
 ******************************************************************************/

/******************************************************************************
 ******************************** CLASS USED **********************************
 ******************************************************************************/

// Graphics library
struct SDL_Surface;

// Project
class Sprite;
class Window;

/******************************************************************************
 ****************************** CLASS DEFINITION ******************************
 ******************************************************************************/

/**
  * @class Surface
  *
  * @brief The Surface class provides interface to the underlying graphics library's surface management.
  */
class Surface
{

	/**************************************************************************
	 ***************************** FRIEND SECTION *****************************
	 **************************************************************************/

	friend class Window;

	/**************************************************************************
	 ***************************** PUBLIC SECTION *****************************
	 **************************************************************************/

public:

	/******************************* ATTRIBUTES *******************************/

	/******************************** METHODS *********************************/

	Surface();
	Surface( const std::string& bmp_file );
	virtual ~Surface();

	void initialize();
	void finalize();

	void load( const std::string& bmp_file );

	void draw( const Sprite& sprite, int x, int y );

	/**************************************************************************
	 **************************** PROTECTED SECTION ***************************
	 **************************************************************************/

protected:

	/******************************* ATTRIBUTES *******************************/

	/**
	 * Graphics library
	 */
	SDL_Surface* surface_;

	/**
	 * Flag to tell whether or not to handle memory management of the underlying graphics library's surface
	 */
	bool manageSurface_;
	
	/******************************** METHODS *********************************/

	/**
	 * Custom constructor
	 */
	Surface( SDL_Surface* surface );

	/**************************************************************************
	 ***************************** PRIVATE SECTION ****************************
	 **************************************************************************/

private:

	/******************************* ATTRIBUTES *******************************/

	/******************************** METHODS *********************************/

};

#endif
