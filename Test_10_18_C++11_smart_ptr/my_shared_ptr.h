//
// Created by 有趣的中国人 on 2025/10/18.
//

#ifndef TEST_10_18_C__11_SMART_PTR_MY_SHARED_PTR_H
#define TEST_10_18_C__11_SMART_PTR_MY_SHARED_PTR_H
#include <iostream>
#include <thread>
#include <list>
#include <string>
#include <mutex>
#include <functional>
#include <memory>

namespace dsj
{
    // RAII
//    template<class T>
//    class shared_ptr
//    {
//    public:
//        explicit shared_ptr(T* ptr)
//            :_ptr(ptr)
//        {
//            _ref_count = new int(1);
//            _ptr_mtx = new std::mutex;
//            //std::cout << "&_ref_count-> " << _ref_count << " _ref_count-> " << *_ref_count << std::endl;
//        }
//
//        shared_ptr(const shared_ptr<T>& sptr)
//            :_ptr(sptr._ptr)
//            ,_ref_count(sptr._ref_count)
//            ,_ptr_mtx(sptr._ptr_mtx)
//        {
//            // 这个不是⚛️原子操作
//            _ptr_mtx->lock();
//            ++(*_ref_count);
//            //std::cout << "&_ref_count-> " << _ref_count << " _ref_count-> " << *_ref_count << std::endl;
//            _ptr_mtx->unlock();
//        }
//
//        // s1 = s2
//        shared_ptr& operator=(const shared_ptr<T>& sptr)
//        {
//            if (this != &sptr)
//            {
//                release();
//                _ptr = sptr._ptr;
//                _ref_count = sptr._ref_count;
//                _ptr_mtx->lock();
//                ++(*_ref_count);
//                _ptr_mtx->unlock();
//            }
//            std::cout << "&_ref_count-> " << _ref_count << " _ref_count-> " << *_ref_count <<std::endl;
//            return *this;
//        }
//
//        int size()
//        {
//            return *_ref_count;
//        }
//
//        T& operator*()
//        {
//            return *_ptr;
//        }
//
//        T* operator->()
//        {
//            return _ptr;
//        }
//
//        void release()
//        {
//            if (*_ref_count == 1)
//            {
//                delete _ptr;
//                delete _ref_count;
//            }
//            else
//            {
//                _ptr_mtx->lock();
//                --(*_ref_count);
//                _ptr_mtx->unlock();
//            }
//        }
//
//        ~shared_ptr()
//        {
//            release();
//        }
//    private:
//        T* _ptr;
//        int * _ref_count;
//        std::mutex* _ptr_mtx;
//    };

    template<class T>
    class shared_ptr
    {
    public:
        explicit shared_ptr(T* ptr)
                :_ptr(ptr)
        {
            _ref_count = new std::atomic<int>;
            *_ref_count = 1;

            //_ptr_mtx = new std::mutex;
            //std::cout << "&_ref_count-> " << _ref_count << " _ref_count-> " << *_ref_count << std::endl;
        }

        shared_ptr(const shared_ptr<T>& sptr)
                :_ptr(sptr._ptr)
                ,_ref_count(sptr._ref_count)
                //,_ptr_mtx(sptr._ptr_mtx)
        {
            // 这个不是⚛️原子操作
            //_ptr_mtx->lock();
            ++(*_ref_count);
            //std::cout << "&_ref_count-> " << _ref_count << " _ref_count-> " << *_ref_count << std::endl;
            //_ptr_mtx->unlock();
        }

        // s1 = s2
        shared_ptr& operator=(const shared_ptr<T>& sptr)
        {
            if (this != &sptr)
            {
                release();
                _ptr = sptr._ptr;
                _ref_count = sptr._ref_count;
                //_ptr_mtx->lock();
                ++(*_ref_count);
                //_ptr_mtx->unlock();
            }
            std::cout << "&_ref_count-> " << _ref_count << " _ref_count-> " << *_ref_count <<std::endl;
            return *this;
        }

        int size()
        {
            return *_ref_count;
        }

        T& operator*()
        {
            return *_ptr;
        }

        T* operator->()
        {
            return _ptr;
        }

        void release()
        {
            if (*_ref_count == 1)
            {
                delete _ptr;
                delete _ref_count;
            }
            else
            {
                //_ptr_mtx->lock();
                --(*_ref_count);
                //_ptr_mtx->unlock();
            }
        }

        ~shared_ptr()
        {
            release();
        }
    private:
        T* _ptr;
        //int * _ref_count;
        std::atomic<int>* _ref_count;
        //std::mutex* _ptr_mtx;
    };
}


#endif //TEST_10_18_C__11_SMART_PTR_MY_SHARED_PTR_H
