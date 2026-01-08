#include <thread>
#include <iostream>

// TASK: Include the <atomic> header and change the counter to an atomic type.
long long counter = 0;

void increment() {
    for (int i = 0; i < 1000000; ++i) {
        // This increment is not atomic!
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
