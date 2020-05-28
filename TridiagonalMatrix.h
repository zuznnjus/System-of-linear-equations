#pragma once
#include "Matrix.h"

class TridiagonalMatrix: public Matrix
{
public:
	void solveTriMat(int n, long double* A, long double* B, long double* C, long double* D, int& status);
};

