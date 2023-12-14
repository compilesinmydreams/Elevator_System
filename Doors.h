/*The Doors class represents the doors of the elevator.
This class handles the opening and closing of elevator doors.
It also manages the functionality to override door timings.*/

#ifndef DOORS_H
#define DOORS_H
#include "ElevatorControlSystem.h"
#include "AudioSystem.h"
class Doors {

public:
    /*Opens the elevator doors.
     * @param override Flag to override normal door timings.
     */
    void doorOpen(bool override);
    /*Closes the elevator doors.
     * @param override Flag to override normal door timings.
     */
    void doorClose(bool override);
};

#endif
