#ifndef Personnage_H
#define Personnage_H
#include <SDL/SDL.h>
#include "enemy.h"

struct perso{
    SDL_Rect position;
    SDL_Rect position_saut;
	SDL_Rect position_Anim;
	SDL_Surface * image;
	int on_ground;
	int jump;
    	
	double acceleration;
	int direction;

	
};
typedef struct perso perso;



int load_perso1(perso *p);
void init_perso(perso *p);

void Move_Right(perso *p);
void Move_Left(perso *p);
void Move_Right1(perso *p,Background B1,int i);

void blit_perso(perso *p, SDL_Surface * screen);

void free_perso(perso *p);


#endif
