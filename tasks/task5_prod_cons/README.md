# Task 5: The Producer-Consumer Problem

**Goal:** Implement a thread-safe queue using `std::mutex` and `std::condition_variable`.

This is a classic concurrency problem. One thread (the "producer") generates data, and another thread (the "consumer") processes it. They communicate through a shared queue.

**The Problem:**
*   If the queue is empty, the consumer must wait.
*   If the queue is full (we'll give it a max size), the producer must wait.
*   Access to the queue must be thread-safe.

**Your Mission:**
Implement the `push` and `pop` methods of the `SafeQueue` class in `main.cpp`.

1.  **`push(int value)`:**
    *   Lock the mutex. You **must** use `std::unique_lock` because you'll need to unlock it temporarily.
    *   Wait until the queue is not full. Use `cv_producer.wait()`. The wait should be in a loop to handle "spurious wakeups".
    *   Push the value onto the queue.
    *   Notify the consumer thread that there's new data. Use `cv_consumer.notify_one()`.

2.  **`pop()`:**
    *   Lock the mutex using `std::unique_lock`.
    *   Wait until the queue is not empty. Use `cv_consumer.wait()`.
    *   Pop the value from the queue.
    *   Notify the producer thread that there's new space. Use `cv_producer.notify_one()`.
    *   Return the value.

**Why `std::unique_lock`?**
`std::condition_variable::wait` requires a `std::unique_lock`. When you call `wait`, it atomically unlocks the mutex and puts the thread to sleep. When the thread is woken up, it re-locks the mutex before returning. `std::lock_guard` doesn't have the flexibility to be unlocked and re-locked like this.

**Run the test script. It will check if all produced items were consumed correctly.**
