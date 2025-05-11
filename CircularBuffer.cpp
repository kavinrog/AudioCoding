#include <vector>
#include <stdexcept>

template<typename T>
class CircularBuffer{
public:
    CircularBuffer(size_t size)
        : buffer(size), head(0), tail(0), full(false){}

        void push(const T& item){
            buffer[head] = item;
            head = (head+1) % buffer.size();
            if(full){
                tail = (tail+1) % buffer.size();
            }
            full =(head == tail);
        } 

        T pop(){
            if(isEmpty()){
                throw std::runtime_error("Buffer is empty");
            }
            T item = buffer[tail];
            tail = (tail+1) % buffer.size();
            full = false;
            return item;
        }

        T peek() const{
            if(isEmpty()){
                throw std:: runtime_error("Buffer is empty");
            }
            return buffer[tail];
        }

        bool isEmpty() const{
            return(!full && head == tail);
        }

        bool isFull() const{
            return full;
        }
        
        size_t size() const{
            if(full){
                return buffer.size();
            }
            if(head>= tail){
                return head-tail;
            }
            return buffer.size() - tail + head;
        }

        size_t capacity() const{
            return buffer.size();
        }
private:
        std::vector<T> buffer;
        size_t head;
        size_t tail;
        bool full;
};

#include <iostream>

int main() {
    CircularBuffer<float> audioBuffer(5);  // buffer holds 5 float audio samples

    audioBuffer.push(0.1f);
    audioBuffer.push(0.2f);
    audioBuffer.push(0.3f);

    std::cout << "Peek: " << audioBuffer.peek() << std::endl; // 0.1

    std::cout << "Pop: " << audioBuffer.pop() << std::endl;   // 0.1
    std::cout << "Pop: " << audioBuffer.pop() << std::endl;   // 0.2

    audioBuffer.push(0.4f);
    audioBuffer.push(0.5f);
    audioBuffer.push(0.6f);
    audioBuffer.push(0.7f); // This will overwrite oldest if full

    while (!audioBuffer.isEmpty()) {
        std::cout << "Audio Sample: " << audioBuffer.pop() << std::endl;
    }

    return 0;
}