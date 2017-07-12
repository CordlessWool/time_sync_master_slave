cmake_minimum_required(VERSION 3.7)
project(MasterSlaveTimesync)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c sock.c sock.h error.c error.h str.c str.h master/master.c master/master.h)
add_executable(MasterSlaveTimesync ${SOURCE_FILES})