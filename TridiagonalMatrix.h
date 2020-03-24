#pragma once
class TridiagonalMatrix
{
	bool checkMatrix();
	long double** createMatrixL();
	long double** createMatrixU();

	long double* solveTriMat(int n, long double* A, long double* B, long double* C, long double* D);
};

