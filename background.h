#ifndef DS1_H_INCLUDED
#define DS1_H_INCLUDED


#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

typedef struct  background
{
		
	    SDL_Surface *background;
	    SDL_Surface *background_tile;
	    SDL_Surface *Gameover_text;
	    SDL_Surface *score_text;
	    TTF_Font *police;
	    //SDL_Color couleurnoir;
	    SDL_Rect camera;
	    SDL_Rect pos_text;
	    char chaine_score[5];
	    int x_relative;
	    int y_relative;

}background;

void initialiser_backround (background *b);
void afficher_background (SDL_Surface *screen,background *b);
void afficher_background_tile (SDL_Surface *screen,background *b);
void afficher_score (SDL_Surface *screen,background *b);






  #endif // DS_H_INCLUDED
