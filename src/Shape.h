#pragma once
#include <SDL.h>

class Shape
{
public:
	enum Type { I=0, J, L, O, S, T, Z };
	Shape();
	Shape(Type);
	void draw(SDL_Renderer*);
	void drawNext(SDL_Renderer*);
	void move(int dx, int dy);
	void rotate();
	bool isBlock(int x, int y) const;
	int getType() const;
	int x() const;
	int y() const;
private:
	Type type_;
	int x_;
	int y_;
	int	rotation_; 
};