# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/august/Documents/projects/progbase2/labs/lab5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/august/Documents/projects/progbase2/labs/lab5/build

# Include any dependencies generated for this target.
include CMakeFiles/mylab5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mylab5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mylab5.dir/flags.make

CMakeFiles/mylab5.dir/src/CUI.c.o: CMakeFiles/mylab5.dir/flags.make
CMakeFiles/mylab5.dir/src/CUI.c.o: ../src/CUI.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/august/Documents/projects/progbase2/labs/lab5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/mylab5.dir/src/CUI.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mylab5.dir/src/CUI.c.o   -c /home/august/Documents/projects/progbase2/labs/lab5/src/CUI.c

CMakeFiles/mylab5.dir/src/CUI.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mylab5.dir/src/CUI.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/august/Documents/projects/progbase2/labs/lab5/src/CUI.c > CMakeFiles/mylab5.dir/src/CUI.c.i

CMakeFiles/mylab5.dir/src/CUI.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mylab5.dir/src/CUI.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/august/Documents/projects/progbase2/labs/lab5/src/CUI.c -o CMakeFiles/mylab5.dir/src/CUI.c.s

CMakeFiles/mylab5.dir/src/CUI.c.o.requires:

.PHONY : CMakeFiles/mylab5.dir/src/CUI.c.o.requires

CMakeFiles/mylab5.dir/src/CUI.c.o.provides: CMakeFiles/mylab5.dir/src/CUI.c.o.requires
	$(MAKE) -f CMakeFiles/mylab5.dir/build.make CMakeFiles/mylab5.dir/src/CUI.c.o.provides.build
.PHONY : CMakeFiles/mylab5.dir/src/CUI.c.o.provides

CMakeFiles/mylab5.dir/src/CUI.c.o.provides.build: CMakeFiles/mylab5.dir/src/CUI.c.o


CMakeFiles/mylab5.dir/src/list.c.o: CMakeFiles/mylab5.dir/flags.make
CMakeFiles/mylab5.dir/src/list.c.o: ../src/list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/august/Documents/projects/progbase2/labs/lab5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/mylab5.dir/src/list.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mylab5.dir/src/list.c.o   -c /home/august/Documents/projects/progbase2/labs/lab5/src/list.c

CMakeFiles/mylab5.dir/src/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mylab5.dir/src/list.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/august/Documents/projects/progbase2/labs/lab5/src/list.c > CMakeFiles/mylab5.dir/src/list.c.i

CMakeFiles/mylab5.dir/src/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mylab5.dir/src/list.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/august/Documents/projects/progbase2/labs/lab5/src/list.c -o CMakeFiles/mylab5.dir/src/list.c.s

CMakeFiles/mylab5.dir/src/list.c.o.requires:

.PHONY : CMakeFiles/mylab5.dir/src/list.c.o.requires

CMakeFiles/mylab5.dir/src/list.c.o.provides: CMakeFiles/mylab5.dir/src/list.c.o.requires
	$(MAKE) -f CMakeFiles/mylab5.dir/build.make CMakeFiles/mylab5.dir/src/list.c.o.provides.build
.PHONY : CMakeFiles/mylab5.dir/src/list.c.o.provides

CMakeFiles/mylab5.dir/src/list.c.o.provides.build: CMakeFiles/mylab5.dir/src/list.c.o


CMakeFiles/mylab5.dir/src/lectureCourse.c.o: CMakeFiles/mylab5.dir/flags.make
CMakeFiles/mylab5.dir/src/lectureCourse.c.o: ../src/lectureCourse.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/august/Documents/projects/progbase2/labs/lab5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/mylab5.dir/src/lectureCourse.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mylab5.dir/src/lectureCourse.c.o   -c /home/august/Documents/projects/progbase2/labs/lab5/src/lectureCourse.c

CMakeFiles/mylab5.dir/src/lectureCourse.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mylab5.dir/src/lectureCourse.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/august/Documents/projects/progbase2/labs/lab5/src/lectureCourse.c > CMakeFiles/mylab5.dir/src/lectureCourse.c.i

CMakeFiles/mylab5.dir/src/lectureCourse.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mylab5.dir/src/lectureCourse.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/august/Documents/projects/progbase2/labs/lab5/src/lectureCourse.c -o CMakeFiles/mylab5.dir/src/lectureCourse.c.s

CMakeFiles/mylab5.dir/src/lectureCourse.c.o.requires:

.PHONY : CMakeFiles/mylab5.dir/src/lectureCourse.c.o.requires

CMakeFiles/mylab5.dir/src/lectureCourse.c.o.provides: CMakeFiles/mylab5.dir/src/lectureCourse.c.o.requires
	$(MAKE) -f CMakeFiles/mylab5.dir/build.make CMakeFiles/mylab5.dir/src/lectureCourse.c.o.provides.build
.PHONY : CMakeFiles/mylab5.dir/src/lectureCourse.c.o.provides

CMakeFiles/mylab5.dir/src/lectureCourse.c.o.provides.build: CMakeFiles/mylab5.dir/src/lectureCourse.c.o


CMakeFiles/mylab5.dir/src/convert.c.o: CMakeFiles/mylab5.dir/flags.make
CMakeFiles/mylab5.dir/src/convert.c.o: ../src/convert.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/august/Documents/projects/progbase2/labs/lab5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/mylab5.dir/src/convert.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mylab5.dir/src/convert.c.o   -c /home/august/Documents/projects/progbase2/labs/lab5/src/convert.c

CMakeFiles/mylab5.dir/src/convert.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mylab5.dir/src/convert.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/august/Documents/projects/progbase2/labs/lab5/src/convert.c > CMakeFiles/mylab5.dir/src/convert.c.i

CMakeFiles/mylab5.dir/src/convert.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mylab5.dir/src/convert.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/august/Documents/projects/progbase2/labs/lab5/src/convert.c -o CMakeFiles/mylab5.dir/src/convert.c.s

CMakeFiles/mylab5.dir/src/convert.c.o.requires:

.PHONY : CMakeFiles/mylab5.dir/src/convert.c.o.requires

CMakeFiles/mylab5.dir/src/convert.c.o.provides: CMakeFiles/mylab5.dir/src/convert.c.o.requires
	$(MAKE) -f CMakeFiles/mylab5.dir/build.make CMakeFiles/mylab5.dir/src/convert.c.o.provides.build
.PHONY : CMakeFiles/mylab5.dir/src/convert.c.o.provides

CMakeFiles/mylab5.dir/src/convert.c.o.provides.build: CMakeFiles/mylab5.dir/src/convert.c.o


CMakeFiles/mylab5.dir/src/storage.c.o: CMakeFiles/mylab5.dir/flags.make
CMakeFiles/mylab5.dir/src/storage.c.o: ../src/storage.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/august/Documents/projects/progbase2/labs/lab5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/mylab5.dir/src/storage.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mylab5.dir/src/storage.c.o   -c /home/august/Documents/projects/progbase2/labs/lab5/src/storage.c

CMakeFiles/mylab5.dir/src/storage.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mylab5.dir/src/storage.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/august/Documents/projects/progbase2/labs/lab5/src/storage.c > CMakeFiles/mylab5.dir/src/storage.c.i

CMakeFiles/mylab5.dir/src/storage.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mylab5.dir/src/storage.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/august/Documents/projects/progbase2/labs/lab5/src/storage.c -o CMakeFiles/mylab5.dir/src/storage.c.s

CMakeFiles/mylab5.dir/src/storage.c.o.requires:

.PHONY : CMakeFiles/mylab5.dir/src/storage.c.o.requires

CMakeFiles/mylab5.dir/src/storage.c.o.provides: CMakeFiles/mylab5.dir/src/storage.c.o.requires
	$(MAKE) -f CMakeFiles/mylab5.dir/build.make CMakeFiles/mylab5.dir/src/storage.c.o.provides.build
.PHONY : CMakeFiles/mylab5.dir/src/storage.c.o.provides

CMakeFiles/mylab5.dir/src/storage.c.o.provides.build: CMakeFiles/mylab5.dir/src/storage.c.o


# Object files for target mylab5
mylab5_OBJECTS = \
"CMakeFiles/mylab5.dir/src/CUI.c.o" \
"CMakeFiles/mylab5.dir/src/list.c.o" \
"CMakeFiles/mylab5.dir/src/lectureCourse.c.o" \
"CMakeFiles/mylab5.dir/src/convert.c.o" \
"CMakeFiles/mylab5.dir/src/storage.c.o"

# External object files for target mylab5
mylab5_EXTERNAL_OBJECTS =

libmylab5.a: CMakeFiles/mylab5.dir/src/CUI.c.o
libmylab5.a: CMakeFiles/mylab5.dir/src/list.c.o
libmylab5.a: CMakeFiles/mylab5.dir/src/lectureCourse.c.o
libmylab5.a: CMakeFiles/mylab5.dir/src/convert.c.o
libmylab5.a: CMakeFiles/mylab5.dir/src/storage.c.o
libmylab5.a: CMakeFiles/mylab5.dir/build.make
libmylab5.a: CMakeFiles/mylab5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/august/Documents/projects/progbase2/labs/lab5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C static library libmylab5.a"
	$(CMAKE_COMMAND) -P CMakeFiles/mylab5.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mylab5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mylab5.dir/build: libmylab5.a

.PHONY : CMakeFiles/mylab5.dir/build

CMakeFiles/mylab5.dir/requires: CMakeFiles/mylab5.dir/src/CUI.c.o.requires
CMakeFiles/mylab5.dir/requires: CMakeFiles/mylab5.dir/src/list.c.o.requires
CMakeFiles/mylab5.dir/requires: CMakeFiles/mylab5.dir/src/lectureCourse.c.o.requires
CMakeFiles/mylab5.dir/requires: CMakeFiles/mylab5.dir/src/convert.c.o.requires
CMakeFiles/mylab5.dir/requires: CMakeFiles/mylab5.dir/src/storage.c.o.requires

.PHONY : CMakeFiles/mylab5.dir/requires

CMakeFiles/mylab5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mylab5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mylab5.dir/clean

CMakeFiles/mylab5.dir/depend:
	cd /home/august/Documents/projects/progbase2/labs/lab5/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/august/Documents/projects/progbase2/labs/lab5 /home/august/Documents/projects/progbase2/labs/lab5 /home/august/Documents/projects/progbase2/labs/lab5/build /home/august/Documents/projects/progbase2/labs/lab5/build /home/august/Documents/projects/progbase2/labs/lab5/build/CMakeFiles/mylab5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mylab5.dir/depend

