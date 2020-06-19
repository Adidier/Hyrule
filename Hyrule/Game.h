#pragma once
#include "GameState.h"
#include "Player.h"
#include "Enemy.h"
#include "Map.h"

class Game : public GameState
{
private:
	Player *p1;
	Map initMap;
	Map initMapItems;
	std::vector<Enemy *> enemies;
public:
	Game() {};
	void Init() override;
	void Draw() override;
	void Update() override;
	bool Input(int key) override;
	void Close() override;
};

