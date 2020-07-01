#ifndef DATAOUTPUT_H
#define DATAOUTPUT_H

#include <QObject>
#include <QWidget>
#include "DataInput.h"
#include "SymmetricMatrix.h"
#include "TridiagonalMatrix.h"

class DataOutput : public QWidget
{
    Q_OBJECT
public:
    DataOutput(int, int, DataInput*, QWidget *parent = nullptr);

private:
    DataInput *input;
    QGridLayout *layout;
    QVector<repr_t> result;
    int n, status, method, arithmetic;

    void prepareSymMatData();
    void prepareTriMatData();
    void showResult();
};

#endif // DATAOUTPUT_H
