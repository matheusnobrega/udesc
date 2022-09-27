#include <stdio.h>
#include <math.h>
void newton(double (*f)(double), double (*df)(double), double(x0), int n) {
	int i, j;
	
	for(i=0; i< n; i++) {
		double dfx0 = df(x0);
		if(dfx0 == 0) {
			break;
		}
		
		double xi = x0 - f(x0) /dfx0;
		printf("x_%d = %.16f\n", i+1, xi);
		x0 = xi;
	}
}

int main() {
	double pi = 3.14159265358;
	
	double f(double x) {
		return (pi * pow(x, 2)) * (((3 * 4.27) - x)/3) - 199.21;
	}
	
	double df(double x) {
		return 1.04719 * (25.62* x - 3*pow(x, 2));
	}
	double x0 = 1.23  ;
	int n = 5;
	
	newton(f, df, x0, n);
}



