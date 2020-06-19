#pragma once
#include "Enemy.h"
class SpiderBlue :
	public Enemy
{
	public:
		SpiderBlue(Tile t);
		void Update() override;
};

