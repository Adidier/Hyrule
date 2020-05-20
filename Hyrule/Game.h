#pragma once
#include "GameState.h"
class Game :
	public GameState
{
	void Init() override;
	void Draw() override;
	void Update() override;
	void Input(int key) override;
	void Close() override;
};

