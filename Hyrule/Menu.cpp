#include "Menu.h"
#include <iostream>

void Menu::Init()
{

}

void Menu::Draw()
{
	std::cout << "estoy en Draw de menu" << std::endl;
}

void Menu::Close()
{

}

void Menu::Update()
{
	std::cout << "estoy en Update de menu" << std::endl;
}

void Menu::Input(int key)
{
	std::cout << "estoy en input de menu"<<std::endl;
}