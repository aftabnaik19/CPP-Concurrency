# Solution for Task 6

Here is the complete corrected code for `main.cpp`.

```cpp
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <semaphore> // C++20

const int NUM_WORKERS = 5;
const int NUM_SLOTS = 3;

// A semaphore to control access to a limited number of "slots"
std::counting_semaphore<> sem(NUM_SLOTS);

void worker(int id) {
    std::cout << "Worker " << id << " is waiting..." << std::endl;

    // Acquire a semaphore slot.
    sem.acquire();

    std::cout << "Worker " << id << " has acquired a slot." << std::endl;
    
    // Simulate doing work
    std::this_thread::sleep_for(std::chrono::seconds(1));
    
    std::cout << "Worker " << id << " is releasing the slot." << std::endl;
    
    // Release the semaphore slot.
    sem.release();
}

int main() {
    std::vector<std::thread> workers;
    for (int i = 0; i < NUM_WORKERS; ++i) {
        workers.emplace_back(worker, i + 1);
    }

    for (auto& t : workers) {
        t.join();
    }

    std::cout << "All workers have finished." << std::endl;
    return 0;
}
```
