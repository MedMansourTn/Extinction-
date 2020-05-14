#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "Ennemi.h"
#include "Background.h"

int main()
{
SDL_Surface *ecran = NULL;
int continuer =1;
enemy ennemi;
background back;
mouvement mvt;

int i=0,pos,alea;
int posMin=100,posMax=600;

SDL_Event event;
//initialiser
initialiser_ennemi(&ennemi);
initialiser_background(&back);

SDL_Init(SDL_INIT_VIDEO);

Remplissage_animation (&mvt);

ecran=SDL_SetVideoMode(1600,800,32,SDL_HWSURFACE);

while (continuer)
{		
	SDL_PollEvent(&event);	
	//affichage
        affichage_background(ecran,&back);
	//affichage_ennemi(ecran,&ennemi);
	SDL_Flip(ecran);
	Deplacement_annime (&mvt,&ennemi,&back,ecran,posMax,posMin);
/*	pos=deplacement_alea (posmax,posmin);
	(ennemi.posennemi.x)=pos;	
	SDL_Flip(ecran);
*/
switch (event.type)
{
	case (SDL_QUIT) :
	{
	continuer=0 ;
	break;
	}
}
}
return 0;
}
