#include"header.h"

void scrolling(perso *p,BACKGROUND *back, ENTITE_SECONDAIRE *e,int *min,int *max,entite_frog frog[],SDL_Rect *posbox, SDL_Rect *posdiam)
{    int j;  
if((p->posperso.x>=1200)&&(back->position.x<=8080)) //Width(stage)-Width(ecran) = Arret du scroll.
       {
         back->position.x+=30;
         p->posperso.x-=50;
         e->position.x-=30;
         posbox->x-=30;
         posdiam->x-=30;
         for(j=0;j<6;j++)
         frog[j].pos.x-=30;
       
         (*min)-=10;
         (*max)-=10;
        // entite->position.x-=10;
       }
 if((p->posperso.x<=800)&&(back->position.x>=0))
             {
         back->position.x-=30;
         p->posperso.x+=50;
         e->position.x+=30;
         posbox->x+=30;
         posdiam->x+=30;
         for(j=0;j<6;j++)
         frog[j].pos.x+=30;
         
         (*min)+=10;
         (*max)+=10;
          
        // entite->position.x+=10;
             }


}



