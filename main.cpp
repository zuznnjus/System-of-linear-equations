#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Rozwiązywanie układów równań liniowych");
    w.show();
    return a.exec();
}

