#include "Map.h"
#include <iostream>

Map::Map() :
	data{ 0 }
{
}

void Map::draw(SDL_Renderer* renderer)
{
	for (auto x = 0; x < Width; x++)
		for (auto y = 0; y < Height; y++)
		{
			if (data[x][y]!=0)
			{
				switch (data[x][y])
				{
				case 1:
					SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0x00, 0xff);
					break;
				case 2:
					SDL_SetRenderDrawColor(renderer, 0x00, 0xcc, 0x00, 0xff);
					break;
				case 3:
					SDL_SetRenderDrawColor(renderer, 0xcc, 0xcc, 0x00, 0xff);
					break;
				case 4:
					SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x7F, 0xff);
					break;
				case 5:
					SDL_SetRenderDrawColor(renderer, 0xff, 0x7f, 0x00, 0xff);
					break;
				case 6:
					SDL_SetRenderDrawColor(renderer, 0x7f, 0x40, 0x00, 0xff);
					break;
				case 7:
					SDL_SetRenderDrawColor(renderer, 0x00, 0x7f, 0x7f, 0xff);
					break;
				}
				SDL_Rect rect{ (x * 720 / 2 / 10) + 14, (y * 720 / 2 / 10) + 157, 720 / 2 / 10, 720 / 2 / 10 };
				SDL_RenderDrawRect(renderer, &rect);
				SDL_RenderFillRect(renderer, &rect);
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
				SDL_RenderDrawPoint(renderer, (x * (720 / 2 / 10) + 720 / 2 / 10)+14, (y * (720 / 2 / 10) + 720 / 2 / 10)+157);
			}
		}
}

bool Map::isCollision(const Shape& s) const
{
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
		{
			if (s.isBlock(x, y))
			{
				auto wx = s.x() + x;
				auto wy = s.y() + y;
				if (wy >= Height || data[wx][wy])
					return true;
			}
		}
	return false;
}

bool Map::isEdge(const Shape& s, bool isLeft, bool isMove) const
{
	int xl[4]{ Width + 2, Width + 2 , Width + 2 , Width + 2 };
	int xr[4]{ -2, -2, -2, -2};

	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
		{
			if (s.isBlock(x, y))
			{
				auto wx = s.x() + x;
				auto wy = s.y() + y;
				if (xl[y] > wx)
				{
					xl[y] = wx;
				}
				if (xr[y] < wx)
				{
					xr[y] = wx;
				}
			}
		}
	for (int y = 0; y < 4; y++)
	{
		
		if ((xr[y] != -2) && (xl[y] != Width+2) && s.x()+y != -1)
		{
			int left, right;
			if (isMove) {
				left = xl[y] - 1;
				right = xr[y] + 1;
			}
			else {
				left = xl[y];
				right = xr[y];
			}
			if (isLeft && (left < 0 || data[left][y + s.y()]))
			{
				return true;
			}
			if (!isLeft && (right >= Width || data[right][y + s.y()]))
			{
				return true;
			}
		}
	}
	return false;
}


void Map::unite(const Shape& s)
{	
	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 4; y++)
			if (s.isBlock(x, y))
				data[s.x() + x][s.y() + y] = s.getType() + 1;
				
	
	for (int y = Height - 1; y >= 0; y--)
	{
		bool solid = true;
		for (int x = 0; x < Width; x++)
			if (!data[x][y])
			{
				solid = false;
				break;
			}
		if (solid)
		{
			for (int yy = y - 1; yy >= 0; yy--)
				for (int x = 0; x < Width; x++)
					data[x][yy + 1] = data[x][yy];
			for (int x = 0; x < Width; x++)
				data[x][0] = false;
				nb_clear += 1;
				printf(" \n %i", nb_clear);
				
		}
	}

}