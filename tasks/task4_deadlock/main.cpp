#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>

std::mutex m1, m2;

void thread_a() {
    std::cout << "Thread A trying to lock m1..." << std::endl;
    std::lock_guard<std::mutex> g1(m1);
    std::cout << "Thread A locked m1." << std::endl;
    
    // Introduce a delay to increase the chance of deadlock
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    
    std::cout << "Thread A trying to lock m2..." << std::endl;
    std::lock_guard<std::mutex> g2(m2);
    std::cout << "Thread A locked m2." << std::endl;
    // ... critical section for thread A ...
    std::cout << "Thread A finished." << std::endl;
}

void thread_b() {
    std::cout << "Thread B trying to lock m2..." << std::endl;
    std::lock_guard<std::mutex> g2(m2);
    std::cout << "Thread B locked m2." << std::endl;

    // Introduce a delay to increase the chance of deadlock
    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    std::cout << "Thread B trying to lock m1..." << std::endl;
    std::lock_guard<std::mutex> g1(m1);
    std::cout << "Thread B locked m1." << std::endl;
    // ... critical section for thread B ...
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
