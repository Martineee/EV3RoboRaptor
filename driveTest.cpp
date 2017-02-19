/*
 * Simple prototype to control the driving of the EV3 robot.
*/

#include "ev3dev.h"

#include <chrono>
#include <iostream>
#include <thread>

#ifndef NO_LINUX_HEADERS
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>
#define KEY_RELEASE 0
#define KEY_PRESS   1
#define KEY_REPEAT  2
#endif

using namespace std;
namespace ev3 = ev3dev;

enum motorState
{
    stateIdle,
    stateDriving,
    stateTurning
};


int main()
{
    cout << "RUNNING TEST WORKING!\n";
    ev3::large_motor rightMotor(ev3::OUTPUT_A);
    ev3::large_motor leftMotor(ev3::OUTPUT_B);
    motorState motorState(stateIdle);

    // Reset motors
    if(rightMotor.connected())
    {
        cout << "Right motor connected\n";
        rightMotor.reset();
    }
    if(leftMotor.connected())
    {
        cout << "Left motor connected\n";
        leftMotor.reset();
    }
    motorState = stateIdle;


    // Set speed
    rightMotor.set_speed_sp(400);
    leftMotor.set_speed_sp(400);

    // Run motor for 10 seconds
    rightMotor.set_time_sp(10000).run_timed();
    leftMotor.set_time_sp(10000).run_timed();

    // Wait while motor is running
    while(rightMotor.state().count("running") and leftMotor.state().count("running"))
    {
        cout << "Running?\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    motorState = stateIdle;

    // Reset motor again
    if(rightMotor.connected())
    {
        cout << "Reset\n";
        rightMotor.reset();
    }
    if(leftMotor.connected())
    {
        cout << "Reset\n";
        leftMotor.reset();
    }
    motorState = stateIdle;

    return 0;
}
