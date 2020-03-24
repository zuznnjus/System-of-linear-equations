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
	int determinant = 1;
	if (determinant != 0) 
		return true;
	else 
		return false;
}

long double** SymmetricMatrix::createMatrixL()
{
}

long double** SymmetricMatrix::createMatrixD()
{
}

long double* SymmetricMatrix::solveSymMat(int n, long double** A, long double* B)
{
	int st;
	if (n < 1) st = 1;
	else if (!checkSymmetry(n,A)) st = 2;
	else if (!checkDeterminant(n,A)) st = 3;
	else st = 0;

	if (st == 0) {

	}
	else return; //komunikat

}
