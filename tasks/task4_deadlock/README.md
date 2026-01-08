# Task 4: The Deadlock

**Goal:** Find and fix a deadlock.

A deadlock occurs when two or more threads are blocked forever, each waiting for the other to release a lock.

The `main.cpp` file contains a classic deadlock scenario. Two threads, `thread_a` and `thread_b`, need to lock two mutexes, `m1` and `m2`.
*   `thread_a` locks `m1` then `m2`.
*   `thread_b` locks `m2` then `m1`.

This creates a "deadly embrace." If `thread_a` locks `m1` and `thread_b` locks `m2` at the same time, neither can proceed.

**Your Mission:**

1.  **Run the test script (`./test.sh`)**. It will likely hang and time out. This is the deadlock in action.
2.  **Fix the deadlock.** The best way to fix this in C++17 is to use `std::scoped_lock`. It's a special lock guard that can lock multiple mutexes at once using a deadlock-avoidance algorithm.
    *   Replace the two `std::lock_guard`s in each function with a single `std::scoped_lock(m1, m2);`.

**Alternative Fix (if not using C++17):**
Establish a global lock order. For example, decide that `m1` must *always* be locked before `m2`. Change `thread_b` to lock `m1` first, then `m2`.

**Run the test script again. If the fix is correct, the program will finish quickly and the test will pass.**
