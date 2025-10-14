//
// Created by 有趣的中国人 on 2025/5/27.
//
#include <iostream>
#include <cstring>
#include <cassert>
#include <algorithm>
#ifndef TEST_5_27_25_STRING_H
#define TEST_5_27_25_STRING_H
namespace dsj
{
    class string
    {
    public:
        typedef char* iterator;
        typedef const char* const_iterator;

        string(const char* str = "")
                :_size(strlen(str))
                ,_capacity(_size)
        {
            std::cout << "构造函数：string(const char* str = \"\")" << std::endl;

            _str = new char[_size + 1];
            strcpy(_str,str);
        }

        // 拷贝构造传统写法
        string(const string& str)
        {
            std::cout << "拷贝构造：string(string& str)" << std::endl;
            _size = str._size;
            _capacity = str._capacity;
            _str = new char[_capacity + 1];
            strcpy(_str, str._str);
        }

        string(string&& str)
                :_str(nullptr)
                ,_size(0)
                ,_capacity(0)
        {
            std::cout << "移动构造：string(string&& str)" << std::endl;

            swap(str);
        }
        // 拷贝构造现代写法
//        string(const string& str)
//        {
//            string tmp(str._str);
//            swap(tmp);
//            // 注意这块一定要将_str 置空，不然析构函数会释放野指针，因为拷贝构造也会走初始化列表
//            // 对内置类型不做处理
//            tmp._str = nullptr;
//            tmp._size = 0;
//            tmp._capacity = 0;
//        }

        // 赋值重载传统写法
        string& operator=(const string& str)
        {
            std::cout << "赋值重载：string const& operator=(string& str)" << std::endl;
            if (this != &str)
            {
                _size = str._size;
                _capacity = str._capacity;
                char* tmp = new char[_capacity + 1];
                delete[] _str;
                _str = tmp;
            }
            return *this;
        }

        // 移动赋值
        string& operator=(string&& str)
        {
            std::cout << "const string& operator=(string&& str)" << std::endl;
            swap(str);

            return *this;
        }
        // 现代写法
//        string& operator=(string str)
//        {
//            swap(str);
//            return *this;
//        }

        ~string()
        {
            delete[] _str;
            _size = _capacity = 0;
        }
        // 遍历
        size_t size() const
        {
            return _size;
        }

        char operator[](size_t i) const
        {
            return _str[i];
        }

        // 修改
        // 尾部增加
        string& operator+=(const char* str)
        {
            append(str);
            return *this;
        }

        string& operator+=(char ch)
        {
            append(ch);
            return *this;
        }

        void append(const char* str)
        {
            push_back(str);
        }

        void append(char ch)
        {
            push_back(ch);
        }

        void push_back(char ch)
        {
            if (_size == _capacity)
            {
                reserve(_capacity == 0 ? 4 : 2 * _capacity);
            }
            _str[_size] = ch;
            _str[++_size] = '\0';
        }

        void push_back(const char* str)
        {
            size_t len = strlen(str);
            if (_size == _capacity)
            {
                reserve(_size + len);
            }
            strcpy(_str + _size, str);
            _size = _size + len;
        }

        // 插入单个字符
        void insert(size_t pos, char ch = 'x')
        {
            assert(pos <= _size);
            if (_size == _capacity)
            {
                reserve(_capacity == 0 ? 4 : 2 * _capacity);
            }
            size_t end = _size + 1;
            while (end > pos)
            {
                _str[end] = _str[end - 1];
                --end;
            }
            _str[pos] = ch;
            ++_size;
        }

        // 插入字符串
        void insert(size_t pos, const char* str)
        {
            assert(pos <= _size);
            size_t len = strlen(str);
            if (_size + len >= _capacity)
            {
                reserve(_size + len);
            }
            size_t end = _size + len;
            // 这里pos位置的元素也要移动，所以要 -1
            while (end > pos + len - 1)
            {
                _str[end] = _str[end - len];
                --end;
            }
            strncpy(_str + pos, str, len);
            _size += len;
        }

        // 删除元素
        void erase(size_t pos, size_t len = npos)
        {
            assert(pos < _size && pos >= 0 && _size != 0);
            if (_size - pos < len)
            {
                _str[pos] = '\0';
                _size = pos;
            }
            else
            {
                strcpy(_str + pos, _str + pos + len);
                _size = _size - len;
            }
        }

        // 容量操作
        size_t capacity() const
        {
            return _capacity;
        }

        void reserve(size_t size)
        {
            if (size > _size)
            {
                char* tmp = new char[size + 1];
                strcpy(tmp,_str);
                delete[] _str;
                _str = tmp;
                _capacity = size;
            }
        }

        void resize(size_t size, char ch = 'x')
        {
            if (_size > size)
            {
                _str[size] = '\0';
                _size = size;
            }
            else if (_size < size && size <= _capacity)
            {
                for (size_t i = _size; i < size; ++i)
                {
                    _str[i] = ch;
                }
                _size = size;
            }
            else
            {
                reserve(size);
                for (size_t i = _size; i < size; ++i)
                {
                    _str[i] = ch;
                }
                _size = size;
            }
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
        // const 迭代器
        const_iterator begin() const
        {
            return _str;
        }

        const_iterator end() const
        {
            return _str+_size;
        }

        const char* c_str() const
        {
            return _str;
        }

        // swap
        void swap(string& str)
        {
            std::swap(_str,str._str);
            std::swap(_size,str._size);
            std::swap(_capacity,str._capacity);
        }

        // find
        size_t find(const char* str) const
        {
            char* pos = strstr(_str,str);
            size_t ret_pos = 0;
            if (pos)
            {
                ret_pos = pos - _str;
            }
            else
            {
                ret_pos = npos;
            }
            return ret_pos;
        }

        // substr
        string substr(size_t pos = 0, size_t len = npos)
        {
            assert(pos < _size);
            string ret_str;
            if (_size - pos < len)
            {
                ret_str += _str + pos;
            }
            else
            {
                ret_str.reserve(len);
                strncpy(ret_str._str,_str,len);
            }
            return ret_str;
        }

        void clear()
        {
            _str[0] = '\0';
            _size = 0;
        }


    private:
        char* _str;
        size_t _size;
        size_t _capacity;
        const static size_t npos = -1;
    };

    // 这样就可以优先调用自己实现的swap，而不是全局的模版函数swap。
    void swap(string& str1, string& str2)
    {
        str1.swap(str2);
    }

    std::ostream& operator<<(std::ostream& out, string& str)
    {
//       for (size_t i = 0; i < str.size(); ++i)
//       {
//           out << str[i];
//       }
        out << str.c_str();
        return out;
    }

    std::istream& operator>>(std::istream& in, string& str)
    {
        str.clear();
        char buffer[128];
        char ch = in.get();
        buffer[0] = ch;
        size_t i = 1;
        while (ch != ' ' && ch != '\n')
        {
            if (i != 127)
            {
                ch = in.get();
                buffer[i] = ch;
                ++i;
            }
            else
            {
                // 这儿要加 '\0',不然还会继续往后读
                buffer[127] = '\0';
                str += buffer;
                i = 0;
            }
        }
        if (i != 0)
        {
            buffer[i] = '\0';
            str += buffer;
        }
        return in;
    }

    std::istream& getline(std::istream& in, string& str)
    {
        str.clear();
        char ch = in.get();
        char buffer[128];
        size_t i = 0;
        while (ch != ' ' && ch != '\n')
        {
            buffer[i++] = ch;
            if (i == 127)
            {
                buffer[i] = '\0';
                str += buffer;
                i = 0;
            }
            ch = in.get();
        }
        if (i != 0)
        {
            buffer[i] = '\0';
            str += buffer;
        }
        return in;
    }
}
#endif //TEST_5_27_25_STRING_H
