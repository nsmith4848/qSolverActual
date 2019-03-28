//Name: Michael Steinman
//Class: CS 4900
//qSolver

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "createOutput.h"

int main(int argc, char * argv[]) {
	FILE *fptr = fopen("input.txt", "r");
	char *line = NULL;
	ssize_t lineSize;
	size_t BUFFSIZE = 20;
	char *token;
	
	if(fptr){
		while((lineSize = getline(&line, &BUFFSIZE, fptr)) != -1){
			double *roots = malloc(sizeof(double)*3);
			
			token = strtok(line, ",");
			int i = 0;
			while(token != NULL){
				if(token[1] == '\n'){
					i = -1;
				}
				roots[i] = atof(token);
				token = strtok(NULL, ",");
				i++;
			}
			roots[2] = i;
			char *output = createOutput(roots);
			printf("%s\n", output);
		}
	}
}
