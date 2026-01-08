#!/bin/bash

# Compile the code
g++ -std=c++17 main.cpp -pthread -o counter_mutex

# Run the code
OUTPUT=$(./counter_mutex)
RESULT=$(echo $OUTPUT | grep -o -E '[0-9]+')

# The correct value should be 2,000,000.
if [ "$RESULT" -eq 2000000 ]; then
    echo "TASK 2: PASS"
    exit 0
else
    echo "TASK 2: FAIL (Expected 2000000, got $RESULT)"
    exit 1
fi
