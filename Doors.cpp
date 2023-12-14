#include "Doors.h"
#include <iostream>

using namespace std;

void Doors::doorOpen(bool override) {
    // Display a message indicating that the doors are opening
    cout << "Doors open. Please enter!\n";

    // Create an instance of the AudioSystem to ring the bell
    AudioSystem bell;
    bell.bell();

    // If override is true, reset the door timer
    if (override) {
        cout << "Door timer resets, and the door stays open for another few seconds\n" << endl;
    }
}

void Doors::doorClose(bool override) {
    // If override is true, fast forward the door timer
    if (override) {
        cout << "Door timer fast-forwards, and the door closes sooner\n" << endl;
    }

    // Display a message indicating that the doors are closing
    cout << "Doors close" << endl;

    // Create an instance of the AudioSystem to ring the bell
    AudioSystem bell;
    bell.bell();
}
