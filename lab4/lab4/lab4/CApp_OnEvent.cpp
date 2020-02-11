//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnEvent(SDL_Event* Event) {
    /*if(Event->type == SDL_QUIT||Event->type == SDL_KEYDOWN) {
        Running = false;
    }*/
	switch (Event->type)
	{
	case SDL_QUIT:
		
		break;
	case SDL_MOUSEMOTION:


		positions[0].y = Event->motion.y;


		break;
	case SDL_MOUSEBUTTONDOWN:

		if (Event->button.button == SDL_BUTTON_LEFT)
		{
			positions[2].x = positions[0].x;
			positions[2].y = positions[0].y;
			velocities[2].x = 1;

		}

		break;
	case SDL_MOUSEBUTTONUP:


		break;

	case SDL_JOYBUTTONDOWN:


		if (Event->jbutton.which == 0 && Event->jbutton.button == 0)
		{
			positions[3].x = positions[1].x;
			positions[3].y = positions[1].y;
			velocities[3].x = -1;


		}
		break;
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
}






//==============================================================================
