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

    *base = getAverage(baseBuffer);
    *shoulder = getAverage(shoulderBuffer);
    *elbow = getAverage(elbowBuffer);
    *wrist = getAverage(wristBuffer);
    *claw = getAverage(clawBuffer);

}

//Helper function to read and write to specific pin and their associated buffer
int Input::readPot(int pin, std::queue<int>& buffer) {
    if (buffer.size() >= BufferSize) {
        buffer.pop();
    }
    //analogRead is being mocked via mock.h, make sure to remove mock during produciton
    buffer.push(analogRead(pin));
}

int Input::getAverage(std::queue<int>& buffer) {
    //Currently using stdlib queue implementation that requires coppying queue and repeatedly dequeuing. Maybe we can create our own implementation witha built in avg func?
    std::queue<int> copy = buffer;
    int sum = 0;

    while(!copy.empty()) {
        sum += copy.front();
        copy.pop();
    }
    return sum / BufferSize;
}




