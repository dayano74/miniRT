#!/bin/bash

for file in scenes/ng/*.rt; do
    echo "Running: $file"
    ./miniRT "$file"
done
