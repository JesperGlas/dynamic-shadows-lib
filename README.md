# dynamic-shadows-lib
A C++ library for calculating the blocking edge of primitive shapes in relation a lightsource. This can then be used as a near edge of a trapezoid representing the shapes 2D shadow.

## Build with CMake (Ubuntu)
0. Make sure you have CMake installed
1. Open the root directory in your terminal
2. mkdir build
3. cd build
4. cmake ../
5. cmake --build .
6. ./tests/test_main (To run tests)