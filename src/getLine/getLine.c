//Name: Michael Steinman & Nic Smith
//Class: CS 4900
//qSolver getLine.c

#include "getLine.h"
#include "logging.h"

int getLine(double input[3], int NLINE, int log, FILE *fp) {
	if(log){
		logging(input, input, NLINE, -1, 0, 2, fp);
	}
	char line[NLINE];
	char *token;
	int ret = 0;
	int i = 0;
	printf("Enter values for \"a b c\" space separated: ");
	fgets(line, NLINE, stdin);
	printf("\n");
	if (0 == strncmp(line, "help", 4*sizeof(char))){
		printf("This program takes three space separated numbers (such as '15.2131 3.75 198275.6214' ");
		printf("and plugs them into the quadratic formula as if the first number input was the 'a' value, the second as 'b', and the third as 'c'\n");
		printf("If letters are included as input, the number will be treated as 0, unless the letters are ");
		printf("only after every digit of the number, in which case they will be ignored.");
		printf("The program also checks for invalid inputs that may be too large, too small, or are simply not a number. ");
		printf("It also checks for significant precision loss when input values and roots from double to float.\n");
		printf("Enter any command line argument to enable logging.\n");
		ret = -1;
	} else if (0 == strncmp(line, "quit", 4*sizeof(char))) {
		ret = -2;
	} else {
		token = strtok(line, " ");
		while(token != NULL){
			if(i < 3){
				input[i] = atof(token);
			}
			token = strtok(NULL, " ");
			i++;
		}
	}
	if(3 != i && ret > -1){
		ret = 1; //When number of inputs is not 3
	}
	return ret;
}
