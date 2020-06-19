#pragma once
#include "Tile.h"
class Enemy 
{
protected:
	Tile tile;
	int attack;
	int movePattern;
	int xPosInit;
	int yPosInit;
	const int maxMove{ 20 };
	int dir;
public:
	Enemy(Tile t);
	void Draw();
	virtual void Update();
};

