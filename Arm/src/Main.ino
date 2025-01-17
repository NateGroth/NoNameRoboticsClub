#include "get_input.h"
#include "send_cmd.h"   
#include "pinout.h"
//remove for prod
#include "mock.h"


using namespace std;

// These values are modifed by the Input class, range from 1 -> 1023
int BaseTarget;
int ShoulderTarget;
int ElbowTarget;
int WristTarget;
int ClawTarget;

Input input(&BaseTarget, &ShoulderTarget, &ElbowTarget, &WristTarget, &ClawTarget);
Arm arm;

void setup() {
    //uncomment for prod
    // Serial.begin(9600);

    //Set Potentiometer analog pins to INPUT
    pinMode(BasePotPin, INPUT);
    pinMode(ShoulderPotPin, INPUT);
    pinMode(ElbowPotPin, INPUT);
    pinMode(WristPotPin, INPUT);
    pinMode(ClawPotPin, INPUT);
}

void loop() {
    input.readValues();
    arm.send_CMD(&BaseTarget, &ShoulderTarget, &ElbowTarget, &WristTarget, &ClawTarget);
}