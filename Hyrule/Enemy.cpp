#include "Enemy.h"


Enemy::Enemy(Tile t)
{
	tile = t;
	xPosInit = tile.GetxPos();
	yPosInit = tile.GetyPos();
	dir = rand() %10;
	if (dir > 5)
	{
		dir = 1;
	}
	else
	{
		dir -= 1;
	}
}

void Enemy::Draw()
{
	tile.Draw();
}

void Enemy::Update()
{
	if (tile.GetxPos() + dir < xPosInit + maxMove && dir>0)
	{
		tile.SetxPos(tile.GetxPos() + 1);
		return;
	}
	else
	{
		dir = -1;
	}

	if (tile.GetxPos() + dir > xPosInit - maxMove && dir < 0)
	{
		tile.SetxPos(tile.GetxPos() - 1);
		return;
	}
	else
	{
		dir = 1;
	}
}

int Enemy::GetxPos()
{
	return xPosInit;
}

int Enemy::GetyPos()
{
	return yPosInit;
}

