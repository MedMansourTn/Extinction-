#include<stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>


struct files
{
	SDL_Surface *screen;
	SDL_Surface *image,*play1,*play2,*setting1,*setting2,*exit1,*exit2,*newg,*back1,*back2,*volume1,*sbg,*fullscreen1,*fullscreen2,*more1,*more2,*load1;
	SDL_Rect posnewgame;
	SDL_Rect possetting;
	SDL_Rect posquitter;
	SDL_Rect posback;
	Mix_Music* music;
	Mix_Chunk *effect1,*effect2;
	int x,y;
	int xmouse;
	int ymouse;
	SDL_Cursor* cursor;
	int m;
	int v;
	SDL_Rect posfullscreen;
	SDL_Rect posmore;
	//ttf
	TTF_Font* times;
	SDL_Surface* help;
	SDL_Color black;
	SDL_Rect posline;
	SDL_Rect posload;
};
int pos(SDL_Event event,SDL_Rect rect,SDL_Surface *img); 
int poz(int xmouse,int ymouse,SDL_Rect rect,SDL_Surface *img);
struct files Initialisation(struct files fl);
struct files play(struct files f,SDL_Event event);
struct files setting(struct files f,SDL_Event event);
struct files menu(struct files f,SDL_Event event);
struct files back(struct files f);
struct files help(struct files f,SDL_Event event);
void alwen(SDL_Event event,SDL_Surface *s1, SDL_Surface *s2,SDL_Rect pos,SDL_Surface *s);
