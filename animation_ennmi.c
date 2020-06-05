int i;
int x;
int y;
SDL_RECT tableau_rectangles[6];
int pointeur_frame=0;
( for i=0;i<3;i++)
{
x=i*90;
y=0;
tableau_rectangles[pointeur_frame].x=x;
tableau_rectangles[pointeur_frame].y=y;
tableau_rectangles[pointeur_frame].w=90;
tableau_rectangles[pointeur_frame].h=130;
}
// on recommence pour la deuxiÃ¨me ligne
( for i=0;i<3;i++)
{
x=i*90;
y=130;
tableau_rectangles[pointeur_frame].x=x;
tableau_rectangles[pointeur_frame].y=y;
tableau_rectangles[pointeur_frame].w=90;
tableau_rectangles[pointeur_frame].h=130;
pointeur_frame++;
}
