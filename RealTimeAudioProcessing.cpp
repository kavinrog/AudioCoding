#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

// Simulate audio buffer processing
void processAudioBuffer(std::vector<float>& buffer) {
    for (auto& sample : buffer) {
        // Apply gain as a dummy DSP effect
        sample *= 0.5f;
    }
}

int main() {
    const int bufferSize = 512; // 512 samples per buffer
    const int sampleRate = 48000; // 48kHz audio
    const int bufferDurationMs = (bufferSize * 1000) / sampleRate;

    std::vector<float> buffer(bufferSize, 1.0f); // dummy input buffer

    while (true) {
        // Simulate pulling new audio data
        std::cout << "Processing buffer...\n";
        processAudioBuffer(buffer);

        // Sleep to simulate real-time processing interval
        std::this_thread::sleep_for(std::chrono::milliseconds(bufferDurationMs));
    }

    return 0;
}