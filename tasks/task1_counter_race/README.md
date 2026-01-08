# Task 1: The Race Condition

**Goal:** Observe a race condition.

The `main.cpp` file contains a simple program where two threads increment a shared counter.

1.  Compile and run the code using the test script: `./test.sh`
2.  Observe the output. The expected final value of the counter is 2,000,000.
3.  The test will fail because the actual value is unpredictable and almost always less than 2,000,000.

This happens because both threads are reading and writing to the `counter` variable at the same time without any synchronization. This is a classic **race condition**.

Your job is done for this task. Proceed to **Task 2** to fix this bug.
