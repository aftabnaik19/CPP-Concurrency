# Hint for Task 5

This is the most complex task so far. Here's a breakdown for the `push` method. The `pop` method is very similar.

### For `push(int value)`:

1.  **Lock:** Start with `std::unique_lock<std::mutex> lock(mtx);`. You need `unique_lock` for condition variables.

2.  **Wait:** The producer must wait if the queue is full. The condition to wait for is "the queue is NOT full", i.e., `buffer.size() < MAX_QUEUE_SIZE`. The `wait` call looks like this:
    ```cpp
    cv_producer.wait(lock, [this]{
        return buffer.size() < MAX_QUEUE_SIZE;
    });
    ```
    The `wait` function will:
    a. Check the condition.
    b. If it's false, it will unlock the `lock` and put the thread to sleep.
    c. When another thread calls `notify_one()` or `notify_all()`, this thread will wake up, re-lock the `lock`, and check the condition again. It only proceeds if the condition is true.

3.  **Push:** After the wait is over, you are guaranteed to have the lock and know that the buffer is not full. So, `buffer.push(value);`.

4.  **Notify:** You just added an item, so the consumer might be waiting because the queue was empty. You need to wake it up: `cv_consumer.notify_one();`.

The logic for `pop()` is the mirror image of this.
