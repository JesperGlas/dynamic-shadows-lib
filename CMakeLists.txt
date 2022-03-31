cmake_minimum_required(VERSION 3.16)

project(
    dynamic-shadows
    VERSION 1.0
    LANGUAGES CXX
)

# Set C++ to version 14
set(CMAKE_CXX_STANDARD 14)

# Set a name for the target
set(TARGET_LIB ${CMAKE_PROJECT_NAME}-lib)

# Make library ${TARGET_LIB}
add_library(
    ${TARGET_LIB} STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vec2f.cpp
)

# Set include directory for ${TARGET_LIB}
target_include_directories(
    ${TARGET_LIB}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_subdirectory(tests)
