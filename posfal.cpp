#include <stdio.h>
#include <math.h>

void secante(double (*f)(double), double a, double b, int n) {
	int i;
	
	for (i = 0; i<n; i++) {
		double fa = f(a);
		double fb = f(b);
		if(fa * fb >= 0) {
			printf("nao vai\n");
			break;
		}
		double x1 = (a * fb - b*fa)/(fb-fa);
		
		printf("x_%d=%.16f\n", i+1, x1);
	
		
		double fx1 = f(x1);
		if (fa * fx1 < 0) {
			b = x1;
			fb = fx1;
		} else {
			a = x1;
			fa = fx1;
		}
	}
}


double f(double x) {
		double pi = 3.14159265358;
		return (pi * pow(x, 2)) * (((3 * 4.27) - x)/3) - 199.21;
	}
	
int main() {
	
	double a = 0;
	double b = 8.54;
	int n = 11;
	
	secante(f, a, b, n);
}

