#!/bin/bash

# Compile the code using C++20 standard
g++ -std=c++20 main.cpp -pthread -o semaphore_test

# Run the executable. It will return 0 on success.
./semaphore_test

# Check the exit code of the last command
if [ $? -eq 0 ]; then
    echo "TASK 6: PASS (Please verify from the output that no more than 3 workers ran concurrently)"
    exit 0
else
    echo "TASK 6: FAIL"
    exit 1
fi
