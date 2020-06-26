#ifndef DATAINPUT_H
#define DATAINPUT_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>

class DataInput : public QWidget
{
    Q_OBJECT
public:
    DataInput(QWidget *parent = nullptr);

private slots:
    void matrixInput();

private:
    QLineEdit *size;
    QVector<QLineEdit*> matrix;
    QVector<QLineEdit*> vector;
};

#endif // DATAINPUT_H
