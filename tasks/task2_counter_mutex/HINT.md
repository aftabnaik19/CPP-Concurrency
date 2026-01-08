# Hint for Task 2

1.  Add `#include <mutex>` at the top of the file.
2.  Create a global mutex object: `std::mutex m;`
3.  Inside the `increment` function, before `counter++`, create a lock guard object that locks the mutex. The syntax is `std::lock_guard<std::mutex> guard(m);`.

The lock guard will automatically lock the mutex. When the `increment` function returns and the guard goes out of scope, it will automatically unlock the mutex.
