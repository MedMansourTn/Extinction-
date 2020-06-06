#include"enigme.h"
struct enigme init_enigme(struct enigme e,SDL_Surface *screen,SDL_Surface *image)
{
	e.background=IMG_Load("elback.png");
	e.obj=IMG_Load("mafiousi.png");
	e.puzz[0]=IMG_Load("untitled-1.png");
	e.puzz[1]=IMG_Load("untitled-2.png");
	e.puzz[2]=IMG_Load("untitled-3.png");
	e.puzz[3]=IMG_Load("untitled-4.png");
	e.puzz[4]=IMG_Load("untitled-5.png");
	e.puzz[5]=IMG_Load("untitled-6.png");
	e.puzz[6]=IMG_Load("untitled-7.png");
	e.puzz[7]=IMG_Load("untitled-8.png");
	e.puzz[8]=IMG_Load("untitled-9.png");
	
	
	e.posback.x=((image->w)/2)-((e.background->w)/2);
	e.posback.y=((image->h)/2)-((e.background->h)/2);
	SDL_BlitSurface(e.obj,NULL,screen,&e.posback);

	e.times = TTF_OpenFont("reality1.ttf",20);
	e.black.r=255,e.black.g=255;e.black.b=0;
	e.line=TTF_RenderText_Blended(e.times,"Solve This Puzzle",e.black);
	e.posline.x=((screen->w)/2)-(e.line->w)/2;
	e.posline.y=100;
	SDL_BlitSurface(e.line,NULL,screen,&e.posline);
	SDL_Flip(screen);
	SDL_Delay(3000);

	SDL_BlitSurface(image,NULL,screen,NULL);
	SDL_BlitSurface(e.background,NULL,screen,&e.posback);
	
	
	e.pospuzz[0].x=0;
	e.pospuzz[0].y=0;

	e.pospuzzobj[0].x=e.posback.x;
	e.pospuzzobj[0].y=e.posback.y;

	e.pospuzzobj[1].x=e.posback.x+(e.background->w)/3;
	e.pospuzzobj[1].y=e.posback.y;

	e.pospuzzobj[2].x=e.posback.x+(e.background->w)*2/3;
	e.pospuzzobj[2].y=e.posback.y;


	e.pospuzzobj[3].x=e.posback.x;
	e.pospuzzobj[3].y=e.posback.y+(e.background->h)/3;

	e.pospuzzobj[4].x=e.posback.x+(e.background->w)/3;
	e.pospuzzobj[4].y=e.posback.y+(e.background->h)/3;

	e.pospuzzobj[5].x=e.posback.x+(e.background->w)*2/3;
	e.pospuzzobj[5].y=e.posback.y+(e.background->h)/3;


	e.pospuzzobj[6].x=e.posback.x;
	e.pospuzzobj[6].y=e.posback.y+(e.background->h)*2/3;

	e.pospuzzobj[7].x=e.posback.x+(e.background->w)/3;
	e.pospuzzobj[7].y=e.posback.y+(e.background->h)*2/3;

	e.pospuzzobj[8].x=e.posback.x+(e.background->w)*2/3;
	e.pospuzzobj[8].y=e.posback.y+(e.background->h)*2/3;
	


	e.i=9;
	int i=0;
	while (i<e.i)
	{	
		SDL_BlitSurface(e.puzz[i],NULL,screen,&e.pospuzz[i]);
		e.pospuzz[i+1].x=e.pospuzz[i].x+100;
		e.pospuzz[i+1].y=0;
		i++;
	}
	SDL_Flip(screen);
	
	return e;
}
int pos(SDL_Event event,SDL_Rect rect,SDL_Surface *img)
{
	if((event.button.x>rect.x) && (event.button.x<rect.x+img->w) && (event.button.y>rect.y) && (event.button.y<rect.y+img->h))
	return 1;
	return 0;
}
struct enigme go_enigme(struct enigme e,SDL_Surface *screen,SDL_Surface *image)
{
	
	e=init_enigme(e,screen,image);
	e.posback.x=((image->w)/2)-((e.background->w)/2);
	e.posback.y=((image->h)/2)-((e.background->h)/2);
	int xmouse,ymouse;
	SDL_Event event;
	int x=0;
	int k=0;
	int i;
	SDL_Rect tmp;
	
	while(x==0)
	{	
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
					x=1;
				break;
				case SDL_MOUSEBUTTONDOWN:
				{
					i=0;
					while (i<9 && (pos(event,e.pospuzz[i],e.puzz[i]))==0 )
					i++;
					if (i<9 )
					{
						while(event.type!=SDL_MOUSEBUTTONUP)
						{
							SDL_GetMouseState(&(xmouse),&(ymouse));
							tmp.x=xmouse-(e.puzz[i]->w)/2;
							tmp.y=ymouse-(e.puzz[i]->h)/2;
							SDL_BlitSurface(image,NULL,screen,NULL);
							SDL_BlitSurface(e.background,NULL,screen,&e.posback);
							k=0;
							while (k<e.i)
							{				
								if (k!=i )
								SDL_BlitSurface(e.puzz[k],NULL,screen,&e.pospuzz[k]);
								k++;
							}
							//if (e.pospuzz[i].x!=e.pospuzzobj[i].x && e.pospuzz[i].y!=e.pospuzzobj[i].y)	
							SDL_BlitSurface(e.puzz[i],NULL,screen,&tmp);
							SDL_Flip(screen);
							SDL_PollEvent(&event);
						}
						if (pos(event,e.pospuzzobj[i],e.puzz[i])==1)
						{
							e.pospuzz[i]=e.pospuzzobj[i];
							SDL_BlitSurface(image,NULL,screen,NULL);
							SDL_BlitSurface(e.background,NULL,screen,&e.posback);
							k=0;
							while (k<e.i)
							{				
								SDL_BlitSurface(e.puzz[k],NULL,screen,&e.pospuzz[k]);
								k++;
							}
							SDL_Flip(screen);
						}
						else 
						{
							SDL_BlitSurface(image,NULL,screen,NULL);
							SDL_BlitSurface(e.background,NULL,screen,&e.posback);
							k=0;
							while (k<e.i)
							{				
								SDL_BlitSurface(e.puzz[k],NULL,screen,&e.pospuzz[k]);
								k++;
							}	
							SDL_Flip(screen);
						}		
					}
				}break;
			}
		}
		i=0;
		while (i<e.i && e.pospuzz[i].x==e.pospuzzobj[i].x && e.pospuzz[i].y==e.pospuzzobj[i].y )
		i++;
		if (i==e.i)
		{
			int l;
			for (l=4;l>=1;l--)
			{		
				SDL_BlitSurface(image,NULL,screen,NULL);
				SDL_BlitSurface(e.obj,NULL,screen,&e.posback);
				switch (l)
				{
					case 4:
					e.line=TTF_RenderText_Blended(e.times,"Puzzle Completed !Game will shut off in 3s...",e.black);break;
					case 3:
					e.line=TTF_RenderText_Blended(e.times,"3",e.black);break;
					case 2:
					e.line=TTF_RenderText_Blended(e.times,"2",e.black);break;
					case 1:	
					e.line=TTF_RenderText_Blended(e.times,"1",e.black);break;
				}
				e.posline.x=((screen->w)/2)-(e.line->w)/2;
				e.posline.y=((screen->h)/2)-(e.line->h)/2;
				SDL_BlitSurface(e.line,NULL,screen,&e.posline);
				SDL_Flip(screen);
				SDL_Delay(1000);
			}
			
			x=1;
		}
	}
	return e;
}
