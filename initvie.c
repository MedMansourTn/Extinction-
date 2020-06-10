#include "header.h"

void initialiser_vie(vie *vie)
{
vie->image_vie=IMG_Load("life.png");
vie->pos.w=vie->image_vie->w;
vie->pos.h=vie->image_vie->h/7;
vie->pos.x=0;
vie->pos.y=0;
}
