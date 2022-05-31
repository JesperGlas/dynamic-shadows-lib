set(TARGET ${PROJECT_NAME}-benchmark)

add_executable(
    ${TARGET}
    main.cpp
)

target_link_libraries(
    ${TARGET}
    PRIVATE
        dynamic-shadows-lib   
)

file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/benchmark_out)