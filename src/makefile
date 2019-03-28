CC=gcc
CFLAGS=-ggdb -Wall -pedantic -std=c11 -lm
DEPENDS=Source.c getLine.c validateInputs.c qSolve.c createOutput.c printOutput.c getLine.h validateInputs.h qSolve.h createOutput.h printOutput.h

build:
	$(CC) $(DEPENDS) $(CFLAGS)

clean:
	-rm -f *.o *.exe *.out

