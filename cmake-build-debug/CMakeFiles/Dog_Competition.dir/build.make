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
CMAKE_SOURCE_DIR = /tmp/tmp.T6NouvRkdk

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.T6NouvRkdk/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Dog_Competition.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Dog_Competition.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Dog_Competition.dir/flags.make

CMakeFiles/Dog_Competition.dir/main.cpp.o: CMakeFiles/Dog_Competition.dir/flags.make
CMakeFiles/Dog_Competition.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.T6NouvRkdk/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Dog_Competition.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Dog_Competition.dir/main.cpp.o -c /tmp/tmp.T6NouvRkdk/main.cpp

CMakeFiles/Dog_Competition.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dog_Competition.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.T6NouvRkdk/main.cpp > CMakeFiles/Dog_Competition.dir/main.cpp.i

CMakeFiles/Dog_Competition.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dog_Competition.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.T6NouvRkdk/main.cpp -o CMakeFiles/Dog_Competition.dir/main.cpp.s

# Object files for target Dog_Competition
Dog_Competition_OBJECTS = \
"CMakeFiles/Dog_Competition.dir/main.cpp.o"

# External object files for target Dog_Competition
Dog_Competition_EXTERNAL_OBJECTS =

Dog_Competition: CMakeFiles/Dog_Competition.dir/main.cpp.o
Dog_Competition: CMakeFiles/Dog_Competition.dir/build.make
Dog_Competition: CMakeFiles/Dog_Competition.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.T6NouvRkdk/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Dog_Competition"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Dog_Competition.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Dog_Competition.dir/build: Dog_Competition

.PHONY : CMakeFiles/Dog_Competition.dir/build

CMakeFiles/Dog_Competition.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Dog_Competition.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Dog_Competition.dir/clean

CMakeFiles/Dog_Competition.dir/depend:
	cd /tmp/tmp.T6NouvRkdk/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.T6NouvRkdk /tmp/tmp.T6NouvRkdk /tmp/tmp.T6NouvRkdk/cmake-build-debug /tmp/tmp.T6NouvRkdk/cmake-build-debug /tmp/tmp.T6NouvRkdk/cmake-build-debug/CMakeFiles/Dog_Competition.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Dog_Competition.dir/depend

