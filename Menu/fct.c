#include"fct.h"
struct files back(struct files f)
{	
	Mix_PlayChannel(-1,f.effect2,0);
	f.y=1;//EXIT
	SDL_BlitSurface(f.image,NULL,f.screen,NULL);
	SDL_BlitSurface(f.play1,NULL,f.screen,&f.posnewgame);//2
	SDL_BlitSurface(f.setting1,NULL,f.screen,&f.possetting);
	SDL_BlitSurface(f.exit1,NULL,f.screen,&f.posquitter);
	SDL_BlitSurface(f.more1,NULL,f.screen,&f.posmore);
	SDL_BlitSurface(f.load1,NULL,f.screen,&f.posload);
	SDL_Flip(f.screen);
	//SDL_WarpMouse(f.posnewgame.x+(f.play1->w)/2,f.posnewgame.y+(f.play1->h)/2);
	return f;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int pos(SDL_Event event,SDL_Rect rect,SDL_Surface *img)
{
	if((event.button.x>rect.x) && (event.button.x<rect.x+img->w) && (event.button.y>rect.y) && (event.button.y<rect.y+img->h))
	return 1;
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int poz(int xmouse,int ymouse,SDL_Rect rect,SDL_Surface *img)
{
	if((xmouse>rect.x) && (xmouse<rect.x+img->w) && (ymouse>rect.y) && (ymouse<rect.y+img->h))
	return 1;
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct files Initialisation(struct files fl)
{
	//Fenetre
	//T_img[0]=screen;
	fl.screen=SDL_SetVideoMode(640,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
	fl.v=0;
	//Image
	
	fl.image=SDL_LoadBMP("bmpp.bmp");//load bmp
	//fl.image=IMG_Load("bggg.png");
	//fl.image=IMG_Load("bmpp.jpg");
	fl.back1=IMG_Load("back1.png");
	fl.back2=IMG_Load("back2.png");
	fl.newg=IMG_Load("newg.png");
	fl.exit1=IMG_Load("exit1.png");
	fl.exit2=IMG_Load("exit2.png");
	fl.setting1=IMG_Load("setting1.png");
	fl.setting2=IMG_Load("setting2.png");
	fl.play1=IMG_Load("play1.png");
	fl.play2=IMG_Load("play2.png");
	fl.volume1=IMG_Load("volume1.png");//load png
	fl.sbg=IMG_Load("sbg.png");
	fl.fullscreen1=IMG_Load("fullscreen1.png");
	fl.fullscreen2=IMG_Load("fullscreen2.png");
	fl.more1=IMG_Load("more1.png");
	fl.more2=IMG_Load("more2.png");
	fl.load1=IMG_Load("load1.png");
	
	fl.posload.x=(fl.screen->w)/2-(fl.load1->w)/2;
	fl.posload.y=130;
	fl.posfullscreen.x=(fl.screen->w)/2-((fl.fullscreen1->w)/2)*2;
	fl.posfullscreen.y=200;
	fl.possetting.x=(fl.screen->w)/2-(fl.setting1->w)/2;
	fl.possetting.y=210;	
	fl.posnewgame.x=(fl.screen->w)/2-(fl.play1->w)/2;
	fl.posnewgame.y=50;
	fl.posquitter.x=(fl.screen->w)/2-(fl.exit1->w)/2;
	fl.posquitter.y=370;
	fl.posmore.x=(fl.screen->w)/2-(fl.more1->w)/2;
	fl.posmore.y=290;
	fl.posback.x=(fl.screen->w)-(fl.back1->w);
	fl.posback.y=370;

	//Music
	Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
	fl.music=Mix_LoadMUS("theme.wav");//or .mp3
	
	Mix_PlayMusic(fl.music,-1);
	
	fl.effect1=Mix_LoadWAV("sound23.wav");//only .wav;
	fl.effect2=Mix_LoadWAV("chunkk.wav");
	

	//Display
	
	SDL_BlitSurface(fl.image,NULL,fl.screen,NULL);
	SDL_BlitSurface(fl.more1,NULL,fl.screen,&fl.posmore);
	SDL_BlitSurface(fl.play1,NULL,fl.screen,&fl.posnewgame);
	SDL_BlitSurface(fl.setting1,NULL,fl.screen,&fl.possetting);		
	SDL_BlitSurface(fl.exit1,NULL,fl.screen,&fl.posquitter);
	SDL_BlitSurface(fl.load1,NULL,fl.screen,&fl.posload);
	SDL_Flip(fl.screen);
	fl.x=0;
	fl.y=1;

	
	fl.times = TTF_OpenFont("reality1.ttf",20);
	fl.black.r=255,fl.black.g=0;fl.black.b=0;
	
	
	return fl;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct files play(struct files f,SDL_Event event)
{
	f.y=0;
							SDL_BlitSurface(f.newg,NULL,f.screen,NULL);
							SDL_Flip(f.screen);
							while (f.y==0)
							{
								alwen(event,f.back1,f.back2,f.posback,f.screen);
								while(SDL_PollEvent(&event))
								{
									switch(event.type)
									{
										case SDL_KEYUP://back (clavier)
										{
											switch( event.key.keysym.sym)
											{
												case SDLK_BACKSPACE:
												{
												f=back(f);	
												}break;
											}//switchkey
										}break;
										case SDL_MOUSEBUTTONUP:
										{
		                        						if ((event.button.button == SDL_BUTTON_LEFT) && pos(event,f.posback,f.back1))
											{//back->menu
												f=back(f);
											}
										}break;
										
										case SDL_QUIT:
										{
											f.x=1;
											f.y=1;
										}break;
											
											case SDL_KEYDOWN:
											{
												switch( event.key.keysym.sym)
												{
													case SDLK_ESCAPE://echap->quitter
													{f.x=1;f.y=1;}
													break;
													
												
											}break;
										}break;
								}//poll
									}//switch	
							}//while y==0
	return f;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct files setting(struct files f,SDL_Event event)
{	SDL_BlitSurface(f.sbg,NULL,f.screen,NULL);
	SDL_Flip(f.screen);
	f.y=0;
	while (f.y==0)
	{
		alwen(event,f.back1,f.back2,f.posback,f.screen);
		alwen(event,f.fullscreen1,f.fullscreen2,f.posfullscreen,f.screen);	
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_MOUSEBUTTONUP:
				{
		                        if ((event.button.button == SDL_BUTTON_LEFT) && pos(event,f.posback,f.back1))
					{//back->menu
						f=back(f);
					}
					if ((event.button.button == SDL_BUTTON_LEFT) && pos(event,f.posfullscreen,f.fullscreen1))
					{
						if (f.v==0)//si normal--> go full
							{
								f.screen=SDL_SetVideoMode(640,480,32,SDL_HWSURFACE | SDL_FULLSCREEN);
								f.v=1;
								SDL_BlitSurface(f.sbg,NULL,f.screen,NULL);
								SDL_BlitSurface(f.fullscreen2,NULL,f.screen,&f.posfullscreen);
							}
							else 
							{
								f.screen=SDL_SetVideoMode(640,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
								f.v=0;
								SDL_BlitSurface(f.sbg,NULL,f.screen,NULL);
								SDL_BlitSurface(f.fullscreen1,NULL,f.screen,&f.posfullscreen);
							}

							
							
							
							SDL_Flip(f.screen);
					}
				}break;
										
				case SDL_QUIT:
				{
					f.x=1;
					f.y=1;
				}break;
				case SDL_KEYDOWN:
				{
					switch( event.key.keysym.sym)
					{
						case SDLK_BACKSPACE:
						{
							//Mix_VolumeMusic(0);//music
							//Mix_Volume(-1,0);//chunks
							f=back(f);
						}break;
						case SDLK_RIGHT://volume up
						{
							f.m=Mix_VolumeMusic(f.m+16)+16;
						}break;	
						case SDLK_LEFT://volume down
						{
							f.m=Mix_VolumeMusic(f.m-16)-16;
							if (f.m<0)	
							f.m=0;
						}break;	
						case SDLK_f://fullscreen
						{
							if (f.v==0)//si normal--> go full
							{
								f.screen=SDL_SetVideoMode(640,480,32,SDL_HWSURFACE | SDL_FULLSCREEN);
								f.v=1;
								SDL_BlitSurface(f.sbg,NULL,f.screen,NULL);
								SDL_BlitSurface(f.fullscreen2,NULL,f.screen,&f.posfullscreen);
							}
							else 
							{
								f.screen=SDL_SetVideoMode(640,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
								f.v=0;
								SDL_BlitSurface(f.sbg,NULL,f.screen,NULL);
								SDL_BlitSurface(f.fullscreen1,NULL,f.screen,&f.posfullscreen);
							}

							
							
							
							SDL_Flip(f.screen);
						}break;					
					}break;
				}
			}
		}
	}
	return f;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct files menu(struct files f,SDL_Event event)
{
	while(f.x==0)
	{		
		SDL_Flip(f.screen);
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
					f.x=1;
					break;
				case SDL_MOUSEBUTTONUP:
				{
                                	if ((event.button.button == SDL_BUTTON_LEFT) && pos(event,f.posquitter,f.exit1))
						f.x=1;//EXIT
				}
					break;

				case SDL_KEYDOWN:
				{
					switch( event.key.keysym.sym)
					{
						
						case SDLK_ESCAPE://echap->quitter
						f.x=1;
						break;

						case SDLK_j://j->play
							f=play(f,event);
						break;

						
						break;
	
						case SDLK_RETURN://Entrée
						{
         						Mix_PlayChannel(-1,f.effect2,0);
							SDL_GetMouseState(&(f.xmouse),&(f.ymouse));
							if (poz(f.xmouse,f.ymouse,f.posnewgame,f.play1))
							f=play(f,event);
							else if (poz(f.xmouse,f.ymouse,f.possetting,f.setting1))
							f=setting(f,event);
							else if (poz(f.xmouse,f.ymouse,f.posmore,f.more1))
							f=help(f,event);
							else if (poz(f.xmouse,f.ymouse,f.posquitter,f.exit1))
							f.x=1;
							
						}break;
						
						case SDLK_UP:
						{	
							SDL_GetMouseState(&(f.xmouse),&(f.ymouse));
	
							if (poz(f.xmouse,f.ymouse,f.posnewgame,f.play1))
							SDL_WarpMouse(f.posquitter.x+(f.exit1->w)/2,f.posquitter.y+(f.exit1->h)/2);

							else if (poz(f.xmouse,f.ymouse,f.posquitter,f.exit1))
							SDL_WarpMouse(f.posmore.x+(f.more1->w)/2,f.posmore.y+(f.more1->h)/2);

							else if (poz(f.xmouse,f.ymouse,f.possetting,f.setting1))
							SDL_WarpMouse(f.posnewgame.x+(f.play1->w)/2,f.posnewgame.y+(f.play1->h)/2);
							
							else if (poz(f.xmouse,f.ymouse,f.posmore,f.more1))
							SDL_WarpMouse(f.possetting.x+(f.setting1->w)/2,f.possetting.y+(f.setting1->h)/2);

							else SDL_WarpMouse(f.posnewgame.x+(f.play1->w)/2,f.posnewgame.y+(f.play1->h)/2);
						}break;
						case SDLK_DOWN:
						{
							SDL_GetMouseState(&(f.xmouse),&(f.ymouse));
	
							if (poz(f.xmouse,f.ymouse,f.posnewgame,f.play1))
							SDL_WarpMouse(f.possetting.x+(f.setting1->w)/2,f.possetting.y+(f.setting1->h)/2);

							else if (poz(f.xmouse,f.ymouse,f.posquitter,f.exit1))
							SDL_WarpMouse(f.posnewgame.x+(f.play1->w)/2,f.posnewgame.y+(f.play1->h)/2);

							else if (poz(f.xmouse,f.ymouse,f.possetting,f.setting1))
							SDL_WarpMouse(f.posmore.x+(f.more1->w)/2,f.posmore.y+(f.more1->h)/2);

							else if (poz(f.xmouse,f.ymouse,f.posmore,f.more1))
							SDL_WarpMouse(f.posquitter.x+(f.exit1->w)/2,f.posquitter.y+(f.exit1->h)/2);

							else SDL_WarpMouse(f.posnewgame.x+(f.play1->w)/2,f.posnewgame.y+(f.play1->h)/2);
						}break;
					}
				}break;
				case SDL_MOUSEBUTTONDOWN:
				{
					if (pos(event,f.posquitter,f.exit1) || pos(event,f.posnewgame,f.play1) || pos(event,f.possetting,f.setting1)|| pos(event,f.posmore,f.more1))
					Mix_PlayChannel(-1,f.effect2,0);
					if (pos(event,f.posnewgame,f.play1))//PLAY-souris
						f=play(f,event);
					else if(pos(event,f.possetting,f.setting1))
						{f=setting(f,event);}
					else if(pos(event,f.posmore,f.more1))
						f=help(f,event);
				}break;
			}//switch
		}//while poll
		if (event.type==SDL_MOUSEMOTION)//ta7rik souris == verif alwen
		{
		
					alwen(event,f.play1,f.play2,f.posnewgame,f.screen);
					alwen(event,f.setting1,f.setting2,f.possetting,f.screen);
					alwen(event,f.exit1,f.exit2,f.posquitter,f.screen);
					alwen(event,f.more1,f.more2,f.posmore,f.screen);
					
				}
		
		
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct files help(struct files f,SDL_Event event)
{
	SDL_BlitSurface(f.newg,NULL,f.screen,NULL);
	
	f.help=TTF_RenderText_Blended(f.times,"This game revolves around two brothers:",f.black);
	f.posline.x=(f.screen->w)/2-(f.help->w/2);
	f.posline.y=100;
	SDL_BlitSurface(f.help,NULL,f.screen,&f.posline);

	f.help=TTF_RenderText_Blended(f.times,"one who has been sentenced to death for a crime he did not commit",f.black);
	f.posline.x=(f.screen->w)/2-(f.help->w/2);
	f.posline.y=f.posline.y+f.help->h;
	SDL_BlitSurface(f.help,NULL,f.screen,&f.posline);

	f.help=TTF_RenderText_Blended(f.times,"and his younger sibling, a genuis who devises an elaborate plan ",f.black);
	f.posline.x=(f.screen->w)/2-(f.help->w/2);
	f.posline.y=f.posline.y+f.help->h;
	SDL_BlitSurface(f.help,NULL,f.screen,&f.posline);

	f.help=TTF_RenderText_Blended(f.times,"to help him escape prison by purposely getting himself imprisoned.",f.black);
	f.posline.x=(f.screen->w)/2-(f.help->w/2);
	f.posline.y=f.posline.y+f.help->h;
	SDL_BlitSurface(f.help,NULL,f.screen,&f.posline);
	f.y=0;
							
							while (f.y==0)
							{//cha3la
								alwen(event,f.back1,f.back2,f.posback,f.screen);
								while(SDL_PollEvent(&event))
								{
									switch(event.type)
									{
										case SDL_KEYUP://back (clavier)
										{
											switch( event.key.keysym.sym)
											{
												case SDLK_BACKSPACE:
												{
												f=back(f);	
												}break;
											}//switchkey
										}break;
										case SDL_MOUSEBUTTONUP:
										{
		                        						if ((event.button.button == SDL_BUTTON_LEFT) && pos(event,f.posback,f.back1))
											{//back->menu
												f=back(f);
											}
										}break;
										
										case SDL_QUIT:
										{
											f.x=1;
											f.y=1;
										}break;
											
											case SDL_KEYDOWN:
											{
												switch( event.key.keysym.sym)
												{
													case SDLK_ESCAPE://echap->quitter
													{f.x=1;f.y=1;}
													break;
													
												
											}break;
										}break;
								}//poll
									}//switch	
							}//while y==0
	return f;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void alwen(SDL_Event event,SDL_Surface *s1, SDL_Surface *s2,SDL_Rect posi,SDL_Surface *s)
{
	if (pos(event,posi,s1))
	{	
		SDL_BlitSurface(s2,NULL,s,&posi);
		SDL_Flip(s);	
	}
	else
	{
		SDL_BlitSurface(s1,NULL,s,&posi);
		SDL_Flip(s);
	}
}
