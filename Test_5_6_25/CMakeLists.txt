cmake_minimum_required(VERSION 3.31)
project(Test_5_6_25)

set(CMAKE_CXX_STANDARD 11)

add_executable(Test_5_6_25 main.cpp
        cmake-build-debug/Stack.h
        stack.h)
