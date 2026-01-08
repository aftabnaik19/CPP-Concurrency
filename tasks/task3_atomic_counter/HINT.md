# Hint for Task 3

1.  Add `#include <atomic>` at the top of the file.
2.  Change the declaration of `counter` from `long long` to `std::atomic<long long>`.
3.  Initialize it to zero: `std::atomic<long long> counter = 0;`
4.  You can remove the `// This increment is not atomic!` comment. The `++` operation is now guaranteed to be atomic because the `counter` variable is an atomic type.
5.  When printing the final value, it's good practice to use `.load()` to read from an atomic, although direct printing often works: `std::cout << counter.load() << std::endl;`
