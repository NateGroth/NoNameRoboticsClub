#include <queue>

#ifndef GET_INPUT
#define GET_INPUT

class Input {
    public:
    // Constructor which takes in pointers to varaibles in main func (MODIFIES THESE VALUES)
        Input(int* base, int* shoulder, int* elbow, int* wrist, int* claw);
        void readValues();
    private:

    //Stores pointer to variables in main func
        int* base;
        int* shoulder;
        int* elbow;
        int* wrist;
        int* claw;

    //Initialize buffer, used for smoothing out inputs (change length in pinout.h >> BufferSize)
        std::queue<int> baseBuffer;
        std::queue<int> shoulderBuffer;
        std::queue<int> elbowBuffer;
        std::queue<int> wristBuffer;
        std::queue<int> clawBuffer;

        int getAverage(std::queue<int>& buffer);
        int readPot(int pin, std::queue<int>& buffer);
};

#endif