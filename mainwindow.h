#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <DataInput.h>
#include <DataOutput.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void inputButtonClicked();
    void solveButtonClicked();

private:
    Ui::MainWindow *ui;
    DataInput *input;
    DataOutput *output;
    bool checkInput();
};
#endif // MAINWINDOW_H
