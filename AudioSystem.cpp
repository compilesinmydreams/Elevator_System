#include "AudioSystem.h"
#include <iostream>
#include <QLabel>
using namespace std;

void AudioSystem::emergencyAudioMsg(EmergencyType type) {
    // Play different audio messages based on the emergency type
    switch(type) {
        case EmergencyType::FIRE:
            cout << "PLAYED AS AUDIO: Emergency! Fire alarm! Evacuate elevator at the safe floor!\n"<<endl;
            break;
        case EmergencyType::OVERLOAD:
            cout << "PLAYED AS AUDIO: Emergency! Overload! Reduce load in the elevator.\n"<<endl;
            break;
        case EmergencyType::POWER_OUT:
            cout << "PLAYED AS AUDIO: Emergency! Power Out alarm! Evacuate elevator at the safe floor!\n"<<endl;
            break;
        case EmergencyType::EXTDOOR_OBSTACLE:
            cout << "PLAYED AS AUDIO: Emergency! CLEAR DOOR PATH!\n"<<endl;
        break;
        default:
        break;
    }
}

void AudioSystem::helpCall(QLabel* label) {
    // Display a help message on the provided label
    label->setText("Help");

    // Simulate connecting to building security
    cout << "Connecting to building security" << endl;

    // Display a simple hello message
    cout << "Hello?" << endl;

    // Simulate a countdown
    for (int i = 1; i <= 5; i++) {
        cout << i << endl;
    }

    // Connect to 911 due to no response
    cout << "Connecting to 911 because of no response" << endl;
}

void AudioSystem::bell() {
    // Play a bell sound (print "Ding!" for now)
    cout << "Ding!\n";

    // Logic to play an actual bell sound can be added here
    // (for example, using a sound library or hardware interface)
}
