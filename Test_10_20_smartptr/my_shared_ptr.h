//
// Created by 有趣的中国人 on 2025/10/20.
//

#ifndef TEST_10_20_SMARTPTR_MY_SHARED_PTR_H
#define TEST_10_20_SMARTPTR_MY_SHARED_PTR_H
#include <iostream>
#include <mutex>
#include <thread>
#include <functional>
using namespace std;

template <class T>
class my_shared_ptr
{
public:
    explicit my_shared_ptr(T* ptr = nullptr)
        :_ptr(ptr)
        ,_ref_count(new int(1))
        ,_mtx(new mutex)
    {}

    template<class D>
    my_shared_ptr(T* ptr, D del)
        :_ptr(ptr)
        ,_ref_count(new int(1))
        ,_mtx(new mutex)
        ,_del(del)
    {}

    my_shared_ptr(const my_shared_ptr& sptr)
        :_ptr(sptr._ptr)
        ,_ref_count(sptr._ref_count)
        ,_mtx(sptr._mtx)
    {
        _mtx->lock();
        ++(*_ref_count);
        _mtx->unlock();
    }

    // s1 = s2;
    my_shared_ptr& operator=(const my_shared_ptr& sptr)
    {
        if (this != &sptr)
        {
            release();
            _ptr = sptr._ptr;
            _ref_count = sptr._ref_count;

            _mtx->lock();
            ++(*_ref_count);
            _mtx->unlock();
        }
        return *this;
    }

    void release()
    {
        _mtx->lock();
        if (*_ref_count == 1)
        {
            _del(_ptr);
        }
        else
        {
            --(*_ref_count);
        }
        _mtx->unlock();
    }

    T& operator*()
    {
        return *_ptr;
    }

    T* operator->()
    {
        return _ptr;
    }

    int use_count()
    {
        return *_ref_count;
    }

    ~my_shared_ptr()
    {
        release();
    }

private:
    T* _ptr;
    int* _ref_count;
    mutex* _mtx;
    function<void(T*)> _del = [](T* ptr)mutable ->void{delete ptr;};
};

#endif //TEST_10_20_SMARTPTR_MY_SHARED_PTR_H
