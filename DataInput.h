#ifndef DATAINPUT_H
#define DATAINPUT_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>

class DataInput : public QWidget
{
    Q_OBJECT
public:
    DataInput(int, int, QWidget *parent = nullptr);

    QLineEdit *size;
    QVector<QLineEdit*> matrixLeft;
    QVector<QLineEdit*> matrixRight;
    QVector<QLineEdit*> vectorLeft;
    QVector<QLineEdit*> vectorRight;

private slots:
    void input();

private:
    int n, method, arithmetic;
    QWidget *widget;
    QGridLayout *inputLayout;

    void matrixInput();
    void vectorInput(QString, int);
};

#endif // DATAINPUT_H
