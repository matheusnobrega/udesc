#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void bisection(double(*f)(double), double a, double b, int n, double tol) {
	double fa = f(a);
	double fb = f(b);
	
	if (fa * fb >= 0) {
		printf("voce nao pode usar esse intervalo");
		return;
	} else {
		int i;
		for (i = 0; i <n; i++) {
			double m = 0.5 * (a + b);
			double fm = f(m);
			
			if(fm == 0) {
				printf("voce encontrou uma raiz r =%.7f", m);
				return;
			}
			
//			printf("x %d m  =  %.7f fa*fm = %.7f a = %.7f b = %.7f fa = %.7f fb = %.7f fm = %.7f\n", i + 1, m, fa * fm, a , b, fa, fb, fm);
			printf("x %d =  %.16f\n", i+1, m); 
//			
//			if (fabs(fm) < tol) {
//				printf("atingiu a tolerancia x %d = %.7f\n", i + 1, m);
//				return;
//			}
			if (fa * fm < 0) { // mudar para ZERO
				b = m;
			} else {
				a = m;
				fa = fm;
			}
		}
	}

}

int main() {
	double pi = 3.14159265358;
	double f(double x) {
		double Vs = (pi*pow(x, 2))/3 *(3*9.47 - x);
		return  1000*(Vs - (287.01*Vs)/1000) - 712.99*Vs;  //pw(Vs-V) = psVs;
	}
	double a = 0.1;
	double b = 3.08;
	int n = 12;
	double tol = 4.76228*pow(10, -8);
	bisection(f, a, b, n, tol);

}	
