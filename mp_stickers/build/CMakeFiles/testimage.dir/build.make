# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/cs225/CS-225/mp_stickers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/cs225/CS-225/mp_stickers/build

# Include any dependencies generated for this target.
include CMakeFiles/testimage.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/testimage.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/testimage.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testimage.dir/flags.make

CMakeFiles/testimage.dir/entry/testimage.cpp.o: CMakeFiles/testimage.dir/flags.make
CMakeFiles/testimage.dir/entry/testimage.cpp.o: ../entry/testimage.cpp
CMakeFiles/testimage.dir/entry/testimage.cpp.o: CMakeFiles/testimage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/cs225/CS-225/mp_stickers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testimage.dir/entry/testimage.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testimage.dir/entry/testimage.cpp.o -MF CMakeFiles/testimage.dir/entry/testimage.cpp.o.d -o CMakeFiles/testimage.dir/entry/testimage.cpp.o -c /workspaces/cs225/CS-225/mp_stickers/entry/testimage.cpp

CMakeFiles/testimage.dir/entry/testimage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testimage.dir/entry/testimage.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/cs225/CS-225/mp_stickers/entry/testimage.cpp > CMakeFiles/testimage.dir/entry/testimage.cpp.i

CMakeFiles/testimage.dir/entry/testimage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testimage.dir/entry/testimage.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/cs225/CS-225/mp_stickers/entry/testimage.cpp -o CMakeFiles/testimage.dir/entry/testimage.cpp.s

# Object files for target testimage
testimage_OBJECTS = \
"CMakeFiles/testimage.dir/entry/testimage.cpp.o"

# External object files for target testimage
testimage_EXTERNAL_OBJECTS =

testimage: CMakeFiles/testimage.dir/entry/testimage.cpp.o
testimage: CMakeFiles/testimage.dir/build.make
testimage: src/libsrc.a
testimage: lib/libcs225.a
testimage: lib/liblodepng.a
testimage: CMakeFiles/testimage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/cs225/CS-225/mp_stickers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testimage"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testimage.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testimage.dir/build: testimage
.PHONY : CMakeFiles/testimage.dir/build

CMakeFiles/testimage.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testimage.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testimage.dir/clean

CMakeFiles/testimage.dir/depend:
	cd /workspaces/cs225/CS-225/mp_stickers/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/cs225/CS-225/mp_stickers /workspaces/cs225/CS-225/mp_stickers /workspaces/cs225/CS-225/mp_stickers/build /workspaces/cs225/CS-225/mp_stickers/build /workspaces/cs225/CS-225/mp_stickers/build/CMakeFiles/testimage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testimage.dir/depend

