//
// Created by 有趣的中国人 on 2025/5/11.
//
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#ifndef TEST_5_10_STRING_H
#define TEST_5_10_STRING_H
using namespace  std;

class mystring
{
public:
//    string()
//        :_str(nullptr),
//        _size(0),
//        _capacity(0)
//    {}
    mystring(const char * str = " ")
        :_size(strlen(str))
    {
        _capacity = _size;
        _str = new char(_capacity + 1);
    }
private:
    char* _str;
    size_t _size;
    size_t _capacity;
};














#endif //TEST_5_10_STRING_H
