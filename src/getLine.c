//Name: Michael Steinman
//Class: CS 4900
//qSolver getLine.c

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "getLine.h"


double* getLine() {
	double* ret = malloc(sizeof(int)*4); //[0] = a, [1] = b, [2] = c, [3] stores error codes, or 0 if there is no error
	int errCheck;
	printf("Enter values \"a b c\" space separated: ");
	errCheck = scanf("%lf %lf %lf", &ret[0], &ret[1], &ret[2]);
	printf("\n");
	if(3 != errCheck){
		ret[3] = 1; //When number of inputs is not 3
	}
	return ret;
}
