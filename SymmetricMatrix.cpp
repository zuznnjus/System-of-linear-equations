#include "SymmetricMatrix.h"

bool SymmetricMatrix::checkSymmetry(int n, long double** A)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			if (i < j) {
				if (A[i][j] != A[j][i]) {
					return false;
				}
			}
		}
	}
	return true;
}

bool SymmetricMatrix::checkDeterminant(int n, long double** A)
{
	int determinant = 1;  //dodac obliczanie wyznacznika
	if (determinant != 0) 
		return true;
	else 
		return false;
}

void SymmetricMatrix::createMatrixLD(int n, long double** A, long double** L, long double* D)
{
	long double sum, sum2;
	
	long double** C = new long double *[n];
	for (int i = 0; i < n; ++i)
		C[i] = new long double[n];

	D[0] = A[0][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			sum = 0;
			for (int k = 0; k < j; k++) {
				sum += C[i][k] * L[j][k];
			}
			L[i][j] = (A[i][j] - sum) / D[j];
			C[i][j] = D[j] * L[i][j];
		}
		sum2 = 0;
		for (int k = 0; k < i; k++) {
			sum2 += C[i][k] * L[i][k];
		}
		D[i] = A[i][i] - sum2;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) L[i][j] = 1;
			else if (i < j) L[i][j] = 0;
		}
	}
}

long double* SymmetricMatrix::solveSymMat(int n, long double** A, long double* B, long double* X)
{
	int st;
	long double sum, sum2;

	if (n < 1) st = 1;
	else if (!checkSymmetry(n,A)) st = 2;
	else if (!checkDeterminant(n,A)) st = 3;
	else st = 0;

	if (st == 0) {
		long double** L = new long double* [n];
		for (int i = 0; i < n; ++i)
			L[i] = new long double[n];

		long double* Y = new long double[n];
		long double* D = new long double[n];

		createMatrixLD(n, A, L, D);

		for (int i = 0; i < n; i++) {
			sum = 0;
			for (int j = 0; j < i; j++) {
				sum += L[i][j] * Y[j];
			}
			Y[i] = B[i] - sum;
		}

		for (int i = n-1; i >= 0; i--) {
			sum2 = 0;
			for (int j = i + 1; j < n; j++) {
				sum2 += L[j][i] * X[j];
			}
			X[i] = Y[i] / D[i] - sum2;
		}


		for (int i = 0; i < n; i++)
		{
			delete[] L[i];
		}
		delete[] L;
		delete[] Y;
		delete[] D;

	}
	else 
		return 0; //zrobic komunikat


}
