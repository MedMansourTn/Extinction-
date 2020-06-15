
#ifndef JEU_H
#define JEU_H
#include <SDL/SDL.h>
#include "personnage.h"
#include "enemy.h"
#include "ex.h"
#include <string.h>
#include <time.h>
#include <SDL/SDL_ttf.h>
struct jeu
{
   perso p1 ;
   enemy e;
   Background B1;
   int game_over ;
   int directionSouris;
   int i;

} ;
typedef struct jeu jeu ;
void test(jeu *game);
int jouer(jeu *game, SDL_Surface *screen);
int load_images(jeu *game);
int initialiser (jeu *game);
void input (int keys_on[], jeu *game);
void update (int keys_on[], jeu *game, SDL_Surface *screen);
void display_game ( jeu *game, SDL_Surface *screen);
void free_game(jeu *game);




#endif
