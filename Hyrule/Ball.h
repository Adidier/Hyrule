#pragma once
#include "GameObject.h"
#include "SDL.h"
class Ball : public GameObject
{
	float movientoY;
	public:
		Ball(int _x, int _y, int _w, int _h);
		void Draw(SDL_Renderer* renderer);
		void Update();
};

