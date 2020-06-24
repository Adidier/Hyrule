#pragma once
#include <string>
#include <vector>
#include "Tile.h"
#include <fstream>
#include <map>
class Map
{
public:
	enum Tiles
	{
		free,
		floor,
		stoneWall,
		brickWall,
		TEST,
		door,		
		water,
		spider1,
		spider2,
	};
	Map() {};
	void Init(std::map<int, Tile>, std::string path);
	int GetTypeTileByPositon(int x, int y);
	std::vector<Tile> GetTilesType(int type);
	void Draw();
	int GetType();
private:
	int w;
	int h;
	std::string name; 
	int type; 
	std::vector<Tile> map;
};

