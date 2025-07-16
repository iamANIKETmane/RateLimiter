#include <iostream>
#include <chrono>
#include <thread>

int main() {
    // Get current time
    auto start = std::chrono::steady_clock::now();
    
    // Do something that takes time
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    
    // Get time again
    auto end = std::chrono::steady_clock::now();
    
    // Calculate difference
    auto duration = end - start;
    
    // Convert to milliseconds for display
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
    
    std::cout << "Elapsed time: " << ms.count() << " ms" << std::endl;
    
    return 0;
}