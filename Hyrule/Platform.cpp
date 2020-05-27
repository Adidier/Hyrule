#include "Platform.h"

Platform* Platform::ptr;

Platform::Platform()
{

}

Platform* Platform::GetPtr()
{
	if (ptr == nullptr)
	{
		ptr = new Platform();
	}
	return ptr;
}

bool Platform::Init(int width, int heigth)
{
	//Initialization flag
	bool success = true;
	this->width = width;
	this->heigth = heigth;
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
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, heigth, SDL_WINDOW_SHOWN);
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
				SDL_SetRenderDrawColor(gRenderer, 0x64, 0x6F, 0xCE, 0xFF);


			}
		}
	}

	return success;
}

void Platform::Close()
{
	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;
	SDL_Quit();
}

void Platform::RenderClear()
{
	SDL_SetRenderDrawColor(gRenderer, 0x64, 0x6F, 0xCE, 0xFF);
	SDL_RenderClear(gRenderer);
}

void Platform::RenderPresent()
{
	SDL_RenderPresent(gRenderer);
}

void Platform::Input(bool& quit)
{
	SDL_Event e;
	//Handle events on queue
	while (SDL_PollEvent(&e) != 0)
	{
		//User requests quit
		if (e.type == SDL_QUIT)
		{
			quit = true;
		}
	}
}