#include <SDL.h>
#include <iostream>

#include "Game.h"
#include "GameCore.h"

using namespace Core;

int main(int argc, char** argv)
{
	GameCore::initialize();
	Game game;
	game.initialize();
	while (game.tick());
	printf("aaaaaaaaa");
	GameCore::finalize();
	printf("bbbbbbbbbbbb");
	return 0;
}

