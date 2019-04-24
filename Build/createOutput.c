//Name: Michael Steinman & Nic Smith
//Class: CS 4900
//qSolver createOutput.c

#include "createOutput.h"
#include "logging.h"

void createOutput(double roots[3], int log, FILE *fp) {
	if(log){
		logging(roots, roots, -1, -1, 0, 5, fp);
	}
	int i;
	if (1 == roots[2]){
		if(log){
			logging(roots, roots, 0, 1, 5, 3, fp);
		}
		validateInputs(roots[0], 0, 1, log, fp);
	} else if (2 == roots[2]){
		for(i = 0; i < 2; i++){
			if(log){
				logging(roots, roots, i, 1, 5, 3, fp);
			}
			validateInputs(roots[i], i, 1, log, fp);
		}
	}
	
	if(0 == roots[2]){
		printf("There are no real roots\n");
	} else if (1 == roots[2]){
		printf("There is one real root:\nx1: %f\n", roots[0]);
	} else if (2 == roots[2]){
		printf("There are two real roots:\n");
		if (roots[0] < roots[1]){
			printf("x1: %f\nx2: %f\n", roots[0], roots[1]);
		} else {
			printf("x1: %f\nx2: %f\n", roots[1], roots[2]);
		}
	}
	if(log){
		logging(roots, roots, -1, -1, 5, 5, fp);
	}
	
}
