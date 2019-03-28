CC=gcc
CFLAGS=-ggdb -Wall -pedantic -std=c11 -lm
DEPENDS=Source.c getLine.c validateInputs.c getLine.h validateInputs.h

build:
	$(CC) $(DEPENDS) $(CFLAGS)

clean:
	-rm -f *.o *.exe *.out

