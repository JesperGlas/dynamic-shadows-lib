set(TARGET test_main)

add_executable(${TARGET} main.cpp)
target_link_libraries(
    ${TARGET}
    PRIVATE
        dynamic-shadows-lib
)