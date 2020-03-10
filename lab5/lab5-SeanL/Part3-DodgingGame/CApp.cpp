//==============================================================================
#include "CApp.h"
#include <iostream>
//==============================================================================
CApp::CApp()
{
    Running = true;

	health = 20;

	points = 0;

	scroller = 0;

	speedfactor = 0;
}


Uint32 CApp::time_left(void)
{
    Uint32 now;

    now = SDL_GetTicks();
    if(next_time <= now)
        return 0;
    else
        return next_time - now;
}
//USE THIS FUNCTION TO DETECT COLLISIONS BETWEEN SNOWFLAKES and YOUR PLAYER
bool CApp::checkCollision(SDL_Rect A, SDL_Rect B)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;
	//Calculate the sides of rect A
	leftA = A.x;
	rightA = A.x + A.w;
	topA = A.y;
	bottomA = A.y + A.h;
	//Calculate the sides of rect B
	leftB = B.x;
	rightB = B.x + B.w;
	topB = B.y;
	bottomB = B.y + B.h;
	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}
	if (rightA <= leftB)
	{
		return false;
	}
	if (leftA >= rightB)
	{
		return false;
	}
	if (topA >= bottomB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}

/*int CApp::health(int hp)
{
	hp = hp - 1;

	if (hp == 0)
	{
		SDL_Quit();
	}

	return hp;
}*/

void CApp::displayGameStats(int x, int y, char* formattedString, int number) {

	sprintf_s(message, formattedString, number);	 		//convert number to string, insert into formatted string
	messageSurface = TTF_RenderText_Solid(font, message, color);	//make text an image (an SDL_Surface)
	messageTexture = SDL_CreateTextureFromSurface(renderer, messageSurface);	//convert SDL_Surface to SDL_Texture

	int texW = 0;
	int texH = 0;
	SDL_QueryTexture(messageTexture, NULL, NULL, &texW, &texH);	//get width & height of texture
	messageRect = { x, y, texW, texH };				//create a SDL_Rect for the message

	SDL_RenderCopy(renderer, messageTexture, NULL, &messageRect);	//copy it to screen
	SDL_DestroyTexture(messageTexture);				//release the Texture and Surfaces resources we created
	SDL_FreeSurface(messageSurface);
}


int
CApp::LoadSprite(char *file, SDL_Texture* &psprite, SDL_Rect *prect)
{
    SDL_Surface *temp;

    /* Load the sprite image */
    temp = SDL_LoadBMP(file);
    if (temp == NULL)
    {
        fprintf(stderr, "Couldn't load %s: %s", file, SDL_GetError());
        return (-1);
    }
    prect->w = temp->w;
    prect->h = temp->h;

    /* Set transparent pixel as the pixel at (0,0) */
    if (temp->format->palette)
    {
        SDL_SetColorKey(temp, SDL_TRUE, *(Uint8 *) temp->pixels);
    }
    else
    {
        switch (temp->format->BitsPerPixel)
        {
        case 15:
            SDL_SetColorKey(temp, SDL_TRUE,
                            (*(Uint16 *) temp->pixels) & 0x00007FFF);
            break;
        case 16:
            SDL_SetColorKey(temp, SDL_TRUE, *(Uint16 *) temp->pixels);
            break;
        case 24:
            SDL_SetColorKey(temp, SDL_TRUE,
                            (*(Uint32 *) temp->pixels) & 0x00FFFFFF);
            break;
        case 32:
            SDL_SetColorKey(temp, SDL_TRUE, *(Uint32 *) temp->pixels);
            break;
        }
    }

    /* Create textures from the image */
    psprite = SDL_CreateTextureFromSurface(renderer, temp);
    if (!psprite)
    {
        fprintf(stderr, "Couldn't create texture: %s\n", SDL_GetError());
        SDL_FreeSurface(temp);
        return (-1);
    }
    SDL_FreeSurface(temp);

    /* We're ready to roll. :) */
    return (0);
}



//------------------------------------------------------------------------------
int CApp::OnExecute()
{
    if(OnInit() == false)
    {
        return -1;
    }

    SDL_Event Event;
    next_time = SDL_GetTicks() + TICK_INTERVAL;
    while(Running)
    {
        while(SDL_PollEvent(&Event))
        {
            OnEvent(&Event);
        }

        OnLoop();
		if (health == 0)
		{
			std::cout << "YOU HAVE DIED" << endl;

			std::cout << " your total score was: " << points << endl;
			Running = false;
		}
        OnRender();
    }

    OnCleanup();

	 

    return 0;
}

//==============================================================================
int main(int argc, char* argv[])
{
    CApp theApp;

    return theApp.OnExecute();
}

//==============================================================================
