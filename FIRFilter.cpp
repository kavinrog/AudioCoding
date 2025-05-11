#include <vector>

class FIRFilter {
public:
    FIRFilter(const std::vector<float>& taps)
        : coefficients(taps), buffer(taps.size(), 0.0f), index(0){}

        float process(float input){
            buffer[index] = input;

            float output =0.0f;
            size_t tapIndex = 0;
            size_t bufIndex = index;
            for(; tapIndex<coefficients.size(); ++tapIndex){
                output += coefficients[tapIndex] * buffer[bufIndex];
                if(bufIndex == 0)
                    bufIndex = buffer.size()-1;
                else
                    --bufIndex;
            }
            index = (index +1) % buffer.size();
            return output;

        }
private:
    std::vector<float> coefficients;
    std::vector<float> buffer;
    size_t index;
};