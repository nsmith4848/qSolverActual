//Name: Michael Steinman
//Class: CS 4900
//qSolver getLine.c

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


double[] getLine() {
	double ret[4]; //[0] = a, [1] = b, [2] = c, [3] stores error codes, or 0 if there is no error
	int errCheck;
	errCheck = scanf("%f %f %f", ret[0], ret[1], ret[2]);
	if(3 != errCheck){
		ret[3] = 1; //When number of inputs is not 3
	}
	return ret;
}
