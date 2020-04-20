#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "head.h"

int main()
{
    SDL_Surface *ecran = NULL;
    int continuer =1,direction=0,frame_limit=0,random,random_question,nbrvie=3,i;

    questions question;
    userinterface  ui;
    tete Tete;
    background back;

    SDL_Event event;
//initialiser
    random=initialiser_background(&back);
    initialiser_tete(&Tete,random);
    initialiser_ui(&ui);
    random_question=initialiser_question(&question);

    SDL_Init(SDL_INIT_VIDEO);
//fps
    frame_limit=SDL_GetTicks()+33;
    limit_fps(frame_limit);
    frame_limit=SDL_GetTicks()+33;
//fin fps
    ecran=SDL_SetVideoMode(800,450,32,SDL_HWSURFACE |SDL_DOUBLEBUF);
    afficher_question(ecran,&question,&ui);
    affichage_background(ecran,&back);

    while (continuer)

    {
        SDL_PollEvent(&event);
//affichage
        //afficher_question(ecran,&question,&ui);
        //SDL_Flip(ecran);
        //affichage_background(ecran,&back);

        afficher_main(ecran,&back,&Tete,&ui,random,&continuer,&nbrvie,&question);
        //printf("%d\n",nbrvie);
        SDL_Flip(ecran);

        deplacer_tete(ecran,Tete.image_tete,&Tete.pos_tete,&direction);
        //printf("%d\n",Tete.pos_tete.x);

        SDL_Flip(ecran);
        switch (event.type)
        {
        case SDL_QUIT:
            continuer=0;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                continuer=0;
                break;
            case SDLK_UP:
                direction=1;

                break;
            case SDLK_DOWN:
                direction=-1;


                break;
            }
            break;
        }
    }
    SDL_FreeSurface(back.imagedefond);
    SDL_FreeSurface(Tete.image_tete);
    SDL_FreeSurface(back.image_masque);
    SDL_FreeSurface(ui.win);
    SDL_FreeSurface(ui.lose);
    for(i=0; i<6; i++)
        SDL_FreeSurface(ui.countdown[i]);
    SDL_FreeSurface(question.image_question);

    return 0;
}

