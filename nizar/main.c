#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include "defs.h"
#include "jouer.h"


int main ()
{
    jeu game;

	

    SDL_Surface *screen;
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        fprintf( stderr, "Unable to init SDL" );
        return 1;
    }
    atexit(SDL_Quit);
    screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_SRCALPHA);
    if ( !screen )
    {
        fprintf(stderr, "Unable to set /n");
        return 1;
    }

    SDL_WM_SetCaption(" Game", NULL);
    SDL_WM_SetIcon(IMG_Load("logo.png"), NULL);

  

    jouer(&game, screen);

    return 0;
}
