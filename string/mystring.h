//
// Created by dsj on 2026/2/15.
//
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <cassert>

#ifndef STRING_MYSTRING_H
#define STRING_MYSTRING_H

template<class T, class Ptr, class Ref>
class StringIterator
{
public:
    StringIterator(Ptr sptr)
        : _sptr(sptr)
    {}

    // 这个是前置++
    // 返回引用支持链式调用
    StringIterator& operator++()
    {
        _sptr++;
        return *this;
    }

    // 后置++
    StringIterator operator++(int)
    {
        StringIterator tmp(_sptr);
        ++_sptr;
        return tmp;
    }

    // 前置--
    StringIterator& operator--()
    {
        _sptr--;
        return *this;
    }

    // 后置--
    StringIterator operator--(int)
    {
        StringIterator tmp(_sptr);
        --_sptr;
        return tmp;
    }

    Ref operator*()
    {
        return *_sptr;
    }

    bool operator!=(const StringIterator& other)
    {
        return _sptr != other._sptr;
    }

    bool operator==(const StringIterator& other)
    {
        return _sptr == other._sptr;
    }

private:
    Ptr _sptr;
};

class mystring
{
public:
    typedef StringIterator<char, char*, char&> iterator;
    typedef StringIterator<const char, const char*, const char&> const_iterator;

    // 迭代器
    iterator begin()
    {
        return iterator(_str);
    }

    iterator end()
    {
        return iterator(_str + _size);
    }

    const_iterator begin() const
    {
        return const_iterator(_str);
    }

    const_iterator end() const
    {
        return const_iterator(_str + _size);
    }

public:
    mystring(const char* str = "")
    {
        _size = strlen(str);
        _str = new char[_size + 1];
        strcpy(_str, str);
        _capacity = _size;
    }

    ~mystring()
    {
        if (_str)
        {
            delete[] _str;
            _str = nullptr;
        }
        _size = 0;
        _capacity = 0;
    }

    mystring(const mystring& other)
    {
        _str = new char[other._size + 1];

        strcpy(_str, other._str);
        _size = other._size;
        _capacity = other._capacity;
    }

    // s1(s2)
    // mystring(const mystring& other)
    //     : _str(nullptr), _size(0), _capacity(0)
    // {
    //     mystring tmp(other._str);
    //
    //     std::swap(_str, tmp._str);
    //     std::swap(_size, tmp._size);
    //     std::swap(_capacity, tmp._capacity);
    // }

    // mystring& operator=(const mystring& other)
    // {
    //     if (this != &other)
    //     {
    //         if (_str)
    //         {
    //             delete[] _str;
    //         }
    //         _str = new char[other._size + 1];
    //
    //         strcpy(_str, other._str);
    //         _size = other._size;
    //         _capacity = other._capacity;
    //     }
    //     return *this;
    // }

    // s1 = s2
    mystring& operator=(mystring other)
    {
        std::swap(_str, other._str);
        std::swap(_size, other._size);
        std::swap(_capacity, other._capacity);
        return *this;
    }
public:
    // 容量操作
    size_t size() const
    {
        return _size;
    }

    size_t length() const
    {
        return _size;
    }

    size_t capacity() const
    {
        return _capacity;
    }

    bool empty() const
    {
        return _size == 0;
    }

    void clear()
    {
        _size = 0;
    }
public:
    // 元素获取
    char operator[](int pos) const
    {
        assert(pos < _size);
        return _str[pos];
    }

    char front() const
    {
        return _str[0];
    }

    char back() const
    {
        return _str[_size - 1];
    }

public:
    void reserve(int new_capacity = 0)
    {
        if (new_capacity <= _capacity)
            return;
        else
        {
            char* tmp = new char[new_capacity + 1];
            strcpy(tmp, _str);
            delete[] _str;
            _str = tmp;
            _capacity = new_capacity;
        }
    }

    void resize(int n, char ch = ' ')
    {
        if (n < _size)
        {
            _size = n;
            _str[n] = '\0';
        }
        else if (n <= _capacity)
        {
            for (int i = _size; i < n; ++i)
            {
                _str[i] = ch;
            }
            _str[n] = '\0';
            _size = n;
        }
        else
        {
            reserve(n);
            for (int i = _size; i < n; ++i)
            {
                _str[i] = ch;
            }
            _str[n] = '\0';
            _size = n;
        }
    }

    void push_back(char c)
    {
        if (_size == _capacity)
        {
            int newcapacity = capacity() == 0 ? 1 : 2 * _capacity;
            reserve(newcapacity);
        }
        _str[_size++] = c;
        _str[_size] = '\0';
    }

    mystring& append(const char* str)
    {
        size_t len = strlen(str);
        if (_capacity < _size + len)
        {
            int newcapacity = capacity();
            while (newcapacity < len + _size)
            {
                newcapacity == 0 ? 1 : 2 * capacity();
            }
            reserve(newcapacity);
        }

        strcpy(&_str[_size], str);
        _size += len;
        return *this;
    }

    mystring& append(const char* str, size_t len)
    {
        if (_capacity < _size + len)
        {
            int newcapacity = capacity();
            while (newcapacity < len + _size)
            {
                newcapacity == 0 ? 1 : 2 * capacity();
            }
            reserve(newcapacity);
        }
        while (len--)
        {
            push_back(*str);
            ++str;
        }
        return *this;
    }

    // 防止自己追加自己
    mystring& append(const mystring& str)
    {
        if (this == &str)
        {
            mystring tmp(str);
            return append(tmp.c_str());
        }
        else
        {
            if (_capacity < _size + str.size())
            {
                int newcapacity = capacity();
                while (newcapacity < str.size() + _size)
                {
                    newcapacity == 0 ? 1 : 2 * capacity();
                }
                reserve(newcapacity);
            }
            append(str.c_str());
        }
        return *this;
    }

    mystring& operator+=(char ch)
    {
        push_back(ch);
        return *this;
    }

    mystring& operator+=(const char* str)
    {
        append(str);
        return *this;
    }

    mystring& insert(size_t pos, char ch)
    {
        if (_size == _capacity)
        {
            int newcapacity = (_capacity == 0 ? 1 : 2 * capacity());
            reserve(newcapacity);
        }

        size_t right = _size + 1;
        while (right > pos)
        {
            _str[right] = _str[right - 1];
            --right;
        }
        _str[pos] = ch;
        ++_size;
        return *this;
    }

    mystring& insert(size_t pos, const char* str)
    {
        int len = strlen(str);
        if (capacity() < len + _size)
        {
            reserve(len + size());
        }

        int right = _size + len;
        while (pos + len <= right)
        {
            _str[right] = _str[right - len];
            --right;
        }
        strncpy(_str + pos, str, len);
        _size += len;
        return *this;
    }

    mystring& erase(size_t pos, size_t len = npos)
    {
        assert(pos >= 0 && pos < _size);
        if (len == npos || pos + len < _size)
        {
            memcpy(_str + pos, _str + pos + len, _size - pos - len + 1);
            _size = _size - len;
        }
        else
        {
            _str[pos] = '\0';
            _size = pos;
        }
        return *this;
    }

    const char* c_str() const
    {
        return _str;
    }

    size_t find(char ch, size_t pos = 0)
    {
        for (int i = pos; i < _size; ++i)
        {
            if (_str[i] == ch)
            {
                return i;
            }
        }
        return npos;
    }

    size_t find(char* str, size_t pos = 0)
    {
        const char* p = strstr(_str, str);
        if (!p)
            return npos;
        return p - _str;
    }

    mystring substr(size_t pos = 0, size_t len = npos)
    {
        mystring sub;
        if (_size - pos >= len)
        {
            return _str + pos;
        }
        else
        {
            for (int i = pos; i < len; ++i)
            {
                sub += _str[i];
            }
        }
        return sub;
    }

    static std::ostream mystring::operator<<(const std::ostream& stream, mystring& str)
    {
        stream << str.c_str();
    }

private:
    char* _str;
    size_t _size;
    size_t _capacity;
    static size_t npos;
};

size_t mystring::npos = -1;

// std::cout <<


#endif //STRING_MYSTRING_H