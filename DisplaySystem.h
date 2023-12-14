/*The DisplaySystem class manages display information inside the elevators.
The class displays emergency text messages and current floor numbers inside the elevator.*/
#ifndef DISPLAYSYSTEM_H
#define DISPLAYSYSTEM_H
#include <QLabel>
#include "ElevatorControlSystem.h"


class DisplaySystem {

public:
    /*Displays an emergency text message on the provided QLabel.
         * @param type The type of emergency for which the text message is displayed.
         * @param label The QLabel to display the emergency text message.
         */
    void emergencyTextMsg(EmergencyType type, QLabel* label);
    /*Displays the current floor number on the provided QLabel.
     * @param label The QLabel to display the current floor number.
     * @param floor The current floor number to be displayed.
     */
    void displayFloorNumber(QLabel* label,int floor);
};

#endif
