// uncomment when posting to Arduino
// #include <Servo.h>
#include "get_input.h"
#include "send_cmd.h"   
#include "pinout.h"
#include <queue>

using namespace std;

Servo Base;
Servo Shoulder;
Servo Elbow;
Servo Wrist;
Servo Claw;

int BasePot;
int ShoulderPot;
int ElbowPot;
int WristPot;
int ClawPot;

void Setup() {
    Serial.begin(9600)

    Base.attach(basePin)
    Shoulder.attach(shoulderPin)
    Elbow.attach(ElbowPin)
    Wrist.attach(WristPin)
    Claw.attach(ClawPin)

    Base.write(100)
    Shoulder.write(100)
    Elbow.write(100)
    Wrist.write(100)
    Claw.write(100)

    queue<int> baseBuffer;
    queue<int> shoulderBuffer;
    queue<int> elbowBuffer;
    queue<int> wristBuffer;
    queue<int> clawBuffer;
}

void Loop() {

}