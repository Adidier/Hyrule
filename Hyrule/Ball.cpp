#include "Ball.h"
Ball::Ball(int _x, int _y, int _w, int _h)
{
	x = _x;
	y = _y;
	w = _w;
	h = _h;
	movientoY = 0;
}
void Ball::Draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_Rect r;
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
	SDL_RenderFillRect(renderer, &r);
}
void Ball::Update()
{
	y = y + movientoY;
	movientoY = movientoY + 0.0001;
}