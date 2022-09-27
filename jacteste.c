#include <stdio.h>

#define numRows 3
#define numCols 4

// só funciona para sistemas n x n
void jacobi(double E[numRows][numCols], double chute[numRows], int n) {
	int i, j,k;
    for (i = 0; i < n; i++) {
        double resp[numRows] = {};
        for (j = 0; j < numRows; j++) {
            double bj = E[j][numCols - 1];
            double soma = 0;
            for (k = 0; k < numCols - 1; k++) {
                if (k != j) {
                    soma += E[j][k] * chute[k];
                }
            }
            double xj = (bj - soma) / E[j][j];
            resp[j] = xj;
            printf("x_%d^(%d) = %.16f\t", j + 1, i + 1, xj);
        }
        printf("\n");
        for (i = 0; i < numRows; i++) {
            chute[i] = resp[i];
        }
    }
}

int main() {
    double E[numRows][numCols] = {
        -14.19, -4.49, -3.51, 4.96},
        {-1.49, -7.21, -3.1, 1.39},
        {4.97, -3.57, 13.06, 3.29},
        {3.16, 0.81, 2.25, 7.45}
    };
    double chute[numRows] = {1.66, 3.04, -0.94, 2.16};
    int n = 29;

    jacobi(E, chute, n);
}
