#include "DataInput.h"
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>

DataInput::DataInput(int method, int arithmetic, QWidget *parent): QWidget(parent)
{
    this->method = method;
    this->arithmetic = arithmetic;

    QGridLayout *layout = new QGridLayout;

    QLabel *sizeLabel = new QLabel(tr("Rozmiar n:"));
    size = new QLineEdit();
    layout->addWidget(sizeLabel, 0, 0);
    layout->addWidget(size, 0, 1);

    QPushButton *submitButton = new QPushButton("Zatwierdź");
    layout->addWidget(submitButton, 1, 1);

    connect(submitButton, SIGNAL(clicked()),this,SLOT(input()));
    connect(submitButton, SIGNAL(clicked()),this,SLOT(hide()));

    setWindowTitle("Wprowadzanie danych");
    this->setLayout(layout);
    this->show();
}

void DataInput::input()
{
    widget = new QWidget();
    inputLayout = new QGridLayout();

    //QScrollArea* scroller = new QScrollArea;
    //scroller->setWidget(widget);
    //layout->addWidget(scroller);

    n = size->text().toInt();

    switch(method){
        case 0:
            matrixInput();
            vectorInput("B",n*n);
            break;
        case 1:
            vectorInput("A",0);
            vectorInput("B",n);
            vectorInput("C",2*n);
            vectorInput("D",3*n);
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
    for (int i = 0; i < n*n; i++){
        QLabel *matrixLabel = new QLabel(QString("Element macierzy: A [%1][%2]").arg(i/n).arg(i%n));
        matrixLeft.append(new QLineEdit());
        inputLayout->addWidget(matrixLabel, i, 0);
        inputLayout->addWidget(matrixLeft.last(), i, 1);
        if (arithmetic == 2){
            matrixRight.append(new QLineEdit());
            inputLayout->addWidget(matrixRight.last(), i, 2);
        }
    }
}

void DataInput::vectorInput(QString vectorName, int startAt)
{
    for (int i = 0; i < n; i++){
        QLabel *vectorLabel = new QLabel(QString("Element wektora: %1 [%2]").arg(vectorName).arg(i));
        vectorLeft.append(new QLineEdit());
        inputLayout->addWidget(vectorLabel, startAt + i, 0);
        inputLayout->addWidget(vectorLeft.last(), startAt + i, 1);
        if (arithmetic == 2){
            vectorRight.append(new QLineEdit());
            inputLayout->addWidget(vectorRight.last(), startAt + i, 2);
        }
    }
}
