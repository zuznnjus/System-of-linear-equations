#pragma once
class SymmetricMatrix
{
public:
	bool checkSymmetry(int n, long double** A);
	bool checkDeterminant(int n, long double** A);
	long double** createMatrixL();
	long double** createMatrixD();

	long double* solveSymMat(int n, long double** A, long double* B);
};

