# C++ Concurrency 

**Duration:** 30–60 minutes

**Goal:** A compact, hands-on assignment set (clone + run + fix) that teaches why we need mutexes/atomics/semaphores, how they work, alternatives, common pitfalls, and industry use-cases. Progress is visible after each task via simple test outputs.

---

## Learning Objectives

By the end of this workshop, you will be able to:

*   Explain why concurrency causes race conditions.
*   Use `std::mutex`, `std::lock_guard`, and `std::scoped_lock` to prevent race conditions.
*   Use `std::atomic` for simple, lock-free operations.
*   Recognize and fix a deadlock.
*   Understand the producer-consumer problem and solve it with `std::condition_variable`.
*   Use a `std::counting_semaphore` (C++20) to control access to a resource.

---

## Setup & How to Run

1.  **Clone the repository.**
2.  **Navigate to a task directory:** `cd tasks/task1_counter_race`
3.  **Inspect the code** and the task's `README.md`.
4.  **Build and run the test** by executing the `test.sh` script: `./test.sh`. Observe the failure.
5.  **Fix the code** in `main.cpp` according to the task's `README.md`.
6.  **Run the test script again** (`./test.sh`) to confirm your fix. `PASS` means you are ready for the next task!

To check your progress at any time, run the master test script from the root directory:

```bash
bash scripts/run_all_tests.sh
```

---

## Task List

*   **Task 1: The Race Condition:** See a race condition in action.
*   **Task 2: Fix with Mutex:** Learn to use `std::mutex` and `std::lock_guard`.
*   **Task 3: The Atomic Alternative:** Discover `std::atomic` for simple cases.
*   **Task 4: The Deadlock:** Find and fix a classic deadlock scenario.
*   **Task 5: Producer-Consumer:** Use `std::condition_variable` to synchronize two threads.
*   **Task 6: The Semaphore:** Use a C++20 semaphore to limit resource access.
