# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /opt/clion-2017.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2017.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wolle/Workspace/c/MasterSlaveTimesync

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wolle/Workspace/c/MasterSlaveTimesync/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MasterSlaveTimesync.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MasterSlaveTimesync.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MasterSlaveTimesync.dir/flags.make

CMakeFiles/MasterSlaveTimesync.dir/main.c.o: CMakeFiles/MasterSlaveTimesync.dir/flags.make
CMakeFiles/MasterSlaveTimesync.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wolle/Workspace/c/MasterSlaveTimesync/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/MasterSlaveTimesync.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MasterSlaveTimesync.dir/main.c.o   -c /home/wolle/Workspace/c/MasterSlaveTimesync/main.c

CMakeFiles/MasterSlaveTimesync.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MasterSlaveTimesync.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wolle/Workspace/c/MasterSlaveTimesync/main.c > CMakeFiles/MasterSlaveTimesync.dir/main.c.i

CMakeFiles/MasterSlaveTimesync.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MasterSlaveTimesync.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wolle/Workspace/c/MasterSlaveTimesync/main.c -o CMakeFiles/MasterSlaveTimesync.dir/main.c.s

CMakeFiles/MasterSlaveTimesync.dir/main.c.o.requires:

.PHONY : CMakeFiles/MasterSlaveTimesync.dir/main.c.o.requires

CMakeFiles/MasterSlaveTimesync.dir/main.c.o.provides: CMakeFiles/MasterSlaveTimesync.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/MasterSlaveTimesync.dir/build.make CMakeFiles/MasterSlaveTimesync.dir/main.c.o.provides.build
.PHONY : CMakeFiles/MasterSlaveTimesync.dir/main.c.o.provides

CMakeFiles/MasterSlaveTimesync.dir/main.c.o.provides.build: CMakeFiles/MasterSlaveTimesync.dir/main.c.o


CMakeFiles/MasterSlaveTimesync.dir/sock.c.o: CMakeFiles/MasterSlaveTimesync.dir/flags.make
CMakeFiles/MasterSlaveTimesync.dir/sock.c.o: ../sock.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wolle/Workspace/c/MasterSlaveTimesync/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/MasterSlaveTimesync.dir/sock.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MasterSlaveTimesync.dir/sock.c.o   -c /home/wolle/Workspace/c/MasterSlaveTimesync/sock.c

CMakeFiles/MasterSlaveTimesync.dir/sock.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MasterSlaveTimesync.dir/sock.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wolle/Workspace/c/MasterSlaveTimesync/sock.c > CMakeFiles/MasterSlaveTimesync.dir/sock.c.i

CMakeFiles/MasterSlaveTimesync.dir/sock.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MasterSlaveTimesync.dir/sock.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wolle/Workspace/c/MasterSlaveTimesync/sock.c -o CMakeFiles/MasterSlaveTimesync.dir/sock.c.s

CMakeFiles/MasterSlaveTimesync.dir/sock.c.o.requires:

.PHONY : CMakeFiles/MasterSlaveTimesync.dir/sock.c.o.requires

CMakeFiles/MasterSlaveTimesync.dir/sock.c.o.provides: CMakeFiles/MasterSlaveTimesync.dir/sock.c.o.requires
	$(MAKE) -f CMakeFiles/MasterSlaveTimesync.dir/build.make CMakeFiles/MasterSlaveTimesync.dir/sock.c.o.provides.build
.PHONY : CMakeFiles/MasterSlaveTimesync.dir/sock.c.o.provides

CMakeFiles/MasterSlaveTimesync.dir/sock.c.o.provides.build: CMakeFiles/MasterSlaveTimesync.dir/sock.c.o


CMakeFiles/MasterSlaveTimesync.dir/error.c.o: CMakeFiles/MasterSlaveTimesync.dir/flags.make
CMakeFiles/MasterSlaveTimesync.dir/error.c.o: ../error.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wolle/Workspace/c/MasterSlaveTimesync/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/MasterSlaveTimesync.dir/error.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MasterSlaveTimesync.dir/error.c.o   -c /home/wolle/Workspace/c/MasterSlaveTimesync/error.c

CMakeFiles/MasterSlaveTimesync.dir/error.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MasterSlaveTimesync.dir/error.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wolle/Workspace/c/MasterSlaveTimesync/error.c > CMakeFiles/MasterSlaveTimesync.dir/error.c.i

CMakeFiles/MasterSlaveTimesync.dir/error.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MasterSlaveTimesync.dir/error.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wolle/Workspace/c/MasterSlaveTimesync/error.c -o CMakeFiles/MasterSlaveTimesync.dir/error.c.s

CMakeFiles/MasterSlaveTimesync.dir/error.c.o.requires:

.PHONY : CMakeFiles/MasterSlaveTimesync.dir/error.c.o.requires

CMakeFiles/MasterSlaveTimesync.dir/error.c.o.provides: CMakeFiles/MasterSlaveTimesync.dir/error.c.o.requires
	$(MAKE) -f CMakeFiles/MasterSlaveTimesync.dir/build.make CMakeFiles/MasterSlaveTimesync.dir/error.c.o.provides.build
.PHONY : CMakeFiles/MasterSlaveTimesync.dir/error.c.o.provides

CMakeFiles/MasterSlaveTimesync.dir/error.c.o.provides.build: CMakeFiles/MasterSlaveTimesync.dir/error.c.o


CMakeFiles/MasterSlaveTimesync.dir/str.c.o: CMakeFiles/MasterSlaveTimesync.dir/flags.make
CMakeFiles/MasterSlaveTimesync.dir/str.c.o: ../str.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wolle/Workspace/c/MasterSlaveTimesync/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/MasterSlaveTimesync.dir/str.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MasterSlaveTimesync.dir/str.c.o   -c /home/wolle/Workspace/c/MasterSlaveTimesync/str.c

CMakeFiles/MasterSlaveTimesync.dir/str.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MasterSlaveTimesync.dir/str.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wolle/Workspace/c/MasterSlaveTimesync/str.c > CMakeFiles/MasterSlaveTimesync.dir/str.c.i

CMakeFiles/MasterSlaveTimesync.dir/str.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MasterSlaveTimesync.dir/str.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wolle/Workspace/c/MasterSlaveTimesync/str.c -o CMakeFiles/MasterSlaveTimesync.dir/str.c.s

CMakeFiles/MasterSlaveTimesync.dir/str.c.o.requires:

.PHONY : CMakeFiles/MasterSlaveTimesync.dir/str.c.o.requires

CMakeFiles/MasterSlaveTimesync.dir/str.c.o.provides: CMakeFiles/MasterSlaveTimesync.dir/str.c.o.requires
	$(MAKE) -f CMakeFiles/MasterSlaveTimesync.dir/build.make CMakeFiles/MasterSlaveTimesync.dir/str.c.o.provides.build
.PHONY : CMakeFiles/MasterSlaveTimesync.dir/str.c.o.provides

CMakeFiles/MasterSlaveTimesync.dir/str.c.o.provides.build: CMakeFiles/MasterSlaveTimesync.dir/str.c.o


CMakeFiles/MasterSlaveTimesync.dir/master/master.c.o: CMakeFiles/MasterSlaveTimesync.dir/flags.make
CMakeFiles/MasterSlaveTimesync.dir/master/master.c.o: ../master/master.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wolle/Workspace/c/MasterSlaveTimesync/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/MasterSlaveTimesync.dir/master/master.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/MasterSlaveTimesync.dir/master/master.c.o   -c /home/wolle/Workspace/c/MasterSlaveTimesync/master/master.c

CMakeFiles/MasterSlaveTimesync.dir/master/master.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MasterSlaveTimesync.dir/master/master.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wolle/Workspace/c/MasterSlaveTimesync/master/master.c > CMakeFiles/MasterSlaveTimesync.dir/master/master.c.i

CMakeFiles/MasterSlaveTimesync.dir/master/master.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MasterSlaveTimesync.dir/master/master.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wolle/Workspace/c/MasterSlaveTimesync/master/master.c -o CMakeFiles/MasterSlaveTimesync.dir/master/master.c.s

CMakeFiles/MasterSlaveTimesync.dir/master/master.c.o.requires:

.PHONY : CMakeFiles/MasterSlaveTimesync.dir/master/master.c.o.requires

CMakeFiles/MasterSlaveTimesync.dir/master/master.c.o.provides: CMakeFiles/MasterSlaveTimesync.dir/master/master.c.o.requires
	$(MAKE) -f CMakeFiles/MasterSlaveTimesync.dir/build.make CMakeFiles/MasterSlaveTimesync.dir/master/master.c.o.provides.build
.PHONY : CMakeFiles/MasterSlaveTimesync.dir/master/master.c.o.provides

CMakeFiles/MasterSlaveTimesync.dir/master/master.c.o.provides.build: CMakeFiles/MasterSlaveTimesync.dir/master/master.c.o


# Object files for target MasterSlaveTimesync
MasterSlaveTimesync_OBJECTS = \
"CMakeFiles/MasterSlaveTimesync.dir/main.c.o" \
"CMakeFiles/MasterSlaveTimesync.dir/sock.c.o" \
"CMakeFiles/MasterSlaveTimesync.dir/error.c.o" \
"CMakeFiles/MasterSlaveTimesync.dir/str.c.o" \
"CMakeFiles/MasterSlaveTimesync.dir/master/master.c.o"

# External object files for target MasterSlaveTimesync
MasterSlaveTimesync_EXTERNAL_OBJECTS =

MasterSlaveTimesync: CMakeFiles/MasterSlaveTimesync.dir/main.c.o
MasterSlaveTimesync: CMakeFiles/MasterSlaveTimesync.dir/sock.c.o
MasterSlaveTimesync: CMakeFiles/MasterSlaveTimesync.dir/error.c.o
MasterSlaveTimesync: CMakeFiles/MasterSlaveTimesync.dir/str.c.o
MasterSlaveTimesync: CMakeFiles/MasterSlaveTimesync.dir/master/master.c.o
MasterSlaveTimesync: CMakeFiles/MasterSlaveTimesync.dir/build.make
MasterSlaveTimesync: CMakeFiles/MasterSlaveTimesync.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wolle/Workspace/c/MasterSlaveTimesync/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable MasterSlaveTimesync"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MasterSlaveTimesync.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MasterSlaveTimesync.dir/build: MasterSlaveTimesync

.PHONY : CMakeFiles/MasterSlaveTimesync.dir/build

CMakeFiles/MasterSlaveTimesync.dir/requires: CMakeFiles/MasterSlaveTimesync.dir/main.c.o.requires
CMakeFiles/MasterSlaveTimesync.dir/requires: CMakeFiles/MasterSlaveTimesync.dir/sock.c.o.requires
CMakeFiles/MasterSlaveTimesync.dir/requires: CMakeFiles/MasterSlaveTimesync.dir/error.c.o.requires
CMakeFiles/MasterSlaveTimesync.dir/requires: CMakeFiles/MasterSlaveTimesync.dir/str.c.o.requires
CMakeFiles/MasterSlaveTimesync.dir/requires: CMakeFiles/MasterSlaveTimesync.dir/master/master.c.o.requires

.PHONY : CMakeFiles/MasterSlaveTimesync.dir/requires

CMakeFiles/MasterSlaveTimesync.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MasterSlaveTimesync.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MasterSlaveTimesync.dir/clean

CMakeFiles/MasterSlaveTimesync.dir/depend:
	cd /home/wolle/Workspace/c/MasterSlaveTimesync/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wolle/Workspace/c/MasterSlaveTimesync /home/wolle/Workspace/c/MasterSlaveTimesync /home/wolle/Workspace/c/MasterSlaveTimesync/cmake-build-debug /home/wolle/Workspace/c/MasterSlaveTimesync/cmake-build-debug /home/wolle/Workspace/c/MasterSlaveTimesync/cmake-build-debug/CMakeFiles/MasterSlaveTimesync.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MasterSlaveTimesync.dir/depend

