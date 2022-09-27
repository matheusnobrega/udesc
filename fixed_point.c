#include <stdio.h>
#include <math.h>

double f(double x) {
		double pi = 3.14159265358;
		return pow(x, 4) + 2*pow(x, 2) - x - 3;
	}


double g(double x) {
	return (3*pow(x, 4) + 2*pow(x, 2) + 3)/(4*pow(x, 3) + 4*x - 1);
}

void fixed_point(double (*f)(double), double x0, int n) {
	int i;
	
	for (i=0; i<n; i++) {
		x0 = f(x0);
		printf("x_%d = %.16f\n", i+1, x0);
	}
}

int main() {
	int n = 8;
	double x0 =  1.01281;
	
	fixed_point(g, x0, n);
}
