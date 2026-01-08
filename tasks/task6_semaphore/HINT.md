# Hint for Task 6

This task introduces `std::counting_semaphore` from C++20.

1.  Make sure you have `#include <semaphore>`
2.  The semaphore `sem` is already created for you with 3 slots: `std::counting_semaphore<> sem(NUM_SLOTS);`

The two main functions of a semaphore are `acquire` and `release`.

*   To wait for a slot to become available and then take it, use `sem.acquire();`. This will block if the semaphore's internal counter is zero.
*   To give a slot back, use `sem.release();`. This increments the counter and will wake up a waiting thread if any exist.
