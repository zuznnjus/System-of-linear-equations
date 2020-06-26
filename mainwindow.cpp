#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <DataInput.h>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->inputButton,SIGNAL(clicked()),this,SLOT(inputButtonClicked()));
    connect(ui->solveButton,SIGNAL(clicked()),this,SLOT(solveButtonClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inputButtonClicked()
{
    method = ui->comboBox->currentIndex();
    arithmetic = ui->comboBox_2->currentIndex();

    switch(method){
    case 0:
        if(arithmetic==2){

        }
        else{
            new DataInput();
        }
        break;
    case 1:
        if(arithmetic==2){

        }
        else{

        }
        break;
    }
}

void MainWindow::solveButtonClicked()
{

}
