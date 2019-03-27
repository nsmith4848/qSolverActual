//Name: Michael Steinman
//Class: CS 4900
//qSolver floating point spike

#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char * argv[]) {
	long digits10 = 100000000000;
	float fpi = 3.14159265359;
	double dpi = 3.14159265359;
	printf("3.14159265359 .11f\nFloat:  %.11f\nDouble: %.11f\n", fpi, dpi);
	printf("3.14159265359 f\nFloat:  %f\nDouble: %f\n", fpi, dpi);
	float fpi2 = fpi * digits10;
	double dpi2 = dpi * digits10;
	printf("\n3.14159265359*100000000000\nFloat:  %.11f\nDouble: %.11f\n", fpi2, dpi2);
	
	float fpi3 = floor(fpi * digits10) / digits10;
	double dpi3 = floor(dpi * digits10) / digits10;
	printf("\nfloor(3.14159265359 * 100000000000) / 100000000000\nFloat:  %.11f\nDouble: %.11f\n", fpi3, dpi3);
	
	float fpi4 = floor(fpi * digits10);
	double dpi4 = floor(dpi * digits10);
	printf("\nfloor(3.14159265359 * 100000000000)\nFloat:  %.11f\nDouble: %.11f\n", fpi4, dpi4);
	
	if(fpi == dpi){
		printf("\n%.11f == %.11f\n", fpi, dpi);
	} else {
		printf("\n%.11f != %.11f\n", fpi, dpi);
	}
	
	float a = 5.0;
	float b = 13.0;
	float c = a / b;
	if(a / b == c){
		printf("%f / %f == %f\n", a, b, c);
	} else {
		printf("%f / %f == %f\n", a, b, c);
	}
	//test for digit overflow
}