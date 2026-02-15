cmake_minimum_required(VERSION 4.1)
project(string)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(string
        main.cpp
        mystring.h)
