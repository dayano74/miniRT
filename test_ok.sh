#!/bin/bash

for file in scenes/*.rt; do
    echo "Running: $file"
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes    ./miniRT "$file"
done