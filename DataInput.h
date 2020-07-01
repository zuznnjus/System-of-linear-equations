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
    DataInput(QWidget *parent = nullptr);
    DataInput(int, int, QWidget *parent = nullptr);

    QLineEdit *sizeN;
    QVector<QLineEdit*> matrixLeft;
    QVector<QLineEdit*> matrixRight;
    QVector<QLineEdit*> vectorLeft;
    QVector<QLineEdit*> vectorRight;
    int n;

private slots:
    void input();

private:
    int method, arithmetic;
    QWidget *widget;
    QGridLayout *inputLayout;

    void matrixInput();
    void vectorInput(QString, int);
};

#endif // DATAINPUT_H
