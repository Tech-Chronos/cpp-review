//
// Created by 有趣的中国人 on 2025/5/6.
//
#include <iostream>
#include <cstdlib>
using namespace std;
namespace dsj
{
    template<typename T>
    class Stack {
    public:
        Stack()
                : _top(-1),
                  _capacity(4) {
            _arr = (T *) malloc(sizeof(T) * _capacity);
            if (!_arr) {
                cerr << "malloc error" << endl;
                return;
            }
        }

        void Push(const T &val) {
            CheckCapacity();
            ++_top;
            _arr[_top] = val;

        }

        const T& Pop()
        {
            cout << _arr[_top--] << endl;
        }

    private:
        void CheckCapacity() {
            if (_top == _capacity - 1) {
                int newcapacity = 2 * _capacity;
                T *tmp = (T *) realloc(_arr, sizeof(T) * newcapacity);
                if (!tmp) {
                    cerr << "realloc error" << endl;
                    return;
                }
                _capacity = newcapacity;
                _arr = tmp;
            }
        }

    private:
        T *_arr;
        int _top;
        int _capacity;
    };
}