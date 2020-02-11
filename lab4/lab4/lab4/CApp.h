//==============================================================================
// SDL Tutorial 1
//==============================================================================
#ifndef _CAPP_H_
#define _CAPP_H_

#include "SDL.h"

#define WINDOW_WIDTH    640
#define WINDOW_HEIGHT   480
#define NUM_SPRITES     8
#define MAX_SPEED       1

//==============================================================================
class CApp
{
private:
    bool            Running;

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *sprite;
	SDL_Texture* sprite1; //alien
	SDL_Texture* sprite2; //canon
	SDL_Texture* sprite3;	//fireball
	SDL_Texture* sprite4;	//canonball
    SDL_Rect positions[NUM_SPRITES];
    SDL_Rect velocities[NUM_SPRITES];
    int sprite_w, sprite_h;

	SDL_Joystick *joy = NULL;

public:
    CApp();

    int OnExecute();

public:
    bool OnInit();

    void OnEvent(SDL_Event* Event);

    void OnLoop();

    void OnRender();
	int LoadSprite(char *file, SDL_Renderer *renderer, SDL_Texture* &somesprite);
    void MoveSprites();

    void OnCleanup();
};

//==============================================================================

#endif
