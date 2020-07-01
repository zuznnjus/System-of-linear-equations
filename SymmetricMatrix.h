#ifndef SYMMETRICMATRIX_H
#define SYMMETRICMATRIX_H

#pragma once

#include "Interval.h"
#include <QVector>


template <typename T>
class SymmetricMatrix
{
    repr_t getRepr(const float&);
    repr_t getRepr(const Interval<long double>&);

public:
    void solveSymMatrix(const int&, T**, T*, T*, QVector<repr_t>&, int&);
};

template<typename T>
repr_t SymmetricMatrix<T>::getRepr(const float &value)
{
    return {std::to_string(value), "", ""};
}

template<typename T>
repr_t SymmetricMatrix<T>::getRepr(const Interval<long double> &value)
{
    return value.getRepresentation();
}

template<typename T>
void SymmetricMatrix<T>::solveSymMatrix(const int& n, T** a, T* b, T* x, QVector<repr_t>& result, int& status)
{
    bool symmetry = true, determinant = true;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i < j) {
                if (a[i][j] != a[j][i]){
                    symmetry = false;
                    break;
                }
            }
        }
    }

    //TODO implementacja wyznacznika

    if (n < 1) status = 1;
    else if (!symmetry) status = 2;
    else if (!determinant) status = 3;
    else status = 0;

    if (status == 0) {
        long double sum, sum2, sumTmp, sumTmp2;

        T** L = new T* [n];
        for (int i = 0; i < n; ++i)
            L[i] = new T[n];

        T* D = new T[n];
        T* y = new T[n];

        T** c = new T* [n];
        for (int i = 0; i < n; ++i)
            c[i] = new T[n];

        D[0] = a[0][0];

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                sumTmp = 0;
                for (int k = 0; k < j; ++k) {
                    sumTmp += c[i][k] * L[j][k];
                }
                L[i][j] = (a[i][j] - sumTmp) / D[j];
                c[i][j] = D[j] * L[i][j];
            }
            sumTmp2 = 0;
            for (int k = 0; k < i; ++k) {
                sumTmp2 += c[i][k] * L[i][k];
            }
            D[i] = a[i][i] - sumTmp2;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) L[i][j] = 1;
                else if (i < j) L[i][j] = 0;
            }
        }

        for (int i = 0; i < n; ++i) {
            sum = 0;
            for (int j = 0; j < i; ++j) {
                sum += L[i][j] * y[j];
            }
            y[i] = b[i] - sum;
        }

        for (int i = n - 1; i >= 0; --i) {
            sum2 = 0;
            for (int j = i + 1; j < n; ++j) {
                sum2 += L[j][i] * x[j];
            }
            x[i] = y[i] / D[i] - sum2;
        }

        for (int i = 0; i < n; ++i)
        {
            delete[] L[i];
        }

        for (int i = 0; i < n; ++i)
        {
            delete[] c[i];
        }

        for (int i = 0; i < n; ++i)
        {
            result.push_back(getRepr(x[i]));
        }

        delete[] L;
        delete[] c;
        delete[] y;
        delete[] D;
    }
}




#endif // SYMMETRICMATRIX_H
