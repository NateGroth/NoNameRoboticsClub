#include <Servo.h>
#include "get_input.h"
#include "send_cmd.h"   
#include "pinout.h"

using namespace std;

Servo Base;
Servo Shoulder;
Servo Elbow;
Servo Wrist;
Servo Claw;

// These values are modifed by the Input class, range from 1 -> 1023
int BaseTarget;
int ShoulderTarget;
int ElbowTarget;
int WristTarget;
int ClawTarget;

void Setup() {
    Serial.begin(9600)

    //Startup arm servos
    Base.attach(basePin)
    Shoulder.attach(shoulderPin)
    Elbow.attach(ElbowPin)
    Wrist.attach(WristPin)
    Claw.attach(ClawPin)

    //Move to 100 on start
    Base.write(100)
    Shoulder.write(100)
    Elbow.write(100)
    Wrist.write(100)
    Claw.write(100)

    //Set Potentiometer analog pins to INPUT
    pinMode(BasePotPin, INPUT);
    pinMode(ShoulderPotPin, INPUT);
    pinMode(ElbowPotPin, INPUT);
    pinMode(WristPotPin, INPUT);
    pinMode(ClawPotPin, INPUT);

    //Initialize input class
    Input Input(&BaseTarget, &ShoulderTarget, &Elbowtarget, &WristTarget, &ClawTarget)

    
}

void Loop() {
    Input::readValues();
}