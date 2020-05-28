#include "TridiagonalMatrix.h"

void TridiagonalMatrix::solveTriMat(int n, long double* A, long double* B, long double* C, long double* D, int& status)
{
	if (n < 1) status = 1;
	//else if (!checkDeterminant(n,)) status = 2;
	else status = 0;

	if (status == 0) {
		long double* Y = new long double[n];
		long double* U = new long double[n - 1];

		Y[0] = D[0] / A[0];
		U[0] = B[0] / A[0];

		for (int i = 1; i < n-1; i++) {
			U[i] = B[i] / (A[i] - U[i - 1] * C[i+1]); //////// C + 1
		}
		for (int i = 0; i < n-1; i++) {
			Y[i + 1] = (D[i + 1] - C[i + 2] * Y[i]) / (A[i + 1] - U[i] * C[i + 2]); // C powiekszone o 1 - a chyba musi byc pomniejszone
		}

		D[n - 1] = Y[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			D[i] = Y[i] - U[i] * D[i + 1];
		}

		delete[] Y;
		delete[] U;
	}
}
