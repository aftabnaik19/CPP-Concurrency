# Task 6: The Bounded Resource (Semaphore)

**Goal:** Use a C++20 `std::counting_semaphore` to control access to a limited number of resources.

A semaphore is a simple synchronization primitive that acts as a counter for controlling access to a resource.

Imagine a scenario where you have a pool of a few database connections, and many threads that need to use them. A semaphore is a perfect tool to manage this.

**Your Mission:**
Complete the `worker` function. The program simulates 5 workers trying to acquire one of 3 available "slots" or resources.

1.  **Include the `<semaphore>` header.** This is a C++20 feature.
2.  In the `worker` function:
    *   Call `sem.acquire()`. This will block until a slot is available, then decrement the semaphore's counter.
    *   Once acquired, the thread "does its work" (simulated by a sleep).
    *   Call `sem.release()`. This increments the semaphore's counter, making a slot available for another waiting thread.

**Run the test script. The output should show that no more than 3 workers are ever running concurrently.**
