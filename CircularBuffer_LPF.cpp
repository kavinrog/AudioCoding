#include <iostream>
#include <vector>
#include <cmath>

class CircularBuffer{
    std::vector<float> buffer;
    int size, writeIndex = 0;
public: 
    CircularBuffer(int s) : size(s), buffer(s, 0.0f){}
    void write(float sample){
        buffer[writeIndex] = sample;
        writeIndex = (writeIndex+1)%size;
    }
    float read(int delay) const{
        int index = (writeIndex-delay +size)%size;
        return buffer[index];

    }
};