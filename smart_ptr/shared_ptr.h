//
// Created by dsj on 2026/3/3.
//

#ifndef SMART_PTR_SHARED_PTR_H
#define SMART_PTR_SHARED_PTR_H
#include <iostream>
#include <mutex>
#include <functional>

template<class T>
class shared_ptr
{
public:
    explicit shared_ptr(T* ptr = nullptr)
        :_ptr(ptr)
        ,_count(new int(1))
        ,_mtx(new std::mutex())
    {}

    shared_ptr(const shared_ptr<T>& other)
        :_ptr(other._ptr)
        ,_count(other._count)
        ,_mtx(other._mtx)
    {
        _mtx->lock();
        ++(*_count);
        _mtx->unlock();
    }

    template<class D>
    shared_ptr(T* ptr, D del)
        :_ptr(ptr)
        ,_count(new int(1))
        ,_mtx(new std::mutex())
        ,_del(del)
    {}

    void release()
    {
        _mtx->lock();
        if (--(*_count) == 0)
        {
            delete _ptr;
            delete _count;
            delete _mtx;
            _count = nullptr;
            _ptr = nullptr;
        }
        _mtx->unlock();
    }

    shared_ptr<T>& operator=(shared_ptr<T> other)
    {

        std::swap(_ptr, other._ptr);
        std::swap(_count, other._count);
        std::swap(_mtx, other._mtx);
        std::swap(_del, other._del);

        return *this;
    }

    ~shared_ptr()
    {
        release();
    }


private:
    T* _ptr;
    int* _count;
    std::mutex* _mtx;
    std::function<void(T*)> _del = [](T* ptr)->void { delete ptr; };
};

#endif //SMART_PTR_SHARED_PTR_H
