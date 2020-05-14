#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
typedef struct
{
SDL_Surface *ennemi;
SDL_Rect posennemi;
}enemy;

typedef struct
{
SDL_Surface *image;
SDL_Rect positionecran;
SDL_Surface *imageM;
}background;

typedef struct
{
SDL_Surface *mvt_avant[8];
SDL_Surface *mvt_back[8];
}mouvement;

void initialiser_ennemi (enemy *ennemi);
void initialiser_background(background *back);
void Remplissage_animation (mouvement *mvt);
void affichage_ennemi(SDL_Surface *ecran,enemy *ennemi);
void affichage_background(SDL_Surface *ecran,background *back);
void Deplacement_annime (mouvement *mvt,enemy *ennemi,background *back,SDL_Surface *ecran,int posMax,int posMin);

int deplacement_alea (int posmax,int posmin);

#endif // HEADER_H_INCLUDED
