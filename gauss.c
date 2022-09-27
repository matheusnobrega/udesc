# include <stdio.h>
#include <math.h>
#define numRows  3
#define numCols  4

void print_matrix(double m[numRows][numCols]) {
	int i, j;
	
	for (i=0; i<numRows; i++) {
		for(j=0; j<numCols; j++) {
			printf("%.8f\t", m[i][j]);
		}
		printf("\n");
	}
}


void gauss(double E[numRows][numCols]) {
	int i, j, k, p;
	 
	for (j=0; j<numCols-1; j++) {
		for (i=j; i< numRows; i++) {
			if (E[i][j] != 0) {
				if (i != j) {
					for (k=0; k<numCols; k++) {
						double temp = E[i][k];
						E[i][k] = E[j][k];
						E[j][k] = temp;
					}
				}
				for(k=0; k<numRows; k++) {
					if (k==j) {
						continue;
					}
					double m = -E[k][j] / E[j][j];
					for (p=j; p<numCols; p++) {
						E[k][p] = m * E[j][p] + E[k][p];
					}
				}
				printf("\n");
				print_matrix(E);
				break; 
			}
		}
	}
	for (i=0;i<numRows;i++) {
		double xi = E[i][numCols-1] / E[i][i];
		printf("x_%d = %.16f\n", i+1,xi);
	}
}



int main() {
	int A = 40;
	int B = 28;
	double cosA = 0.57357644;
	double cosB = 0.5591929;
	double cosA90 = 0.81915204;
	double cosB90 = 0.82903757;
	double F = 2414.0;
	double E[numRows][numCols] = {
		{49, 34, 28, 3347},
		{23, 59, 21, 3064},
		{28, 7, 51, 2724}
	};
	
	print_matrix(E);
	gauss(E);
}

//
//{5, -8, 2},
//		{-6, 5, 1},
//		{2, -8, -6}
