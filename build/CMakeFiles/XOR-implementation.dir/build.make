# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/glebegor/Programming/school/c-xor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/glebegor/Programming/school/c-xor/build

# Include any dependencies generated for this target.
include CMakeFiles/XOR-implementation.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/XOR-implementation.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/XOR-implementation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/XOR-implementation.dir/flags.make

CMakeFiles/XOR-implementation.dir/main.c.o: CMakeFiles/XOR-implementation.dir/flags.make
CMakeFiles/XOR-implementation.dir/main.c.o: /Users/glebegor/Programming/school/c-xor/main.c
CMakeFiles/XOR-implementation.dir/main.c.o: CMakeFiles/XOR-implementation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/glebegor/Programming/school/c-xor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/XOR-implementation.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/XOR-implementation.dir/main.c.o -MF CMakeFiles/XOR-implementation.dir/main.c.o.d -o CMakeFiles/XOR-implementation.dir/main.c.o -c /Users/glebegor/Programming/school/c-xor/main.c

CMakeFiles/XOR-implementation.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/XOR-implementation.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/glebegor/Programming/school/c-xor/main.c > CMakeFiles/XOR-implementation.dir/main.c.i

CMakeFiles/XOR-implementation.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/XOR-implementation.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/glebegor/Programming/school/c-xor/main.c -o CMakeFiles/XOR-implementation.dir/main.c.s

# Object files for target XOR-implementation
XOR__implementation_OBJECTS = \
"CMakeFiles/XOR-implementation.dir/main.c.o"

# External object files for target XOR-implementation
XOR__implementation_EXTERNAL_OBJECTS =

XOR-implementation: CMakeFiles/XOR-implementation.dir/main.c.o
XOR-implementation: CMakeFiles/XOR-implementation.dir/build.make
XOR-implementation: CMakeFiles/XOR-implementation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/glebegor/Programming/school/c-xor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable XOR-implementation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/XOR-implementation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/XOR-implementation.dir/build: XOR-implementation
.PHONY : CMakeFiles/XOR-implementation.dir/build

CMakeFiles/XOR-implementation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/XOR-implementation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/XOR-implementation.dir/clean

CMakeFiles/XOR-implementation.dir/depend:
	cd /Users/glebegor/Programming/school/c-xor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/glebegor/Programming/school/c-xor /Users/glebegor/Programming/school/c-xor /Users/glebegor/Programming/school/c-xor/build /Users/glebegor/Programming/school/c-xor/build /Users/glebegor/Programming/school/c-xor/build/CMakeFiles/XOR-implementation.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/XOR-implementation.dir/depend

