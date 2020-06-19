#include "Map.h"
#include<iostream>

void Map::Init(std::map<int, Tile> tiles,std::string path)
{
	this->name = path;
	std::ifstream file(path);
	std::string line;
	std::vector<std::string> numberTile;
	while (std::getline(file, line, ',')) {
		numberTile.push_back(line);
	}

	w=stoi(numberTile[0]);
	h=stoi(numberTile[1]);
		
	for (int i = 2; i < numberTile.size(); i++)
	{
		int typeinFile = stoi(numberTile[i]);

		auto tile = tiles[typeinFile];
		map.push_back(tile);
	}

	int x = 0;
	int y = 0;
	for (auto &element : map)
	{

		if (element.GetType() != 0)
		{
			element.SetxPos(x * element.GetxScale());
			element.SetyPos(y * element.GetyScale());
		}

		if (x > w - 2)
		{
			x = 0;
			y++;
		}
		else
		{
			x++;
		}
	}
}

std::vector<Tile>  Map::GetTilesType(int type)
{
	std::vector<Tile> tiles;
	for (auto tile : map)
	{
		if (tile.GetType() == type)
		{
			tiles.push_back(tile);
		}
	}
	return tiles;
}

int Map::GetType()
{
	return type;
}

int Map::GetTypeTileByPositon(int x, int y)
{
	int vectorPosition = y * w + x;
	int type = map[vectorPosition - 1].GetType();
	return type;

}

void Map::Draw()
{
	for (auto element : map)
	{
		element.Draw();
	}
}