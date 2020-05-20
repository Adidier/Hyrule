// Arkanoid.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
//Using SDL, SDL_image, standard IO, math, and strings
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "Player.h"
#include "Ball.h"
#include "Block.h"


//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();


//Frees media and shuts down SDL
void close();

void GameLoop(bool& quit, SDL_Event& e);

void Input(SDL_Event& e, bool& quit);

void Render();

void Update();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);


			}
		}
	}

	return success;
}


void close()
{
	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;


	SDL_Quit();
}

Player player1(300, 420, 100, 50);
Ball ball(310, 210, 20, 20);

Block blocksLine1[12];
Block blocksLine2[12];
Block blocksLine3[12];


int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;

		for(int i=0;i<12;i++)
		{ 
			blocksLine1[i].SetPosition(i * 51 +10, 50);
			blocksLine1[i].SetSize(50, 30);
			blocksLine1[i].SetColor(rand() % 255, rand() % 255, rand() % 255);
		}

		for (int i = 0; i < 12; i++)
		{
			blocksLine2[i].SetPosition(i * 51 + 10, 85);
			blocksLine2[i].SetSize(50, 30);
			blocksLine2[i].SetColor(rand() % 255, rand() % 255, rand() % 255);
		}

		for (int i = 0; i < 12; i++)
		{
			blocksLine3[i].SetPosition(i * 51 + 10, 120);
			blocksLine3[i].SetSize(50, 30);
			blocksLine3[i].SetColor(rand() % 255, rand() % 255, rand() % 255);
		}
		
		GameLoop(quit, e);

	}

	//Free resources and close SDL
	close();

	return 0;
}

void GameLoop(bool& quit, SDL_Event& e)
{
	//While application is running
	while (!quit)
	{
		Input(e, quit);
		Update();
		Render();
	}
}
void Update()
{
	ball.Update();
}

void Input(SDL_Event& e, bool& quit)
{
	//Handle events on queue
	while (SDL_PollEvent(&e) != 0)
	{
		//User requests quit
		if (e.type == SDL_QUIT)
		{
			quit = true;
		}
		if (e.type == SDL_KEYDOWN) {
			switch (e.key.keysym.sym)
			{
				case SDLK_LEFT:
					player1.Input(-1);
				break;

				case SDLK_RIGHT:
					player1.Input(1);
				break;
			}

		}
	}
}

void Render()
{
	//Clear screen
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(gRenderer);

	player1.Draw(gRenderer);
	ball.Draw(gRenderer);
	for (int i = 0; i < 12; i++)
	{
		blocksLine1[i].Draw(gRenderer);
	}

	for (int i = 0; i < 12; i++)
	{
		blocksLine2[i].Draw(gRenderer);
	}

	for (int i = 0; i < 12; i++)
	{
		blocksLine3[i].Draw(gRenderer);
	}

	//Update screen
	SDL_RenderPresent(gRenderer);
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
