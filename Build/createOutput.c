//Name: Michael Steinman
//Class: CS 4900
//qSolver

#include "createOutput.h"

char* createOutput(double* roots) {
	char* output;
	char* root1String = malloc(9*sizeof(char)); //9 = 6 sig figs + 1 '.' decimal + 1 '-' sign + 1 terminating character
	char* root2String = malloc(9*sizeof(char));
	if(0 == roots[2]){
		output = "There are no real roots\n";
	} else if (1 == roots[2]){
		output = malloc(34*sizeof(char)); //34 = size of root 1 string + string literal below
		strncpy(output, "There is one real root: ", 25);
		snprintf(root1String, 9, "%.6f", (float)roots[0]);
		strncat(output, root1String, 9);
	} else if (2 == roots[2]){
		//53 = size of root 1 string + root 2 string + string literals below + null terminating character
		output = malloc(53*sizeof(char)); 
		strncpy(output, "There are two real roots x1: ", 30);
		snprintf(root1String, 9, "%.6f", (float)roots[0]);
		snprintf(root2String, 9, "%.6f", (float)roots[1]);
		strncat(output, root1String, 9);
		strncat(output, " x2: ", 5);
		strncat(output, root2String, 9);
	}
	return output;
}
