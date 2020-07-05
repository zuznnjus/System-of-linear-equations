#include "DataOutput.h"

#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QLabel>

using iarithm_t = Interval<long double>;

DataOutput::DataOutput(int method, int arithmetic, DataInput *input, QWidget *parent): QWidget(parent)
{
    this->method = method;
    this->arithmetic = arithmetic;
    this->input = input;

    layout = new QGridLayout;
    n = input->n;

    if (method == 0)
        prepareSymMatData();
    else
        prepareTriMatData();

    showResult();

    setWindowTitle("Wynik");
    this->setLayout(layout);
    this->show();
}

void DataOutput::prepareSymMatData()
{
    switch(arithmetic){
        case 0:
            {
            float** a = new float*[n];
            for (int i = 0; i < n; ++i)
                a[i] = new float[n];

            float* b = new float[n];
            float* x = new float[n];

            for (int i = 0; i < n; ++i){
                    b[i] = input->vectorLeft.takeFirst()->text().toFloat();
                    for (int j = 0; j < n; ++j)
                            a[i][j] = input->matrixLeft.takeFirst()->text().toFloat();
                }

            SymmetricMatrix<float> *symMat = new SymmetricMatrix<float>();
            symMat->solveSymMatrix(n, a, b, x, result, status);

            for (int i = 0; i < n; ++i)
                delete[] a[i];
            delete[] a;
            delete[] b;
            delete[] x;
            break;
            }

        case 1:
            {
            QString tmp;
            iarithm_t** a = new iarithm_t*[n];
            for (int i = 0; i < n; ++i)
                a[i] = new iarithm_t[n];

            iarithm_t* b = new iarithm_t[n];
            iarithm_t* x = new iarithm_t[n];

            for (int i = 0; i < n; ++i){
                    tmp = input->vectorLeft.takeFirst()->text();
                    b[i] = iarithm_t(tmp.toStdString(), tmp.toStdString(), std::stold);

                    for (int j = 0; j < n; ++j){
                            tmp = input->matrixLeft.takeFirst()->text();
                            a[i][j] = iarithm_t(tmp.toStdString(), tmp.toStdString(), std::stold);
                    }
                }

            SymmetricMatrix<iarithm_t> *symMatInt = new SymmetricMatrix<iarithm_t>();
            symMatInt->solveSymMatrix(n, a, b, x, result, status);

            for (int i = 0; i < n; ++i)
                delete[] a[i];
            delete[] a;
            delete[] b;
            delete[] x;
            break;
            }

        case 2:
        {
            iarithm_t** a = new iarithm_t*[n];
            for (int i = 0; i < n; ++i)
                a[i] = new iarithm_t[n];

            iarithm_t* b = new iarithm_t[n];
            iarithm_t* x = new iarithm_t[n];

            for (int i = 0; i < n; ++i){
                    b[i] = iarithm_t(input->vectorLeft.takeFirst()->text().toStdString(),
                                     input->vectorRight.takeFirst()->text().toStdString(), std::stold);

                    for (int j = 0; j < n; ++j)
                            a[i][j] = iarithm_t(input->matrixLeft.takeFirst()->text().toStdString(),
                                                input->matrixRight.takeFirst()->text().toStdString(), std::stold);
                }

            SymmetricMatrix<iarithm_t> *symMat = new SymmetricMatrix<iarithm_t>();
            symMat->solveSymMatrix(n, a, b, x, result, status);

            for (int i = 0; i < n; ++i)
                delete[] a[i];
            delete[] a;
            delete[] b;
            delete[] x;
            break;
        }
    }
}

void DataOutput::prepareTriMatData()
{
    switch(arithmetic){
        case 0:
            {
            float* a = new float[n];
            float* b = new float[n];
            float* c = new float[n];
            float* d = new float[n];

            for (int i = 0; i < n; ++i){
                a[i] = input->vectorLeft.takeFirst()->text().toFloat();
                d[n-i-1] = input->vectorLeft.takeLast()->text().toFloat();
            }

            for (int i = 0; i < n - 1; ++i){
                b[i] = input->vectorLeft.takeFirst()->text().toFloat();
                c[n-i-2] = input->vectorLeft.takeLast()->text().toFloat();
            }

            TridiagonalMatrix<float> *triMat = new TridiagonalMatrix<float>();
            triMat->solveTriMatrix(n, a, b, c, d, result, status);
            break;

            delete[] a;
            delete[] b;
            delete[] c;
            delete[] d;
            }

        case 1:
            {
            QString tmp;
            iarithm_t* a = new iarithm_t[n];
            iarithm_t* b = new iarithm_t[n];
            iarithm_t* c = new iarithm_t[n];
            iarithm_t* d = new iarithm_t[n];

            for (int i = 0; i < n; ++i){
                tmp = input->vectorLeft.takeFirst()->text();
                a[i] = iarithm_t(tmp.toStdString(), tmp.toStdString(), std::stold);
                tmp = input->vectorLeft.takeLast()->text();
                d[n-i-1] = iarithm_t(tmp.toStdString(), tmp.toStdString(), std::stold);
            }

            for (int i = 0; i < n - 1; ++i){
                tmp = input->vectorLeft.takeFirst()->text();
                b[i] = iarithm_t(tmp.toStdString(), tmp.toStdString(), std::stold);
                tmp = input->vectorLeft.takeLast()->text();
                c[n-i-2] = iarithm_t(tmp.toStdString(), tmp.toStdString(), std::stold);
            }

            TridiagonalMatrix<iarithm_t> *triMatInt = new TridiagonalMatrix<iarithm_t>();
            triMatInt->solveTriMatrix(n, a, b, c, d, result, status);

            delete[] a;
            delete[] b;
            delete[] c;
            delete[] d;
            break;
            }

        case 2:
            {
            iarithm_t* a = new iarithm_t[n];
            iarithm_t* b = new iarithm_t[n];
            iarithm_t* c = new iarithm_t[n];
            iarithm_t* d = new iarithm_t[n];

            for (int i = 0; i < n; ++i){
                a[i] = iarithm_t(input->vectorLeft.takeFirst()->text().toStdString(),
                                 input->vectorRight.takeFirst()->text().toStdString(), std::stold);
                d[n-i-1] = iarithm_t(input->vectorLeft.takeLast()->text().toStdString(),
                                     input->vectorRight.takeLast()->text().toStdString(), std::stold);
            }

            for (int i = 0; i < n - 1; ++i){
                b[i] = iarithm_t(input->vectorLeft.takeFirst()->text().toStdString(),
                                 input->vectorRight.takeFirst()->text().toStdString(), std::stold);
                c[n-i-2] = iarithm_t(input->vectorLeft.takeLast()->text().toStdString(),
                                     input->vectorRight.takeLast()->text().toStdString(), std::stold);
            }

            TridiagonalMatrix<iarithm_t> *triMat = new TridiagonalMatrix<iarithm_t>();
            triMat->solveTriMatrix(n, a, b, c, d, result, status);

            delete[] a;
            delete[] b;
            delete[] c;
            delete[] d;
            break;
            }
    }
}

void DataOutput::showResult()
{
    QLabel *label;
    QLabel *resultLabel;
    repr_t tmp;
    QString text;

    if(!result.isEmpty()){

        for (int i = 0; i < n; ++i){
            if (arithmetic == 0)
                text = "x[%1] =";
            else
                text = "x[%1] = [";
            label = new QLabel(text.arg(i));
            layout->addWidget(label, i, 0);
            tmp = result.takeFirst();
            resultLabel = new QLabel(QString("%1").arg(QString::fromStdString(tmp[0])));
            layout->addWidget(resultLabel, i, 1);

            if(arithmetic == 1 || arithmetic == 2){
                resultLabel = new QLabel(QString(",  %1 ]").arg(QString::fromStdString(tmp[1])));
                layout->addWidget(resultLabel, i, 2);
                resultLabel = new QLabel(QString(",  szerokość(x[%1]) = %2").arg(i).arg(QString::fromStdString(tmp[2])));
                layout->addWidget(resultLabel, i, 3);
            }
        }
        label = new QLabel(QString("status = %1").arg(status));
        layout->addWidget(label, n + 1, 0);
    }
    else {
         label = new QLabel(QString("Brak wyniku: status = %1").arg(status));
         layout->addWidget(label, 0, 0);
    }
}
