#include"enigme.h"

int main()
{	
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();


	SDL_Surface *screen;
	screen=SDL_SetVideoMode(1000,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_Surface *image;
	image=IMG_Load("bggg.png");
	SDL_BlitSurface(image,NULL,screen,NULL);
	SDL_Flip(screen);
	
	SDL_Event event;
	int x=0;
	struct enigme e;
	while(x==0)
		{		
			SDL_Flip(screen);
			while(SDL_PollEvent(&event))
			{
				switch(event.type)
				{
					case SDL_QUIT:
						x=1;
					break;
					case SDL_KEYDOWN:
					{
						switch(event.key.keysym.sym)
						{
							
							case SDLK_j://echap->quitter
							{
								e=go_enigme(e,screen,image);
								x=1;
							}break;	
						}
					}break;
				}
			}
		}
	SDL_FreeSurface(image);
	SDL_FreeSurface(e.background);
	SDL_FreeSurface(e.obj);
	int i=0;
	while (i<e.i)
	{
		SDL_FreeSurface(e.puzz[i]);
		i++;
	}
	TTF_CloseFont(e.times);
	TTF_Quit();
	SDL_Quit();
	return 0;					
}
