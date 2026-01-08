# Hint for Task 1

The issue here is that `++counter` is not a single, atomic operation. It's actually three operations:

1.  **Read** the current value of `counter`.
2.  **Increment** the value.
3.  **Write** the new value back to `counter`.

When two threads do this at the same time, they can both read the *same* initial value, increment it, and then write back the same result, overwriting each other's work. This is why the final count is lower than expected.
