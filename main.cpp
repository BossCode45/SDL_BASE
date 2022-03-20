#include <SDL2/SDL.h>
#include <iostream>
#include <math.h>

#include "ExampleAnim.h"
#include "SDL2/SDL_events.h"
#include "SDL2/SDL_render.h"

using namespace std;

bool init();
void close();
void mainLoop();

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 960;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Event e;

ExampleAnim img;

bool init()
{
	if( SDL_Init( SDL_INIT_VIDEO ) < 0)
	{
		printf("SDL couldn't init, error: %s\n",  SDL_GetError());
		return(false);
	}
	else
	{
		gWindow = SDL_CreateWindow("SDL_BASE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(gWindow == NULL)
		{
			printf("Window can't be created, error: %s\n", SDL_GetError());
			return(false);
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if(gRenderer == NULL)
			{
				printf("Renderer can't be created! error%s\n", SDL_GetError());
				return(false);
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);

				img.init(gRenderer);
			}
		}
	}
	return(true);
}

void close()
{
	img.free();

	
	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}

void mainLoop()
{
	float deltaTime = 0;
	Uint64 start = SDL_GetPerformanceCounter();
	Uint64 end = SDL_GetPerformanceCounter();
	while(true)
	{
		while(SDL_PollEvent(&e)!=0)
		{
			switch(e.type)
			{
				case SDL_KEYDOWN:
					if(img.getAnim() == ExampleAnim::idle)
					{
						img.swapAnim(ExampleAnim::levelUp);
					}
					else
					{
						img.swapAnim(ExampleAnim::idle);
					}
					break;

				case SDL_QUIT:
					return;
			}
		}
		SDL_Rect rect = {0, 0, SCREEN_WIDTH, SCREEN_WIDTH};
		SDL_RenderFillRect(gRenderer, &rect);

		img.draw(gRenderer, 0, 0, deltaTime);

		SDL_RenderPresent(gRenderer);

		
		end = SDL_GetPerformanceCounter();
		deltaTime = (end-start) / (float) SDL_GetPerformanceFrequency();
		start = SDL_GetPerformanceCounter();
		deltaTime *= 1000;
		Uint32 delay = floor(5.0f - deltaTime);
		SDL_Delay((delay < 5? delay : 5));
	}
}

int main(int argc, char* argv[])
{
	if(!init())
	{
		printf("Couldn't init");
	}
	else
	{
		SDL_RenderClear(gRenderer);

		mainLoop();
	}
	close();
	return 0;
}
