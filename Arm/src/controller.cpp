#include "get_input.h"
#include "pinout.h"
#include <queue>
//remove mock when pushing to prod
#include "mock.h"

Input::Input(int* base, int* shoulder, int* elbow, int* wrist, int* claw) {
    this->base = base;
    this->shoulder = shoulder;
    this->elbow = elbow;
    this->wrist = wrist;
    this->claw = claw;
}

void Input::readValues() {
    readPot(basePin, baseBuffer);
    readPot(shoulderPin, shoulderBuffer);
    readPot(ElbowPin, elbowBuffer);
    readPot(WristPin, wristBuffer);
    readPot(ClawPin, clawBuffer);
}

int Input::readPot(int pin, std::queue<int>& buffer) {
    if (buffer.size() >= BufferSize) {
        buffer.pop();
    }
    //analogRead is being mocked via mock.h, make sure to remove mock during produciton
    buffer.push(analogRead(pin));
}

int Input::getAverage() {

}




