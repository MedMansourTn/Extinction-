#include<stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>

struct enigme
{
	SDL_Surface *puzz[9],*background,*obj;
	SDL_Rect pospuzz[9],posback,pospuzzobj[9];
	int i;
	TTF_Font* times;
	SDL_Color black;
	SDL_Rect posline;
	SDL_Surface *line;
};


struct enigme init_enigme(struct enigme e,SDL_Surface *screen,SDL_Surface *image);
struct enigme go_enigme(struct enigme e,SDL_Surface *screen,SDL_Surface *image);
int pos(SDL_Event event,SDL_Rect rect,SDL_Surface *img);
