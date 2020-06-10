
#include "header.h"


void Collision(perso p,SDL_Surface *e,SDL_Rect pos,int *td,int *tg, int *th,int *tb)
{ 
pos.x=pos.x-e->w;
  
  *td=1;
  *tg=1;
  *tb=1;
  *th=1;
   if ((pos.y +e->h < p.posperso.y + p.perframe->h)||(p.posperso.x+p.perframe->w < pos.x)||(p.posperso.y+p.perframe->h < pos.y)||(p.posperso.x > pos.x+e->w ))// trop en bas
   {*tb=0;}

   if ((pos.x > p.posperso.x + p.perframe->w) ||(p.posperso.y+p.perframe->h < pos.y)||(p.posperso.y > pos.y+e->h)||(p.posperso.x+p.perframe->w > pos.x+e->w ))    // trop à droite   
   {*td=0;}
   
   if ((pos.x + e->w < p.posperso.x)||(p.posperso.y+p.perframe->h < pos.y)||(p.posperso.y > pos.y+e->h)||(p.posperso.x < pos.x)) // trop à gauche
   {*tg=0;}
   
   
   
   if ((pos.y + e->h < p.posperso.y) ||(pos.y > p.posperso.y)||(p.posperso.x+p.perframe->w < pos.x)||(p.posperso.x > pos.x+e->w ))  // trop en haut
   {*th=0;}

/*

  *td=0;
  *tg=0;
  *tb=0;
  *th=0;
   
   if ((pos.y == p.posperso.y+p.perframe->h)&&((p.posperso.x+p.perframe->w >= pos.x)||(p.posperso.x <= pos.x+e->w)))// trop en bas
   {*tb=1;}

   if ((pos.x == p.posperso.x + p.perframe->w)&&((p.posperso.y+p.perframe->h > pos.y)||(p.posperso.y+p.perframe->h < pos.y+e->h)))    // trop à droite   
   {*td=1;}

   if ((pos.x + e->w == p.posperso.x)&&(p.posperso.y+p.perframe->h >pos.y)&&(p.posperso.y+p.perframe->h < pos.y+e->h)) // trop à gauche

   {*tg=1;}

   
   if (pos.y + e->h == p.posperso.y) // trop en haut

   {*th=1;}*/


}

void Collision2(perso p,SDL_Surface *e,SDL_Rect pos,int *td,int *tg, int *th,int *tb)
{ 
//pos.x=pos.x-e->w;
  
  *td=1;
  *tg=1;
  *tb=1;
  *th=1;
   if ((pos.y +e->h < p.posperso.y + p.perframe->h)||(p.posperso.x+p.perframe->w < pos.x)||(p.posperso.y+p.perframe->h < pos.y)||(p.posperso.x > pos.x+e->w ))// trop en bas
   {*tb=0;}

   if ((pos.x > p.posperso.x + p.perframe->w) ||(p.posperso.y+p.perframe->h < pos.y)||(p.posperso.y > pos.y+e->h)||(p.posperso.x+p.perframe->w > pos.x+e->w ))    // trop à droite   
   {*td=0;}
   
   if ((pos.x + e->w < p.posperso.x)||(p.posperso.y+p.perframe->h < pos.y)||(p.posperso.y > pos.y+e->h)||(p.posperso.x < pos.x)) // trop à gauche
   {*tg=0;}
   
   
   
   if ((pos.y + e->h < p.posperso.y) ||(pos.y > p.posperso.y)||(p.posperso.x+p.perframe->w < pos.x)||(p.posperso.x > pos.x+e->w ))  // trop en haut
   {*th=0;}

/*

  *td=0;
  *tg=0;
  *tb=0;
  *th=0;
   
   if ((pos.y == p.posperso.y+p.perframe->h)&&((p.posperso.x+p.perframe->w >= pos.x)||(p.posperso.x <= pos.x+e->w)))// trop en bas
   {*tb=1;}

   if ((pos.x == p.posperso.x + p.perframe->w)&&((p.posperso.y+p.perframe->h > pos.y)||(p.posperso.y+p.perframe->h < pos.y+e->h)))    // trop à droite   
   {*td=1;}

   if ((pos.x + e->w == p.posperso.x)&&(p.posperso.y+p.perframe->h >pos.y)&&(p.posperso.y+p.perframe->h < pos.y+e->h)) // trop à gauche

   {*tg=1;}

   
   if (pos.y + e->h == p.posperso.y) // trop en haut

   {*th=1;}*/


}

void Collision_diamond(perso p,SDL_Surface *e,SDL_Rect pos,int *col)
{ 
//pos.x=pos.x-e->w;
  
  *col=1;
  
   if ((pos.y +e->h < p.posperso.y + p.perframe->h)||(p.posperso.x+p.perframe->w < pos.x)||(p.posperso.y+p.perframe->h < pos.y)||(p.posperso.x > pos.x+e->w ))// trop en bas
   {*col=0;}

   if ((pos.x > p.posperso.x + p.perframe->w) ||(p.posperso.y+p.perframe->h < pos.y)||(p.posperso.y > pos.y+e->h)||(p.posperso.x+p.perframe->w > pos.x+e->w ))    // trop à droite   
   {*col=0;}
   
   if ((pos.x + e->w < p.posperso.x)||(p.posperso.y+p.perframe->h < pos.y)||(p.posperso.y > pos.y+e->h)||(p.posperso.x < pos.x)) // trop à gauche
   {*col=0;}
   
   
   
   if ((pos.y + e->h < p.posperso.y) ||(pos.y > p.posperso.y)||(p.posperso.x+p.perframe->w < pos.x)||(p.posperso.x > pos.x+e->w ))  // trop en haut
   {*col=0;}

}


//void deplacment (SDL_Surface *ecran,SDL_Surface *imageFOND,SDL_Surface *personage,SDL_Rect positionFond,SDL_Rect positionPerso ,int continuer)
void deplacement(perso *p,SDL_Event *event,int *continuer,entite_frog frog[],vie *vie,int *c)
{int td,tb,tg,th,j,haut=0,bas=0,gauche=0,droite=0;
Uint8 * keys;
Uint32 timer,elapsed;
BACKGROUND back;
int min=0,max=0;


/*SDL_SetColorKey(personage,SDL_SRCCOLORKEY,SDL_MapRGB(personage->format,0,0,255));*/


//SDL_BlitSurface(personage,NULL,ecran,&positionPerso);
//SDL_Flip(ecran);

//SDL_EnableKeyRepeat(20,20);

//while(continuer)
//{
SDL_PollEvent(event);
for (j=0;j<6;j++)
{
    Collision(*p,frog[j].image_frog,frog[j].pos,&td,&tg,&th,&tb);
    if (td==1) 
           {
             droite=1;
             (*c)++;
             vie->pos.y+=vie->image_vie->h/7;
           }

    if (th==1) 
           {
             haut=1;
             (*c)++;
             vie->pos.y+=vie->image_vie->h/7;
           }

    if (tg==1) 
           {
             gauche=1;
             (*c)++;
            vie->pos.y+=vie->image_vie->h/7;
           }
    if (tb==1)
           {
             bas=1;
             (*c)++;
             vie->pos.y+=vie->image_vie->h/7;
           } 

}



switch (event->type)
{
case SDL_QUIT:
*continuer =0 ;
break;
case SDL_KEYDOWN:
switch (event->key.keysym.sym)
{

case SDLK_ESCAPE :
 *continuer=0;
break;
case SDLK_UP:
if ((haut==0)&&(p->posperso.y-25>=0))
p->posperso.y-=80;
if (haut==1)
p->posperso.y+=40;

break;
case SDLK_DOWN:
if ((bas==0)&&(p->posperso.y+25<=610))
p->posperso.y+=80;
if (bas==1)
p->posperso.y-=40;

break;
case SDLK_RIGHT:

if (droite==0)

p->posperso.x+=80;

else
{
p->posperso.x-=30;

}


//SDL_WaitEvent(&event);
break;
case SDLK_LEFT:

if ((gauche==0)&&(p->posperso.x-100>=0))//100 c est le width du personnage
p->posperso.x-=80;
if (gauche==1)
p->posperso.x+=50;

//SDL_WaitEvent(&event);
break;
/*case SDLK_SPACE:
SDL_PumpEvents();
Evolue(p,keys);
Render(p,screen);
//SDL_Flip(screen);
elapsed = SDL_GetTicks() - timer;
		if (elapsed<20)
			SDL_Delay(20-elapsed);
break;*/
}
break;
  case SDL_MOUSEBUTTONDOWN:
    if(event->button.button == SDL_BUTTON_LEFT)
{

if(event->button.x>p->posperso.x)
{p->posperso.x+=80; }

if(event->button.x<p->posperso.x)
{p->posperso.x-=80; }




if(event->button.y>p->posperso.y)
{p->posperso.y+=50; }

if(event->button.y<p->posperso.y)
{p->posperso.y-=50; }






}break;
}//bigswitch
}//FunctionEnd



//}
/*
SDL_BlitSurface(imageFOND,NULL,ecran,&positionFond);
SDL_BlitSurface(personage,NULL,ecran,&positionPerso);
SDL_Flip(ecran);
*/
//}

//il faut suprimer cette derniere acaulade } pour fonctioner SDL_MOUSSEBUTTON
