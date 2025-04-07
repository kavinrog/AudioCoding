#include <vector>
#include <deque>
class FIRFilter{
    std::vector<float> coeffs;
    std::deque<float> buffer;
public:
    FIRFilter(const std::vector<float>& coefficients) :coeffs(coefficients)
, buffer(coefficients.size(), 0.0f){}
    float processSample(float inputSample){
        buffer.pop_back();
        buffer.push_front(inputSample);
        float result = 0.0f;
        for (size_t i = 0; i<coeffs.size(); ++i){
            result+=coeffs[i]* buffer[i];
        }
        return result ;
    }
};

