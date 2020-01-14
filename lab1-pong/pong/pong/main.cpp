/*
Sean Legroulx
Game 202
Majid Moghadam
Pong
1/12/2020


*/

#include "sdl.h"
#include <cstdlib>


#define WINDOW_WIDTH  800
#define WINDOW_HIGHT  600


SDL_Renderer *renderer;

bool running = true;


SDL_Event event;


int mouse_x, mouse_y;
int speed_x, speed_y;
int direction[2] = { -1, 1 };

SDL_Rect playerpaddle;
SDL_Rect AIpaddle;
SDL_Rect Ball;



bool check_collision(SDL_Rect A, SDL_Rect B)
{

	int leftA, LeftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;












}

void LoadGame()
{
	SDL_Window *window;

	window = SDL_CreateWindow("Basic SDL Sprites",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HIGHT,

		SDL_WINDOW_SHOWN);
	if (!window) {
		return;
	}
	speed_x = -1;
	speed_y = -1;



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

void input() {
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_MOUSEMOTION)
		{
			SDL_GetMouseState(&mouse_x, &mouse_y);
		}

		if (event.type == SDL_QUIT)
		{
			running = false;
		}

		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				running = false;
				break;
			}
		}
	}
}


void update() {
	playerpaddle.y = mouse_y;

	Ball.x += speed_x;
	Ball.y += speed_y;




	if (Ball.x < 0 || Ball.x > WINDOW_WIDTH) {
		Ball.x = WINDOW_WIDTH / 2;
		Ball.y = WINDOW_WIDTH / 2;



		speed_x = (rand() % 2 + 1) * direction[rand() % 2];
		speed_y = (rand() % 2 + 1) * direction[rand() % 2];

	}

	if (Ball.y < 0 || Ball.y > WINDOW_HIGHT)
	{
		speed_y = -speed_y;
	}

	if (Ball.y < 0 || Ball.y >(WINDOW_HIGHT - Ball.h))
	{
		speed_y = -speed_y;
	}



	AIpaddle.y = Ball.y - AIpaddle.h / 2 + Ball.h / 2;


	SDL_Delay(10);

}


void DrawScreen() {

	SDL_RenderClear(renderer);

	SDL_Rect background = { 0, 0, 800, 600 };
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &background);


	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &playerpaddle);
	SDL_RenderFillRect(renderer, &AIpaddle);


	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &Ball);

	SDL_RenderPresent(renderer);
}

void Quit() {

	SDL_Quit();
}


int main(int argc, char *argv[]) {

	LoadGame();

	while (running == true) {
		input();
		update();
		DrawScreen();




	}



	Quit();

	return 0;
}