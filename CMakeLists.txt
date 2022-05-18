cmake_minimum_required(VERSION 3.16)

project(
    dynamic-shadows
    VERSION 1.0
    LANGUAGES CXX
)

# Build config variables
set(BUILD_DEMO TRUE)
set(BUILD_TESTS TRUE)

# Set C++ to version 14
set(CMAKE_CXX_STANDARD 14)

# Set binary destinations
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

# Set header dir
set(HEADERS_DIR ${PROJECT_SOURCE_DIR}/include)

# Set source dir
set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

# Set a name for the target
set(TARGET_LIB ${PROJECT_NAME}-lib)

# Make library ${TARGET_LIB}
add_library(
    ${TARGET_LIB} STATIC
    ${SOURCE_DIR}/math.cpp
    ${SOURCE_DIR}/vec2f.cpp
    ${SOURCE_DIR}/line2D.cpp
    ${SOURCE_DIR}/square2D.cpp
    ${SOURCE_DIR}/triangle2D.cpp
    ${SOURCE_DIR}/evenShape2D.cpp
)

target_include_directories(
    ${TARGET_LIB}
    PUBLIC
        ${HEADERS_DIR}   
)

if (${BUILD_TESTS})
    # Enable testing (GoogleTests)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()