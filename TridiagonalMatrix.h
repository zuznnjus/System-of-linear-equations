#pragma once
class TridiagonalMatrix
{
private:
	bool checkMatrix();
	long double** createMatrixL();
	long double** createMatrixU();

public:
	long double* solveTriMat(int n, long double* A, long double* B, long double* C, long double* D);
};

