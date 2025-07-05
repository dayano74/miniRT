#!/bin/bash

for file in scenes/ng/*.rt; do
    echo "Running: $file"
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes  -q  ./miniRT "$file"
done