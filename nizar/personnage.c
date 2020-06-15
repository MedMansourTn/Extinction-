#include <SDL/SDL.h>
#include "defs.h"
#include <SDL/SDL_image.h>

#include "personnage.h"


void init_perso(perso *p)
{
    p->position.x = 0;
    p->position.y = 50;
    p->position.w = perso_WIDTH;
    p->position.h = perso_HEIGHT;
    p->position_Anim.x = 0;
    p->position_Anim.y = perso_HEIGHT;
    p->position_Anim.w = perso_WIDTH;
    p->position_Anim.h = perso_HEIGHT;
    p->direction = 0;
    p->on_ground = 1;
    p->position_saut.x=0;

    
}

int load_perso1(perso *p)
{  
    p->image = IMG_Load("personnage.png");
    if(p->image == NULL) {
    printf("Unable to load image:%s\n", SDL_GetError());
    return (-1);
    }
    return (0);
}

void blit_perso(perso *p, SDL_Surface * screen)
{
    SDL_BlitSurface(p->image, &(p->position_Anim), screen, &(p->position));
}

void Move_Right1(perso *p,Background B1,int i)
{    
        
         if(i==0)
         {  p->position.x+=4; }
         else if(i==1)
         {p->position.x -=4;}        
}


void Move_Right(perso *p)
{          
          p->position.x+=2;
}

void Move_Left(perso *p)
{   
    p->position.x -=2;

}
 

void free_perso(perso *p)
{
    SDL_FreeSurface(p->image);
}
