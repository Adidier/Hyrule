// Arkanoid.cpp : Este archivo contiene la funci�n "main". La ejecuci�n del programa comienza y termina ah�.
//

#include <iostream>
//Using SDL, SDL_image, standard IO, math, and strings
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "GameStateManager.h"
#include "GameState.h"
#include "Menu.h"
#include "Game.h"
#include "Platform.h"
#include <iostream>

int main(int argc, char* args[])
{
	GameStateManager manager;
	GameState* game = new Game();
	manager.SetState(game);
	manager.GameLoop();
	return 0;
}
	