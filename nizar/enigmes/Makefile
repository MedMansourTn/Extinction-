prog:main.o enigme.o
	gcc main.o enigme.o -o prog -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
enigme.o:enigme.c
	gcc -c enigme.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
