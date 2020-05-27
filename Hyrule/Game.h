#pragma once
#include "GameState.h"
#include "Player.h"

class Game : public GameState
{
private:
	Player *p1;
public:
	void Init() override;
	void Draw() override;
	void Update() override;
	void Input(int key) override;
	void Close() override;
};

