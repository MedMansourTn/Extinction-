#include<stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>


 struct player
{
	SDL_Surface *walk[10],*run[8],*jump[7];
	SDL_Rect posplayer;
	int bw,br;
	
};

struct background
{
	SDL_Surface *image,*tile,*image2;
	SDL_Rect postile[50];
	int i;
	SDL_Rect pos;
};

struct background init_background1(struct background b);
struct background init_background2(struct background b);
void blit_background(struct background b,SDL_Surface *screen);
struct player init_player(struct player p,struct background b);

int collision(SDL_Surface *img1,SDL_Rect pos1,struct background b);

struct player walk(struct player p,struct background b,SDL_Surface *screen,SDL_Event event);
void run(struct player p[],struct background b[],SDL_Surface *screen,SDL_Event event);
struct player jump(struct player p,struct background b,SDL_Surface *screen,SDL_Event event);

struct player grav (struct player p,SDL_Surface *img,struct background ,SDL_Surface *screen);
