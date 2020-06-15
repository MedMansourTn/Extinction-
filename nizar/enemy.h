#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "defs.h"
struct enemy
{
SDL_Rect position;
SDL_Surface *img_avant[11]; 
SDL_Surface *img_back[11];
int direction;
int frame;


};
typedef struct enemy enemy;



struct Background
{
    SDL_Surface *backgroundImg;
    SDL_Rect back_Pos;
    int i;
};
typedef struct Background Background;

void init(enemy *E);
void afficher(enemy *E,SDL_Surface *ecran);
void free_ennemi(enemy *E);
void MoveEnnemi1(enemy *E);
void MoveEnnemi2(enemy *E);


void initBackground(Background *B);
int charger_Background(Background *B);
void freeBackground(Background *B);
void blitBackground(Background *B, SDL_Rect *pos, SDL_Surface *screen);


#endif // ENEMY_H_INCLUDED
