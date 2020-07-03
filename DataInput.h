#ifndef DATAINPUT_H
#define DATAINPUT_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>

class DataInput : public QWidget
{
    Q_OBJECT
public:
    DataInput(int, int, QWidget *parent = nullptr);

    QLineEdit *sizeN;
    QVector<QLineEdit*> matrixLeft;
    QVector<QLineEdit*> matrixRight;
    QVector<QLineEdit*> vectorLeft;
    QVector<QLineEdit*> vectorRight;
    int n, method, arithmetic;

private slots:
    void input();
    void checkSizeN();

private:
    QWidget *widget;
    QGridLayout *inputLayout;
    QPushButton *sizeSubmitButton;

    void matrixInput();
    void vectorInput(QString, int, int, int);
};

#endif // DATAINPUT_H
