set(TARGET ${PROJECT_NAME}-benchmark)

add_executable(
    ${TARGET}
    main.cpp
)

file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/benchmark_out)