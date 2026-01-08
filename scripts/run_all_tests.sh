#!/bin/bash

# Get the root directory of the project
ROOT_DIR=$(dirname "$0")/..
cd "$ROOT_DIR"

# Find all test scripts and run them
for task_dir in tasks/task*/; do
    if [ -f "${task_dir}test.sh" ]; then
        echo "=================================================="
        echo "Running test in ${task_dir}"
        echo "=================================================="
        (cd "$task_dir" && ./test.sh)
        echo ""
    fi
done

echo "=================================================="
echo "All tests finished."
echo "=================================================="
