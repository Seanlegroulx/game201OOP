#ifndef CDoger_H
#define CDoger_H

#include <SDL.h>
#include "mywindow.h"
#include <string>

using namespace std;

/* Implement a sprite as a player.... */

class CDoger
{
    public:
            bool loaded;
            SDL_Rect position;
            SDL_Rect velocity;
            string imagename;

			CDoger();
			CDoger(string s, int x, int y, int vx, int vy);

            int loadPlayer(SDL_Renderer *prenderer);
            void display(SDL_Renderer *prenderer);
            void move();
    protected:
            SDL_Texture *texture;

};


#endif
