#include <stdio.h>
#include <stdlib.h>
#include "savegame.h"




void sauvegarder_stage (perssonage *p, int *stage,background *b)
{
	int a=1;
	FILE *f;
   
	f=fopen("savings.txt", "wb");

	fwrite(p, sizeof(perssonage), 1, f);
	fwrite(stage, sizeof(int), 1, f);
	fwrite(b,sizeof(background),1,f);

	fclose(f);
	
	FILE* fichier = NULL;

    fichier = fopen("saves.txt", "w");

 

    if (fichier != NULL)

    {
            fprintf(fichier, "%d",a );

        fclose(fichier);

    }
   
}

void load_game (perssonage *p, int *stage , background *b)
{

	FILE *f=fopen("savings.txt","rb");

	if(f==NULL)
	{
	     printf("Erreur !");
	}
	
	
	else
	{
		//printf("loading");
		fread(p, sizeof(perssonage), 1, f);	
		fread(stage, sizeof(int), 1, f);
		fread(b, sizeof(background), 1, f);
	}

	fclose(f);
}