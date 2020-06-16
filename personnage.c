#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "def.h"
#include "background.h"
#include "perssonage.h"
#include "jouer.h"
#include "mouvement.h"
#include "collision.h"
#include "coin.h"
#include "coeur.h"
#include "enemi.h"




#define gravity 9.81;
#define GRAVITY_SPEED 0.6
#define MAX_FALL_SPEED 5
#define JUMP_HEIGHT 14.5
#define SPEED 2
#define MAX_SPEED 7




void initialiser_perssonage (perssonage *p)
{
p->personnage=IMG_Load("frame/12.png");
p->frame=0;
p->rect.x=0;
p->rect.y=0;
p->rect.w=100;
p->rect.h=200;
p->xvelocity=2;
p->yvelocity=2;
p->delta_time=0.00;
p->one_jump=0;
p->onground=0;
p->vie=3;
p->score=0;
p->invincible=false;
p->current_time;
p->previous_time=0.00;
p->on_water=false;
}
/*********************************************************************************************************/
/*********************************************************************************************************/
void afficher_perssonage (perssonage *p,SDL_Surface *screen)
{
	SDL_BlitSurface(p->personnage,&p->rects[p->frame],screen,&p->rect);
}
/*************************************************************************************************************/
/*************************************************************************************************************/
void animation_right (perssonage *p)
{

	p->frame++;
	if (p->frame>=7)
		p->frame=1;
}
/*********************************************************************************************************/
/*********************************************************************************************************/
void actualiser_perssonage (perssonage *p)
{
	if (p->onground==1)
p->rect.y-=p->yvelocity;
	else p->rect.y+=p->yvelocity;

}



/*********************************************************************************************************/
/*********************************************************************************************************/
void setrects(SDL_Rect* clip)
{
clip[0].x=0;
clip[0].y=0;
clip[0].w=83;
clip[0].h=100;

clip[1].x=94;
clip[1].y=0;
clip[1].w=83;
clip[1].h=100;

clip[2].x=188;
clip[2].y=0;
clip[2].w=83;
clip[2].h=100;

clip[3].x=282;
clip[3].y=0;
clip[3].w=83;
clip[3].h=100;

clip[4].x=376;
clip[4].y=0;
clip[4].w=83;
clip[4].h=100;

clip[5].x=0;
clip[5].y=100;
clip[5].w=83;
clip[5].h=100;

clip[6].x=94;
clip[6].y=100;
clip[6].w=83;
clip[6].h=100;

/*clip[7].x=735;
clip[7].y=0;
clip[7].w=100;
clip[7].h=110;

clip[8].x=840;
clip[8].y=0;
clip[8].w=100;
clip[8].h=110;

clip[9].x=945;
clip[9].y=0;
clip[9].w=100;
clip[9].h=110;

clip[10].x=0;
clip[10].y=120;
clip[10].w=100;
clip[10].h=110;

clip[11].x=105;
clip[11].y=120;
clip[11].w=100;
clip[11].h=110;

clip[12].x=210;
clip[12].y=120;
clip[12].w=100;
clip[12].h=110;

clip[13].x=315;
clip[13].y=120;
clip[13].w=100;
clip[13].h=110;

clip[14].x=420;
clip[14].y=120;
clip[14].w=100;
clip[14].h=110;

clip[15].x=0;
clip[15].y=120;
clip[15].w=100;
clip[15].h=110;

clip[16].x=105;
clip[16].y=120;
clip[16].w=100;
clip[16].h=110;

clip[17].x=210;
clip[17].y=120;
clip[17].w=100;
clip[17].h=110;

clip[18].x=315;
clip[18].y=120;
clip[18].w=100;
clip[18].h=110;

clip[19].x=420;
clip[19].y=120;
clip[19].w=100;
clip[19].h=110;

clip[20].x=105;
clip[20].y=240;
clip[20].w=100;
clip[20].h=110;

clip[21].x=210;
clip[21].y=240;
clip[21].w=100;
clip[21].h=110;

clip[22].x=315;
clip[22].y=240;
clip[22].w=100;
clip[22].h=110;

clip[23].x=420;
clip[23].y=240;
clip[23].w=100;
clip[23].h=110;

clip[24].x=525;
clip[24].y=240;
clip[24].w=100;
clip[24].h=110;

clip[25].x=630;
clip[25].y=240;
clip[25].w=100;
clip[25].h=110;
*/
}



