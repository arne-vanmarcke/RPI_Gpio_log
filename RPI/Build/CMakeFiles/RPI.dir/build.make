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
CMAKE_SOURCE_DIR = /home/pi/gpio_log/RPI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/gpio_log/RPI/Build

# Include any dependencies generated for this target.
include CMakeFiles/RPI.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RPI.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RPI.dir/flags.make

CMakeFiles/RPI.dir/RPI.c.o: CMakeFiles/RPI.dir/flags.make
CMakeFiles/RPI.dir/RPI.c.o: ../RPI.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/gpio_log/RPI/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/RPI.dir/RPI.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/RPI.dir/RPI.c.o   -c /home/pi/gpio_log/RPI/RPI.c

CMakeFiles/RPI.dir/RPI.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RPI.dir/RPI.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/gpio_log/RPI/RPI.c > CMakeFiles/RPI.dir/RPI.c.i

CMakeFiles/RPI.dir/RPI.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RPI.dir/RPI.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/gpio_log/RPI/RPI.c -o CMakeFiles/RPI.dir/RPI.c.s

# Object files for target RPI
RPI_OBJECTS = \
"CMakeFiles/RPI.dir/RPI.c.o"

# External object files for target RPI
RPI_EXTERNAL_OBJECTS =

libRPI.a: CMakeFiles/RPI.dir/RPI.c.o
libRPI.a: CMakeFiles/RPI.dir/build.make
libRPI.a: CMakeFiles/RPI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/gpio_log/RPI/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libRPI.a"
	$(CMAKE_COMMAND) -P CMakeFiles/RPI.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RPI.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RPI.dir/build: libRPI.a

.PHONY : CMakeFiles/RPI.dir/build

CMakeFiles/RPI.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RPI.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RPI.dir/clean

CMakeFiles/RPI.dir/depend:
	cd /home/pi/gpio_log/RPI/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/gpio_log/RPI /home/pi/gpio_log/RPI /home/pi/gpio_log/RPI/Build /home/pi/gpio_log/RPI/Build /home/pi/gpio_log/RPI/Build/CMakeFiles/RPI.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RPI.dir/depend

