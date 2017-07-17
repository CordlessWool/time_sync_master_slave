cmake_minimum_required(VERSION 3.5)
project(MasterSlaveTimesync)


set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_SYSTEM_PROCESSOR "i686")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32" CACHE STRING "c++ flags")
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -m32" CACHE STRING "c flags")


set(CMAKE_C_STANDARD 11)
find_package (Threads)
set(SOURCE_FILES main.c sock.c sock.h error.c error.h aids/str.c aids/str.h master/master.c master/master.h slave/slave.c slave/slave.h aids/calc.c aids/calc.h)
add_executable(MasterSlaveTimesync ${SOURCE_FILES})
set_target_properties(MasterSlaveTimesync PROPERTIES COMPILE_FLAGS "-m32" LINK_FLAGS "-m32")
target_link_libraries (MasterSlaveTimesync ${CMAKE_THREAD_LIBS_INIT})