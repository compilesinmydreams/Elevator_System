// elevator.cpp
#include "Elevator.h"

Elevator::Elevator() : elevatorNumber(0), currentFloor(1) {
    // Default constructor initializes elevator with number 0 and default current floor (e.g., 1)
}

Elevator::Elevator(int number) : elevatorNumber(number), currentFloor(1) {
    // Constructor with elevator number initializes elevator with the given number and default current floor (e.g., 1)
}

int Elevator::getElevatorNumber() const {
    return elevatorNumber;
}

int Elevator::getCurrentFloor() const {
    return currentFloor;
}

void Elevator::setCurrentFloor(int floor) {
    currentFloor = floor;
}
void  Elevator::setElevatorNumber(int num){
    elevatorNumber=num;
}
