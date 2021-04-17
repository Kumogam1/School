#include "Game.h"
#include <stdexcept>

Game::Game() :
	distribut_(0,6)
,	moveTime_(SDL_GetTicks())
,	window_(nullptr)
,	countLine_(0)
,	score_(0)
{
}

Game::~Game()
{
	SDL_Quit();
}

void Game::initialize() {
	window_ = new Window("Tetris", 600, 900);
	window_->initialize();
	s_ = Shape{ static_cast<Shape::Type>(distribut_(generator_)) };
	next_ = Shape{ static_cast<Shape::Type>(distribut_(generator_)) };
}

bool Game::tick()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_KEYDOWN:
			switch (e.key.keysym.sym)
			{
			case SDLK_DOWN: 
				{
					Shape s = s_;
					s.move(0, 1);
					check(s);
				}
				break;
			
			case SDLK_RIGHT: 
				{
					Shape s = s_;
					if(!map_.isEdge(s, false, true)){
						s.move(1, 0);
					}
					check(s);
				}
				break;
			
			case SDLK_LEFT:
				{
					Shape s = s_;
					if(!map_.isEdge(s, true, true)){
						s.move(-1, 0);
					}
					check(s);
				}
				break;

			case SDLK_UP:
				{
					Shape s = s_;
					s.rotate();
					int i = 0;
					//a modifier problème existant
					while (map_.isEdge(s, true, false))
					{
						s.move(1, 0);
					}
					while (map_.isEdge(s, false, false))
					{
						s.move(-1, 0);
					}
					check(s);
				}
				break;
			case SDLK_SPACE:
				while (!map_.isCollision(s_))
				{
					s_.move(0, 1);
				}
				s_.move(0, -1);
				map_.unite(s_);
				int line = map_.lineFull();
				if (line != 0) {
					addScore(line);
					countLine_ += line;
				}
				s_ = next_;
				next_ = Shape{ static_cast<Shape::Type>(distribut_(generator_)) };
				break;
			}
			break;
		case SDL_QUIT:
			window_->finalize();
			return false;
		}
	}

	
	window_->update(map_, s_, next_, score_);

	if (SDL_GetTicks() > moveTime_)
	{
		int vit;
		if (int(countLine_ / 10) < 10)
		{
			vit = int(countLine_ / 10);
		}
		else if (int(countLine_ / 10) < 13) {
			vit = 10;
		}
		else if (int(countLine_ / 10) < 16)
		{
			vit = 11;
		}
		else if (int(countLine_ / 10) < 19)
		{
			vit = 12;
		}
		else if (int(countLine_ / 10) < 28)
		{
			vit = 13;
		}
		else
		{
			vit = 14;
		}
		moveTime_ += (diff_[vit]*1000)/60;
		Shape cshape = s_;
		cshape.move(0, 1);
		check(cshape);
		
	}

	return true;
};

void Game::check(const Shape& s)
{
	if (map_.isCollision(s))
	{
		map_.unite(s_);
		int line = map_.lineFull();
		if (line != 0) {
			addScore(line);
			countLine_ += line;
		}
		s_ = next_;
		next_ = Shape{ static_cast<Shape::Type>(distribut_(generator_)) };
		if (map_.isCollision(s_))
		{
			window_->game_over();

			SDL_Event e;
			while (SDL_PollEvent(&e))
			{
				switch (e.type)
				{
				case SDL_KEYDOWN:
					switch (e.key.keysym.sym)
					{
					case SDLK_SPACE:
					{
						// lance nouvelle game
					}
					break;

					case SDLK_RETURN:
					{
						SDL_Quit();
						printf("return");
					}
					break;
					}
				}

			}
		}
	}

	else
	{
		s_ = s;
	}
}

void Game::addScore(int line) {
	switch (line)
	{
	case 1:
	{
		score_ += 40 * ((countLine_ / 10) + 1);
	}
	break;
	case 2:
	{
		score_ += 100 * ((countLine_ / 10) + 1);
	}
	break;
	case 3:
	{
		score_ += 300 * ((countLine_ / 10) + 1);
	}
	break;
	case 4:
	{
		score_ += 1200 * ((countLine_ / 10) + 1);
	}
	break;
	default:
		break;
	}
}