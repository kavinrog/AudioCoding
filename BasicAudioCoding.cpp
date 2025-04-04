#include <iostream>
#include <vector>
#include <cmath>

class AudioSignal {
public:
    AudioSignal(int size) {
        buffer.resize(size);
        // Fill with a fake sine wave signal
        for (int i = 0; i < size; ++i) {
            buffer[i] = std::sin(2 * M_PI * i / 50); // simple sine wave
        }
    }

    void applyGain(float gain) {
        for (float& sample : buffer) {
            sample *= gain;
        }
    }

    void print() {
        for (int i = 0; i < 10; ++i) { // Just show the first 10 samples
            std::cout << buffer[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<float> buffer;
};

int main() {
    AudioSignal signal(100);
    std::cout << "Original:\n";
    signal.print();

    signal.applyGain(0.5);
    std::cout << "After Gain (0.5):\n";
    signal.print();

    return 0;
}