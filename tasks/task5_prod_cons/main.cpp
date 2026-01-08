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
        // TASK:
        // 1. Acquire a unique_lock on the mutex.
        // 2. Wait until the queue is not full (use cv_producer).
        //    The condition to check is `buffer.size() < MAX_QUEUE_SIZE`.
        // 3. Push the value onto the buffer.
        // 4. Notify the consumer that an item is available (use cv_consumer).
    }

    int pop() {
        // TASK:
        // 1. Acquire a unique_lock on the mutex.
        // 2. Wait until the queue is not empty (use cv_consumer).
        //    The condition to check is `!buffer.empty()`.
        // 3. Get the value from the front of the buffer.
        // 4. Pop the item from the buffer.
        // 5. Notify the producer that there is space available (use cv_producer).
        // 6. Return the value.
        return 0; // Placeholder
    }

private:
    std::queue<int> buffer;
    std::mutex mtx;
    std::condition_variable cv_producer;
    std::condition_variable cv_consumer;
};

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
