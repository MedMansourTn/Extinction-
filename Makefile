prog:ennemie.o main.o
	gcc ennemie.o main.o -o prog -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
ennemie.o:ennemie.c
	gcc -c ennemie.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
