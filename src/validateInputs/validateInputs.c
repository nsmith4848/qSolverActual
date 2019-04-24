//Name: Michael Steinman & Nic Smith
//Class: CS 4900
//qSolver validateInputs.c

#include "validateInputs.h"
#include "logging.h"

int validateInputs(double in, int variableSpecifier, int boolRoots, int log, FILE *fp) {
	if(log){
		double dummyArray[3];
		logging(dummyArray, dummyArray, variableSpecifier, boolRoots, 0, 3, fp);
	}
	int ret = 0;
	float floatIn = (float)in;
	double diff = fabs(in - floatIn);
	double max;
	if (0 == in && 0 == variableSpecifier && 0 == boolRoots){
		ret = 2; //a == 0
	} else if (isnan(in)){
		ret = 3; //Input is NaN
	} else if (isinf(in)){
		ret = 4; //Input is +/- Inf / out of float range	
	}
	
	//credit: https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/
	if(in > floatIn){
		max = in;
	} else {
		max = floatIn;
	}
	if(diff > max * FLT_EPSILON && in != 0){
		ret += 5; //Input has significant loss of precision on conversion to float
	}
	if (1 < ret && 5 != ret){
		printf("Error! Argument %d (%f) ", variableSpecifier + 1, in);
	}
	if (2 == ret || 7 == ret){ //If user entered 0 for "a"
		printf("cannot be 0.\n");
	} else if (3 == ret || 8 == ret){ //If one of the inputs is NaN
		printf("is not a number.\n");
	} else if (4 == ret || 9 == ret){ //If one of the inputs is outside of float range
		printf("is either too small or too large.\n");	
	}
	if (4 < ret){
		printf("Warning! Significant precision lost in float conversion from %f to %f!\n", in, floatIn);
	}
	
	
	return ret;
}
