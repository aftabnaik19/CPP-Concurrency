# Solution for Task 4

Here is the complete corrected code for `main.cpp` using `std::scoped_lock`.

```cpp
#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>

std::mutex m1, m2;

void thread_a() {
    std::cout << "Thread A trying to lock m1 and m2..." << std::endl;
    std::scoped_lock lock(m1, m2);
    std::cout << "Thread A acquired both locks." << std::endl;
    
    // ... critical section for thread A ...
    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    std::cout << "Thread A finished." << std::endl;
}

void thread_b() {
    std::cout << "Thread B trying to lock m1 and m2..." << std::endl;
    std::scoped_lock lock(m1, m2);
    std::cout << "Thread B acquired both locks." << std::endl;

    // ... critical section for thread B ...
    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    std::cout << "Thread B finished." << std::endl;
}

int main() {
    std::cout << "Starting deadlock example..." << std::endl;
    std::thread t1(thread_a);
    std::thread t2(thread_b);

    t1.join();
    t2.join();

    std::cout << "Finished deadlock example." << std::endl;
    return 0;
}
```
