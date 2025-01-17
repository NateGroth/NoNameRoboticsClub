#include "mock.h"
#include <random>

using namespace std;

//returns a random integer within the range of the Arduino's analogRead func
int analogRead(int pin) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1023); //poteniometer ranges from 1 to 1023
    return dis(gen);
}