#include <stdio.h>


void secante(double (*f)(double), double x0, double x1, int n) {
	int i;
	
	for (i = 0; i<n; i++) {
		double fx0 = f(x0);
		double fx1 = f(x1);
		if(fx0 == fx1) {
			break;
		}
		double x2 = (x0 * fx1 - x1*fx0)/(fx1-fx0);
		printf("x_%d=%.16f\n", i+2, x2);
		x0 = x1;
		x1 = x2;
	}
}

int main() {
	double pi = 3.14159265358;
	double f(double x) {
		return (pi * pow(x, 2)) * (((3 * 4.27) - x)/3) - 199.21;
	}
	
	double x0 = 0.51;
	double x1 = 7.53;
	int n = 5;
	
	secante(f, x0, x1, n);
}

