#include "mainwindow.h"

#include <QApplication>
#include <TridiagonalMatrix.h>
#include <iostream>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Rozwiązywanie układów równań liniowych");
    w.show();
    return a.exec();

    /*int n = 3;
    std::string x = "2.9", y = "3.1";
    //std::cin >> x >> y;
    Interval<double> a[] = {Interval<double>(x, y, std::stod),2,3};
    Interval<double> b[] = {1,-1};
    Interval<double> c[] = {1,-1};
    Interval<double> d[] = {0,1,0};
    int status;
    TridiagonalMatrix<Interval<double>>* result = new TridiagonalMatrix<Interval<double>>();
    result->solveTriMatrix(n,a,b,c,d,status);
    for(int i=0; i<n; ++i){
        std::cout<<d[i].getLower()<<" "<<d[i].getUpper()<<std::endl;
        std::cout<<"getRepresentation()"<<std::endl;
        std::cout<<d[i].getRepresentation()[0]<<std::endl;
        std::cout<<d[i].getRepresentation()[1]<<std::endl;
        std::cout<<d[i].getRepresentation()[2]<<std::endl;
    }*/
    /*int n = 4;
    Interval<double> a[] = {-1.276,2.756,6.98376,0};
    Interval<double> b[] = {2.5473,0.827,0.0003};
    Interval<double> c[] = {0,4.72,8.9174};
    Interval<double> d[] = {1.2,7,3.333,0};
    int status;
    TridiagonalMatrix<Interval<double>>* result = new TridiagonalMatrix<Interval<double>>();
    result->solveTriMatrix(n,a,b,c,d,status);
    for(int i=0; i<n; ++i){
        //std::cout<<d[i].getLower()<<" "<<d[i].getUpper()<<std::endl;
        std::cout<<std::fixed<<d[i].getRepresentation()[0]<<",   "<<
        d[i].getRepresentation()[1]<<",   "<<
        d[i].getRepresentation()[2]<<std::endl;
    }*/
}

