#include <iostream>
#include <deque>
#include <chrono>
#include <thread>

int main() {
    std::deque<std::chrono::steady_clock::time_point> timestamps;
    
    // Add some timestamps with delays
    for (int i = 0; i < 5; ++i) {
        timestamps.push_back(std::chrono::steady_clock::now());
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "Added timestamp " << (i + 1) << std::endl;
    }
    
    std::cout << "Total timestamps: " << timestamps.size() << std::endl;
    
    // Now remove timestamps older than 2 seconds
    auto now = std::chrono::steady_clock::now();
    auto two_seconds_ago = now - std::chrono::seconds(2);
    while (!timestamps.empty() && timestamps.front() < two_seconds_ago) {
    timestamps.pop_front();
    std::cout << "Removed an old timestamp" << std::endl;
    }
    
    std::cout << "Timestamps after cleanup: " << timestamps.size() << std::endl;
    
    return 0;
}