#pragma once
#include "GameState.h"
class Menu : public GameState
{
public:
	void Init() override;
	void Draw() override;
	void Update() override;
	void Input(int key) override;
	void Close() override;
};

