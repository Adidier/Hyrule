#include "Game.h"
#include <iostream>

void Game::Init()
{
	p1 = new Player();
	p1->Init("../Hyrule/Assets/Player1/Player1.png");
}

void Game::Draw()
{
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
void Game::Input(int key)
{
	std::cout << "estoy en Input de game" << std::endl;
}
