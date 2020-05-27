#include "Game.h"
#include <iostream>

void Game::Init()
{

}

void Game::Draw()
{
	std::cout << "estoy en Draw de game" << std::endl;
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
