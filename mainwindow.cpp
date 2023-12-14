
#include<iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ElevatorControlSystem.h"
#include "Doors.h"
#include "Elevator.h"
#include<array>
#include <QColor>
#include <QString>

using namespace std;
MainWindow::MainWindow(int numRows, int numCols, Elevator elevators[], QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      elevatorControlSystem()
{
    ui->setupUi(this);

    setElevator(numRows, numCols);
    highlightCells(numCols, elevators);
    elevatorControlSystem.initElevators(elevators,numCols);
    ui->pushButton_12->setDisabled(true);
    connect(ui->startFloor, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::updateButtonState);
    ui->label_3->setText("1");
    QPushButton* buttons[]={ui->pushButton_1,ui->pushButton_2,ui->pushButton_3,ui->pushButton_4,ui->pushButton_5,ui->pushButton_6};
    for(int i=0;i<numRows;i++){
        buttons[i]->setEnabled(true);
    }


}

MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::updateButtonState(int value) {
    // Adjust the condition based on your requirements
    if (value == ui->startFloor->maximum()) {
        ui->pushButton_11->setDisabled(true);
    } else {
        ui->pushButton_11->setDisabled(false);
    }

    if (value == ui->startFloor->minimum()) {
        ui->pushButton_12->setDisabled(true);
    } else {
        ui->pushButton_12->setDisabled(false);
    }
}


void MainWindow:: highlightCells(int col,Elevator el[]){
    for(int i=0;i<col;i++){
        QTableWidgetItem *item = new QTableWidgetItem();

            // Set the background color of the item
            item->setBackground(QColor(255, 255, 0));

            //cout<<"for highlight\nel num:"<<el[i].getElevatorNumber()<<" curr floor:"<<el[i].getCurrentFloor()<<endl;
            ui->tableWidget->setItem(el[i].getCurrentFloor()-1,el[i].getElevatorNumber()-1, item);
    }


}
void MainWindow::setElevator(int numRows, int numCols) {
    // Set the number of rows and columns in the table

    ui->tableWidget->setRowCount(numRows);
    ui->tableWidget->setColumnCount(numCols);
    ui->tableWidget->verticalHeader()->setVisible(true);
    ui->tableWidget->horizontalHeader()->setVisible(true);
    ui->startFloor->setRange(1,numRows);
}


void MainWindow::on_pushButton_13_clicked()
{
    elevatorControlSystem.sendEmergencyCalls(EmergencyType::FIRE,ui->label_3);
    //cout << "Emergency button clicked. Sending FIRE emergency call!\n"<<endl;
}



void MainWindow::on_pushButton_15_clicked()
{
    elevatorControlSystem.sendEmergencyCalls(EmergencyType::OVERLOAD,ui->label_3);
    //cout << "Emergency button clicked. Sending overload emergency call!\n"<<endl;
}


void MainWindow::on_pushButton_14_clicked()
{
    elevatorControlSystem.sendEmergencyCalls(EmergencyType::POWER_OUT,ui->label_3);
    //cout << "Emergency button clicked. Sending power out emergency call!\n"<<endl;

}


void MainWindow::on_pushButton_16_clicked()
{
    elevatorControlSystem.sendEmergencyCalls(EmergencyType::DOOR_OBSTACLE,ui->label_3);
}


void MainWindow::on_pushButton_17_clicked()
{
    elevatorControlSystem.sendEmergencyCalls(EmergencyType::EXTDOOR_OBSTACLE,ui->label_3);
}


void MainWindow::on_pushButton_9_clicked()
{
    Doors door;
    door.doorOpen(true);
}


void MainWindow::on_pushButton_10_clicked()
{
    Doors door;
    door.doorClose(true);
}


void MainWindow::on_pushButton_help_clicked()
{
    elevatorControlSystem.sendEmergencyCalls(EmergencyType::HELP,ui->label_3);
}


void MainWindow::on_pushButton_11_clicked()
{
    removeBackgroundColors();
    elevatorControlSystem.sendElevatorUp(ui->startFloor->value(),ui->tableWidget);
    ui->label_3->setText(QString::fromStdString(std::to_string(ui->startFloor->value())));
}
void MainWindow::removeBackgroundColors() {
    int numRows = ui->tableWidget->rowCount();
    int numCols = ui->tableWidget->columnCount();

    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            QTableWidgetItem* item = ui->tableWidget->item(row, col);
            if (item) {
                item->setBackground(QColor(Qt::transparent));
            }
        }
    }
}

void MainWindow::on_pushButton_12_clicked()
{
    removeBackgroundColors();
    elevatorControlSystem.sendElevatorUp(ui->startFloor->value(),ui->tableWidget);
    ui->label_3->setText(QString::fromStdString(std::to_string(ui->startFloor->value())));
}


void MainWindow::on_pushButton_1_clicked()
{
    removeBackgroundColors();
    elevatorControlSystem.moveToDestination(ui->startFloor->value(),ui->tableWidget,1,ui->label_3);
}



void MainWindow::on_pushButton_2_clicked()
{
    removeBackgroundColors();
    elevatorControlSystem.moveToDestination(ui->startFloor->value(),ui->tableWidget,2,ui->label_3);
}


void MainWindow::on_pushButton_3_clicked()
{
    removeBackgroundColors();
    elevatorControlSystem.moveToDestination(ui->startFloor->value(),ui->tableWidget,3,ui->label_3);
}


void MainWindow::on_pushButton_4_clicked()
{
    removeBackgroundColors();
    elevatorControlSystem.moveToDestination(ui->startFloor->value(),ui->tableWidget,4,ui->label_3);
}

void MainWindow::on_pushButton_5_clicked()
{
    removeBackgroundColors();
    elevatorControlSystem.moveToDestination(ui->startFloor->value(),ui->tableWidget,5,ui->label_3);
}











