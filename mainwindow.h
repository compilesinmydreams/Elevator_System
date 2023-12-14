#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Elevator.h"
#include "ElevatorControlSystem.h"
#include <QTableWidget>
#include <QTableWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int numRows, int numCols, Elevator elevators[], QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_13_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_help_clicked();

    void setElevator(int, int);

    void highlightCells(int, Elevator*);  // Change the parameter type to Elevator*

    void on_pushButton_11_clicked();

    void removeBackgroundColors();

    void on_pushButton_12_clicked();

     void updateButtonState(int value);

     void on_pushButton_1_clicked();

     void on_pushButton_2_clicked();

     void on_pushButton_3_clicked();

     void on_pushButton_4_clicked();

     void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    ElevatorControlSystem elevatorControlSystem;
};
#endif // MAINWINDOW_H
