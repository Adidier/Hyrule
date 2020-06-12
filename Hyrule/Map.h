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
		stoneWall,
		brickWall,
		door,
		floor,
		water
	};
	Map() {};
	void Init(std::map<int, Tile>, std::string path);
	void Draw();
	int GetType();
private:
	int w;
	int h;
	std::string name; 
	int type; 
	std::vector<Tile> map;
};

