#include"fct.h"


int main ()
{	
	SDL_Init(SDL_INIT_EVERYTHING);
	struct files f;
	TTF_Init();
	f=Initialisation(f);
	
	SDL_Event event;
	f=menu(f,event);
	
	SDL_FreeSurface(f.image);
	SDL_FreeSurface(f.play1);
	SDL_FreeSurface(f.play2);
	SDL_FreeSurface(f.setting1);
	SDL_FreeSurface(f.setting2);
	SDL_FreeSurface(f.exit1);
	SDL_FreeSurface(f.exit2);
	SDL_FreeSurface(f.fullscreen1);
	SDL_FreeSurface(f.fullscreen2);
	SDL_FreeSurface(f.back1);
	SDL_FreeSurface(f.back2);
	SDL_FreeSurface(f.more1);
	SDL_FreeSurface(f.more2);
	SDL_FreeSurface(f.load1);
	SDL_FreeSurface(f.help);
	Mix_FreeMusic(f.music);
	Mix_FreeChunk(f.effect1);
	Mix_FreeChunk(f.effect2);
	Mix_CloseAudio();

	TTF_CloseFont(f.times);
	TTF_Quit();
	SDL_Quit();
	return 0;
	
}

