#pragma once
#include "GameObject.h"
#include "SDL.h"
class Block : public GameObject
{
	private:
		int r, g, b;
	public:
		void SetPosition(int _x, int _y);
		void SetSize(int _w, int _h);
		void SetColor(int _r, int _g, int _b);
		void Draw(SDL_Renderer* renderer);
		void Update();
};

