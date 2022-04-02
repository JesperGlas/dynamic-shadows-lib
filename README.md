# dynamic-shadows-lib
A C++ library for calculating the blocking edge of primitive shapes in relation a lightsource. This can then be used as a near edge of a trapezoid representing the shapes 2D shadow.

## Dependencies
- Python3.8
  - pip3
  - numpy
  - matplotlib
- CMake
- Git

## Build with CMake (Ubuntu)
0. Make sure you have CMake installed
1. Open the project root directory in your terminal
2. mkdir build
3. cd build
4. cmake ../
5. cmake --build .

## Binaries

### dynamic-shadows-demo
  A small visual demo using matplotlibcpp.
  
### dynamic-shadows-tests
  Unit tests with GoogleTest

### dynamic-shadows-visual-tests
  Generates visual test results as .png files in ./build/visual_out/
