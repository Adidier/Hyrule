#include "Tile.h"
#include "Platform.h"
Tile::Tile()
{

}

void Tile::Init(int type, int w, int h, std::string path, int resistance)
{
	img.LoadImage(path); //adidier
	this->type = type;
	this->resistance = resistance;
	xScale = w;
	yScale = h;
}

void Tile::Draw()
{
	//if (resistance > 0)
	{
		Platform::GetPtr()->RenderTexture(&img, xPos, yPos);
	}
}

void Tile::GetDamage(int damage)
{
	resistance = resistance -damage;
}