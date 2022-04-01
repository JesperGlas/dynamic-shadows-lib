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
        ${HEADERS_DIR}
)