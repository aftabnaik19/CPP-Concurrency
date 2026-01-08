# Task 3: The Atomic Alternative

**Goal:** Use `std::atomic` for lock-free synchronization.

Mutexes are powerful, but for simple operations like incrementing a counter, they can be overkill. C++ provides a lighter-weight alternative: `std::atomic`.

Your mission is to fix the race condition using `std::atomic`.

1.  **Include the `<atomic>` header.**
2.  **Change the type of the `counter`** from `long long` to `std::atomic<long long>`.
3.  The rest of the code should work without a mutex or lock guard! The `++` operator is overloaded for `std::atomic` types to perform the increment atomically.

Atomic operations are often faster than mutexes because they are implemented using special CPU instructions that don't require a full kernel-level lock.

**Compile and run the test script (`./test.sh`). If your fix is correct, the test will pass.**
