//Name: Michael Steinman & Nic Smith
//Class: CS 4900
//qSolver logging.c

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "logging.h"

void logging(double input[3], double roots[3], int intOne, int intTwo, int sender, int reciever, FILE *fp){
	int i;
	if (1 == sender){ //main sending
		fprintf(fp, "\nmain() passing variables\n");
		if (2 == reciever){ //getLine recieving
			fprintf(fp, "input[]\n");
			for(i = 0; i < 3; i++){
				fprintf(fp, "  - [%d]: %f\n", i, input[i]);
			}
			fprintf(fp, "NLINE: %d\nto getLine()\n\n", intOne);
		} else if (3 == reciever){ //validateInputs recieving
			fprintf(fp, "input[%d]: %f\n", intOne, input[intOne]);
			fprintf(fp, "variableSpecifier: %d\nboolRoots: %d\nto validateInputs()\n\n", intOne, intTwo);
		} else if (4 == reciever){ //qSolve recieving
			fprintf(fp, "input[]\n");
			for(i = 0; i < 3; i++){
				fprintf(fp, "  - [%d]: %f\n", i, input[i]);
			}
			fprintf(fp, "roots[]\n");
			for(i = 0; i < 3; i++){
				fprintf(fp, "  - [%d]: %f\n", i, roots[i]);
			}
			fprintf(fp, "to qSolve()\n");
		} else if (5 == reciever){ //createOutput recieving
			fprintf(fp, "roots[]\n");
			for(i = 0; i < 3; i++){
				fprintf(fp, "  - [%d]: %f\n", i, roots[i]);
			}
			fprintf(fp, "to createOutput()\n");
		}
	} else if (0 == sender){ //main called function that is calling logging()
		if (2 == reciever){ //getLine recieved
			fprintf(fp, "getLine() recieved variables\ninput[]\n");
			for(i = 0; i < 3; i++){
				fprintf(fp, "  - [%d]: %f\n", i, input[i]);
			}
			fprintf(fp, "NLINE: %d\nfrom main()\n\n", intOne);
		} else if (3 == reciever){ //validateInputs recieved
			fprintf(fp, "\validateInputs() recieved variables\ninput[%d]: %f\n", intOne, input[intOne]);
			fprintf(fp, "variableSpecifier: %d\nboolRoots: %d\nfrom main()\n\n", intOne, intTwo);
		} else if (4 == reciever){ //qSolve recieved
			fprintf(fp, "qSolve() recieved variable\ninput[]\n");
			for(i = 0; i < 3; i++){
				fprintf(fp, "  - [%d]: %f\n", i, input[i]);
			}
			fprintf(fp, "roots[]\n");
			for(i = 0; i < 3; i++){
				fprintf(fp, "  - [%d]: %f\n", i, roots[i]);
			}
			fprintf(fp, "from main()\n");
		} else if (5 == reciever){ //createOutput recieved
			fprintf(fp, "createOutput recieved variable\nroots[]\n");
			for(i = 0; i < 3; i++){
				fprintf(fp, "  - [%d]: %f\n", i, roots[i]);
			}
			fprintf(fp, "from main()\n");
		}
	} else if (2 == sender){ //getLine returns to main
		fprintf(fp, "main() recieved variables\ninput[]\n");
		for(i = 0; i < 3; i++){
			fprintf(fp, "  - [%d]: %f\n", i, input[i]);
		}
		fprintf(fp, "from getLine()\n");
	} else if (3 == sender){ //validateInputs returns to main
		fprintf(fp, "main() recieved variables\nerrorCode: %d\nfrom validateInputs\n", intOne);
	} else if (4 == sender){ //qSolve returns to... 
		if(1 == reciever){ //...main
			fprintf(fp, "main() recieved variable\ninput[]\n");
			for(i = 0; i < 3; i++){
				fprintf(fp, "  - [%d]: %f\n", i, input[i]);
			}
			fprintf(fp, "roots[]\n");
			for(i = 0; i < 3; i++){
				fprintf(fp, "  - [%d]: %f\n", i, roots[i]);
			}
			fprintf(fp, "from qSolve()\n");
		} else if (3 == reciever){ //qSolve calls validateInputs
			fprintf(fp, "\validateInputs() recieved variables\ninput[%d]: %f\n", intOne, input[intOne]);
			fprintf(fp, "variableSpecifier: %d\nboolRoots: %d\nfrom qSolve()\n\n", intOne, intTwo);
		}
	} else if (5 == sender){
		if (3 == reciever){ //createOutpout calls validateInputs
			fprintf(fp, "\validateInputs() recieved variables\nroots[%d]: %f\n", intOne, roots[intOne]);
			fprintf(fp, "variableSpecifier: %d\nboolRoots: %d\nfrom createOutput()\n\n", intOne, intTwo);
		} else if (5 == reciever){
			fprintf(fp, "\nRoots: %f", roots[2]);
		}
	}
}
