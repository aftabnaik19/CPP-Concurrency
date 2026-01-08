#!/bin/bash

# Compile the code
g++ -std=c++17 main.cpp -pthread -o counter_race

# Run the code
OUTPUT=$(./counter_race)
RESULT=$(echo $OUTPUT | grep -o -E '[0-9]+')

# The correct value should be 2,000,000.
# This test "passes" if the race condition occurs and the value is wrong.
if [ "$RESULT" -ne 2000000 ]; then
    echo "TASK 1: PASS (Race condition detected as expected)"
    exit 0
else
    echo "TASK 1: FAIL (No race condition detected? Try running again.)"
    exit 1
fi
