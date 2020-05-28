#pragma once
#include "Matrix.h"

class SymmetricMatrix: public Matrix
{
private:
	bool checkSymmetry(int n, long double** A);
	void createMatrixLD(int n, long double** A, long double** L, long double* D);

public:
	void solveSymMat(int n, long double** A, long double* B, long double* X, int& status);
};

