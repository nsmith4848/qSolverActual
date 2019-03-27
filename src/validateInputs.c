//Name: Michael Steinman
//Class: CS 4900
//qSolver validateInputs.c

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int validateInputs(double [] in) {
	int ret = 0;
	if (0 == in[0]){
		ret = 2; //a == 0
	} else if (in[0] != in[0] || in[1] != in[1] || in[2] != in[2]){
		ret = 3; //One of the inputs is NaN
	} else if (in[0] < -FLT_MAX || in[0] > FLT_MAX 
	|| in[1] < -FLT_MAX || in[1] > FLT_MAX 
	|| in[2] < -FLT_MAX || in[2] > FLT_MAX){
		ret = 4; //One of the inputs is +/- Inf / out of float range	
	} else if (in[0] != (float)in[0] || in[1] != (float)in[1] || in[2] != (float)in[2]){
		ret = 5; //Float representation of value is not the same as double --> too many digits
	}
	//Check if number of digits stored is within bounds
	return ret;
}
