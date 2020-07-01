#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    output =new DataOutput(ui->comboBox->currentIndex(),
                   ui->comboBox_2->currentIndex(), input);
}
