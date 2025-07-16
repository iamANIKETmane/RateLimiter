#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

class TimedCounter {
private:
    int count;
    std::chrono::steady_clock::time_point start_time;
    std::mutex counter_mutex;
    
public:
    TimedCounter() : count(0), start_time(std::chrono::steady_clock::now()) {}
    
    void increment() {
        std::lock_guard<std::mutex> lock(counter_mutex);
        count++;
    }
    
    void print_rate() {
        std::lock_guard<std::mutex> lock(counter_mutex);
        auto now = std::chrono::steady_clock::now();
        auto duration = now - start_time;
        auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration).count();
        
        if (seconds > 0) {
            std::cout << "Rate: " << count / seconds << " increments/second" << std::endl;
        }
    }
};

// TODO: Create a function that increments the counter many times
// TODO: Create multiple threads that call this function
// TODO: Periodically print the rate

int main() {
    TimedCounter counter;
    
    // Your implementation here
    
    return 0;
}