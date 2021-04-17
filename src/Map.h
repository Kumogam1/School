#pragma once
#include "Shape.h"
#include <SDL.h>

class Map
{
public:
	Map();
	void draw(SDL_Renderer *);
	enum {Width = 10, Height = 20};
	bool isCollision(const Shape& s) const;
	bool isEdge(const Shape& s, bool isLeft, bool isMove) const;
	void unite(const Shape& s);
	int Map::lineFull();
private:
	int data[Width][Height];
};

