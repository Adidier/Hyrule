#pragma once
class GameState
{
public:
	virtual void Init() = 0;
	virtual void Draw() = 0;
	virtual void Update() = 0;
	virtual bool Input(int key) = 0;
	virtual void Close() = 0;
};

