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
CMAKE_SOURCE_DIR = /home/Code/cppCode/Rco/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/Code/cppCode/Rco/test/build

# Include any dependencies generated for this target.
include CMakeFiles/tslistTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tslistTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tslistTest.dir/flags.make

CMakeFiles/tslistTest.dir/tslistTest.cpp.o: CMakeFiles/tslistTest.dir/flags.make
CMakeFiles/tslistTest.dir/tslistTest.cpp.o: ../tslistTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Code/cppCode/Rco/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tslistTest.dir/tslistTest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tslistTest.dir/tslistTest.cpp.o -c /home/Code/cppCode/Rco/test/tslistTest.cpp

CMakeFiles/tslistTest.dir/tslistTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tslistTest.dir/tslistTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Code/cppCode/Rco/test/tslistTest.cpp > CMakeFiles/tslistTest.dir/tslistTest.cpp.i

CMakeFiles/tslistTest.dir/tslistTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tslistTest.dir/tslistTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Code/cppCode/Rco/test/tslistTest.cpp -o CMakeFiles/tslistTest.dir/tslistTest.cpp.s

# Object files for target tslistTest
tslistTest_OBJECTS = \
"CMakeFiles/tslistTest.dir/tslistTest.cpp.o"

# External object files for target tslistTest
tslistTest_EXTERNAL_OBJECTS =

tslistTest: CMakeFiles/tslistTest.dir/tslistTest.cpp.o
tslistTest: CMakeFiles/tslistTest.dir/build.make
tslistTest: CMakeFiles/tslistTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/Code/cppCode/Rco/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tslistTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tslistTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tslistTest.dir/build: tslistTest

.PHONY : CMakeFiles/tslistTest.dir/build

CMakeFiles/tslistTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tslistTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tslistTest.dir/clean

CMakeFiles/tslistTest.dir/depend:
	cd /home/Code/cppCode/Rco/test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/Code/cppCode/Rco/test /home/Code/cppCode/Rco/test /home/Code/cppCode/Rco/test/build /home/Code/cppCode/Rco/test/build /home/Code/cppCode/Rco/test/build/CMakeFiles/tslistTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tslistTest.dir/depend
