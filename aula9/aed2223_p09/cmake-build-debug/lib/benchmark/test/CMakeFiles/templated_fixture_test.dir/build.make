# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/219/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/219/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dsferreira/dsantosferreira/programming/aed/aula9/aed2223_p09

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dsferreira/dsantosferreira/programming/aed/aula9/aed2223_p09/cmake-build-debug

# Include any dependencies generated for this target.
include lib/benchmark/test/CMakeFiles/templated_fixture_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/benchmark/test/CMakeFiles/templated_fixture_test.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/benchmark/test/CMakeFiles/templated_fixture_test.dir/progress.make

# Include the compile flags for this target's objects.
include lib/benchmark/test/CMakeFiles/templated_fixture_test.dir/flags.make

lib/benchmark/test/CMakeFiles/templated_fixture_test.dir/templated_fixture_test.cc.o: lib/benchmark/test/CMakeFiles/templated_fixture_test.dir/flags.make
lib/benchmark/test/CMakeFiles/templated_fixture_test.dir/templated_fixture_test.cc.o: /home/dsferreira/dsantosferreira/programming/aed/aula9/aed2223_p09/lib/benchmark/test/templated_fixture_test.cc
lib/benchmark/test/CMakeFiles/templated_fixture_test.dir/templated_fixture_test.cc.o: lib/benchmark/test/CMakeFiles/templated_fixture_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dsferreira/dsantosferreira/programming/aed/aula9/aed2223_p09/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/benchmark/test/CMakeFiles/templated_fixture_test.dir/templated_fixture_test.cc.o"
	cd /home/dsferreira/dsantosferreira/programming/aed/aula9/aed2223_p09/cmake-build-debug/lib/benchmark/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/benchmark/test/CMakeFiles/templated_fixture_test.dir/templated_fixture_test.cc.o -MF CMakeFiles/templated_fixture_test.dir/templated_fixture_test.cc.o.d -o CMakeFiles/templated_fixture_test.dir/templated_fixture_test.cc.o -c /home/dsferreira/dsantosferreira/programming/aed/aula9/aed2223_p09/lib/benchmark/test/templated_fixture_test.cc

lib/benchmark/test/CMakeFiles/templated_fixture_test.dir/templated_fixture_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/templated_fixture_test.dir/templated_fixture_test.cc.i"
	cd /home/dsferreira/dsantosferreira/programming/aed/aula9/aed2223_p09/cmake-build-debug/lib/benchmark/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dsferreira/dsantosferreira/programming/aed/aula9/aed2223_p09/lib/benchmark/test/templated_fixture_test.cc > CMakeFiles/templated_fixture_test.dir/templated_fixture_test.cc.i

lib/benchmark/test/CMakeFiles/templated_fixture_test.dir/templated_fixture_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/templated_fixture_test.dir/templated_fixture_test.cc.s"
	cd /home/dsferreira/dsantosferreira/programming/aed/aula9/aed2223_p09/cmake-build-debug/lib/benchmark/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dsferreira/dsantosferreira/programming/aed/aula9/aed2223_p09/lib/benchmark/test/templated_fixture_test.cc -o CMakeFiles/templated_fixture_test.dir/templated_fixture_test.cc.s

# Object files for target templated_fixture_test
templated_fixture_test_OBJECTS = \
"CMakeFiles/templated_fixture_test.dir/templated_fixture_test.cc.o"

# External object files for target templated_fixture_test
templated_fixture_test_EXTERNAL_OBJECTS =

lib/benchmark/test/templated_fixture_test: lib/benchmark/test/CMakeFiles/templated_fixture_test.dir/templated_fixture_test.cc.o
lib/benchmark/test/templated_fixture_test: lib/benchmark/test/CMakeFiles/templated_fixture_test.dir/build.make
lib/benchmark/test/templated_fixture_test: lib/benchmark/test/liboutput_test_helper.a
lib/benchmark/test/templated_fixture_test: lib/benchmark/src/libbenchmark_main.a
lib/benchmark/test/templated_fixture_test: lib/benchmark/src/libbenchmark.a
lib/benchmark/test/templated_fixture_test: lib/benchmark/test/CMakeFiles/templated_fixture_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dsferreira/dsantosferreira/programming/aed/aula9/aed2223_p09/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable templated_fixture_test"
	cd /home/dsferreira/dsantosferreira/programming/aed/aula9/aed2223_p09/cmake-build-debug/lib/benchmark/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/templated_fixture_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/benchmark/test/CMakeFiles/templated_fixture_test.dir/build: lib/benchmark/test/templated_fixture_test
.PHONY : lib/benchmark/test/CMakeFiles/templated_fixture_test.dir/build

lib/benchmark/test/CMakeFiles/templated_fixture_test.dir/clean:
	cd /home/dsferreira/dsantosferreira/programming/aed/aula9/aed2223_p09/cmake-build-debug/lib/benchmark/test && $(CMAKE_COMMAND) -P CMakeFiles/templated_fixture_test.dir/cmake_clean.cmake
.PHONY : lib/benchmark/test/CMakeFiles/templated_fixture_test.dir/clean

lib/benchmark/test/CMakeFiles/templated_fixture_test.dir/depend:
	cd /home/dsferreira/dsantosferreira/programming/aed/aula9/aed2223_p09/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dsferreira/dsantosferreira/programming/aed/aula9/aed2223_p09 /home/dsferreira/dsantosferreira/programming/aed/aula9/aed2223_p09/lib/benchmark/test /home/dsferreira/dsantosferreira/programming/aed/aula9/aed2223_p09/cmake-build-debug /home/dsferreira/dsantosferreira/programming/aed/aula9/aed2223_p09/cmake-build-debug/lib/benchmark/test /home/dsferreira/dsantosferreira/programming/aed/aula9/aed2223_p09/cmake-build-debug/lib/benchmark/test/CMakeFiles/templated_fixture_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/benchmark/test/CMakeFiles/templated_fixture_test.dir/depend

