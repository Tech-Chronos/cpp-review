cmake_minimum_required(VERSION 3.31)
project(test_odr)

set(CMAKE_CXX_STANDARD 20)

add_executable(test_odr main.cpp
        util.h
        other.cpp)
