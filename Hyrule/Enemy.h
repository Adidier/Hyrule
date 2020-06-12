#pragma once
#include "Tile.h"
class Enemy : public Tile
{
public:
	int attack;
	int movePattern;

	Enemy(int attack,int movePattern,int type, int x, int y, int w, int h, std::string path, int resistance = 1);
};

