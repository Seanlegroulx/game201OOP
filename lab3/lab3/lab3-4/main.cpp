#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "SDL.h"

#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   600

#define NUM_SPRITES     4
#define MAX_SPEED       1


SDL_Texture* sprite1; //alien
SDL_Texture* sprite2; //canon
SDL_Texture* sprite3;	//fireball
SDL_Texture* sprite4;	//canonball
SDL_Rect positions[NUM_SPRITES];
SDL_Rect velocities[NUM_SPRITES];
SDL_Joystick *joy = NULL;
int sprite_w, sprite_h;

int LoadSprite(char *file, SDL_Renderer *renderer, SDL_Texture* &somesprite)
{
	SDL_Surface *temp;

	// Load the sprite image
	temp = SDL_LoadBMP(file);
	if (temp == NULL) {
		fprintf(stderr, "Couldn't load %s: %s", file, SDL_GetError());
		return (-1);
	}
	sprite_w = temp->w;
	sprite_h = temp->h;

	// Set transparent pixel as the pixel at (0,0)
	if (temp->format->palette) {
		SDL_SetColorKey(temp, SDL_TRUE, *(Uint8 *)temp->pixels);
	}
	else {
		switch (temp->format->BitsPerPixel) {
		case 15:
			SDL_SetColorKey(temp, SDL_TRUE, (*(Uint16 *)temp->pixels) & 0x00007FFF);
			break;
		case 16:
			SDL_SetColorKey(temp, SDL_TRUE, *(Uint16 *)temp->pixels);
			break;
		case 24:
			SDL_SetColorKey(temp, SDL_TRUE, (*(Uint32 *)temp->pixels) & 0x00FFFFFF);
			break;
		case 32:
			SDL_SetColorKey(temp, SDL_TRUE, *(Uint32 *)temp->pixels);
			break;
		}
	}

	// Create textures from the image
	somesprite = SDL_CreateTextureFromSurface(renderer, temp);
	if (!somesprite) {
		fprintf(stderr, "Couldn't create texture: %s\n", SDL_GetError());
		SDL_FreeSurface(temp);
		return (-1);
	}
	SDL_FreeSurface(temp);

	return (0);
}

void MoveSprites(SDL_Window * window, SDL_Renderer * renderer)
{
	int i;
	int window_w = WINDOW_WIDTH;
	int window_h = WINDOW_HEIGHT;
	SDL_Rect *position, *velocity;

	// Draw a gray background
	SDL_SetRenderDrawColor(renderer, 0xA0, 0xA0, 0xA0, 0xFF);
	SDL_RenderClear(renderer);

	// Move the sprite, bounce at the wall, and draw
	for (i = 0; i < NUM_SPRITES; ++i) {
		position = &positions[i];
		velocity = &velocities[i];
		position->x += velocity->x;
		if ((position->x < 0) || (position->x >= (window_w - sprite_w))) {
			velocity->x = -velocity->x;
			position->x += velocity->x;
		}
		position->y += velocity->y;
		if ((position->y < 0) || (position->y >= (window_h - sprite_h))) {
			velocity->y = -velocity->y;
			position->y += velocity->y;
		}

		// Blit the sprite onto the 
		if (i == 0) {
			SDL_RenderCopy(renderer, sprite1, NULL, position);
		}
		if (i == 1) {
			SDL_RenderCopy(renderer, sprite2, NULL, position);
		}		
		if (i == 2) {
			SDL_RenderCopy(renderer, sprite3, NULL, position);
		}
		if (i == 3) {
			SDL_RenderCopy(renderer, sprite4, NULL, position);
		}
	}

	// Update the screen!
	SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[])
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	int i, done;
	SDL_Event event;

	window = SDL_CreateWindow("Basic SDL Sprites",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN);
	if (!window) {
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer) {
		return false;
	}
	SDL_InitSubSystem(SDL_INIT_JOYSTICK);

	if (SDL_NumJoysticks() > 0)
	{
		joy = SDL_JoystickOpen(0);
		
	}

	if (LoadSprite("alien.bmp", renderer, sprite1) < 0) {
		return false;
	}
	positions[0].x = 0;
	positions[0].y =WINDOW_HEIGHT/2 - sprite_h/2;
	positions[0].w = sprite_w;
	positions[0].h = sprite_h;
	velocities[0].x = 0;
	velocities[0].y = 0;

	if (LoadSprite("cannon.bmp", renderer, sprite2) < 0) {
		return false;
	}
	positions[1].x = WINDOW_WIDTH- sprite_w;
	positions[1].y = WINDOW_HEIGHT / 2 - sprite_h / 2;
	positions[1].w = sprite_w;
	positions[1].h = sprite_h;
	velocities[1].x = 0;
	velocities[1].y = 0;
	if (LoadSprite("fireball.bmp", renderer, sprite3) < 0) {
		return false;
	}
	positions[2].x = -100;
	positions[2].y = positions[0].y;
	positions[2].w = sprite_w;
	positions[2].h = sprite_h;
	velocities[2].x = 0;
	velocities[2].y = 0;
	if (LoadSprite("cannonball.bmp", renderer,sprite4) < 0) {
		return false;
	}
	positions[3].x = -100;
	positions[3].y = positions[1].y;
	positions[3].w = sprite_w;
	positions[3].h = sprite_h;
	velocities[3].x = 0;
	velocities[3].y = 0;

	// Initialize the sprite positions
	
	

	// Main render loop
	done = 0;
	while (!done) {
		// Check for events
		while (SDL_PollEvent(&event)) {
			switch (event.type)
			{

			case SDL_QUIT:
				done = 1;
				break;
			case SDL_KEYDOWN:
				done = 1;
				break;
			case SDL_MOUSEMOTION:


				positions[0].y = event.motion.y;


				break;
			case SDL_MOUSEBUTTONDOWN:

				if (event.button.button == SDL_BUTTON_LEFT)
				{
					positions[2].x = positions[0].x;
					positions[2].y = positions[0].y;
					velocities[2].x = 1;

				}

				break;
			case SDL_MOUSEBUTTONUP:


				break;

			case SDL_JOYBUTTONDOWN:


				if (event.jbutton.which == 0 && event.jbutton.button == 0)
				{
					positions[3].x = positions[1].x;
					positions[3].y = positions[1].y;
					velocities[3].x = -1;


				}
				break;
			}
		}

		if (joy)
		{


			positions[1].y += SDL_JoystickGetAxis(joy, 1) / 6000;
			if (positions[1].x > WINDOW_WIDTH - sprite_w)
				positions[1].x = WINDOW_WIDTH - sprite_w;
			if (positions[1].x < 0)
				positions[1].x = 0;
			if (positions[1].y > WINDOW_HEIGHT - sprite_h)
				positions[1].y = WINDOW_HEIGHT - sprite_h;
			if (positions[1].y < 0)
				positions[1].y = 0;

		}
		
		MoveSprites(window, renderer);
		
		SDL_Delay(3);
	}

	SDL_Quit();

	return true;
}

//SDL_InitSubSystem
