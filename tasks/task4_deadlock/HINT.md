# Hint for Task 4

The deadlock happens because the two threads lock the mutexes in a different order.

The best fix is to lock both mutexes at the same time in a single operation. C++17 introduced `std::scoped_lock` for this exact purpose.

In both `thread_a` and `thread_b`, replace the two separate `std::lock_guard` lines with a single line:

`std::scoped_lock lock(m1, m2);`

This will acquire locks on both `m1` and `m2` using a deadlock-avoidance algorithm, and automatically release them when `lock` goes out of scope.
