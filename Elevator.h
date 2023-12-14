// elevator.h The Elevator class represents an elevator in a building.
#ifndef ELEVATOR_H
#define ELEVATOR_H

class Elevator {
private:
    int elevatorNumber;// Unique identifier for the elevator
    int currentFloor;    // The current floor where the elevator is located

public:
    /*Default constructor for the Elevator class.
     */
    Elevator();

    /*Constructor with an elevator number.
     * @param number The elevator number.
     */
    Elevator(int number);

    /*Getter method for the elevator number.
     * @return The elevator number.
     */
    int getElevatorNumber() const;

    /*Getter method for the current floor.
     * @return The current floor where the elevator is located.
     */
    int getCurrentFloor() const;
    /*Setter method for the current floor.
     * @param floor The new current floor value.
     */
    void setCurrentFloor(int floor);
    /*Setter method for the elevator number.
         * @param num The new elevator number.
         */
    void setElevatorNumber(int num);
};

#endif
