prog:Ennemi.o main.o
	gcc Ennemi.o main.o -o prog -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
Ennemi.o:Ennemi.c
	gcc -c Ennemi.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
