# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jesper/dev/cpp/dynamic-shadows-lib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jesper/dev/cpp/dynamic-shadows-lib/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/test_main.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/test_main.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test_main.dir/flags.make

tests/CMakeFiles/test_main.dir/main.cpp.o: tests/CMakeFiles/test_main.dir/flags.make
tests/CMakeFiles/test_main.dir/main.cpp.o: ../tests/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jesper/dev/cpp/dynamic-shadows-lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/test_main.dir/main.cpp.o"
	cd /home/jesper/dev/cpp/dynamic-shadows-lib/build/tests && /bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_main.dir/main.cpp.o -c /home/jesper/dev/cpp/dynamic-shadows-lib/tests/main.cpp

tests/CMakeFiles/test_main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_main.dir/main.cpp.i"
	cd /home/jesper/dev/cpp/dynamic-shadows-lib/build/tests && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jesper/dev/cpp/dynamic-shadows-lib/tests/main.cpp > CMakeFiles/test_main.dir/main.cpp.i

tests/CMakeFiles/test_main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_main.dir/main.cpp.s"
	cd /home/jesper/dev/cpp/dynamic-shadows-lib/build/tests && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jesper/dev/cpp/dynamic-shadows-lib/tests/main.cpp -o CMakeFiles/test_main.dir/main.cpp.s

# Object files for target test_main
test_main_OBJECTS = \
"CMakeFiles/test_main.dir/main.cpp.o"

# External object files for target test_main
test_main_EXTERNAL_OBJECTS =

tests/test_main: tests/CMakeFiles/test_main.dir/main.cpp.o
tests/test_main: tests/CMakeFiles/test_main.dir/build.make
tests/test_main: libdynamic-shadows-lib.a
tests/test_main: tests/CMakeFiles/test_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jesper/dev/cpp/dynamic-shadows-lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_main"
	cd /home/jesper/dev/cpp/dynamic-shadows-lib/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/test_main.dir/build: tests/test_main

.PHONY : tests/CMakeFiles/test_main.dir/build

tests/CMakeFiles/test_main.dir/clean:
	cd /home/jesper/dev/cpp/dynamic-shadows-lib/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_main.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/test_main.dir/clean

tests/CMakeFiles/test_main.dir/depend:
	cd /home/jesper/dev/cpp/dynamic-shadows-lib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jesper/dev/cpp/dynamic-shadows-lib /home/jesper/dev/cpp/dynamic-shadows-lib/tests /home/jesper/dev/cpp/dynamic-shadows-lib/build /home/jesper/dev/cpp/dynamic-shadows-lib/build/tests /home/jesper/dev/cpp/dynamic-shadows-lib/build/tests/CMakeFiles/test_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/test_main.dir/depend
