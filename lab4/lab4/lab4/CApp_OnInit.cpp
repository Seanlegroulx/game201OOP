//==============================================================================
#include "CApp.h"
#include <stdlib.h>
#include <time.h>
//==============================================================================
bool CApp::OnInit()
{
	//if(SDL_init)
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	int i;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0)
	{
		return false;
	}
	window = SDL_CreateWindow("Basic SDL 2.0 Sprites",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN);
	if (!window)
		return false;
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer)
		return false;
	SDL_InitSubSystem(SDL_INIT_JOYSTICK);

	if (SDL_NumJoysticks() > 0)
	{
		joy = SDL_JoystickOpen(0);

	}
/*	if (LoadSprite("alien.bmp", renderer, sprite1) < 0) {
		return false;
	}
	positions[0].x = 0;
	positions[0].y = WINDOW_HEIGHT / 2 - sprite_h / 2;
	positions[0].w = sprite_w;
	positions[0].h = sprite_h;
	velocities[0].x = 0;
	velocities[0].y = 0;

	if (LoadSprite("cannon.bmp", renderer, sprite2) < 0) {
		return false;
	}
	positions[1].x = WINDOW_WIDTH - sprite_w;
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
	if (LoadSprite("cannonball.bmp", renderer, sprite4) < 0) {
		return false;
	}
	positions[3].x = -100;
	positions[3].y = positions[1].y;
	positions[3].w = sprite_w;
	positions[3].h = sprite_h;
	velocities[3].x = 0;
	velocities[3].y = 0;
	*/
	if (LoadSprite("alien.bmp", renderer, sprite) < 0) 
		return false;


	positions[0].x = 0;
	positions[0].y = WINDOW_HEIGHT / 2 - sprite_h / 2;
	positions[0].w = sprite_w;
	positions[0].h = sprite_h;
	velocities[0].x = 0;
	velocities[0].y = 0;

	if (LoadSprite("cannon.bmp", renderer, sprite2) < 0) {
		return false;
	}
	positions[1].x = WINDOW_WIDTH - sprite_w;
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
	if (LoadSprite("cannonball.bmp", renderer, sprite4) < 0) {
		return false;
	}
	positions[3].x = -100;
	positions[3].y = positions[1].y;
	positions[3].w = sprite_w;
	positions[3].h = sprite_h;
	velocities[3].x = 0;
	velocities[3].y = 0;



			//}

			return true;
		

		//==============================================================================
		
}