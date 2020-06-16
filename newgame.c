#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "newgame.h"
#include <SDL/SDL_rotozoom.h>


int newgame(SDL_Surface *screen)
{
	SDL_Surface *bg,*escape,*arrow;//*zoom;
	SDL_Rect pos,posarrow,posbg;
	SDL_Event event;
	pos.x=0;
	pos.y=0;
	posbg.x=0;
	posbg.y=0;
	posarrow.x=420;
	posarrow.y=200;
	int stage=0;
	bg=IMG_Load("bg/Map.jpg");
	escape=IMG_Load("boutton/echaptoreturn.png");
	arrow=IMG_Load("bg/arrow.png");
	do
	{
		SDL_BlitSurface(bg,NULL,screen,&posbg);
		SDL_BlitSurface(escape,NULL,screen,&pos);
		SDL_BlitSurface(arrow,NULL,screen,&posarrow);
		SDL_Flip(screen);
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button==SDL_BUTTON_LEFT)
				{
					if (event.motion.x>0 && event.motion.y>0 && event.motion.x<230 && event.motion.y<50)
					{
						event.key.keysym.sym=SDLK_ESCAPE;
					}
				}
			break;
			
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_LEFT:
						if (stage==2)
						{
							posarrow.x =560;
							posarrow.y=250;
							stage=1;
						}
						else if (stage==0)
						{
							posarrow.x=120;
							posarrow.y=200;
							stage=2;
						}
						else if (stage==1)
						{
							posarrow.x=420;
							posarrow.y=200;
							stage=0;
						}
					break;

					case SDLK_RIGHT:
						if (stage==0)
						{
							posarrow.x =560;
							posarrow.y=250;
							stage=1;
						}
						else if (stage==1)
						{
							posarrow.x=120;
							posarrow.y=200;
							stage=2;
						}
						else if (stage==2)
						{
							posarrow.x=420;
							posarrow.y=200;
							stage=0;
						}
					break;

					case SDLK_RETURN:
						/*zoom = rotozoomSurface(bg, 0, 2.0, 1);
						posbg.x=posarrow.x-800;
						posbg.y=posarrow.y-500;
						SDL_BlitSurface(zoom,NULL,screen,&posbg);
						SDL_Flip(screen);
						SDL_Delay(2000);*/ 
						return stage;
					break;
				}
			break;
		}

	} while (event.key.keysym.sym!=SDLK_ESCAPE );

}