set(TARGET ${PROJECT_NAME}-tests)

# FetchContent
include(FetchContent)
Set(FETCHCONTENT_QUIET FALSE)

message(STATUS "Fetching GoogleTest")
FetchContent_Declare(
  googletest
  GIT_REPOSITORY "https://github.com/google/googletest/"
  GIT_TAG "e2239ee6043f73722e7aa812a459f54a28552929"
  GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(googletest)

add_executable(
    ${TARGET}
    main.cpp
    vec2fTests.cpp
    line2DTests.cpp
)

target_link_libraries(
    ${TARGET}
    PRIVATE
        gtest_main
        dynamic-shadows-lib
)

include(GoogleTest)
gtest_discover_tests(${TARGET})