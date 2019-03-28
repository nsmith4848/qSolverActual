//Name: Michael Steinman
//Class: CS 4900
//qSolver

#include "qSolve.h"

double* qSolve(double* in) {
	double* roots = malloc(sizeof(double)*3); //[0] is root 1, [1] is root 2, [2] stores the number of roots
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
	
	return roots;
}
