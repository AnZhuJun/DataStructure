# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2020.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2020.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\CLion 2020.3\DataStructure\LInkedBinTree"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\CLion 2020.3\DataStructure\LInkedBinTree\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/LInkedBinTree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LInkedBinTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LInkedBinTree.dir/flags.make

CMakeFiles/LInkedBinTree.dir/main.c.obj: CMakeFiles/LInkedBinTree.dir/flags.make
CMakeFiles/LInkedBinTree.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\CLion 2020.3\DataStructure\LInkedBinTree\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/LInkedBinTree.dir/main.c.obj"
	D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\LInkedBinTree.dir\main.c.obj   -c "D:\CLion 2020.3\DataStructure\LInkedBinTree\main.c"

CMakeFiles/LInkedBinTree.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LInkedBinTree.dir/main.c.i"
	D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\CLion 2020.3\DataStructure\LInkedBinTree\main.c" > CMakeFiles\LInkedBinTree.dir\main.c.i

CMakeFiles/LInkedBinTree.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LInkedBinTree.dir/main.c.s"
	D:\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\CLion 2020.3\DataStructure\LInkedBinTree\main.c" -o CMakeFiles\LInkedBinTree.dir\main.c.s

# Object files for target LInkedBinTree
LInkedBinTree_OBJECTS = \
"CMakeFiles/LInkedBinTree.dir/main.c.obj"

# External object files for target LInkedBinTree
LInkedBinTree_EXTERNAL_OBJECTS =

LInkedBinTree.exe: CMakeFiles/LInkedBinTree.dir/main.c.obj
LInkedBinTree.exe: CMakeFiles/LInkedBinTree.dir/build.make
LInkedBinTree.exe: CMakeFiles/LInkedBinTree.dir/linklibs.rsp
LInkedBinTree.exe: CMakeFiles/LInkedBinTree.dir/objects1.rsp
LInkedBinTree.exe: CMakeFiles/LInkedBinTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\CLion 2020.3\DataStructure\LInkedBinTree\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable LInkedBinTree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\LInkedBinTree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LInkedBinTree.dir/build: LInkedBinTree.exe

.PHONY : CMakeFiles/LInkedBinTree.dir/build

CMakeFiles/LInkedBinTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\LInkedBinTree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/LInkedBinTree.dir/clean

CMakeFiles/LInkedBinTree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\CLion 2020.3\DataStructure\LInkedBinTree" "D:\CLion 2020.3\DataStructure\LInkedBinTree" "D:\CLion 2020.3\DataStructure\LInkedBinTree\cmake-build-debug" "D:\CLion 2020.3\DataStructure\LInkedBinTree\cmake-build-debug" "D:\CLion 2020.3\DataStructure\LInkedBinTree\cmake-build-debug\CMakeFiles\LInkedBinTree.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/LInkedBinTree.dir/depend

