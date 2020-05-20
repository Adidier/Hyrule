#include "Player.h"


Player::Player(int _x, int _y, int _w, int _h)
{
	x = _x;
	y = _y;
	w = _w;
	h = _h;
}

void Player::Input(int dir)
{
	x = x + dir;
}

void Player::Draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0x17, 0xE8, 0x22, 0xFF);
	SDL_Rect r;
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
	SDL_RenderFillRect(renderer, &r);
}

void Player::Update()
{

}