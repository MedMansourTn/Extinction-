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




void mouvementright (perssonage *p)
{
if (p->xvelocity>=MAX_SPEED)
	p->xvelocity=MAX_SPEED;
if (p->rect.x<350)
p->rect.x=p->rect.x+p->xvelocity*p->delta_time;
}
/*********************************************************************************************/
/*********************************************************************************************/
void mouvementleft (perssonage *p)
{
if (p->xvelocity>=MAX_SPEED)
	p->xvelocity=MAX_SPEED;
if (p->rect.x>150)
p->rect.x=p->rect.x-p->xvelocity*p->delta_time;

}
/*********************************************************************************************/
/*********************************************************************************************/
void mouvementdown (perssonage *p)
{
if (p->xvelocity>=MAX_SPEED)
	p->xvelocity=MAX_SPEED;
p->rect.y=p->rect.y+p->xvelocity*p->delta_time;

}
/*********************************************************************************************/
/*********************************************************************************************/
void mouvementjump (perssonage *p)
{
	if (p->one_jump==1)
	{
		p->yvelocity-=JUMP_HEIGHT;
		//if (p->rect.y<=p->rect.y-p->yvelocity*p->delta_time)
		//p->rect.y=p->rect.y-p->yvelocity*p->delta_time;
		p->onground=0;
	}
}