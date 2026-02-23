//
// Created by dsj on 2026/2/21.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H
#include <iostream>
#include <string>
#include <initializer_list>
#include <utility>
#include <cstring>
#include <cassert>

namespace dsj
{
    template <class T, class Ptr, class Ref>
    class VectorIterator
    {
    public:
        VectorIterator(Ptr vptr)
            :_vptr(vptr)
        {}

        Ref operator*()
        {
            return *_vptr;
        }

        // 后置++
        VectorIterator operator++()
        {
            VectorIterator tmp(_vptr);

            _vptr++;
            return tmp;
        }

        // 前置++
        VectorIterator& operator++(int)
        {
            ++_vptr;
            return *this;
        }

        // 后置--
        VectorIterator operator--()
        {
            VectorIterator tmp(_vptr);

            _vptr--;
            return tmp;
        }

        // 前置--
        VectorIterator& operator--(int)
        {
            --_vptr;
            return *this;
        }

        bool operator==(const VectorIterator& other)
        {
            return _vptr == other._vptr;
        }

        bool operator!=(const VectorIterator& other)
        {
            return !(*this == other);
            // return _vptr != other._vptr;
        }

        size_t operator-(const VectorIterator& other)
        {
            return _vptr - other._vptr;
        }

    private:
        Ptr _vptr;
    };

    template <class T>
    class vector
    {
    public:
        typedef VectorIterator<T, T*, T&> iterator;
        typedef VectorIterator<T, const T*, const T&> const_iterator;

        iterator begin()
        {
            return iterator(_start);
        }

        iterator end()
        {
            return iterator(_finish);
        }

        const_iterator begin() const
        {
            return const_iterator(_start);
        }

        const_iterator end() const
        {
            return const_iterator(_finish);
        }
    public:
        vector()
        {}

        vector(size_t n, const T& val = T())
        {
            _start = new T[n];
            _finish = _start;
            _end_of_storage = _start + n;

            while (n--)
            {
                push_back(val);
            }
        }

        template <class InputIterator>
        vector(const InputIterator& begin, const InputIterator& end)
        {
            InputIterator tmp = begin;
            while (tmp != end)
            {
                push_back(*tmp);
                ++tmp;
            }
        }

        vector(const std::initializer_list<T>& il)
        {
            typename std::initializer_list<T>::iterator it = il.begin();
            while (it != il.end())
            {
                push_back(*it);
                ++it;
            }
        }


        // v2(v1)
        // vector(const vector<T>& other)
        // {
        //     _start = new T[other.capacity()];
        //     memcpy(_start, other._start, sizeof(T) * other.size());
        //
        //     _finish = _start + other.size();
        //     _end_of_storage = _start + other.capacity();
        // }

        vector(const vector& other)
        {
            reserve(other.capacity());
            for (auto e : other)
            {
                push_back(e);
            }
        }

        // 移动构造
        vector(vector&& other)
        {
            _start = other._start;
            _finish = other._finish;
            _end_of_storage = other._end_of_storage;

            other._start = nullptr;
            other._finish = nullptr;
            other._end_of_storage = nullptr;
        }

        // v2 = v1;
        // vector& operator=(const vector& other)
        // {
        //     if (this != &other)
        //     {
        //         T* tmp = new T[other.capacity()];
        //
        //         memcpy(tmp, other._start, sizeof(T) * other.size());
        //         _start = tmp;
        //         _finish = _start + other.size();
        //         _end_of_storage = _start + other.capacity();
        //     }
        //     return *this;
        // }

        // v2 = v1;
        vector& operator=(vector other)
        {
            std::swap(_start, other._start);
            std::swap(_finish, other._finish);
            std::swap(_end_of_storage, other._end_of_storage);

            return *this;
        }

        vector& operator=(vector&& other)
        {
            if (this != &other)
            {
                _start = other._start;
                _finish = other._finish;
                _end_of_storage = other._end_of_storage;

                other._start = nullptr;
                other._finish = nullptr;
                other._end_of_storage = nullptr;
            }

            return *this;
        }

        // 元素获取相关
        T operator[](size_t pos)
        {
            assert(pos >= 0 && pos < size());
            return _start[pos];
        }

        // 容量操作
        size_t size() const
        {
            return _finish - _start;
        }

        size_t capacity() const
        {
            return _end_of_storage - _start;
        }

        void reserve(int n)
        {
            if (n <= capacity())
                return;
            else
            {
                int old_size = size();
                T* tmp = new T[n];
                // 假如模版是自定义类型，且有深拷贝，memcpy会拷贝原来的地址，析构的时候会释放两次
                for (int i = 0; i < size(); ++i)
                {
                    // 对于自定义类型会深拷贝
                    tmp[i] = _start[i];
                }

                delete[] _start;

                _start = tmp;
                _finish = _start + old_size;
                _end_of_storage = _start + n;
            }
        }

        void resize(int n, const T& val = T())
        {
            if (n <= size())
            {
                _finish = _start + n;
            }
            else
            {
                reserve(n);
                while (_finish < _start + n)
                {
                    *_finish = val;
                    ++_finish;
                }
            }
        }

        bool empty()
        {
            return _start == _finish;
        }

        // 修改操作
        void push_back(const T& val)
        {
            // 判断是否需要扩容
            // if (size() == capacity())
            // {
            //     size_t oldsize = size();
            //     // 给出新空间大小
            //     size_t new_capacity = (capacity() == 0) ? 4 : 2 * capacity();
            //
            //     T* tmp = new T[new_capacity];
            //     for (int i = 0; i < size(); ++i)
            //     {
            //         tmp[i] = _start[i];
            //     }
            //
            //     // 释放旧空间
            //     delete[] _start;
            //
            //     // 更新成员变量
            //     _start = tmp;
            //     _finish = tmp + oldsize;
            //     _end_of_storage = tmp + new_capacity;
            // }
            // *_finish = val;
            // ++_finish;
            emplace_back(val);
        }

        void push_back(T&& val) // 到这里 val 已经构造了一次
        {
            // 判断是否需要扩容
            // if (size() == capacity())
            // {
            //     size_t oldsize = size();
            //     // 给出新空间大小
            //     size_t new_capacity = (capacity() == 0) ? 4 : 2 * capacity();
            //
            //     T* tmp = new T[new_capacity];
            //     for (int i = 0; i < size(); ++i)
            //     {
            //         tmp[i] = std::move(_start[i]);
            //     }
            //
            //     // 释放旧空间
            //     delete[] _start;
            //
            //     // 更新成员变量
            //     _start = tmp;
            //     _finish = tmp + oldsize;
            //     _end_of_storage = tmp + new_capacity;
            // }
            // // 本身是左值，要move成右值
            // *_finish = std::move(val);
            // //*_finish = std::forward<T>(val);
            // ++_finish;

            emplace_back(std::move(val));
        }

        // 模版 + 可变参数 -> 万能引用
        template<class ...Args>
        void emplace_back(Args&& ...args)
        {
            if (_finish == _end_of_storage)
            {
                size_t oldsize = size();
                // 给出新空间大小
                size_t new_capacity = (capacity() == 0) ? 4 : 2 * capacity();

                T* tmp = new T[new_capacity];
                for (int i = 0; i < size(); ++i)
                {
                    tmp[i] = std::move(_start[i]);
                }

                // 释放旧空间
                delete[] _start;

                // 更新成员变量
                _start = tmp;
                _finish = tmp + oldsize;
                _end_of_storage = tmp + new_capacity;
            }
            // new (_finish) T(std::forward<Args>(args)...);
            // 传递T的左值就是拷贝构造，传递T的右值就是移动构造，传递T所需的构造参数就是直接构造
            new (_finish) T(std::forward<Args>(args)...);
            ++_finish;
        }

        void insert(size_t pos, const T& val = T())
        {
            if (size() == capacity())
            {
                int old_size = size();
                int new_capacity = (capacity() == 0) ? 4 : 2 * capacity();

                T* tmp = new T[new_capacity];
                for (int i = 0; i < size(); ++i)
                {
                    tmp[i] = _start[i];
                }
                delete _start;

                _start = tmp;
                _finish = _start + old_size;
                _end_of_storage = _start + new_capacity;
            }

            T* right = _finish;
            while (right > _start + pos)
            {
                *right = *(right - 1);
                --right;
            }

            _start[pos] = val;
            ++_finish;
        }

        void pop_back()
        {
            assert(!empty());
            --_finish;
        }

        void erase(size_t pos)
        {
            assert(pos >= 0 && pos < size());

            size_t left = pos;
            while (left < size())
            {
                _start[left] = _start[left + 1];
                ++left;
            }
            --_finish;
        }
    private:
        T* _start = nullptr;
        T* _finish = nullptr;
        T* _end_of_storage = nullptr;
    };
} // dsj

#endif //VECTOR_VECTOR_H