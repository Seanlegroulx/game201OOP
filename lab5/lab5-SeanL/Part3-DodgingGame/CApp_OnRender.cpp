//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnRender()
{

	
	
	SDL_SetRenderDrawColor(renderer, 0xA0, 0xA0, 0xA0, 0xFF);
	SDL_RenderClear(renderer);
	mars.display(renderer);
for (int i = 0; i < NUM_SPRITES; i++) {
allplayers[i].display(renderer);
	}
	displayGameStats(20, 20, "lives remaning: %2d", health);
	displayGameStats(40, 40, "score: %2d", points);
	displayGameStats(60, 60, "scroll: %2d", mars.numofScrolls);
	displayGameStats(80, 80, "Speed factor: %2d", speedfactor);
	
	playercharacter.display(renderer);
    /* Update the screen! */
    SDL_RenderPresent(renderer);
    //SDL_Delay(10);
    SDL_Delay(time_left());
    next_time += TICK_INTERVAL;



}

//==============================================================================
