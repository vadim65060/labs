# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\cSosi\Lab7.5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\cSosi\Lab7.5\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab7_5.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Lab7_5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab7_5.dir/flags.make

CMakeFiles/Lab7_5.dir/main.c.obj: CMakeFiles/Lab7_5.dir/flags.make
CMakeFiles/Lab7_5.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\cSosi\Lab7.5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Lab7_5.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Lab7_5.dir\main.c.obj -c C:\cSosi\Lab7.5\main.c

CMakeFiles/Lab7_5.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Lab7_5.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\cSosi\Lab7.5\main.c > CMakeFiles\Lab7_5.dir\main.c.i

CMakeFiles/Lab7_5.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Lab7_5.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\cSosi\Lab7.5\main.c -o CMakeFiles\Lab7_5.dir\main.c.s

# Object files for target Lab7_5
Lab7_5_OBJECTS = \
"CMakeFiles/Lab7_5.dir/main.c.obj"

# External object files for target Lab7_5
Lab7_5_EXTERNAL_OBJECTS =

Lab7_5.exe: CMakeFiles/Lab7_5.dir/main.c.obj
Lab7_5.exe: CMakeFiles/Lab7_5.dir/build.make
Lab7_5.exe: CMakeFiles/Lab7_5.dir/linklibs.rsp
Lab7_5.exe: CMakeFiles/Lab7_5.dir/objects1.rsp
Lab7_5.exe: CMakeFiles/Lab7_5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\cSosi\Lab7.5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Lab7_5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lab7_5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab7_5.dir/build: Lab7_5.exe
.PHONY : CMakeFiles/Lab7_5.dir/build

CMakeFiles/Lab7_5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lab7_5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lab7_5.dir/clean

CMakeFiles/Lab7_5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\cSosi\Lab7.5 C:\cSosi\Lab7.5 C:\cSosi\Lab7.5\cmake-build-debug C:\cSosi\Lab7.5\cmake-build-debug C:\cSosi\Lab7.5\cmake-build-debug\CMakeFiles\Lab7_5.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab7_5.dir/depend

