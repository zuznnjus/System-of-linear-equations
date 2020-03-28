#include "InputData.h"
#include <iostream>

int InputData::chooseMethod()
{
	int option;

	std::cout << "Jaka metoda chcesz obliczyc uklad rownan?" << std::endl;
	do {
		std::cout << "1 - macierz symetryczna\n 2 - macierz trojdiagonalna metoda Crouta" << std::endl;
		std::cin >> option;
	} while (option != 1 || option != 2);

	return option;
}

void InputData::enterArray1D(int n, long double* array)
{
	for (int i = 0; i < n; i++) {
		std::cin >> array[i];
	}
}

void InputData::enterArray2D(int n, long double** array)
{
	std::cout << "Podaj elementy macierzy wspolczynnikow A:" << std::endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> array[i][j];
		}
	}
}

void InputData::enterDataSymMat(int n, long double** A, long double* B)
{
	std::cout << "Podaj liczbe rownan n: ";
	std::cin >> n;

	enterArray2D(n, A);

	std::cout << "Podaj elementy wektora B" << std::endl;
	enterArray1D(n, B);
}

void InputData::enterDataTrimMat(int n, long double* A, long double* B, long double* C, long double* D)
{
	std::cout << "Podaj liczbe n rownan: ";
	std::cin >> n;

	std::cout << "Podaj elementy wektora A" << std::endl;
	enterArray1D(n, A);

	std::cout << "Podaj elementy wektora B" << std::endl;
	enterArray1D(n, B);

	std::cout << "Podaj elementy wektora C" << std::endl;
	enterArray1D(n, C);

	std::cout << "Podaj elementy wektora D" << std::endl;
	enterArray1D(n, D);
}

