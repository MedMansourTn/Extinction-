prog:main.o  jouer.o personnage.o  enigme.o ex.o   enemy.o 
	gcc main.o  jouer.o  personnage.o   enigme.o ex.o   enemy.o  -o prog -lSDL -lSDL_ttf -lSDL_gfx -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -g

jeu.o:jouer.c
	gcc -c jeu.c -g

personnage.o:personnage.c
	gcc -c personnage.c -g


enemy.o:enemy.c
	gcc -c enemy.c -g

enigme.o:enigme.c
	gcc -c enigme.c -g
ex.o:ex.c
	gcc -c ex.c -g
