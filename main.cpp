#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "Elevator.h"
#include "ElevatorControlSystem.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Get integer input from the user for floors and elevators
    int rows;
        cout << "Enter num of floors (max 5): ";
        cin >> rows;

    int columns;
        cout << "Enter num of elevators (max 5): ";
        cin >> columns;
       Elevator elevators[columns];
       for(int i=0;i<columns;i++){

           elevators[i].setElevatorNumber(i+1);
           elevators[i].setCurrentFloor(1);
       }

    MainWindow w(rows, columns,elevators);
    w.show();

    return a.exec();
}
