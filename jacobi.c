#define ROWS 3
#define COLS 3

void jacobi(double A[ROWS][ROWS], double B[ROWS], double x[ROWS], int n) {
	int i, j, k;
	double next[ROWS];
	for (k=0;k<n;k++) {
		for (i=0;i<ROWS; i++){
			double bi = B[i];
			for (j=0; j<ROWS;j++) {
				if (j!=i) {
					bi -= A[i][j] * x[j]; 
				}
			}
			bi /= A[i][i];
			printf("x_%d^(%d) = %.9f\t", i+1, k+1, bi);
			next[i] = bi;
		}
		printf("\n");
		for(i=0;i<ROWS;i++) {
				x[i] = next[i];
		}
	}
}


int main() {
	double A[ROWS][COLS] = {{--8.11, 4.65, -2.02}, 
							{0.63, -3.43, 1.35}, 
							{3.66, -3.78, -8.89}};
	double B[ROWS] = {-3.06, 3.45, -4.71};
	
	double chute[ROWS] = {1.5, 4.63, -0.06};
	int n = 19;
	
	jacobi(A, B, chute, n);
}
