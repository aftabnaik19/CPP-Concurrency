#include <thread>
#include <iostream>
#include <vector>

// TASK: Include the <mutex> header and create a std::mutex object.

long long counter = 0;

void increment() {
    for (int i = 0; i < 1000000; ++i) {
        // TASK: Create a std::lock_guard to protect the counter.
        counter++;
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final counter value: " << counter << std::endl;

    return 0;
}
