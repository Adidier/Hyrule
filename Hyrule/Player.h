#pragma once
#include "GameObject.h"
#include "SDL.h"
class Player :	public GameObject
{
	public:
		Player(int _x, int _y, int _w, int _h);
		void Input(int dir);
		void Draw(SDL_Renderer* renderer);
		void Update();
};

