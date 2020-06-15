#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "defs.h"

#include "personnage.h"
#include "jouer.h"




int initialiser (jeu *game)
{


 initBackground(&(game->B1));
 init_perso(&(game->p1));
 init(&(game->e));
 game->game_over = 0;
 game->i = 5;
  
}


void test(jeu *game)
{

}



int load_images(jeu *game)
{


    if(load_perso1(&(game->p1)) == -1)
    {
        fprintf(stderr, "Erreur Chargement personnage\n");
        return(-1);
    }

    if(charger_Background(&(game->B1)) == -1)
    {
        fprintf(stderr, "Erreur Chargement Background \n");
        return(-1);
    }


}



void input (int keys_on[], jeu *game)
{
    SDL_Event event;

    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
    while (SDL_PollEvent(&event))
    {

        switch (event.type)
        {

        case SDL_QUIT:
            game->game_over = 1;
            break;
        case SDL_KEYDOWN:
            keys_on[event.key.keysym.sym] = 1;
            break;

        case SDL_KEYUP:
            keys_on[event.key.keysym.sym] = 0;

            break;

        case SDL_MOUSEBUTTONDOWN:

            keys_on[event.button.button]=1;
            if(event.button.x < game->p1.position.x)
            {
                game->directionSouris=1;
            }
            if(event.button.x > game->p1.position.x)
            {
                game->directionSouris=2;
            }

      

        break;




        }

    }
}



void update (int keys_on[], jeu *game, SDL_Surface *screen)
{

    int sens;


    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
  
    
 
// mvt auto ennemi

if(game->e.position.x-game->p1.position.x<120)
        { 
            game->e.direction=0;
       
 	    MoveEnnemi2(&(game->e));
                     
}

else if (game->e.position.x-game->p1.position.x>120 )
 {
game->e.direction=1;
    MoveEnnemi1(&(game->e));


}

// fin mvt ennemi




   //Enigme

   

   if(game->p1.position.x==730 )
                {
                    
                   en();
 	
      
                }
//fin enigme



///////deplacement //////////////////////////

//saut personnage
 if (keys_on[SDLK_SPACE] )
         {
            if( game->p1.direction==0 && game->p1.on_ground==1  )
            { 

                game->p1.on_ground=0;
                game->p1.position.x = game->p1.position.x +80;
                game->p1.position.y = game->p1.position.y-JUMP_HEIGHT;
         
            }
            else if( game->p1.direction==1 && game->p1.on_ground==1)  
            {
                game->p1.on_ground=0;
                game->p1.position.x = game->p1.position.x -80;
                game->p1.position.y = game->p1.position.y-JUMP_HEIGHT;
        
            }

        }

        if (!(keys_on[SDLK_SPACE]) )
        {

                game->p1.position.y=50; 
 	
                game->p1.on_ground=1;
            if(game->p1.direction==0)
            {
                game->p1.position_Anim.y=perso_HEIGHT;
    
            }
            else 
            {
                game->p1.position_Anim.y=0;
            }
    
        }
//fin saut personnage
    
//attaque personnage

                 if( keys_on[SDLK_a] &&game->p1.on_ground==1 &&   game->p1.direction==0) 
        {
                game->i=0;
                game->p1.direction=0;
       
    

  
       
                Move_Right(&(game->p1));
          
        
             

        }

//fin attaque personnage

//mvt personnage
    if(keys_on[SDLK_RIGHT] && game->p1.on_ground==1) 
     {
                game->i=0;
                game->p1.direction=0;
  		Move_Right(&(game->p1));
        }

        if(keys_on[SDLK_LEFT] && game->p1.on_ground==1) 
        {
                game->i=1;
                game->p1.direction=1;
                Move_Left(&(game->p1));
        }

         // fin mvt personnage
//vitesse personnage

        if((((keys_on[SDLK_s])&&(keys_on[SDLK_LEFT])) ||((keys_on[SDLK_s])&&(keys_on[SDLK_RIGHT])))  && game->p1.on_ground==1)  
        {   
                game->p1.acceleration+=100;
                Move_Right1(&(game->p1),game->B1,game->i);
      
        }

//fin vitesse personnage


        if(keys_on[SDL_BUTTON_LEFT]&& game->p1.on_ground==1) 
        {
                    if(game->directionSouris==2)
                    {
                        game->i=2;
                    game->p1.direction=0;
                    Move_Right(&(game->p1)); 
                    }
                    if(game->directionSouris==1)
                    {
                        game->i=3;
                    game->p1.direction=1;
                    Move_Left(&(game->p1));
            
                
                    }
                     keys_on[SDL_BUTTON_LEFT]=0;

        }
  
/////////////////////////////////////////////////////////////////////////////////////


  
     
        }


void display_game ( jeu *game, SDL_Surface *screen)
{
    SDL_Rect pos1 = {0, 0, 0, 350};
    blitBackground(&(game->B1), &pos1, screen);
    blit_perso(&(game->p1),  screen);
    afficher(&(game->e),screen);
    SDL_Flip(screen);
}

/*************************************************************************************************************************
*********************************************************************************************************/

void free_game(jeu *game)
{
    Mix_CloseAudio();
    freeBackground(&(game->B1));
    free_perso(&(game->p1));
    free_ennemi(&(game->e));
}
/*************************************************************************************************************************
*********************************************************************************************************/

int jouer(jeu *game, SDL_Surface *screen)
{
    Uint32 start;
    int keys_on[323] = {0};
    initialiser (game);
    load_images(game);

    while(game->game_over == 0)
    {
        start = SDL_GetTicks();
        input (keys_on, game);
        update (keys_on, game, screen );
        display_game (game, screen)	;
       
    }
    free_game(game);

    return(0);
}































