/* Structure pour gérer notre héros */

   typedef struct Hero
   {
       //Sprite du héros (pas d'animation pour l'instant)
       SDL_Surface *sprite;

       /* Coordonnées du héros */
       int x, y;

   } Hero;
