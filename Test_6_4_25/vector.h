//
// Created by 有趣的中国人 on 2025/6/4.
//
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#ifndef TEST_6_4_25_VECTOR_H
#define TEST_6_4_25_VECTOR_H
namespace dsj
{
    template<typename T>
    class vector
    {
    public:
        typedef T* iterator;
        typedef const T* const_iterator;

        // 默认成员函数
        vector(size_t n = 0)
            :_start(new T[n])
            ,_finish(_start)
            ,_endofstorage(_start + n)
        {}

        // 迭代器区间构造
        template<typename InputIterator>
        vector(InputIterator it1, InputIterator it2)
        {
            while (it1 != it2)
            {
                push_back(*it1);
                ++it1;
            }
        }

        // n 个值构造
        vector(size_t n, const T& val = T())
        {
            reserve(n);
            while (n--)
            {
                push_back(val);
            }
        }

        // initializer_list 构造
        vector(const std::initializer_list<T>& il)
        {
            size_t size = il.size();
            reserve(size);
            typename std::initializer_list<T>::iterator it1 = il.begin();
            typename std::initializer_list<T>::iterator it2 = il.end();
            while (it1 != it2)
            {
                push_back(*it1);
                ++it1;
            }
        }

        // v2(v1) 拷贝构造
        vector(vector<T>& v)
        {
            reserve(v.capacity());
            for (auto& e : v)
            {
                push_back(e);
            }
        }
//        vector(vector<T>& v)
//        {
//            size_t size = v.size();
//            size_t capacity = v.capacity();
//            _start = new T[v.capacity()];
//            _finish = _start + size;
//            _endofstorage = _start + capacity;
//            memcpy(_start, v._start,sizeof(T) * size);
//        }

        // 赋值重载
        vector<T>& operator=(vector<T> v)
        {
            swap(v);
            return *this;
        }
//        vector<T>& operator=(vector<T>& v)
//        {
//            if(this != &v)
//            {
//                size_t size = v.size();
//                size_t capacity = v.capacity();
//                _start = new T[v.capacity()];
//                _finish = _start + size;
//                _endofstorage = _start + capacity;
//                memcpy(_start, v._start, sizeof(T) * size);
//            }
//            return *this;
//        }
//        vector(vector<T>& v)
//        {
//            size_t size = v.size();
//            size_t capacity = v.capacity();
//            _start = new T[v.capacity()];
//            _finish = _start + size;
//            _endofstorage = _start + capacity;
//            memcpy(_start, v._start,sizeof(T) * size);
//        }

        ~vector()
        {
            delete[] _start;
            _start = _finish = _endofstorage = nullptr;
        }

        // 容量操作
        iterator begin()
        {
            return _start;
        }

        iterator end()
        {
            return _finish;
        }

        const_iterator begin() const
        {
            return _start;
        }

        const_iterator end() const
        {
            return _finish;
        }

        size_t size() const
        {
            return _finish - _start;
        }

        size_t capacity() const
        {
            return _endofstorage - _start;
        }

        void reserve(size_t n)
        {
            if (n > capacity())
            {
                // 记录一下原始的size，迭代器失效
                size_t old_size = size();
                iterator tmp = new T[n];
                //memcpy(tmp, _start, sizeof(T) * old_size);
                for (size_t i = 0; i < size(); ++i)
                {
                    // 赋值就会进行深拷贝
                    tmp[i] = _start[i];
                }
                // 释放之后，如果T是string类似的类型也会被释放，
                // 析构的时候又会被delete，所以不能用memcpy
                delete[] _start;
                _start = tmp;
                _finish = _start + old_size;
                _endofstorage = _start + n;
            }
        }

        void push_back(const T& val)
        {
            if (_finish == _endofstorage)
            {
                reserve(size() == 0 ? 4 : 2 * capacity());
            }
            *_finish = val;
            ++_finish;
        }

        void pop_back()
        {
            assert(size() > 0);
            --_finish;
        }

        void insert(iterator pos, const T& val = T())
        {
            assert(pos >= _start && pos <= _finish);
            if (_finish == _endofstorage)
            {
                size_t len = pos - _start;
                reserve(size() == 0 ? 4 : 2 * capacity());
                // 一定要修改 pos 的位置
                 pos = _start + len;
            }
            iterator end = _finish;
            while (end > pos)
            {
                *end = *(end - 1);
                --end;
            }
            // 可能野指针访问
            *pos = val;
            ++_finish;
        }

        // 防止迭代器失效，返回类型改为iterator，返回值是删除元素的下一个位置
        iterator erase(iterator pos)
        {
            assert(pos >= _start && pos < _finish);
            iterator begin = pos + 1;
            while (begin < _finish)
            {
                *(begin - 1) = *begin;
                ++begin;
            }
            --_finish;
            return pos;
        }

        void swap(vector<T> v)
        {
            std::swap(_start, v._start);
            std::swap(_finish, v._finish);
            std::swap(_endofstorage, v._endofstorage);
        }
    private:
        iterator _start = nullptr;
        iterator _finish = nullptr;
        iterator _endofstorage = nullptr;
    };

    template<typename T>
    void swap(vector<T> v1, vector<T> v2)
    {
        v1.swap(v2);
    }

    template<typename T>
    void print_vector(const vector<T>& v)
    {
        typename vector<T>::const_iterator it = v.begin();
        //auto it = v.begin();
        while (it != v.end())
        {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;
    }
}
#endif //TEST_6_4_25_VECTOR_H
