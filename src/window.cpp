#include "window.h"

/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/

// Graphics library
#include <SDL.h>

// Project

/******************************************************************************
 ****************************** NAMESPACE SECTION *****************************
 ******************************************************************************/

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
 * Default constructor
 ******************************************************************************/
Window::Window()
:	window_( nullptr )
,	renderer_( nullptr )
,	background_( nullptr )
,	w_( 200 )
,	h_( 200 )
,	title_( "NoName" )
{
}

/******************************************************************************
 * Constructor
 ******************************************************************************/
Window::Window( const std::string& name, int w, int h )
:	window_( nullptr )
,	renderer_( nullptr )
,	w_( w )
,	h_( h )
,	title_( name )
{
}

/******************************************************************************
 * Destructor
 ******************************************************************************/
Window::~Window()
{
	finalize();
}

/******************************************************************************
 * Initialize
 ******************************************************************************/
void Window::initialize()
{
	window_ = SDL_CreateWindow(title_.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w_, h_, SDL_WINDOW_SHOWN);
	renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_Surface* image = SDL_LoadBMP("../res/tetris.bmp");
	background_ = SDL_CreateTextureFromSurface(renderer_, image);
	SDL_FreeSurface(image);
}

/******************************************************************************
 * Finalize
 ******************************************************************************/
void Window::finalize()
{
	SDL_DestroyRenderer( renderer_ );
	SDL_DestroyWindow( window_ );
}

/******************************************************************************
 * draw()
 ******************************************************************************/
void Window::draw( const Sprite& sprite, int x, int y )
{
	
}

/******************************************************************************
 * update()
 ******************************************************************************/
void Window::update(Map& map, Shape& shape, Shape& next) const
{
	SDL_RenderClear(renderer_);
	SDL_RenderCopy(renderer_, background_, NULL, NULL);
	SDL_RenderPresent(renderer_);
	map.draw(renderer_);
	shape.draw(renderer_);
	next.drawNext(renderer_);
	SDL_RenderPresent(renderer_);
}

void Window::game_over() 
{	// image à changer plus tard 
	SDL_Surface* image = SDL_LoadBMP("../res/game_over.bmp");
	background_ = SDL_CreateTextureFromSurface(renderer_, image);
	SDL_FreeSurface(image);
	SDL_RenderCopy(renderer_, background_, NULL, NULL);
	SDL_RenderPresent(renderer_);
}
