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
include CMakeFiles/taskTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/taskTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/taskTest.dir/flags.make

CMakeFiles/taskTest.dir/taskTest.cpp.o: CMakeFiles/taskTest.dir/flags.make
CMakeFiles/taskTest.dir/taskTest.cpp.o: ../taskTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Code/cppCode/Rco/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/taskTest.dir/taskTest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/taskTest.dir/taskTest.cpp.o -c /home/Code/cppCode/Rco/test/taskTest.cpp

CMakeFiles/taskTest.dir/taskTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/taskTest.dir/taskTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Code/cppCode/Rco/test/taskTest.cpp > CMakeFiles/taskTest.dir/taskTest.cpp.i

CMakeFiles/taskTest.dir/taskTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/taskTest.dir/taskTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Code/cppCode/Rco/test/taskTest.cpp -o CMakeFiles/taskTest.dir/taskTest.cpp.s

CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/asm/context_jump.S.o: CMakeFiles/taskTest.dir/flags.make
CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/asm/context_jump.S.o: /home/Code/cppCode/Rco/core/asm/context_jump.S
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Code/cppCode/Rco/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building ASM object CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/asm/context_jump.S.o"
	/usr/bin/cc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/asm/context_jump.S.o -c /home/Code/cppCode/Rco/core/asm/context_jump.S

CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/details/context.cpp.o: CMakeFiles/taskTest.dir/flags.make
CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/details/context.cpp.o: /home/Code/cppCode/Rco/core/details/context.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Code/cppCode/Rco/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/details/context.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/details/context.cpp.o -c /home/Code/cppCode/Rco/core/details/context.cpp

CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/details/context.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/details/context.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Code/cppCode/Rco/core/details/context.cpp > CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/details/context.cpp.i

CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/details/context.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/details/context.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Code/cppCode/Rco/core/details/context.cpp -o CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/details/context.cpp.s

CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/rcontext.cpp.o: CMakeFiles/taskTest.dir/flags.make
CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/rcontext.cpp.o: /home/Code/cppCode/Rco/core/rcontext.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Code/cppCode/Rco/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/rcontext.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/rcontext.cpp.o -c /home/Code/cppCode/Rco/core/rcontext.cpp

CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/rcontext.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/rcontext.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Code/cppCode/Rco/core/rcontext.cpp > CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/rcontext.cpp.i

CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/rcontext.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/rcontext.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Code/cppCode/Rco/core/rcontext.cpp -o CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/rcontext.cpp.s

CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/task/task.cpp.o: CMakeFiles/taskTest.dir/flags.make
CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/task/task.cpp.o: /home/Code/cppCode/Rco/task/task.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Code/cppCode/Rco/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/task/task.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/task/task.cpp.o -c /home/Code/cppCode/Rco/task/task.cpp

CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/task/task.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/task/task.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Code/cppCode/Rco/task/task.cpp > CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/task/task.cpp.i

CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/task/task.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/task/task.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Code/cppCode/Rco/task/task.cpp -o CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/task/task.cpp.s

# Object files for target taskTest
taskTest_OBJECTS = \
"CMakeFiles/taskTest.dir/taskTest.cpp.o" \
"CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/asm/context_jump.S.o" \
"CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/details/context.cpp.o" \
"CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/rcontext.cpp.o" \
"CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/task/task.cpp.o"

# External object files for target taskTest
taskTest_EXTERNAL_OBJECTS =

taskTest: CMakeFiles/taskTest.dir/taskTest.cpp.o
taskTest: CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/asm/context_jump.S.o
taskTest: CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/details/context.cpp.o
taskTest: CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/core/rcontext.cpp.o
taskTest: CMakeFiles/taskTest.dir/home/Code/cppCode/Rco/task/task.cpp.o
taskTest: CMakeFiles/taskTest.dir/build.make
taskTest: CMakeFiles/taskTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/Code/cppCode/Rco/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable taskTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/taskTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/taskTest.dir/build: taskTest

.PHONY : CMakeFiles/taskTest.dir/build

CMakeFiles/taskTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/taskTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/taskTest.dir/clean

CMakeFiles/taskTest.dir/depend:
	cd /home/Code/cppCode/Rco/test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/Code/cppCode/Rco/test /home/Code/cppCode/Rco/test /home/Code/cppCode/Rco/test/build /home/Code/cppCode/Rco/test/build /home/Code/cppCode/Rco/test/build/CMakeFiles/taskTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/taskTest.dir/depend
