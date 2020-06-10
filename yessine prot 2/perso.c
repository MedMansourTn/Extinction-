#include"perso.h"

struct background init_background1(struct background b)
{
	int i=0;
	b.image=IMG_Load("Background.png");
	b.image2=IMG_Load("backgroundmulti.png");
	b.tile=IMG_Load("burrr.png");
	b.postile[0].y=100;
	b.postile[0].x=20;
	SDL_Rect pos;
	b.pos.x=0;
	b.pos.y=0;
	pos.x=b.postile[0].x;
	pos.y=b.postile[0].y;
	while (pos.x<400 && pos.y<(270-b.tile->h))
		{
			i++;
			pos.x=pos.x+b.tile->w;
			pos.y=pos.y+b.tile->h;
			b.postile[i].x=pos.x;
			b.postile[i].y=pos.y;

			 
		}
	b.i=i;
	b.i++;
	b.postile[b.i].y=b.postile[b.i-2].y;
	b.postile[b.i].x=b.postile[i].x+b.tile->w;

	





	return b;
}
struct background init_background2(struct background b)
{
	int i=0;
	b.image=IMG_Load("Background.png");
	b.image2=IMG_Load("backgroundmulti.png");
	b.tile=IMG_Load("burrr.png");
	b.pos.x=0;
	b.pos.y=270;
	b.postile[0].x=20;
	b.postile[0].y=370;
	SDL_Rect pos;
	pos.x=20;
	pos.y=370;
	while (pos.x<400 && pos.y<(540-b.tile->h))
		{
			i++;
			pos.x=pos.x+b.tile->w;
			pos.y=pos.y+b.tile->h;
			b.postile[i].x=pos.x;
			b.postile[i].y=pos.y;

			 
		}
	b.i=i;
	b.i++;
	b.postile[b.i].y=b.postile[b.i-2].y;
	b.postile[b.i].x=b.postile[i].x+b.tile->w;


	return b;
}

void blit_background(struct background b,SDL_Surface *screen)
{
	int i=0;
	
	SDL_BlitSurface(b.image2,NULL,screen,&b.pos);
	for (i=0;i<=b.i;i++)	
		SDL_BlitSurface(b.tile,NULL,screen,&b.postile[i]);
		
}


struct player init_player(struct player p,struct background b)
{
	p.walk[0]=IMG_Load("walk1.png");
	p.walk[1]=IMG_Load("walk2.png");
	p.walk[2]=IMG_Load("walk3.png");
	p.walk[3]=IMG_Load("walk4.png");
	p.walk[4]=IMG_Load("walk5.png");
	p.walk[5]=IMG_Load("walk6.png");
	p.walk[6]=IMG_Load("walk7.png");
	p.walk[7]=IMG_Load("walk8.png");
	p.walk[8]=IMG_Load("walk9.png");
	p.walk[9]=IMG_Load("walk10.png");

	p.run[0]=IMG_Load("run1.png");
	p.run[1]=IMG_Load("run2.png");
	p.run[2]=IMG_Load("run3.png");
	p.run[3]=IMG_Load("run4.png");
	p.run[4]=IMG_Load("run5.png");
	p.run[5]=IMG_Load("run6.png");
	p.run[6]=IMG_Load("run7.png");
	p.run[7]=IMG_Load("run8.png");

	p.jump[0]=IMG_Load("jump1.png");
	p.jump[1]=IMG_Load("jump2.png");
	p.jump[2]=IMG_Load("jump3.png");
	p.jump[3]=IMG_Load("jump4.png");
	p.jump[4]=IMG_Load("jump5.png");
	p.jump[5]=IMG_Load("jump6.png");
	p.jump[6]=IMG_Load("jump7.png");

	
	p.bw=1;
	p.br=1;
	return p;
	
}



int collision(SDL_Surface *img1,SDL_Rect pos1,struct background b)
{
	int i;
	for (i=0;i<=b.i;i++)
	{

		if ((pos1.x+img1->w>b.postile[i].x) && (pos1.y+img1->h>b.postile[i].y) && pos1.x+img1->w<b.postile[i].x+b.tile->w)
		return i;
	}
	return -1;
}


struct player walk(struct player p,struct background b,SDL_Surface *screen,SDL_Event event)
{

	int i=0;
	int fps=15;
	int start;	
			
	SDL_Rect test;
	test.x=200;
	test.y=350;
	int k=-1;
	int e=0;
	while (p.posplayer.y+p.walk[0]->h!=b.postile[e].y && e<=b.i)
		{
			e++;
			
		}
		if (p.posplayer.x+p.walk[0]->w>=b.postile[e].x && p.posplayer.x<=b.postile[e].x+b.tile->w)
			{
			p.posplayer.y=b.postile[e].y-p.walk[0]->h;
			
			}


	Uint8 *keystate = SDL_GetKeyState(NULL);
	while (keystate[SDLK_RIGHT]||keystate[SDLK_d])
	{	
		
		e=0;
		p.posplayer.x=p.posplayer.x+5;

		k=collision(p.walk[i],p.posplayer,b);
		if (k>-1)	
		p.posplayer.x=b.postile[k].x-p.walk[i]->w;
		
		p=grav(p,p.walk[i],b,screen);
	
		start=SDL_GetTicks();
		blit_background(b,screen);
		SDL_BlitSurface(p.walk[i],NULL,screen,&p.posplayer);
		SDL_Flip(screen);
		i++;
		if (i==10)
			i=0;

		while (p.posplayer.y+p.walk[i]->h!=b.postile[e].y && e<=b.i)
		{
			e++;
			if (p.posplayer.x+p.walk[i]->w>=b.postile[e].x && p.posplayer.x<=b.postile[e].x+b.tile->w)
			{
			p.posplayer.y=b.postile[e].y-p.walk[i]->h;
			e=b.i+1;
			}
		}
		

 
		
		if (1000/fps>SDL_GetTicks()-start)
			SDL_Delay(1000/fps-(SDL_GetTicks()-start));
		SDL_PollEvent(&event);
		if (event.type==SDL_KEYDOWN)
			if (event.key.keysym.sym==SDLK_UP)
			{
				p.bw=0;
				p=jump(p,b,screen,event);
			}
		keystate = SDL_GetKeyState(NULL);
	}

	//blit_background(b,screen);
	//SDL_BlitSurface(p.walk[0],NULL,screen,&p.posplayer);
	//SDL_Flip(screen);
	return p;
}
void run(struct player p[],struct background b[],SDL_Surface *screen,SDL_Event event)
{
	int i=0;
	int j=0;
	int fps=20;
	int start;
	Uint8 *keystate = SDL_GetKeyState(NULL);


	int key[323]={0};
	SDL_EnableKeyRepeat(0,0);

	

	while (keystate[SDLK_LEFT]||keystate[SDLK_q])

	{	
		start=SDL_GetTicks();


		

			SDL_PollEvent(&event);
			 switch (event.type)
			{    
		    case SDL_KEYDOWN:
		        key[event.key.keysym.sym] =1;
		        break;
		    case SDL_KEYUP:
		        key[event.key.keysym.sym] =0;
		        break;
			 default:
               		 break;
			}
			if(key[SDLK_LEFT])

			{
				p[0].posplayer.x=p[0].posplayer.x+8;
				blit_background(b[0],screen);
				SDL_BlitSurface(p[0].run[i],NULL,screen,&p[0].posplayer);	
				i++;	
				if (i==8)
				i=0;
			}
			
		
			if(key[SDLK_q])
			{
				p[1].posplayer.x=p[1].posplayer.x+8;
				blit_background(b[1],screen);
				SDL_BlitSurface(p[1].run[j],NULL,screen,&p[1].posplayer);
				j++;
				if (j==8)
				j=0;	
			}
		
		
		

		
		



		SDL_Flip(screen);
		
		if (1000/fps>SDL_GetTicks()-start)
		SDL_Delay(1000/fps-(SDL_GetTicks()-start));

		//keystate = SDL_GetKeyState(NULL);
	}

	//blit_background(b,screen);
	//SDL_BlitSurface(p.walk[0],NULL,screen,&p.posplayer);
	//SDL_Flip(screen);	
	
}


struct player grav (struct player p,SDL_Surface *img,struct background b,SDL_Surface *screen)
{
	int i=4;
	int fps=15;
	int velocity =1;
	int start;
	int k=-1;
	
		
	int j=0;
		
		while (j<=b.i && k==-1)
		{
			j++;
			if (p.posplayer.x+img->w>=b.postile[j].x && p.posplayer.x<=b.postile[j].x+b.tile->w && p.posplayer.y+img->h<=b.postile[j].y )
			{
				k=j;
				while (p.posplayer.y+img->h+velocity*2<b.postile[j].y)
				{	
				
					velocity=velocity*2;
					p.posplayer.y=p.posplayer.y+velocity;

					start=SDL_GetTicks();
					blit_background(b,screen);
					SDL_BlitSurface(img,NULL,screen,&p.posplayer);
					SDL_Flip(screen);
					if (1000/fps>SDL_GetTicks()-start)
					SDL_Delay(1000/fps-(SDL_GetTicks()-start));
				}
			}
		}
		if (k==j)
		{
			p.posplayer.y=b.postile[j].y-p.jump[i]->h;
			blit_background(b,screen);
			SDL_BlitSurface(img,NULL,screen,&p.posplayer);
			SDL_Flip(screen);
		}

	return p;
}
struct player jump(struct player p,struct background b,SDL_Surface *screen,SDL_Event event)
{

	int i=0;
	int fps=15;
	int velocity=2;
	int start;

	int k=-1;

	while (i<7)

	{	

		if (p.bw==0)//UP+WALK
		p.posplayer.x=p.posplayer.x+10;
		else if (p.br==0)
		p.posplayer.x=p.posplayer.x+8;

		

		velocity=velocity*2;

		if (i<=3)
		{
			p.posplayer.y=p.posplayer.y-50+velocity;

			start=SDL_GetTicks();
			blit_background(b,screen);
			SDL_BlitSurface(p.jump[i],NULL,screen,&p.posplayer);
			SDL_Flip(screen);
			i++;
			if (1000/fps>SDL_GetTicks()-start)
			SDL_Delay(1000/fps-(SDL_GetTicks()-start));
		}
		else
		{
			p=grav(p,p.jump[4],b,screen);
			i=20;
		}
		
	}

	//blit_background(b,screen);
	//SDL_BlitSurface(p.walk[0],NULL,screen,&p.posplayer);
	//SDL_Flip(screen);
	
	p.bw=1;
	p.br=1;
	return p;
}






