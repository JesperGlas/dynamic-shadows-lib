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
include CMakeFiles/dynamic-shadows-lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dynamic-shadows-lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dynamic-shadows-lib.dir/flags.make

CMakeFiles/dynamic-shadows-lib.dir/src/vec2f.cpp.o: CMakeFiles/dynamic-shadows-lib.dir/flags.make
CMakeFiles/dynamic-shadows-lib.dir/src/vec2f.cpp.o: ../src/vec2f.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jesper/dev/cpp/dynamic-shadows-lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dynamic-shadows-lib.dir/src/vec2f.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dynamic-shadows-lib.dir/src/vec2f.cpp.o -c /home/jesper/dev/cpp/dynamic-shadows-lib/src/vec2f.cpp

CMakeFiles/dynamic-shadows-lib.dir/src/vec2f.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dynamic-shadows-lib.dir/src/vec2f.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jesper/dev/cpp/dynamic-shadows-lib/src/vec2f.cpp > CMakeFiles/dynamic-shadows-lib.dir/src/vec2f.cpp.i

CMakeFiles/dynamic-shadows-lib.dir/src/vec2f.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dynamic-shadows-lib.dir/src/vec2f.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jesper/dev/cpp/dynamic-shadows-lib/src/vec2f.cpp -o CMakeFiles/dynamic-shadows-lib.dir/src/vec2f.cpp.s

# Object files for target dynamic-shadows-lib
dynamic__shadows__lib_OBJECTS = \
"CMakeFiles/dynamic-shadows-lib.dir/src/vec2f.cpp.o"

# External object files for target dynamic-shadows-lib
dynamic__shadows__lib_EXTERNAL_OBJECTS =

libdynamic-shadows-lib.a: CMakeFiles/dynamic-shadows-lib.dir/src/vec2f.cpp.o
libdynamic-shadows-lib.a: CMakeFiles/dynamic-shadows-lib.dir/build.make
libdynamic-shadows-lib.a: CMakeFiles/dynamic-shadows-lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jesper/dev/cpp/dynamic-shadows-lib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libdynamic-shadows-lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/dynamic-shadows-lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dynamic-shadows-lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dynamic-shadows-lib.dir/build: libdynamic-shadows-lib.a

.PHONY : CMakeFiles/dynamic-shadows-lib.dir/build

CMakeFiles/dynamic-shadows-lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dynamic-shadows-lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dynamic-shadows-lib.dir/clean

CMakeFiles/dynamic-shadows-lib.dir/depend:
	cd /home/jesper/dev/cpp/dynamic-shadows-lib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jesper/dev/cpp/dynamic-shadows-lib /home/jesper/dev/cpp/dynamic-shadows-lib /home/jesper/dev/cpp/dynamic-shadows-lib/build /home/jesper/dev/cpp/dynamic-shadows-lib/build /home/jesper/dev/cpp/dynamic-shadows-lib/build/CMakeFiles/dynamic-shadows-lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dynamic-shadows-lib.dir/depend
