#include "animation.h"


void drawanimatedplayer()
{

    /* Gestion du timer */

    if (player.frameTimer <= 0)
    // Si notre timer (un compte Ã  rebours en fait) arrive Ã  zÃ©ro
    {
        //On le rÃ©initialise

        player.frameTimer = TIME_BETWEEN_2_FRAMES;

        //Et on incrÃ©mente notre variable qui compte les frames de 1 pour passer Ã  la suivante

        player.frameNumber++;

        if(player.frameNumber >= player.sprite->w / PLAYER_WIDTH)
            player.frameNumber = 0;

    }
    //Sinon, on dÃ©crÃ©mente notre timer
    else
        player.frameTimer--;


    //Ensuite, on peut passer la main Ã  notre fonction
    drawplayer();


}
