# FetchContent
include(FetchContent)
Set(FETCHCONTENT_QUIET FALSE)

# Matplotlib
# find python libraries
find_package(Python3 COMPONENTS Interpreter Development NumPy REQUIRED)
find_package(PythonLibs 3.0 REQUIRED)
include_directories(${PYTHON3_INCLUDE_DIRS} ${NumPy_INCLUDE_DIRS})

message(STATUS "Fetching matplotlib-cpp")
FetchContent_Declare(
  matplotlib
  GIT_REPOSITORY "https://github.com/lava/matplotlib-cpp/"
  GIT_TAG "ef0383f1315d32e0156335e10b82e90b334f6d9f"
  GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(matplotlib)

include_directories(SYSTEM ${matplotlib_SOURCE_DIR})

# Add playground executable for testing
set(TARGET_VISUAL_TEST ${PROJECT_NAME}-visual-tests)

add_executable(
  ${TARGET_VISUAL_TEST}
  main.cpp
)

target_link_libraries(
    ${TARGET_VISUAL_TEST}
    PRIVATE
        ${PYTHON_LIBRARIES}
        Python3::NumPy
        dynamic-shadows-lib
)

# Set include directory for ${TARGET_DEMO}
target_include_directories(
    ${TARGET_VISUAL_TEST}
    PUBLIC
        ${HEADERS_DIR}
)

# Create directory for visual test output
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/visual_out)