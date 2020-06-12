#include "Game.h"
#include <iostream>
#include <map>

void Game::Init()
{
	p1 = new Player(100,100);
	p1->Init("../Hyrule/Assets/Player1/Player1.png");
	std::map<int, Tile > tilemap;
	tilemap[1].Init(Map::floor, 16, 16, "../Hyrule/Assets/Map/floor.png", -1);
	tilemap[2].Init(Map::stoneWall, 16, 16, "../Hyrule/Assets/Map/StoneWall.png", 50);
	tilemap[3].Init(Map::brickWall, 16, 16, "../Hyrule/Assets/Map/BrickStone.png", 10);
	tilemap[4].Init(Map::water, 16, 16, "../Hyrule/Assets/Map/Water.png", 1);
	initMap.Init(tilemap, "../Hyrule/Assets/Map/map1.txt");

	std::map<int, Tile > tileItems;
	tileItems[0].Init(Map::free, 16, 16, "", 0);
	tileItems[1].Init(Map::floor, 16, 16, "../Hyrule/Assets/Player1/Player1.png", -1);
	tileItems[2].Init(Map::stoneWall, 16, 16, "../Hyrule/Assets/Enemy1/enemy.png", 50);

	initMapItems.Init(tileItems, "../Hyrule/Assets/Map/map1_Items.txt");
}

void Game::Draw()
{
	initMap.Draw();
	initMapItems.Draw();

	p1->Draw();
	std::cout << "estoy en Draw de game " << std::endl;
}

void Game::Close()
{

}

void Game::Update()
{
	std::cout << "estoy en Update de game" << std::endl;
}
bool Game::Input(int key)
{
	if (key == 'a')
	{
		p1->Walk(-1, 0);
	}
	else if (key == 'd')
	{
		p1->Walk(1, 0);
	}
	
	if (key == 'w')
	{
		p1->Walk(0, -1);
	}
	else if (key == 's')
	{
		p1->Walk(0, 1);
	}
	std::cout << "estoy en Input de game" << std::endl;
	return true;
}
