#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex counter_mutex;

void increment_counter() {
    for (int i = 0; i < 100000; ++i) {
        std::lock_guard<std::mutex> lock(counter_mutex);
        counter++;  // Now this is thread-safe!
    }  // lock automatically released when lock_guard goes out of scope
}

int main() {
    std::thread t1(increment_counter);
    std::thread t2(increment_counter);
    
    t1.join();
    t2.join();
    
    std::cout << "Final counter: " << counter << std::endl;
    std::cout << "Expected: " << 200000 << std::endl;
    
    return 0;
}