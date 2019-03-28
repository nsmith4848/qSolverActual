//Name: Michael Steinman
//Class: CS 4900
//qSolver

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "getLine.h"
#include "validateInputs.h"
#include "qSolve.h"
#include "createOutput.h"
#include "printOutput.h"

int main(int argc, char * argv[]) {
	double* input;
	double* roots;
	char* output;
	int errorCode;
	
	do {
		input = getLine();
		if (1 == input[3]){ //If number of inputs is not 3
		
			printf("Error! Please enter 3 arguments.\n");
		
		} else {
			errorCode = validateInputs(input);
			
			if (2 == errorCode){ //If user entered 0 for "a"
				printf("Error! \"a\" cannot be 0.\n");
			} else if (3 == errorCode){ //If one of the inputs is NaN
				printf("Error! At least one of the inputs is not a number.\n");
			} else if (4 == errorCode){ //If one of the inputs is outside of float range
				printf("Error! At least one of the inputs is either too small or too large.\n");
			} else if (5 == errorCode){ //If too many significant figures were entered for values to be precise
				printf("Warning! At least one of the inputs has too many significant figures for full precision.\n");
				errorCode = 0;
			}
			input[4] = errorCode;
		}	
	} while(0 != input[4]);
	
	roots = qSolve(input);
	output = createOutput(roots);
	printOutput(output);
	
	free(input);
	free(roots);
	free(output);
}
