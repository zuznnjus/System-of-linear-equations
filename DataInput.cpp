#include "DataInput.h"
#include <QLabel>
#include <QScrollArea>
#include <QMessageBox>

DataInput::DataInput(int method, int arithmetic, QWidget *parent): QWidget(parent)
{
    this->method = method;
    this->arithmetic = arithmetic;

    QGridLayout *layout = new QGridLayout;

    QLabel *sizeLabel = new QLabel(tr("Rozmiar n:"));
    sizeN = new QLineEdit();
    layout->addWidget(sizeLabel, 0, 0);
    layout->addWidget(sizeN, 0, 1);

    sizeSubmitButton = new QPushButton("Zatwierdź");
    layout->addWidget(sizeSubmitButton, 1, 1);

    connect(sizeSubmitButton, SIGNAL(clicked()),this,SLOT(checkSizeN()));

    setWindowTitle("Wprowadzanie danych");
    this->setLayout(layout);
    this->show();
}

void DataInput::checkSizeN()
{
    n = sizeN->text().toInt();
    if (n < 1){
        QMessageBox::warning(this, "Błąd","n musi być liczbą całkowitą dodatnią");
    }
    else {
    connect(sizeSubmitButton, SIGNAL(clicked()),this,SLOT(input()));
    connect(sizeSubmitButton, SIGNAL(clicked()),this,SLOT(hide()));
    }
}

void DataInput::input()
{
    widget = new QWidget();
    inputLayout = new QGridLayout();

    //QScrollArea* scroller = new QScrollArea;
    //scroller->setWidget(widget);
    //layout->addWidget(scroller);



    switch(method){
        case 0:
            matrixInput();
            vectorInput("B", n*n, n, 0);
            break;
        case 1:
            vectorInput("A", 0, n, 0);
            vectorInput("B", n, n-1, 0);
            vectorInput("C", 2*n-1, n-1, 1);
            vectorInput("D", 3*n-2, n, 0);
            break;
    }

    QPushButton *submitButton = new QPushButton("Zatwierdź");
    inputLayout->addWidget(submitButton, (n+1)*n, 1);

    connect(submitButton, SIGNAL(clicked()),widget,SLOT(hide()));

    widget->setLayout(inputLayout);
    widget->show();
}


void DataInput::matrixInput()
{
    QLabel *matrixLabel;
    for (int i = 0; i < n*n; i++){
        matrixLabel = new QLabel(QString("Element macierzy: A [%1][%2]").arg(i/n).arg(i%n));
        matrixLeft.push_back(new QLineEdit());
        inputLayout->addWidget(matrixLabel, i, 0);
        inputLayout->addWidget(matrixLeft.last(), i, 1);

        if (arithmetic == 2){
            matrixRight.push_back(new QLineEdit());
            inputLayout->addWidget(matrixRight.last(), i, 2);
        }
    }
}

void DataInput::vectorInput(QString vectorName, int startAt, int vectorSize, int x)
{
    QLabel *vectorLabel;
    for (int i = 0; i < vectorSize; i++){
        vectorLabel = new QLabel(QString("Element wektora: %1 [%2]").arg(vectorName).arg(i+x));
        vectorLeft.push_back(new QLineEdit());
        inputLayout->addWidget(vectorLabel, startAt + i, 0);
        inputLayout->addWidget(vectorLeft.last(), startAt + i, 1);

        if (arithmetic == 2){
            vectorRight.push_back(new QLineEdit());
            inputLayout->addWidget(vectorRight.last(), startAt + i, 2);
        }
    }
}
