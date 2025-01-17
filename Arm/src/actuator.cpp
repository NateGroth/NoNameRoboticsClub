#include <Servo.h>
#include "send_cmd.h"
#include "mock.h"
#include "pinout.h"

Arm::Arm() {
    this->Base.attach(basePin)
    this->Shoulder.attach(shoulderPin)
    this->Elbow.attach(ElbowPin)
    this->Wrist.attach(WristPin)
    this->Claw.attach(ClawPin)
}

void send_CMD(int* base, int* shoulder, int* elbow, int* wrist, int* claw)