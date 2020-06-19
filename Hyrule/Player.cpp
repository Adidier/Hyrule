#include "Player.h"
#include "Platform.h"

void Player::Walk(int x, int y)
{
	xPos += x;
	yPos += y;
}
bool Player::CheckCollision(int x, int y, Map& map)
{

	int nextX = (xPos + x)/16;
	int nextY = (yPos + y)/16;
	int temp = map.GetTypeTileByPositon(nextX, nextY);

	if (temp != Map::Tiles::stoneWall) {
		return false;
	}
	return true;
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