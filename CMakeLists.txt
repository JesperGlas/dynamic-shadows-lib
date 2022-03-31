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

# Set source dir
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Make library ${TARGET_LIB}
add_library(
    ${TARGET_LIB} STATIC
    ${SOURCE_DIR}/vec2f.cpp
    ${SOURCE_DIR}/line2D.cpp
)

# Set include directory for ${TARGET_LIB}
target_include_directories(
    ${TARGET_LIB}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Enable testing (GoogleTests)
enable_testing()
add_subdirectory(tests)

# DEMO EXECUTABLE

# Add playground executable for testing
set(TARGET_DEMO ${PROJECT_NAME}-demo)

add_executable(${TARGET_DEMO} demo.cpp)

target_link_libraries(
    ${TARGET_DEMO}
    PRIVATE
        dynamic-shadows-lib
)

# Set include directory for ${TARGET_DEMO}
target_include_directories(
    ${TARGET_DEMO}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)