cmake_minimum_required(VERSION 3.31)
project(smart_ptr)

set(CMAKE_CXX_STANDARD 20)

add_executable(smart_ptr main.cpp
        shared_ptr.h)
