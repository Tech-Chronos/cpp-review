cmake_minimum_required(VERSION 3.31)
project(Test_10_20_smartptr)

set(CMAKE_CXX_STANDARD 20)

add_executable(Test_10_20_smartptr main.cpp
        my_shared_ptr.h)
