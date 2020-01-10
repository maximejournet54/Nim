CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXE=nim

all: $(EXE)

nim: fonctions.o main.o
	$(CC) -o nim fonctions.o main.o $(LDFLAGS)

fonctions.o: fonctions.c
	$(CC) -o fonctions.o -c fonctions.c $(CFLAGS)

main.o: main.c jeu.h
	$(CC) -o main.o -c main.c $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXE)