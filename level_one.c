#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <string.h>
#include "header.h"

void level_one()
{  

int running=1,y,min=600, max = 800,i=1,r=500,c=1,j,t=1,test=0;


int numkeys;
	Uint8 * keys;

	Uint32 timer,elapsed;

entite_frog frog[6];
vie vie;
BACKGROUND back;
SDL_Surface* exemple;
ENTITE_SECONDAIRE entite;
perso personnage;
SDL_Event event;
SDL_Surface *ecran=NULL , *box=NULL, *diam=NULL;
SDL_Rect pos, posbox;
SDL_Rect posenig, posdiam;

posdiam.x=8136;
posdiam.y=330;

posbox.x=8436;
posbox.y=750;

pos.x=0;
pos.y=0;


//posenig.x=100;
//posenig.y=300;

int td,th,tb,tg;

SDL_Init(SDL_INIT_VIDEO);
ecran=SDL_SetVideoMode(1920,960,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("LOST LIFE",NULL);

//INITIALIZING 

intialiser_back(&back);
intialiser_entite(&entite);
init_perso(&personnage);
initialiser_vie(&vie);

intialiser_frog(&frog[0],700,690);
intialiser_frog(&frog[1],1900,540);
intialiser_frog(&frog[2],5108,750);
intialiser_frog(&frog[3],6180,750);
intialiser_frog(&frog[4],8826,750);
intialiser_frog(&frog[5],8136,750);

box=IMG_Load("prplbox.png");
exemple=IMG_Load("e1.png");


int s=0;

int k1,k2,k3,k4;

while(running)
{

SDL_PollEvent(&event);


for(j=0;j<6;j++)
{anim_frog(&c,&frog[j]);}

deplacement(&personnage,&event,&running,frog,&vie,&s);
if (s==6)
{running=0;}             
//anim_diamond(&t,diam);
char lien[40];//
                                     
                                      t++;
                                      if(t>10) {t=1;}
                                      sprintf(lien,"prpldiamond/%d.png",t);
                                      SDL_Delay(20);
                                      
                                      diam = IMG_Load(lien); //animation diamond
timer = SDL_GetTicks();
	
SDL_PumpEvents();
keys = SDL_GetKeyState(&numkeys);
Evolue(&personnage,keys);

		
		elapsed = SDL_GetTicks() - timer;
		if (elapsed<10)
	        SDL_Delay(10-elapsed);

	
anim_perso(&i,&event,&personnage);

//Collision_diamond(personnage,diam,posdiam,&col);
Collision2(personnage,diam,posdiam,&k1,&k2,&k3,&k4);
if (k1==1 || k2==1 || k3==1 || k4==1 )
//{running=0;}
{test=1;}




scrolling(&personnage,&back,&entite,&min,&max,frog,&posbox,&posdiam);
deplacement_aleatoire(&entite,min,max,back);

/*if ((personnage.posperso.x>entite.position.x)&&(personnage.posperso.x<entite.position.x+116)&&(personnage.posperso.y>entite.position.y)) //si le personnage rencontre l ennemi)
{
personnage.posperso.x=min;
partievie.y+=180;
}*/

/**enigme**/
Collision2(personnage,box,posbox,&td,&tg,&th,&tb);
{
   if (((td==1)||(th==1)||(tg==1)||(tb==1))&& test==1)
{
      //col=1;  
      enigme();
      running=0;

        }

}


//BLITTING  
affichback(&back,ecran);
afficher_perso(personnage,ecran,event);//ecran to back try | IF ALL ELSE FAILS REVERT TO SCREEN DUMBASS!
//if ((entite.position.x>=0)&&(entite.position.x<=450))  //450=back.width-width.ennemi

for(j=0;j<6;j++)
   {
     afficherfrog(frog[j] ,ecran);
     //SDL_Flip(ecran);
   }

SDL_BlitSurface(vie.image_vie,&vie.pos,ecran,&pos);
SDL_BlitSurface(box,NULL,ecran,&posbox);

if (test==0)
{SDL_BlitSurface(diam,NULL,ecran,&posdiam);}

/*if(entite.position.x>0)
afficherennemi(&entite,ecran);*/

//SDL_BlitSurface(entite.enemis[entite.direction],NULL,ecran,&entite.position);
//SDL_BlitSurface(exemple,NULL,ecran,&posenig);

//SDL_BlitSurface(exemple,NULL,ecran,&pos);

//UPDATE
SDL_Flip(ecran);
}
SDL_FreeSurface(entite.enemis[0]);
SDL_FreeSurface(back.f);
SDL_FreeSurface(ecran);		

}

