//==============================================================================
// SDL Tutorial 1
//==============================================================================
#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL.h>
#include <SDL_ttf.h>
#include "mywindow.h"
#include "CPlayer.h"
#include "CDoger.h"
#include "Scroller.h"

#define TICK_INTERVAL    10
#define NUM_SPRITES     11
#define MAX_SPEED       1

//==============================================================================
class CApp
{
private:
    bool            Running;

    Uint32 next_time;
    SDL_Window *window;
    SDL_Renderer *renderer;
    CPlayer allplayers[NUM_SPRITES];
	CDoger playercharacter;
	CScroll_Player mars;

	TTF_Font * font;			//font object we will use for the message
	SDL_Color color;			//color of the message
	char message[100];			//the message string
	SDL_Surface * messageSurface;	//surface that stores the message
	SDL_Texture * messageTexture;	//surface is converted to a texture
	SDL_Rect messageRect;		//location of the message


public:
    CApp();
    Uint32 time_left(void);
    int OnExecute();

public:
    bool OnInit();

    void OnEvent(SDL_Event* Event);

    void OnLoop();

    void OnRender();
    int LoadSprite(char *file, SDL_Texture* &psprite, SDL_Rect *prect);
    void MoveSprites();

    void OnCleanup();

	bool checkCollision(SDL_Rect A, SDL_Rect B);

	int health;

	int points;

	void displayGameStats(int x, int y, char* formattedString, int number);

	int scroller;

	int updown(int value);

	int speedfactor;

};

//==============================================================================

#endif
