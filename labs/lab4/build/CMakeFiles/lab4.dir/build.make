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
CMAKE_SOURCE_DIR = /home/august/Documents/projects/progbase2/labs/lab4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/august/Documents/projects/progbase2/labs/lab4/build

# Include any dependencies generated for this target.
include CMakeFiles/lab4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab4.dir/flags.make

CMakeFiles/lab4.dir/main.c.o: CMakeFiles/lab4.dir/flags.make
CMakeFiles/lab4.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/august/Documents/projects/progbase2/labs/lab4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab4.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab4.dir/main.c.o   -c /home/august/Documents/projects/progbase2/labs/lab4/main.c

CMakeFiles/lab4.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab4.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/august/Documents/projects/progbase2/labs/lab4/main.c > CMakeFiles/lab4.dir/main.c.i

CMakeFiles/lab4.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab4.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/august/Documents/projects/progbase2/labs/lab4/main.c -o CMakeFiles/lab4.dir/main.c.s

CMakeFiles/lab4.dir/main.c.o.requires:

.PHONY : CMakeFiles/lab4.dir/main.c.o.requires

CMakeFiles/lab4.dir/main.c.o.provides: CMakeFiles/lab4.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/main.c.o.provides.build
.PHONY : CMakeFiles/lab4.dir/main.c.o.provides

CMakeFiles/lab4.dir/main.c.o.provides.build: CMakeFiles/lab4.dir/main.c.o


CMakeFiles/lab4.dir/src/CUI.c.o: CMakeFiles/lab4.dir/flags.make
CMakeFiles/lab4.dir/src/CUI.c.o: ../src/CUI.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/august/Documents/projects/progbase2/labs/lab4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lab4.dir/src/CUI.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab4.dir/src/CUI.c.o   -c /home/august/Documents/projects/progbase2/labs/lab4/src/CUI.c

CMakeFiles/lab4.dir/src/CUI.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab4.dir/src/CUI.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/august/Documents/projects/progbase2/labs/lab4/src/CUI.c > CMakeFiles/lab4.dir/src/CUI.c.i

CMakeFiles/lab4.dir/src/CUI.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab4.dir/src/CUI.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/august/Documents/projects/progbase2/labs/lab4/src/CUI.c -o CMakeFiles/lab4.dir/src/CUI.c.s

CMakeFiles/lab4.dir/src/CUI.c.o.requires:

.PHONY : CMakeFiles/lab4.dir/src/CUI.c.o.requires

CMakeFiles/lab4.dir/src/CUI.c.o.provides: CMakeFiles/lab4.dir/src/CUI.c.o.requires
	$(MAKE) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/src/CUI.c.o.provides.build
.PHONY : CMakeFiles/lab4.dir/src/CUI.c.o.provides

CMakeFiles/lab4.dir/src/CUI.c.o.provides.build: CMakeFiles/lab4.dir/src/CUI.c.o


CMakeFiles/lab4.dir/src/list.c.o: CMakeFiles/lab4.dir/flags.make
CMakeFiles/lab4.dir/src/list.c.o: ../src/list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/august/Documents/projects/progbase2/labs/lab4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/lab4.dir/src/list.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab4.dir/src/list.c.o   -c /home/august/Documents/projects/progbase2/labs/lab4/src/list.c

CMakeFiles/lab4.dir/src/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab4.dir/src/list.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/august/Documents/projects/progbase2/labs/lab4/src/list.c > CMakeFiles/lab4.dir/src/list.c.i

CMakeFiles/lab4.dir/src/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab4.dir/src/list.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/august/Documents/projects/progbase2/labs/lab4/src/list.c -o CMakeFiles/lab4.dir/src/list.c.s

CMakeFiles/lab4.dir/src/list.c.o.requires:

.PHONY : CMakeFiles/lab4.dir/src/list.c.o.requires

CMakeFiles/lab4.dir/src/list.c.o.provides: CMakeFiles/lab4.dir/src/list.c.o.requires
	$(MAKE) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/src/list.c.o.provides.build
.PHONY : CMakeFiles/lab4.dir/src/list.c.o.provides

CMakeFiles/lab4.dir/src/list.c.o.provides.build: CMakeFiles/lab4.dir/src/list.c.o


CMakeFiles/lab4.dir/src/lectureCourse.c.o: CMakeFiles/lab4.dir/flags.make
CMakeFiles/lab4.dir/src/lectureCourse.c.o: ../src/lectureCourse.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/august/Documents/projects/progbase2/labs/lab4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/lab4.dir/src/lectureCourse.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab4.dir/src/lectureCourse.c.o   -c /home/august/Documents/projects/progbase2/labs/lab4/src/lectureCourse.c

CMakeFiles/lab4.dir/src/lectureCourse.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab4.dir/src/lectureCourse.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/august/Documents/projects/progbase2/labs/lab4/src/lectureCourse.c > CMakeFiles/lab4.dir/src/lectureCourse.c.i

CMakeFiles/lab4.dir/src/lectureCourse.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab4.dir/src/lectureCourse.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/august/Documents/projects/progbase2/labs/lab4/src/lectureCourse.c -o CMakeFiles/lab4.dir/src/lectureCourse.c.s

CMakeFiles/lab4.dir/src/lectureCourse.c.o.requires:

.PHONY : CMakeFiles/lab4.dir/src/lectureCourse.c.o.requires

CMakeFiles/lab4.dir/src/lectureCourse.c.o.provides: CMakeFiles/lab4.dir/src/lectureCourse.c.o.requires
	$(MAKE) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/src/lectureCourse.c.o.provides.build
.PHONY : CMakeFiles/lab4.dir/src/lectureCourse.c.o.provides

CMakeFiles/lab4.dir/src/lectureCourse.c.o.provides.build: CMakeFiles/lab4.dir/src/lectureCourse.c.o


CMakeFiles/lab4.dir/src/convert.c.o: CMakeFiles/lab4.dir/flags.make
CMakeFiles/lab4.dir/src/convert.c.o: ../src/convert.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/august/Documents/projects/progbase2/labs/lab4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/lab4.dir/src/convert.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab4.dir/src/convert.c.o   -c /home/august/Documents/projects/progbase2/labs/lab4/src/convert.c

CMakeFiles/lab4.dir/src/convert.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab4.dir/src/convert.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/august/Documents/projects/progbase2/labs/lab4/src/convert.c > CMakeFiles/lab4.dir/src/convert.c.i

CMakeFiles/lab4.dir/src/convert.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab4.dir/src/convert.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/august/Documents/projects/progbase2/labs/lab4/src/convert.c -o CMakeFiles/lab4.dir/src/convert.c.s

CMakeFiles/lab4.dir/src/convert.c.o.requires:

.PHONY : CMakeFiles/lab4.dir/src/convert.c.o.requires

CMakeFiles/lab4.dir/src/convert.c.o.provides: CMakeFiles/lab4.dir/src/convert.c.o.requires
	$(MAKE) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/src/convert.c.o.provides.build
.PHONY : CMakeFiles/lab4.dir/src/convert.c.o.provides

CMakeFiles/lab4.dir/src/convert.c.o.provides.build: CMakeFiles/lab4.dir/src/convert.c.o


CMakeFiles/lab4.dir/src/storage.c.o: CMakeFiles/lab4.dir/flags.make
CMakeFiles/lab4.dir/src/storage.c.o: ../src/storage.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/august/Documents/projects/progbase2/labs/lab4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/lab4.dir/src/storage.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab4.dir/src/storage.c.o   -c /home/august/Documents/projects/progbase2/labs/lab4/src/storage.c

CMakeFiles/lab4.dir/src/storage.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab4.dir/src/storage.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/august/Documents/projects/progbase2/labs/lab4/src/storage.c > CMakeFiles/lab4.dir/src/storage.c.i

CMakeFiles/lab4.dir/src/storage.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab4.dir/src/storage.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/august/Documents/projects/progbase2/labs/lab4/src/storage.c -o CMakeFiles/lab4.dir/src/storage.c.s

CMakeFiles/lab4.dir/src/storage.c.o.requires:

.PHONY : CMakeFiles/lab4.dir/src/storage.c.o.requires

CMakeFiles/lab4.dir/src/storage.c.o.provides: CMakeFiles/lab4.dir/src/storage.c.o.requires
	$(MAKE) -f CMakeFiles/lab4.dir/build.make CMakeFiles/lab4.dir/src/storage.c.o.provides.build
.PHONY : CMakeFiles/lab4.dir/src/storage.c.o.provides

CMakeFiles/lab4.dir/src/storage.c.o.provides.build: CMakeFiles/lab4.dir/src/storage.c.o


# Object files for target lab4
lab4_OBJECTS = \
"CMakeFiles/lab4.dir/main.c.o" \
"CMakeFiles/lab4.dir/src/CUI.c.o" \
"CMakeFiles/lab4.dir/src/list.c.o" \
"CMakeFiles/lab4.dir/src/lectureCourse.c.o" \
"CMakeFiles/lab4.dir/src/convert.c.o" \
"CMakeFiles/lab4.dir/src/storage.c.o"

# External object files for target lab4
lab4_EXTERNAL_OBJECTS =

lab4: CMakeFiles/lab4.dir/main.c.o
lab4: CMakeFiles/lab4.dir/src/CUI.c.o
lab4: CMakeFiles/lab4.dir/src/list.c.o
lab4: CMakeFiles/lab4.dir/src/lectureCourse.c.o
lab4: CMakeFiles/lab4.dir/src/convert.c.o
lab4: CMakeFiles/lab4.dir/src/storage.c.o
lab4: CMakeFiles/lab4.dir/build.make
lab4: CMakeFiles/lab4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/august/Documents/projects/progbase2/labs/lab4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable lab4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab4.dir/build: lab4

.PHONY : CMakeFiles/lab4.dir/build

CMakeFiles/lab4.dir/requires: CMakeFiles/lab4.dir/main.c.o.requires
CMakeFiles/lab4.dir/requires: CMakeFiles/lab4.dir/src/CUI.c.o.requires
CMakeFiles/lab4.dir/requires: CMakeFiles/lab4.dir/src/list.c.o.requires
CMakeFiles/lab4.dir/requires: CMakeFiles/lab4.dir/src/lectureCourse.c.o.requires
CMakeFiles/lab4.dir/requires: CMakeFiles/lab4.dir/src/convert.c.o.requires
CMakeFiles/lab4.dir/requires: CMakeFiles/lab4.dir/src/storage.c.o.requires

.PHONY : CMakeFiles/lab4.dir/requires

CMakeFiles/lab4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab4.dir/clean

CMakeFiles/lab4.dir/depend:
	cd /home/august/Documents/projects/progbase2/labs/lab4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/august/Documents/projects/progbase2/labs/lab4 /home/august/Documents/projects/progbase2/labs/lab4 /home/august/Documents/projects/progbase2/labs/lab4/build /home/august/Documents/projects/progbase2/labs/lab4/build /home/august/Documents/projects/progbase2/labs/lab4/build/CMakeFiles/lab4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab4.dir/depend

