prog:enigme.o main.o
	gcc enigme.o main.o -o prog -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf 
main.o:main.c
	gcc -c main.c
enigme.o:enigme.c
	gcc -c enigme.c
