#include "DisplaySystem.h"
#include <iostream>
#include<QString>
using namespace std;

void DisplaySystem::emergencyTextMsg(EmergencyType type, QLabel* label) {
    // Update the label text based on the emergency type
    switch(type) {
        case EmergencyType::FIRE:
           label->setText("Fire!");
            break;
        case EmergencyType::OVERLOAD:
            label->setText("OVERLOAD");
            break;
        case EmergencyType::HELP:
            label->setText("HELP");
            break;
        case EmergencyType::POWER_OUT:
             label->setText("POWER_OUT");
            break;
        case EmergencyType::DOOR_OBSTACLE:
             label->setText("DOOR_OBSTACLE");
            break;
        case EmergencyType::NONE:

            break;
    }
}

void DisplaySystem::displayFloorNumber(QLabel* label,int floor) {
    // Update the label text with the floor number as a string
    label->setText(QString::fromStdString(std::to_string(floor)));

}
