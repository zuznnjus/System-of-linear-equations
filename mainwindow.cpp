#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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
    input = new DataInput(ui->comboBox->currentIndex(),
                  ui->comboBox_2->currentIndex());
}

void MainWindow::solveButtonClicked()
{
    if (checkInput())
        QMessageBox::warning(this, "Błąd","Wprowadź wszystkie dane");
    else
        output = new DataOutput(ui->comboBox->currentIndex(),
                       ui->comboBox_2->currentIndex(), input);
}

bool MainWindow::checkInput()
{
    bool wrongInput = false;

    if (input == nullptr){
        wrongInput = true;
    }
    else if (input->n < 1){
        wrongInput = true;
    }
    else if (input->method == 0){
        for (int i = 0; i < input->n*input->n; ++i){
            if (input->matrixLeft.at(i)->text().isEmpty()){
                wrongInput = true;
                break;
            }
            if (input->arithmetic == 2 && input->matrixRight.at(i)->text().isEmpty()){
                wrongInput = true;
                break;
            }
        }
        for (int i = 0; i < input->n; ++i){
            if (input->vectorLeft.at(i)->text().isEmpty()){
                wrongInput = true;
                break;
            }
            if (input->arithmetic == 2 && input->vectorRight.at(i)->text().isEmpty()){
                wrongInput = true;
                break;
            }
        }
    }
    else if(input->method == 1){
        for (int i = 0; i < 4*input->n - 2; ++i){
            if (input->vectorLeft.at(i)->text().isEmpty()){
                wrongInput = true;
                break;
            }
            if (input->arithmetic == 2 && input->vectorRight.at(i)->text().isEmpty()){
                wrongInput = true;
                break;
            }
        }
    }

    return wrongInput;
}
