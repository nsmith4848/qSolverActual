//Name: Michael Steinman & Nic Smith
//Class: CS 4900
//qSolver Source.c

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "getLine.h"
#include "validateInputs.h"
#include "qSolve.h"
#include "createOutput.h"
#include "logging.h"

#define NLINE 100

int main(int argc, char * argv[]) {
	double input[3]; //[0] is 'a', [1] is 'b', [2] is 'c'
	double roots[3]; //[0] is root 1, [1] is root 2, [2] stores the number of roots
	int errorCode;
	int cont;
	int i;
	int log = 0;
	FILE *fp;
	struct tm *sTm;
	time_t now = time (0);
	char timeBuffer[20];
	printf("-------------------\n");
	printf("qSolver v1\n");
	printf("Authors: Michael Steinman, Nic Smith\n");
	printf("Licensed under GPL-2.0-or-later\n");
	printf("Michael Steinman & Nic Smith hereby disclaims all copyright interest in the program “qSolver” (which computes the quadratic formula) written by Michael Steinman & Nic Smith.\n");
	printf("-------------------\n\n");
	printf("Input three numbers for a, b, and c in the quadratic formula to get their root values\nType 'help' for help or extra info about the program.\nType 'quit' to exit.\nType 'log' to enable logging.\n\n");
	if (1 < argc){
		log = 1;
		printf("Logging is enabled!\n");
		fp = fopen("log.txt", "a");
		if (NULL == fp){
			printf("Unable to open log.txt -> Logging disabled.\n");
		} else {
			//CREDIT: https://stackoverflow.com/questions/7411301/how-to-introduce-date-and-time-in-log-file
			sTm = gmtime(&now);
			strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", sTm);
			fprintf(fp, "\n---------------\n%s\n", timeBuffer);
		}
	}
	do {
		cont = 0;
		if(log){
			logging(input, roots, NLINE, -1, 1, 2, fp); //main -> getLine
		}
		errorCode = getLine(input, NLINE, log, fp);
		if(log){
			logging(input, roots, NLINE, -1, 2, 1, fp); //main -> getLine
		}
		if (1 == errorCode){ //If number of inputs is not 3
			printf("Error! Please enter 3 arguments.\n");
			cont = 1;
		} else if (-1 == errorCode) {
			printf("\n-------------------\n\n");
			printf("Input three numbers for a, b, and c in the quadratic formula to get their root values\nType 'help' for help or extra info about the program.\nType 'quit' to exit.\nType 'log' to enable logging.\n\n");
			cont = 1;
		} else if (-2 == errorCode) {
			printf("Exiting...\n\n");
		} else if (-1 < errorCode) {
			for(i = 0; i < 3; i++){
				if(log){
					logging(input, roots, i, 0, 1, 3, fp); //main -> validateInputs
				}
				errorCode = validateInputs(input[i], i, 0, log, fp);
				if(log){
					logging(input, roots, errorCode, -1, 3, 1, fp); //validateInputs --> main
				}
				if (errorCode > 0){
					cont = 1;
				}
			}
		}	
	} while(cont);
	
	if(log){
		logging(input, roots, -1, -1, 1, 4, fp); //main -> qSolve
	}
	qSolve(input, roots, log, fp);
	if(log){
		logging(input, roots, -1, -1, 4, 1, fp); //qSolve -> main
		logging(roots, roots, -1, -1, 1, 5, fp); //main -> createOutput
	}
	createOutput(roots, log, fp);
	if(log){
		fprintf(fp, "\n---------------\n\n");
		fclose(fp);
	}
}
