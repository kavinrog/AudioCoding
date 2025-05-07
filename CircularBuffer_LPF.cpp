#include <iostream>
#include <vector>
#include <cmath>

class CircularBuffer{
    std::vector<float> buffer;
    int size, writeIndex = 0;
public: 
    CircularBuffer(int s): size(s), buffer(s, 0.0f){}
    void write(float sample){
        buffer[writeIndex] = sample;
        writeIndex = (writeIndex+1)%size;
    }
    float read(int delay) const{
        int index = (writeIndex - delay +size)%size;
        return buffer[index];
    }
};

template<typename T>
class LowPassFilter{
    T alpha;
    T prevOutput;
public: 
    LowPassFilter(T alphaVal) : alpha(alphaVal){}
    T process(T input){
        T output = alpha * input + (1-alpha) * prevOutput;
        prevOutput = output
        return output
    }
};

class SimpleReverb{
    CircularBuffer delayline;
    int delaySample;
    float feedback;
public:
    SimpleReverb(int delaysize, float fb) : delayline(delaysize), delaySample(delaysize), feedback(fb){}
    float process(float input){
        float delayed = delayline.read(delaySample);
        float output = input + delayed * 0.5f;
        delayline.write(input + delayed * feedback);
        return output;
    }

};

template<typename T>
void generateSineWave(std::vector<T>& signal, int samples, float freq, float sampleRate) {
    for (int i = 0; i < samples; ++i) {
        signal[i] = std::sin(2 * M_1_PI * freq * i / sampleRate);
    }
}

int main() {
    const int numSamples = 48000;
    const float sampleRate = 48000.0f;
    std::vector<float> input(numSamples);
    generateSineWave(input, numSamples, 440.0f, sampleRate);

    LowPassFilter<float> lpf(0.1f);
    SimpleReverb reverb(1000, 0.4f);

    for (int i = 0; i < numSamples; ++i) {
        float filtered = lpf.process(input[i]);
        float withReverb = reverb.process(filtered);
        std::cout << withReverb << "\n"; // Output for testing
    }

    return 0;
}