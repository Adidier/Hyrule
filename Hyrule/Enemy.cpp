#include "Enemy.h"


Enemy::Enemy(int attack, int movePattern, int type, 
	int x, int y, int w, int h, 
	std::string path, int resistance) : Tile()
{
	//Tile::Init(type, x, y, w, h, path, resistance);
	this->attack = attack;
	this->movePattern = movePattern;
}