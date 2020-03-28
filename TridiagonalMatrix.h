#pragma once
#include "Matrix.h"

class TridiagonalMatrix: public Matrix
{
public:
	long double* solveTriMat(int n, long double* A, long double* B, long double* C, long double* D);
};

