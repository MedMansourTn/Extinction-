#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "head.h"
#include <time.h>
//initialiser
void initialiser_tete (tete *Tete,int random)
{
    switch(random)
    {
    case 1:
        Tete->pos_tete.x=33;
        Tete->pos_tete.y=400;
        break;
    case 2:
        Tete->pos_tete.x=33;
        Tete->pos_tete.y=333;
        break;
    case 3:
        Tete->pos_tete.x=32;
        Tete->pos_tete.y=77;
        break;
    case 4:
        Tete->pos_tete.x=33;
        Tete->pos_tete.y=20;
        break;
    case 5:
        Tete->pos_tete.x=33;
        Tete->pos_tete.y=270;
        break;
    case 6:
        Tete->pos_tete.x=33;
        Tete->pos_tete.y=412;
        break;
    }

    Tete->image_tete=IMG_Load("tete2.png");


}
int initialiser_background(background *back)
{
    srand(time(NULL));
    int rand_num = (rand() % (1 - 8 + 1)) + 1;
    //int rand_num=6;
    back->pos_fond.x=0;
    back->pos_fond.y=0;
    back->pos_masque.x=0;
    back->pos_masque.y=0;
    switch(rand_num)
    {
    case 1:
        back->imagedefond=IMG_Load("image/background/alea1.png");
        back->image_masque=SDL_LoadBMP("image/masque/alea1_mas.bmp");
        break;
    case 2:
        back->imagedefond=IMG_Load("image/background/alea2.png");
        back->image_masque=SDL_LoadBMP("image/masque/alea2_mas.bmp");
        break;
    case 3:
        back->imagedefond=IMG_Load("image/background/alea3.png");
        back->image_masque=SDL_LoadBMP("image/masque/alea3_mas.bmp");
        break;
    case 4:
        back->imagedefond=IMG_Load("image/background/alea4.png");
        back->image_masque=SDL_LoadBMP("image/masque/alea4_mas.bmp");
        break;
    case 5:
        back->imagedefond=IMG_Load("image/background/alea5.png");
        back->image_masque=SDL_LoadBMP("image/masque/alea5_mas.bmp");
        break;
    case 6:
        back->imagedefond=IMG_Load("image/background/alea6.png");
        back->image_masque=SDL_LoadBMP("image/masque/alea6_mas.bmp");
        break;

    }
//printf("%d\n",rand_num);
    return rand_num;
//return 6;
}
void initialiser_ui(userinterface *ui)
{
    ui->win=IMG_Load("win.png");
    ui->lose=IMG_Load("lose.png");
    ui->countdown[0]=IMG_Load("image/timer/1.png");
    ui->countdown[1]=IMG_Load("image/timer/2.png");
    ui->countdown[2]=IMG_Load("image/timer/3.png");
    ui->countdown[3]=IMG_Load("image/timer/4.png");
    ui->countdown[4]=IMG_Load("image/timer/5.png");
    ui->pos_win.x=50;
    ui->pos_win.y=100;
    ui->pos_lose.x=0;
    ui->pos_win.y=0;
    ui->pos_countdown.x=600;
    ui->pos_countdown.y=300;
}

int initialiser_question(questions *question)
{
    srand(time(NULL));
    int random = (rand() % (1 - 8 + 1)) + 1;
    //int random=3;
    question->pos_question.x=0;
    question->pos_question.y=0;
    switch(random)
    {
    case 1:
        question->image_question=IMG_Load("image/questions/ques1.png");
        question->reponse=11;
        break;
    case 2:
        question->image_question=IMG_Load("image/questions/ques2.png");
        question->reponse=10;
        break;
    case 3:
        question->image_question=IMG_Load("image/questions/ques3.png");
        question->reponse=12;
        break;
    case 4:
        question->image_question=IMG_Load("image/questions/ques4.png");
        question->reponse=12;
        break;
    case 5:
        question->image_question=IMG_Load("image/questions/ques5.png");
        question->reponse=10;
        break;
    case 6:
        question->image_question=IMG_Load("image/questions/ques6.png");
        question->reponse=12;
        break;

    }

    //return 3;
    return random;
}
//affichage
void afficher_main(SDL_Surface *ecran,background *back,tete *Tete,userinterface *ui,int random,int *continuer,int *nbrvie,questions *question)
{

    if(CollisionParfaite(*Tete,*back)==0)
    {
        affichage_tete(ecran,Tete);
    }
    //case win
    else if(CollisionParfaite(*Tete,*back)==question->reponse)
    {
        afficher_win(ecran,ui);
        SDL_Flip(ecran);
        SDL_Delay(1000);
        *continuer=0;
    }
    //case lose
    else if(CollisionParfaite(*Tete,*back)==1)
    {
        *nbrvie=*nbrvie-1;
        //printf("%d\n",*nbrvie);
        afficher_lose(ecran,ui);
        SDL_Flip(ecran);
        SDL_Delay(1000);
        if(*nbrvie==0)
            *continuer=0;
        else
        {
            SDL_Flip(ecran);
            afficher_question(ecran,question,ui);
            SDL_Flip(ecran);
            affichage_background(ecran,back);
            SDL_Flip(ecran);
            initialiser_tete(Tete,random);
        }

    }

}

void afficher_win(SDL_Surface *ecran,userinterface *ui)
{
    SDL_BlitSurface(ui->win, NULL,ecran,&ui->pos_win);

}

void afficher_lose(SDL_Surface *ecran,userinterface *ui)
{
    SDL_BlitSurface(ui->lose, NULL,ecran,&ui->pos_lose);
    SDL_Delay(1000);
}

void afficher_countdown(SDL_Surface *ecran,userinterface *ui)
{
    int i;
    for (i=4; i>=0; i--)
    {
//printf("%d\n",i);
        SDL_BlitSurface(ui->countdown[i],NULL,ecran,&ui->pos_countdown);

        SDL_Flip(ecran);
        SDL_Delay(1000);

    }
}

void affichage_tete(SDL_Surface *ecran,tete *Tete)
{
    //valeur delay  5
    SDL_Delay(5);
    SDL_BlitSurface(Tete->image_tete, NULL, ecran, &Tete->pos_tete);
}

void affichage_background(SDL_Surface *ecran,background *back )
{
    SDL_BlitSurface(back->imagedefond, NULL, ecran, &back->pos_fond);
}

void afficher_question(SDL_Surface *ecran,questions *question,userinterface *ui)
{
    SDL_BlitSurface(question->image_question, NULL, ecran, &question->pos_question);
    //printf("test\n");
    SDL_Flip(ecran);
    //SDL_Delay(5000);

    afficher_countdown(ecran,ui);
}

//deplacer
void deplacer_tete(SDL_Surface *ecran,SDL_Surface *image_tete,SDL_Rect *pos_tete,int *direction)
{

    if(*direction==0)

    {
        pos_tete->x=pos_tete->x+1;

    }
    if (*direction==1)
    {
        pos_tete->y=pos_tete->y-1;

        *direction=0;
    }
    if (*direction==-1)
    {
        pos_tete->y=pos_tete->y+1;

        *direction=0;
    }


}
//fps

void limit_fps(int limit)
{
    int ticks=SDL_GetTicks();
    if (limit <ticks)
        return;
    else if(limit >ticks+33)
        SDL_Delay(33);
    else
        SDL_Delay(limit-ticks);
}


//COLISION

SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y)
{
    SDL_Color color;
    Uint32 col=0;
//Determine position
    char* pPosition=(char* ) pSurface->pixels;
    pPosition+= (pSurface->pitch * y);
    pPosition+= (pSurface->format->BytesPerPixel *x);
    memcpy(&col,pPosition,pSurface->format->BytesPerPixel);
//convertir color
    SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
    return (color);
}

int CollisionParfaite(tete Tete,background back)
{
    SDL_Color couleur_obstacle;
    int X,Y,W,H;
    X=Tete.pos_tete.x;
    Y=Tete.pos_tete.y;
    W=Tete.pos_tete.w;
    H=Tete.pos_tete.h;
    SDL_Rect pos[8];
    pos[0].x=X;
    pos[0].y=Y;
    pos[1].x=X+W/2;
    pos[1].y=Y;
    pos[2].x=X+W;
    pos[2].y=Y;
    pos[3].x=X;
    pos[3].y=Y+H/2;
    pos[4].x=X;
    pos[4].y=Y+H;
    pos[5].x=X+W/2;
    pos[5].y=Y+H;
    pos[6].x=X+W;
    pos[6].y=Y+H;
    pos[7].x=X+W;
    pos[7].y=Y+H/2;
    int collision=0;
    int i=0;
    while((i<8) && (collision==0))
    {
        couleur_obstacle=GetPixel(back.image_masque,pos[i].x,pos[i].y);
        if((couleur_obstacle.r==255) && (couleur_obstacle.g==0) && (couleur_obstacle.b==0))
            collision=1;
        if((couleur_obstacle.r==0) && (couleur_obstacle.g==0) && (couleur_obstacle.b==255))
            collision=10;
        if((couleur_obstacle.r==255) && (couleur_obstacle.g==255) && (couleur_obstacle.b==0))
            collision=11;
        if((couleur_obstacle.r==0) && (couleur_obstacle.g==255) && (couleur_obstacle.b==0))
            collision=12;
        i++;
//32/75/155

//printf("%d/%d/%d\n",couleur_obstacle.r,couleur_obstacle.g,couleur_obstacle.b);
    }
    return collision;
}
//input
void input(int *continuer,SDL_Event *event,int *direction)
{
switch (event->type)
        {
        case SDL_QUIT:
            *continuer=0;
            break;
        case SDL_KEYDOWN:
            switch(event->key.keysym.sym)
            {
            case SDLK_ESCAPE:
                *continuer=0;
                break;
            case SDLK_UP:
                *direction=1;

                break;
            case SDLK_DOWN:
                *direction=-1;


                break;
            }
            break;
        }
    
}








