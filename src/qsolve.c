void qsolve()
{
	double input[4];
	double tobeSquared;
	double squared;
	double roots[3];
	input[0] = 1.2;
	input[1] = 4;
	input[2] = 2.45763;
	tobeSquared = (input[1] * input[1]) - (4 * input[0] * input[2]);
	squared = sqrt(tobeSquared);
	roots[0] = (-1 * input[1]) - squared;
	roots[1] = (-1 * input[1]) + squared;
	roots[0] = roots[0] * -1 / (2 * input[0]);
	roots[1] = roots[1] * -1 / (2 * input[0]);
	printf("The roots of this equation are %f and %f\n", roots[0], roots[1]);
}
