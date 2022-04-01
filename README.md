# dynamic-shadows-lib
A C++ library for calculating the blocking edge of primitive shapes in relation a lightsource. This can then be used as a near edge of a trapezoid representing the shapes 2D shadow.

## Dependencies
The demo and visual tests requires python 3.8 with matplotlib installed.

## Build with CMake (Ubuntu)
0. Make sure you have CMake installed
1. Open the root directory in your terminal
2. mkdir build
3. cd build
4. cmake ../
5. cmake --build .

## Binaries
- ./dynamic-shadows-demo          - A small visual demo.
- ./dynamic-shadows-tests         - Unit tests with GoogleTest
- ./dynamic-shadows-visual-tests  - Generates visual testcases in build/visual_out
