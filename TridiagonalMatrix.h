#pragma once
#include "Interval.h"
#include <QVector>

template <typename T>
class TridiagonalMatrix
{
    repr_t getRepr(const float&);
    repr_t getRepr(const Interval<long double>&);
public:
    void solveTriMatrix(const int&, T*, T*, T*, T*, QVector<repr_t>&, int&);
};

template<typename T>
repr_t TridiagonalMatrix<T>::getRepr(const float &value)
{
    return {std::to_string(value), "", ""};
}

template<typename T>
repr_t TridiagonalMatrix<T>::getRepr(const Interval<long double> &value)
{
    return value.getRepresentation();
}

template<typename T>
void TridiagonalMatrix<T>::solveTriMatrix(const int& n, T* a, T* b, T* c, T* d, QVector<repr_t>& result, int& status)
{
    bool determinant = true;

    T* y = new T[n];
    T* u = new T[n - 1];
    T* L = new T[n];

    y[0] = d[0] / a[0];
    u[0] = b[0] / a[0];

    L[0] = d[0]/y[0];
    if(L[0] == 0){
        determinant = false;
    }

    for (int i = 1; i < n - 1; ++i) {
        u[i] = b[i] / (a[i] - u[i - 1] * c[i-1]);
    }

    for (int i = 0; i < n - 1; ++i) {
        if (a[i + 1] == u[i] * c[i]){
            determinant = false;
            break;
        }
        else{
        y[i + 1] = (d[i + 1] - c[i] * y[i]) / (a[i + 1] - u[i] * c[i]);

        L[i+1] = d[i+1]/y[i+1] - c[i+1];
        if (L[i+1] == 0){
            determinant = false;
            break;
        }
        }
    }

	if (n < 1) status = 1;
	else if (!determinant) status = 2;
	else status = 0;

	if (status == 0) {
		d[n - 1] = y[n - 1];

		for (int i = n - 2; i >= 0; --i) {
			d[i] = y[i] - u[i] * d[i + 1];
		}

        for (int i = 0; i < n; ++i) {
            result.push_back(getRepr(d[i]));
        }
	}

    delete[] y;
    delete[] u;
    delete[] L;
}
