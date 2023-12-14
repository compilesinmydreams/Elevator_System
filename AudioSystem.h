/*The AudioSystem class handles audio messages and bell sounds.
This class is responsible for generating emergency audio messages
corresponding to different emergency situations.
It also handles the bell sound that indicates the arrival of an
elevator at a floor.*/

#ifndef AUDIOSYSTEM_H
#define AUDIOSYSTEM_H
#include "ElevatorControlSystem.h"



class AudioSystem {
public:
    /*Generates an emergency audio message based on the given emergency type.
         * @param type The type of emergency for which the audio message is generated.
         */
    void emergencyAudioMsg(EmergencyType type);
    /*Initiates a help call and updates the provided label with relevant information.
         * @param label The QLabel to display information about the help call.
         */
    void helpCall(QLabel* label);
    /*Plays the bell sound to indicate the arrival of an elevator at a floor.
         */
    void bell();
};

#endif
