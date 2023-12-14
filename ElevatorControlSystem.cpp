
#include "ElevatorControlSystem.h"
#include "AudioSystem.h"
#include "DisplaySystem.h"
#include "Doors.h"
#include "Elevator.h"
#include <iostream>
#include <cstdlib>
#include<QTableWidget>

using namespace std;

void ElevatorControlSystem::moveElevatorToClosestFloor() {
    // Logic to move the elevators to the closest floor
    cout<<"Moving to closest floor\n"<<endl;
}
void ElevatorControlSystem::initElevators(Elevator elevators[], int size){
     numEl=size;
    for(int i=0;i<size;i++)
    {
        Elevators[i]=elevators[i];

    }
//    for(int i=0;i<size;i++)
//    {
//        cout<<"floor:"<<Elevators[i].getCurrentFloor()<<" el:"<<Elevators[i].getElevatorNumber()<<endl;

//    }
}



void ElevatorControlSystem::sendEmergencyCalls(EmergencyType type,QLabel* label) {
    AudioSystem audioSystem;
    DisplaySystem displaySystem;
    Doors door;
    if (type==EmergencyType::DOOR_OBSTACLE){
        Doors door;
        door.doorOpen(true);
    }
    else if(type==EmergencyType::EXTDOOR_OBSTACLE){
        audioSystem.emergencyAudioMsg(type);
        door.doorOpen(true);
    }
    else if(type==EmergencyType::HELP){
        audioSystem.helpCall(label);
    }
   else if(type==EmergencyType::OVERLOAD){
        audioSystem.emergencyAudioMsg(type);
        door.doorOpen(false);
    }
    else{
        audioSystem.emergencyAudioMsg(type);
        displaySystem.emergencyTextMsg(type,label);
        moveElevatorToClosestFloor();
    }
}
int ElevatorControlSystem::AbsDistance(int TargetFloor){
    int distance[numEl];
    for(int i=0;i<numEl;i++){
        distance[i]=abs(Elevators[i].getCurrentFloor()-TargetFloor);
    }
    int min=10,ind=0;
    for(int i=0;i<numEl;i++){
        if(min>=distance[i]){
            min=distance[i];
            ind=i;
        }
    }
    return ind;
}
void ElevatorControlSystem::updateTableHighlights(QTableWidget* table) {
    // Update the table to highlight the elevators' positions
    for (int i = 0; i < numEl; i++) {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setBackground(QColor(255, 255, 0));
        table->setItem(Elevators[i].getCurrentFloor() - 1, Elevators[i].getElevatorNumber() - 1, item);
    }
}

void ElevatorControlSystem::sendElevatorUp(int TargetFloor, QTableWidget* table) {
     // Move the elevator up to the target floor and update the table
    int ClosestElevator=AbsDistance(TargetFloor);
    Elevators[ClosestElevator].setCurrentFloor(TargetFloor);
    updateTableHighlights(table);
    Doors door;
    door.doorOpen(false);
    door.doorClose(false);

}

void ElevatorControlSystem::sendElevatorDown(int TargetFloor,QTableWidget* table)
{
    // Move the elevator down to the target floor and update the table
    int ClosestElevator=AbsDistance(TargetFloor);
    Elevators[ClosestElevator].setCurrentFloor(TargetFloor);
    updateTableHighlights(table);
    Doors door;
    door.doorOpen(false);
    door.doorClose(false);

}
void ElevatorControlSystem::moveToDestination(int atFloor,QTableWidget* table, int destFloor,QLabel* label){
      // Move elevator to the destination floor and update the table
    for(int i=0;i<numEl;i++){
            if(Elevators[i].getCurrentFloor()==atFloor){
                Elevators[i].setCurrentFloor(destFloor);
                break;
            }
        }
        updateTableHighlights(table);
        // Display the destination floor number on the labe
        DisplaySystem display;
        display.displayFloorNumber(label, destFloor);

}
