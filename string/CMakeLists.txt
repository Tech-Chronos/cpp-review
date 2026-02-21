cmake_minimum_required(VERSION 4.1)
project(string)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")

include_directories(.)

add_executable(string
        main.cpp
        mystring.h)
