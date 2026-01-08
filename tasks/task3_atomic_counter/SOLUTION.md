# Solution for Task 3

Here is the complete corrected code for `main.cpp`.

```cpp
#include <thread>
#include <iostream>
#include <atomic>

std::atomic<long long> counter = 0;

void increment() {
    for (int i = 0; i < 1000000; ++i) {
        counter++; // This is now an atomic operation
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final counter value: " << counter.load() << std::endl;

    return 0;
}
```
