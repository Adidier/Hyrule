#include "SpiderBlue.h"

SpiderBlue::SpiderBlue(Tile t) : Enemy(t)
{

}

void SpiderBlue::Update()
{
	if (tile.GetyPos() + dir < yPosInit + maxMove && dir>0)
	{
		tile.SetyPos(tile.GetyPos() + 1);
		return;
	}
	else
	{
		dir = -1;
	}

	if (tile.GetyPos() + dir > yPosInit - maxMove && dir < 0)
	{
		tile.SetyPos(tile.GetyPos() - 1);
		return;
	}
	else
	{
		dir = 1;
	}
}