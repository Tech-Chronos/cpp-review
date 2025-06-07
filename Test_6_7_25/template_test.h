//
// Created by 有趣的中国人 on 2025/6/7.
//
#include "Date.h"
namespace dsj
{
    template<class T>
    bool Less(const T& t1, const T& t2)
    {
        return t1 > t2;
    }

//    template<>
//    bool Less<dsj::Date*>(const Date* d1, const Date* d2)
//    {
//        return *d1 > *d2;
//    }
}
//namespace dsj
//{
//    template<class T, size_t N = 100>
//    class array
//    {
//    public:
////        array()
////        {
////            T arr[N];
////            _arr[N] = arr[N];
////        }
//
////        void push_back(const T& val)
////        {
////            _arr[_size] = val;
////            ++_size;
////        }
////
////        void pop_back()
////        {
////            --_size;
////        }
//
//        size_t size() const
//        {
//            return _size;
//        }
//
////        T& operator[](size_t size)
////        {
////            return _arr[size - 1];
////        }
//    private:
//        T _arr[N];
//        size_t _size = N;
//    };
//}



