# dynamic-shadows-lib
A C++ library for calculating the blocking edge of primitive shapes in relation a lightsource. This can then be used as a near edge of a trapezoid representing the shapes 2D shadow.

## Dependencies
- Python3.8
  - pip3
  - numpy
  - matplotlib
- CMake
- Git

(This library and its utilities has only been tested on Ubuntu 20.04. Other dependencies/fixes might be needed for other systems.)

## Build with CMake (Ubuntu)
0. Make sure you have the necessary dependencies installed
1. Open the project root directory in your terminal
2. mkdir build
3. cd build
4. cmake ../
5. cmake --build .

(Using the VSCode extension "CMake Tools" make this process eaiser. It's included in the "C/C++ Extension Pack" extension.)

## Content

```
.
├── CMakeLists.txt
├── demo
│   ├── CMakeLists.txt
│   └── demo.cpp
├── include
│   ├── line2D.hpp
│   ├── math.hpp
│   ├── mathplotUtil.hpp
│   ├── square2D.hpp
│   └── vec2f.hpp
├── LICENSE
├── README.md
├── src
│   ├── line2D.cpp
│   ├── math.cpp
│   ├── square2D.cpp
│   └── vec2f.cpp
└── tests
    ├── CMakeLists.txt
    ├── unit_tests
    │   ├── CMakeLists.txt
    │   ├── line2DTests.cpp
    │   ├── main.cpp
    │   ├── square2DTests.cpp
    │   └── vec2fTests.cpp
    └── visual_tests
        ├── CMakeLists.txt
        ├── main.cpp
        └── visualTests.hpp
```

## Binaries

### dynamic-shadows-demo
  A visual playground for the shapes using matplot lib. Shapes can be defined in ./demo/demp.cpp to get visual results.
  
### dynamic-shadows-tests
  Unit tests with GoogleTest.

### dynamic-shadows-visual-tests
  Generates pre-made visual tests as .png files in ./build/visual_out/. Additional tests can be defined in ./tests/visual_tests/main.cpp (Additional tests needs to be defined in the header visualTests.hpp).
