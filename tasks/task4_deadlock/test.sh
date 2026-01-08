#!/bin/bash

# Compile the code
g++ -std=c++17 main.cpp -pthread -o deadlock_test

# Run the executable in the background
./deadlock_test &
PID=$!

# Wait for 2 seconds
sleep 2

# Check if the process is still running
if kill -0 $PID 2>/dev/null; then
    # Process is still running, which means it's deadlocked.
    echo "TASK 4: FAIL (Deadlock detected)"
    kill -9 $PID # Force kill the process
    exit 1
else
    # Process finished correctly.
    echo "TASK 4: PASS"
    exit 0
fi
