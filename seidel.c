#include <stdio.h>

#define numRows 5
#define numCols 5

// só funciona para sistemas n x n
void seidel(double E[numRows][numCols], double chute[numRows], int n) {
	int i, j,k;
    for (i = 0; i < n; i++) {

        for (j = 0; j < numRows; j++) {
            double bj = E[j][numCols - 1];
            double soma = 0;
            for (k = 0; k < numCols - 1; k++) {
                if (k != j) {
                    soma += E[j][k] * chute[k];
                }
            }
            double xj = (bj - soma) / E[j][j];
            chute[j] = xj;
            printf("x_%d^(%d) = %.16f\t", j + 1, i + 1, xj);
        }
        printf("\n");

    }
}

int main() {
    double E[numRows][numCols] = {
        {11.13, -4.81, -2.37, 2.29, 0.68},
        {4.43, 10.12, -0.05, -3.98, 2.33},
        {4.74, -2.48, -12.36, -3.48, -1.9},
        {4.79, -4.87, 4.48, -15.8, 2.26}
    };
    double chute[numRows] = {2.94, -3.88, -3.2, -2.54};
    int n = 25;

    seidel(E, chute, n);
}
