//
// Created by 有趣的中国人 on 2025/5/12.
//
#include <iostream>
#include <cstring>
#ifndef TEST_5_12_25_STRING_H
#define TEST_5_12_25_STRING_H
using namespace std;

 namespace dsj
{
    class string
    {
    public:
        typedef char* iterator;
        typedef const char* const_iterator;
//        string()
//        {
//            _str = new char[1];
//            _size = _capacity = 0;
//        }
        string(const char* str = "")
            :_size(strlen(str))
        {
            _capacity = _size;
            _str = new char[_size + 1];
            strcpy(_str, str);
        }
        // 拷贝构造
        string(const dsj::string& str)
        {
            _size = str._size;
            _capacity = str._capacity;
            char* tmp = new char[_capacity + 1];
            strcpy(tmp,str._str);
            delete[] _str;
            _str = tmp;
        }
        // 复制重载
        string& operator=(dsj::string& str)
        {
            if (this != &str)
            {
                _size = str._size;
                _capacity = str._capacity;
                char* ch = new char[_capacity + 1];
                strcpy(ch, str._str);
                delete[] _str;
                _str = ch;
            }
            return *this;
        }

        ~string()
        {
            delete[] _str;
            _size = _capacity = 0;
        }
        // 普通迭代器
        iterator begin()
        {
            return _str;
        }

        iterator end()
        {
            return _str + _size;
        }
        //  const 迭代器，给 const 对象用
        const_iterator begin() const
        {
            return _str;
        }

        const_iterator end() const
        {
            return _str + _size;
        }
        // 重载，进行遍历
        char operator[](size_t num)
        {
            return _str[num];
        }

        const char* c_str() const
        {
            cout << _str << endl;
            return _str;
        }

        void resize(size_t capacity, char ch = ' ')
        {
            if (capacity <= _size)
            {
                _str[capacity] = '\0';
                _size = capacity;
            }
            else
            {
                reserve(capacity);
                for (size_t i = _size; i < capacity; ++i)
                {
                    _str[i] = ch;
                }
                _str[capacity] = '\0';
                _size = _capacity;
            }
        }

        // 修改
        void reserve(size_t newcapacity)
        {
            if (newcapacity > _capacity)
            {
                char* tmp = new char[newcapacity + 1]; // 多开一个空间给 '\0'
                strcpy(tmp, _str);
                _str = tmp;
                _capacity = newcapacity;
            }
        }
        // 尾插
        void push_back(char ch)
        {
            if (_size == _capacity)
            {
                reserve(_capacity == 0 ? 4 : 2 * _capacity);
            }
            _str[_size] = ch;
            ++_size;
            _str[_size] = '\0';
        }

        void append(const char* str)
        {
            size_t len =strlen(str);
            if (_size == _capacity)
            {
                reserve(_capacity == 0 ? 4 : _size + len);
            }
            for (size_t i = 0; i < len; ++i)
            {
                _str[_size] = str[i];
                ++_size;
            }
            _str[_size] = '\0';
        }
        // += 运算符重载
        string& operator+=(char ch)
        {
            push_back(ch);
            return *this;
        }

        string& operator+=(const char* str)
        {
            append(str);
            return *this;
        }

        void insert(size_t pos, char ch)
        {
            if (_size == _capacity)
            {
                reserve(_capacity == 0 ? 4 : 2 * _capacity);
            }
            if (pos <= _size)
            {
                size_t end = _size;
                while (end > pos)
                {
                    _str[end] = _str[end - 1];
                    --end;
                }
                _str[pos] = ch;
                ++_size;
                _str[_size] = '\0';
            }
        }

        // 从第pos位置开始删除，第pos位置也要删除
        void erase(size_t pos, size_t len = npos)
        {
            if (_size - pos <= len)
            {
                _str[pos] = '\0';
                _size = pos;
            }
            else
            {
                strcpy(_str + pos, _str + pos + len);
                _size -= len;
            }
        }

        // 有问题
        void insert(size_t pos, const char* str)
        {
            size_t len = strlen(str);
            if (_size == _capacity)
            {
                reserve(_capacity == 0 ? 4 : _size + len);
            }
            if (pos <= _size)
            {
                size_t end = _size - 1;
                while (end >= pos)
                {
                    _str[end + len] = _str[end];
                    --end;
                }
                for (size_t i = 0; i < len; ++i)
                {
                    _str[pos + i] = str[i];
                }
                _size += len;
                _str[_size] = '\0';
            }
        }
    private:
        char* _str;
        size_t _capacity;
        size_t _size;
        static const size_t npos = -1;
    };

}
#endif //TEST_5_12_25_STRING_H
