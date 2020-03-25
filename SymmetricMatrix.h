#pragma once
class SymmetricMatrix
{
public:
	bool checkSymmetry(int n, long double** A);
	bool checkDeterminant(int n, long double** A);
	void createMatrixLD(int n, long double** A, long double** L, long double* D);

	long double* solveSymMat(int n, long double** A, long double* B);
};

