//
// Created by 有趣的中国人 on 2025/5/11.
//
#include <iostream>
#include <cstring>
#ifndef TEST_5_11_25_STRING_H
#define TEST_5_11_25_STRING_H
using namespace std;
class mystring
{
public:
    mystring(const char* str = "")
        :_size(strlen(str))
    {
        _str = new char[_size + 1];
        _capacity = _size;
        strcpy(_str, str);
    }

private:
    char* _str;
    size_t _size;
    size_t _capacity;
};

#endif //TEST_5_11_25_STRING_H
