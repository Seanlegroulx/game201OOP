//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnEvent(SDL_Event* Event) {
	
	
	switch (Event->type)
	{
	case SDL_QUIT:
		Running = false;
		break;
	case SDL_MOUSEMOTION:


		playercharacter.position.x = Event->motion.x; 

		if (playercharacter.position.x >= WINDOW_WIDTH)
		{
			playercharacter.position.x = WINDOW_WIDTH - 124;
		}
		break;


	
	case SDL_KEYDOWN:
		switch (Event->key.keysym.sym) {
		case SDLK_DOWN:
			for (int i = 0; i < NUM_SPRITES; ++i) {

				allplayers[i].velocity.y = 3;
				speedfactor = 3;

			}

			break;
		case SDLK_UP:
			for (int i = 0; i < NUM_SPRITES; ++i) {

				allplayers[i].velocity.y = 1;
				speedfactor = 1;

			}
		}
		break;


	//case SDL_MOUSEBUTTONDOWN:

		/*if (Event->button.button == SDL_BUTTON_LEFT)
		{
			position.x = positions[0].x;
			positions.y = positions[0].y;
			velocities.x = 1;

		}
*/
	}
			
}

//==============================================================================
