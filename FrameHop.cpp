#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<float>> frame_audio(
    const vector<float>& audio,
    size_t frame_size = 1024,
    size_t hop_size = 512
){
    vector<vector<float>> frames;
    size_t num_sample = audio.size();
    size_t num_frames =(num_sample - frame_size)/hop_size +1;
    for(size_t i =0; i<num_frames; ++i){
        size_t start = i* hop_size;
        vector<float> frame(audio.begin()+start, audio.begin()+start+num_frames);
        frames.push_back(move(frame));
    }
    return frames;
}

int main() {
    vector<float> audio(5000, 0.5f); // input audio samples initialized with a constant value
    auto frames = frame_audio(audio, 1024, 512);

    cout << "Created " << frames.size() << " frames of size 1024\n";
    return 0;
}