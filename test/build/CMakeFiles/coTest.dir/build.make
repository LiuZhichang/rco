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
include CMakeFiles/coTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/coTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/coTest.dir/flags.make

CMakeFiles/coTest.dir/cotest.cpp.o: CMakeFiles/coTest.dir/flags.make
CMakeFiles/coTest.dir/cotest.cpp.o: ../cotest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Code/cppCode/Rco/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/coTest.dir/cotest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coTest.dir/cotest.cpp.o -c /home/Code/cppCode/Rco/test/cotest.cpp

CMakeFiles/coTest.dir/cotest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coTest.dir/cotest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Code/cppCode/Rco/test/cotest.cpp > CMakeFiles/coTest.dir/cotest.cpp.i

CMakeFiles/coTest.dir/cotest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coTest.dir/cotest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Code/cppCode/Rco/test/cotest.cpp -o CMakeFiles/coTest.dir/cotest.cpp.s

CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/asm/context_jump.S.o: CMakeFiles/coTest.dir/flags.make
CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/asm/context_jump.S.o: /home/Code/cppCode/Rco/core/asm/context_jump.S
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Code/cppCode/Rco/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building ASM object CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/asm/context_jump.S.o"
	/usr/bin/cc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/asm/context_jump.S.o -c /home/Code/cppCode/Rco/core/asm/context_jump.S

CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/details/context.cpp.o: CMakeFiles/coTest.dir/flags.make
CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/details/context.cpp.o: /home/Code/cppCode/Rco/core/details/context.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Code/cppCode/Rco/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/details/context.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/details/context.cpp.o -c /home/Code/cppCode/Rco/core/details/context.cpp

CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/details/context.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/details/context.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Code/cppCode/Rco/core/details/context.cpp > CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/details/context.cpp.i

CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/details/context.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/details/context.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Code/cppCode/Rco/core/details/context.cpp -o CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/details/context.cpp.s

CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/rcontext.cpp.o: CMakeFiles/coTest.dir/flags.make
CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/rcontext.cpp.o: /home/Code/cppCode/Rco/core/rcontext.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Code/cppCode/Rco/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/rcontext.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/rcontext.cpp.o -c /home/Code/cppCode/Rco/core/rcontext.cpp

CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/rcontext.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/rcontext.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Code/cppCode/Rco/core/rcontext.cpp > CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/rcontext.cpp.i

CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/rcontext.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/rcontext.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Code/cppCode/Rco/core/rcontext.cpp -o CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/rcontext.cpp.s

CMakeFiles/coTest.dir/home/Code/cppCode/Rco/task/task.cpp.o: CMakeFiles/coTest.dir/flags.make
CMakeFiles/coTest.dir/home/Code/cppCode/Rco/task/task.cpp.o: /home/Code/cppCode/Rco/task/task.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Code/cppCode/Rco/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/coTest.dir/home/Code/cppCode/Rco/task/task.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coTest.dir/home/Code/cppCode/Rco/task/task.cpp.o -c /home/Code/cppCode/Rco/task/task.cpp

CMakeFiles/coTest.dir/home/Code/cppCode/Rco/task/task.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coTest.dir/home/Code/cppCode/Rco/task/task.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Code/cppCode/Rco/task/task.cpp > CMakeFiles/coTest.dir/home/Code/cppCode/Rco/task/task.cpp.i

CMakeFiles/coTest.dir/home/Code/cppCode/Rco/task/task.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coTest.dir/home/Code/cppCode/Rco/task/task.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Code/cppCode/Rco/task/task.cpp -o CMakeFiles/coTest.dir/home/Code/cppCode/Rco/task/task.cpp.s

CMakeFiles/coTest.dir/home/Code/cppCode/Rco/cpc/channel.cpp.o: CMakeFiles/coTest.dir/flags.make
CMakeFiles/coTest.dir/home/Code/cppCode/Rco/cpc/channel.cpp.o: /home/Code/cppCode/Rco/cpc/channel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Code/cppCode/Rco/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/coTest.dir/home/Code/cppCode/Rco/cpc/channel.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coTest.dir/home/Code/cppCode/Rco/cpc/channel.cpp.o -c /home/Code/cppCode/Rco/cpc/channel.cpp

CMakeFiles/coTest.dir/home/Code/cppCode/Rco/cpc/channel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coTest.dir/home/Code/cppCode/Rco/cpc/channel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Code/cppCode/Rco/cpc/channel.cpp > CMakeFiles/coTest.dir/home/Code/cppCode/Rco/cpc/channel.cpp.i

CMakeFiles/coTest.dir/home/Code/cppCode/Rco/cpc/channel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coTest.dir/home/Code/cppCode/Rco/cpc/channel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Code/cppCode/Rco/cpc/channel.cpp -o CMakeFiles/coTest.dir/home/Code/cppCode/Rco/cpc/channel.cpp.s

CMakeFiles/coTest.dir/home/Code/cppCode/Rco/scheduler/processer.cpp.o: CMakeFiles/coTest.dir/flags.make
CMakeFiles/coTest.dir/home/Code/cppCode/Rco/scheduler/processer.cpp.o: /home/Code/cppCode/Rco/scheduler/processer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Code/cppCode/Rco/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/coTest.dir/home/Code/cppCode/Rco/scheduler/processer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/coTest.dir/home/Code/cppCode/Rco/scheduler/processer.cpp.o -c /home/Code/cppCode/Rco/scheduler/processer.cpp

CMakeFiles/coTest.dir/home/Code/cppCode/Rco/scheduler/processer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coTest.dir/home/Code/cppCode/Rco/scheduler/processer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Code/cppCode/Rco/scheduler/processer.cpp > CMakeFiles/coTest.dir/home/Code/cppCode/Rco/scheduler/processer.cpp.i

CMakeFiles/coTest.dir/home/Code/cppCode/Rco/scheduler/processer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coTest.dir/home/Code/cppCode/Rco/scheduler/processer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Code/cppCode/Rco/scheduler/processer.cpp -o CMakeFiles/coTest.dir/home/Code/cppCode/Rco/scheduler/processer.cpp.s

# Object files for target coTest
coTest_OBJECTS = \
"CMakeFiles/coTest.dir/cotest.cpp.o" \
"CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/asm/context_jump.S.o" \
"CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/details/context.cpp.o" \
"CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/rcontext.cpp.o" \
"CMakeFiles/coTest.dir/home/Code/cppCode/Rco/task/task.cpp.o" \
"CMakeFiles/coTest.dir/home/Code/cppCode/Rco/cpc/channel.cpp.o" \
"CMakeFiles/coTest.dir/home/Code/cppCode/Rco/scheduler/processer.cpp.o"

# External object files for target coTest
coTest_EXTERNAL_OBJECTS =

coTest: CMakeFiles/coTest.dir/cotest.cpp.o
coTest: CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/asm/context_jump.S.o
coTest: CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/details/context.cpp.o
coTest: CMakeFiles/coTest.dir/home/Code/cppCode/Rco/core/rcontext.cpp.o
coTest: CMakeFiles/coTest.dir/home/Code/cppCode/Rco/task/task.cpp.o
coTest: CMakeFiles/coTest.dir/home/Code/cppCode/Rco/cpc/channel.cpp.o
coTest: CMakeFiles/coTest.dir/home/Code/cppCode/Rco/scheduler/processer.cpp.o
coTest: CMakeFiles/coTest.dir/build.make
coTest: CMakeFiles/coTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/Code/cppCode/Rco/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable coTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/coTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/coTest.dir/build: coTest

.PHONY : CMakeFiles/coTest.dir/build

CMakeFiles/coTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/coTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/coTest.dir/clean

CMakeFiles/coTest.dir/depend:
	cd /home/Code/cppCode/Rco/test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/Code/cppCode/Rco/test /home/Code/cppCode/Rco/test /home/Code/cppCode/Rco/test/build /home/Code/cppCode/Rco/test/build /home/Code/cppCode/Rco/test/build/CMakeFiles/coTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/coTest.dir/depend

