#include <Servo.h>   
#include <Arduino.h>
#include "pinout.h"


#ifndef SEND_CMD
#define SEND_CMD

class Arm {
    public:
        Arm();
        void send_CMD(int* base, int* shoulder, int* elbow, int* wrist, int* claw);
    private:
        int analogPWM(int* analogValue);
        Servo Base;
        Servo Shoulder;
        Servo Elbow;
        Servo Wrist;
        Servo Claw;

};

#endif