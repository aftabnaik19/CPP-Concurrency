# Task 2: Fix with Mutex

**Goal:** Fix the race condition using `std::mutex`.

This directory contains the same buggy code from Task 1. Your mission is to fix it.

1.  **Include the `<mutex>` header.**
2.  **Create a `std::mutex` object.** Like the `counter`, it should be accessible to both threads.
3.  **Create a `std::lock_guard`** inside the `increment` function to lock the mutex. The lock should surround the line where `counter` is modified.

The `std::lock_guard` is an RAII-style wrapper that locks the mutex in its constructor and unlocks it in its destructor, ensuring the mutex is always released, even if an exception occurs.

**Compile and run the test script (`./test.sh`). If your fix is correct, the test will pass.**
