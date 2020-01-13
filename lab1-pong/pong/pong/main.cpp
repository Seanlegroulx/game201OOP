/* 
Sean Legroulx
Game 202
Majid Moghadam
Pong
1/12/2020


*/

#include "sdl.h"

#define WINDOW_WIDTH  800
#define WINDOW_HIGHT  600


SDL_Renderer *renderer;

bool running = true;


SDL_Rect playerpaddle;
SDL_Rect AIpaddle;
SDL_Rect Ball;

void LoadGame()
{
	SDL_Window *window;

	window = SDL_CreateWindow("Basic SDL Sprites",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HIGHT,

		SDL_WINDOW_SHOWN);
	if(!window) {
		return;
	}


	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer) {
		return;
	}

	playerpaddle.x = 20;
	playerpaddle.y = 250;
	playerpaddle.h = 100;
	playerpaddle.w = 20;

	AIpaddle.x = 760;
	AIpaddle.y = 250;
	AIpaddle.h = 100;
	AIpaddle.w = 20;

	Ball.x = 370;
	Ball.y = 290; 
	Ball.w = 20;
	Ball.h = 20;


}