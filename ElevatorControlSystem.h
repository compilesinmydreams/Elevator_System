/*
 * @file ElevatorControlSystem.h
 * @brief This class manages elevators and floors in the building, providing functions to control elevator movement, handle emergency calls, and update sensor information.
 */

#ifndef ELEVATORCONTROLSYSTEM_H
#define ELEVATORCONTROLSYSTEM_H

#include "Elevator.h"
#include <QLabel>
#include <QTableWidget>  // Include QObject

enum class EmergencyType {
    FIRE,
    OVERLOAD,
    HELP,
    POWER_OUT,
    DOOR_OBSTACLE,
    EXTDOOR_OBSTACLE,
    NONE
};

class ElevatorControlSystem {

private:
    int numEl;
    int numFloors;
    Elevator Elevators[];  // Note: This array declaration needs a size.

public:
    /*Initializes the elevators in the system.
     * @param elevators An array of Elevator objects.
     * @param size The number of elevators in the array.
     */
    void initElevators(Elevator elevators[], int size);

    /* Moves the elevators to the closest floor.
     */
    void moveElevatorToClosestFloor();

    /*Sends emergency calls to the elevator system.
     * @param type The type of emergency.
     * @param label A QLabel used for display information.
     */
    void sendEmergencyCalls(EmergencyType type, QLabel* label);

    /* Moves the elevator to a specified destination floor.
     * @param atFloor The current floor of the elevator.
     * @param table A QTableWidget representing the building layout.
     * @param destFloor The destination floor requested by a user.
     * @param label A QLabel used for display information.
     */
    void moveToDestination(int atFloor, QTableWidget* table, int destFloor, QLabel* label);

    /* Sends the elevator up to a target floor.
     * @param TargetFloor The target floor to which the elevator should move.
     * @param table A QTableWidget representing the building layout.
     */
    void sendElevatorUp(int TargetFloor, QTableWidget* table);

    /* Sends the elevator down to a target floor.
     * @param TargetFloor The target floor to which the elevator should move.
     * @param table A QTableWidget representing the building layout.
     */
    void sendElevatorDown(int TargetFloor, QTableWidget* table);

    /* Updates the table highlighting to represent elevator positions.
     * @param table A QTableWidget representing the building layout.
     */
    void updateTableHighlights(QTableWidget* table);

    /* Calculates the absolute distance between the elevator and a target floor.
     * @param TargetFloor The target floor.
     * @return The absolute distance between the elevator and the target floor.
     */
    int AbsDistance(int TargetFloor);
};

#endif
