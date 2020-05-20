#include "Block.h"


void Block::SetPosition(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Block::SetSize(int _w, int _h)
{
	w = _w;
	h = _h;
}
void Block::SetColor(int _r, int _g, int _b)
{
	r = _r;
	g = _g;
	b = _b;
}

void Block::Draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, 0xFF);
	SDL_Rect r;
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
	SDL_RenderFillRect(renderer, &r);
}

void Block::Update()
{

}