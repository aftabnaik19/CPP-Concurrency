# Solution for Task 2

Here is the complete corrected code for `main.cpp`.

```cpp
#include <thread>
#include <iostream>
#include <vector>
#include <mutex>

long long counter = 0;
std::mutex m;

void increment() {
    for (int i = 0; i < 1000000; ++i) {
        std::lock_guard<std::mutex> guard(m);
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
```
