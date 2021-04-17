#include "window.h"

/******************************************************************************
 ******************************* INCLUDE SECTION ******************************
 ******************************************************************************/

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
,	police_( nullptr )
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
,	background_( nullptr )
,	police_( nullptr )
,	couleur_({ 0, 0, 0 })
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
	TTF_Init();
	police_ = TTF_OpenFont("../res/BAUHS93.ttf", 30);
	if (police_ == nullptr) {
		fprintf(stderr, "Rendering text failed (%s)\n", TTF_GetError());
		return;
	}
}

/******************************************************************************
 * Finalize
 ******************************************************************************/
void Window::finalize()
{
	SDL_DestroyRenderer( renderer_ );
	SDL_DestroyWindow( window_ );
	TTF_CloseFont(police_);
	TTF_Quit();
}

/******************************************************************************
 * update()
 ******************************************************************************/
void Window::update(Map& map, Shape& shape, Shape& next, int score) const
{
	SDL_RenderClear(renderer_);
	SDL_RenderCopy(renderer_, background_, NULL, NULL);
	char buffer[10];
	if (score< 1000000000)
	{
		itoa(score, buffer, 10);
	}
	else
	{
		itoa(999999999, buffer, 10);
	}
	SDL_Surface* texte = TTF_RenderText_Solid(police_, buffer, couleur_);
	SDL_Texture* scores = SDL_CreateTextureFromSurface(renderer_, texte);
	SDL_Rect position; //create a rect
	position.x = 495- ((texte->w)/2);  //controls the rect's x coordinate 
	position.y = 435; // controls the rect's y coordinte
	position.w = texte->w;  //controls the rect's x coordinate 
	position.h = texte->h; // controls the rect's y coordinte
	SDL_RenderCopy(renderer_, scores, NULL, &position);

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
