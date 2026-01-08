#!/bin/bash

# Compile the code
g++ -std=c++17 main.cpp -pthread -o prod_cons_test

# Run the executable. It will return 0 on success.
./prod_cons_test

# Check the exit code of the last command
if [ $? -eq 0 ]; then
    echo "TASK 5: PASS"
    exit 0
else
    echo "TASK 5: FAIL (Incorrect number of items consumed)"
    exit 1
fi
