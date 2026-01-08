#!/bin/bash

# Compile the code
g++ -std=c++17 main.cpp -pthread -o counter_atomic

# Run the code
OUTPUT=$(./counter_atomic)
RESULT=$(echo $OUTPUT | grep -o -E '[0-9]+')

# The correct value should be 2,000,000.
if [ "$RESULT" -eq 2000000 ]; then
    echo "TASK 3: PASS"
    exit 0
else
    echo "TASK 3: FAIL (Expected 2000000, got $RESULT)"
    exit 1
fi
