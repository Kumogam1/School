#pragma once
#include <random>
#include <SDL.h>
#include "Map.h"
#include "Shape.h"
#include "Window.h"

class Game
{
public:
	Game();
	~Game();
	bool tick();
	void initialize();
private:
	Game(const Game&);
	Game&operator=(const Game &);
	Window* window_;
	Map map_;
	Shape s_;
	Shape next_;
	uint32_t moveTime_;
	void check(const Shape &s);
	std::default_random_engine generator_;
	std::uniform_int_distribution<int> distribut_;
	const int diff_[15]{48, 43, 38, 33, 28, 23, 18, 13, 8, 6, 5, 4, 3, 2, 1};
	int countLine_;
};

