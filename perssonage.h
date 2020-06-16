#ifndef DS2_H_INCLUDED
#define DS2_H_INCLUDED
#include <stdbool.h>
#include <SDL/SDL.h>

typedef struct perssonage
{
SDL_Surface *personnage;
SDL_Rect rect;
SDL_Rect rects[26];
int frame;
float xvelocity,yvelocity;	 
float delta_time;
int onground;
int one_jump;
int vie;
bool invincible;
int score;
float current_time;
float previous_time;
bool on_water;
}perssonage;


void initialiser_perssonage (perssonage *p);
void afficher_perssonage (perssonage *p,SDL_Surface *screen);
void animation_right (perssonage *p);
void setrects(SDL_Rect* clip);




  #endif // DS_H_INCLUDED
