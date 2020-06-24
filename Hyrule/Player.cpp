#include "Player.h"
#include "Platform.h"

void Player::Walk(int x, int y)
{
	xPos += x;
	yPos += y;
}
bool Player::CheckCollision(int x, int y, int typeTile, Map& map)
{
	int temp = GetTileFromMatrix(x, y,0,0, map);
	int temp2 = GetTileFromMatrix(x, y, 15, 15, map);
	int temp3 = GetTileFromMatrix(x, y, 15, 0, map);
	int temp4 = GetTileFromMatrix(x, y, 0, 15, map);
	
	if (temp != typeTile && temp2 != typeTile
		&& temp3 != typeTile && temp4 != typeTile) {
		return false;
	}
	return true;
}
int Player::GetTileFromMatrix(int x, int y, int cornerX,int cornerY, Map& map)
{
	int nextX = (xPos + x + cornerX) / 16;
	int nextY = (yPos + y + cornerY) / 16;
	return map.GetTypeTileByPositon(nextX, nextY);
}
void Player::Attack()
{

}
void Player::Run()
{

}
void Player::TakeItem()
{

}
int	Player::GetHealth()
{
	return 0;
}
void Player::SetHealth(int h)
{

}

int Player::GetW()
{
	return 16;
}

int Player::GetH()
{
	return 16;//adidier regresa
}

void Player::Init(std::string pathImage)
{
	img = new Image();
	img->LoadImage(pathImage);
}

void Player::Draw()
{
	Platform::GetPtr()->RenderTexture(img, xPos, yPos);
}

Player::Player(int positionX, int positionY)
{
	xPos = positionX;
	yPos = positionY;
}