// #include <Servo.h>
// #include <Arduino.h>
#include "send_cmd.h"
#include "pinout.h"
// #include "WMath.cpp"

Arm::Arm() {
    this->Base.attach(basePin);
    this->Shoulder.attach(ShoulderPin);
    this->Elbow.attach(ElbowPin);
    this->Wrist.attach(WristPin);
    this->Claw.attach(ClawPin);

    //move to 100 on startup
    Base.write(90);
    Shoulder.write(90);
    Elbow.write(90);
    Wrist.write(90);
    Claw.write(90);
}

void Arm::send_CMD(int* base, int* shoulder, int* elbow, int* wrist, int* claw) {
    Base.write(analogPWM(base));
    Shoulder.write(analogPWM(shoulder));
    Elbow.write(analogPWM(elbow));
    Wrist.write(analogPWM(wrist));
    Claw.write(analogPWM(claw));
}

int Arm::analogPWM(int* analogValue) {
    return map(*analogValue, 1, 1023, 1, 179);
}