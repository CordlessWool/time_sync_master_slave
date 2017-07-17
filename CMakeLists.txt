cmake_minimum_required(VERSION 3.5)
project(MasterSlaveTimesync)


set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_VERSION 1)
#set(CMAKE_SYSTEM_PROCESSOR "i686")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32" CACHE STRING "c++ flags")
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -m32" CACHE STRING "c flags")



include (CheckSymbolExists)
include (CheckStructHasMember)

CHECK_SYMBOL_EXISTS(CPU_SET_ZERO sched.h CPU_SET_ZERO_exists)
CHECK_SYMBOL_EXISTS(sched_setaffinity sched.h sched_setaffinity_exists)
CHECK_STRUCT_HAS_MEMBER(cpu_set_t <member?> sched.h cpu_set_t_exists)


set(CMAKE_C_STANDARD 11)
find_package (Threads)
set(SOURCE_FILES main.c sock.c sock.h error.c error.h aids/str.c aids/str.h master/master.c master/master.h slave/slave.c slave/slave.h aids/calc.c aids/calc.h)
add_executable(MasterSlaveTimesync ${SOURCE_FILES})
set_target_properties(MasterSlaveTimesync PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
target_link_libraries (MasterSlaveTimesync ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries (MasterSlaveTimesync ${cm})