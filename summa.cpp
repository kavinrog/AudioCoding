#include <iostream>
#include <vector>
#include <cmath>

// Your function to split audio into overlapping frames
std::vector<std::vector<float>> frame_audio(
    const std::vector<float>& audio,
    size_t frame_size = 1024,
    size_t hop_size = 512
) {
    std::vector<std::vector<float>> frames;

    size_t num_samples = audio.size();
    size_t num_frames = (num_samples - frame_size) / hop_size + 1;

    for (size_t i = 0; i < num_frames; ++i) {
        size_t start = i * hop_size;
        std::vector<float> frame(audio.begin() + start, audio.begin() + start + frame_size);
        frames.push_back(std::move(frame));
    }

    return frames;
}

int main() {
    // 🔉 Step 1: Create a dummy audio signal (sine wave)
    const size_t sample_rate = 16000; // 16 kHz
    const float freq = 440.0f;        // A4 tone
    const float duration = 1.0f;      // 1 second
    const size_t num_samples = static_cast<size_t>(sample_rate * duration);

    std::vector<float> audio(num_samples);
    for (size_t i = 0; i < num_samples; ++i) {
        audio[i] = std::sin(2 * M_PI * freq * i / sample_rate);
    }

    // 🎯 Step 2: Frame the audio
    size_t frame_size = 1024;
    size_t hop_size = 512;
    auto frames = frame_audio(audio, frame_size, hop_size);

    // 📦 Step 3: Print some frame info
    std::cout << "Total frames: " << frames.size() << "\n";
    std::cout << "Each frame has " << frame_size << " samples\n";

    // 🧪 (Optional) print first few samples of the first frame
    for (size_t i = 0; i < 10; ++i) {
        std::cout << frames[0][i] << " ";
    }
    std::cout << "\n";

    return 0;
}