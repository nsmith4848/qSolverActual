//Name: Michael Steinman
//Class: CS 4900
//qSolver

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "getLine.h"
#include "validateInputs.h"

int main(int argc, char * argv[]) {
	double* input;
	input = getLine();
	int errorCode = validateInputs(input);
	printf("%d\n", errorCode);
	
	free(input);
}
