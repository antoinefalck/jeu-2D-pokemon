OBJETS=main.o histoire.o credits.o jeu.o dresseur.o

CC=gcc

CFLAGS=-Wall

main : $(OBJETS)
	$(CC) $(CFLAGS) $(OBJETS) -o main -lSDL -lSDL_ttf -lSDL_image

main.o : main.c histoire.h constantes.h 
	$(CC) $(CFLAGS) -c main.c

histoire.o : histoire.h histoire.c discours.h
	$(CC) $(CFLAGS) -c histoire.c

credits.o : credits.h credits.c discours.h
	$(CC) $(CFLAGS) -c credits.c

jeu.o : jeu.h jeu.c constantes.h dresseur.h
	$(CC) $(CFLAGS) -c jeu.c

dresseur.o : dresseur.h dresseur.c
	$(CC) $(CFLAGS) -c dresseur.c

clean :
	rm $(OBJETS)
