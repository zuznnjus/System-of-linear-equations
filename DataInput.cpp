#include "DataInput.h"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>

DataInput::DataInput(QWidget *parent): QWidget(parent)
{
    QGridLayout *layout = new QGridLayout;

    QLabel *sizeLabel = new QLabel(tr("Rozmiar n:"));
    size = new QLineEdit();
    layout->addWidget(sizeLabel, 0, 0);
    layout->addWidget(size, 0, 1);

    QPushButton *submitButton = new QPushButton("Zatwierdź");
    layout->addWidget(submitButton, 1, 1);

    connect(submitButton, SIGNAL(clicked()),this,SLOT(matrixInput()));

    setWindowTitle("Wprowadzanie danych");
    this->setLayout(layout);
    this->show();
}

void DataInput::matrixInput()
{
    auto *widget = new QWidget();
    QGridLayout *layout = new QGridLayout;
    QString text;

    //QScrollArea* scroller = new QScrollArea;
    //scroller->setWidget(widget);
    //layout->addWidget(scroller);

    int n = size->text().toInt();

    for (int i = 0; i < n*n; i++){
        QLabel *matrixLabel = new QLabel(QString("Element macierzy: A[%1][%2]").arg(i/n).arg(i%n));
        matrix.append(new QLineEdit());
        layout->addWidget(matrixLabel, i, 0);
        layout->addWidget(matrix.last(), i, 1);
    }

    for (int i = 0; i < size->text().toInt(); i++){
        QLabel *vectorLabel = new QLabel(QString("Element wektora: B[%1]").arg(i));
        vector.append(new QLineEdit());
        layout->addWidget(vectorLabel, n*n + i, 0);
        layout->addWidget(vector.last(), n*n + i, 1);
    }

    QPushButton *submitButton = new QPushButton("Zatwierdź");
    layout->addWidget(submitButton, (n+1)*n, 1);

    //connect(submitButton, SIGNAL(clicked()),this,SLOT(matrixInput()));


    widget->setLayout(layout);
    widget->show();
}
