#include "enemy.h"

void init(enemy *e)
{
e->img_avant[1]=IMG_Load("ennemi/en1.png");
e->img_avant[2]=IMG_Load("ennemi/en2.png");
e->img_avant[3]=IMG_Load("ennemi/en3.png");
e->img_avant[4]=IMG_Load("ennemi/en4.png");
e->img_avant[5]=IMG_Load("ennemi/en5.png");
e->img_avant[6]=IMG_Load("ennemi/en6.png");
e->img_avant[7]=IMG_Load("ennemi/en7.png");



e->img_back[1]=IMG_Load("ennemi/en8.png");
e->img_back[2]=IMG_Load("ennemi/en9.png");
e->img_back[3]=IMG_Load("ennemi/en10.png");
e->img_back[4]=IMG_Load("ennemi/en11.png");




e->position.x=580;
e->position.y=50;
e->direction=0;
e->frame=1;
}

void afficher(enemy *e,SDL_Surface *ecran)
{
SDL_Surface *img=NULL;
if(e->direction==1)
{
SDL_BlitSurface(e->img_avant[e->frame],NULL,ecran,&(e->position));
e->frame++;
if(e->frame==6)
{
e->frame=1;
}

}
else
{
e->frame=1;
SDL_BlitSurface(e->img_back[e->frame],NULL,ecran,&(e->position));
e->frame++;
if(e->frame==3)
{
e->frame=1;
}
}
}
	
void MoveEnnemi2(enemy *E)
{
       E->position.x -=0.0005;    
          if(E->position.x<=10)
            {
             
                E->position.x=10;
            }      
}
void MoveEnnemi1(enemy *E)
{
     E->position.x +=1;  
 if(E->position.x>=500)
            {
             
                E->position.x=500;
            }   
}
void free_ennemi(enemy *e)
{
int i;
for(i=0;i<3;i++)
{
SDL_FreeSurface(e->img_avant[i]);
SDL_FreeSurface(e->img_back[i]);
}
}




int charger_Background(Background *B)
{

    B->backgroundImg = IMG_Load("back1.png");
    if (B->backgroundImg == NULL)
    {
        printf("erreur: %s\n", SDL_GetError());
        return (-1);
    }
    return (0);
}



void initBackground(Background *B)
{
    B->i = 0;
    B->back_Pos.x = 0;
    B->back_Pos.y = 0;
    B->back_Pos.w = SCREEN_W;
    B->back_Pos.h = SCREEN_H;
}


void blitBackground(Background *B, SDL_Rect *pos, SDL_Surface *screen)
{
   
    SDL_BlitSurface(B->backgroundImg, &(B->back_Pos), screen, pos);

}



void freeBackground(Background *B)
{
    SDL_FreeSurface(B->backgroundImg);
}


