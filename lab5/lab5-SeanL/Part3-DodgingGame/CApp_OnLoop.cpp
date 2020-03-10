//==============================================================================
#include "CApp.h"
int basevelocity = 0;

void
CApp::MoveSprites()
{
    int i;
	int hp = 20;

    /* Draw a gray background */

    /* Move the sprite, bounce at the wall, and draw */
    for (i = 0; i < NUM_SPRITES; ++i)
    {
        allplayers[i].move();
       
		
		if (checkCollision(playercharacter.position, allplayers[i].position))
		{
			allplayers[i].position.x = rand() % (window_w);
			allplayers[i].position.y = (rand() % (300)) - 400;
			allplayers[i].velocity.x = 0;
			allplayers[i].velocity.y = rand() % (MAX_SPEED * 3) + 1;
			
		
				health -= 1;
				
				points -= 5;


			
		
		}
		if (allplayers[i].position.y > window_h)
		{
			allplayers[i].position.x = rand() % (window_w);
			allplayers[i].position.y = (rand() % (300)) - 400;
			allplayers[i].velocity.x = 0;
			allplayers[i].velocity.y = rand() % (MAX_SPEED * 3) + 1;
			points += 1;


			
		}
    }


}


//==============================================================================
void CApp::OnLoop()
{

    
    MoveSprites();




	
	mars.move();


	
   

}

//==============================================================================
