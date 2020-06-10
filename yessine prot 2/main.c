#include"perso.h"

int main()
{	
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface *screen;
	screen=SDL_SetVideoMode(960,540,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
	
	
	struct player p[2];
	p[0].posplayer.x=21;
	p[0].posplayer.y=99;

	p[1].posplayer.x=21;
	p[1].posplayer.y=99+270;

	struct background b[2];

	b[0]=init_background1(b[0]);
	b[1]=init_background2(b[1]);

	p[0]=init_player(p[0],b[0]);
	p[1]=init_player(p[1],b[1]);

	blit_background(b[0],screen); 
	blit_background(b[1],screen); 
	SDL_Flip(screen);
	
	SDL_Event event;
	int x=0;	
	int i=0;
	Uint8 *keystate = SDL_GetKeyState(NULL);
	int keysHeld[323] = {0};
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
					
					/*case SDL_KEYUP:
						keysHeld[event.key.keysym.sym] = 0;
					break;*/
					case SDL_KEYDOWN:
					{
						switch(event.key.keysym.sym)
						{
							
							case SDLK_RIGHT:
							{
								p[0]=walk(p[0],b[0],screen,event);
							}break;
							
										
							case SDLK_LEFT:
							{
								run(p,b,screen,event);	
							}break;
							case SDLK_q:
							{
								run(p,b,screen,event);	
							}break;
							case SDLK_UP:
							{
								p[0]=jump(p[0],b[0],screen,event);	
							}break;
							
						}
					}break;
				}
				
				
			}
				
			
		}
	SDL_FreeSurface(b[0].image);
	SDL_FreeSurface(b[0].tile);
	SDL_FreeSurface(b[0].image2);
	
	for (i=0;i<10;i++)
	SDL_FreeSurface(p[0].walk[i]);
	for (i=0;i<8;i++)
	SDL_FreeSurface(p[0].run[i]);
	for (i=0;i<7;i++)
	SDL_FreeSurface(p[0].jump[i]);

	SDL_FreeSurface(b[1].image);
	SDL_FreeSurface(b[1].tile);
	SDL_FreeSurface(b[1].image2);
	
	for (i=0;i<10;i++)
	SDL_FreeSurface(p[1].walk[i]);
	for (i=0;i<8;i++)
	SDL_FreeSurface(p[1].run[i]);
	for (i=0;i<7;i++)
	SDL_FreeSurface(p[1].jump[i]);
	
}
