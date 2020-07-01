#include "DataOutput.h"

#include <QPushButton>
#include <QGridLayout>
#include <QLabel>

DataOutput::DataOutput(int method, int arithmetic, DataInput *input, QWidget *parent): QWidget(parent)
{
    this->method = method;
    this->arithmetic = arithmetic;
    this->input = input;

    layout = new QGridLayout;

    n = input->n;
    prepareSymMatData();
    showResult();

    setWindowTitle("Wynik");
    this->setLayout(layout);
    this->show();
}

void DataOutput::prepareSymMatData()
{
    switch (arithmetic){
        case 0:
            float** a = new float* [n];
            for (int i = 0; i < n; ++i)
                a[i] = new float[n];

            float* b = new float[n];
            float* x = new float[n];

            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (!input->matrixLeft.isEmpty() && !input->vectorLeft.isEmpty()){
                        a[i][j] = input->matrixLeft.takeFirst()->text().toFloat();
                        b[i] = input->vectorLeft.takeFirst()->text().toFloat();
                    }

            SymmetricMatrix<float> *symMat = new SymmetricMatrix<float>();
            symMat->solveSymMatrix(n, a, b, x, result, status);
            
            break;
    }
}

void DataOutput::prepareTriMatData()
{

}

void DataOutput::showResult()
{
    QLabel *label;
    QLabel *resultLabel;
    repr_t tmp;
    if(!result.isEmpty()){
    for (int i = 0; i < n; ++i){
        label = new QLabel(QString("Wektor wynikowy: x[%1] =").arg(i));
        layout->addWidget(label, i, 0);
        tmp = result.takeFirst();
        resultLabel = new QLabel(QString("%1").arg(i)); //QString::fromStdString(tmp[0])
        layout->addWidget(resultLabel, i, 1);
        }
    }
    else{
         label = new QLabel(QString("Brak wyniku: status = %1").arg(status));
         layout->addWidget(label, 0, 0);
    }
}


