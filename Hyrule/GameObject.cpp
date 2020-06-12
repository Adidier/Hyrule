#include "GameObject.h"

int GameObject::GetxPos()
{
	return xPos;
}
void GameObject::SetxPos(int xPos)
{
	this->xPos = xPos;
}
int GameObject::GetyPos()
{
	return yPos;
}
void GameObject::SetyPos(int yPos)
{
	this->yPos = yPos;
}

int GameObject::GetxScale()
{
	return xScale;
}
void GameObject::SetxScale(int xScale)
{
	this->xScale = xScale;
}
int GameObject::GetyScale()
{
	return yScale;
}
void GameObject::SetyScale(int yScale)
{
	this->yScale = yScale;
}