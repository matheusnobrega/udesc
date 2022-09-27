#include <stdio.h>
#include <stdlib.h>


void bisection(double(*f)(double), double a, double b, double n) {
	double fa = f(a);
	double fb = f(b);
	
	if (fa * fb >= 0) {
		printf("voce nao pode usar esse intercale");
        return 0;
	} else {
		int i;
		for (i = 0; i <n; i++) {
			double m = 0.5 * (a + b);
			double fm = f(m);
			
			if(fm == 0) {
				printf('voce enontrou uma raiz r =%.16f', m);
			}
			printf("x %d =  %.16f\n", i + 1, m);
			if (fa * fm < 0) {
				b = m;
			} else {
				a = m;
				fa = fm;
			}
		}
	}

}

int main() {
	double f(x) {
		return x*x -3;
	}
	double a = 1;
	double b = 2;
	int n = 10;
	bis(f,a,b,n);
}