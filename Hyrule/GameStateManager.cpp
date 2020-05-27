#include "GameStateManager.h"
#include "Platform.h"

void GameStateManager::SetState(GameState* state)
{
	state->Init();
	gamestates.push(state);
}

void GameStateManager::ReleaseState()
{
	gamestates.pop();
}

void GameStateManager::GameLoop()
{
	bool closeApp = false;
	while (!closeApp)
	{
		if (gamestates.size() == 0)
		{
			break;
		}
		plat->Input(closeApp);
		gamestates.top()->Input(0);
		gamestates.top()->Update();
		plat->RenderClear();
		gamestates.top()->Draw();
		plat->RenderPresent();
	}
}

GameStateManager::GameStateManager()
{
	plat = Platform::GetPtr();
	plat->Init(640,480);
}

GameStateManager::~GameStateManager()
{
	plat->Close();
}