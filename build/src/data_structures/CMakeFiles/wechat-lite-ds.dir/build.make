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
CMAKE_SOURCE_DIR = /home/flareon/workshop/wechat-lite

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/flareon/workshop/wechat-lite/build

# Include any dependencies generated for this target.
include src/data_structures/CMakeFiles/wechat-lite-ds.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/data_structures/CMakeFiles/wechat-lite-ds.dir/compiler_depend.make

# Include the progress variables for this target.
include src/data_structures/CMakeFiles/wechat-lite-ds.dir/progress.make

# Include the compile flags for this target's objects.
include src/data_structures/CMakeFiles/wechat-lite-ds.dir/flags.make

src/data_structures/CMakeFiles/wechat-lite-ds.dir/list/c_list.c.o: src/data_structures/CMakeFiles/wechat-lite-ds.dir/flags.make
src/data_structures/CMakeFiles/wechat-lite-ds.dir/list/c_list.c.o: ../src/data_structures/list/c_list.c
src/data_structures/CMakeFiles/wechat-lite-ds.dir/list/c_list.c.o: src/data_structures/CMakeFiles/wechat-lite-ds.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/flareon/workshop/wechat-lite/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/data_structures/CMakeFiles/wechat-lite-ds.dir/list/c_list.c.o"
	cd /home/flareon/workshop/wechat-lite/build/src/data_structures && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/data_structures/CMakeFiles/wechat-lite-ds.dir/list/c_list.c.o -MF CMakeFiles/wechat-lite-ds.dir/list/c_list.c.o.d -o CMakeFiles/wechat-lite-ds.dir/list/c_list.c.o -c /home/flareon/workshop/wechat-lite/src/data_structures/list/c_list.c

src/data_structures/CMakeFiles/wechat-lite-ds.dir/list/c_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wechat-lite-ds.dir/list/c_list.c.i"
	cd /home/flareon/workshop/wechat-lite/build/src/data_structures && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/flareon/workshop/wechat-lite/src/data_structures/list/c_list.c > CMakeFiles/wechat-lite-ds.dir/list/c_list.c.i

src/data_structures/CMakeFiles/wechat-lite-ds.dir/list/c_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wechat-lite-ds.dir/list/c_list.c.s"
	cd /home/flareon/workshop/wechat-lite/build/src/data_structures && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/flareon/workshop/wechat-lite/src/data_structures/list/c_list.c -o CMakeFiles/wechat-lite-ds.dir/list/c_list.c.s

src/data_structures/CMakeFiles/wechat-lite-ds.dir/queue/c_queue.c.o: src/data_structures/CMakeFiles/wechat-lite-ds.dir/flags.make
src/data_structures/CMakeFiles/wechat-lite-ds.dir/queue/c_queue.c.o: ../src/data_structures/queue/c_queue.c
src/data_structures/CMakeFiles/wechat-lite-ds.dir/queue/c_queue.c.o: src/data_structures/CMakeFiles/wechat-lite-ds.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/flareon/workshop/wechat-lite/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/data_structures/CMakeFiles/wechat-lite-ds.dir/queue/c_queue.c.o"
	cd /home/flareon/workshop/wechat-lite/build/src/data_structures && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/data_structures/CMakeFiles/wechat-lite-ds.dir/queue/c_queue.c.o -MF CMakeFiles/wechat-lite-ds.dir/queue/c_queue.c.o.d -o CMakeFiles/wechat-lite-ds.dir/queue/c_queue.c.o -c /home/flareon/workshop/wechat-lite/src/data_structures/queue/c_queue.c

src/data_structures/CMakeFiles/wechat-lite-ds.dir/queue/c_queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wechat-lite-ds.dir/queue/c_queue.c.i"
	cd /home/flareon/workshop/wechat-lite/build/src/data_structures && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/flareon/workshop/wechat-lite/src/data_structures/queue/c_queue.c > CMakeFiles/wechat-lite-ds.dir/queue/c_queue.c.i

src/data_structures/CMakeFiles/wechat-lite-ds.dir/queue/c_queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wechat-lite-ds.dir/queue/c_queue.c.s"
	cd /home/flareon/workshop/wechat-lite/build/src/data_structures && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/flareon/workshop/wechat-lite/src/data_structures/queue/c_queue.c -o CMakeFiles/wechat-lite-ds.dir/queue/c_queue.c.s

src/data_structures/CMakeFiles/wechat-lite-ds.dir/stack/c_stack.c.o: src/data_structures/CMakeFiles/wechat-lite-ds.dir/flags.make
src/data_structures/CMakeFiles/wechat-lite-ds.dir/stack/c_stack.c.o: ../src/data_structures/stack/c_stack.c
src/data_structures/CMakeFiles/wechat-lite-ds.dir/stack/c_stack.c.o: src/data_structures/CMakeFiles/wechat-lite-ds.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/flareon/workshop/wechat-lite/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/data_structures/CMakeFiles/wechat-lite-ds.dir/stack/c_stack.c.o"
	cd /home/flareon/workshop/wechat-lite/build/src/data_structures && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/data_structures/CMakeFiles/wechat-lite-ds.dir/stack/c_stack.c.o -MF CMakeFiles/wechat-lite-ds.dir/stack/c_stack.c.o.d -o CMakeFiles/wechat-lite-ds.dir/stack/c_stack.c.o -c /home/flareon/workshop/wechat-lite/src/data_structures/stack/c_stack.c

src/data_structures/CMakeFiles/wechat-lite-ds.dir/stack/c_stack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wechat-lite-ds.dir/stack/c_stack.c.i"
	cd /home/flareon/workshop/wechat-lite/build/src/data_structures && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/flareon/workshop/wechat-lite/src/data_structures/stack/c_stack.c > CMakeFiles/wechat-lite-ds.dir/stack/c_stack.c.i

src/data_structures/CMakeFiles/wechat-lite-ds.dir/stack/c_stack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wechat-lite-ds.dir/stack/c_stack.c.s"
	cd /home/flareon/workshop/wechat-lite/build/src/data_structures && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/flareon/workshop/wechat-lite/src/data_structures/stack/c_stack.c -o CMakeFiles/wechat-lite-ds.dir/stack/c_stack.c.s

src/data_structures/CMakeFiles/wechat-lite-ds.dir/binary_tree/bt_node.c.o: src/data_structures/CMakeFiles/wechat-lite-ds.dir/flags.make
src/data_structures/CMakeFiles/wechat-lite-ds.dir/binary_tree/bt_node.c.o: ../src/data_structures/binary_tree/bt_node.c
src/data_structures/CMakeFiles/wechat-lite-ds.dir/binary_tree/bt_node.c.o: src/data_structures/CMakeFiles/wechat-lite-ds.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/flareon/workshop/wechat-lite/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/data_structures/CMakeFiles/wechat-lite-ds.dir/binary_tree/bt_node.c.o"
	cd /home/flareon/workshop/wechat-lite/build/src/data_structures && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/data_structures/CMakeFiles/wechat-lite-ds.dir/binary_tree/bt_node.c.o -MF CMakeFiles/wechat-lite-ds.dir/binary_tree/bt_node.c.o.d -o CMakeFiles/wechat-lite-ds.dir/binary_tree/bt_node.c.o -c /home/flareon/workshop/wechat-lite/src/data_structures/binary_tree/bt_node.c

src/data_structures/CMakeFiles/wechat-lite-ds.dir/binary_tree/bt_node.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wechat-lite-ds.dir/binary_tree/bt_node.c.i"
	cd /home/flareon/workshop/wechat-lite/build/src/data_structures && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/flareon/workshop/wechat-lite/src/data_structures/binary_tree/bt_node.c > CMakeFiles/wechat-lite-ds.dir/binary_tree/bt_node.c.i

src/data_structures/CMakeFiles/wechat-lite-ds.dir/binary_tree/bt_node.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wechat-lite-ds.dir/binary_tree/bt_node.c.s"
	cd /home/flareon/workshop/wechat-lite/build/src/data_structures && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/flareon/workshop/wechat-lite/src/data_structures/binary_tree/bt_node.c -o CMakeFiles/wechat-lite-ds.dir/binary_tree/bt_node.c.s

src/data_structures/CMakeFiles/wechat-lite-ds.dir/mem_pool/mempool.c.o: src/data_structures/CMakeFiles/wechat-lite-ds.dir/flags.make
src/data_structures/CMakeFiles/wechat-lite-ds.dir/mem_pool/mempool.c.o: ../src/data_structures/mem_pool/mempool.c
src/data_structures/CMakeFiles/wechat-lite-ds.dir/mem_pool/mempool.c.o: src/data_structures/CMakeFiles/wechat-lite-ds.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/flareon/workshop/wechat-lite/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/data_structures/CMakeFiles/wechat-lite-ds.dir/mem_pool/mempool.c.o"
	cd /home/flareon/workshop/wechat-lite/build/src/data_structures && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/data_structures/CMakeFiles/wechat-lite-ds.dir/mem_pool/mempool.c.o -MF CMakeFiles/wechat-lite-ds.dir/mem_pool/mempool.c.o.d -o CMakeFiles/wechat-lite-ds.dir/mem_pool/mempool.c.o -c /home/flareon/workshop/wechat-lite/src/data_structures/mem_pool/mempool.c

src/data_structures/CMakeFiles/wechat-lite-ds.dir/mem_pool/mempool.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wechat-lite-ds.dir/mem_pool/mempool.c.i"
	cd /home/flareon/workshop/wechat-lite/build/src/data_structures && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/flareon/workshop/wechat-lite/src/data_structures/mem_pool/mempool.c > CMakeFiles/wechat-lite-ds.dir/mem_pool/mempool.c.i

src/data_structures/CMakeFiles/wechat-lite-ds.dir/mem_pool/mempool.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wechat-lite-ds.dir/mem_pool/mempool.c.s"
	cd /home/flareon/workshop/wechat-lite/build/src/data_structures && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/flareon/workshop/wechat-lite/src/data_structures/mem_pool/mempool.c -o CMakeFiles/wechat-lite-ds.dir/mem_pool/mempool.c.s

# Object files for target wechat-lite-ds
wechat__lite__ds_OBJECTS = \
"CMakeFiles/wechat-lite-ds.dir/list/c_list.c.o" \
"CMakeFiles/wechat-lite-ds.dir/queue/c_queue.c.o" \
"CMakeFiles/wechat-lite-ds.dir/stack/c_stack.c.o" \
"CMakeFiles/wechat-lite-ds.dir/binary_tree/bt_node.c.o" \
"CMakeFiles/wechat-lite-ds.dir/mem_pool/mempool.c.o"

# External object files for target wechat-lite-ds
wechat__lite__ds_EXTERNAL_OBJECTS =

src/data_structures/libwechat-lite-ds.a: src/data_structures/CMakeFiles/wechat-lite-ds.dir/list/c_list.c.o
src/data_structures/libwechat-lite-ds.a: src/data_structures/CMakeFiles/wechat-lite-ds.dir/queue/c_queue.c.o
src/data_structures/libwechat-lite-ds.a: src/data_structures/CMakeFiles/wechat-lite-ds.dir/stack/c_stack.c.o
src/data_structures/libwechat-lite-ds.a: src/data_structures/CMakeFiles/wechat-lite-ds.dir/binary_tree/bt_node.c.o
src/data_structures/libwechat-lite-ds.a: src/data_structures/CMakeFiles/wechat-lite-ds.dir/mem_pool/mempool.c.o
src/data_structures/libwechat-lite-ds.a: src/data_structures/CMakeFiles/wechat-lite-ds.dir/build.make
src/data_structures/libwechat-lite-ds.a: src/data_structures/CMakeFiles/wechat-lite-ds.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/flareon/workshop/wechat-lite/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C static library libwechat-lite-ds.a"
	cd /home/flareon/workshop/wechat-lite/build/src/data_structures && $(CMAKE_COMMAND) -P CMakeFiles/wechat-lite-ds.dir/cmake_clean_target.cmake
	cd /home/flareon/workshop/wechat-lite/build/src/data_structures && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wechat-lite-ds.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/data_structures/CMakeFiles/wechat-lite-ds.dir/build: src/data_structures/libwechat-lite-ds.a
.PHONY : src/data_structures/CMakeFiles/wechat-lite-ds.dir/build

src/data_structures/CMakeFiles/wechat-lite-ds.dir/clean:
	cd /home/flareon/workshop/wechat-lite/build/src/data_structures && $(CMAKE_COMMAND) -P CMakeFiles/wechat-lite-ds.dir/cmake_clean.cmake
.PHONY : src/data_structures/CMakeFiles/wechat-lite-ds.dir/clean

src/data_structures/CMakeFiles/wechat-lite-ds.dir/depend:
	cd /home/flareon/workshop/wechat-lite/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/flareon/workshop/wechat-lite /home/flareon/workshop/wechat-lite/src/data_structures /home/flareon/workshop/wechat-lite/build /home/flareon/workshop/wechat-lite/build/src/data_structures /home/flareon/workshop/wechat-lite/build/src/data_structures/CMakeFiles/wechat-lite-ds.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/data_structures/CMakeFiles/wechat-lite-ds.dir/depend

