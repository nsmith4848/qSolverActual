//Name: Michael Steinman & Nic Smith
//Class: CS 4900
//qSolver qSolve.c

#include "qSolve.h"
#include "logging.h"

void qSolve(double in[3], double roots[3], int log, FILE *fp) {
	if(log){
		logging(in, roots, -1, -1, 0, 4, fp);
	}
	int i;
	for(i = 0; i < 3; i++){
		if(log){
			logging(in, roots, i, 0, 4, 3, fp);
		}
		validateInputs(in[i], i, 0, log, fp);
	}
	if (0 == in[1]*in[1] - 4*in[0]*in[2]){
		roots[2] = 1;
	} else if (0 < in[1]*in[1] - 4*in[0]*in[2]){
		roots[2] = 2;
	} else {
		roots[2] = 0;
	}
	if (0 < roots[2]){
		roots[0] = -1 * (-1*in[1] + sqrt(in[1]*in[1] - 4*in[0]*in[2])) / (2*in[0]);
	}
	if (1 < roots[2]){
		roots[1] = -1 * (-1*in[1] - sqrt(in[1]*in[1] - 4*in[0]*in[2])) / (2*in[0]);
	}
}
