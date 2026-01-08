# Solution for Task 5

Here is the complete implementation of the `SafeQueue` class.

```cpp
#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <chrono>

const int MAX_QUEUE_SIZE = 5;
const int NUM_ITEMS_TO_PRODUCE = 100;

class SafeQueue {
public:
    void push(int value) {
        std::unique_lock<std::mutex> lock(mtx);
        cv_producer.wait(lock, [this]{ return buffer.size() < MAX_QUEUE_SIZE; });
        
        buffer.push(value);
        
        lock.unlock(); // Not strictly necessary, but good practice to unlock before notifying
        cv_consumer.notify_one();
    }

    int pop() {
        std::unique_lock<std::mutex> lock(mtx);
        cv_consumer.wait(lock, [this]{ return !buffer.empty(); });
        
        int value = buffer.front();
        buffer.pop();
        
        lock.unlock(); // Not strictly necessary, but good practice to unlock before notifying
        cv_producer.notify_one();
        
        return value;
    }

private:
    std::queue<int> buffer;
    std::mutex mtx;
    std::condition_variable cv_producer;
    std::condition_variable cv_consumer;
};

// The rest of the main.cpp file remains the same.
// ...
// ... (producer, consumer, and main functions)
// ...
void producer(SafeQueue& q) {
    for (int i = 0; i < NUM_ITEMS_TO_PRODUCE; ++i) {
        std::cout << "Producing " << i << std::endl;
        q.push(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Simulate work
    }
}

void consumer(SafeQueue& q, std::vector<int>& consumed_items) {
    for (int i = 0; i < NUM_ITEMS_TO_PRODUCE; ++i) {
        int value = q.pop();
        std::cout << "Consuming " << value << std::endl;
        consumed_items.push_back(value);
    }
}

int main() {
    SafeQueue q;
    std::vector<int> consumed_items;

    std::thread prod_thread(producer, std::ref(q));
    std::thread cons_thread(consumer, std::ref(q), std::ref(consumed_items));

    prod_thread.join();
    cons_thread.join();

    std::cout << "Producer and Consumer finished." << std::endl;
    std::cout << "Total items consumed: " << consumed_items.size() << std::endl;

    if (consumed_items.size() != NUM_ITEMS_TO_PRODUCE) {
        return 1; // Error
    }

    return 0;
}
```
