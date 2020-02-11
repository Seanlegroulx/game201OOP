//==============================================================================
#include "CApp.h"


void
CApp::MoveSprites()
{
    int i;
    int window_w = WINDOW_WIDTH;
    int window_h = WINDOW_HEIGHT;
    SDL_Rect *position, *velocity;

    /* Draw a gray background */
    SDL_SetRenderDrawColor(renderer, 0xA0, 0xA0, 0xA0, 0xFF);
    SDL_RenderClear(renderer);

    /* Move the sprite, bounce at the wall, and draw */
    for (i = 0; i < NUM_SPRITES; ++i)
    {
        position = &positions[i];
        velocity = &velocities[i];
        position->x += velocity->x;
        if ((position->x < 0) || (position->x >= (window_w - sprite_w)))
        {
            velocity->x = -velocity->x;
            position->x += velocity->x;
        }
        position->y += velocity->y;
        if ((position->y < 0) || (position->y >= (window_h - sprite_h)))
        {
            velocity->y = -velocity->y;
            position->y += velocity->y;
        }

        /* Blit the sprite onto the screen */
		if (i == 0) {
			SDL_RenderCopy(renderer, sprite, NULL, position);
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


}


//==============================================================================
void CApp::OnLoop()
{
    MoveSprites();




}

//==============================================================================
