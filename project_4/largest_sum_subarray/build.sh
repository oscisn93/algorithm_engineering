#!/bin/bash

rm main

echo "Compile main.cpp using clang compiler"
clang++ main.cpp -o main

echo "Run the Largest Sum Array program:"
./main < 1.in

echo "Build process completed"

