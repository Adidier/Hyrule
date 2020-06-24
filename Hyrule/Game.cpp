#include "Game.h"
#include <iostream>
#include <map>
#include "stdlib.h"
#include "time.h"
#include "SpiderBlue.h"
#include "SpiderRed.h"
void Game::Init()
{
	srand(time(NULL));
	p1 = new Player(17,17);
	p1->Init("../Hyrule/Assets/Player1/Player1.png");
	std::map<int, Tile > tilemap;
	tilemap[1].Init(Map::floor, 16, 16, "../Hyrule/Assets/Map/floor.png", -1);
	tilemap[2].Init(Map::stoneWall, 16, 16, "../Hyrule/Assets/Map/StoneWall.png", 50);
	tilemap[3].Init(Map::brickWall, 16, 16, "../Hyrule/Assets/Map/BrickStone.png", 10);
	tilemap[4].Init(Map::water, 16, 16, "../Hyrule/Assets/Map/Water.png", 1);
	tilemap[5].Init(Map::TEST, 16, 16, "../Hyrule/Assets/Map/BrickStone.png", 10);
	initMap.Init(tilemap, "../Hyrule/Assets/Map/map1.txt");

	std::map<int, Tile > tileItems;
	tileItems[0].Init(Map::free, 16, 16, "", 0);
	tileItems[1].Init(Map::spider1, 16, 16, "../Hyrule/Assets/Enemy1/enemy.png", 50);
	tileItems[2].Init(Map::spider2, 16, 16, "../Hyrule/Assets/Enemy2/enemy2.png", 50);

	initMapItems.Init(tileItems, "../Hyrule/Assets/Map/map1_Items.txt");
	auto spiders1Enemies = initMapItems.GetTilesType(Map::spider1);
	auto spiders2Enemies(initMapItems.GetTilesType(Map::spider2));
	for (auto spider : spiders1Enemies)
	{
		enemies.push_back(new SpiderRed(spider));
	}
	for (auto spider : spiders2Enemies)
	{
		enemies.push_back(new SpiderBlue(spider));
	}
}

void Game::Draw()
{
	initMap.Draw();
	
	for (auto spider : enemies)
	{
		spider->Draw();
	}
	p1->Draw();
	std::cout << "estoy en Draw de game " << std::endl;
}

void Game::Close()
{

}

bool Game::Impact(int x,int y, int w,int h, int x1, int y1, int w1, int h1)
{
	if ( x <= x1 && x1 <= x + w 
		&& y + h >= y1 && y <= y1 )
		return true;
	else
		return false;
}

void Game::Update()
{
	for (auto spider : enemies)
	{
		spider->Update();
		
		bool ar = Impact(p1->GetxPos(), p1->GetyPos(), p1->GetW(), p1->GetH(), spider->GetxPos(), spider->GetyPos(), 16,16);
	}
}

bool Game::Input(int key)
{
	if (key == 'a' && !p1->CheckCollision(-1,0, Map::Tiles::stoneWall, initMap))
	{
		p1->Walk(-1, 0);
	}
	else if (key == 'd' && !p1->CheckCollision(1, 0, Map::Tiles::stoneWall, initMap))
	{
		p1->Walk(1, 0);
	}
	
	if (key == 'w' && !p1->CheckCollision(0, -1, Map::Tiles::stoneWall, initMap))
	{
		p1->Walk(0, -1);
	}
	else if (key == 's' && !p1->CheckCollision(0, 1, Map::Tiles::stoneWall, initMap))
	{
		p1->Walk(0, 1);
	}
	std::cout << "estoy en Input de game" << std::endl;
	return true;
}
