#ifndef _WINDOW_
#define _WINDOW_

/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/



//class Window
//{
//public:
//	Window();
//
//	void initialize()
//	{
//		// creation fenetre
//		window = SDL_CreateWindow("Arknoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_SHOWN);
//		SDL_Surface* surface_sdl = SDL_GetWindowSurface(window);
//		Surface* surface = new Surface( surface_sdl );
//	}
//
//private:
//	SDL_Window* window;
//	Surface* surface;
//};
//
//class Sprite;

//class Surface
//{
//	friend Window;
//
//public:
//
//	draw( const Sprite& sprite, int x, int y )
//	{
//		//SDL_Rect dstBall = { ball.x, ball.y, 0, 0 };
//		//SDL_BlitSurface( /*source*/plancheSprites, &srcBall,
//		//				/*destination*/surface, &dstBall );
//	}
//	
//private:
//	Surface( SDL_Surface* surface )
//	{
//		surface = surface;
//	}
//
//	SDL_Surface* surface;
//};

//class Sprite
//{
//public:
//
//private:
//	SDL_Rect* sprite;
//}






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
struct SDL_Window;

// Project
class Surface;
class Sprite;

/******************************************************************************
 ****************************** CLASS DEFINITION ******************************
 ******************************************************************************/

/**
  * @class Window
  *
  * @brief The Window class provides interface to the underlying graphics library's window management.
  */
class Window
{

	/**************************************************************************
	 ***************************** PUBLIC SECTION *****************************
	 **************************************************************************/

public:

	/******************************* ATTRIBUTES *******************************/

	/******************************** METHODS *********************************/

	Window();
	Window( const std::string& name, const int w, const int h );
	virtual ~Window();

	inline int width() const;
	inline int height() const;

	void initialize();
	void finalize();

	void draw( const Sprite& sprite, int x, int y );

	void update() const;

	/**************************************************************************
	 **************************** PROTECTED SECTION ***************************
	 **************************************************************************/

protected:

	/******************************* ATTRIBUTES *******************************/

	/**
	 * Graphics library
	 */
	SDL_Window* window_;

	/**
	 * Associated underlying surface
	 */
	Surface* surface_;

	/**
	 * Size 
	 */
	int w_;
	int h_;

	/**
	 * Name
	 */
	std::string title_;

	/******************************** METHODS *********************************/

	/**************************************************************************
	 ***************************** PRIVATE SECTION ****************************
	 **************************************************************************/

private:

	/******************************* ATTRIBUTES *******************************/

	/******************************** METHODS *********************************/

};

/**************************************************************************
 ***************************** INLINE SECTION *****************************
 **************************************************************************/

#include "window.inl"

#endif
