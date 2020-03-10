//==============================================================================
#include "CApp.h"
#include <stdlib.h>
#include <time.h>
//==============================================================================
bool CApp::OnInit()
{

    int i;

    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_JOYSTICK)<0)
    {
        return false;
    }
    window = SDL_CreateWindow("Basic SDL 2.0 Scrolling",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window)
        return false;
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer)
        return false;


	TTF_Init();		//starts up SDL_ttf

	font = TTF_OpenFont("lazy.ttf", 25);
	color = { 255, 0, 0 };

    srand(time(NULL));

    for (i = 0; i < (NUM_SPRITES); ++i) {
		allplayers[i].imagename = "Flying_Saucer.bmp";
        allplayers[i].loadPlayer(renderer);
        allplayers[i].position.x = rand() % (window_w);
        allplayers[i].position.y = (rand() % (window_h))-200;
        allplayers[i].velocity.x = 0;
		allplayers[i].velocity.y = rand() % (MAX_SPEED * 3) + 1;
    }

	playercharacter =CDoger("emmet-lego.bmp",WINDOW_WIDTH/2,WINDOW_HEIGHT- 124,0,0);
	playercharacter.loadPlayer(renderer);


	mars.imagename = "mars.bmp";
	mars.loadPlayer(renderer);
	mars.set_scroll_loc(0, 0, window_w, window_h);
    
    return true;
}




//==============================================================================
