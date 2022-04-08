cmake_minimum_required(VERSION 3.16)

project(
    dynamic-shadows
    VERSION 1.0
    LANGUAGES CXX
)

# Build config variables
set(BUILD_DEMO FALSE)
set(BUILD_TESTS FALSE)

# Set C++ to version 14
set(CMAKE_CXX_STANDARD 14)

# Set binary destinations
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Set header dir
set(HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${HEADERS_DIR})

# Set source dir
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Set a name for the target
set(TARGET_LIB ${CMAKE_PROJECT_NAME}-lib)

# Make library ${TARGET_LIB}
add_library(
    ${TARGET_LIB} STATIC
    ${SOURCE_DIR}/math.cpp
    ${SOURCE_DIR}/vec2f.cpp
    ${SOURCE_DIR}/line2D.cpp
    ${SOURCE_DIR}/square2D.cpp
    ${SOURCE_DIR}/triangle2D.cpp
)

if (${BUILD_TESTS})
    # Enable testing (GoogleTests)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()

if (${BUILD_DEMO})
    # Demo
    add_subdirectory(demo)
endif()

install(TARGETS ${TARGET_LIB} DESTINATION lib)
install(DIRECTORY ${HEADERS_DIR} DESTINATION lib/include)