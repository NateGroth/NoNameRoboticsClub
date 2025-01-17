
#ifndef GET_INPUT
#define GET_INPUT

class input {
    public:
        input(int* base, int* shoulder, int* elbow, int* wrist, int* claw);
        void readValues(int* base, int* shoulder, int* elbow, int* wrist, int* claw);
        int getAverage();
    private:
        int curr;
        int last;
        int avg;

        int* base;
        int* shoulder;
        int* elbow;
        int* wrist;
        int* claw;

        
};

#endif